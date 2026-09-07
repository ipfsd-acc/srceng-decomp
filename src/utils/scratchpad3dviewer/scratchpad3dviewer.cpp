// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/scratchpad3dviewer/scratchpad3dviewer.cpp
// Functions: 29
// ============================================================

#include "utils\scratchpad3dviewer\scratchpad3dviewer.h"

//------------------------------------------------------------------------------
// Address: 0x00401E30
// Name: public: void CUtlMemory<class CSPVert,int>::EnsureCapacity(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSPVert,int>::EnsureCapacity(CUtlMemory<CSPVert,int> *this, int num)
{
  CSPVert *m_pMemory; // edx

  if ( this->m_nAllocationCount < num && this->m_nGrowSize >= 0 )
  {
    m_pMemory = this->m_pMemory;
    this->m_nAllocationCount = num;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSPVert *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: 28 * num);
    else
      this->m_pMemory = (CSPVert *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * num);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EA0
// Name: public: void CUtlMemory<class CSPVert,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CSPVert,int>::Grow(CUtlMemory<CSPVert,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CSPVert *m_pMemory; // edx

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
    this->m_nAllocationCount = m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CSPVert *)_g_pMemAlloc->Realloc_2(
                                     this: _g_pMemAlloc,
                                     a2: m_pMemory,
                                     a3: 28 * m_nAllocationCount);
    else
      this->m_pMemory = (CSPVert *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 28 * m_nAllocationCount);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402960
// Name: public: int CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>>::AddVectorToTail(class CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::AddVectorToTail(
        CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *this,
        const CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *src)
{
  int m_Size; // ebx
  int v4; // edi
  CSPVert *m_pMemory; // edx
  int v6; // ebx
  int v7; // edx
  CSPVert *v8; // eax
  CSPVert *v9; // ecx
  int base; // [esp+Ch] [ebp-4h]

  m_Size = this->m_Size;
  v4 = src->m_Size;
  base = m_Size;
  CUtlMemory<CSPVert,int>::EnsureCapacity(this: &this->m_Memory, num: v4 + m_Size);
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_Size += v4;
  this->m_pElements = m_pMemory;
  if ( v4 <= 0 )
    return m_Size;
  v6 = 0;
  v7 = base;
  do
  {
    v8 = &src->m_Memory.m_pMemory[v6];
    v9 = &this->m_Memory.m_pMemory[v7];
    if ( v9 != nullptr )
    {
      *(_QWORD *)&v9->m_vPos.x = *(_QWORD *)&v8->m_vPos.x;
      *(_QWORD *)&v9->m_vPos.z = *(_QWORD *)&v8->m_vPos.z;
      *(_QWORD *)&v9->m_vColor.m_vColor.y = *(_QWORD *)&v8->m_vColor.m_vColor.y;
      v9->m_vColor.m_flAlpha = v8->m_vColor.m_flAlpha;
    }
    ++v6;
    ++v7;
    --v4;
  }
  while ( v4 != 0 );
  return base;
}

//------------------------------------------------------------------------------
// Address: 0x004029F0
// Name: public: CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>>::~CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::~CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>(
        CUtlVector<CScratchPad3D::CBaseCommand *,CUtlMemory<CScratchPad3D::CBaseCommand *,int> > *this)
{
  bool v2; // sf
  CScratchPad3D::CBaseCommand **m_pMemory; // eax

  v2 = this->m_Memory.m_nGrowSize < 0;
  this->m_Size = 0;
  if ( !v2 )
  {
    if ( this->m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Memory.m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
  v2 = this->m_Memory.m_nGrowSize < 0;
  m_pMemory = this->m_Memory.m_pMemory;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( !v2 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Memory.m_pMemory = nullptr;
    }
    this->m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402A60
// Name: public: int CUtlVector<class CSPVert,class CUtlMemory<class CSPVert,int>>::InsertMultipleBefore(int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(
        CUtlVector<CSPVert,CUtlMemory<CSPVert,int> > *this,
        int elem,
        int num)
{
  int m_Size; // eax
  int m_nAllocationCount; // ecx
  CSPVert *m_pMemory; // ecx
  int v9; // eax
  int v10; // edx
  int v11; // eax
  unsigned int v12; // edx
  CSPVert *v13; // ecx
  int v14; // eax
  int v15; // edi
  CSPVert *v16; // ecx
  int i; // [esp+10h] [ebp+8h]

  if ( num == 0 )
    return elem;
  m_Size = this->m_Size;
  m_nAllocationCount = this->m_Memory.m_nAllocationCount;
  if ( m_Size + num > m_nAllocationCount )
    CUtlMemory<CSPVert,int>::Grow(this: &this->m_Memory, num: num + m_Size - m_nAllocationCount);
  this->m_Size += num;
  m_pMemory = this->m_Memory.m_pMemory;
  v9 = this->m_Size - elem - num;
  this->m_pElements = this->m_Memory.m_pMemory;
  if ( v9 > 0 && num > 0 )
    _V_memmove(dest: (void *)&m_pMemory[elem + num], src: &m_pMemory[elem], count: 28 * v9);
  v10 = 0;
  if ( num >= 4 )
  {
    v11 = elem;
    v12 = ((unsigned int)(num - 4) >> 2) + 1;
    i = 4 * v12;
    do
    {
      v13 = &this->m_Memory.m_pMemory[v11];
      if ( v13 != nullptr )
        v13->m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-28 )
        this->m_Memory.m_pMemory[v11 + 1].m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-56 )
        this->m_Memory.m_pMemory[v11 + 2].m_vColor.m_flAlpha = 1.0;
      if ( &this->m_Memory.m_pMemory[v11] != (CSPVert *)-84 )
        this->m_Memory.m_pMemory[v11 + 3].m_vColor.m_flAlpha = 1.0;
      v11 += 4;
      --v12;
    }
    while ( v12 != 0 );
    v10 = i;
  }
  if ( v10 < num )
  {
    v14 = v10 + elem;
    v15 = num - v10;
    do
    {
      v16 = &this->m_Memory.m_pMemory[v14];
      if ( v16 != nullptr )
        v16->m_vColor.m_flAlpha = 1.0;
      ++v14;
      --v15;
    }
    while ( v15 != 0 );
  }
  return elem;
}

//------------------------------------------------------------------------------
// Address: 0x00403F20
// Name: public: void CUtlVector<char,class CUtlMemory<char,int>>::CopyArray(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<char,CUtlMemory<char,int>>::CopyArray(
        CUtlVector<char,CUtlMemory<char,int> > *this,
        const char *pArray,
        int size)
{
  int m_nAllocationCount; // eax
  char *m_pMemory; // ecx
  int v6; // eax
  int i; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow(this: &this->m_Memory, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v6 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v6 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v6);
  }
  for ( i = 0; i < size; ++i )
    this->m_Memory.m_pMemory[i] = pArray[i];
}

//------------------------------------------------------------------------------
// Address: 0x00404180
// Name: void CommandRender_LinesStart(struct IDirect3DDevice8 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandRender_LinesStart()
{
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_ALPHABLENDENABLE, a3: 1u);
  g_pDevice->SetTexture(this: g_pDevice, a2: 0, a3: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x004041B0
// Name: void CommandRender_LinesStop(struct IDirect3DDevice8 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandRender_LinesStop()
{
  g_pDevice->DrawPrimitiveUP(
    this: g_pDevice,
    a2: D3DPT_LINELIST,
    a3: g_nLineBatchVerts / 2,
    a4: g_LineBatchVerts,
    a5: 24u);
  g_nLines += g_nLineBatchVerts / 2;
  g_nLineBatchVerts = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00404200
// Name: void CommandRender_Line(class CScratchPad3D::CBaseCommand __near *,struct IDirect3DDevice8 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandRender_Line(CScratchPad3D::CBaseCommand *pInCmd)
{
  int v1; // esi
  unsigned int v2; // ecx
  int v3; // esi
  CScratchPad3D::CBaseCommand_vtbl *v4; // xmm1_4
  float v5; // xmm2_4
  CScratchPad3D::CBaseCommand_vtbl *v6; // xmm3_4
  unsigned int v7; // ecx
  float v8; // xmm1_4
  float v9; // xmm3_4
  float v10; // xmm2_4

  v1 = g_nLineBatchVerts;
  if ( g_nLineBatchVerts == 1024 )
  {
    g_pDevice->DrawPrimitiveUP(this: g_pDevice, a2: D3DPT_LINELIST, a3: 512u, a4: g_LineBatchVerts, a5: 24u);
    g_nLines += g_nLineBatchVerts / 2;
    v1 = 0;
    g_nLineBatchVerts = 0;
  }
  v2 = 3 * v1;
  g_LineBatchVerts[v2 / 3].m_Pos.x = *(float *)&pInCmd[1].__vftable;
  v3 = v1 + 1;
  flt_437CD4[2 * v2] = *(float *)&pInCmd[1].m_iCommand;
  flt_437CD8[2 * v2] = *(float *)&pInCmd[1].m_pCachedRenderData;
  v4 = pInCmd[2].__vftable;
  v5 = *(float *)&pInCmd[2].m_iCommand;
  v6 = pInCmd[3].__vftable;
  byte_437CDC[8 * v2] = (int)(float)(*(float *)&pInCmd[2].m_pCachedRenderData * 255.89999);
  g_nLineBatchVerts = v3;
  byte_437CDD[8 * v2] = (int)(float)(v5 * 255.89999);
  byte_437CDE[8 * v2] = (int)(float)(*(float *)&v4 * 255.89999);
  byte_437CDF[8 * v2] = (int)(float)(*(float *)&v6 * 255.89999);
  v7 = 3 * v3;
  g_LineBatchVerts[v7 / 3].m_Pos.x = *(float *)&pInCmd[3].m_iCommand;
  flt_437CD4[2 * v7] = *(float *)&pInCmd[3].m_pCachedRenderData;
  flt_437CD8[2 * v7] = *(float *)&pInCmd[4].__vftable;
  v8 = *(float *)&pInCmd[4].m_iCommand;
  v9 = *(float *)&pInCmd[5].m_iCommand;
  v10 = *(float *)&pInCmd[4].m_pCachedRenderData * 255.89999;
  byte_437CDC[8 * v7] = (int)(float)(*(float *)&pInCmd[5].__vftable * 255.89999);
  byte_437CDD[8 * v7] = (int)v10;
  g_nLineBatchVerts = v3 + 1;
  byte_437CDE[8 * v7] = (int)(float)(v8 * 255.89999);
  byte_437CDF[8 * v7] = (int)(float)(v9 * 255.89999);
}

//------------------------------------------------------------------------------
// Address: 0x00404350
// Name: void CommandRender_Matrix(class CScratchPad3D::CBaseCommand __near *,struct IDirect3DDevice8 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandRender_Matrix(CScratchPad3D::CBaseCommand *pInCmd)
{
  VMatrix mTransposed; // [esp+0h] [ebp-40h] BYREF

  VMatrix::Transpose(this: (VMatrix *)&pInCmd[1], result: &mTransposed);
  g_pDevice->SetTransform(this: g_pDevice, a2: (_D3DTRANSFORMSTATETYPE)256, a3: (const _D3DMATRIX *)&mTransposed);
}

//------------------------------------------------------------------------------
// Address: 0x00404390
// Name: void CommandRender_RenderState(class CScratchPad3D::CBaseCommand __near *,struct IDirect3DDevice8 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandRender_RenderState(CScratchPad3D::CBaseCommand *pInCmd)
{
  CScratchPad3D::CBaseCommand_vtbl *v1; // eax
  char *v2; // eax
  HRESULT (__stdcall *SetRenderState)(IDirect3DDevice8 *, _D3DRENDERSTATETYPE, unsigned int); // edx

  v1 = pInCmd[1].__vftable;
  if ( v1 != nullptr )
  {
    v2 = (char *)&v1[-1].Write + 3;
    if ( v2 != nullptr )
    {
      if ( v2 == (char *)1 )
        g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_ZBIAS, a3: *(_DWORD *)&pInCmd[1].m_iCommand);
    }
    else
    {
      g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_ZENABLE, a3: *(_DWORD *)&pInCmd[1].m_iCommand);
    }
  }
  else
  {
    SetRenderState = g_pDevice->SetRenderState;
    if ( *(_DWORD *)&pInCmd[1].m_iCommand != 0 )
      SetRenderState(this: g_pDevice, a2: D3DRS_FILLMODE, a3: 3u);
    else
      SetRenderState(this: g_pDevice, a2: D3DRS_FILLMODE, a3: 2u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404400
// Name: bool CheckForNewFile(bool)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CheckForNewFile(bool bForce)
{
  HANDLE FileA; // esi
  char CommandsFromFile; // bl
  unsigned int v4; // eax
  int v5; // ecx
  _FILETIME createTime; // [esp+4h] [ebp-18h] BYREF
  _FILETIME accessTime; // [esp+Ch] [ebp-10h] BYREF
  _FILETIME writeTime; // [esp+14h] [ebp-8h] BYREF

  FileA = CreateFileA(
            lpFileName: g_pScratchPad->m_pFilename,
            dwDesiredAccess: 0x80000000,
            dwShareMode: 1u,
            lpSecurityAttributes: nullptr,
            dwCreationDisposition: 3u,
            dwFlagsAndAttributes: 0,
            hTemplateFile: nullptr);
  if ( FileA == nullptr )
    return 0;
  if ( !GetFileTime(
          hFile: FileA,
          lpCreationTime: &createTime,
          lpLastAccessTime: &accessTime,
          lpLastWriteTime: &writeTime) )
  {
    CloseHandle(hObject: FileA);
    return 0;
  }
  CommandsFromFile = 0;
  v4 = 8;
  v5 = 0;
  while ( *(unsigned int *)((char *)&writeTime.dwLowDateTime + v5) == *(unsigned int *)((char *)&g_LastWriteTime.dwLowDateTime
                                                                                      + v5) )
  {
    v4 -= 4;
    v5 += 4;
    if ( v4 < 4 )
    {
      if ( !bForce )
        goto LABEL_11;
      break;
    }
  }
  CommandsFromFile = CScratchPad3D::LoadCommandsFromFile(this: g_pScratchPad);
  if ( CommandsFromFile != 0 )
    g_LastWriteTime = writeTime;
LABEL_11:
  CloseHandle(hObject: FileA);
  return CommandsFromFile;
}

//------------------------------------------------------------------------------
// Address: 0x004044B0
// Name: void AppInit(void)
// Source: json
//------------------------------------------------------------------------------
// bad sp value at call has been detected, the output may be wrong!
void __usercall AppInit(int a1@<ebx>, int a2@<esi>)
{
  char *Arg; // ebx
  IFileSystem *v3; // esi
  CScratchPad3D *v4; // eax
  IDirect3DDevice8_vtbl *v5; // edx
  HRESULT (__stdcall *SetRenderState)(IDirect3DDevice8 *, _D3DRENDERSTATETYPE, unsigned int); // edx
  unsigned int v7; // esi
  char string[512]; // [esp+0h] [ebp-208h] BYREF
  unsigned int flZero; // [esp+200h] [ebp-8h]
  unsigned int flOne; // [esp+204h] [ebp-4h]

  g_ViewController.m_vPos.x = -200.0;
  g_ViewController.m_vPos.y = 0.0;
  g_ViewController.m_vPos.z = 0.0;
  g_ViewController.m_vAngles.x = 0.0;
  g_ViewController.m_vAngles.y = 0.0;
  g_ViewController.m_vAngles.z = 0.0;
  Arg = Sys_FindArg(pArg: "-file", pDefault: "scratch.pad");
  V_strncpy(pDest: g_Filename, pSrc: Arg, maxLen: 256);
  v3 = ScratchPad3D_SetupFileSystem();
  if ( v3 == nullptr || ((int (__thiscall *)(IFileSystem *, int, int))v3->Init)(a1: v3, a2, a3: a1) != 1 )
    Sys_Quit();
  v3->AddSearchPath(this: v3, a2: ".", a3: "PLATFORM", a4: PATH_ADD_TO_TAIL);
  v4 = (CScratchPad3D *)operator new(nSize: 0x24u);
  if ( v4 != nullptr )
    g_pScratchPad = CScratchPad3D::CScratchPad3D(this: v4, pFilename: Arg, pFileSystem: v3, bAutoClear: false);
  else
    g_pScratchPad = nullptr;
  g_nPolygons = 0;
  g_nLines = 0;
  sprintf(string, format: "ScratchPad3DViewer: <%s>  lines: %d, polygons: %d", g_Filename, 0, 0);
  Sys_SetWindowText(pMsg: string);
  v5 = g_pDevice->__vftable;
  flOne = 0;
  flZero = 40;
  ((void (__stdcall *)(IDirect3DDevice8 *))v5->SetRenderState)(a1: g_pDevice);
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_LIGHTING, a3: 0);
  g_pDevice->SetTextureStageState(this: g_pDevice, a2: 0, a3: D3DTSS_COLOROP, a4: 2u);
  g_pDevice->SetTextureStageState(this: g_pDevice, a2: 0, a3: D3DTSS_COLORARG1, a4: 0);
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_ALPHABLENDENABLE, a3: 0);
  g_pDevice->SetTexture(this: g_pDevice, a2: 0, a3: nullptr);
  SetRenderState = g_pDevice->SetRenderState;
  flOne = 1065353216;
  flZero = 0;
  SetRenderState(this: g_pDevice, a2: D3DRS_POINTSCALEENABLE, a3: 1u);
  v7 = flZero;
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_POINTSCALE_A, a3: flZero);
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_POINTSCALE_B, a3: v7);
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_POINTSCALE_C, a3: flOne);
  g_LastWriteTime = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004046C0
