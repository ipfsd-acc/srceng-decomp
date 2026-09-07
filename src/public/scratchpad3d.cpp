// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/scratchpad3d.cpp
// Functions: 39
// ============================================================

#include "public\scratchpad3d.h"

//------------------------------------------------------------------------------
// Address: 0x00401A90
// Name: public: virtual void CScratchPad3D::CCommand_Point::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Point::Read(CScratchPad3D::CCommand_Point *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_flPointSize,
                    a3: 4,
                    a4: pFile->m_fp);
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: (void *)&this->m_Vert,
                    a3: 28,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x00401AE0
// Name: public: virtual void CScratchPad3D::CCommand_Point::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Point::Write(
        CScratchPad3D::CCommand_Point *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_flPointSize, a3: 4, a4: fp);
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_Vert, a3: 28, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x00401B20
// Name: public: virtual void CScratchPad3D::CCommand_Line::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Line::Read(CScratchPad3D::CCommand_Line *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: (void *)this->m_Verts,
                    a3: 56,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x00401B50
// Name: public: virtual void CScratchPad3D::CCommand_Line::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Line::Write(
        CScratchPad3D::CCommand_Line *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: this->m_Verts, a3: 56, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x00401B80
// Name: public: virtual void CScratchPad3D::CCommand_Matrix::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Matrix::Read(CScratchPad3D::CCommand_Matrix *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_mMatrix,
                    a3: 64,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x00401BB0
// Name: public: virtual void CScratchPad3D::CCommand_Matrix::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Matrix::Write(
        CScratchPad3D::CCommand_Matrix *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_mMatrix, a3: 64, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x00401BE0
// Name: public: virtual void CScratchPad3D::CCommand_RenderState::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_RenderState::Read(CScratchPad3D::CCommand_RenderState *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_State,
                    a3: 4,
                    a4: pFile->m_fp);
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_Val,
                    a3: 4,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x00401C30