// Name: void AppChar(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppChar()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x00404760
// Name: void UpdateView(float,float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl UpdateView(float mouseDeltaX, float mouseDeltaY)
{
  float v2; // xmm1_4
  float v3; // xmm2_4
  float v4; // xmm0_4
  float v5; // xmm1_4
  const VMatrix *v6; // eax
  const VMatrix *v7; // eax
  VMatrix *v8; // eax
  const VMatrix *v9; // eax
  const VMatrix *v10; // eax
  const VMatrix *v11; // [esp+Ch] [ebp-26Ch]
  VMatrix v12; // [esp+10h] [ebp-268h] BYREF
  VMatrix v13; // [esp+50h] [ebp-228h] BYREF
  VMatrix v14; // [esp+90h] [ebp-1E8h] BYREF
  D3DXMATRIX matProj; // [esp+D0h] [ebp-1A8h] BYREF
  VMatrix v16; // [esp+110h] [ebp-168h] BYREF
  VMatrix mIdentity; // [esp+150h] [ebp-128h] BYREF
  VMatrix mRot; // [esp+190h] [ebp-E8h] BYREF
  VMatrix result; // [esp+1D0h] [ebp-A8h] BYREF
  VMatrix mD3DToVEngine; // [esp+210h] [ebp-68h] BYREF
  Vector vForward; // [esp+250h] [ebp-28h] BYREF
  float v22; // [esp+25Ch] [ebp-1Ch]
  Vector vRight; // [esp+260h] [ebp-18h] BYREF
  Vector vUp; // [esp+26Ch] [ebp-Ch] BYREF

  if ( Sys_HasFocus() )
  {
    AngleVectors(angles: &g_ViewController.m_vAngles, forward: &vForward, right: &vRight, up: &vUp);
    if ( Sys_GetKeyState(key: -1) )
    {
      if ( !Sys_GetKeyState(key: -2) )
      {
        g_ViewController.m_vAngles.y = g_ViewController.m_vAngles.y - (float)(fAngleScale * mouseDeltaX);
        g_ViewController.m_vAngles.x = (float)(fAngleScale * mouseDeltaY) + g_ViewController.m_vAngles.x;
        goto LABEL_9;
      }
      v2 = COERCE_FLOAT(LODWORD(mouseDeltaY) ^ _mask__NegFloat_) * vForward.x;
      v3 = COERCE_FLOAT(LODWORD(mouseDeltaY) ^ _mask__NegFloat_) * vForward.y;
      v4 = COERCE_FLOAT(LODWORD(mouseDeltaY) ^ _mask__NegFloat_) * vForward.z;
    }
    else
    {
      if ( !Sys_GetKeyState(key: -2) )
        goto LABEL_9;
      v2 = COERCE_FLOAT(LODWORD(mouseDeltaY) ^ _mask__NegFloat_) * vUp.x;
      v3 = COERCE_FLOAT(LODWORD(mouseDeltaY) ^ _mask__NegFloat_) * vUp.y;
      v4 = COERCE_FLOAT(LODWORD(mouseDeltaY) ^ _mask__NegFloat_) * vUp.z;
    }
    g_ViewController.m_vPos.z = (float)((float)(vRight.z * mouseDeltaX) * fDistScale)
                              + (float)((float)(v4 * fDistScale) + g_ViewController.m_vPos.z);
    g_ViewController.m_vPos.y = (float)((float)(vRight.y * mouseDeltaX) * fDistScale)
                              + (float)((float)(v3 * fDistScale) + g_ViewController.m_vPos.y);
    g_ViewController.m_vPos.x = (float)((float)(vRight.x * mouseDeltaX) * fDistScale)
                              + (float)((float)(v2 * fDistScale) + g_ViewController.m_vPos.x);
  }
LABEL_9:
  v22 = (float)Sys_ScreenWidth();
  v5 = (float)Sys_ScreenHeight();
  D3DXMatrixPerspectiveFovLH(a1: (int)&matProj, a2: 1.5707964, a3: v22 / v5, a4: 1.0, a5: 10000.0);
  g_pDevice->SetTransform(this: g_pDevice, a2: D3DTS_PROJECTION, a3: &matProj);
  *(_QWORD *)&mD3DToVEngine.m[0][0] = 0;
  memset(&mD3DToVEngine.m[1][2], 0, 12);
  memset(&mD3DToVEngine.m[2][3], 0, 12);
  *(_QWORD *)&mD3DToVEngine.m[3][2] = 0x3F80000000000000LL;
  g_ViewerPos = g_ViewController.m_vPos;
  *(_QWORD *)&mD3DToVEngine.m[0][2] = 1065353216;
  *(_QWORD *)&mD3DToVEngine.m[1][0] = 3212836864LL;
  *(_QWORD *)&mD3DToVEngine.m[2][1] = 1065353216;
  v6 = SetupMatrixAngles(&result, vAngles: &g_ViewController.m_vAngles);
  VMatrix::operator=(this: &mRot, mOther: v6);
  *(_QWORD *)&vUp.x = *(_QWORD *)&g_ViewerPos.x ^ 0x8000000080000000uLL;
  vUp.z = -g_ViewerPos.z;
  VMatrix::InverseGeneral(this: &mD3DToVEngine, vInverse: &result);
  v11 = SetupMatrixTranslation(result: &v14, vTranslation: &vUp);
  v7 = VMatrix::Transpose3x3(this: &mRot, result: &v13);
  v8 = VMatrix::operator*(this: &result, result: &v16, vm: v7);
  v9 = VMatrix::operator*(this: v8, result: &v12, vm: v11);
  VMatrix::operator=(this: &g_mModelView, mOther: v9);
  if ( (_S1 & 1) == 0 )
    _S1 |= 1u;
  v10 = VMatrix::Transpose(this: &g_mModelView, result: &v16);
  VMatrix::operator=(this: &stru_43DD38, mOther: v10);
  g_pDevice->SetTransform(this: g_pDevice, a2: D3DTS_VIEW, a3: (const _D3DMATRIX *)&stru_43DD38);
  SetupMatrixIdentity(result: &mIdentity);
  g_pDevice->SetTransform(this: g_pDevice, a2: (_D3DTRANSFORMSTATETYPE)256, a3: (const _D3DMATRIX *)&mIdentity);
}

//------------------------------------------------------------------------------
// Address: 0x00404B00
// Name: void CommandRender_Point(class CScratchPad3D::CBaseCommand __near *,struct IDirect3DDevice8 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandRender_Point(CScratchPad3D::CBaseCommand *pInCmd)
{
  CScratchPad3D::CBaseCommand_vtbl *v1; // xmm1_4
  int v2; // ecx
  int v3; // edx
  int v4; // eax
  float v5; // xmm1_4
  VertPosDiffuse vert; // [esp+4h] [ebp-18h] BYREF

  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_POINTSIZE, a3: (unsigned int)pInCmd[1].__vftable);
  v1 = pInCmd[3].__vftable;
  vert.m_Pos = *(Vector *)((char *)pInCmd + 16);
  v2 = (int)(float)(*(float *)&v1 * 255.89999);
  v3 = (int)(float)(*(float *)&pInCmd[2].m_pCachedRenderData * 255.89999);
  v4 = (int)(float)(*(float *)&pInCmd[2].m_iCommand * 255.89999);
  v5 = *(float *)&pInCmd[3].m_iCommand;
  vert.m_Diffuse[0] = v2;
  vert.m_Diffuse[3] = (int)(float)(v5 * 255.89999);
  vert.m_Diffuse[2] = v4;
  vert.m_Diffuse[1] = v3;
  g_pDevice->DrawPrimitiveUP(this: g_pDevice, a2: D3DPT_POINTLIST, a3: 1u, a4: &vert, a5: 24u);
}