// Name: public: virtual void CScratchPad3D::CCommand_RenderState::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_RenderState::Write(
        CScratchPad3D::CCommand_RenderState *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_State, a3: 4, a4: fp);
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_Val, a3: 4, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x00401C70
// Name: public: virtual void CScratchPad3D::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Release(CScratchPad3D *this)
{
  this->Flush(this);
  ((void (__thiscall *)(CScratchPad3D *, int))this->dtr_IScratchPad3D)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x00401C90
// Name: public: virtual bool CScratchPad3D::GetAutoFlush(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScratchPad3D::GetAutoFlush(CScratchPad3D *this)
{
  return this->m_bAutoFlush;
}

//------------------------------------------------------------------------------
// Address: 0x00401CA0
// Name: public: virtual void CScratchPad3D::SetAutoFlush(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetAutoFlush(CScratchPad3D *this, bool bAutoFlush)
{
  this->m_bAutoFlush = bAutoFlush;
  if ( bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x00401CC0
// Name: public: class CTextParams __near & CTextParams::operator=(class CTextParams const __near &)
// Source: json
//------------------------------------------------------------------------------
CTextParams *__thiscall CTextParams::operator=(CTextParams *this, const CTextParams *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00401D30
// Name: public: virtual void CScratchPad3D::DrawImageBW(unsigned char const __near *,int,int,int,bool,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawImageBW(
        CScratchPad3D *this,
        const unsigned __int8 *pData,
        int width,
        int height,
        int pitchInBytes,
        BOOL bOutlinePixels,
        BOOL bOutlineImage,
        Vector *vCorners)
{
  int v8; // esi
  CScratchPad3D *v10; // ebx
  SPRGBA *v11; // eax
  const unsigned __int8 *v12; // edx
  SPRGBA *v13; // ebx
  SPRGBA *v14; // eax
  int i; // esi
  unsigned __int8 v16; // cl
  bool v17; // zf
  SPRGBA *pRGBA; // [esp+10h] [ebp-4h]
  const unsigned __int8 *pDataa; // [esp+1Ch] [ebp+8h]
  const unsigned __int8 *widtha; // [esp+20h] [ebp+Ch]

  v8 = height;
  v10 = this;
  v11 = (SPRGBA *)operator new(nSize: 4 * height * width);
  pRGBA = v11;
  if ( height > 0 )
  {
    v12 = pData;
    widtha = pData;
    v13 = v11;
    pDataa = (const unsigned __int8 *)height;
    do
    {
      v14 = v13;
      if ( width > 0 )
      {
        for ( i = width; i != 0; --i )
        {
          v16 = *v12;
          v14->b = *v12;
          v14->g = v16;
          v14->r = v16;
          ++v12;
          ++v14;
        }
        v8 = height;
        v12 = widtha;
      }
      v12 += pitchInBytes;
      v13 += width;
      v17 = pDataa-- == (const unsigned __int8 *)1;
      widtha = v12;
    }
    while ( !v17 );
    v10 = this;
    v11 = pRGBA;
  }
  v10->DrawImageRGBA(
    this: v10,
    a2: v11,
    a3: width,
    a4: v8,
    a5: 4 * width,
    a6: bOutlinePixels,
    a7: bOutlineImage,
    a8: vCorners);
  free(pMem: pRGBA);
}

//------------------------------------------------------------------------------
// Address: 0x00401DF0
// Name: class IFileSystem __near * ScratchPad3D_SetupFileSystem(void)
// Source: json
//------------------------------------------------------------------------------
IFileSystem *__cdecl ScratchPad3D_SetupFileSystem()
{
  struct CSysModule *Module; // eax
  struct CSysModule *v1; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IFileSystem *result; // eax

  Module = Sys_LoadModule(pModuleName: "filesystem_stdio");
  v1 = Module;
  if ( Module == nullptr )
    return nullptr;
  Factory = Sys_GetFactory(pModule: Module);
  if ( Factory == nullptr || (result = (IFileSystem *)Factory(a1: "VFileSystem017", a2: nullptr)) == nullptr )
  {
    Sys_UnloadModule(pModule: v1);
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401F50
// Name: public: void CUtlMemory<class CScratchPad3D::CBaseCommand __near *,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<CScratchPad3D::CBaseCommand *,int>::Grow(
        CUtlMemory<CScratchPad3D::CBaseCommand *,int> *this,
        int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  CScratchPad3D::CBaseCommand **m_pMemory; // edx
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
        m_nAllocationCount = 8;
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
    v7 = 4 * m_nAllocationCount;
    if ( m_pMemory != nullptr )
      this->m_pMemory = (CScratchPad3D::CBaseCommand **)_g_pMemAlloc->Realloc_2(
                                                          this: _g_pMemAlloc,
                                                          a2: m_pMemory,
                                                          a3: v7);
    else
      this->m_pMemory = (CScratchPad3D::CBaseCommand **)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: v7);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401FE0
// Name: public: virtual void CScratchPad3D::CCommand_Polygon::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Polygon::Write(
        CScratchPad3D::CCommand_Polygon *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  int (__thiscall *Write)(IBaseFileSystem *, const void *, int, void *); // edx
  int count; // [esp+Ch] [ebp-4h] BYREF

  Write = pFileSystem->Write;
  count = this->m_Verts.m_Size;
  Write(this: &pFileSystem->IBaseFileSystem, a2: &count, a3: 4, a4: fp);
  if ( count != 0 )
    pFileSystem->Write(
      this: &pFileSystem->IBaseFileSystem,
      a2: this->m_Verts.m_Memory.m_pMemory,
      a3: 28 * count,
      a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x00402040
// Name: public: virtual void CScratchPad3D::CCommand_Text::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Text::Write(
        CScratchPad3D::CCommand_Text *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  int (__thiscall *Write)(IBaseFileSystem *, const void *, int, void *); // edx
  IBaseFileSystem *v5; // esi
  int strLen; // [esp+Ch] [ebp-4h] BYREF

  Write = pFileSystem->Write;
  v5 = &pFileSystem->IBaseFileSystem;
  strLen = this->m_String.m_Size;
  Write(this: &pFileSystem->IBaseFileSystem, a2: &strLen, a3: 4, a4: fp);
  v5->Write(this: v5, a2: this->m_String.m_Memory.m_pMemory, a3: strLen, a4: fp);
  v5->Write(this: v5, a2: &this->m_TextParams, a3: 56, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x004020A0
// Name: public: virtual void CScratchPad3D::DrawWireframeBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawWireframeBox(
        CScratchPad3D *this,
        const Vector *vMin,
        const Vector *vMax,
        const Vector *vColor)
{
  float y; // xmm3_4
  float z; // xmm4_4
  float x; // xmm0_4
  float v7; // xmm1_4
  float v9; // xmm2_4
  void (__thiscall *DrawLine)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  void (__thiscall *v15)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  void (__thiscall *v22)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  void (__thiscall *v27)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  void (__thiscall *v34)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v35; // xmm3_4
  float v36; // xmm4_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  void (__thiscall *v39)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  void (__thiscall *v45)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  float v49; // xmm4_4
  float v50; // xmm1_4
  void (__thiscall *v51)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v52; // xmm2_4
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  void (__thiscall *v58)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v59; // xmm3_4
  float v60; // xmm4_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  void (__thiscall *v63)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v64; // xmm2_4
  float v65; // xmm3_4
  float v66; // xmm4_4
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm2_4
  void (__thiscall *v71)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v72; // xmm3_4
  float v73; // xmm4_4
  float v74; // xmm0_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  void (__thiscall *v77)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v78; // [esp+0h] [ebp-54h] BYREF
  float v79; // [esp+4h] [ebp-50h]
  float v80; // [esp+8h] [ebp-4Ch]
  float v81; // [esp+Ch] [ebp-48h]
  float v82; // [esp+10h] [ebp-44h]
  float v83; // [esp+14h] [ebp-40h]
  int v84; // [esp+18h] [ebp-3Ch]
  float v85; // [esp+1Ch] [ebp-38h] BYREF
  float v86; // [esp+20h] [ebp-34h]
  float v87; // [esp+24h] [ebp-30h]
  float v88; // [esp+28h] [ebp-2Ch]
  float v89; // [esp+2Ch] [ebp-28h]
  float v90; // [esp+30h] [ebp-24h]
  int v91; // [esp+34h] [ebp-20h]
  _DWORD v92[5]; // [esp+38h] [ebp-1Ch] BYREF
  float v93; // [esp+4Ch] [ebp-8h]
  float v94; // [esp+50h] [ebp-4h]

  y = vMin->y;
  z = vMin->z;
  x = vColor->x;
  v7 = vColor->y;
  v93 = vColor->z;
  v85 = vMax->x;
  v86 = y;
  v87 = z;
  v9 = vMin->x;
  DrawLine = this->DrawLine;
  v88 = x;
  v81 = x;
  v89 = v7;
  v90 = v93;
  v91 = 1065353216;
  v78 = v9;
  v79 = y;
  v80 = z;
  v82 = v7;
  v83 = v93;
  v84 = 1065353216;
  DrawLine(this, a2: (const CSPVert *)&v78, a3: (const CSPVert *)&v85);
  v11 = vMin->x;
  v12 = vMin->z;
  v13 = vColor->x;
  v14 = vColor->y;
  v15 = this->DrawLine;
  v93 = vColor->z;
  v78 = v11;
  v79 = vMax->y;
  v80 = v12;
  v16 = vMin->y;
  v81 = v13;
  v88 = v13;
  v82 = v14;
  v83 = v93;
  v84 = 1065353216;
  v85 = v11;
  v86 = v16;
  v87 = v12;
  v89 = v14;
  v90 = v93;
  v91 = 1065353216;
  v15(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v17 = vMax->x;
  v18 = vMin->z;
  v19 = vColor->x;
  v20 = vColor->y;
  v93 = vColor->z;
  v78 = v17;
  v79 = vMax->y;
  v80 = v18;
  v21 = vMin->y;
  v22 = this->DrawLine;
  v81 = v19;
  v88 = v19;
  v82 = v20;
  v83 = v93;
  v84 = 1065353216;
  v85 = v17;
  v86 = v21;
  v87 = v18;
  v89 = v20;
  v90 = v93;
  v91 = 1065353216;
  v22(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v23 = vMin->z;
  v24 = vMax->y;
  v25 = vColor->x;
  v26 = vColor->y;
  v27 = this->DrawLine;
  v93 = vColor->z;
  v78 = vMin->x;
  v79 = v24;
  v80 = v23;
  v28 = vMax->x;
  v81 = v25;
  v88 = v25;
  v82 = v26;
  v83 = v93;
  v84 = 1065353216;
  v85 = v28;
  v86 = v24;
  v87 = v23;
  v89 = v26;
  v90 = v93;
  v91 = 1065353216;
  v27(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v29 = vColor->x;
  v30 = vColor->y;
  v31 = vMin->y;
  v32 = vMax->z;
  v93 = vColor->z;
  v78 = vMax->x;
  v79 = v31;
  v80 = v32;
  v33 = vMin->x;
  v34 = this->DrawLine;
  v81 = v29;
  v88 = v29;
  v82 = v30;
  v83 = v93;
  v84 = 1065353216;
  v85 = v33;
  v86 = v31;
  v87 = v32;
  v89 = v30;
  v90 = v93;
  v91 = 1065353216;
  v34(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v35 = vMin->x;
  v36 = vMax->z;
  v37 = vColor->x;
  v38 = vColor->y;
  v39 = this->DrawLine;
  v93 = vColor->z;
  v78 = v35;
  v79 = vMax->y;
  v80 = v36;
  v40 = vMin->y;
  v81 = v37;
  v88 = v37;
  v82 = v38;
  v83 = v93;
  v84 = 1065353216;
  v85 = v35;
  v86 = v40;
  v87 = v36;
  v89 = v38;
  v90 = v93;
  v91 = 1065353216;
  v39(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v41 = vMax->x;
  v42 = vMax->z;
  v43 = vColor->x;
  v44 = vColor->y;
  v93 = vColor->z;
  v45 = this->DrawLine;
  v78 = v41;
  v79 = vMax->y;
  v80 = v42;
  v46 = vMin->y;
  v81 = v43;
  v88 = v43;
  v82 = v44;
  v83 = v93;
  v84 = 1065353216;
  v85 = v41;
  v86 = v46;
  v87 = v42;
  v89 = v44;
  v90 = v93;
  v91 = 1065353216;
  v45(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v47 = vMax->y;
  v48 = vColor->x;
  v49 = vMax->z;
  v50 = vColor->y;
  v51 = this->DrawLine;
  v93 = vColor->z;
  v78 = vMin->x;
  v79 = v47;
  v80 = v49;
  v52 = vMax->x;
  v81 = v48;
  v88 = v48;
  v82 = v50;
  v83 = v93;
  v84 = 1065353216;
  v85 = v52;
  v86 = v47;
  v87 = v49;
  v89 = v50;
  v90 = v93;
  v91 = 1065353216;
  v51(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v53 = vMin->x;
  v54 = vMin->y;
  v55 = vColor->x;
  v56 = vColor->y;
  v93 = vColor->z;
  v78 = v53;
  v79 = v54;
  v80 = vMax->z;
  v57 = vMin->z;
  v58 = this->DrawLine;
  v81 = v55;
  v88 = v55;
  v82 = v56;
  v83 = v93;
  v84 = 1065353216;
  v85 = v53;
  v86 = v54;
  v87 = v57;
  v89 = v56;
  v90 = v93;
  v91 = 1065353216;
  v58(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v59 = vMin->x;
  v60 = vMax->y;
  v61 = vColor->x;
  v62 = vColor->y;
  v63 = this->DrawLine;
  v93 = vColor->z;
  v78 = v59;
  v79 = v60;
  v80 = vMax->z;
  v64 = vMin->z;
  v81 = v61;
  v88 = v61;
  v82 = v62;
  v83 = v93;
  v84 = 1065353216;
  v85 = v59;
  v86 = v60;
  v87 = v64;
  v89 = v62;
  v90 = v93;
  v91 = 1065353216;
  v63(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v65 = vMax->x;
  v66 = vMax->y;
  v67 = vColor->x;
  v68 = vColor->y;
  v93 = vColor->z;
  v78 = v65;
  v79 = v66;
  v69 = vMax->z;
  v81 = v67;
  v80 = v69;
  v82 = v68;
  v83 = v93;
  v70 = vMin->z;
  v71 = this->DrawLine;
  v88 = v67;
  v84 = 1065353216;
  v85 = v65;
  v86 = v66;
  v87 = v70;
  v89 = v68;
  v90 = v93;
  v91 = 1065353216;
  v71(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v72 = vMax->x;
  v73 = vMin->y;
  v74 = vColor->x;
  v75 = vColor->y;
  v90 = vColor->z;
  v94 = vMax->z;
  v78 = v72;
  v79 = v73;
  v80 = v94;
  v76 = vMin->z;
  v77 = this->DrawLine;
  v81 = v74;
  *(float *)&v92[3] = v74;
  v82 = v75;
  v83 = v90;
  v84 = 1065353216;
  *(float *)v92 = v72;
  *(float *)&v92[1] = v73;
  *(float *)&v92[2] = v76;
  *(float *)&v92[4] = v75;
  v93 = v90;
  v94 = 1.0;
  v77(this, a2: (const CSPVert *)v92, a3: (const CSPVert *)&v78);
}

//------------------------------------------------------------------------------
// Address: 0x00402800
// Name: public: void CScratchPad3D::DeleteCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DeleteCommands(CScratchPad3D *this)
{
  int v2; // ebx
  CScratchPad3D::CBaseCommand *v3; // esi
  CScratchPad3D::ICachedRenderData *m_pCachedRenderData; // ecx

  v2 = 0;
  if ( this->m_Commands.m_Size <= 0 )
  {
    this->m_Commands.m_Size = 0;
  }
  else
  {
    do
    {
      v3 = this->m_Commands.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        m_pCachedRenderData = v3->m_pCachedRenderData;
        v3->__vftable = (CScratchPad3D::CBaseCommand_vtbl *)&CScratchPad3D::CBaseCommand::`vftable';
        if ( m_pCachedRenderData != nullptr )
        {
          m_pCachedRenderData->Release(this: m_pCachedRenderData);
          v3->m_pCachedRenderData = nullptr;
        }
        free(pMem: v3);
      }
      ++v2;
    }
    while ( v2 < this->m_Commands.m_Size );
    this->m_Commands.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402860
// Name: public: virtual void CScratchPad3D::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Clear(CScratchPad3D *this)
{
  void *i; // eax

  for ( i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "wb",
              a4: 0);
        i == nullptr;
        i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "wb",
              a4: 0) )
  {
    Sleep(dwMilliseconds: 5u);
  }
  this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: i);
  CScratchPad3D::DeleteCommands(this);
}

//------------------------------------------------------------------------------
// Address: 0x004028C0
// Name: public: virtual void CScratchPad3D::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Flush(CScratchPad3D *this)
{
  void *i; // edi
  int j; // ebx
  CScratchPad3D::CBaseCommand *v4; // ecx

  for ( i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "ab+",
              a4: 0);
        i == nullptr;
        i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "ab+",
              a4: 0) )
  {
    Sleep(dwMilliseconds: 5u);
  }
  for ( j = 0; j < this->m_Commands.m_Size; ++j )
  {
    this->m_pFileSystem->Write(
      this: &this->m_pFileSystem->IBaseFileSystem,
      a2: &this->m_Commands.m_Memory.m_pMemory[j]->m_iCommand,
      a3: 1,
      a4: i);
    v4 = this->m_Commands.m_Memory.m_pMemory[j];
    v4->Write(this: v4, a2: this->m_pFileSystem, a3: i);
  }
  this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: i);
  CScratchPad3D::DeleteCommands(this);
}

//------------------------------------------------------------------------------
// Address: 0x00402B90
// Name: public: CScratchPad3D::CCommand_Text::CCommand_Text(void)
// Source: json
//------------------------------------------------------------------------------
CScratchPad3D::CCommand_Text *__thiscall CScratchPad3D::CCommand_Text::CCommand_Text(
        CScratchPad3D::CCommand_Text *this)
{
  this->m_iCommand = 5;
  this->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_Text::`vftable';
  this->m_pCachedRenderData = nullptr;
  this->m_String.m_Memory.m_pMemory = nullptr;
  this->m_String.m_Memory.m_nAllocationCount = 0;
  this->m_String.m_Memory.m_nGrowSize = 0;
  this->m_String.m_Size = 0;
  this->m_String.m_pElements = nullptr;
  this->m_TextParams.m_vColor.x = 1.0;
  this->m_TextParams.m_vColor.y = 1.0;
  this->m_TextParams.m_vColor.z = 1.0;
  this->m_TextParams.m_flAlpha = 1.0;
  *(_WORD *)&this->m_TextParams.m_bSolidBackground = 257;
  this->m_TextParams.m_vPos.x = 0.0;
  this->m_TextParams.m_vPos.y = 0.0;
  this->m_TextParams.m_vPos.z = 0.0;
  this->m_TextParams.m_bCentered = true;
  this->m_TextParams.m_vAngles.x = 0.0;
  this->m_TextParams.m_vAngles.y = 0.0;
  this->m_TextParams.m_vAngles.z = 0.0;
  this->m_TextParams.m_bTwoSided = true;
  this->m_TextParams.m_flLetterWidth = 3.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402C10
// Name: public: CScratchPad3D::CScratchPad3D(char const __near *,class IFileSystem __near *,bool)
// Source: json
//------------------------------------------------------------------------------
CScratchPad3D *__thiscall CScratchPad3D::CScratchPad3D(
        CScratchPad3D *this,
        const char *pFilename,
        IFileSystem *pFileSystem,
        bool bAutoClear)
{
  this->__vftable = (CScratchPad3D_vtbl *)&CScratchPad3D::`vftable';
  this->m_Commands.m_Memory.m_pMemory = nullptr;
  this->m_Commands.m_Memory.m_nAllocationCount = 0;
  this->m_Commands.m_Memory.m_nGrowSize = 0;
  this->m_Commands.m_Size = 0;
  this->m_Commands.m_pElements = nullptr;
  this->m_pFileSystem = pFileSystem;
  this->m_pFilename = pFilename;
  this->m_bAutoFlush = true;
  if ( bAutoClear )
    CScratchPad3D::Clear(this);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402C50
// Name: public: CSPVertList::CSPVertList(class Vector const __near *,int,class CSPColor)
// Source: json
//------------------------------------------------------------------------------
CSPVertList *__thiscall CSPVertList::CSPVertList(CSPVertList *this, const Vector *pVerts, int nVerts, CSPColor vColor)
{
  int v4; // ebx
  signed int v6; // eax
  int v7; // ecx
  float *p_z; // eax
  unsigned int v9; // ebx
  CSPVert *m_pMemory; // edx
  CSPVert *v11; // edx
  int v12; // edx
  CSPVert *v13; // edx
  int v14; // edx
  CSPVert *v15; // edx
  unsigned int v16; // ecx
  float *v17; // edx
  int v18; // ebx
  CSPVert *v19; // eax
  int i; // [esp+Ch] [ebp-4h]

  v4 = nVerts;
  this->m_Verts.m_Memory.m_pMemory = nullptr;
  this->m_Verts.m_Memory.m_nAllocationCount = 0;
  this->m_Verts.m_Memory.m_nGrowSize = 0;
  this->m_Verts.m_Size = 0;
  this->m_Verts.m_pElements = nullptr;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(this: &this->m_Verts, elem: 0, num: nVerts);
  v6 = 0;
  if ( nVerts >= 4 )
  {
    v7 = 0;
    p_z = &pVerts[1].z;
    v9 = ((unsigned int)(nVerts - 4) >> 2) + 1;
    i = 4 * v9;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pMemory[v7].m_vPos.x = *(p_z - 5);
      p_z += 12;
      m_pMemory[v7].m_vPos.y = *(p_z - 16);
      m_pMemory[v7].m_vPos.z = *(p_z - 15);
      this->m_Verts.m_Memory.m_pMemory[v7].m_vColor = vColor;
      v11 = this->m_Verts.m_Memory.m_pMemory;
      v11[v7 + 1].m_vPos.x = *(p_z - 14);
      v12 = (int)&v11[v7 + 1];
      *(float *)(v12 + 4) = *(p_z - 13);
      *(float *)(v12 + 8) = *(p_z - 12);
      this->m_Verts.m_Memory.m_pMemory[v7 + 1].m_vColor = vColor;
      v13 = this->m_Verts.m_Memory.m_pMemory;
      v13[v7 + 2].m_vPos.x = *(p_z - 11);
      v14 = (int)&v13[v7 + 2];
      *(float *)(v14 + 4) = *(p_z - 10);
      *(float *)(v14 + 8) = *(p_z - 9);
      this->m_Verts.m_Memory.m_pMemory[v7 + 2].m_vColor = vColor;
      v15 = this->m_Verts.m_Memory.m_pMemory;
      v15[v7 + 3].m_vPos.x = *(p_z - 8);
      v15[v7 + 3].m_vPos.y = *(p_z - 7);
      v15[v7 + 3].m_vPos.z = *(p_z - 6);
      this->m_Verts.m_Memory.m_pMemory[v7 + 3].m_vColor = vColor;
      v7 += 4;
      --v9;
    }
    while ( v9 != 0 );
    v6 = i;
    v4 = nVerts;
  }
  if ( v6 < v4 )
  {
    v16 = v6;
    v17 = &pVerts[v6].z;
    v18 = v4 - v6;
    do
    {
      v19 = this->m_Verts.m_Memory.m_pMemory;
      v19[v16].m_vPos.x = *(v17 - 2);
      v17 += 3;
      v19[v16].m_vPos.y = *(v17 - 4);
      v19[v16].m_vPos.z = *(v17 - 3);
      this->m_Verts.m_Memory.m_pMemory[v16++].m_vColor = vColor;
      --v18;
    }
    while ( v18 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00402E50
// Name: public: virtual void CScratchPad3D::CCommand_Polygon::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Polygon::Read(CScratchPad3D::CCommand_Polygon *this, int pFile)
{
  CFileRead *v2; // esi
  CFileRead *v4; // ecx

  v2 = (CFileRead *)pFile;
  v2->m_Pos += (**(int (__thiscall ***)(int, int *, int, _DWORD))(*(_DWORD *)pFile + 4))(
                 a1: *(_DWORD *)pFile + 4,
                 a2: &pFile,
                 a3: 4,
                 a4: *(_DWORD *)(pFile + 4));
  v4 = (CFileRead *)pFile;
  this->m_Verts.m_Size = 0;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(
    this: &this->m_Verts,
    elem: this->m_Verts.m_Size,
    num: (int)v4);
  if ( pFile != 0 )
    v2->m_Pos += v2->m_pFileSystem->Read(
                   this: &v2->m_pFileSystem->IBaseFileSystem,
                   a2: (void *)this->m_Verts.m_Memory.m_pMemory,
                   a3: 28 * pFile,
                   a4: v2->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x00402EF0
// Name: public: bool CScratchPad3D::LoadCommandsFromFile(void)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CScratchPad3D::LoadCommandsFromFile(CScratchPad3D *this)
{
  CScratchPad3D *v1; // esi
  void *v2; // edi
  int v3; // eax
  IFileSystem *m_pFileSystem; // ecx
  int v5; // eax
  CScratchPad3D::CCommand_Text *v6; // eax
  CScratchPad3D::CCommand_Text *v7; // eax
  CScratchPad3D::CCommand_Text *v8; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v12; // eax
  CScratchPad3D::CBaseCommand **v13; // ebx
  CFileRead fileRead; // [esp+Ch] [ebp-1Ch] BYREF
  int fileEndPos; // [esp+18h] [ebp-10h]
  CScratchPad3D *v17; // [esp+1Ch] [ebp-Ch]
  void *fp; // [esp+20h] [ebp-8h]
  unsigned __int8 iCommand; // [esp+27h] [ebp-1h] BYREF

  v1 = this;
  v17 = this;
  CScratchPad3D::DeleteCommands(this);
  v2 = v1->m_pFileSystem->Open(this: &v1->m_pFileSystem->IBaseFileSystem, a2: v1->m_pFilename, a3: "rb", a4: nullptr);
  fp = v2;
  if ( v2 == nullptr )
    return 0;
  v3 = v1->m_pFileSystem->Size_2(this: &v1->m_pFileSystem->IBaseFileSystem, a2: v2);
  m_pFileSystem = v1->m_pFileSystem;
  fileEndPos = v3;
  fileRead.m_pFileSystem = m_pFileSystem;
  fileRead.m_fp = v2;
  fileRead.m_Pos = 0;
  if ( v3 != 0 )
  {
    while ( 1 )
    {
      v5 = fileRead.m_pFileSystem->Read(
             this: &fileRead.m_pFileSystem->IBaseFileSystem,
             a2: &iCommand,
             a3: 1,
             a4: fileRead.m_fp);
      fileRead.m_Pos += v5;
      if ( iCommand != 0 )
      {
        switch ( iCommand )
        {
          case 1u:
            v6 = (CScratchPad3D::CCommand_Text *)operator new(nSize: 0x44u);
            if ( v6 == nullptr )
              goto LABEL_31;
            v6->m_iCommand = 1;
            v6->m_pCachedRenderData = nullptr;
            v6->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_Line::`vftable';
            v6->m_TextParams.m_vColor.y = 1.0;
            *(_DWORD *)&v6->m_TextParams.m_bCentered = 1065353216;
            break;
          case 2u:
            v6 = (CScratchPad3D::CCommand_Text *)operator new(nSize: 0x20u);
            if ( v6 == nullptr )
              goto LABEL_31;
            v6->m_iCommand = 2;
            v6->m_pCachedRenderData = nullptr;
            v6->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_Polygon::`vftable';
            v6->m_String.m_Memory.m_pMemory = nullptr;
            v6->m_String.m_Memory.m_nAllocationCount = 0;
            v6->m_String.m_Memory.m_nGrowSize = 0;
            v6->m_String.m_Size = 0;
            v6->m_String.m_pElements = nullptr;
            break;
          case 3u:
            v6 = (CScratchPad3D::CCommand_Text *)operator new(nSize: 0x4Cu);
            if ( v6 == nullptr )
              goto LABEL_31;
            v6->m_iCommand = 3;
            v6->m_pCachedRenderData = nullptr;
            v6->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_Matrix::`vftable';
            break;
          case 4u:
            v6 = (CScratchPad3D::CCommand_Text *)operator new(nSize: 0x14u);
            if ( v6 == nullptr )
              goto LABEL_31;
            v6->m_iCommand = 4;
            v6->m_pCachedRenderData = nullptr;
            v6->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_RenderState::`vftable';
            break;
          case 5u:
            v7 = (CScratchPad3D::CCommand_Text *)operator new(nSize: 0x58u);
            if ( v7 == nullptr )
              goto LABEL_31;
            v6 = CScratchPad3D::CCommand_Text::CCommand_Text(this: v7);
            break;
          default:
            goto LABEL_31;
        }
      }
      else
      {
        v6 = (CScratchPad3D::CCommand_Text *)operator new(nSize: 0x2Cu);
        if ( v6 == nullptr )
          goto LABEL_31;
        v6->m_iCommand = 0;
        v6->m_pCachedRenderData = nullptr;
        v6->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_Point::`vftable';
        v6->m_TextParams.m_vColor.z = 1.0;
      }
      v8 = v6;
      if ( v6 == nullptr )
        break;
      v6->Read(this: v6, a2: &fileRead);
      m_Size = v1->m_Commands.m_Size;
      m_nAllocationCount = v1->m_Commands.m_Memory.m_nAllocationCount;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CScratchPad3D::CBaseCommand *,int>::Grow(
          this: &v1->m_Commands.m_Memory,
          num: m_Size - m_nAllocationCount + 1);
      ++v1->m_Commands.m_Size;
      m_pMemory = v1->m_Commands.m_Memory.m_pMemory;
      v12 = v1->m_Commands.m_Size - m_Size - 1;
      v1->m_Commands.m_pElements = m_pMemory;
      if ( v12 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v12);
      v13 = &v1->m_Commands.m_Memory.m_pMemory[m_Size];
      if ( v13 != nullptr )
        *v13 = v8;
      v1 = v17;
      v2 = fp;
      if ( fileRead.m_Pos == fileEndPos )
        goto LABEL_33;
    }
    v2 = fp;
LABEL_31:
    v1->m_pFileSystem->Close(this: &v1->m_pFileSystem->IBaseFileSystem, a2: v2);
    return 0;
  }
LABEL_33:
  v1->m_pFileSystem->Close(this: &v1->m_pFileSystem->IBaseFileSystem, a2: v2);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403130
// Name: public: virtual void CScratchPad3D::SetMapping(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetMapping(
        CScratchPad3D *this,
        const Vector *vInputMin,
        const Vector *vInputMax,
        const Vector *vOutputMin,
        const Vector *vOutputMax)
{
  _DWORD *v6; // eax
  CScratchPad3D::CBaseCommand *v7; // esi
  int m_nAllocationCount; // eax
  int m_Size; // ebx
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v11; // eax
  CScratchPad3D::CBaseCommand **v12; // ebx
  float v15; // xmm0_4
  float v16; // xmm6_4
  float y; // xmm0_4
  float v18; // xmm0_4
  float z; // xmm7_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float x; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float vDivisor_4; // [esp+Ch] [ebp-18h]
  CScratchPad3D::CBaseCommand_vtbl *vScale; // [esp+14h] [ebp-10h]
  CScratchPad3D::ICachedRenderData *vScale_4; // [esp+18h] [ebp-Ch]
  float vInputMina; // [esp+2Ch] [ebp+8h]
  float vInputMaxa; // [esp+30h] [ebp+Ch]

  v6 = operator new(nSize: 0x4Cu);
  v7 = nullptr;
  if ( v6 != nullptr )
  {
    v6[2] = 0;
    *((_BYTE *)v6 + 4) = 3;
    *v6 = &CScratchPad3D::CCommand_Matrix::`vftable';
    v7 = (CScratchPad3D::CBaseCommand *)v6;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CScratchPad3D::CBaseCommand *,int>::Grow(
      this: &this->m_Commands.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v11 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = v7;
  v15 = vInputMax->x - vInputMin->x;
  vInputMina = vInputMin->x;
  if ( fabs(v15) < 0.000099999997 )
    v15 = 0.001;
  v16 = v15;
  y = vInputMax->y;
  vInputMaxa = vInputMin->y;
  v18 = y - vInputMaxa;
  if ( fabs(v18) < 0.000099999997 )
    v18 = 0.001;
  z = vInputMin->z;
  vDivisor_4 = v18;
  v20 = vInputMax->z - z;
  if ( fabs(v20) < 0.000099999997 )
    v20 = 0.001;
  v21 = vOutputMax->z;
  x = vOutputMin->x;
  v23 = vOutputMin->y;
  v24 = vOutputMin->z;
  *(float *)&vScale = (float)(vOutputMax->x - vOutputMin->x) / v16;
  *(float *)&vScale_4 = (float)(vOutputMax->y - v23) / vDivisor_4;
  v7[1].__vftable = vScale;
  v25 = (float)(v21 - v24) / v20;
  *(_DWORD *)&v7[1].m_iCommand = 0;
  v7[1].m_pCachedRenderData = nullptr;
  *(_DWORD *)&v7[2].m_iCommand = 0;
  v7[3].__vftable = nullptr;
  v7[3].m_pCachedRenderData = nullptr;
  v7[4].__vftable = nullptr;
  v7[5].__vftable = nullptr;
  *(_DWORD *)&v7[5].m_iCommand = 0;
  v7[5].m_pCachedRenderData = nullptr;
  *(float *)&v7[2].__vftable = x + (float)((float)-vInputMina * *(float *)&vScale);
  v7[2].m_pCachedRenderData = vScale_4;
  *(float *)&v7[3].m_iCommand = v23 + (float)((float)-vInputMaxa * *(float *)&vScale_4);
  *(float *)&v7[4].m_iCommand = v25;
  *(float *)&v7[4].m_pCachedRenderData = v24 + (float)((float)-z * v25);
  v7[6].__vftable = (CScratchPad3D::CBaseCommand_vtbl *)1065353216;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403330
// Name: public: virtual void CScratchPad3D::DrawPoint(class CSPVert const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPoint(CScratchPad3D *this, const CSPVert *v, float flPointSize)
{
  _BYTE *v4; // eax
  _BYTE *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // edi

  v4 = operator new(nSize: 0x2Cu);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[4] = 0;
    *((_DWORD *)v4 + 2) = 0;
    *(_DWORD *)v4 = &CScratchPad3D::CCommand_Point::`vftable';
    *((_DWORD *)v4 + 10) = 1065353216;
    v5 = v4;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CScratchPad3D::CBaseCommand *,int>::Grow(
      this: &this->m_Commands.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = (CScratchPad3D::CBaseCommand *)v5;
  *(CSPVert *)(v5 + 16) = *v;
  *((float *)v5 + 3) = flPointSize;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403410
// Name: public: virtual void CScratchPad3D::DrawLine(class CSPVert const __near &,class CSPVert const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawLine(CScratchPad3D *this, const CSPVert *v1, const CSPVert *v2)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // ebx

  v4 = operator new(nSize: 0x44u);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[2] = 0;
    *((_BYTE *)v4 + 4) = 1;
    *v4 = &CScratchPad3D::CCommand_Line::`vftable';
    v4[9] = 1065353216;
    v4[16] = 1065353216;
    v5 = v4;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CScratchPad3D::CBaseCommand *,int>::Grow(
      this: &this->m_Commands.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = (CScratchPad3D::CBaseCommand *)v5;
  *(CSPVert *)(v5 + 3) = *v1;
  *(CSPVert *)(v5 + 10) = *v2;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403510
// Name: public: virtual void CScratchPad3D::DrawPolygon(class CSPVertList const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPolygon(CScratchPad3D *this, const CSPVertList *verts)
{
  CScratchPad3D::CCommand_Polygon *v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v7; // eax
  CScratchPad3D::CBaseCommand **v8; // eax
  CScratchPad3D::CCommand_Polygon *cmd; // [esp+Ch] [ebp-4h]

  v3 = (CScratchPad3D::CCommand_Polygon *)operator new(nSize: 0x20u);
  if ( v3 != nullptr )
  {
    v3->m_iCommand = 2;
    v3->m_pCachedRenderData = nullptr;
    v3->__vftable = (CScratchPad3D::CCommand_Polygon_vtbl *)&CScratchPad3D::CCommand_Polygon::`vftable';
    v3->m_Verts.m_Memory.m_pMemory = nullptr;
    v3->m_Verts.m_Memory.m_nAllocationCount = 0;
    v3->m_Verts.m_Memory.m_nGrowSize = 0;
    v3->m_Verts.m_Size = 0;
    v3->m_Verts.m_pElements = nullptr;
    cmd = v3;
  }
  else
  {
    cmd = nullptr;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CScratchPad3D::CBaseCommand *,int>::Grow(
      this: &this->m_Commands.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v7 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = cmd;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::AddVectorToTail(this: &cmd->m_Verts, src: &verts->m_Verts);
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x004035D0
// Name: public: virtual void CScratchPad3D::DrawRectYZ(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectYZ(
        CScratchPad3D *this,
        float xPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v17 = xPos;
  v14 = xPos;
  v11 = xPos;
  pVerts.x = xPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.y = vMin->x;
  v12 = pVerts.y;
  v13 = vMax->y;
  v16 = v13;
  v21 = *vColor;
  pVerts.z = y;
  v15 = x;
  v18 = x;
  v19 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::~CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>(this: (CUtlVector<CScratchPad3D::CBaseCommand *,CUtlMemory<CScratchPad3D::CBaseCommand *,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x00403680
// Name: public: virtual void CScratchPad3D::DrawRectXZ(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectXZ(
        CScratchPad3D *this,
        float yPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v18 = yPos;
  v15 = yPos;
  v12 = yPos;
  pVerts.y = yPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.x = vMin->x;
  v11 = pVerts.x;
  v13 = vMax->y;
  v16 = v13;
  v21 = *vColor;
  pVerts.z = y;
  v14 = x;
  v17 = x;
  v19 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::~CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>(this: (CUtlVector<CScratchPad3D::CBaseCommand *,CUtlMemory<CScratchPad3D::CBaseCommand *,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x00403730
// Name: public: virtual void CScratchPad3D::DrawRectXY(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectXY(
        CScratchPad3D *this,
        float zPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v19 = zPos;
  v16 = zPos;
  v13 = zPos;
  pVerts.z = zPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.x = vMin->x;
  v11 = pVerts.x;
  v12 = vMax->y;
  v15 = v12;
  v21 = *vColor;
  pVerts.y = y;
  v14 = x;
  v17 = x;
  v18 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::~CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>(this: (CUtlVector<CScratchPad3D::CBaseCommand *,CUtlMemory<CScratchPad3D::CBaseCommand *,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x004037E0
// Name: public: virtual void CScratchPad3D::SetRenderState(enum IScratchPad3D::RenderState,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetRenderState(
        CScratchPad3D *this,
        CScratchPad3D::CBaseCommand_vtbl *state,
        unsigned int val)
{
  _DWORD *v4; // eax
  CScratchPad3D::CBaseCommand *v5; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // eax

  v4 = operator new(nSize: 0x14u);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[2] = 0;
    *((_BYTE *)v4 + 4) = 4;
    *v4 = &CScratchPad3D::CCommand_RenderState::`vftable';
    v5 = (CScratchPad3D::CBaseCommand *)v4;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CScratchPad3D::CBaseCommand *,int>::Grow(
      this: &this->m_Commands.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v5;
  v5[1].__vftable = state;
  *(_DWORD *)&v5[1].m_iCommand = val;
}

//------------------------------------------------------------------------------
// Address: 0x00403880
// Name: public: void CScratchPad3D::DrawPolygonsForPixels(class SPRGBA __near *,int,int,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPolygonsForPixels(
        CScratchPad3D *this,
        SPRGBA *pData,
        int width,
        int height,
        unsigned int pitchInBytes,
        Vector *vCorners)
{
  float v6; // xmm2_4
  float v7; // xmm1_4
  float z; // edx
  float x; // xmm7_4
  float v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float y; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  int v23; // edx
  SPRGBA *v24; // esi
  unsigned int v25; // eax
  const CSPVertList *v26; // eax
  CSPVert *m_pMemory; // eax
  bool v28; // sf
  bool v29; // zf
  CSPColor v30; // [esp-1Ch] [ebp-D8h]
  unsigned int v31; // [esp+Ch] [ebp-B0h]
  float vLeftInc; // [esp+10h] [ebp-ACh]
  float vLeftInc_4; // [esp+14h] [ebp-A8h]
  float vLeftInc_8; // [esp+18h] [ebp-A4h]
  float vBottomXInc; // [esp+1Ch] [ebp-A0h]
  float vBottomXInc_4; // [esp+20h] [ebp-9Ch]
  float vBottomXInc_8; // [esp+24h] [ebp-98h]
  float vRightInc; // [esp+28h] [ebp-94h]
  float vRightInc_4; // [esp+2Ch] [ebp-90h]
  float vRightInc_8; // [esp+30h] [ebp-8Ch]
  SPRGBA *v41; // [esp+34h] [ebp-88h]
  int v42; // [esp+38h] [ebp-84h]
  float vNextLeft; // [esp+3Ch] [ebp-80h]
  float vNextLeft_4; // [esp+40h] [ebp-7Ch]
  float vNextLeft_8; // [esp+44h] [ebp-78h]
  float vTopXInc; // [esp+48h] [ebp-74h]
  float vTopXInc_4; // [esp+4Ch] [ebp-70h]
  float vTopXInc_8; // [esp+50h] [ebp-6Ch]
  Vector vPolyBox[4]; // [esp+54h] [ebp-68h] BYREF
  CSPVertList v50; // [esp+84h] [ebp-38h] BYREF
  Vector vNextRight; // [esp+98h] [ebp-24h]
  Vector vCurRight; // [esp+A4h] [ebp-18h]
  Vector vCurLeft; // [esp+B0h] [ebp-Ch]
  int pitchInBytesa; // [esp+D0h] [ebp+14h]
  float vCornersa; // [esp+D4h] [ebp+18h]

  v6 = vCorners->x - vCorners[1].x;
  v7 = vCorners->z - vCorners[1].z;
  z = vCorners[2].z;
  *(_QWORD *)&vCurLeft.x = *(_QWORD *)&vCorners[1].x;
  x = vCurLeft.x;
  v11 = vCorners[1].z;
  *(_QWORD *)&vCurRight.x = *(_QWORD *)&vCorners[2].x;
  v12 = vCorners->y - vCorners[1].y;
  vCurLeft.z = v11;
  v13 = 1.0 / (float)height;
  v14 = v12 * v13;
  v15 = v13 * v6;
  vLeftInc_8 = v7 * v13;
  v16 = (float)(vCorners[3].z - vCorners[2].z) * v13;
  vRightInc_4 = (float)(vCorners[3].y - vCorners[2].y) * v13;
  v17 = v11;
  y = vCurLeft.y;
  v19 = vCurRight.x + (float)((float)(1.0 / (float)height) * (float)(vCorners[3].x - vCorners[2].x));
  vRightInc = (float)(1.0 / (float)height) * (float)(vCorners[3].x - vCorners[2].x);
  vRightInc_8 = v16;
  vLeftInc = v15;
  v20 = vCurLeft.x + v15;
  vLeftInc_4 = v14;
  v21 = vCurLeft.y + v14;
  vNextRight.y = vCurRight.y + vRightInc_4;
  vCurRight.z = z;
  v22 = v11 + vLeftInc_8;
  vNextLeft = v20;
  vNextLeft_4 = v21;
  vNextLeft_8 = v11 + vLeftInc_8;
  vNextRight.x = v19;
  vNextRight.z = z + vRightInc_8;
  if ( height > 0 )
  {
    v23 = width;
    v24 = pData;
    v25 = 4 * (pitchInBytes >> 2);
    vCornersa = 1.0 / (float)width;
    v31 = v25;
    v41 = pData;
    v42 = height;
    while ( 1 )
    {
      vPolyBox[0].y = y;
      vPolyBox[0].z = v17;
      vTopXInc_4 = (float)(vCurRight.y - y) * vCornersa;
      vBottomXInc_4 = (float)(vNextRight.y - v21) * vCornersa;
      vTopXInc_8 = (float)(vCurRight.z - v17) * vCornersa;
      vTopXInc = vCornersa * (float)(vCurRight.x - x);
      vPolyBox[1].x = vTopXInc + x;
      vPolyBox[1].y = vTopXInc_4 + vCurLeft.y;
      vPolyBox[1].z = vTopXInc_8 + vCurLeft.z;
      vBottomXInc = vCornersa * (float)(vNextRight.x - v20);
      vPolyBox[0].x = x;
      vPolyBox[3].x = v20;
      vPolyBox[3].y = v21;
      vPolyBox[3].z = v22;
      vBottomXInc_8 = (float)(vNextRight.z - v22) * vCornersa;
      vPolyBox[2].x = vBottomXInc + v20;
      vPolyBox[2].y = vBottomXInc_4 + v21;
      vPolyBox[2].z = vBottomXInc_8 + v22;
      if ( v23 > 0 )
      {
        pitchInBytesa = v23;
        do
        {
          if ( pData != nullptr )
          {
            v30.m_vColor.x = (float)v24->r * 0.0039200312;
            v30.m_vColor.y = (float)v24->g * 0.0039200312;
            v30.m_vColor.z = (float)v24->b * 0.0039200312;
          }
          else
          {
            *(_QWORD *)&v30.m_vColor.x = 0x3F8000003F800000LL;
            v30.m_vColor.z = 1.0;
          }
          v30.m_flAlpha = 1.0;
          v26 = CSPVertList::CSPVertList(this: &v50, pVerts: vPolyBox, nVerts: 4, vColor: v30);
          this->DrawPolygon(this, a2: v26);
          m_pMemory = v50.m_Verts.m_Memory.m_pMemory;
          v50.m_Verts.m_Size = 0;
          v28 = v50.m_Verts.m_Memory.m_nGrowSize < 0;
          if ( v50.m_Verts.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v50.m_Verts.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)v50.m_Verts.m_Memory.m_pMemory);
              m_pMemory = nullptr;
              v50.m_Verts.m_Memory.m_pMemory = nullptr;
            }
            v28 = v50.m_Verts.m_Memory.m_nGrowSize < 0;
            v50.m_Verts.m_Memory.m_nAllocationCount = 0;
          }
          v50.m_Verts.m_pElements = m_pMemory;
          if ( !v28 && m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)m_pMemory);
          vPolyBox[0].z = vPolyBox[0].z + vTopXInc_8;
          vPolyBox[1].y = vPolyBox[1].y + vTopXInc_4;
          vPolyBox[0].x = vPolyBox[0].x + vTopXInc;
          vPolyBox[1].x = vPolyBox[1].x + vTopXInc;
          vPolyBox[1].z = vPolyBox[1].z + vTopXInc_8;
          vPolyBox[3].x = vPolyBox[3].x + vBottomXInc;
          vPolyBox[0].y = vPolyBox[0].y + vTopXInc_4;
          vPolyBox[3].z = vPolyBox[3].z + vBottomXInc_8;
          vPolyBox[2].y = vPolyBox[2].y + vBottomXInc_4;
          ++v24;
          v29 = pitchInBytesa-- == 1;
          vPolyBox[3].y = vPolyBox[3].y + vBottomXInc_4;
          vPolyBox[2].x = vPolyBox[2].x + vBottomXInc;
          vPolyBox[2].z = vPolyBox[2].z + vBottomXInc_8;
        }
        while ( !v29 );
        x = vCurLeft.x;
        v20 = vNextLeft;
        v21 = vNextLeft_4;
        v22 = vNextLeft_8;
        v25 = v31;
        v23 = width;
      }
      x = x + vLeftInc;
      v20 = v20 + vLeftInc;
      v21 = v21 + vLeftInc_4;
      v22 = v22 + vLeftInc_8;
      vCurLeft.z = vCurLeft.z + vLeftInc_8;
      vCurRight.x = vCurRight.x + vRightInc;
      vCurLeft.y = vCurLeft.y + vLeftInc_4;
      vCurRight.z = vCurRight.z + vRightInc_8;
      vNextRight.y = vNextRight.y + vRightInc_4;
      v24 = (SPRGBA *)((char *)v41 + v25);
      v29 = v42-- == 1;
      vCurLeft.x = x;
      vNextLeft = v20;
      vNextLeft_4 = v21;
      vNextLeft_8 = v22;
      vCurRight.y = vCurRight.y + vRightInc_4;
      vNextRight.x = vNextRight.x + vRightInc;
      vNextRight.z = vNextRight.z + vRightInc_8;
      v41 = (SPRGBA *)((char *)v41 + v25);
      if ( v29 )
        break;
      v17 = vCurLeft.z;
      y = vCurLeft.y;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403DE0
// Name: public: virtual void CScratchPad3D::DrawImageRGBA(class SPRGBA __near *,int,int,int,bool,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawImageRGBA(
        CScratchPad3D *this,
        SPRGBA *pData,
        int width,
        int height,
        unsigned int pitchInBytes,
        bool bOutlinePixels,
        bool bOutlineImage,
        Vector *vCorners)
{
  Vector *v8; // edi
  void (__thiscall *SetRenderState)(struct CScratchPad3D *, IScratchPad3D::RenderState, unsigned int); // eax
  CScratchPad3D_vtbl *v11; // ebx
  CSPVertList *v12; // eax
  CSPColor v13; // [esp-10h] [ebp-60h]
  Vector vDefaultCorners[4]; // [esp+Ch] [ebp-44h] BYREF
  CSPVertList v15; // [esp+3Ch] [ebp-14h] BYREF
  bool bOldAutoFlush_3; // [esp+73h] [ebp+23h]

  v8 = vCorners;
  if ( vCorners == nullptr )
  {
    v8 = vDefaultCorners;
    vDefaultCorners[0].x = -100.0;
    vDefaultCorners[0].y = -100.0;
    vDefaultCorners[0].z = 0.0;
    vDefaultCorners[1].x = -100.0;
    vDefaultCorners[1].y = 100.0;
    vDefaultCorners[1].z = 0.0;
    vDefaultCorners[2].x = 100.0;
    vDefaultCorners[2].y = 100.0;
    vDefaultCorners[2].z = 0.0;
    vDefaultCorners[3].x = 100.0;
    vDefaultCorners[3].y = -100.0;
    vDefaultCorners[3].z = 0.0;
  }
  bOldAutoFlush_3 = this->m_bAutoFlush;
  SetRenderState = this->SetRenderState;
  this->m_bAutoFlush = false;
  ((void (__stdcall *)(_DWORD, int))SetRenderState)(a1: 0, a2: 1);
  CScratchPad3D::DrawPolygonsForPixels(this, pData, width, height, pitchInBytes, vCorners: v8);
  if ( bOutlinePixels )
  {
    this->SetRenderState(this, a2: RS_FillMode, a3: 0);
    CScratchPad3D::DrawPolygonsForPixels(this, pData: nullptr, width, height, pitchInBytes, vCorners: v8);
  }
  if ( bOutlineImage )
  {
    this->SetRenderState(this, a2: RS_FillMode, a3: 0);
    v11 = this->__vftable;
    *(_QWORD *)&v15.m_Verts.m_Memory.m_nAllocationCount = 0x3F8000003F800000LL;
    *(_QWORD *)&v15.m_Verts.m_Size = 0x3F8000003F800000LL;
    *(_QWORD *)&v13.m_vColor.x = 0x3F8000003F800000LL;
    *(_QWORD *)&v13.m_vColor.z = 0x3F8000003F800000LL;
    v12 = CSPVertList::CSPVertList(this: &v15, pVerts: v8, nVerts: 4, vColor: v13);
    v11->DrawPolygon(this, a2: v12);
    CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::~CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>(this: (CUtlVector<CScratchPad3D::CBaseCommand *,CUtlMemory<CScratchPad3D::CBaseCommand *,int> > *)&v15);
  }
  this->m_bAutoFlush = bOldAutoFlush_3;
  if ( bOldAutoFlush_3 )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x00403F90
// Name: public: virtual void CScratchPad3D::CCommand_Text::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Text::Read(CScratchPad3D::CCommand_Text *this, CFileRead *pFile)
{
  CFileRead *v2; // esi
  CFileRead *v4; // eax
  int v5; // ebx
  int m_nAllocationCount; // ecx
  char *m_pMemory; // edx
  int v8; // ecx

  v2 = pFile;
  v2->m_Pos += pFile->m_pFileSystem->Read(
                 this: &pFile->m_pFileSystem->IBaseFileSystem,
                 a2: &pFile,
                 a3: 4,
                 a4: pFile->m_fp);
  v4 = pFile;
  v5 = (int)pFile;
  this->m_String.m_Size = 0;
  if ( v5 != 0 )
  {
    m_nAllocationCount = this->m_String.m_Memory.m_nAllocationCount;
    if ( (int)v4 > m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(this: &this->m_String.m_Memory, num: (int)v4 - m_nAllocationCount);
      v4 = pFile;
    }
    this->m_String.m_Size += v5;
    m_pMemory = this->m_String.m_Memory.m_pMemory;
    v8 = this->m_String.m_Size - v5;
    this->m_String.m_pElements = m_pMemory;
    if ( v8 > 0 && v5 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: v8);
      v4 = pFile;
    }
  }
  v2->m_Pos += v2->m_pFileSystem->Read(
                 this: &v2->m_pFileSystem->IBaseFileSystem,
                 a2: this->m_String.m_Memory.m_pMemory,
                 a3: (int)v4,
                 a4: v2->m_fp);
  v2->m_Pos += v2->m_pFileSystem->Read(
                 this: &v2->m_pFileSystem->IBaseFileSystem,
                 a2: (void *)&this->m_TextParams,
                 a3: 56,
                 a4: v2->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x00404040
// Name: public: virtual void CScratchPad3D::DrawText(char const __near *,class CTextParams const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawText(CScratchPad3D *this, const char *pStr, const CTextParams *params)
{
  CScratchPad3D::CCommand_Text *v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v8; // eax
  CScratchPad3D::CBaseCommand **v9; // eax
  CScratchPad3D::CCommand_Text *cmd; // [esp+10h] [ebp-4h]

  v4 = (CScratchPad3D::CCommand_Text *)operator new(nSize: 0x58u);
  if ( v4 != nullptr )
  {
    v4->m_iCommand = 5;
    v4->m_pCachedRenderData = nullptr;
    v4->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_Text::`vftable';
    v4->m_String.m_Memory.m_pMemory = nullptr;
    v4->m_String.m_Memory.m_nAllocationCount = 0;
    v4->m_String.m_Memory.m_nGrowSize = 0;
    v4->m_String.m_Size = 0;
    v4->m_String.m_pElements = nullptr;
    v4->m_TextParams.m_vColor.x = 1.0;
    v4->m_TextParams.m_vColor.y = 1.0;
    v4->m_TextParams.m_vColor.z = 1.0;
    v4->m_TextParams.m_flAlpha = 1.0;
    *(_WORD *)&v4->m_TextParams.m_bSolidBackground = 257;
    v4->m_TextParams.m_vPos.x = 0.0;
    v4->m_TextParams.m_vPos.y = 0.0;
    v4->m_TextParams.m_vPos.z = 0.0;
    v4->m_TextParams.m_bCentered = true;
    v4->m_TextParams.m_vAngles.x = 0.0;
    v4->m_TextParams.m_vAngles.y = 0.0;
    v4->m_TextParams.m_vAngles.z = 0.0;
    v4->m_TextParams.m_bTwoSided = true;
    v4->m_TextParams.m_flLetterWidth = 3.0;
    cmd = v4;
  }
  else
  {
    cmd = nullptr;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CScratchPad3D::CBaseCommand *,int>::Grow(
      this: &this->m_Commands.m_Memory,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v8 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = cmd;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &cmd->m_String, pArray: pStr, size: strlen(pStr) + 1);
  CTextParams::operator=(this: &cmd->m_TextParams, __that: params);
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x004046D0
// Name: public: void CUtlMemory<char,int>::Grow(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CUtlMemory<char,int>::Grow(CUtlMemory<char,int> *this, int num)
{
  int m_nGrowSize; // esi
  int m_nAllocationCount; // eax
  int v5; // ecx
  char *m_pMemory; // edx

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
        m_nAllocationCount = 32;
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
      this->m_pMemory = (char *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: m_pMemory, a3: m_nAllocationCount);
    else
      this->m_pMemory = (char *)_g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: m_nAllocationCount);
  }
}

// ============================================================
// Overlay from vbspinfo (Missing functions)
// ============================================================
namespace vbspinfo {

//------------------------------------------------------------------------------
// Address: 0x0040A6C0
// Name: public: virtual void CScratchPad3D::CCommand_Point::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Point::Read(CScratchPad3D::CCommand_Point *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_flPointSize,
                    a3: 4,
                    a4: pFile->m_fp);
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_Vert,
                    a3: 28,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040A710
// Name: public: virtual void CScratchPad3D::CCommand_Point::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Point::Write(
        CScratchPad3D::CCommand_Point *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_flPointSize, a3: 4, a4: fp);
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_Vert, a3: 28, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040A750
// Name: public: virtual void CScratchPad3D::CCommand_Line::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Line::Read(CScratchPad3D::CCommand_Line *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: this->m_Verts,
                    a3: 56,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040A780
// Name: public: virtual void CScratchPad3D::CCommand_Line::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Line::Write(
        CScratchPad3D::CCommand_Line *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: this->m_Verts, a3: 56, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040A7B0
// Name: public: virtual void CScratchPad3D::CCommand_Matrix::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Matrix::Read(CScratchPad3D::CCommand_Matrix *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_mMatrix,
                    a3: 64,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040A7E0
// Name: public: virtual void CScratchPad3D::CCommand_Matrix::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Matrix::Write(
        CScratchPad3D::CCommand_Matrix *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_mMatrix, a3: 64, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040A810
// Name: public: virtual void CScratchPad3D::CCommand_RenderState::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_RenderState::Read(CScratchPad3D::CCommand_RenderState *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_State,
                    a3: 4,
                    a4: pFile->m_fp);
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_Val,
                    a3: 4,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040A860
// Name: public: virtual void CScratchPad3D::CCommand_RenderState::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_RenderState::Write(
        CScratchPad3D::CCommand_RenderState *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_State, a3: 4, a4: fp);
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_Val, a3: 4, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040A8A0
// Name: public: virtual void CScratchPad3D::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Release(CScratchPad3D *this)
{
  this->Flush(this);
  ((void (__thiscall *)(CScratchPad3D *, int))this->dtr_IScratchPad3D)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x0040A8C0
// Name: public: virtual bool CScratchPad3D::GetAutoFlush(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScratchPad3D::GetAutoFlush(CScratchPad3D *this)
{
  return this->m_bAutoFlush;
}

//------------------------------------------------------------------------------
// Address: 0x0040A8D0
// Name: public: virtual void CScratchPad3D::SetAutoFlush(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetAutoFlush(CScratchPad3D *this, bool bAutoFlush)
{
  this->m_bAutoFlush = bAutoFlush;
  if ( bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040A8F0
// Name: public: class CTextParams __near & CTextParams::operator=(class CTextParams const __near &)
// Source: json
//------------------------------------------------------------------------------
CTextParams *__thiscall CTextParams::operator=(CTextParams *this, const CTextParams *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040A960
// Name: public: virtual void CScratchPad3D::DrawImageBW(unsigned char const __near *,int,int,int,bool,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawImageBW(
        CScratchPad3D *this,
        const unsigned __int8 *pData,
        int width,
        int height,
        int pitchInBytes,
        BOOL bOutlinePixels,
        BOOL bOutlineImage,
        Vector *vCorners)
{
  int v8; // esi
  CScratchPad3D *v10; // ebx
  SPRGBA *v11; // eax
  const unsigned __int8 *v12; // edx
  SPRGBA *v13; // ebx
  SPRGBA *v14; // eax
  int i; // esi
  unsigned __int8 v16; // cl
  bool v17; // zf
  SPRGBA *pRGBA; // [esp+10h] [ebp-4h]
  const unsigned __int8 *pDataa; // [esp+1Ch] [ebp+8h]
  const unsigned __int8 *widtha; // [esp+20h] [ebp+Ch]

  v8 = height;
  v10 = this;
  v11 = (SPRGBA *)operator new(size: 4 * height * width);
  pRGBA = v11;
  if ( height > 0 )
  {
    v12 = pData;
    widtha = pData;
    v13 = v11;
    pDataa = (const unsigned __int8 *)height;
    do
    {
      v14 = v13;
      if ( width > 0 )
      {
        for ( i = width; i != 0; --i )
        {
          v16 = *v12;
          v14->b = *v12;
          v14->g = v16;
          v14->r = v16;
          ++v12;
          ++v14;
        }
        v8 = height;
        v12 = widtha;
      }
      v12 += pitchInBytes;
      v13 += width;
      v17 = pDataa-- == (const unsigned __int8 *)1;
      widtha = v12;
    }
    while ( !v17 );
    v10 = this;
    v11 = pRGBA;
  }
  v10->DrawImageRGBA(
    this: v10,
    a2: v11,
    a3: width,
    a4: v8,
    a5: 4 * width,
    a6: bOutlinePixels,
    a7: bOutlineImage,
    a8: vCorners);
  operator delete(p: pRGBA);
}

//------------------------------------------------------------------------------
// Address: 0x0040AA90
// Name: public: virtual void CScratchPad3D::CCommand_Polygon::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Polygon::Write(
        CScratchPad3D::CCommand_Polygon *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  int (__thiscall *Write)(IBaseFileSystem *, const void *, int, void *); // edx
  int count; // [esp+Ch] [ebp-4h] BYREF

  Write = pFileSystem->Write;
  count = this->m_Verts.m_Size;
  Write(this: &pFileSystem->IBaseFileSystem, a2: &count, a3: 4, a4: fp);
  if ( count != 0 )
    pFileSystem->Write(
      this: &pFileSystem->IBaseFileSystem,
      a2: this->m_Verts.m_Memory.m_pMemory,
      a3: 28 * count,
      a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040AAF0
// Name: public: virtual void CScratchPad3D::CCommand_Text::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Text::Write(
        CScratchPad3D::CCommand_Text *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  int (__thiscall *Write)(IBaseFileSystem *, const void *, int, void *); // edx
  IBaseFileSystem *v5; // esi
  int strLen; // [esp+Ch] [ebp-4h] BYREF

  Write = pFileSystem->Write;
  v5 = &pFileSystem->IBaseFileSystem;
  strLen = this->m_String.m_Size;
  Write(this: &pFileSystem->IBaseFileSystem, a2: &strLen, a3: 4, a4: fp);
  v5->Write(this: v5, a2: this->m_String.m_Memory.m_pMemory, a3: strLen, a4: fp);
  v5->Write(this: v5, a2: &this->m_TextParams, a3: 56, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040AB50
// Name: public: virtual void CScratchPad3D::DrawWireframeBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawWireframeBox(
        CScratchPad3D *this,
        const Vector *vMin,
        const Vector *vMax,
        const Vector *vColor)
{
  float y; // xmm3_4
  float z; // xmm4_4
  float x; // xmm0_4
  float v7; // xmm1_4
  float v9; // xmm2_4
  void (__thiscall *DrawLine)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  void (__thiscall *v15)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  void (__thiscall *v22)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  void (__thiscall *v27)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  void (__thiscall *v34)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v35; // xmm3_4
  float v36; // xmm4_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  void (__thiscall *v39)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  void (__thiscall *v45)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  float v49; // xmm4_4
  float v50; // xmm1_4
  void (__thiscall *v51)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v52; // xmm2_4
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  void (__thiscall *v58)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v59; // xmm3_4
  float v60; // xmm4_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  void (__thiscall *v63)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v64; // xmm2_4
  float v65; // xmm3_4
  float v66; // xmm4_4
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm2_4
  void (__thiscall *v71)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v72; // xmm3_4
  float v73; // xmm4_4
  float v74; // xmm0_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  void (__thiscall *v77)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v78; // [esp+0h] [ebp-54h] BYREF
  float v79; // [esp+4h] [ebp-50h]
  float v80; // [esp+8h] [ebp-4Ch]
  float v81; // [esp+Ch] [ebp-48h]
  float v82; // [esp+10h] [ebp-44h]
  float v83; // [esp+14h] [ebp-40h]
  int v84; // [esp+18h] [ebp-3Ch]
  float v85; // [esp+1Ch] [ebp-38h] BYREF
  float v86; // [esp+20h] [ebp-34h]
  float v87; // [esp+24h] [ebp-30h]
  float v88; // [esp+28h] [ebp-2Ch]
  float v89; // [esp+2Ch] [ebp-28h]
  float v90; // [esp+30h] [ebp-24h]
  int v91; // [esp+34h] [ebp-20h]
  _DWORD v92[5]; // [esp+38h] [ebp-1Ch] BYREF
  float v93; // [esp+4Ch] [ebp-8h]
  float v94; // [esp+50h] [ebp-4h]

  y = vMin->y;
  z = vMin->z;
  x = vColor->x;
  v7 = vColor->y;
  v93 = vColor->z;
  v85 = vMax->x;
  v86 = y;
  v87 = z;
  v9 = vMin->x;
  DrawLine = this->DrawLine;
  v88 = x;
  v81 = x;
  v89 = v7;
  v90 = v93;
  v91 = 1065353216;
  v78 = v9;
  v79 = y;
  v80 = z;
  v82 = v7;
  v83 = v93;
  v84 = 1065353216;
  DrawLine(this, a2: (const CSPVert *)&v78, a3: (const CSPVert *)&v85);
  v11 = vMin->x;
  v12 = vMin->z;
  v13 = vColor->x;
  v14 = vColor->y;
  v15 = this->DrawLine;
  v93 = vColor->z;
  v78 = v11;
  v79 = vMax->y;
  v80 = v12;
  v16 = vMin->y;
  v81 = v13;
  v88 = v13;
  v82 = v14;
  v83 = v93;
  v84 = 1065353216;
  v85 = v11;
  v86 = v16;
  v87 = v12;
  v89 = v14;
  v90 = v93;
  v91 = 1065353216;
  v15(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v17 = vMax->x;
  v18 = vMin->z;
  v19 = vColor->x;
  v20 = vColor->y;
  v93 = vColor->z;
  v78 = v17;
  v79 = vMax->y;
  v80 = v18;
  v21 = vMin->y;
  v22 = this->DrawLine;
  v81 = v19;
  v88 = v19;
  v82 = v20;
  v83 = v93;
  v84 = 1065353216;
  v85 = v17;
  v86 = v21;
  v87 = v18;
  v89 = v20;
  v90 = v93;
  v91 = 1065353216;
  v22(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v23 = vMin->z;
  v24 = vMax->y;
  v25 = vColor->x;
  v26 = vColor->y;
  v27 = this->DrawLine;
  v93 = vColor->z;
  v78 = vMin->x;
  v79 = v24;
  v80 = v23;
  v28 = vMax->x;
  v81 = v25;
  v88 = v25;
  v82 = v26;
  v83 = v93;
  v84 = 1065353216;
  v85 = v28;
  v86 = v24;
  v87 = v23;
  v89 = v26;
  v90 = v93;
  v91 = 1065353216;
  v27(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v29 = vColor->x;
  v30 = vColor->y;
  v31 = vMin->y;
  v32 = vMax->z;
  v93 = vColor->z;
  v78 = vMax->x;
  v79 = v31;
  v80 = v32;
  v33 = vMin->x;
  v34 = this->DrawLine;
  v81 = v29;
  v88 = v29;
  v82 = v30;
  v83 = v93;
  v84 = 1065353216;
  v85 = v33;
  v86 = v31;
  v87 = v32;
  v89 = v30;
  v90 = v93;
  v91 = 1065353216;
  v34(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v35 = vMin->x;
  v36 = vMax->z;
  v37 = vColor->x;
  v38 = vColor->y;
  v39 = this->DrawLine;
  v93 = vColor->z;
  v78 = v35;
  v79 = vMax->y;
  v80 = v36;
  v40 = vMin->y;
  v81 = v37;
  v88 = v37;
  v82 = v38;
  v83 = v93;
  v84 = 1065353216;
  v85 = v35;
  v86 = v40;
  v87 = v36;
  v89 = v38;
  v90 = v93;
  v91 = 1065353216;
  v39(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v41 = vMax->x;
  v42 = vMax->z;
  v43 = vColor->x;
  v44 = vColor->y;
  v93 = vColor->z;
  v45 = this->DrawLine;
  v78 = v41;
  v79 = vMax->y;
  v80 = v42;
  v46 = vMin->y;
  v81 = v43;
  v88 = v43;
  v82 = v44;
  v83 = v93;
  v84 = 1065353216;
  v85 = v41;
  v86 = v46;
  v87 = v42;
  v89 = v44;
  v90 = v93;
  v91 = 1065353216;
  v45(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v47 = vMax->y;
  v48 = vColor->x;
  v49 = vMax->z;
  v50 = vColor->y;
  v51 = this->DrawLine;
  v93 = vColor->z;
  v78 = vMin->x;
  v79 = v47;
  v80 = v49;
  v52 = vMax->x;
  v81 = v48;
  v88 = v48;
  v82 = v50;
  v83 = v93;
  v84 = 1065353216;
  v85 = v52;
  v86 = v47;
  v87 = v49;
  v89 = v50;
  v90 = v93;
  v91 = 1065353216;
  v51(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v53 = vMin->x;
  v54 = vMin->y;
  v55 = vColor->x;
  v56 = vColor->y;
  v93 = vColor->z;
  v78 = v53;
  v79 = v54;
  v80 = vMax->z;
  v57 = vMin->z;
  v58 = this->DrawLine;
  v81 = v55;
  v88 = v55;
  v82 = v56;
  v83 = v93;
  v84 = 1065353216;
  v85 = v53;
  v86 = v54;
  v87 = v57;
  v89 = v56;
  v90 = v93;
  v91 = 1065353216;
  v58(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v59 = vMin->x;
  v60 = vMax->y;
  v61 = vColor->x;
  v62 = vColor->y;
  v63 = this->DrawLine;
  v93 = vColor->z;
  v78 = v59;
  v79 = v60;
  v80 = vMax->z;
  v64 = vMin->z;
  v81 = v61;
  v88 = v61;
  v82 = v62;
  v83 = v93;
  v84 = 1065353216;
  v85 = v59;
  v86 = v60;
  v87 = v64;
  v89 = v62;
  v90 = v93;
  v91 = 1065353216;
  v63(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v65 = vMax->x;
  v66 = vMax->y;
  v67 = vColor->x;
  v68 = vColor->y;
  v93 = vColor->z;
  v78 = v65;
  v79 = v66;
  v69 = vMax->z;
  v81 = v67;
  v80 = v69;
  v82 = v68;
  v83 = v93;
  v70 = vMin->z;
  v71 = this->DrawLine;
  v88 = v67;
  v84 = 1065353216;
  v85 = v65;
  v86 = v66;
  v87 = v70;
  v89 = v68;
  v90 = v93;
  v91 = 1065353216;
  v71(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v72 = vMax->x;
  v73 = vMin->y;
  v74 = vColor->x;
  v75 = vColor->y;
  v90 = vColor->z;
  v94 = vMax->z;
  v78 = v72;
  v79 = v73;
  v80 = v94;
  v76 = vMin->z;
  v77 = this->DrawLine;
  v81 = v74;
  *(float *)&v92[3] = v74;
  v82 = v75;
  v83 = v90;
  v84 = 1065353216;
  *(float *)v92 = v72;
  *(float *)&v92[1] = v73;
  *(float *)&v92[2] = v76;
  *(float *)&v92[4] = v75;
  v93 = v90;
  v94 = 1.0;
  v77(this, a2: (const CSPVert *)v92, a3: (const CSPVert *)&v78);
}

//------------------------------------------------------------------------------
// Address: 0x0040B2B0
// Name: public: void CScratchPad3D::DeleteCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DeleteCommands(CScratchPad3D *this)
{
  int v2; // ebx
  CScratchPad3D::CBaseCommand *v3; // esi
  CScratchPad3D::ICachedRenderData *m_pCachedRenderData; // ecx

  v2 = 0;
  if ( this->m_Commands.m_Size <= 0 )
  {
    this->m_Commands.m_Size = 0;
  }
  else
  {
    do
    {
      v3 = this->m_Commands.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        m_pCachedRenderData = v3->m_pCachedRenderData;
        v3->__vftable = (CScratchPad3D::CBaseCommand_vtbl *)&CScratchPad3D::CBaseCommand::`vftable';
        if ( m_pCachedRenderData != nullptr )
        {
          m_pCachedRenderData->Release(this: m_pCachedRenderData);
          v3->m_pCachedRenderData = nullptr;
        }
        operator delete(p: v3);
      }
      ++v2;
    }
    while ( v2 < this->m_Commands.m_Size );
    this->m_Commands.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040B310
// Name: public: virtual void CScratchPad3D::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Clear(CScratchPad3D *this)
{
  void *i; // eax

  for ( i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "wb",
              a4: 0);
        i == nullptr;
        i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "wb",
              a4: 0) )
  {
    Sleep(dwMilliseconds: 5u);
  }
  this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: i);
  CScratchPad3D::DeleteCommands(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040B370
// Name: public: virtual void CScratchPad3D::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Flush(CScratchPad3D *this)
{
  void *i; // edi
  int j; // ebx
  CScratchPad3D::CBaseCommand *v4; // ecx

  for ( i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "ab+",
              a4: 0);
        i == nullptr;
        i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "ab+",
              a4: 0) )
  {
    Sleep(dwMilliseconds: 5u);
  }
  for ( j = 0; j < this->m_Commands.m_Size; ++j )
  {
    this->m_pFileSystem->Write(
      this: &this->m_pFileSystem->IBaseFileSystem,
      a2: &this->m_Commands.m_Memory.m_pMemory[j]->m_iCommand,
      a3: 1,
      a4: i);
    v4 = this->m_Commands.m_Memory.m_pMemory[j];
    v4->Write(this: v4, a2: this->m_pFileSystem, a3: i);
  }
  this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: i);
  CScratchPad3D::DeleteCommands(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040B5D0
// Name: class IScratchPad3D __near * ScratchPad3D_Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScratchPad3D *__cdecl ScratchPad3D_Create(const char *pFilename)
{
  struct CSysModule *Module; // eax
  struct CSysModule *v2; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  int v4; // ebx
  CScratchPad3D *v6; // esi

  Module = Sys_LoadModule(pModuleName: "filesystem_stdio");
  v2 = Module;
  if ( Module == nullptr )
    return nullptr;
  Factory = Sys_GetFactory(pModule: Module);
  if ( Factory == nullptr || (v4 = (int)Factory(a1: "VFileSystem017", a2: nullptr)) == 0 )
  {
    Sys_UnloadModule(pModule: v2);
    return nullptr;
  }
  v6 = (CScratchPad3D *)operator new(size: 0x24u);
  if ( v6 == nullptr )
    return nullptr;
  v6->__vftable = (CScratchPad3D_vtbl *)&CScratchPad3D::`vftable';
  v6->m_Commands.m_Memory.m_pMemory = nullptr;
  v6->m_Commands.m_Memory.m_nAllocationCount = 0;
  v6->m_Commands.m_Memory.m_nGrowSize = 0;
  v6->m_Commands.m_Size = 0;
  v6->m_Commands.m_pElements = nullptr;
  v6->m_pFileSystem = (IFileSystem *)v4;
  v6->m_pFilename = pFilename;
  v6->m_bAutoFlush = true;
  CScratchPad3D::Clear(this: v6);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x0040B660
// Name: public: CSPVertList::CSPVertList(class Vector const __near *,int,class CSPColor)
// Source: json
//------------------------------------------------------------------------------
CSPVertList *__thiscall CSPVertList::CSPVertList(CSPVertList *this, const Vector *pVerts, int nVerts, CSPColor vColor)
{
  int v4; // ebx
  signed int v6; // eax
  int v7; // ecx
  float *p_z; // eax
  unsigned int v9; // ebx
  CSPVert *m_pMemory; // edx
  CSPVert *v11; // edx
  int v12; // edx
  CSPVert *v13; // edx
  int v14; // edx
  CSPVert *v15; // edx
  unsigned int v16; // ecx
  float *v17; // edx
  int v18; // ebx
  CSPVert *v19; // eax
  int i; // [esp+Ch] [ebp-4h]

  v4 = nVerts;
  this->m_Verts.m_Memory.m_pMemory = nullptr;
  this->m_Verts.m_Memory.m_nAllocationCount = 0;
  this->m_Verts.m_Memory.m_nGrowSize = 0;
  this->m_Verts.m_Size = 0;
  this->m_Verts.m_pElements = nullptr;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(this: &this->m_Verts, elem: 0, num: nVerts);
  v6 = 0;
  if ( nVerts >= 4 )
  {
    v7 = 0;
    p_z = &pVerts[1].z;
    v9 = ((unsigned int)(nVerts - 4) >> 2) + 1;
    i = 4 * v9;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pMemory[v7].m_vPos.x = *(p_z - 5);
      p_z += 12;
      m_pMemory[v7].m_vPos.y = *(p_z - 16);
      m_pMemory[v7].m_vPos.z = *(p_z - 15);
      this->m_Verts.m_Memory.m_pMemory[v7].m_vColor = vColor;
      v11 = this->m_Verts.m_Memory.m_pMemory;
      v11[v7 + 1].m_vPos.x = *(p_z - 14);
      v12 = (int)&v11[v7 + 1];
      *(float *)(v12 + 4) = *(p_z - 13);
      *(float *)(v12 + 8) = *(p_z - 12);
      this->m_Verts.m_Memory.m_pMemory[v7 + 1].m_vColor = vColor;
      v13 = this->m_Verts.m_Memory.m_pMemory;
      v13[v7 + 2].m_vPos.x = *(p_z - 11);
      v14 = (int)&v13[v7 + 2];
      *(float *)(v14 + 4) = *(p_z - 10);
      *(float *)(v14 + 8) = *(p_z - 9);
      this->m_Verts.m_Memory.m_pMemory[v7 + 2].m_vColor = vColor;
      v15 = this->m_Verts.m_Memory.m_pMemory;
      v15[v7 + 3].m_vPos.x = *(p_z - 8);
      v15[v7 + 3].m_vPos.y = *(p_z - 7);
      v15[v7 + 3].m_vPos.z = *(p_z - 6);
      this->m_Verts.m_Memory.m_pMemory[v7 + 3].m_vColor = vColor;
      v7 += 4;
      --v9;
    }
    while ( v9 != 0 );
    v6 = i;
    v4 = nVerts;
  }
  if ( v6 < v4 )
  {
    v16 = v6;
    v17 = &pVerts[v6].z;
    v18 = v4 - v6;
    do
    {
      v19 = this->m_Verts.m_Memory.m_pMemory;
      v19[v16].m_vPos.x = *(v17 - 2);
      v17 += 3;
      v19[v16].m_vPos.y = *(v17 - 4);
      v19[v16].m_vPos.z = *(v17 - 3);
      this->m_Verts.m_Memory.m_pMemory[v16++].m_vColor = vColor;
      --v18;
    }
    while ( v18 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0040B860
// Name: public: virtual void CScratchPad3D::CCommand_Polygon::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Polygon::Read(CScratchPad3D::CCommand_Polygon *this, int pFile)
{
  CFileRead *v2; // esi
  CFileRead *v4; // ecx

  v2 = (CFileRead *)pFile;
  v2->m_Pos += (**(int (__thiscall ***)(int, int *, int, _DWORD))(*(_DWORD *)pFile + 4))(
                 a1: *(_DWORD *)pFile + 4,
                 a2: &pFile,
                 a3: 4,
                 a4: *(_DWORD *)(pFile + 4));
  v4 = (CFileRead *)pFile;
  this->m_Verts.m_Size = 0;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(
    this: &this->m_Verts,
    elem: this->m_Verts.m_Size,
    num: (int)v4);
  if ( pFile != 0 )
    v2->m_Pos += v2->m_pFileSystem->Read(
                   this: &v2->m_pFileSystem->IBaseFileSystem,
                   a2: this->m_Verts.m_Memory.m_pMemory,
                   a3: 28 * pFile,
                   a4: v2->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040B900
// Name: public: virtual void CScratchPad3D::SetMapping(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetMapping(
        CScratchPad3D *this,
        const Vector *vInputMin,
        const Vector *vInputMax,
        const Vector *vOutputMin,
        const Vector *vOutputMax)
{
  _DWORD *v6; // eax
  CScratchPad3D::CBaseCommand *v7; // esi
  int m_nAllocationCount; // eax
  int m_Size; // ebx
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v11; // eax
  CScratchPad3D::CBaseCommand **v12; // ebx
  float v15; // xmm0_4
  float v16; // xmm6_4
  float y; // xmm0_4
  float v18; // xmm0_4
  float z; // xmm7_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float x; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float vDivisor_4; // [esp+Ch] [ebp-18h]
  CScratchPad3D::CBaseCommand_vtbl *vScale; // [esp+14h] [ebp-10h]
  CScratchPad3D::ICachedRenderData *vScale_4; // [esp+18h] [ebp-Ch]
  float vInputMina; // [esp+2Ch] [ebp+8h]
  float vInputMaxa; // [esp+30h] [ebp+Ch]

  v6 = operator new(size: 0x4Cu);
  v7 = nullptr;
  if ( v6 != nullptr )
  {
    v6[2] = 0;
    *((_BYTE *)v6 + 4) = 3;
    *v6 = &CScratchPad3D::CCommand_Matrix::`vftable';
    v7 = (CScratchPad3D::CBaseCommand *)v6;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v11 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = v7;
  v15 = vInputMax->x - vInputMin->x;
  vInputMina = vInputMin->x;
  if ( fabs(v15) < 0.000099999997 )
    v15 = 0.001;
  v16 = v15;
  y = vInputMax->y;
  vInputMaxa = vInputMin->y;
  v18 = y - vInputMaxa;
  if ( fabs(v18) < 0.000099999997 )
    v18 = 0.001;
  z = vInputMin->z;
  vDivisor_4 = v18;
  v20 = vInputMax->z - z;
  if ( fabs(v20) < 0.000099999997 )
    v20 = 0.001;
  v21 = vOutputMax->z;
  x = vOutputMin->x;
  v23 = vOutputMin->y;
  v24 = vOutputMin->z;
  *(float *)&vScale = (float)(vOutputMax->x - vOutputMin->x) / v16;
  *(float *)&vScale_4 = (float)(vOutputMax->y - v23) / vDivisor_4;
  v7[1].__vftable = vScale;
  v25 = (float)(v21 - v24) / v20;
  *(_DWORD *)&v7[1].m_iCommand = 0;
  v7[1].m_pCachedRenderData = nullptr;
  *(_DWORD *)&v7[2].m_iCommand = 0;
  v7[3].__vftable = nullptr;
  v7[3].m_pCachedRenderData = nullptr;
  v7[4].__vftable = nullptr;
  v7[5].__vftable = nullptr;
  *(_DWORD *)&v7[5].m_iCommand = 0;
  v7[5].m_pCachedRenderData = nullptr;
  *(float *)&v7[2].__vftable = x + (float)((float)-vInputMina * *(float *)&vScale);
  v7[2].m_pCachedRenderData = vScale_4;
  *(float *)&v7[3].m_iCommand = v23 + (float)((float)-vInputMaxa * *(float *)&vScale_4);
  *(float *)&v7[4].m_iCommand = v25;
  *(float *)&v7[4].m_pCachedRenderData = v24 + (float)((float)-z * v25);
  v7[6].__vftable = (CScratchPad3D::CBaseCommand_vtbl *)1065353216;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040BB00
// Name: public: virtual void CScratchPad3D::DrawPoint(class CSPVert const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPoint(CScratchPad3D *this, const CSPVert *v, float flPointSize)
{
  _BYTE *v4; // eax
  _BYTE *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // edi

  v4 = operator new(size: 0x2Cu);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[4] = 0;
    *((_DWORD *)v4 + 2) = 0;
    *(_DWORD *)v4 = &CScratchPad3D::CCommand_Point::`vftable';
    *((_DWORD *)v4 + 10) = 1065353216;
    v5 = v4;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = (CScratchPad3D::CBaseCommand *)v5;
  *(CSPVert *)(v5 + 16) = *v;
  *((float *)v5 + 3) = flPointSize;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040BBE0
// Name: public: virtual void CScratchPad3D::DrawLine(class CSPVert const __near &,class CSPVert const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawLine(CScratchPad3D *this, const CSPVert *v1, const CSPVert *v2)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // ebx

  v4 = operator new(size: 0x44u);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[2] = 0;
    *((_BYTE *)v4 + 4) = 1;
    *v4 = &CScratchPad3D::CCommand_Line::`vftable';
    v4[9] = 1065353216;
    v4[16] = 1065353216;
    v5 = v4;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = (CScratchPad3D::CBaseCommand *)v5;
  *(CSPVert *)(v5 + 3) = *v1;
  *(CSPVert *)(v5 + 10) = *v2;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040BCE0
// Name: public: virtual void CScratchPad3D::DrawPolygon(class CSPVertList const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPolygon(CScratchPad3D *this, const CSPVertList *verts)
{
  CScratchPad3D::CCommand_Polygon *v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v7; // eax
  CScratchPad3D::CBaseCommand **v8; // eax
  CScratchPad3D::CCommand_Polygon *cmd; // [esp+Ch] [ebp-4h]

  v3 = (CScratchPad3D::CCommand_Polygon *)operator new(size: 0x20u);
  if ( v3 != nullptr )
  {
    v3->m_iCommand = 2;
    v3->m_pCachedRenderData = nullptr;
    v3->__vftable = (CScratchPad3D::CCommand_Polygon_vtbl *)&CScratchPad3D::CCommand_Polygon::`vftable';
    v3->m_Verts.m_Memory.m_pMemory = nullptr;
    v3->m_Verts.m_Memory.m_nAllocationCount = 0;
    v3->m_Verts.m_Memory.m_nGrowSize = 0;
    v3->m_Verts.m_Size = 0;
    v3->m_Verts.m_pElements = nullptr;
    cmd = v3;
  }
  else
  {
    cmd = nullptr;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v7 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = cmd;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::AddVectorToTail(this: &cmd->m_Verts, src: &verts->m_Verts);
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040BDA0
// Name: public: virtual void CScratchPad3D::DrawRectYZ(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectYZ(
        CScratchPad3D *this,
        float xPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v17 = xPos;
  v14 = xPos;
  v11 = xPos;
  pVerts.x = xPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.y = vMin->x;
  v12 = pVerts.y;
  v13 = vMax->y;
  v16 = v13;
  v21 = *vColor;
  pVerts.z = y;
  v15 = x;
  v18 = x;
  v19 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x0040BE50
// Name: public: virtual void CScratchPad3D::DrawRectXZ(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectXZ(
        CScratchPad3D *this,
        float yPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v18 = yPos;
  v15 = yPos;
  v12 = yPos;
  pVerts.y = yPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.x = vMin->x;
  v11 = pVerts.x;
  v13 = vMax->y;
  v16 = v13;
  v21 = *vColor;
  pVerts.z = y;
  v14 = x;
  v17 = x;
  v19 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x0040BF00
// Name: public: virtual void CScratchPad3D::DrawRectXY(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectXY(
        CScratchPad3D *this,
        float zPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v19 = zPos;
  v16 = zPos;
  v13 = zPos;
  pVerts.z = zPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.x = vMin->x;
  v11 = pVerts.x;
  v12 = vMax->y;
  v15 = v12;
  v21 = *vColor;
  pVerts.y = y;
  v14 = x;
  v17 = x;
  v18 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x0040BFB0
// Name: public: virtual void CScratchPad3D::SetRenderState(enum IScratchPad3D::RenderState,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetRenderState(
        CScratchPad3D *this,
        CScratchPad3D::CBaseCommand_vtbl *state,
        unsigned int val)
{
  _DWORD *v4; // eax
  CScratchPad3D::CBaseCommand *v5; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // eax

  v4 = operator new(size: 0x14u);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[2] = 0;
    *((_BYTE *)v4 + 4) = 4;
    *v4 = &CScratchPad3D::CCommand_RenderState::`vftable';
    v5 = (CScratchPad3D::CBaseCommand *)v4;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v5;
  v5[1].__vftable = state;
  *(_DWORD *)&v5[1].m_iCommand = val;
}

//------------------------------------------------------------------------------
// Address: 0x0040C050
// Name: public: void CScratchPad3D::DrawPolygonsForPixels(class SPRGBA __near *,int,int,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPolygonsForPixels(
        CScratchPad3D *this,
        SPRGBA *pData,
        int width,
        int height,
        unsigned int pitchInBytes,
        Vector *vCorners)
{
  float v6; // xmm2_4
  float v7; // xmm1_4
  float z; // edx
  float x; // xmm7_4
  float v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float y; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  int v23; // edx
  SPRGBA *v24; // esi
  unsigned int v25; // eax
  const CSPVertList *v26; // eax
  CSPVert *m_pMemory; // eax
  bool v28; // sf
  bool v29; // zf
  CSPColor v30; // [esp-1Ch] [ebp-D8h]
  unsigned int v31; // [esp+Ch] [ebp-B0h]
  float vLeftInc; // [esp+10h] [ebp-ACh]
  float vLeftInc_4; // [esp+14h] [ebp-A8h]
  float vLeftInc_8; // [esp+18h] [ebp-A4h]
  float vBottomXInc; // [esp+1Ch] [ebp-A0h]
  float vBottomXInc_4; // [esp+20h] [ebp-9Ch]
  float vBottomXInc_8; // [esp+24h] [ebp-98h]
  float vRightInc; // [esp+28h] [ebp-94h]
  float vRightInc_4; // [esp+2Ch] [ebp-90h]
  float vRightInc_8; // [esp+30h] [ebp-8Ch]
  SPRGBA *v41; // [esp+34h] [ebp-88h]
  int v42; // [esp+38h] [ebp-84h]
  float vNextLeft; // [esp+3Ch] [ebp-80h]
  float vNextLeft_4; // [esp+40h] [ebp-7Ch]
  float vNextLeft_8; // [esp+44h] [ebp-78h]
  float vTopXInc; // [esp+48h] [ebp-74h]
  float vTopXInc_4; // [esp+4Ch] [ebp-70h]
  float vTopXInc_8; // [esp+50h] [ebp-6Ch]
  Vector vPolyBox[4]; // [esp+54h] [ebp-68h] BYREF
  CSPVertList v50; // [esp+84h] [ebp-38h] BYREF
  Vector vNextRight; // [esp+98h] [ebp-24h]
  Vector vCurRight; // [esp+A4h] [ebp-18h]
  Vector vCurLeft; // [esp+B0h] [ebp-Ch]
  int pitchInBytesa; // [esp+D0h] [ebp+14h]
  float vCornersa; // [esp+D4h] [ebp+18h]

  v6 = vCorners->x - vCorners[1].x;
  v7 = vCorners->z - vCorners[1].z;
  z = vCorners[2].z;
  *(_QWORD *)&vCurLeft.x = *(_QWORD *)&vCorners[1].x;
  x = vCurLeft.x;
  v11 = vCorners[1].z;
  *(_QWORD *)&vCurRight.x = *(_QWORD *)&vCorners[2].x;
  v12 = vCorners->y - vCorners[1].y;
  vCurLeft.z = v11;
  v13 = 1.0 / (float)height;
  v14 = v12 * v13;
  v15 = v13 * v6;
  vLeftInc_8 = v7 * v13;
  v16 = (float)(vCorners[3].z - vCorners[2].z) * v13;
  vRightInc_4 = (float)(vCorners[3].y - vCorners[2].y) * v13;
  v17 = v11;
  y = vCurLeft.y;
  v19 = vCurRight.x + (float)((float)(1.0 / (float)height) * (float)(vCorners[3].x - vCorners[2].x));
  vRightInc = (float)(1.0 / (float)height) * (float)(vCorners[3].x - vCorners[2].x);
  vRightInc_8 = v16;
  vLeftInc = v15;
  v20 = vCurLeft.x + v15;
  vLeftInc_4 = v14;
  v21 = vCurLeft.y + v14;
  vNextRight.y = vCurRight.y + vRightInc_4;
  vCurRight.z = z;
  v22 = v11 + vLeftInc_8;
  vNextLeft = v20;
  vNextLeft_4 = v21;
  vNextLeft_8 = v11 + vLeftInc_8;
  vNextRight.x = v19;
  vNextRight.z = z + vRightInc_8;
  if ( height > 0 )
  {
    v23 = width;
    v24 = pData;
    v25 = 4 * (pitchInBytes >> 2);
    vCornersa = 1.0 / (float)width;
    v31 = v25;
    v41 = pData;
    v42 = height;
    while ( 1 )
    {
      vPolyBox[0].y = y;
      vPolyBox[0].z = v17;
      vTopXInc_4 = (float)(vCurRight.y - y) * vCornersa;
      vBottomXInc_4 = (float)(vNextRight.y - v21) * vCornersa;
      vTopXInc_8 = (float)(vCurRight.z - v17) * vCornersa;
      vTopXInc = vCornersa * (float)(vCurRight.x - x);
      vPolyBox[1].x = vTopXInc + x;
      vPolyBox[1].y = vTopXInc_4 + vCurLeft.y;
      vPolyBox[1].z = vTopXInc_8 + vCurLeft.z;
      vBottomXInc = vCornersa * (float)(vNextRight.x - v20);
      vPolyBox[0].x = x;
      vPolyBox[3].x = v20;
      vPolyBox[3].y = v21;
      vPolyBox[3].z = v22;
      vBottomXInc_8 = (float)(vNextRight.z - v22) * vCornersa;
      vPolyBox[2].x = vBottomXInc + v20;
      vPolyBox[2].y = vBottomXInc_4 + v21;
      vPolyBox[2].z = vBottomXInc_8 + v22;
      if ( v23 > 0 )
      {
        pitchInBytesa = v23;
        do
        {
          if ( pData != nullptr )
          {
            v30.m_vColor.x = (float)v24->r * 0.0039200312;
            v30.m_vColor.y = (float)v24->g * 0.0039200312;
            v30.m_vColor.z = (float)v24->b * 0.0039200312;
          }
          else
          {
            *(_QWORD *)&v30.m_vColor.x = 0x3F8000003F800000LL;
            v30.m_vColor.z = 1.0;
          }
          v30.m_flAlpha = 1.0;
          v26 = CSPVertList::CSPVertList(this: &v50, pVerts: vPolyBox, nVerts: 4, vColor: v30);
          this->DrawPolygon(this, a2: v26);
          m_pMemory = v50.m_Verts.m_Memory.m_pMemory;
          v50.m_Verts.m_Size = 0;
          v28 = v50.m_Verts.m_Memory.m_nGrowSize < 0;
          if ( v50.m_Verts.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v50.m_Verts.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50.m_Verts.m_Memory.m_pMemory);
              m_pMemory = nullptr;
              v50.m_Verts.m_Memory.m_pMemory = nullptr;
            }
            v28 = v50.m_Verts.m_Memory.m_nGrowSize < 0;
            v50.m_Verts.m_Memory.m_nAllocationCount = 0;
          }
          v50.m_Verts.m_pElements = m_pMemory;
          if ( !v28 && m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          vPolyBox[0].z = vPolyBox[0].z + vTopXInc_8;
          vPolyBox[1].y = vPolyBox[1].y + vTopXInc_4;
          vPolyBox[0].x = vPolyBox[0].x + vTopXInc;
          vPolyBox[1].x = vPolyBox[1].x + vTopXInc;
          vPolyBox[1].z = vPolyBox[1].z + vTopXInc_8;
          vPolyBox[3].x = vPolyBox[3].x + vBottomXInc;
          vPolyBox[0].y = vPolyBox[0].y + vTopXInc_4;
          vPolyBox[3].z = vPolyBox[3].z + vBottomXInc_8;
          vPolyBox[2].y = vPolyBox[2].y + vBottomXInc_4;
          ++v24;
          v29 = pitchInBytesa-- == 1;
          vPolyBox[3].y = vPolyBox[3].y + vBottomXInc_4;
          vPolyBox[2].x = vPolyBox[2].x + vBottomXInc;
          vPolyBox[2].z = vPolyBox[2].z + vBottomXInc_8;
        }
        while ( !v29 );
        x = vCurLeft.x;
        v20 = vNextLeft;
        v21 = vNextLeft_4;
        v22 = vNextLeft_8;
        v25 = v31;
        v23 = width;
      }
      x = x + vLeftInc;
      v20 = v20 + vLeftInc;
      v21 = v21 + vLeftInc_4;
      v22 = v22 + vLeftInc_8;
      vCurLeft.z = vCurLeft.z + vLeftInc_8;
      vCurRight.x = vCurRight.x + vRightInc;
      vCurLeft.y = vCurLeft.y + vLeftInc_4;
      vCurRight.z = vCurRight.z + vRightInc_8;
      vNextRight.y = vNextRight.y + vRightInc_4;
      v24 = (SPRGBA *)((char *)v41 + v25);
      v29 = v42-- == 1;
      vCurLeft.x = x;
      vNextLeft = v20;
      vNextLeft_4 = v21;
      vNextLeft_8 = v22;
      vCurRight.y = vCurRight.y + vRightInc_4;
      vNextRight.x = vNextRight.x + vRightInc;
      vNextRight.z = vNextRight.z + vRightInc_8;
      v41 = (SPRGBA *)((char *)v41 + v25);
      if ( v29 )
        break;
      v17 = vCurLeft.z;
      y = vCurLeft.y;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0040C5B0
// Name: public: virtual void CScratchPad3D::DrawImageRGBA(class SPRGBA __near *,int,int,int,bool,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawImageRGBA(
        CScratchPad3D *this,
        SPRGBA *pData,
        int width,
        int height,
        unsigned int pitchInBytes,
        bool bOutlinePixels,
        bool bOutlineImage,
        Vector *vCorners)
{
  Vector *v8; // edi
  void (__thiscall *SetRenderState)(struct CScratchPad3D *, IScratchPad3D::RenderState, unsigned int); // eax
  CScratchPad3D_vtbl *v11; // ebx
  CSPVertList *v12; // eax
  CSPColor v13; // [esp-10h] [ebp-60h]
  Vector vDefaultCorners[4]; // [esp+Ch] [ebp-44h] BYREF
  CSPVertList v15; // [esp+3Ch] [ebp-14h] BYREF
  bool bOldAutoFlush_3; // [esp+73h] [ebp+23h]

  v8 = vCorners;
  if ( vCorners == nullptr )
  {
    v8 = vDefaultCorners;
    vDefaultCorners[0].x = -100.0;
    vDefaultCorners[0].y = -100.0;
    vDefaultCorners[0].z = 0.0;
    vDefaultCorners[1].x = -100.0;
    vDefaultCorners[1].y = 100.0;
    vDefaultCorners[1].z = 0.0;
    vDefaultCorners[2].x = 100.0;
    vDefaultCorners[2].y = 100.0;
    vDefaultCorners[2].z = 0.0;
    vDefaultCorners[3].x = 100.0;
    vDefaultCorners[3].y = -100.0;
    vDefaultCorners[3].z = 0.0;
  }
  bOldAutoFlush_3 = this->m_bAutoFlush;
  SetRenderState = this->SetRenderState;
  this->m_bAutoFlush = false;
  ((void (__stdcall *)(_DWORD, int))SetRenderState)(a1: 0, a2: 1);
  CScratchPad3D::DrawPolygonsForPixels(this, pData, width, height, pitchInBytes, vCorners: v8);
  if ( bOutlinePixels )
  {
    this->SetRenderState(this, a2: RS_FillMode, a3: 0);
    CScratchPad3D::DrawPolygonsForPixels(this, pData: nullptr, width, height, pitchInBytes, vCorners: v8);
  }
  if ( bOutlineImage )
  {
    this->SetRenderState(this, a2: RS_FillMode, a3: 0);
    v11 = this->__vftable;
    *(_QWORD *)&v15.m_Verts.m_Memory.m_nAllocationCount = 0x3F8000003F800000LL;
    *(_QWORD *)&v15.m_Verts.m_Size = 0x3F8000003F800000LL;
    *(_QWORD *)&v13.m_vColor.x = 0x3F8000003F800000LL;
    *(_QWORD *)&v13.m_vColor.z = 0x3F8000003F800000LL;
    v12 = CSPVertList::CSPVertList(this: &v15, pVerts: v8, nVerts: 4, vColor: v13);
    v11->DrawPolygon(this, a2: v12);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CUtlSymbolTable::StringPool_t *,CUtlMemory<CUtlSymbolTable::StringPool_t *,int> > *)&v15);
  }
  this->m_bAutoFlush = bOldAutoFlush_3;
  if ( bOldAutoFlush_3 )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x0040C760
// Name: public: virtual void CScratchPad3D::CCommand_Text::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Text::Read(CScratchPad3D::CCommand_Text *this, CFileRead *pFile)
{
  CFileRead *v2; // esi
  CFileRead *v4; // eax
  int v5; // ebx
  int m_nAllocationCount; // ecx
  char *m_pMemory; // edx
  int v8; // ecx

  v2 = pFile;
  v2->m_Pos += pFile->m_pFileSystem->Read(
                 this: &pFile->m_pFileSystem->IBaseFileSystem,
                 a2: &pFile,
                 a3: 4,
                 a4: pFile->m_fp);
  v4 = pFile;
  v5 = (int)pFile;
  this->m_String.m_Size = 0;
  if ( v5 != 0 )
  {
    m_nAllocationCount = this->m_String.m_Memory.m_nAllocationCount;
    if ( (int)v4 > m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&this->m_String,
        num: (int)v4 - m_nAllocationCount);
      v4 = pFile;
    }
    this->m_String.m_Size += v5;
    m_pMemory = this->m_String.m_Memory.m_pMemory;
    v8 = this->m_String.m_Size - v5;
    this->m_String.m_pElements = m_pMemory;
    if ( v8 > 0 && v5 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: v8);
      v4 = pFile;
    }
  }
  v2->m_Pos += v2->m_pFileSystem->Read(
                 this: &v2->m_pFileSystem->IBaseFileSystem,
                 a2: this->m_String.m_Memory.m_pMemory,
                 a3: (int)v4,
                 a4: v2->m_fp);
  v2->m_Pos += v2->m_pFileSystem->Read(
                 this: &v2->m_pFileSystem->IBaseFileSystem,
                 a2: &this->m_TextParams,
                 a3: 56,
                 a4: v2->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x0040C810
// Name: public: virtual void CScratchPad3D::DrawText(char const __near *,class CTextParams const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawText(CScratchPad3D *this, const char *pStr, const CTextParams *params)
{
  CScratchPad3D::CCommand_Text *v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v8; // eax
  CScratchPad3D::CBaseCommand **v9; // eax
  CScratchPad3D::CCommand_Text *cmd; // [esp+10h] [ebp-4h]

  v4 = (CScratchPad3D::CCommand_Text *)operator new(size: 0x58u);
  if ( v4 != nullptr )
  {
    v4->m_iCommand = 5;
    v4->m_pCachedRenderData = nullptr;
    v4->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_Text::`vftable';
    v4->m_String.m_Memory.m_pMemory = nullptr;
    v4->m_String.m_Memory.m_nAllocationCount = 0;
    v4->m_String.m_Memory.m_nGrowSize = 0;
    v4->m_String.m_Size = 0;
    v4->m_String.m_pElements = nullptr;
    v4->m_TextParams.m_vColor.x = 1.0;
    v4->m_TextParams.m_vColor.y = 1.0;
    v4->m_TextParams.m_vColor.z = 1.0;
    v4->m_TextParams.m_flAlpha = 1.0;
    *(_WORD *)&v4->m_TextParams.m_bSolidBackground = 257;
    v4->m_TextParams.m_vPos.x = 0.0;
    v4->m_TextParams.m_vPos.y = 0.0;
    v4->m_TextParams.m_vPos.z = 0.0;
    v4->m_TextParams.m_bCentered = true;
    v4->m_TextParams.m_vAngles.x = 0.0;
    v4->m_TextParams.m_vAngles.y = 0.0;
    v4->m_TextParams.m_vAngles.z = 0.0;
    v4->m_TextParams.m_bTwoSided = true;
    v4->m_TextParams.m_flLetterWidth = 3.0;
    cmd = v4;
  }
  else
  {
    cmd = nullptr;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CUtlSymbolTable::StringPool_t *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v8 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = cmd;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &cmd->m_String, pArray: pStr, size: strlen(pStr) + 1);
  CTextParams::operator=(this: &cmd->m_TextParams, __that: params);
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

} // namespace vbspinfo

// ============================================================
// Overlay from vvis_dll (Missing functions)
// ============================================================
namespace vvis_dll {

//------------------------------------------------------------------------------
// Address: 0x1000FC50
// Name: public: virtual void CScratchPad3D::CCommand_Point::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Point::Read(CScratchPad3D::CCommand_Point *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_flPointSize,
                    a3: 4,
                    a4: pFile->m_fp);
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_Vert,
                    a3: 28,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1000FCA0
// Name: public: virtual void CScratchPad3D::CCommand_Point::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Point::Write(
        CScratchPad3D::CCommand_Point *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_flPointSize, a3: 4, a4: fp);
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_Vert, a3: 28, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x1000FCE0
// Name: public: virtual void CScratchPad3D::CCommand_Line::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Line::Read(CScratchPad3D::CCommand_Line *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: this->m_Verts,
                    a3: 56,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD10
// Name: public: virtual void CScratchPad3D::CCommand_Line::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Line::Write(
        CScratchPad3D::CCommand_Line *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: this->m_Verts, a3: 56, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD40
// Name: public: virtual void CScratchPad3D::CCommand_Matrix::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Matrix::Read(CScratchPad3D::CCommand_Matrix *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_mMatrix,
                    a3: 64,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1000FD70
// Name: public: virtual void CScratchPad3D::CCommand_Matrix::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Matrix::Write(
        CScratchPad3D::CCommand_Matrix *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_mMatrix, a3: 64, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x1000FDA0
// Name: public: virtual void CScratchPad3D::CCommand_RenderState::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_RenderState::Read(CScratchPad3D::CCommand_RenderState *this, CFileRead *pFile)
{
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_State,
                    a3: 4,
                    a4: pFile->m_fp);
  pFile->m_Pos += pFile->m_pFileSystem->Read(
                    this: &pFile->m_pFileSystem->IBaseFileSystem,
                    a2: &this->m_Val,
                    a3: 4,
                    a4: pFile->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x1000FDF0
// Name: public: virtual void CScratchPad3D::CCommand_RenderState::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_RenderState::Write(
        CScratchPad3D::CCommand_RenderState *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_State, a3: 4, a4: fp);
  pFileSystem->Write(this: &pFileSystem->IBaseFileSystem, a2: &this->m_Val, a3: 4, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE30
// Name: public: virtual void CScratchPad3D::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Release(CScratchPad3D *this)
{
  this->Flush(this);
  ((void (__thiscall *)(CScratchPad3D *, int))this->dtr_IScratchPad3D)(a1: this, a2: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE50
// Name: public: virtual bool CScratchPad3D::GetAutoFlush(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CScratchPad3D::GetAutoFlush(CScratchPad3D *this)
{
  return this->m_bAutoFlush;
}

//------------------------------------------------------------------------------
// Address: 0x1000FE60
// Name: public: virtual void CScratchPad3D::SetAutoFlush(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetAutoFlush(CScratchPad3D *this, bool bAutoFlush)
{
  this->m_bAutoFlush = bAutoFlush;
  if ( bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x1000FE80
// Name: public: class CTextParams __near & CTextParams::operator=(class CTextParams const __near &)
// Source: json
//------------------------------------------------------------------------------
CTextParams *__thiscall CTextParams::operator=(CTextParams *this, const CTextParams *__that)
{
  *this = *__that;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x1000FEF0
// Name: public: virtual void CScratchPad3D::DrawImageBW(unsigned char const __near *,int,int,int,bool,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawImageBW(
        CScratchPad3D *this,
        const unsigned __int8 *pData,
        int width,
        int height,
        int pitchInBytes,
        BOOL bOutlinePixels,
        BOOL bOutlineImage,
        Vector *vCorners)
{
  int v8; // esi
  CScratchPad3D *v10; // ebx
  SPRGBA *v11; // eax
  const unsigned __int8 *v12; // edx
  SPRGBA *v13; // ebx
  SPRGBA *v14; // eax
  int i; // esi
  unsigned __int8 v16; // cl
  bool v17; // zf
  SPRGBA *pRGBA; // [esp+10h] [ebp-4h]
  const unsigned __int8 *pDataa; // [esp+1Ch] [ebp+8h]
  const unsigned __int8 *widtha; // [esp+20h] [ebp+Ch]

  v8 = height;
  v10 = this;
  v11 = (SPRGBA *)operator new(size: 4 * height * width);
  pRGBA = v11;
  if ( height > 0 )
  {
    v12 = pData;
    widtha = pData;
    v13 = v11;
    pDataa = (const unsigned __int8 *)height;
    do
    {
      v14 = v13;
      if ( width > 0 )
      {
        for ( i = width; i != 0; --i )
        {
          v16 = *v12;
          v14->b = *v12;
          v14->g = v16;
          v14->r = v16;
          ++v12;
          ++v14;
        }
        v8 = height;
        v12 = widtha;
      }
      v12 += pitchInBytes;
      v13 += width;
      v17 = pDataa-- == (const unsigned __int8 *)1;
      widtha = v12;
    }
    while ( !v17 );
    v10 = this;
    v11 = pRGBA;
  }
  v10->DrawImageRGBA(
    this: v10,
    a2: v11,
    a3: width,
    a4: v8,
    a5: 4 * width,
    a6: bOutlinePixels,
    a7: bOutlineImage,
    a8: vCorners);
  operator delete(p: pRGBA);
}

//------------------------------------------------------------------------------
// Address: 0x100100D0
// Name: public: virtual void CScratchPad3D::CCommand_Polygon::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Polygon::Write(
        CScratchPad3D::CCommand_Polygon *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  int (__thiscall *Write)(IBaseFileSystem *, const void *, int, void *); // edx
  int count; // [esp+Ch] [ebp-4h] BYREF

  Write = pFileSystem->Write;
  count = this->m_Verts.m_Size;
  Write(this: &pFileSystem->IBaseFileSystem, a2: &count, a3: 4, a4: fp);
  if ( count != 0 )
    pFileSystem->Write(
      this: &pFileSystem->IBaseFileSystem,
      a2: this->m_Verts.m_Memory.m_pMemory,
      a3: 28 * count,
      a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10010130
// Name: public: virtual void CScratchPad3D::CCommand_Text::Write(class IFileSystem __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Text::Write(
        CScratchPad3D::CCommand_Text *this,
        IFileSystem *pFileSystem,
        void *fp)
{
  int (__thiscall *Write)(IBaseFileSystem *, const void *, int, void *); // edx
  IBaseFileSystem *v5; // esi
  int strLen; // [esp+Ch] [ebp-4h] BYREF

  Write = pFileSystem->Write;
  v5 = &pFileSystem->IBaseFileSystem;
  strLen = this->m_String.m_Size;
  Write(this: &pFileSystem->IBaseFileSystem, a2: &strLen, a3: 4, a4: fp);
  v5->Write(this: v5, a2: this->m_String.m_Memory.m_pMemory, a3: strLen, a4: fp);
  v5->Write(this: v5, a2: &this->m_TextParams, a3: 56, a4: fp);
}

//------------------------------------------------------------------------------
// Address: 0x10010190
// Name: public: virtual void CScratchPad3D::DrawWireframeBox(class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawWireframeBox(
        CScratchPad3D *this,
        const Vector *vMin,
        const Vector *vMax,
        const Vector *vColor)
{
  float y; // xmm3_4
  float z; // xmm4_4
  float x; // xmm0_4
  float v7; // xmm1_4
  float v9; // xmm2_4
  void (__thiscall *DrawLine)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v11; // xmm3_4
  float v12; // xmm4_4
  float v13; // xmm0_4
  float v14; // xmm1_4
  void (__thiscall *v15)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v16; // xmm2_4
  float v17; // xmm3_4
  float v18; // xmm4_4
  float v19; // xmm0_4
  float v20; // xmm1_4
  float v21; // xmm2_4
  void (__thiscall *v22)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v23; // xmm4_4
  float v24; // xmm3_4
  float v25; // xmm0_4
  float v26; // xmm1_4
  void (__thiscall *v27)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v28; // xmm2_4
  float v29; // xmm5_4
  float v30; // xmm6_4
  float v31; // xmm3_4
  float v32; // xmm4_4
  float v33; // xmm2_4
  void (__thiscall *v34)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v35; // xmm3_4
  float v36; // xmm4_4
  float v37; // xmm0_4
  float v38; // xmm1_4
  void (__thiscall *v39)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v40; // xmm2_4
  float v41; // xmm3_4
  float v42; // xmm4_4
  float v43; // xmm5_4
  float v44; // xmm6_4
  void (__thiscall *v45)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v46; // xmm2_4
  float v47; // xmm3_4
  float v48; // xmm0_4
  float v49; // xmm4_4
  float v50; // xmm1_4
  void (__thiscall *v51)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v52; // xmm2_4
  float v53; // xmm3_4
  float v54; // xmm4_4
  float v55; // xmm0_4
  float v56; // xmm1_4
  float v57; // xmm2_4
  void (__thiscall *v58)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v59; // xmm3_4
  float v60; // xmm4_4
  float v61; // xmm0_4
  float v62; // xmm1_4
  void (__thiscall *v63)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v64; // xmm2_4
  float v65; // xmm3_4
  float v66; // xmm4_4
  float v67; // xmm0_4
  float v68; // xmm1_4
  float v69; // xmm2_4
  float v70; // xmm2_4
  void (__thiscall *v71)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // edx
  float v72; // xmm3_4
  float v73; // xmm4_4
  float v74; // xmm0_4
  float v75; // xmm1_4
  float v76; // xmm2_4
  void (__thiscall *v77)(struct CScratchPad3D *, const CSPVert *, const CSPVert *); // eax
  float v78; // [esp+0h] [ebp-54h] BYREF
  float v79; // [esp+4h] [ebp-50h]
  float v80; // [esp+8h] [ebp-4Ch]
  float v81; // [esp+Ch] [ebp-48h]
  float v82; // [esp+10h] [ebp-44h]
  float v83; // [esp+14h] [ebp-40h]
  int v84; // [esp+18h] [ebp-3Ch]
  float v85; // [esp+1Ch] [ebp-38h] BYREF
  float v86; // [esp+20h] [ebp-34h]
  float v87; // [esp+24h] [ebp-30h]
  float v88; // [esp+28h] [ebp-2Ch]
  float v89; // [esp+2Ch] [ebp-28h]
  float v90; // [esp+30h] [ebp-24h]
  int v91; // [esp+34h] [ebp-20h]
  _DWORD v92[5]; // [esp+38h] [ebp-1Ch] BYREF
  float v93; // [esp+4Ch] [ebp-8h]
  float v94; // [esp+50h] [ebp-4h]

  y = vMin->y;
  z = vMin->z;
  x = vColor->x;
  v7 = vColor->y;
  v93 = vColor->z;
  v85 = vMax->x;
  v86 = y;
  v87 = z;
  v9 = vMin->x;
  DrawLine = this->DrawLine;
  v88 = x;
  v81 = x;
  v89 = v7;
  v90 = v93;
  v91 = 1065353216;
  v78 = v9;
  v79 = y;
  v80 = z;
  v82 = v7;
  v83 = v93;
  v84 = 1065353216;
  DrawLine(this, a2: (const CSPVert *)&v78, a3: (const CSPVert *)&v85);
  v11 = vMin->x;
  v12 = vMin->z;
  v13 = vColor->x;
  v14 = vColor->y;
  v15 = this->DrawLine;
  v93 = vColor->z;
  v78 = v11;
  v79 = vMax->y;
  v80 = v12;
  v16 = vMin->y;
  v81 = v13;
  v88 = v13;
  v82 = v14;
  v83 = v93;
  v84 = 1065353216;
  v85 = v11;
  v86 = v16;
  v87 = v12;
  v89 = v14;
  v90 = v93;
  v91 = 1065353216;
  v15(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v17 = vMax->x;
  v18 = vMin->z;
  v19 = vColor->x;
  v20 = vColor->y;
  v93 = vColor->z;
  v78 = v17;
  v79 = vMax->y;
  v80 = v18;
  v21 = vMin->y;
  v22 = this->DrawLine;
  v81 = v19;
  v88 = v19;
  v82 = v20;
  v83 = v93;
  v84 = 1065353216;
  v85 = v17;
  v86 = v21;
  v87 = v18;
  v89 = v20;
  v90 = v93;
  v91 = 1065353216;
  v22(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v23 = vMin->z;
  v24 = vMax->y;
  v25 = vColor->x;
  v26 = vColor->y;
  v27 = this->DrawLine;
  v93 = vColor->z;
  v78 = vMin->x;
  v79 = v24;
  v80 = v23;
  v28 = vMax->x;
  v81 = v25;
  v88 = v25;
  v82 = v26;
  v83 = v93;
  v84 = 1065353216;
  v85 = v28;
  v86 = v24;
  v87 = v23;
  v89 = v26;
  v90 = v93;
  v91 = 1065353216;
  v27(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v29 = vColor->x;
  v30 = vColor->y;
  v31 = vMin->y;
  v32 = vMax->z;
  v93 = vColor->z;
  v78 = vMax->x;
  v79 = v31;
  v80 = v32;
  v33 = vMin->x;
  v34 = this->DrawLine;
  v81 = v29;
  v88 = v29;
  v82 = v30;
  v83 = v93;
  v84 = 1065353216;
  v85 = v33;
  v86 = v31;
  v87 = v32;
  v89 = v30;
  v90 = v93;
  v91 = 1065353216;
  v34(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v35 = vMin->x;
  v36 = vMax->z;
  v37 = vColor->x;
  v38 = vColor->y;
  v39 = this->DrawLine;
  v93 = vColor->z;
  v78 = v35;
  v79 = vMax->y;
  v80 = v36;
  v40 = vMin->y;
  v81 = v37;
  v88 = v37;
  v82 = v38;
  v83 = v93;
  v84 = 1065353216;
  v85 = v35;
  v86 = v40;
  v87 = v36;
  v89 = v38;
  v90 = v93;
  v91 = 1065353216;
  v39(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v41 = vMax->x;
  v42 = vMax->z;
  v43 = vColor->x;
  v44 = vColor->y;
  v93 = vColor->z;
  v45 = this->DrawLine;
  v78 = v41;
  v79 = vMax->y;
  v80 = v42;
  v46 = vMin->y;
  v81 = v43;
  v88 = v43;
  v82 = v44;
  v83 = v93;
  v84 = 1065353216;
  v85 = v41;
  v86 = v46;
  v87 = v42;
  v89 = v44;
  v90 = v93;
  v91 = 1065353216;
  v45(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v47 = vMax->y;
  v48 = vColor->x;
  v49 = vMax->z;
  v50 = vColor->y;
  v51 = this->DrawLine;
  v93 = vColor->z;
  v78 = vMin->x;
  v79 = v47;
  v80 = v49;
  v52 = vMax->x;
  v81 = v48;
  v88 = v48;
  v82 = v50;
  v83 = v93;
  v84 = 1065353216;
  v85 = v52;
  v86 = v47;
  v87 = v49;
  v89 = v50;
  v90 = v93;
  v91 = 1065353216;
  v51(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v53 = vMin->x;
  v54 = vMin->y;
  v55 = vColor->x;
  v56 = vColor->y;
  v93 = vColor->z;
  v78 = v53;
  v79 = v54;
  v80 = vMax->z;
  v57 = vMin->z;
  v58 = this->DrawLine;
  v81 = v55;
  v88 = v55;
  v82 = v56;
  v83 = v93;
  v84 = 1065353216;
  v85 = v53;
  v86 = v54;
  v87 = v57;
  v89 = v56;
  v90 = v93;
  v91 = 1065353216;
  v58(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v59 = vMin->x;
  v60 = vMax->y;
  v61 = vColor->x;
  v62 = vColor->y;
  v63 = this->DrawLine;
  v93 = vColor->z;
  v78 = v59;
  v79 = v60;
  v80 = vMax->z;
  v64 = vMin->z;
  v81 = v61;
  v88 = v61;
  v82 = v62;
  v83 = v93;
  v84 = 1065353216;
  v85 = v59;
  v86 = v60;
  v87 = v64;
  v89 = v62;
  v90 = v93;
  v91 = 1065353216;
  v63(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v65 = vMax->x;
  v66 = vMax->y;
  v67 = vColor->x;
  v68 = vColor->y;
  v93 = vColor->z;
  v78 = v65;
  v79 = v66;
  v69 = vMax->z;
  v81 = v67;
  v80 = v69;
  v82 = v68;
  v83 = v93;
  v70 = vMin->z;
  v71 = this->DrawLine;
  v88 = v67;
  v84 = 1065353216;
  v85 = v65;
  v86 = v66;
  v87 = v70;
  v89 = v68;
  v90 = v93;
  v91 = 1065353216;
  v71(this, a2: (const CSPVert *)&v85, a3: (const CSPVert *)&v78);
  v72 = vMax->x;
  v73 = vMin->y;
  v74 = vColor->x;
  v75 = vColor->y;
  v90 = vColor->z;
  v94 = vMax->z;
  v78 = v72;
  v79 = v73;
  v80 = v94;
  v76 = vMin->z;
  v77 = this->DrawLine;
  v81 = v74;
  *(float *)&v92[3] = v74;
  v82 = v75;
  v83 = v90;
  v84 = 1065353216;
  *(float *)v92 = v72;
  *(float *)&v92[1] = v73;
  *(float *)&v92[2] = v76;
  *(float *)&v92[4] = v75;
  v93 = v90;
  v94 = 1.0;
  v77(this, a2: (const CSPVert *)v92, a3: (const CSPVert *)&v78);
}

//------------------------------------------------------------------------------
// Address: 0x100108F0
// Name: public: void CScratchPad3D::DeleteCommands(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DeleteCommands(CScratchPad3D *this)
{
  int v2; // ebx
  CScratchPad3D::CBaseCommand *v3; // esi
  CScratchPad3D::ICachedRenderData *m_pCachedRenderData; // ecx

  v2 = 0;
  if ( this->m_Commands.m_Size <= 0 )
  {
    this->m_Commands.m_Size = 0;
  }
  else
  {
    do
    {
      v3 = this->m_Commands.m_Memory.m_pMemory[v2];
      if ( v3 != nullptr )
      {
        m_pCachedRenderData = v3->m_pCachedRenderData;
        v3->__vftable = (CScratchPad3D::CBaseCommand_vtbl *)&CScratchPad3D::CBaseCommand::`vftable';
        if ( m_pCachedRenderData != nullptr )
        {
          m_pCachedRenderData->Release(this: m_pCachedRenderData);
          v3->m_pCachedRenderData = nullptr;
        }
        operator delete(p: v3);
      }
      ++v2;
    }
    while ( v2 < this->m_Commands.m_Size );
    this->m_Commands.m_Size = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10010950
// Name: public: virtual void CScratchPad3D::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Clear(CScratchPad3D *this)
{
  void *i; // eax

  for ( i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "wb",
              a4: 0);
        i == nullptr;
        i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "wb",
              a4: 0) )
  {
    Sleep(dwMilliseconds: 5u);
  }
  this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: i);
  CScratchPad3D::DeleteCommands(this);
}

//------------------------------------------------------------------------------
// Address: 0x100109B0
// Name: public: virtual void CScratchPad3D::Flush(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::Flush(CScratchPad3D *this)
{
  void *i; // edi
  int j; // ebx
  CScratchPad3D::CBaseCommand *v4; // ecx

  for ( i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "ab+",
              a4: 0);
        i == nullptr;
        i = this->m_pFileSystem->Open(
              this: &this->m_pFileSystem->IBaseFileSystem,
              a2: this->m_pFilename,
              a3: "ab+",
              a4: 0) )
  {
    Sleep(dwMilliseconds: 5u);
  }
  for ( j = 0; j < this->m_Commands.m_Size; ++j )
  {
    this->m_pFileSystem->Write(
      this: &this->m_pFileSystem->IBaseFileSystem,
      a2: &this->m_Commands.m_Memory.m_pMemory[j]->m_iCommand,
      a3: 1,
      a4: i);
    v4 = this->m_Commands.m_Memory.m_pMemory[j];
    v4->Write(this: v4, a2: this->m_pFileSystem, a3: i);
  }
  this->m_pFileSystem->Close(this: &this->m_pFileSystem->IBaseFileSystem, a2: i);
  CScratchPad3D::DeleteCommands(this);
}

//------------------------------------------------------------------------------
// Address: 0x10010C10
// Name: class IScratchPad3D __near * ScratchPad3D_Create(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CScratchPad3D *__cdecl ScratchPad3D_Create(const char *pFilename)
{
  struct CSysModule *Module; // eax
  struct CSysModule *v2; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  int v4; // ebx
  CScratchPad3D *v6; // esi

  Module = Sys_LoadModule(pModuleName: "filesystem_stdio");
  v2 = Module;
  if ( Module == nullptr )
    return nullptr;
  Factory = Sys_GetFactory(pModule: Module);
  if ( Factory == nullptr || (v4 = (int)Factory(a1: "VFileSystem017", a2: nullptr)) == 0 )
  {
    Sys_UnloadModule(pModule: v2);
    return nullptr;
  }
  v6 = (CScratchPad3D *)operator new(size: 0x24u);
  if ( v6 == nullptr )
    return nullptr;
  v6->__vftable = (CScratchPad3D_vtbl *)&CScratchPad3D::`vftable';
  v6->m_Commands.m_Memory.m_pMemory = nullptr;
  v6->m_Commands.m_Memory.m_nAllocationCount = 0;
  v6->m_Commands.m_Memory.m_nGrowSize = 0;
  v6->m_Commands.m_Size = 0;
  v6->m_Commands.m_pElements = nullptr;
  v6->m_pFileSystem = (IFileSystem *)v4;
  v6->m_pFilename = pFilename;
  v6->m_bAutoFlush = true;
  CScratchPad3D::Clear(this: v6);
  return v6;
}

//------------------------------------------------------------------------------
// Address: 0x10010CA0
// Name: public: CSPVertList::CSPVertList(class Vector const __near *,int,class CSPColor)
// Source: json
//------------------------------------------------------------------------------
CSPVertList *__thiscall CSPVertList::CSPVertList(CSPVertList *this, const Vector *pVerts, int nVerts, CSPColor vColor)
{
  int v4; // ebx
  signed int v6; // eax
  int v7; // ecx
  float *p_z; // eax
  unsigned int v9; // ebx
  CSPVert *m_pMemory; // edx
  CSPVert *v11; // edx
  int v12; // edx
  CSPVert *v13; // edx
  int v14; // edx
  CSPVert *v15; // edx
  unsigned int v16; // ecx
  float *v17; // edx
  int v18; // ebx
  CSPVert *v19; // eax
  int i; // [esp+Ch] [ebp-4h]

  v4 = nVerts;
  this->m_Verts.m_Memory.m_pMemory = nullptr;
  this->m_Verts.m_Memory.m_nAllocationCount = 0;
  this->m_Verts.m_Memory.m_nGrowSize = 0;
  this->m_Verts.m_Size = 0;
  this->m_Verts.m_pElements = nullptr;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(this: &this->m_Verts, elem: 0, num: nVerts);
  v6 = 0;
  if ( nVerts >= 4 )
  {
    v7 = 0;
    p_z = &pVerts[1].z;
    v9 = ((unsigned int)(nVerts - 4) >> 2) + 1;
    i = 4 * v9;
    do
    {
      m_pMemory = this->m_Verts.m_Memory.m_pMemory;
      m_pMemory[v7].m_vPos.x = *(p_z - 5);
      p_z += 12;
      m_pMemory[v7].m_vPos.y = *(p_z - 16);
      m_pMemory[v7].m_vPos.z = *(p_z - 15);
      this->m_Verts.m_Memory.m_pMemory[v7].m_vColor = vColor;
      v11 = this->m_Verts.m_Memory.m_pMemory;
      v11[v7 + 1].m_vPos.x = *(p_z - 14);
      v12 = (int)&v11[v7 + 1];
      *(float *)(v12 + 4) = *(p_z - 13);
      *(float *)(v12 + 8) = *(p_z - 12);
      this->m_Verts.m_Memory.m_pMemory[v7 + 1].m_vColor = vColor;
      v13 = this->m_Verts.m_Memory.m_pMemory;
      v13[v7 + 2].m_vPos.x = *(p_z - 11);
      v14 = (int)&v13[v7 + 2];
      *(float *)(v14 + 4) = *(p_z - 10);
      *(float *)(v14 + 8) = *(p_z - 9);
      this->m_Verts.m_Memory.m_pMemory[v7 + 2].m_vColor = vColor;
      v15 = this->m_Verts.m_Memory.m_pMemory;
      v15[v7 + 3].m_vPos.x = *(p_z - 8);
      v15[v7 + 3].m_vPos.y = *(p_z - 7);
      v15[v7 + 3].m_vPos.z = *(p_z - 6);
      this->m_Verts.m_Memory.m_pMemory[v7 + 3].m_vColor = vColor;
      v7 += 4;
      --v9;
    }
    while ( v9 != 0 );
    v6 = i;
    v4 = nVerts;
  }
  if ( v6 < v4 )
  {
    v16 = v6;
    v17 = &pVerts[v6].z;
    v18 = v4 - v6;
    do
    {
      v19 = this->m_Verts.m_Memory.m_pMemory;
      v19[v16].m_vPos.x = *(v17 - 2);
      v17 += 3;
      v19[v16].m_vPos.y = *(v17 - 4);
      v19[v16].m_vPos.z = *(v17 - 3);
      this->m_Verts.m_Memory.m_pMemory[v16++].m_vColor = vColor;
      --v18;
    }
    while ( v18 != 0 );
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10010EA0
// Name: public: virtual void CScratchPad3D::CCommand_Polygon::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Polygon::Read(CScratchPad3D::CCommand_Polygon *this, int pFile)
{
  CFileRead *v2; // esi
  CFileRead *v4; // ecx

  v2 = (CFileRead *)pFile;
  v2->m_Pos += (**(int (__thiscall ***)(int, int *, int, _DWORD))(*(_DWORD *)pFile + 4))(
                 a1: *(_DWORD *)pFile + 4,
                 a2: &pFile,
                 a3: 4,
                 a4: *(_DWORD *)(pFile + 4));
  v4 = (CFileRead *)pFile;
  this->m_Verts.m_Size = 0;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::InsertMultipleBefore(
    this: &this->m_Verts,
    elem: this->m_Verts.m_Size,
    num: (int)v4);
  if ( pFile != 0 )
    v2->m_Pos += v2->m_pFileSystem->Read(
                   this: &v2->m_pFileSystem->IBaseFileSystem,
                   a2: this->m_Verts.m_Memory.m_pMemory,
                   a3: 28 * pFile,
                   a4: v2->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10010F40
// Name: public: virtual void CScratchPad3D::SetMapping(class Vector const __near &,class Vector const __near &,class Vector const __near &,class Vector const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetMapping(
        CScratchPad3D *this,
        const Vector *vInputMin,
        const Vector *vInputMax,
        const Vector *vOutputMin,
        const Vector *vOutputMax)
{
  _DWORD *v6; // eax
  CScratchPad3D::CBaseCommand *v7; // esi
  int m_nAllocationCount; // eax
  int m_Size; // ebx
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v11; // eax
  CScratchPad3D::CBaseCommand **v12; // ebx
  float v15; // xmm0_4
  float v16; // xmm6_4
  float y; // xmm0_4
  float v18; // xmm0_4
  float z; // xmm7_4
  float v20; // xmm0_4
  float v21; // xmm2_4
  float x; // xmm3_4
  float v23; // xmm4_4
  float v24; // xmm5_4
  float v25; // xmm2_4
  float vDivisor_4; // [esp+Ch] [ebp-18h]
  CScratchPad3D::CBaseCommand_vtbl *vScale; // [esp+14h] [ebp-10h]
  CScratchPad3D::ICachedRenderData *vScale_4; // [esp+18h] [ebp-Ch]
  float vInputMina; // [esp+2Ch] [ebp+8h]
  float vInputMaxa; // [esp+30h] [ebp+Ch]

  v6 = operator new(size: 0x4Cu);
  v7 = nullptr;
  if ( v6 != nullptr )
  {
    v6[2] = 0;
    *((_BYTE *)v6 + 4) = 3;
    *v6 = &CScratchPad3D::CCommand_Matrix::`vftable';
    v7 = (CScratchPad3D::CBaseCommand *)v6;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CTCPPacket *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v11 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v11 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v11);
  v12 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v12 != nullptr )
    *v12 = v7;
  v15 = vInputMax->x - vInputMin->x;
  vInputMina = vInputMin->x;
  if ( fabs(v15) < 0.000099999997 )
    v15 = 0.001;
  v16 = v15;
  y = vInputMax->y;
  vInputMaxa = vInputMin->y;
  v18 = y - vInputMaxa;
  if ( fabs(v18) < 0.000099999997 )
    v18 = 0.001;
  z = vInputMin->z;
  vDivisor_4 = v18;
  v20 = vInputMax->z - z;
  if ( fabs(v20) < 0.000099999997 )
    v20 = 0.001;
  v21 = vOutputMax->z;
  x = vOutputMin->x;
  v23 = vOutputMin->y;
  v24 = vOutputMin->z;
  *(float *)&vScale = (float)(vOutputMax->x - vOutputMin->x) / v16;
  *(float *)&vScale_4 = (float)(vOutputMax->y - v23) / vDivisor_4;
  v7[1].__vftable = vScale;
  v25 = (float)(v21 - v24) / v20;
  *(_DWORD *)&v7[1].m_iCommand = 0;
  v7[1].m_pCachedRenderData = nullptr;
  *(_DWORD *)&v7[2].m_iCommand = 0;
  v7[3].__vftable = nullptr;
  v7[3].m_pCachedRenderData = nullptr;
  v7[4].__vftable = nullptr;
  v7[5].__vftable = nullptr;
  *(_DWORD *)&v7[5].m_iCommand = 0;
  v7[5].m_pCachedRenderData = nullptr;
  *(float *)&v7[2].__vftable = x + (float)((float)-vInputMina * *(float *)&vScale);
  v7[2].m_pCachedRenderData = vScale_4;
  *(float *)&v7[3].m_iCommand = v23 + (float)((float)-vInputMaxa * *(float *)&vScale_4);
  *(float *)&v7[4].m_iCommand = v25;
  *(float *)&v7[4].m_pCachedRenderData = v24 + (float)((float)-z * v25);
  v7[6].__vftable = (CScratchPad3D::CBaseCommand_vtbl *)1065353216;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011140
// Name: public: virtual void CScratchPad3D::DrawPoint(class CSPVert const __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPoint(CScratchPad3D *this, const CSPVert *v, float flPointSize)
{
  _BYTE *v4; // eax
  _BYTE *v5; // ebx
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // edi

  v4 = operator new(size: 0x2Cu);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[4] = 0;
    *((_DWORD *)v4 + 2) = 0;
    *(_DWORD *)v4 = &CScratchPad3D::CCommand_Point::`vftable';
    *((_DWORD *)v4 + 10) = 1065353216;
    v5 = v4;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CTCPPacket *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = (CScratchPad3D::CBaseCommand *)v5;
  *(CSPVert *)(v5 + 16) = *v;
  *((float *)v5 + 3) = flPointSize;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011220
// Name: public: virtual void CScratchPad3D::DrawLine(class CSPVert const __near &,class CSPVert const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawLine(CScratchPad3D *this, const CSPVert *v1, const CSPVert *v2)
{
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // ebx

  v4 = operator new(size: 0x44u);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[2] = 0;
    *((_BYTE *)v4 + 4) = 1;
    *v4 = &CScratchPad3D::CCommand_Line::`vftable';
    v4[9] = 1065353216;
    v4[16] = 1065353216;
    v5 = v4;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CTCPPacket *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = (CScratchPad3D::CBaseCommand *)v5;
  *(CSPVert *)(v5 + 3) = *v1;
  *(CSPVert *)(v5 + 10) = *v2;
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011320
// Name: public: virtual void CScratchPad3D::DrawPolygon(class CSPVertList const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPolygon(CScratchPad3D *this, const CSPVertList *verts)
{
  CScratchPad3D::CCommand_Polygon *v3; // eax
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v7; // eax
  CScratchPad3D::CBaseCommand **v8; // eax
  CScratchPad3D::CCommand_Polygon *cmd; // [esp+Ch] [ebp-4h]

  v3 = (CScratchPad3D::CCommand_Polygon *)operator new(size: 0x20u);
  if ( v3 != nullptr )
  {
    v3->m_iCommand = 2;
    v3->m_pCachedRenderData = nullptr;
    v3->__vftable = (CScratchPad3D::CCommand_Polygon_vtbl *)&CScratchPad3D::CCommand_Polygon::`vftable';
    v3->m_Verts.m_Memory.m_pMemory = nullptr;
    v3->m_Verts.m_Memory.m_nAllocationCount = 0;
    v3->m_Verts.m_Memory.m_nGrowSize = 0;
    v3->m_Verts.m_Size = 0;
    v3->m_Verts.m_pElements = nullptr;
    cmd = v3;
  }
  else
  {
    cmd = nullptr;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CTCPPacket *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v7 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v7 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v7);
  v8 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v8 != nullptr )
    *v8 = cmd;
  CUtlVector<CSPVert,CUtlMemory<CSPVert,int>>::AddVectorToTail(this: &cmd->m_Verts, src: &verts->m_Verts);
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x100113E0
// Name: public: virtual void CScratchPad3D::DrawRectYZ(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectYZ(
        CScratchPad3D *this,
        float xPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v17 = xPos;
  v14 = xPos;
  v11 = xPos;
  pVerts.x = xPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.y = vMin->x;
  v12 = pVerts.y;
  v13 = vMax->y;
  v16 = v13;
  v21 = *vColor;
  pVerts.z = y;
  v15 = x;
  v18 = x;
  v19 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x10011490
// Name: public: virtual void CScratchPad3D::DrawRectXZ(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectXZ(
        CScratchPad3D *this,
        float yPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v18 = yPos;
  v15 = yPos;
  v12 = yPos;
  pVerts.y = yPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.x = vMin->x;
  v11 = pVerts.x;
  v13 = vMax->y;
  v16 = v13;
  v21 = *vColor;
  pVerts.z = y;
  v14 = x;
  v17 = x;
  v19 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x10011540
// Name: public: virtual void CScratchPad3D::DrawRectXY(float,class Vector2D const __near &,class Vector2D const __near &,class CSPColor const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawRectXY(
        CScratchPad3D *this,
        float zPos,
        const Vector2D *vMin,
        const Vector2D *vMax,
        const CSPColor *vColor)
{
  float y; // xmm1_4
  float x; // xmm2_4
  CScratchPad3D_vtbl *v8; // edi
  CSPVertList *v9; // eax
  Vector pVerts; // [esp+0h] [ebp-44h] BYREF
  float v11; // [esp+Ch] [ebp-38h]
  float v12; // [esp+10h] [ebp-34h]
  float v13; // [esp+14h] [ebp-30h]
  float v14; // [esp+18h] [ebp-2Ch]
  float v15; // [esp+1Ch] [ebp-28h]
  float v16; // [esp+20h] [ebp-24h]
  float v17; // [esp+24h] [ebp-20h]
  float v18; // [esp+28h] [ebp-1Ch]
  float v19; // [esp+2Ch] [ebp-18h]
  CSPVertList v20; // [esp+30h] [ebp-14h] BYREF
  CSPColor v21; // 0:^8.16

  y = vMin->y;
  v19 = zPos;
  v16 = zPos;
  v13 = zPos;
  pVerts.z = zPos;
  x = vMax->x;
  v8 = this->__vftable;
  pVerts.x = vMin->x;
  v11 = pVerts.x;
  v12 = vMax->y;
  v15 = v12;
  v21 = *vColor;
  pVerts.y = y;
  v14 = x;
  v17 = x;
  v18 = y;
  v9 = CSPVertList::CSPVertList(this: &v20, &pVerts, nVerts: 4, vColor: v21);
  v8->DrawPolygon(this, a2: v9);
  CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&v20);
}

//------------------------------------------------------------------------------
// Address: 0x100115F0
// Name: public: virtual void CScratchPad3D::SetRenderState(enum IScratchPad3D::RenderState,unsigned long)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::SetRenderState(
        CScratchPad3D *this,
        CScratchPad3D::CBaseCommand_vtbl *state,
        unsigned int val)
{
  _DWORD *v4; // eax
  CScratchPad3D::CBaseCommand *v5; // ebx
  int m_nAllocationCount; // eax
  int m_Size; // edi
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v9; // eax
  CScratchPad3D::CBaseCommand **v10; // eax

  v4 = operator new(size: 0x14u);
  v5 = nullptr;
  if ( v4 != nullptr )
  {
    v4[2] = 0;
    *((_BYTE *)v4 + 4) = 4;
    *v4 = &CScratchPad3D::CCommand_RenderState::`vftable';
    v5 = (CScratchPad3D::CBaseCommand *)v4;
  }
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  m_Size = this->m_Commands.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CTCPPacket *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v9 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v5;
  v5[1].__vftable = state;
  *(_DWORD *)&v5[1].m_iCommand = val;
}

//------------------------------------------------------------------------------
// Address: 0x10011690
// Name: public: void CScratchPad3D::DrawPolygonsForPixels(class SPRGBA __near *,int,int,int,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawPolygonsForPixels(
        CScratchPad3D *this,
        SPRGBA *pData,
        int width,
        int height,
        unsigned int pitchInBytes,
        Vector *vCorners)
{
  float v6; // xmm2_4
  float v7; // xmm1_4
  float z; // edx
  float x; // xmm7_4
  float v11; // ecx
  float v12; // xmm0_4
  float v13; // xmm3_4
  float v14; // xmm6_4
  float v15; // xmm5_4
  float v16; // xmm4_4
  float v17; // xmm3_4
  float y; // xmm1_4
  float v19; // xmm2_4
  float v20; // xmm4_4
  float v21; // xmm5_4
  float v22; // xmm6_4
  int v23; // edx
  SPRGBA *v24; // esi
  unsigned int v25; // eax
  const CSPVertList *v26; // eax
  CSPVert *m_pMemory; // eax
  bool v28; // sf
  bool v29; // zf
  CSPColor v30; // [esp-1Ch] [ebp-D8h]
  unsigned int v31; // [esp+Ch] [ebp-B0h]
  float vLeftInc; // [esp+10h] [ebp-ACh]
  float vLeftInc_4; // [esp+14h] [ebp-A8h]
  float vLeftInc_8; // [esp+18h] [ebp-A4h]
  float vBottomXInc; // [esp+1Ch] [ebp-A0h]
  float vBottomXInc_4; // [esp+20h] [ebp-9Ch]
  float vBottomXInc_8; // [esp+24h] [ebp-98h]
  float vRightInc; // [esp+28h] [ebp-94h]
  float vRightInc_4; // [esp+2Ch] [ebp-90h]
  float vRightInc_8; // [esp+30h] [ebp-8Ch]
  SPRGBA *v41; // [esp+34h] [ebp-88h]
  int v42; // [esp+38h] [ebp-84h]
  float vNextLeft; // [esp+3Ch] [ebp-80h]
  float vNextLeft_4; // [esp+40h] [ebp-7Ch]
  float vNextLeft_8; // [esp+44h] [ebp-78h]
  float vTopXInc; // [esp+48h] [ebp-74h]
  float vTopXInc_4; // [esp+4Ch] [ebp-70h]
  float vTopXInc_8; // [esp+50h] [ebp-6Ch]
  Vector vPolyBox[4]; // [esp+54h] [ebp-68h] BYREF
  CSPVertList v50; // [esp+84h] [ebp-38h] BYREF
  Vector vNextRight; // [esp+98h] [ebp-24h]
  Vector vCurRight; // [esp+A4h] [ebp-18h]
  Vector vCurLeft; // [esp+B0h] [ebp-Ch]
  int pitchInBytesa; // [esp+D0h] [ebp+14h]
  float vCornersa; // [esp+D4h] [ebp+18h]

  v6 = vCorners->x - vCorners[1].x;
  v7 = vCorners->z - vCorners[1].z;
  z = vCorners[2].z;
  *(_QWORD *)&vCurLeft.x = *(_QWORD *)&vCorners[1].x;
  x = vCurLeft.x;
  v11 = vCorners[1].z;
  *(_QWORD *)&vCurRight.x = *(_QWORD *)&vCorners[2].x;
  v12 = vCorners->y - vCorners[1].y;
  vCurLeft.z = v11;
  v13 = 1.0 / (float)height;
  v14 = v12 * v13;
  v15 = v13 * v6;
  vLeftInc_8 = v7 * v13;
  v16 = (float)(vCorners[3].z - vCorners[2].z) * v13;
  vRightInc_4 = (float)(vCorners[3].y - vCorners[2].y) * v13;
  v17 = v11;
  y = vCurLeft.y;
  v19 = vCurRight.x + (float)((float)(1.0 / (float)height) * (float)(vCorners[3].x - vCorners[2].x));
  vRightInc = (float)(1.0 / (float)height) * (float)(vCorners[3].x - vCorners[2].x);
  vRightInc_8 = v16;
  vLeftInc = v15;
  v20 = vCurLeft.x + v15;
  vLeftInc_4 = v14;
  v21 = vCurLeft.y + v14;
  vNextRight.y = vCurRight.y + vRightInc_4;
  vCurRight.z = z;
  v22 = v11 + vLeftInc_8;
  vNextLeft = v20;
  vNextLeft_4 = v21;
  vNextLeft_8 = v11 + vLeftInc_8;
  vNextRight.x = v19;
  vNextRight.z = z + vRightInc_8;
  if ( height > 0 )
  {
    v23 = width;
    v24 = pData;
    v25 = 4 * (pitchInBytes >> 2);
    vCornersa = 1.0 / (float)width;
    v31 = v25;
    v41 = pData;
    v42 = height;
    while ( 1 )
    {
      vPolyBox[0].y = y;
      vPolyBox[0].z = v17;
      vTopXInc_4 = (float)(vCurRight.y - y) * vCornersa;
      vBottomXInc_4 = (float)(vNextRight.y - v21) * vCornersa;
      vTopXInc_8 = (float)(vCurRight.z - v17) * vCornersa;
      vTopXInc = vCornersa * (float)(vCurRight.x - x);
      vPolyBox[1].x = vTopXInc + x;
      vPolyBox[1].y = vTopXInc_4 + vCurLeft.y;
      vPolyBox[1].z = vTopXInc_8 + vCurLeft.z;
      vBottomXInc = vCornersa * (float)(vNextRight.x - v20);
      vPolyBox[0].x = x;
      vPolyBox[3].x = v20;
      vPolyBox[3].y = v21;
      vPolyBox[3].z = v22;
      vBottomXInc_8 = (float)(vNextRight.z - v22) * vCornersa;
      vPolyBox[2].x = vBottomXInc + v20;
      vPolyBox[2].y = vBottomXInc_4 + v21;
      vPolyBox[2].z = vBottomXInc_8 + v22;
      if ( v23 > 0 )
      {
        pitchInBytesa = v23;
        do
        {
          if ( pData != nullptr )
          {
            v30.m_vColor.x = (float)v24->r * 0.0039200312;
            v30.m_vColor.y = (float)v24->g * 0.0039200312;
            v30.m_vColor.z = (float)v24->b * 0.0039200312;
          }
          else
          {
            *(_QWORD *)&v30.m_vColor.x = 0x3F8000003F800000LL;
            v30.m_vColor.z = 1.0;
          }
          v30.m_flAlpha = 1.0;
          v26 = CSPVertList::CSPVertList(this: &v50, pVerts: vPolyBox, nVerts: 4, vColor: v30);
          this->DrawPolygon(this, a2: v26);
          m_pMemory = v50.m_Verts.m_Memory.m_pMemory;
          v50.m_Verts.m_Size = 0;
          v28 = v50.m_Verts.m_Memory.m_nGrowSize < 0;
          if ( v50.m_Verts.m_Memory.m_nGrowSize >= 0 )
          {
            if ( v50.m_Verts.m_Memory.m_pMemory != nullptr )
            {
              _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v50.m_Verts.m_Memory.m_pMemory);
              m_pMemory = nullptr;
              v50.m_Verts.m_Memory.m_pMemory = nullptr;
            }
            v28 = v50.m_Verts.m_Memory.m_nGrowSize < 0;
            v50.m_Verts.m_Memory.m_nAllocationCount = 0;
          }
          v50.m_Verts.m_pElements = m_pMemory;
          if ( !v28 && m_pMemory != nullptr )
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
          vPolyBox[0].z = vPolyBox[0].z + vTopXInc_8;
          vPolyBox[1].y = vPolyBox[1].y + vTopXInc_4;
          vPolyBox[0].x = vPolyBox[0].x + vTopXInc;
          vPolyBox[1].x = vPolyBox[1].x + vTopXInc;
          vPolyBox[1].z = vPolyBox[1].z + vTopXInc_8;
          vPolyBox[3].x = vPolyBox[3].x + vBottomXInc;
          vPolyBox[0].y = vPolyBox[0].y + vTopXInc_4;
          vPolyBox[3].z = vPolyBox[3].z + vBottomXInc_8;
          vPolyBox[2].y = vPolyBox[2].y + vBottomXInc_4;
          ++v24;
          v29 = pitchInBytesa-- == 1;
          vPolyBox[3].y = vPolyBox[3].y + vBottomXInc_4;
          vPolyBox[2].x = vPolyBox[2].x + vBottomXInc;
          vPolyBox[2].z = vPolyBox[2].z + vBottomXInc_8;
        }
        while ( !v29 );
        x = vCurLeft.x;
        v20 = vNextLeft;
        v21 = vNextLeft_4;
        v22 = vNextLeft_8;
        v25 = v31;
        v23 = width;
      }
      x = x + vLeftInc;
      v20 = v20 + vLeftInc;
      v21 = v21 + vLeftInc_4;
      v22 = v22 + vLeftInc_8;
      vCurLeft.z = vCurLeft.z + vLeftInc_8;
      vCurRight.x = vCurRight.x + vRightInc;
      vCurLeft.y = vCurLeft.y + vLeftInc_4;
      vCurRight.z = vCurRight.z + vRightInc_8;
      vNextRight.y = vNextRight.y + vRightInc_4;
      v24 = (SPRGBA *)((char *)v41 + v25);
      v29 = v42-- == 1;
      vCurLeft.x = x;
      vNextLeft = v20;
      vNextLeft_4 = v21;
      vNextLeft_8 = v22;
      vCurRight.y = vCurRight.y + vRightInc_4;
      vNextRight.x = vNextRight.x + vRightInc;
      vNextRight.z = vNextRight.z + vRightInc_8;
      v41 = (SPRGBA *)((char *)v41 + v25);
      if ( v29 )
        break;
      v17 = vCurLeft.z;
      y = vCurLeft.y;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10011BF0
// Name: public: virtual void CScratchPad3D::DrawImageRGBA(class SPRGBA __near *,int,int,int,bool,bool,class Vector __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawImageRGBA(
        CScratchPad3D *this,
        SPRGBA *pData,
        int width,
        int height,
        unsigned int pitchInBytes,
        bool bOutlinePixels,
        bool bOutlineImage,
        Vector *vCorners)
{
  Vector *v8; // edi
  void (__thiscall *SetRenderState)(struct CScratchPad3D *, IScratchPad3D::RenderState, unsigned int); // eax
  CScratchPad3D_vtbl *v11; // ebx
  CSPVertList *v12; // eax
  CSPColor v13; // [esp-10h] [ebp-60h]
  Vector vDefaultCorners[4]; // [esp+Ch] [ebp-44h] BYREF
  CSPVertList v15; // [esp+3Ch] [ebp-14h] BYREF
  bool bOldAutoFlush_3; // [esp+73h] [ebp+23h]

  v8 = vCorners;
  if ( vCorners == nullptr )
  {
    v8 = vDefaultCorners;
    vDefaultCorners[0].x = -100.0;
    vDefaultCorners[0].y = -100.0;
    vDefaultCorners[0].z = 0.0;
    vDefaultCorners[1].x = -100.0;
    vDefaultCorners[1].y = 100.0;
    vDefaultCorners[1].z = 0.0;
    vDefaultCorners[2].x = 100.0;
    vDefaultCorners[2].y = 100.0;
    vDefaultCorners[2].z = 0.0;
    vDefaultCorners[3].x = 100.0;
    vDefaultCorners[3].y = -100.0;
    vDefaultCorners[3].z = 0.0;
  }
  bOldAutoFlush_3 = this->m_bAutoFlush;
  SetRenderState = this->SetRenderState;
  this->m_bAutoFlush = false;
  ((void (__stdcall *)(_DWORD, int))SetRenderState)(a1: 0, a2: 1);
  CScratchPad3D::DrawPolygonsForPixels(this, pData, width, height, pitchInBytes, vCorners: v8);
  if ( bOutlinePixels )
  {
    this->SetRenderState(this, a2: RS_FillMode, a3: 0);
    CScratchPad3D::DrawPolygonsForPixels(this, pData: nullptr, width, height, pitchInBytes, vCorners: v8);
  }
  if ( bOutlineImage )
  {
    this->SetRenderState(this, a2: RS_FillMode, a3: 0);
    v11 = this->__vftable;
    *(_QWORD *)&v15.m_Verts.m_Memory.m_nAllocationCount = 0x3F8000003F800000LL;
    *(_QWORD *)&v15.m_Verts.m_Size = 0x3F8000003F800000LL;
    *(_QWORD *)&v13.m_vColor.x = 0x3F8000003F800000LL;
    *(_QWORD *)&v13.m_vColor.z = 0x3F8000003F800000LL;
    v12 = CSPVertList::CSPVertList(this: &v15, pVerts: v8, nVerts: 4, vColor: v13);
    v11->DrawPolygon(this, a2: v12);
    CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>::~CUtlVector<dleafambientlighting_t,CUtlMemory<dleafambientlighting_t,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&v15);
  }
  this->m_bAutoFlush = bOldAutoFlush_3;
  if ( bOldAutoFlush_3 )
    this->Flush(this);
}

//------------------------------------------------------------------------------
// Address: 0x10011D30
// Name: public: virtual void CScratchPad3D::CCommand_Text::Read(class CFileRead __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::CCommand_Text::Read(CScratchPad3D::CCommand_Text *this, CFileRead *pFile)
{
  CFileRead *v2; // esi
  CFileRead *v4; // eax
  int v5; // ebx
  int m_nAllocationCount; // ecx
  char *m_pMemory; // edx
  int v8; // ecx

  v2 = pFile;
  v2->m_Pos += pFile->m_pFileSystem->Read(
                 this: &pFile->m_pFileSystem->IBaseFileSystem,
                 a2: &pFile,
                 a3: 4,
                 a4: pFile->m_fp);
  v4 = pFile;
  v5 = (int)pFile;
  this->m_String.m_Size = 0;
  if ( v5 != 0 )
  {
    m_nAllocationCount = this->m_String.m_Memory.m_nAllocationCount;
    if ( (int)v4 > m_nAllocationCount )
    {
      CUtlMemory<char,int>::Grow(
        this: (CUtlMemory<unsigned char,int> *)&this->m_String,
        num: (int)v4 - m_nAllocationCount);
      v4 = pFile;
    }
    this->m_String.m_Size += v5;
    m_pMemory = this->m_String.m_Memory.m_pMemory;
    v8 = this->m_String.m_Size - v5;
    this->m_String.m_pElements = m_pMemory;
    if ( v8 > 0 && v5 > 0 )
    {
      _V_memmove(dest: &m_pMemory[v5], src: m_pMemory, count: v8);
      v4 = pFile;
    }
  }
  v2->m_Pos += v2->m_pFileSystem->Read(
                 this: &v2->m_pFileSystem->IBaseFileSystem,
                 a2: this->m_String.m_Memory.m_pMemory,
                 a3: (int)v4,
                 a4: v2->m_fp);
  v2->m_Pos += v2->m_pFileSystem->Read(
                 this: &v2->m_pFileSystem->IBaseFileSystem,
                 a2: &this->m_TextParams,
                 a3: 56,
                 a4: v2->m_fp);
}

//------------------------------------------------------------------------------
// Address: 0x10011DE0
// Name: public: virtual void CScratchPad3D::DrawText(char const __near *,class CTextParams const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CScratchPad3D::DrawText(CScratchPad3D *this, const char *pStr, const CTextParams *params)
{
  CScratchPad3D::CCommand_Text *v4; // eax
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CScratchPad3D::CBaseCommand **m_pMemory; // ecx
  int v8; // eax
  CScratchPad3D::CBaseCommand **v9; // eax
  CScratchPad3D::CCommand_Text *cmd; // [esp+10h] [ebp-4h]

  v4 = (CScratchPad3D::CCommand_Text *)operator new(size: 0x58u);
  if ( v4 != nullptr )
  {
    v4->m_iCommand = 5;
    v4->m_pCachedRenderData = nullptr;
    v4->__vftable = (CScratchPad3D::CCommand_Text_vtbl *)&CScratchPad3D::CCommand_Text::`vftable';
    v4->m_String.m_Memory.m_pMemory = nullptr;
    v4->m_String.m_Memory.m_nAllocationCount = 0;
    v4->m_String.m_Memory.m_nGrowSize = 0;
    v4->m_String.m_Size = 0;
    v4->m_String.m_pElements = nullptr;
    v4->m_TextParams.m_vColor.x = 1.0;
    v4->m_TextParams.m_vColor.y = 1.0;
    v4->m_TextParams.m_vColor.z = 1.0;
    v4->m_TextParams.m_flAlpha = 1.0;
    *(_WORD *)&v4->m_TextParams.m_bSolidBackground = 257;
    v4->m_TextParams.m_vPos.x = 0.0;
    v4->m_TextParams.m_vPos.y = 0.0;
    v4->m_TextParams.m_vPos.z = 0.0;
    v4->m_TextParams.m_bCentered = true;
    v4->m_TextParams.m_vAngles.x = 0.0;
    v4->m_TextParams.m_vAngles.y = 0.0;
    v4->m_TextParams.m_vAngles.z = 0.0;
    v4->m_TextParams.m_bTwoSided = true;
    v4->m_TextParams.m_flLetterWidth = 3.0;
    cmd = v4;
  }
  else
  {
    cmd = nullptr;
  }
  m_Size = this->m_Commands.m_Size;
  m_nAllocationCount = this->m_Commands.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<int,int>::Grow(
      this: (CUtlMemory<CTCPPacket *,int> *)&this->m_Commands,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_Commands.m_Size;
  m_pMemory = this->m_Commands.m_Memory.m_pMemory;
  v8 = this->m_Commands.m_Size - m_Size - 1;
  this->m_Commands.m_pElements = m_pMemory;
  if ( v8 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v8);
  v9 = &this->m_Commands.m_Memory.m_pMemory[m_Size];
  if ( v9 != nullptr )
    *v9 = cmd;
  CUtlVector<char,CUtlMemory<char,int>>::CopyArray(this: &cmd->m_String, pArray: pStr, size: strlen(pStr) + 1);
  CTextParams::operator=(this: &cmd->m_TextParams, __that: params);
  if ( this->m_bAutoFlush )
    this->Flush(this);
}

} // namespace vvis_dll