//------------------------------------------------------------------------------
// Address: 0x00404BB0
// Name: public: virtual void CCachedTextData::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CCachedTextData::Release(CCachedTextData *this)
{
  IDirect3DTexture8 *m_pTexture; // eax

  if ( this != nullptr )
  {
    m_pTexture = this->m_pTexture;
    this->__vftable = (CCachedTextData_vtbl *)&CCachedTextData::`vftable';
    if ( m_pTexture != nullptr )
      m_pTexture->Release(this: m_pTexture);
    free(pMem: this);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BE0
// Name: struct IDirect3DTexture8 __near * MakeD3DTextureFromBitmap(class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &,int,int,bool)
// Source: json
//------------------------------------------------------------------------------
IDirect3DTexture8 *__cdecl MakeD3DTextureFromBitmap(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *bitmap,
        int width,
        int height,
        bool bSolidBackground)
{
  int v4; // ebx
  int v5; // esi
  int v6; // eax
  int v8; // edi
  int v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // dl
  _D3DLOCKED_RECT lockedRect; // [esp+Ch] [ebp-10h] BYREF
  unsigned __int8 *pDestData; // [esp+14h] [ebp-8h]
  IDirect3DTexture8 *pRet; // [esp+18h] [ebp-4h] BYREF

  v4 = width;
  v5 = 0;
  pRet = nullptr;
  v6 = g_pDevice->CreateTexture(
         this: g_pDevice,
         a2: width,
         a3: height,
         a4: 1u,
         a5: 0,
         a6: D3DFMT_A8R8G8B8,
         a7: D3DPOOL_MANAGED,
         a8: &pRet);
  if ( pRet == nullptr || v6 < 0 )
    return nullptr;
  if ( pRet->LockRect(this: pRet, a2: 0, a3: &lockedRect, a4: nullptr, a5: 0) < 0 )
  {
    pRet->Release(this: pRet);
    return nullptr;
  }
  pDestData = (unsigned __int8 *)lockedRect.pBits;
  if ( height > 0 )
  {
    v8 = 0;
    do
    {
      v9 = 0;
      if ( v4 > 0 )
      {
        do
        {
          v10 = &pDestData[4 * v9 + v5 * lockedRect.Pitch];
          v11 = bitmap->m_Memory.m_pMemory[v8 + v9];
          if ( bSolidBackground )
          {
            v10[3] = -1;
            v10[2] = v11;
            v10[1] = v11;
            *v10 = v11;
          }
          else
          {
            *(_WORD *)(v10 + 1) = -1;
            *v10 = -1;
            v10[3] = v11;
          }
          ++v9;
        }
        while ( v9 < width );
        v4 = width;
      }
      ++v5;
      v8 += v4;
    }
    while ( v5 < height );
  }
  pRet->UnlockRect(this: pRet, a2: 0);
  return pRet;
}

//------------------------------------------------------------------------------
// Address: 0x00404CC0
// Name: void CommandRender_Polygon(class CScratchPad3D::CBaseCommand __near *,struct IDirect3DDevice8 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandRender_Polygon(CScratchPad3D::CBaseCommand *pInCmd)
{
  int v1; // esi
  CScratchPad3D::CBaseCommand_vtbl *v2; // ecx
  unsigned __int8 *v3; // eax
  int v4; // edi
  float v5; // xmm0_4
  float v6; // xmm1_4
  float v7; // xmm2_4
  VertPosDiffuse *v8; // eax
  IDirect3DDevice8 *v9; // ecx
  IDirect3DDevice8_vtbl *v10; // edx
  VertPosDiffuse verts[65]; // [esp+4h] [ebp-618h] BYREF

  v1 = (int)pInCmd[2].__vftable;
  if ( v1 > 64 )
    v1 = 64;
  if ( v1 > 0 )
  {
    v2 = pInCmd[1].__vftable;
    v3 = &verts[0].m_Diffuse[1];
    v4 = v1;
    do
    {
      v3 += 24;
      *(float *)(v3 - 37) = *(float *)&v2->Read;
      v2 = (CScratchPad3D::CBaseCommand_vtbl *)((char *)v2 + 28);
      --v4;
      *(float *)(v3 - 33) = *(float *)&v2[-3].Read;
      *(float *)(v3 - 29) = *(float *)&v2[-3].Write;
      v5 = *(float *)&v2[-2].Read;
      v6 = *(float *)&v2[-2].Write;
      v7 = *(float *)&v2[-1].Write;
      *(v3 - 25) = (int)(float)(*(float *)&v2[-1].Read * 255.89999);
      *(v3 - 24) = (int)(float)(v6 * 255.89999);
      *(v3 - 23) = (int)(float)(v5 * 255.89999);
      *(v3 - 22) = (int)(float)(v7 * 255.89999);
    }
    while ( v4 != 0 );
  }
  g_pDevice->GetRenderState(this: g_pDevice, a2: D3DRS_FILLMODE, a3: (unsigned int *)&pInCmd);
  if ( pInCmd == (CScratchPad3D::CBaseCommand *)2 )
  {
    if ( v1 >= 2 )
    {
      g_pDevice->DrawPrimitiveUP(this: g_pDevice, a2: D3DPT_LINESTRIP, a3: v1 - 1, a4: verts, a5: 24u);
      verts[v1].m_Pos.x = verts[0].m_Pos.x;
      v8 = &verts[v1];
      v8->m_Pos.y = verts[0].m_Pos.y;
      v8->m_Pos.z = verts[0].m_Pos.z;
      v8->m_Diffuse[0] = verts[0].m_Diffuse[0];
      v8->m_Diffuse[1] = verts[0].m_Diffuse[1];
      v8->m_Diffuse[2] = verts[0].m_Diffuse[2];
      v9 = g_pDevice;
      v8->m_Diffuse[3] = verts[0].m_Diffuse[3];
      v10 = v9->__vftable;
      v8->m_tCoords = verts[0].m_tCoords;
      v10->DrawPrimitiveUP(this: v9, a2: D3DPT_LINESTRIP, a3: 1u, a4: &v8[-1], a5: 24u);
      ++g_nPolygons;
      return;
    }
  }
  else
  {
    g_pDevice->DrawPrimitiveUP(this: g_pDevice, a2: D3DPT_TRIANGLEFAN, a3: v1 - 2, a4: verts, a5: 24u);
  }
  ++g_nPolygons;
}

//------------------------------------------------------------------------------
// Address: 0x00404E60
// Name: void RunCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl RunCommands()
{
  CScratchPad3D *v0; // eax
  int v1; // ebx
  int v2; // esi
  CScratchPad3D::CBaseCommand *v3; // edi
  unsigned __int8 m_iCommand; // cl
  void (__cdecl *v5)(IDirect3DDevice8 *); // eax
  void (__cdecl *v6)(IDirect3DDevice8 *); // eax
  VMatrix mIdentity; // [esp+8h] [ebp-40h] BYREF

  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_FILLMODE, a3: 3u);
  g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_ZENABLE, a3: 1u);
  SetupMatrixIdentity(result: &mIdentity);
  g_pDevice->SetTransform(this: g_pDevice, a2: (_D3DTRANSFORMSTATETYPE)256, a3: (const _D3DMATRIX *)&mIdentity);
  v0 = g_pScratchPad;
  v1 = 0;
  v2 = -1;
  if ( g_pScratchPad->m_Commands.m_Size > 0 )
  {
    do
    {
      v3 = v0->m_Commands.m_Memory.m_pMemory[v1];
      m_iCommand = v3->m_iCommand;
      if ( m_iCommand < 6u )
      {
        if ( m_iCommand != v2 )
        {
          if ( v2 != -1 )
          {
            v5 = (void (__cdecl *)(IDirect3DDevice8 *))dword_43620C[3 * v2];
            if ( v5 != nullptr )
              v5(a1: g_pDevice);
          }
          v2 = v3->m_iCommand;
          if ( g_CommandRenderFunctions[v2].m_StartFn != nullptr )
            g_CommandRenderFunctions[v3->m_iCommand].m_StartFn(a1: g_pDevice);
        }
        ((void (__cdecl *)())funcs_404F45[3 * v3->m_iCommand])();
        v0 = g_pScratchPad;
      }
      ++v1;
    }
    while ( v1 < v0->m_Commands.m_Size );
    if ( v2 != -1 )
    {
      v6 = (void (__cdecl *)(IDirect3DDevice8 *))dword_43620C[3 * v2];
      if ( v6 != nullptr )
        v6(a1: g_pDevice);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404F80
// Name: void AppRender(float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppRender(float frametime, float mouseDeltaX, float mouseDeltaY, bool bInvalidRect)
{
  char string[512]; // [esp+30h] [ebp-200h] BYREF

  g_nLines = 0;
  g_nPolygons = 0;
  g_pDevice->SetVertexShader(this: g_pDevice, a2: 322u);
  if ( bInvalidRect || Sys_GetKeyState(key: -1) || Sys_GetKeyState(key: -2) || CheckForNewFile(bForce: false) != 0 )
  {
    ((void (__stdcall *)(IDirect3DDevice8 *, _DWORD, _DWORD, int, _DWORD, int, _DWORD))g_pDevice->Clear)(
      a1: g_pDevice,
      a2: 0,
      a3: 0,
      a4: 3,
      a5: 0,
      a6: 1065353216,
      a7: 0);
    g_pDevice->BeginScene(this: g_pDevice);
    UpdateView(mouseDeltaX, mouseDeltaY);
    RunCommands();
    g_pDevice->EndScene(this: g_pDevice);
    g_pDevice->Present(this: g_pDevice, a2: nullptr, a3: nullptr, a4: nullptr, a5: nullptr);
    sprintf(string, format: "ScratchPad3DViewer: <%s>  lines: %d, polygons: %d", g_Filename, g_nLines, g_nPolygons);
    Sys_SetWindowText(pMsg: string);
  }
  else
  {
    Sys_Sleep(ms: 0x64u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004050B0
// Name: void AppPreResize(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppPreResize()
{
  CScratchPad3D *v0; // eax
  int i; // edi
  CScratchPad3D::CBaseCommand *v2; // esi
  CScratchPad3D::ICachedRenderData *m_pCachedRenderData; // ecx

  v0 = g_pScratchPad;
  for ( i = 0; i < v0->m_Commands.m_Size; ++i )
  {
    v2 = v0->m_Commands.m_Memory.m_pMemory[i];
    if ( v2->m_iCommand == 5 )
    {
      m_pCachedRenderData = v2->m_pCachedRenderData;
      if ( m_pCachedRenderData != nullptr )
      {
        m_pCachedRenderData->Release(this: m_pCachedRenderData);
        v2->m_pCachedRenderData = nullptr;
        v0 = g_pScratchPad;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004050F0
// Name: void AppKey(int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppKey(int key)
{
  if ( key == 27 )
  {
    Sys_Quit();
  }
  else if ( toupper(c: key) == 85 )
  {
    CheckForNewFile(bForce: true);
    AppRender(frametime: 0.1, mouseDeltaX: 0.0, mouseDeltaY: 0.0, bInvalidRect: true);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405150
// Name: public: void CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>>::SetSize(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *this,
        int size)
{
  int m_nAllocationCount; // eax
  unsigned __int8 *m_pMemory; // ecx
  int v5; // eax

  this->m_Size = 0;
  if ( size != 0 )
  {
    m_nAllocationCount = this->m_Memory.m_nAllocationCount;
    if ( size > m_nAllocationCount )
      CUtlMemory<char,int>::Grow((CUtlMemory<char,int> *)this, num: size - m_nAllocationCount);
    this->m_Size += size;
    m_pMemory = this->m_Memory.m_pMemory;
    v5 = this->m_Size - size;
    this->m_pElements = this->m_Memory.m_pMemory;
    if ( v5 > 0 && size > 0 )
      _V_memmove(dest: &m_pMemory[size], src: m_pMemory, count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004051A0
// Name: void GenerateTextGreyscaleBitmap(char const __near *,class CUtlVector<unsigned char,class CUtlMemory<unsigned char,int>> __near &,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GenerateTextGreyscaleBitmap(
        const char *pText,
        CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > *bitmap,
        tagSIZE *pWidth,
        int *pHeight)
{
  HDC__ *CompatibleDC; // esi
  HFONT__ *FontA; // edi
  HBITMAP__ *v6; // ebx
  int v7; // edi
  int cx; // ecx
  int cy; // eax
  char *v10; // edi
  int v11; // ebx
  int v12; // edi
  int *v13; // esi
  tagBITMAPINFOHEADER bmi; // [esp+Ch] [ebp-48h] BYREF
  tagSIZE size; // [esp+34h] [ebp-20h] BYREF
  HBITMAP__ *hBitmap; // [esp+3Ch] [ebp-18h]
  HBITMAP__ *hOldBitmap; // [esp+40h] [ebp-14h]
  HFONT__ *hFont; // [esp+44h] [ebp-10h]
  HFONT__ *hOldFont; // [esp+48h] [ebp-Ch]
  HDC__ *hDC; // [esp+4Ch] [ebp-8h]
  void *pBits; // [esp+50h] [ebp-4h] BYREF
  int y; // [esp+64h] [ebp+10h]
  int *pHeighta; // [esp+68h] [ebp+14h]

  *pHeight = 0;
  pWidth->cx = 0;
  CompatibleDC = CreateCompatibleDC(hdc: nullptr);
  hDC = CompatibleDC;
  FontA = CreateFontA(
            cHeight: 18,
            cWidth: 0,
            cEscapement: 0,
            cOrientation: 0,
            cWeight: 500,
            bItalic: 0,
            bUnderline: 0,
            bStrikeOut: 0,
            iCharSet: 0,
            iOutPrecision: 0,
            iClipPrecision: 0,
            iQuality: 4u,
            iPitchAndFamily: 0,
            pszFaceName: "Arial");
  hFont = FontA;
  if ( FontA != nullptr )
  {
    bmi.biSize = 40;
    bmi.biWidth = 512;
    bmi.biHeight = -64;
    *(_DWORD *)&bmi.biPlanes = 1572865;
    memset(&bmi.biCompression, 0, 24);
    pBits = nullptr;
    v6 = CreateDIBSection(
           hdc: CompatibleDC,
           pbmi: (const BITMAPINFO *)&bmi,
           usage: 0,
           ppvBits: &pBits,
           hSection: nullptr,
           offset: 0);
    hBitmap = v6;
    if ( v6 == nullptr )
    {
      DeleteObject(ho: FontA);
      DeleteDC(hdc: CompatibleDC);
      return;
    }
    hOldFont = (HFONT__ *)SelectObject(hdc: CompatibleDC, h: FontA);
    hOldBitmap = (HBITMAP__ *)SelectObject(hdc: CompatibleDC, h: v6);
    v7 = strlen(pText);
    GetTextExtentPoint32A(hdc: CompatibleDC, lpString: pText, c: v7, psizl: &size);
    TextOutA(hdc: CompatibleDC, x: 0, y: 0, lpString: pText, c: v7);
    cx = size.cx;
    cy = size.cy;
    v10 = (char *)pBits;
    *pWidth = size;
    CUtlVector<unsigned char,CUtlMemory<unsigned char,int>>::SetSize(this: bitmap, size: cx * cy);
    y = 0;
    if ( size.cy > 0 )
    {
      v11 = size.cx;
      pHeighta = (int *)(v10 + 1);
      do
      {
        v12 = 0;
        if ( v11 > 0 )
        {
          v13 = pHeighta;
          do
          {
            ++v12;
            bitmap->m_Memory.m_pMemory[v11 * y - 1 + v12] = -1
                                                          - ((unsigned __int64)(1431655766LL
                                                                              * (*(unsigned __int8 *)v13
                                                                               + *((unsigned __int8 *)v13 + 1)
                                                                               + *((unsigned __int8 *)v13 - 1))) >> 32);
            v11 = size.cx;
            v13 = (int *)((char *)v13 + 3);
          }
          while ( v12 < size.cx );
          CompatibleDC = hDC;
        }
        pHeighta += 384;
        ++y;
      }
      while ( y < size.cy );
    }
    SelectObject(hdc: CompatibleDC, h: hOldFont);
    DeleteObject(ho: hFont);
    SelectObject(hdc: CompatibleDC, h: hOldBitmap);
    DeleteObject(ho: hBitmap);
  }
  DeleteDC(hdc: CompatibleDC);
}

//------------------------------------------------------------------------------
// Address: 0x00405370
// Name: void CommandRender_Text(class CScratchPad3D::CBaseCommand __near *,struct IDirect3DDevice8 __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CommandRender_Text(CScratchPad3D::CBaseCommand *pInCmd)
{
  CScratchPad3D::CBaseCommand *v1; // esi
  CCachedTextData *m_pCachedRenderData; // edi
  CCachedTextData *v3; // eax
  CScratchPad3D::ICachedRenderData *v4; // edi
  IDirect3DTexture8 *D3DTextureFromBitmap; // eax
  int v6; // edx
  int v7; // eax
  float v8; // xmm4_4
  float v9; // xmm5_4
  float v10; // xmm6_4
  char v11; // al
  float y; // xmm7_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  float x; // xmm2_4
  float v16; // xmm3_4
  float v17; // xmm7_4
  float v18; // xmm0_4
  float v19; // xmm2_4
  float v20; // xmm3_4
  float v21; // xmm0_4
  float v22; // xmm7_4
  float v23; // xmm1_4
  float z; // xmm2_4
  int v25; // ecx
  int v26; // eax
  float v27; // xmm1_4
  float v28; // xmm0_4
  int v29; // edx
  float v30; // xmm1_4
  float *p_z; // eax
  int i; // esi
  char v33; // dl
  char v34; // dl
  int v35; // edi
  unsigned int *v36; // esi
  unsigned int *v37; // esi
  int j; // edi
  unsigned int *v39; // esi
  int k; // edi
  unsigned int *v41; // esi
  int m; // edi
  CScratchPad3D::CBaseCommand_vtbl *v43; // [esp-10h] [ebp-178h]
  unsigned int tss[6][3]; // [esp+Ch] [ebp-15Ch] BYREF
  unsigned int rss[5][3]; // [esp+54h] [ebp-114h] BYREF
  Vector vForward; // [esp+90h] [ebp-D8h] BYREF
  VertPosDiffuse quad[5]; // [esp+9Ch] [ebp-CCh] BYREF
  float v48; // [esp+114h] [ebp-54h]
  float v49; // [esp+118h] [ebp-50h]
  float v50; // [esp+11Ch] [ebp-4Ch]
  Vector vUp; // [esp+120h] [ebp-48h] BYREF
  CUtlVector<unsigned char,CUtlMemory<unsigned char,int> > bitmap; // [esp+12Ch] [ebp-3Ch] BYREF
  Vector vRight; // [esp+140h] [ebp-28h] BYREF
  Vector vShift; // [esp+14Ch] [ebp-1Ch] BYREF
  int width; // [esp+158h] [ebp-10h] BYREF
  int height; // [esp+15Ch] [ebp-Ch] BYREF
  CCachedTextData *pCached; // [esp+160h] [ebp-8h]
  char v58; // [esp+165h] [ebp-3h]
  char v59; // [esp+166h] [ebp-2h]
  char v60; // [esp+167h] [ebp-1h]

  v1 = pInCmd;
  m_pCachedRenderData = (CCachedTextData *)pInCmd->m_pCachedRenderData;
  pCached = m_pCachedRenderData;
  if ( m_pCachedRenderData == nullptr )
  {
    v43 = pInCmd[1].__vftable;
    memset(&bitmap, 0, sizeof(bitmap));
    GenerateTextGreyscaleBitmap(pText: (const char *)v43, &bitmap, pWidth: (tagSIZE *)&width, pHeight: &height);
    v3 = (CCachedTextData *)operator new(nSize: 0x14u);
    if ( v3 != nullptr )
    {
      v4 = v3;
      v3->__vftable = (CCachedTextData_vtbl *)&CCachedTextData::`vftable';
      v3->m_pTexture = nullptr;
      pCached = v3;
    }
    else
    {
      pCached = nullptr;
      v4 = nullptr;
    }
    D3DTextureFromBitmap = MakeD3DTextureFromBitmap(&bitmap, width, height, bSolidBackground: (bool)v1[4].__vftable);
    v6 = width;
    v4[1].__vftable = (CScratchPad3D::ICachedRenderData_vtbl *)D3DTextureFromBitmap;
    v7 = height;
    v4[2].__vftable = (CScratchPad3D::ICachedRenderData_vtbl *)v6;
    v4[3].__vftable = (CScratchPad3D::ICachedRenderData_vtbl *)v7;
    v4[4].__vftable = (CScratchPad3D::ICachedRenderData_vtbl *)strlen((const char *)v1[1].__vftable);
    v1->m_pCachedRenderData = v4;
    CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::~CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>(this: (CUtlVector<CScratchPad3D::CBaseCommand *,CUtlMemory<CScratchPad3D::CBaseCommand *,int> > *)&bitmap);
    m_pCachedRenderData = pCached;
  }
  AngleVectors(angles: (const QAngle *)&v1[5].m_pCachedRenderData, forward: &vForward, right: &vRight, up: &vUp);
  v8 = *(float *)&v1[4].m_iCommand;
  v9 = *(float *)&v1[4].m_pCachedRenderData;
  v10 = *(float *)&v1[5].__vftable;
  v11 = 1;
  if ( (float)((float)((float)(vForward.y * (float)(g_ViewerPos.y - v9))
                     + (float)((float)(g_ViewerPos.x - v8) * vForward.x))
             + (float)(vForward.z * (float)(g_ViewerPos.z - v10))) < 0.0 )
  {
    if ( LOBYTE(v1[6].m_pCachedRenderData) == 0 )
      return;
    v11 = 0;
  }
  y = vRight.y;
  v13 = *(float *)&v1[7].__vftable * (float)m_pCachedRenderData->m_nChars;
  v14 = (float)(v13 / (float)m_pCachedRenderData->m_nChars) * 3.0;
  x = vRight.x;
  memset(&vShift, 0, sizeof(vShift));
  if ( v1[5].m_iCommand != 0 )
  {
    v48 = vUp.x * (float)(v14 * 0.5);
    v49 = vUp.y * (float)(v14 * 0.5);
    v50 = vUp.z * (float)(v14 * 0.5);
    *(float *)&bitmap.m_Size = vRight.y * (float)(v13 * -0.5);
    vShift.y = *(float *)&bitmap.m_Size + v49;
    x = vRight.x;
    vShift.z = (float)(vRight.z * (float)(v13 * -0.5)) + v50;
    y = vRight.y;
    vShift.x = (float)(vRight.x * (float)(v13 * -0.5)) + v48;
  }
  v16 = y * v13;
  v17 = (float)(vRight.z * v13) + v10;
  v18 = (float)(x * v13) + v8;
  v19 = v16 + v9;
  v20 = v17;
  *(float *)&height = vUp.x * v14;
  quad[1].m_Pos.x = v18;
  v21 = v18 - (float)(vUp.x * v14);
  *(float *)&width = vUp.y * v14;
  v22 = vUp.z * v14;
  v23 = vUp.y * v14;
  *(float *)&bitmap.m_Memory.m_nGrowSize = v21;
  quad[1].m_Pos.y = v19;
  quad[1].m_Pos.z = v20;
  quad[2].m_Pos.x = v21;
  quad[0].m_Pos.x = v8;
  quad[0].m_Pos.y = v9;
  quad[0].m_Pos.z = v10;
  quad[2].m_Pos.y = v19 - v23;
  quad[2].m_Pos.z = v20 - v22;
  quad[3].m_Pos.x = v8 - *(float *)&height;
  quad[3].m_Pos.y = v9 - v23;
  quad[3].m_Pos.z = v10 - v22;
  quad[2].m_tCoords.y = 1.0;
  quad[3].m_tCoords.y = 1.0;
  quad[0].m_tCoords.y = 0.0;
  quad[1].m_tCoords.y = 0.0;
  if ( v11 != 0 )
  {
    quad[0].m_tCoords.x = 1.0;
    quad[1].m_tCoords.x = 0.0;
    quad[2].m_tCoords.x = 0.0;
    quad[3].m_tCoords.x = 1.0;
  }
  else
  {
    quad[0].m_tCoords.x = 0.0;
    quad[1].m_tCoords.x = 1.0;
    quad[2].m_tCoords.x = 1.0;
    quad[3].m_tCoords.x = 0.0;
  }
  z = vShift.z;
  v25 = (int)(float)(*(float *)&v1[3].m_iCommand * 255.89999);
  v26 = (int)(float)(*(float *)&v1[2].m_pCachedRenderData * 255.89999);
  v27 = *(float *)&v1[3].m_pCachedRenderData * 255.89999;
  v28 = vShift.x;
  v59 = (int)(float)(*(float *)&v1[3].__vftable * 255.89999);
  v29 = (int)v27;
  v30 = vShift.y;
  v60 = v26;
  v58 = v29;
  p_z = &quad[0].m_Pos.z;
  for ( i = 4; i != 0; --i )
  {
    v33 = v59;
    *(p_z - 2) = *(p_z - 2) + v28;
    *(p_z - 1) = v30 + *(p_z - 1);
    *p_z = z + *p_z;
    *((_BYTE *)p_z + 5) = v33;
    *((_BYTE *)p_z + 6) = v60;
    v34 = v58;
    *((_BYTE *)p_z + 4) = v25;
    *((_BYTE *)p_z + 7) = v34;
    p_z += 6;
  }
  *(_QWORD *)&tss[1][0] = 2;
  *(_QWORD *)&tss[3][0] = 0x400000004LL;
  v35 = 6;
  *(_QWORD *)&tss[4][0] = 5;
  *(_QWORD *)&tss[0][0] = 0x400000001LL;
  tss[0][2] = 0;
  tss[1][2] = 0;
  *(_QWORD *)&tss[2][0] = 0x200000003LL;
  tss[2][2] = 0;
  tss[3][2] = 0;
  tss[4][2] = 0;
  *(_QWORD *)&tss[5][0] = 0x200000006LL;
  tss[5][2] = 0;
  *(_QWORD *)&rss[0][0] = 0x10000001BLL;
  rss[0][2] = 0;
  *(_QWORD *)&rss[1][0] = 0x300000008LL;
  rss[1][2] = 0;
  *(_QWORD *)&rss[2][0] = 0x500000013LL;
  rss[2][2] = 0;
  *(_QWORD *)&rss[3][0] = 0x600000014LL;
  rss[3][2] = 0;
  *(_QWORD *)&rss[4][0] = 0x300000008LL;
  rss[4][2] = 0;
  v36 = tss[0];
  do
  {
    g_pDevice->GetTextureStageState(this: g_pDevice, a2: 0, a3: (_D3DTEXTURESTAGESTATETYPE)*v36, a4: v36 + 2);
    g_pDevice->SetTextureStageState(this: g_pDevice, a2: 0, a3: (_D3DTEXTURESTAGESTATETYPE)*v36, a4: v36[1]);
    v36 += 3;
    --v35;
  }
  while ( v35 != 0 );
  v37 = rss[0];
  for ( j = 5; j != 0; --j )
  {
    g_pDevice->GetRenderState(this: g_pDevice, a2: (_D3DRENDERSTATETYPE)*v37, a3: v37 + 2);
    g_pDevice->SetRenderState(this: g_pDevice, a2: (_D3DRENDERSTATETYPE)*v37, a3: v37[1]);
    v37 += 3;
  }
  g_pDevice->SetTexture(this: g_pDevice, a2: 0, a3: pCached->m_pTexture);
  g_pDevice->DrawPrimitiveUP(this: g_pDevice, a2: D3DPT_TRIANGLEFAN, a3: 2u, a4: quad, a5: 24u);
  g_pDevice->SetTexture(this: g_pDevice, a2: 0, a3: nullptr);
  ++g_nPolygons;
  v39 = tss[0];
  for ( k = 6; k != 0; --k )
  {
    g_pDevice->SetTextureStageState(this: g_pDevice, a2: 0, a3: (_D3DTEXTURESTAGESTATETYPE)*v39, a4: v39[2]);
    v39 += 3;
  }
  v41 = rss[0];
  for ( m = 5; m != 0; --m )
  {
    g_pDevice->SetRenderState(this: g_pDevice, a2: (_D3DRENDERSTATETYPE)*v41, a3: v41[2]);
    v41 += 3;
  }
  if ( BYTE1(pInCmd[4].__vftable) != 0 )
  {
    g_pDevice->GetRenderState(this: g_pDevice, a2: D3DRS_FILLMODE, a3: (unsigned int *)&pInCmd);
    g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_FILLMODE, a3: 2u);
    quad[4] = quad[0];
    g_pDevice->DrawPrimitiveUP(this: g_pDevice, a2: D3DPT_LINESTRIP, a3: 4u, a4: quad, a5: 24u);
    g_pDevice->SetRenderState(this: g_pDevice, a2: D3DRS_FILLMODE, a3: (unsigned int)pInCmd);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A55
// Name: DXGetErrorString8A(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__stdcall DXGetErrorString8A(int a1)
{
  const char *result; // eax

  if ( a1 > -2005532337 )
  {
    if ( a1 > -2005397239 )
    {
      if ( a1 > -2005397136 )
      {
        if ( a1 > 1 )
        {
          if ( a1 > 262403 )
          {
            if ( a1 <= 262796 )
            {
              if ( a1 == 262796 )
                return "VFW_S_DVD_CHANNEL_CONTENTS_NOT_AVAILABLE";
              if ( a1 > 262744 )
              {
                if ( a1 > 262760 )
                {
                  switch ( a1 )
                  {
                    case 262768:
                      return "VFW_S_NO_STOP_TIME";
                    case 262782:
                      return "VFW_S_NOPREVIEWPIN";
                    case 262784:
                      return "VFW_S_DVD_NON_ONE_SEQUENTIAL";
                    default:
                      break;
                  }
                }
                else
                {
                  switch ( a1 )
                  {
                    case 262760:
                      return "VFW_S_CANT_CUE";
                    case 262746:
                      return "VFW_S_RPZA";
                    case 262752:
                      return "VFW_S_ESTIMATED";
                    case 262755:
                      return "VFW_S_RESERVED";
                    case 262759:
                      return "VFW_S_STREAM_OFF";
                    default:
                      break;
                  }
                }
              }
              else
              {
                if ( a1 == 262744 )
                  return "VFW_S_AUDIO_NOT_RENDERED";
                if ( a1 > 262726 )
                {
                  switch ( a1 )
                  {
                    case 262736:
                      return "VFW_S_RESOURCE_NOT_NEEDED";
                    case 262740:
                      return "VFW_S_MEDIA_TYPE_IGNORED";
                    case 262743:
                      return "VFW_S_VIDEO_NOT_RENDERED";
                    default:
                      break;
                  }
                }
                else
                {
                  switch ( a1 )
                  {
                    case 262726:
                      return "VFW_S_CONNECTIONS_DEFERRED";
                    case 262701:
                      return "VFW_S_DUPLICATE_NAME";
                    case 262711:
                      return "VFW_S_STATE_INTERMEDIATE";
                    case 262722:
                      return "VFW_S_PARTIAL_RENDER";
                    case 262725:
                      return "VFW_S_SOME_DATA_IGNORED";
                    default:
                      break;
                  }
                }
              }
              return "Unknown";
            }
            if ( a1 <= 142086657 )
            {
              if ( a1 == 142086657 )
                return "DMUS_S_FREE";
              if ( a1 > 142082058 )
              {
                switch ( a1 )
                {
                  case 142086289:
                    return "DMUS_S_PARTIALLOAD";
                  case 142086290:
                    return "DMUS_S_PARTIALDOWNLOAD";
                  case 142086656:
                    return "DMUS_S_REQUEUE";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case 142082058:
                    return "DS_NO_VIRTUALIZATION";
                  case 262797:
                    return "VFW_S_DVD_NOT_ACCURATE";
                  case 1376261:
                    return "DV_FULLDUPLEX";
                  case 1376266:
                    return "DV_HALFDUPLEX";
                  case 1376272:
                    return "DV_PENDING";
                  default:
                    break;
                }
              }
              return "Unknown";
            }
            if ( a1 <= 142086675 )
            {
              switch ( a1 )
              {
                case 142086675:
                  return "DMUS_S_UP_OCTAVE";
                case 142086658:
                  return "DMUS_S_END";
                case 142086672:
                  return "DMUS_S_STRING_TRUNCATED";
                case 142086673:
                  return "DMUS_S_LAST_TOOL";
                case 142086674:
                  return "DMUS_S_OVER_CHORD";
                default:
                  break;
              }
              return "Unknown";
            }
            switch ( a1 )
            {
              case 142086676:
                return "DMUS_S_DOWN_OCTAVE";
              case 142086677:
                return "DMUS_S_NOBUFFERCONTROL";
              case 142086678:
                return "DMUS_S_GARBAGE_COLLECTED";
              default:
                return "Unknown";
            }
          }
          else if ( a1 == 262403 )
          {
            return "VFW_S_NO_MORE_ITEMS";
          }
          else
          {
            switch ( a1 )
            {
              case 2:
                return "ERROR_FILE_NOT_FOUND";
              case 3:
                result = "ERROR_PATH_NOT_FOUND";
                break;
              case 4:
                result = "ERROR_TOO_MANY_OPEN_FILES";
                break;
              case 5:
                result = "ERROR_ACCESS_DENIED";
                break;
              case 6:
                result = "ERROR_INVALID_HANDLE";
                break;
              case 8:
                result = "ERROR_NOT_ENOUGH_MEMORY";
                break;
              case 9:
                result = "ERROR_INVALID_BLOCK";
                break;
              case 10:
                result = "ERROR_BAD_ENVIRONMENT";
                break;
              case 11:
                result = "ERROR_BAD_FORMAT";
                break;
              case 14:
                result = "ERROR_OUTOFMEMORY";
                break;
              default:
                return "Unknown";
            }
          }
        }
        else
        {
          if ( a1 == 1 )
            return "S_FALSE";
          if ( a1 > -2005396967 )
          {
            if ( a1 != 0 )
            {
              switch ( a1 )
              {
                case -2005396966:
                  result = "DMUS_E_SCRIPT_VARIABLE_NOT_FOUND";
                  break;
                case -2005396965:
                  result = "DMUS_E_SCRIPT_ROUTINE_NOT_FOUND";
                  break;
                case -2005396964:
                  result = "DMUS_E_SCRIPT_CONTENT_READONLY";
                  break;
                case -2005396963:
                  result = "DMUS_E_SCRIPT_NOT_A_REFERENCE";
                  break;
                case -2005396962:
                  result = "DMUS_E_SCRIPT_VALUE_NOT_SUPPORTED";
                  break;
                case -2005396960:
                  result = "DMUS_E_INVALID_SEGMENTTRIGGERTRACK";
                  break;
                case -2005396959:
                  result = "DMUS_E_INVALID_LYRICSTRACK";
                  break;
                case -2005396958:
                  result = "DMUS_E_INVALID_PARAMCONTROLTRACK";
                  break;
                case -2005396957:
                  result = "DMUS_E_AUDIOVBSCRIPT_SYNTAXERROR";
                  break;
                case -2005396956:
                  result = "DMUS_E_AUDIOVBSCRIPT_RUNTIMEERROR";
                  break;
                case -2005396955:
                  result = "DMUS_E_AUDIOVBSCRIPT_OPERATIONFAILURE";
                  break;
                case -2005396954:
                  result = "DMUS_E_AUDIOPATHS_NOT_VALID";
                  break;
                case -2005396953:
                  result = "DMUS_E_AUDIOPATHS_IN_USE";
                  break;
                case -2005396952:
                  result = "DMUS_E_NO_AUDIOPATH_CONFIG";
                  break;
                case -2005396951:
                  result = "DMUS_E_AUDIOPATH_INACTIVE";
                  break;
                case -2005396950:
                  result = "DMUS_E_AUDIOPATH_NOBUFFER";
                  break;
                case -2005396949:
                  result = "DMUS_E_AUDIOPATH_NOPORT";
                  break;
                case -2005396948:
                  result = "DMUS_E_NO_AUDIOPATH";
                  break;
                case -2005396947:
                  result = "DMUS_E_INVALIDCHUNK";
                  break;
                case -2005396946:
                  result = "DMUS_E_AUDIOPATH_NOGLOBALFXBUFFER";
                  break;
                case -2005396945:
                  result = "DMUS_E_INVALID_CONTAINER_OBJECT";
                  break;
                default:
                  return "Unknown";
              }
            }
            else
            {
              return "S_OK";
            }
          }
          else
          {
            if ( a1 == -2005396967 )
              return "DMUS_E_INVALID_SCRIPTTRACK";
            if ( a1 <= -2005396988 )
            {
              if ( a1 == -2005396988 )
                return "DMUS_E_ALREADY_SENT";
              if ( a1 > -2005397115 )
              {
                switch ( a1 )
                {
                  case -2005397114:
                    return "DMUS_E_LOADER_NOFILENAME";
                  case -2005396992:
                    return "DMUS_E_INVALIDFILE";
                  case -2005396991:
                    return "DMUS_E_ALREADY_EXISTS";
                  case -2005396990:
                    return "DMUS_E_OUT_OF_RANGE";
                  case -2005396989:
                    return "DMUS_E_SEGMENT_INIT_FAILED";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2005397115:
                    return "DMUS_E_LOADER_OBJECTNOTFOUND";
                  case -2005397120:
                    return "DMUS_E_LOADER_NOCLASSID";
                  case -2005397119:
                    return "DMUS_E_LOADER_BADPATH";
                  case -2005397118:
                    return "DMUS_E_LOADER_FAILEDOPEN";
                  case -2005397117:
                    return "DMUS_E_LOADER_FORMATNOTSUPPORTED";
                  case -2005397116:
                    return "DMUS_E_LOADER_FAILEDCREATE";
                  default:
                    break;
                }
              }
              return "Unknown";
            }
            switch ( a1 )
            {
              case -2005396987:
                result = "DMUS_E_CANNOT_FREE";
                break;
              case -2005396986:
                result = "DMUS_E_CANNOT_OPEN_PORT";
                break;
              case -2005396985:
                result = "DMUS_E_CANNOT_CONVERT";
                break;
              case -2005396976:
                result = "DMUS_E_DESCEND_CHUNK_FAIL";
                break;
              case -2005396975:
                result = "DMUS_E_NOT_LOADED";
                break;
              case -2005396973:
                result = "DMUS_E_SCRIPT_LANGUAGE_INCOMPATIBLE";
                break;
              case -2005396972:
                result = "DMUS_E_SCRIPT_UNSUPPORTED_VARTYPE";
                break;
              case -2005396971:
                result = "DMUS_E_SCRIPT_ERROR_IN_SCRIPT";
                break;
              case -2005396970:
                result = "DMUS_E_SCRIPT_CANTLOAD_OLEAUT32";
                break;
              case -2005396969:
                result = "DMUS_E_SCRIPT_LOADSCRIPT_ERROR";
                break;
              case -2005396968:
                result = "DMUS_E_SCRIPT_INVALID_FILE";
                break;
              default:
                return "Unknown";
            }
          }
        }
      }
      else if ( a1 == -2005397136 )
      {
        return "DMUS_E_NO_MASTER_CLOCK";
      }
      else
      {
        switch ( a1 )
        {
          case -2005397231:
            result = "DMUS_E_ALREADY_LOADED";
            break;
          case -2005397229:
            result = "DMUS_E_INVALIDPOS";
            break;
          case -2005397228:
            result = "DMUS_E_INVALIDPATCH";
            break;
          case -2005397227:
            result = "DMUS_E_CANNOTSEEK";
            break;
          case -2005397226:
            result = "DMUS_E_CANNOTWRITE";
            break;
          case -2005397225:
            result = "DMUS_E_CHUNKNOTFOUND";
            break;
          case -2005397223:
            result = "DMUS_E_INVALID_DOWNLOADID";
            break;
          case -2005397216:
            result = "DMUS_E_NOT_DOWNLOADED_TO_PORT";
            break;
          case -2005397215:
            result = "DMUS_E_ALREADY_DOWNLOADED";
            break;
          case -2005397214:
            result = "DMUS_E_UNKNOWN_PROPERTY";
            break;
          case -2005397213:
            result = "DMUS_E_SET_UNSUPPORTED";
            break;
          case -2005397212:
            result = "DMUS_E_GET_UNSUPPORTED";
            break;
          case -2005397211:
            result = "DMUS_E_NOTMONO";
            break;
          case -2005397210:
            result = "DMUS_E_BADARTICULATION";
            break;
          case -2005397209:
            result = "DMUS_E_BADINSTRUMENT";
            break;
          case -2005397208:
            result = "DMUS_E_BADWAVELINK";
            break;
          case -2005397207:
            result = "DMUS_E_NOARTICULATION";
            break;
          case -2005397206:
            result = "DMUS_E_NOTPCM";
            break;
          case -2005397205:
            result = "DMUS_E_BADWAVE";
            break;
          case -2005397204:
            result = "DMUS_E_BADOFFSETTABLE";
            break;
          case -2005397203:
            result = "DMUS_E_UNKNOWNDOWNLOAD";
            break;
          case -2005397202:
            result = "DMUS_E_NOSYNTHSINK";
            break;
          case -2005397201:
            result = "DMUS_E_ALREADYOPEN";
            break;
          case -2005397200:
            result = "DMUS_E_ALREADYCLOSED";
            break;
          case -2005397199:
            result = "DMUS_E_SYNTHNOTCONFIGURED";
            break;
          case -2005397198:
            result = "DMUS_E_SYNTHACTIVE";
            break;
          case -2005397197:
            result = "DMUS_E_CANNOTREAD";
            break;
          case -2005397196:
            result = "DMUS_E_DMUSIC_RELEASED";
            break;
          case -2005397195:
            result = "DMUS_E_BUFFER_EMPTY";
            break;
          case -2005397194:
            result = "DMUS_E_BUFFER_FULL";
            break;
          case -2005397193:
            result = "DMUS_E_PORT_NOT_CAPTURE";
            break;
          case -2005397192:
            result = "DMUS_E_PORT_NOT_RENDER";
            break;
          case -2005397191:
            result = "DMUS_E_DSOUND_NOT_SET";
            break;
          case -2005397190:
            result = "DMUS_E_ALREADY_ACTIVATED";
            break;
          case -2005397189:
            result = "DMUS_E_INVALIDBUFFER";
            break;
          case -2005397188:
            result = "DMUS_E_WAVEFORMATNOTSUPPORTED";
            break;
          case -2005397187:
            result = "DMUS_E_SYNTHINACTIVE";
            break;
          case -2005397186:
            result = "DMUS_E_DSOUND_ALREADY_SET";
            break;
          case -2005397185:
            result = "DMUS_E_INVALID_EVENT";
            break;
          case -2005397168:
            result = "DMUS_E_UNSUPPORTED_STREAM";
            break;
          case -2005397167:
            result = "DMUS_E_ALREADY_INITED";
            break;
          case -2005397166:
            result = "DMUS_E_INVALID_BAND";
            break;
          case -2005397163:
            result = "DMUS_E_TRACK_HDR_NOT_FIRST_CK";
            break;
          case -2005397162:
            result = "DMUS_E_TOOL_HDR_NOT_FIRST_CK";
            break;
          case -2005397161:
            result = "DMUS_E_INVALID_TRACK_HDR";
            break;
          case -2005397160:
            result = "DMUS_E_INVALID_TOOL_HDR";
            break;
          case -2005397159:
            result = "DMUS_E_ALL_TOOLS_FAILED";
            break;
          case -2005397152:
            result = "DMUS_E_ALL_TRACKS_FAILED";
            break;
          case -2005397151:
            result = "DSERR_OBJECTNOTFOUND";
            break;
          case -2005397150:
            result = "DMUS_E_NOT_INIT";
            break;
          case -2005397149:
            result = "DMUS_E_TYPE_DISABLED";
            break;
          case -2005397148:
            result = "DMUS_E_TYPE_UNSUPPORTED";
            break;
          case -2005397147:
            result = "DMUS_E_TIME_PAST";
            break;
          case -2005397146:
            result = "DMUS_E_TRACK_NOT_FOUND";
            break;
          case -2005397145:
            result = "DMUS_E_TRACK_NO_CLOCKTIME_SUPPORT";
            break;
          default:
            return "Unknown";
        }
      }
    }
    else
    {
      if ( a1 == -2005397239 )
        return "DMUS_E_INVALIDOFFSET";
      if ( a1 > -2005531973 )
      {
        if ( a1 > -2005530600 )
        {
          if ( a1 > -2005530522 )
          {
            if ( a1 > -2005401500 )
            {
              if ( a1 > -2005401390 )
              {
                switch ( a1 )
                {
                  case -2005397247:
                    return "DMUS_E_DRIVER_FAILED";
                  case -2005397246:
                    return "DMUS_E_PORTS_OPEN";
                  case -2005397245:
                    return "DMUS_E_DEVICE_IN_USE";
                  case -2005397244:
                    return "DMUS_E_INSUFFICIENTBUFFER";
                  case -2005397243:
                    return "DMUS_E_BUFFERNOTSET";
                  case -2005397242:
                    return "DMUS_E_BUFFERNOTAVAILABLE";
                  case -2005397240:
                    return "DMUS_E_NOTADLSCOL";
                  default:
                    break;
                }
              }
              else
              {
                if ( a1 == -2005401390 )
                  return "DSERR_BADSENDBUFFERGUID";
                if ( a1 > -2005401430 )
                {
                  switch ( a1 )
                  {
                    case -2005401420:
                      return "DSERR_BUFFERTOOSMALL";
                    case -2005401410:
                      return "DSERR_DS8_REQUIRED";
                    case -2005401400:
                      return "DSERR_SENDLOOP";
                    default:
                      break;
                  }
                }
                else
                {
                  switch ( a1 )
                  {
                    case -2005401430:
                      return "DSERR_UNINITIALIZED";
                    case -2005401480:
                      return "DSERR_NODRIVER";
                    case -2005401470:
                      return "DSERR_ALREADYINITIALIZED";
                    case -2005401450:
                      return "DSERR_BUFFERLOST";
                    case -2005401440:
                      return "DSERR_OTHERAPPHASPRIO";
                    default:
                      break;
                  }
                }
              }
              return "Unknown";
            }
            if ( a1 == -2005401500 )
              return "DSERR_BADFORMAT";
            if ( a1 > -2005529771 )
            {
              if ( a1 > -2005401590 )
              {
                switch ( a1 )
                {
                  case -2005401570:
                    return "DSERR_CONTROLUNAVAIL";
                  case -2005401550:
                    return "DSERR_INVALIDCALL";
                  case -2005401530:
                    return "DSERR_PRIOLEVELNEEDED";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2005401590:
                    return "DSERR_ALLOCATED";
                  case -2005529770:
                    return "D3DXERR_CANNOTATTRSORT";
                  case -2005529769:
                    return "D3DXERR_SKINNINGNOTSUPPORTED";
                  case -2005529768:
                    return "D3DXERR_TOOMANYINFLUENCES";
                  case -2005529767:
                    return "D3DXERR_INVALIDDATA";
                  default:
                    break;
                }
              }
              return "Unknown";
            }
            if ( a1 == -2005529771 )
              return "D3DXERR_INVALIDMESH";
            if ( a1 > -2005530517 )
            {
              switch ( a1 )
              {
                case -2005530516:
                  return "D3DERR_INVALIDCALL";
                case -2005530515:
                  return "D3DERR_DRIVERINVALIDCALL";
                case -2005529772:
                  return "D3DXERR_CANNOTMODIFYINDEXBUFFER";
                default:
                  break;
              }
              return "Unknown";
            }
            switch ( a1 )
            {
              case -2005530517:
                return "D3DERR_INVALIDDEVICE";
              case -2005530521:
                return "D3DERR_MOREDATA";
              case -2005530520:
                return "D3DERR_DEVICELOST";
              case -2005530519:
                return "D3DERR_DEVICENOTRESET";
              default:
                return "D3DERR_NOTAVAILABLE";
            }
          }
          else if ( a1 == -2005530522 )
          {
            return "D3DERR_NOTFOUND";
          }
          else
          {
            switch ( a1 )
            {
              case -2005530599:
                result = "D3DERR_UNSUPPORTEDCOLOROPERATION";
                break;
              case -2005530598:
                result = "D3DERR_UNSUPPORTEDCOLORARG";
                break;
              case -2005530597:
                result = "D3DERR_UNSUPPORTEDALPHAOPERATION";
                break;
              case -2005530596:
                result = "D3DERR_UNSUPPORTEDALPHAARG";
                break;
              case -2005530595:
                result = "D3DERR_TOOMANYOPERATIONS";
                break;
              case -2005530594:
                result = "D3DERR_CONFLICTINGTEXTUREFILTER";
                break;
              case -2005530593:
                result = "D3DERR_UNSUPPORTEDFACTORVALUE";
                break;
              case -2005530591:
                result = "D3DERR_CONFLICTINGRENDERSTATE";
                break;
              case -2005530590:
                result = "D3DERR_UNSUPPORTEDTEXTUREFILTER";
                break;
              case -2005530586:
                result = "D3DERR_CONFLICTINGTEXTUREPALETTE";
                break;
              case -2005530585:
                result = "D3DERR_DRIVERINTERNALERROR";
                break;
              default:
                return "Unknown";
            }
          }
        }
        else if ( a1 == -2005530600 )
        {
          return "D3DERR_WRONGTEXTUREFORMAT";
        }
        else
        {
          switch ( a1 )
          {
            case -2005531822:
              result = "DXFILEERR_BADOBJECT";
              break;
            case -2005531821:
              result = "DXFILEERR_BADVALUE";
              break;
            case -2005531820:
              result = "DXFILEERR_BADTYPE";
              break;
            case -2005531819:
              result = "DXFILEERR_BADSTREAMHANDLE";
              break;
            case -2005531818:
              result = "DXFILEERR_BADALLOC";
              break;
            case -2005531817:
              result = "DXFILEERR_NOTFOUND";
              break;
            case -2005531816:
              result = "DXFILEERR_NOTDONEYET";
              break;
            case -2005531815:
              result = "DXFILEERR_FILENOTFOUND";
              break;
            case -2005531814:
              result = "DXFILEERR_RESOURCENOTFOUND";
              break;
            case -2005531813:
              result = "DXFILEERR_URLNOTFOUND";
              break;
            case -2005531812:
              result = "DXFILEERR_BADRESOURCE";
              break;
            case -2005531811:
              result = "DXFILEERR_BADFILETYPE";
              break;
            case -2005531810:
              result = "DXFILEERR_BADFILEVERSION";
              break;
            case -2005531809:
              result = "DXFILEERR_BADFILEFLOATSIZE";
              break;
            case -2005531808:
              result = "DXFILEERR_BADFILECOMPRESSIONTYPE";
              break;
            case -2005531807:
              result = "DXFILEERR_BADFILE";
              break;
            case -2005531806:
              result = "DXFILEERR_PARSEERROR";
              break;
            case -2005531805:
              result = "DXFILEERR_NOTEMPLATE";
              break;
            case -2005531804:
              result = "DXFILEERR_BADARRAYSIZE";
              break;
            case -2005531803:
              result = "DXFILEERR_BADDATAREFERENCE";
              break;
            case -2005531802:
              result = "DXFILEERR_INTERNALERROR";
              break;
            case -2005531801:
              result = "DXFILEERR_NOMOREOBJECTS";
              break;
            case -2005531800:
              result = "DXFILEERR_BADINTRINSICS";
              break;
            case -2005531799:
              result = "DXFILEERR_NOMORESTREAMHANDLES";
              break;
            case -2005531798:
              result = "DXFILEERR_NOMOREDATA";
              break;
            case -2005531797:
              result = "DXFILEERR_BADCACHEFILE";
              break;
            case -2005531796:
              result = "DXFILEERR_NOINTERNET";
              break;
            default:
              return "Unknown";
          }
        }
      }
      else
      {
        if ( a1 == -2005531973 )
          return "DDERR_DEVICEDOESNTOWNSURFACE";
        if ( a1 > -2005532099 )
        {
          switch ( a1 )
          {
            case -2005532098:
              result = "DDERR_BLTFASTCANTCLIP";
              break;
            case -2005532097:
              result = "DDERR_NOBLTHW";
              break;
            case -2005532096:
              result = "DDERR_NODDROPSHW";
              break;
            case -2005532095:
              result = "DDERR_OVERLAYNOTVISIBLE";
              break;
            case -2005532094:
              result = "DDERR_NOOVERLAYDEST";
              break;
            case -2005532093:
              result = "DDERR_INVALIDPOSITION";
              break;
            case -2005532092:
              result = "DDERR_NOTAOVERLAYSURFACE";
              break;
            case -2005532091:
              result = "DDERR_EXCLUSIVEMODEALREADYSET";
              break;
            case -2005532090:
              result = "DDERR_NOTFLIPPABLE";
              break;
            case -2005532089:
              result = "DDERR_CANTDUPLICATE";
              break;
            case -2005532088:
              result = "DDERR_NOTLOCKED";
              break;
            case -2005532087:
              result = "DDERR_CANTCREATEDC";
              break;
            case -2005532086:
              result = "DDERR_NODC";
              break;
            case -2005532085:
              result = "DDERR_WRONGMODE";
              break;
            case -2005532084:
              result = "DDERR_IMPLICITLYCREATED";
              break;
            case -2005532083:
              result = "DDERR_NOTPALETTIZED";
              break;
            case -2005532082:
              result = "DDERR_UNSUPPORTEDMODE";
              break;
            case -2005532081:
              result = "DDERR_NOMIPMAPHW";
              break;
            case -2005532080:
              result = "DDERR_INVALIDSURFACETYPE";
              break;
            case -2005532072:
              result = "DDERR_NOOPTIMIZEHW";
              break;
            case -2005532071:
              result = "DDERR_NOTLOADED";
              break;
            case -2005532070:
              result = "DDERR_NOFOCUSWINDOW";
              break;
            case -2005532069:
              result = "DDERR_NOTONMIPMAPSUBLEVEL";
              break;
            case -2005532052:
              result = "DDERR_DCALREADYCREATED";
              break;
            case -2005532042:
              result = "DDERR_NONONLOCALVIDMEM";
              break;
            case -2005532032:
              result = "DDERR_CANTPAGELOCK";
              break;
            case -2005532012:
              result = "DDERR_CANTPAGEUNLOCK";
              break;
            case -2005531992:
              result = "DDERR_NOTPAGELOCKED";
              break;
            case -2005531982:
              result = "DDERR_MOREDATA";
              break;
            case -2005531981:
              result = "DDERR_EXPIRED";
              break;
            case -2005531980:
              result = "DDERR_TESTFINISHED";
              break;
            case -2005531979:
              result = "DDERR_NEWMODE";
              break;
            case -2005531978:
              result = "DDERR_D3DNOTINITIALIZED";
              break;
            case -2005531977:
              result = "DDERR_VIDEONOTACTIVE";
              break;
            case -2005531976:
              result = "DDERR_NOMONITORINFORMATION";
              break;
            case -2005531975:
              result = "DDERR_NODRIVERSUPPORT";
              break;
            default:
              return "Unknown";
          }
        }
        else
        {
          if ( a1 == -2005532099 )
            return "DDERR_NOPALETTEHW";
          if ( a1 <= -2005532162 )
          {
            if ( a1 == -2005532162 )
              return "DDERR_UNSUPPORTEDFORMAT";
            if ( a1 > -2005532252 )
            {
              if ( a1 > -2005532212 )
              {
                switch ( a1 )
                {
                  case -2005532202:
                    return "DDERR_TOOBIGHEIGHT";
                  case -2005532192:
                    return "DDERR_TOOBIGSIZE";
                  case -2005532182:
                    return "DDERR_TOOBIGWIDTH";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2005532212:
                    return "DDERR_SURFACENOTATTACHED";
                  case -2005532242:
                    return "DDERR_SURFACEBUSY";
                  case -2005532237:
                    return "DDERR_CANTLOCKSURFACE";
                  case -2005532232:
                    return "DDERR_SURFACEISOBSCURED";
                  case -2005532222:
                    return "DDERR_SURFACELOST";
                  default:
                    break;
                }
              }
            }
            else
            {
              if ( a1 == -2005532252 )
                return "DDERR_SURFACEALREADYDEPENDENT";
              if ( a1 > -2005532290 )
              {
                switch ( a1 )
                {
                  case -2005532288:
                    return "DDERR_OVERLAYCOLORKEYONLYONEACTIVE";
                  case -2005532285:
                    return "DDERR_PALETTEBUSY";
                  case -2005532272:
                    return "DDERR_COLORKEYNOTSET";
                  case -2005532262:
                    return "DDERR_SURFACEALREADYATTACHED";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2005532290:
                    return "DDERR_OVERLAYCANTCLIP";
                  case -2005532332:
                    return "DDERR_NOZBUFFERHW";
                  case -2005532322:
                    return "DDERR_NOZOVERLAYHW";
                  case -2005532312:
                    return "DDERR_OUTOFCAPS";
                  case -2005532292:
                    return "D3DERR_OUTOFVIDEOMEMORY";
                  default:
                    break;
                }
              }
            }
            return "Unknown";
          }
          switch ( a1 )
          {
            case -2005532152:
              result = "DDERR_UNSUPPORTEDMASK";
              break;
            case -2005532151:
              result = "DDERR_INVALIDSTREAM";
              break;
            case -2005532135:
              result = "DDERR_VERTICALBLANKINPROGRESS";
              break;
            case -2005532132:
              result = "DDERR_WASSTILLDRAWING";
              break;
            case -2005532130:
              result = "DDERR_DDSCAPSCOMPLEXREQUIRED";
              break;
            case -2005532112:
              result = "DDERR_XALIGN";
              break;
            case -2005532111:
              result = "DDERR_INVALIDDIRECTDRAWGUID";
              break;
            case -2005532110:
              result = "DDERR_DIRECTDRAWALREADYCREATED";
              break;
            case -2005532109:
              result = "DDERR_NODIRECTDRAWHW";
              break;
            case -2005532108:
              result = "DDERR_PRIMARYSURFACEALREADYEXISTS";
              break;
            case -2005532107:
              result = "DDERR_NOEMULATION";
              break;
            case -2005532106:
              result = "DDERR_REGIONTOOSMALL";
              break;
            case -2005532105:
              result = "DDERR_CLIPPERISUSINGHWND";
              break;
            case -2005532104:
              result = "DDERR_NOCLIPPERATTACHED";
              break;
            case -2005532103:
              result = "DDERR_NOHWND";
              break;
            case -2005532102:
              result = "DDERR_HWNDSUBCLASSED";
              break;
            case -2005532101:
              result = "DDERR_HWNDALREADYSET";
              break;
            case -2005532100:
              result = "DDERR_NOPALETTEATTACHED";
              break;
            default:
              return "Unknown";
          }
        }
      }
    }
  }
  else
  {
    if ( a1 == -2005532337 )
      return "DDERR_NOVSYNCHW";
    if ( a1 > -2147023743 )
    {
      if ( a1 > -2146073968 )
      {
        if ( a1 > -2005532662 )
        {
          if ( a1 > -2005532460 )
          {
            if ( a1 > -2005532412 )
            {
              if ( a1 > -2005532356 )
              {
                switch ( a1 )
                {
                  case -2005532355:
                    return "DDERR_NOT4BITCOLORINDEX";
                  case -2005532352:
                    return "DDERR_NOT8BITCOLOR";
                  case -2005532342:
                    return "DDERR_NOTEXTUREHW";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2005532356:
                    return "DDERR_NOT4BITCOLOR";
                  case -2005532402:
                    return "DDERR_OVERLAPPINGRECTS";
                  case -2005532392:
                    return "DDERR_NORASTEROPHW";
                  case -2005532382:
                    return "DDERR_NOROTATIONHW";
                  case -2005532362:
                    return "DDERR_NOSTRETCHHW";
                  default:
                    break;
                }
              }
            }
            else
            {
              if ( a1 == -2005532412 )
                return "DDERR_NOOVERLAYHW";
              if ( a1 > -2005532442 )
              {
                switch ( a1 )
                {
                  case -2005532432:
                    return "DDERR_NOGDI";
                  case -2005532422:
                    return "DDERR_NOMIRRORHW";
                  case -2005532417:
                    return "DDERR_NOTFOUND";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2005532442:
                    return "DDERR_NOFLIPHW";
                  case -2005532457:
                    return "DDERR_NOCOLORKEY";
                  case -2005532452:
                    return "DDERR_NOCOLORKEYHW";
                  case -2005532450:
                    return "DDERR_NODIRECTDRAWSUPPORT";
                  case -2005532447:
                    return "DDERR_NOEXCLUSIVEMODE";
                  default:
                    break;
                }
              }
            }
          }
          else
          {
            if ( a1 == -2005532460 )
              return "DDERR_NOCOOPERATIVELEVELSET";
            if ( a1 > -2005532527 )
            {
              if ( a1 > -2005532491 )
              {
                switch ( a1 )
                {
                  case -2005532490:
                    return "DDERR_NOSURFACELEFT";
                  case -2005532467:
                    return "DDERR_NOCLIPLIST";
                  case -2005532462:
                    return "DDERR_NOCOLORCONVHW";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2005532491:
                    return "DDERR_NOSTEREOHARDWARE";
                  case -2005532522:
                    return "DDERR_INVALIDRECT";
                  case -2005532512:
                    return "DDERR_LOCKEDSURFACES";
                  case -2005532502:
                    return "DDERR_NO3D";
                  case -2005532492:
                    return "DDERR_NOALPHAHW";
                  default:
                    break;
                }
              }
            }
            else
            {
              if ( a1 == -2005532527 )
                return "DDERR_INVALIDPIXELFORMAT";
              if ( a1 > -2005532577 )
              {
                switch ( a1 )
                {
                  case -2005532572:
                    return "DDERR_INVALIDCAPS";
                  case -2005532562:
                    return "DDERR_INVALIDCLIPLIST";
                  case -2005532552:
                    return "DDERR_INVALIDMODE";
                  case -2005532542:
                    return "DDERR_INVALIDOBJECT";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2005532577:
                    return "DDERR_INCOMPATIBLEPRIMARY";
                  case -2005532652:
                    return "DDERR_CANNOTDETACHSURFACE";
                  case -2005532632:
                    return "DDERR_CURRENTLYNOTAVAIL";
                  case -2005532617:
                    return "DDERR_EXCEPTION";
                  case -2005532582:
                    return "DDERR_HEIGHTALIGN";
                  default:
                    break;
                }
              }
            }
          }
        }
        else
        {
          if ( a1 == -2005532662 )
            return "DDERR_CANNOTATTACHSURFACE";
          if ( a1 > -2146073472 )
          {
            if ( a1 > -2146073216 )
            {
              if ( a1 > -2146073040 )
              {
                switch ( a1 )
                {
                  case -2146073024:
                    return "DPNERR_UNINITIALIZED";
                  case -2146073008:
                    return "DPNERR_USERCANCEL";
                  case -2005532667:
                    return "DDERR_ALREADYINITIALIZED";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2146073040:
                    return "DPNERR_TIMEDOUT";
                  case -2146073200:
                    return "DPNERR_PLAYERNOTREACHABLE";
                  case -2146073088:
                    return "DPNERR_SENDTOOLARGE";
                  case -2146073072:
                    return "DPNERR_SESSIONFULL";
                  case -2146073056:
                    return "DPNERR_TABLEFULL";
                  default:
                    break;
                }
              }
            }
            else
            {
              if ( a1 == -2146073216 )
                return "DPNERR_PLAYERNOTINGROUP";
              if ( a1 > -2146073296 )
              {
                switch ( a1 )
                {
                  case -2146073280:
                    return "DPNERR_NOTREADY";
                  case -2146073264:
                    return "DPNERR_NOTREGISTERED";
                  case -2146073248:
                    return "DPNERR_PLAYERALREADYINGROUP";
                  case -2146073232:
                    return "DPNERR_PLAYERLOST";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2146073296:
                    return "DPNERR_NOTHOST";
                  case -2146073456:
                    return "DPNERR_NOHOSTPLAYER";
                  case -2146073344:
                    return "DPNERR_NOMOREADDRESSCOMPONENTS";
                  case -2146073328:
                    return "DPNERR_NORESPONSE";
                  case -2146073312:
                    return "DPNERR_NOTALLOWED";
                  default:
                    break;
                }
              }
            }
          }
          else
          {
            if ( a1 == -2146073472 )
              return "DPNERR_NOCONNECTION";
            if ( a1 > -2146073712 )
            {
              if ( a1 > -2146073536 )
              {
                switch ( a1 )
                {
                  case -2146073520:
                    return "DPNERR_INVALIDURL";
                  case -2146073504:
                    return "DPNERR_INVALIDVERSION";
                  case -2146073488:
                    return "DPNERR_NOCAPS";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2146073536:
                    return "DPNERR_INVALIDSTRING";
                  case -2146073600:
                    return "DPNERR_INVALIDOBJECT";
                  case -2146073584:
                    return "DPNERR_INVALIDPASSWORD";
                  case -2146073568:
                    return "DPNERR_INVALIDPLAYER";
                  case -2146073552:
                    return "DPNERR_INVALIDPRIORITY";
                  default:
                    break;
                }
              }
            }
            else
            {
              if ( a1 == -2146073712 )
                return "DPNERR_INVALIDINTERFACE";
              if ( a1 > -2146073792 )
              {
                switch ( a1 )
                {
                  case -2146073776:
                    return "DPNERR_INVALIDGROUP";
                  case -2146073760:
                    return "DPNERR_INVALIDHANDLE";
                  case -2146073744:
                    return "DPNERR_INVALIDHOSTADDRESS";
                  case -2146073728:
                    return "DPNERR_INVALIDINSTANCE";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2146073792:
                    return "DPNERR_INVALIDFLAGS";
                  case -2146073856:
                    return "DPNERR_INVALIDAPPLICATION";
                  case -2146073840:
                    return "DPNERR_INVALIDCOMMAND";
                  case -2146073824:
                    return "DPNERR_INVALIDDEVICEADDRESS";
                  case -2146073808:
                    return "DPNERR_INVALIDENDPOINT";
                  default:
                    break;
                }
              }
            }
          }
        }
        return "Unknown";
      }
      if ( a1 == -2146073968 )
        return "DPNERR_INVALIDADDRESSFORMAT";
      if ( a1 > -2146107001 )
      {
        if ( a1 > -2146074576 )
        {
          if ( a1 > -2146074256 )
          {
            if ( a1 > -2146074064 )
            {
              switch ( a1 )
              {
                case -2146074048:
                  return "DPNERR_GROUPNOTEMPTY";
                case -2146074032:
                  return "DPNERR_HOSTING";
                case -2146074016:
                  return "DPNERR_HOSTREJECTEDCONNECTION";
                case -2146074000:
                  return "DPNERR_HOSTTERMINATEDSESSION";
                case -2146073984:
                  return "DPNERR_INCOMPLETEADDRESS";
                default:
                  break;
              }
            }
            else
            {
              switch ( a1 )
              {
                case -2146074064:
                  return "DPNERR_EXCEPTION";
                case -2146074251:
                  return "DPNERR_DATATOOLARGE";
                case -2146074240:
                  return "DPNERR_DOESNOTEXIST";
                case -2146074224:
                  return "DPNERR_DUPLICATECOMMAND";
                case -2146074112:
                  return "DPNERR_ENDPOINTNOTRECEIVING";
                case -2146074096:
                  return "DPNERR_ENUMQUERYTOOLARGE";
                case -2146074080:
                  return "DPNERR_ENUMRESPONSETOOLARGE";
                default:
                  break;
              }
            }
          }
          else
          {
            if ( a1 == -2146074256 )
              return "DPNERR_CONVERSION";
            if ( a1 > -2146074368 )
            {
              switch ( a1 )
              {
                case -2146074352:
                  return "DPNERR_CANNOTCANCEL";
                case -2146074336:
                  return "DPNERR_CANTCREATEGROUP";
                case -2146074320:
                  return "DPNERR_CANTCREATEPLAYER";
                case -2146074304:
                  return "DPNERR_CANTLAUNCHAPPLICATION";
                case -2146074288:
                  return "DPNERR_CONNECTING";
                case -2146074272:
                  return "DPNERR_CONNECTIONLOST";
                default:
                  break;
              }
            }
            else
            {
              switch ( a1 )
              {
                case -2146074368:
                  return "DPNERR_BUFFERTOOSMALL";
                case -2146074560:
                  return "DPNERR_ADDRESSING";
                case -2146074544:
                  return "DPNERR_ALREADYCLOSING";
                case -2146074528:
                  return "DPNERR_ALREADYCONNECTED";
                case -2146074512:
                  return "DPNERR_ALREADYDISCONNECTING";
                case -2146074496:
                  return "DPNERR_ALREADYINITIALIZED";
                case -2146074480:
                  return "DPNERR_ALREADYREGISTERED";
                default:
                  break;
              }
            }
          }
          return "Unknown";
        }
        if ( a1 == -2146074576 )
        {
          return "DPNERR_ABORTED";
        }
        else
        {
          switch ( a1 )
          {
            case -2146107000:
              result = "DVERR_NOTRANSPORT";
              break;
            case -2146106999:
              result = "DVERR_NOCALLBACK";
              break;
            case -2146106998:
              result = "DVERR_TRANSPORTNOTINIT";
              break;
            case -2146106997:
              result = "DVERR_TRANSPORTNOSESSION";
              break;
            case -2146106996:
              result = "DVERR_TRANSPORTNOPLAYER";
              break;
            case -2146106995:
              result = "DVERR_USERBACK";
              break;
            case -2146106994:
              result = "DVERR_NORECVOLAVAILABLE";
              break;
            case -2146106993:
              result = "DVERR_INVALIDBUFFER";
              break;
            case -2146106992:
              result = "DVERR_LOCKEDBUFFER";
              break;
            default:
              return "Unknown";
          }
        }
      }
      else
      {
        if ( a1 == -2146107001 )
          return "DVERR_INITIALIZED";
        if ( a1 <= -2146107024 )
        {
          if ( a1 == -2146107024 )
            return "DVERR_INVALIDTARGET";
          if ( a1 > -2146107242 )
          {
            if ( a1 > -2146107030 )
            {
              switch ( a1 )
              {
                case -2146107029:
                  return "DVERR_NOTCONNECTED";
                case -2146107026:
                  return "DVERR_CONNECTABORTING";
                case -2146107025:
                  return "DVERR_NOTALLOWED";
                default:
                  break;
              }
            }
            else
            {
              switch ( a1 )
              {
                case -2146107030:
                  return "DVERR_CONNECTED";
                case -2146107092:
                  return "DVERR_SESSIONLOST";
                case -2146107090:
                  return "DVERR_NOVOICESESSION";
                case -2146107032:
                  return "DVERR_CONNECTIONLOST";
                case -2146107031:
                  return "DVERR_NOTINITIALIZED";
                default:
                  break;
              }
            }
          }
          else
          {
            if ( a1 == -2146107242 )
              return "DVERR_INVALIDHANDLE";
            if ( a1 > -2146107318 )
            {
              switch ( a1 )
              {
                case -2146107272:
                  return "DVERR_INVALIDFLAGS";
                case -2146107262:
                  return "DVERR_INVALIDOBJECT";
                case -2146107257:
                  return "DVERR_INVALIDPLAYER";
                case -2146107247:
                  return "DVERR_INVALIDGROUP";
                default:
                  break;
              }
            }
            else
            {
              switch ( a1 )
              {
                case -2146107318:
                  return "DVERR_EXCEPTION";
                case -2147023728:
                  return "E_PROP_ID_UNSUPPORTED";
                case -2147023726:
                  return "E_PROP_SET_UNSUPPORTED";
                case -2147023649:
                  return "DIERR_ALREADYINITIALIZED";
                case -2146107362:
                  return "DVERR_BUFFERTOOSMALL";
                default:
                  break;
              }
            }
          }
          return "Unknown";
        }
        switch ( a1 )
        {
          case -2146107023:
            result = "DVERR_TRANSPORTNOTHOST";
            break;
          case -2146107022:
            result = "DVERR_COMPRESSIONNOTSUPPORTED";
            break;
          case -2146107021:
            result = "DVERR_ALREADYPENDING";
            break;
          case -2146107020:
            result = "DVERR_SOUNDINITFAILURE";
            break;
          case -2146107019:
            result = "DVERR_TIMEOUT";
            break;
          case -2146107018:
            result = "DVERR_CONNECTABORTED";
            break;
          case -2146107017:
            result = "DVERR_NO3DSOUND";
            break;
          case -2146107016:
            result = "DVERR_ALREADYBUFFERED";
            break;
          case -2146107015:
            result = "DVERR_NOTBUFFERED";
            break;
          case -2146107014:
            result = "DVERR_HOSTING";
            break;
          case -2146107013:
            result = "DVERR_NOTHOSTING";
            break;
          case -2146107012:
            result = "DVERR_INVALIDDEVICE";
            break;
          case -2146107011:
            result = "DVERR_RECORDSYSTEMERROR";
            break;
          case -2146107010:
            result = "DVERR_PLAYBACKSYSTEMERROR";
            break;
          case -2146107009:
            result = "DVERR_SENDERROR";
            break;
          case -2146107008:
            result = "DVERR_USERCANCEL";
            break;
          case -2146107005:
            result = "DVERR_RUNSETUP";
            break;
          case -2146107004:
            result = "DVERR_INCOMPATIBLEVERSION";
            break;
          default:
            return "Unknown";
        }
      }
    }
    else
    {
      if ( a1 == -2147023743 )
        return "DIERR_BETADIRECTINPUTVERSION";
      if ( a1 > -2147220920 )
      {
        if ( a1 > -2147220858 )
        {
          if ( a1 > -2147220736 )
          {
            if ( a1 > -2147024891 )
            {
              if ( a1 > -2147024809 )
              {
                switch ( a1 )
                {
                  case -2147024777:
                    return "DIERR_BADDRIVERVER";
                  case -2147024726:
                    return "DIERR_ACQUIRED";
                  case -2147024637:
                    return "DIERR_NOMOREITEMS";
                  case -2147023746:
                    return "DIERR_OLDDIRECTINPUTVERSION";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2147024809:
                    return "E_INVALIDARG";
                  case -2147024890:
                    return "E_HANDLE";
                  case -2147024884:
                    return "DIERR_NOTACQUIRED";
                  case -2147024882:
                    return "E_OUTOFMEMORY";
                  case -2147024875:
                    return "DIERR_NOTINITIALIZED";
                  case -2147024866:
                    return "DIERR_INPUTLOST";
                  default:
                    break;
                }
              }
            }
            else
            {
              if ( a1 == -2147024891 )
                return "E_ACCESSDENIED";
              if ( a1 > -2147220494 )
              {
                switch ( a1 )
                {
                  case -2147220481:
                    return "DIERR_DRIVERLAST";
                  case -2147220480:
                    return "DIERR_INVALIDCLASSINSTALLER";
                  case -2147220479:
                    return "DIERR_CANCELLED";
                  case -2147220478:
                    return "DIERR_BADINF";
                  case -2147024894:
                    return "ERROR_FILE_NOT_FOUND";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2147220494:
                    return "VFW_E_BAD_KEY";
                  case -2147220735:
                    return "DIERR_DRIVERFIRST+1";
                  case -2147220734:
                    return "DIERR_DRIVERFIRST+2";
                  case -2147220733:
                    return "DIERR_DRIVERFIRST+3";
                  case -2147220732:
                    return "DIERR_DRIVERFIRST+4";
                  case -2147220731:
                    return "DIERR_DRIVERFIRST+5";
                  default:
                    break;
                }
              }
            }
            return "Unknown";
          }
          if ( a1 == -2147220736 )
          {
            return "DIERR_DRIVERFIRST";
          }
          else
          {
            switch ( a1 )
            {
              case -2147220857:
                result = "VFW_E_DVD_INCOMPATIBLE_REGION";
                break;
              case -2147220856:
                result = "VFW_E_DVD_NO_ATTRIBUTES";
                break;
              case -2147220855:
                result = "VFW_E_DVD_NO_GOUP_PGC";
                break;
              case -2147220854:
                result = "VFW_E_DVD_LOW_PARENTAL_LEVEL";
                break;
              case -2147220853:
                result = "VFW_E_DVD_NOT_IN_KARAOKE_MODE";
                break;
              case -2147220850:
                result = "VFW_E_FRAME_STEP_UNSUPPORTED";
                break;
              case -2147220849:
                result = "VFW_E_DVD_STREAM_DISABLED";
                break;
              case -2147220848:
                result = "VFW_E_DVD_TITLE_UNKNOWN";
                break;
              case -2147220847:
                result = "VFW_E_DVD_INVALID_DISC";
                break;
              case -2147220846:
                result = "VFW_E_DVD_NO_RESUME_INFORMATION";
                break;
              case -2147220845:
                result = "VFW_E_PIN_ALREADY_BLOCKED_ON_THIS_THREAD";
                break;
              case -2147220844:
                result = "VFW_E_PIN_ALREADY_BLOCKED";
                break;
              case -2147220843:
                result = "VFW_E_CERTIFICATION_FAILURE";
                break;
              default:
                return "Unknown";
            }
          }
        }
        else if ( a1 == -2147220858 )
        {
          return "VFW_E_DVD_STATE_WRONG_DISC";
        }
        else
        {
          switch ( a1 )
          {
            case -2147220919:
              result = "VFW_E_SAMPLE_TIME_NOT_SET";
              break;
            case -2147220911:
              result = "VFW_E_MEDIA_TIME_NOT_SET";
              break;
            case -2147220910:
              result = "VFW_E_NO_TIME_FORMAT_SET";
              break;
            case -2147220909:
              result = "VFW_E_MONO_AUDIO_HW";
              break;
            case -2147220907:
              result = "VFW_E_NO_DECOMPRESSOR";
              break;
            case -2147220906:
              result = "VFW_E_NO_AUDIO_HARDWARE";
              break;
            case -2147220903:
              result = "VFW_E_RPZA";
              break;
            case -2147220901:
              result = "VFW_E_PROCESSOR_NOT_SUITABLE";
              break;
            case -2147220900:
              result = "VFW_E_UNSUPPORTED_AUDIO";
              break;
            case -2147220899:
              result = "VFW_E_UNSUPPORTED_VIDEO";
              break;
            case -2147220898:
              result = "VFW_E_MPEG_NOT_CONSTRAINED";
              break;
            case -2147220897:
              result = "VFW_E_NOT_IN_GRAPH";
              break;
            case -2147220895:
              result = "VFW_E_NO_TIME_FORMAT";
              break;
            case -2147220894:
              result = "VFW_E_READ_ONLY";
              break;
            case -2147220892:
              result = "VFW_E_BUFFER_UNDERFLOW";
              break;
            case -2147220891:
              result = "VFW_E_UNSUPPORTED_STREAM";
              break;
            case -2147220890:
              result = "VFW_E_NO_TRANSPORT";
              break;
            case -2147220887:
              result = "VFW_E_BAD_VIDEOCD";
              break;
            case -2147220879:
              result = "VFW_E_OUT_OF_VIDEO_MEMORY";
              break;
            case -2147220878:
              result = "VFW_E_VP_NEGOTIATION_FAILED";
              break;
            case -2147220877:
              result = "VFW_E_DDRAW_CAPS_NOT_SUITABLE";
              break;
            case -2147220876:
              result = "VFW_E_NO_VP_HARDWARE";
              break;
            case -2147220875:
              result = "VFW_E_NO_CAPTURE_HARDWARE";
              break;
            case -2147220874:
              result = "VFW_E_DVD_OPERATION_INHIBITED";
              break;
            case -2147220873:
              result = "VFW_E_DVD_INVALIDDOMAIN";
              break;
            case -2147220872:
              result = "VFW_E_DVD_NO_BUTTON";
              break;
            case -2147220871:
              result = "VFW_E_DVD_GRAPHNOTREADY";
              break;
            case -2147220870:
              result = "VFW_E_DVD_RENDERFAIL";
              break;
            case -2147220869:
              result = "VFW_E_DVD_DECNOTENOUGH";
              break;
            case -2147220868:
              result = "VFW_E_DDRAW_VERSION_NOT_SUITABLE";
              break;
            case -2147220867:
              result = "VFW_E_COPYPROT_FAILED";
              break;
            case -2147220865:
              result = "VFW_E_TIME_EXPIRED";
              break;
            case -2147220863:
              result = "VFW_E_DVD_WRONG_SPEED";
              break;
            case -2147220862:
              result = "VFW_E_DVD_MENU_DOES_NOT_EXIST";
              break;
            case -2147220861:
              result = "VFW_E_DVD_CMD_CANCELLED";
              break;
            case -2147220860:
              result = "VFW_E_DVD_STATE_WRONG_VERSION";
              break;
            case -2147220859:
              result = "VFW_E_DVD_STATE_CORRUPT";
              break;
            default:
              return "Unknown";
          }
        }
      }
      else
      {
        if ( a1 == -2147220920 )
          return "VFW_E_INVALID_MEDIA_TYPE";
        if ( a1 > -2147220966 )
        {
          switch ( a1 )
          {
            case -2147220965:
              result = "VFW_E_NOT_OVERLAY_CONNECTION";
              break;
            case -2147220964:
              result = "VFW_E_NOT_SAMPLE_CONNECTION";
              break;
            case -2147220963:
              result = "VFW_E_PALETTE_SET";
              break;
            case -2147220962:
              result = "VFW_E_COLOR_KEY_SET";
              break;
            case -2147220961:
              result = "VFW_E_NO_COLOR_KEY_FOUND";
              break;
            case -2147220960:
              result = "VFW_E_NO_PALETTE_AVAILABLE";
              break;
            case -2147220959:
              result = "VFW_E_NO_DISPLAY_PALETTE";
              break;
            case -2147220958:
              result = "VFW_E_TOO_MANY_COLORS";
              break;
            case -2147220957:
              result = "VFW_E_STATE_CHANGED";
              break;
            case -2147220956:
              result = "VFW_E_NOT_STOPPED";
              break;
            case -2147220955:
              result = "VFW_E_NOT_PAUSED";
              break;
            case -2147220954:
              result = "VFW_E_NOT_RUNNING";
              break;
            case -2147220953:
              result = "VFW_E_WRONG_STATE";
              break;
            case -2147220952:
              result = "VFW_E_START_TIME_AFTER_END";
              break;
            case -2147220951:
              result = "VFW_E_INVALID_RECT";
              break;
            case -2147220950:
              result = "VFW_E_TYPE_NOT_ACCEPTED";
              break;
            case -2147220949:
              result = "VFW_E_SAMPLE_REJECTED";
              break;
            case -2147220948:
              result = "VFW_E_SAMPLE_REJECTED_EOS";
              break;
            case -2147220947:
              result = "VFW_E_DUPLICATE_NAME";
              break;
            case -2147220946:
              result = "VFW_E_TIMEOUT";
              break;
            case -2147220945:
              result = "VFW_E_INVALID_FILE_FORMAT";
              break;
            case -2147220944:
              result = "VFW_E_ENUM_OUT_OF_RANGE";
              break;
            case -2147220943:
              result = "VFW_E_CIRCULAR_GRAPH";
              break;
            case -2147220942:
              result = "VFW_E_NOT_ALLOWED_TO_SAVE";
              break;
            case -2147220941:
              result = "VFW_E_TIME_ALREADY_PASSED";
              break;
            case -2147220940:
              result = "VFW_E_ALREADY_CANCELLED";
              break;
            case -2147220939:
              result = "VFW_E_CORRUPT_GRAPH_FILE";
              break;
            case -2147220938:
              result = "VFW_E_ADVISE_ALREADY_SET";
              break;
            case -2147220936:
              result = "VFW_E_NO_MODEX_AVAILABLE";
              break;
            case -2147220935:
              result = "VFW_E_NO_ADVISE_SET";
              break;
            case -2147220934:
              result = "VFW_E_NO_FULLSCREEN";
              break;
            case -2147220933:
              result = "VFW_E_IN_FULLSCREEN_MODE";
              break;
            case -2147220928:
              result = "VFW_E_UNKNOWN_FILE_TYPE";
              break;
            case -2147220927:
              result = "VFW_E_CANNOT_LOAD_SOURCE_FILTER";
              break;
            case -2147220925:
              result = "VFW_E_FILE_TOO_SHORT";
              break;
            case -2147220924:
              result = "VFW_E_INVALID_FILE_VERSION";
              break;
            case -2147220921:
              result = "VFW_E_INVALID_CLSID";
              break;
            default:
              return "Unknown";
          }
        }
        else
        {
          if ( a1 == -2147220966 )
            return "VFW_E_NO_COLOR_KEY_SET";
          if ( a1 > -2147220985 )
          {
            switch ( a1 )
            {
              case -2147220984:
                result = "DIERR_EFFECTPLAYING & VFW_E_INVALID_DIRECTION";
                break;
              case -2147220983:
                result = "DIERR_UNPLUGGED & VFW_E_NOT_CONNECTED";
                break;
              case -2147220982:
                result = "DIERR_REPORTFULL & VFW_E_NO_ALLOCATOR";
                break;
              case -2147220981:
                result = "DIERR_MAPFILEFAIL & VFW_E_RUNTIME_ERROR";
                break;
              case -2147220980:
                result = "VFW_E_BUFFER_NOTSET";
                break;
              case -2147220979:
                result = "VFW_E_BUFFER_OVERFLOW";
                break;
              case -2147220978:
                result = "VFW_E_BADALIGN";
                break;
              case -2147220977:
                result = "VFW_E_ALREADY_COMMITTED";
                break;
              case -2147220976:
                result = "VFW_E_BUFFERS_OUTSTANDING";
                break;
              case -2147220975:
                result = "VFW_E_NOT_COMMITTED";
                break;
              case -2147220974:
                result = "VFW_E_SIZENOTSET";
                break;
              case -2147220973:
                result = "VFW_E_NO_CLOCK";
                break;
              case -2147220972:
                result = "VFW_E_NO_SINK";
                break;
              case -2147220971:
                result = "VFW_E_NO_INTERFACE";
                break;
              case -2147220970:
                result = "VFW_E_NOT_FOUND";
                break;
              case -2147220969:
                result = "VFW_E_CANNOT_CONNECT";
                break;
              case -2147220968:
                result = "VFW_E_CANNOT_RENDER";
                break;
              case -2147220967:
                result = "VFW_E_CHANGING_FORMAT";
                break;
            }
          }
          else
          {
            if ( a1 == -2147220985 )
              return "DIERR_NOTBUFFERED & VFW_E_NO_ACCEPTABLE_TYPES";
            if ( a1 <= -2147221008 )
            {
              if ( a1 == -2147221008 )
                return "CO_E_NOTINITIALIZED";
              if ( a1 > -2147467260 )
              {
                switch ( a1 )
                {
                  case -2147467259:
                    return "E_FAIL";
                  case -2147418113:
                    return "E_UNEXPECTED";
                  case -2147221232:
                    return "CLASS_E_NOAGGREGATION";
                  case -2147221164:
                    return "REGDB_E_CLASSNOTREG";
                  default:
                    break;
                }
              }
              else
              {
                switch ( a1 )
                {
                  case -2147467260:
                    return "E_ABORT";
                  case -2147483638:
                    return "E_PENDING";
                  case -2147467263:
                    return "E_NOTIMPL";
                  case -2147467262:
                    return "E_NOINTERFACE";
                  case -2147467261:
                    return "E_POINTER";
                  default:
                    break;
                }
              }
              return "Unknown";
            }
            if ( a1 <= -2147220989 )
            {
              switch ( a1 )
              {
                case -2147220989:
                  return "DIERR_NOTDOWNLOADED & VFW_E_ENUM_OUT_OF_SYNC & DMO_E_TYPE_NOT_SET";
                case -2147221007:
                  return "CO_E_ALREADYINITIALIZED";
                case -2147220992:
                  return "DIERR_INSUFFICIENTPRIVS & VFW_E_INVALIDMEDIATYPE";
                case -2147220991:
                  return "DIERR_DEVICEFULL & VFW_E_INVALIDSUBTYPE & DMO_E_INVALIDSTREAMINDEX";
                case -2147220990:
                  return "DIERR_MOREDATA & VFW_E_NEED_OWNER & DMO_E_INVALIDTYPE";
                default:
                  break;
              }
              return "Unknown";
            }
            if ( a1 == -2147220988 )
            {
              return "DIERR_HASEFFECTS & VFW_E_ALREADY_CONNECTED & DMO_E_NOTACCEPTING";
            }
            else if ( a1 == -2147220987 )
            {
              return "DIERR_NOTEXCLUSIVEACQUIRED & VFW_E_FILTER_ACTIVE & DMO_E_TYPE_NOT_ACCEPTED";
            }
            else
            {
              return "DIERR_INCOMPLETEEFFECT & VFW_E_NO_TYPES & DMO_E_NO_MORE_ITEMS";
            }
          }
        }
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00408400
// Name: Direct3DCreate8(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
int __stdcall Direct3DCreate8(int a1)
{
  return __imp__Direct3DCreate8@4(a1);
}

//------------------------------------------------------------------------------
// Address: 0x00408406
// Name: D3DXMatrixPerspectiveFovLH(x,x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
float *__stdcall D3DXMatrixPerspectiveFovLH(float *a1, float a2, float a3, float a4, float a5)
{
  double v6; // st7
  double v7; // st7
  float v8; // [esp+8h] [ebp-8h]
  float v9; // [esp+Ch] [ebp-4h]
  float v10; // [esp+1Ch] [ebp+Ch]

  v8 = a2 * 0.5;
  v10 = cos(v8);
  v9 = sin(v8);
  v6 = v10 / v9;
  *a1 = a3 * v6;
  a1[1] = 0.0;
  a1[2] = 0.0;
  a1[3] = 0.0;
  a1[4] = 0.0;
  a1[5] = v6;
  a1[6] = 0.0;
  a1[7] = 0.0;
  a1[8] = 0.0;
  a1[9] = 0.0;
  v7 = a5 / (a5 - a4);
  a1[10] = v7;
  a1[11] = 1.0;
  a1[12] = 0.0;
  a1[13] = 0.0;
  a1[14] = -(v7 * a4);
  a1[15] = 0.0;
  return a1;
}
