// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/expclass.cpp
// Functions: 21
// ============================================================

#include "utils\hlfaceposer\expclass.h"

//------------------------------------------------------------------------------
// Address: 0x00445780
// Name: public: char const __near * CExpClass::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CExpClass::GetFileName(CExpClass *this)
{
  return this->m_szFileName;
}

//------------------------------------------------------------------------------
// Address: 0x00445790
// Name: public: void CExpClass::SetFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::SetFileName(CExpClass *this, const char *filename)
{
  const char *v2; // eax
  int v3; // edx
  char v4; // cl

  v2 = filename;
  v3 = this->m_szFileName - filename;
  do
  {
    v4 = *v2;
    v2[v3] = *v2;
    ++v2;
  }
  while ( v4 != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x004457B0
// Name: public: bool CExpClass::GetDirty(void)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpClass::GetDirty(CExpClass *this)
{
  return this->m_bDirty;
}

//------------------------------------------------------------------------------
// Address: 0x004457C0
// Name: public: void CExpClass::SetDirty(bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::SetDirty(CExpClass *this, bool dirty)
{
  this->m_bDirty = dirty;
}

//------------------------------------------------------------------------------
// Address: 0x004457D0
// Name: public: void CExpClass::SelectExpression(int,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::SelectExpression(CExpClass *this, int num, bool deselect)
{
  this->m_nSelectedExpression = num;
  FlexPanel::setExpression(this: g_pFlexPanel, index: num);
  mxExpressionTray::Select(this: g_pExpressionTrayTool, exp: num, deselect);
  g_pExpressionTrayTool->redraw(this: g_pExpressionTrayTool);
}

//------------------------------------------------------------------------------
// Address: 0x00445810
// Name: public: int CExpClass::GetSelectedExpression(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpClass::GetSelectedExpression(CExpClass *this)
{
  return this->m_nSelectedExpression;
}

//------------------------------------------------------------------------------
// Address: 0x00445820
// Name: public: void CExpClass::DeselectExpression(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::DeselectExpression(CExpClass *this)
{
  this->m_nSelectedExpression = -1;
}

//------------------------------------------------------------------------------
// Address: 0x00445830
// Name: public: bool CExpClass::IsPhonemeClass(void)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CExpClass::IsPhonemeClass(CExpClass *this)
{
  return this->m_bIsPhonemeClass;
}

//------------------------------------------------------------------------------
// Address: 0x00445840
// Name: public: int CExpClass::GetNumExpressions(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExpClass::GetNumExpressions(CExpClass *this)
{
  return this->m_Expressions.m_Size;
}

//------------------------------------------------------------------------------
// Address: 0x00445A10
// Name: public: class CExpression __near * CExpClass::FindExpression(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpression *__thiscall CExpClass::FindExpression(CExpClass *this, const char *name)
{
  int v2; // ebx
  CExpression *v4; // esi
  int i; // [esp+Ch] [ebp-4h]

  v2 = 0;
  i = 0;
  if ( this->m_Expressions.m_Size <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = &this->m_Expressions.m_Memory.m_pMemory[v2];
    if ( _V_stricmp(s1: v4->name, s2: name) == 0 )
      break;
    ++v2;
    if ( ++i >= this->m_Expressions.m_Size )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00445A70
// Name: public: class CExpression __near * CExpClass::GetExpression(int)
// Source: json
//------------------------------------------------------------------------------
CExpression *__thiscall CExpClass::GetExpression(CExpClass *this, int num)
{
  if ( num < 0 || num >= this->m_Expressions.m_Size )
    return nullptr;
  else
    return &this->m_Expressions.m_Memory.m_pMemory[num];
}

//------------------------------------------------------------------------------
// Address: 0x00445F60
// Name: public: void CExpClass::Export(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::Export(CExpClass *this)
{
  int m_Size; // eax
  int v3; // ebx
  CExpression *v4; // esi
  float *Weights; // ecx
  int v6; // eax
  void *v7; // esi
  int v8; // eax
  unsigned int v9; // ebx
  flexsetting_t *v10; // edi
  CExpression *v11; // ecx
  unsigned int v12; // eax
  unsigned int v13; // esi
  float *v14; // eax
  int v15; // ecx
  float *v16; // edx
  float *v17; // ebx
  float v18; // xmm1_4
  float *v19; // eax
  double v20; // st7
  float v21; // xmm1_4
  float *v22; // eax
  double v23; // st7
  float v24; // xmm1_4
  float *v25; // eax
  double v26; // st7
  float v27; // xmm1_4
  float *v28; // eax
  double v29; // st7
  unsigned int v30; // esi
  int v31; // ebx
  float *v32; // eax
  flexsettinghdr_t *v33; // edx
  int v34; // ecx
  int numflexsettings; // edi
  int *p_index; // eax
  int v37; // eax
  char *v38; // esi
  int v39; // eax
  int *v40; // ecx
  bool v41; // cc
  const char *v42; // eax
  int v43; // eax
  unsigned int v44; // ebx
  unsigned int v45; // esi
  int v46; // edi
  int v47; // ebx
  const char *GlobalFlexControllerName; // eax
  unsigned int v49; // edx
  char v50; // cl
  unsigned __int8 *v51; // ebx
  int v52; // ecx
  unsigned int v53; // edx
  flexsettinghdr_t *v54; // esi
  _BYTE *v55; // edi
  char *v56; // edx
  void *v57; // esi
  char relative[512]; // [esp+Ch] [ebp-630h] BYREF
  char vfefilename[512]; // [esp+20Ch] [ebp-430h] BYREF
  int flexmap[128]; // [esp+40Ch] [ebp-230h] BYREF
  int v61; // [esp+60Ch] [ebp-30h]
  float *v62; // [esp+610h] [ebp-2Ch]
  CExpClass *v63; // [esp+614h] [ebp-28h]
  flexsetting_t *pSetting; // [esp+618h] [ebp-24h]
  unsigned __int8 *pDataStart; // [esp+61Ch] [ebp-20h]
  int v66; // [esp+620h] [ebp-1Ch]
  flexsettinghdr_t *fhdr; // [esp+624h] [ebp-18h]
  int fc_count; // [esp+628h] [ebp-14h]
  int numflexmaps; // [esp+62Ch] [ebp-10h]
  CExpression *expr; // [esp+630h] [ebp-Ch]
  float *settings; // [esp+634h] [ebp-8h]
  int i; // [esp+638h] [ebp-4h]

  v63 = this;
  V_StripExtension(in: this->m_szFileName, out: vfefilename, outSize: 512);
  V_DefaultExtension(path: vfefilename, extension: ".vfe", pathStringLength: 512);
  Con_Printf(fmt: "Exporting %s to %s\n", this->m_szClassName, vfefilename);
  numflexmaps = 0;
  fc_count = GetGlobalFlexControllerCount();
  for ( i = 0; i < fc_count; ++i )
  {
    m_Size = this->m_Expressions.m_Size;
    v3 = 0;
    if ( m_Size > 0 )
    {
      fhdr = nullptr;
      while ( 1 )
      {
        v4 = v3 < 0 || v3 >= m_Size
           ? nullptr
           : (CExpression *)((char *)fhdr + (unsigned int)this->m_Expressions.m_Memory.m_pMemory);
        settings = CExpression::GetSettings(this: v4);
        Weights = CExpression::GetWeights(this: v4);
        if ( settings[i] != 0.0 || Weights[i] != 0.0 )
          break;
        m_Size = this->m_Expressions.m_Size;
        fhdr = (flexsettinghdr_t *)((char *)fhdr + 3652);
        if ( ++v3 >= m_Size )
          goto LABEL_13;
      }
      v6 = numflexmaps;
      flexmap[numflexmaps] = i;
      numflexmaps = v6 + 1;
    }
LABEL_13:
    ;
  }
  v7 = calloc(count: 0x100000u, size: 1u);
  pDataStart = (unsigned __int8 *)v7;
  fhdr = (flexsettinghdr_t *)v7;
  *(_DWORD *)v7 = (char *)&g_flexages[31559] + 1;
  *((_DWORD *)v7 + 1) = 0;
  V_strncpy(pDest: (char *)v7 + 8, pSrc: vfefilename, maxLen: 64);
  v8 = this->m_Expressions.m_Size;
  *((_DWORD *)v7 + 19) = v8;
  pSetting = (flexsetting_t *)(((unsigned int)v7 + 111) & 0xFFFFFFFC);
  v9 = ((unsigned int)&pSetting[v8].nameindex + 3) & 0xFFFFFFFC;
  *((_DWORD *)v7 + 20) = (char *)pSetting - (_BYTE *)v7;
  i = 0;
  if ( v8 > 0 )
  {
    v10 = pSetting;
    fc_count = 0;
    v66 = 0;
    do
    {
      if ( i < 0 || i >= v63->m_Expressions.m_Size )
        expr = nullptr;
      else
        expr = (CExpression *)((char *)v63->m_Expressions.m_Memory.m_pMemory + v66);
      v11 = expr;
      v12 = v9 - fc_count;
      v10->index = expr->index;
      v13 = v9;
      v10->settingindex = v12 - (_DWORD)pSetting;
      v62 = CExpression::GetSettings(this: v11);
      v14 = CExpression::GetWeights(this: expr);
      v15 = 0;
      v16 = v14;
      if ( numflexmaps >= 4 )
      {
        v61 = numflexmaps - 3;
        expr = (CExpression *)(v9 + 3);
        do
        {
          v17 = v62;
          v18 = v62[flexmap[v15]];
          settings = (float *)(4 * flexmap[v15]);
          if ( v18 != 0.0 || *(float *)((char *)v16 + (_DWORD)settings) != 0.0 )
          {
            ++v10->numsettings;
            v19 = settings;
            *(_DWORD *)v13 = v15;
            *(float *)(v13 + 4) = *(float *)((char *)v17 + (_DWORD)v19);
            v13 += 12;
            v20 = *(float *)((char *)v16 + (_DWORD)v19);
            expr = (CExpression *)((char *)expr + 12);
            *(float *)(v13 - 4) = v20;
          }
          v21 = v17[flexmap[v15 + 1]];
          settings = (float *)(4 * flexmap[v15 + 1]);
          if ( v21 != 0.0 || *(float *)((char *)v16 + (_DWORD)settings) != 0.0 )
          {
            ++v10->numsettings;
            *(_DWORD *)v13 = v15 + 1;
            v22 = settings;
            v23 = *(float *)((char *)v17 + (_DWORD)settings);
            v13 += 12;
            expr = (CExpression *)((char *)expr + 12);
            *(float *)(v13 - 8) = v23;
            *(float *)(v13 - 4) = *(float *)((char *)v16 + (_DWORD)v22);
          }
          v24 = v17[flexmap[v15 + 2]];
          settings = (float *)(4 * flexmap[v15 + 2]);
          if ( v24 != 0.0 || *(float *)((char *)v16 + (_DWORD)settings) != 0.0 )
          {
            ++v10->numsettings;
            *(_DWORD *)v13 = v15 + 2;
            v25 = settings;
            v26 = *(float *)((char *)v17 + (_DWORD)settings);
            v13 += 12;
            expr = (CExpression *)((char *)expr + 12);
            *(float *)(v13 - 8) = v26;
            *(float *)(v13 - 4) = *(float *)((char *)v16 + (_DWORD)v25);
          }
          v27 = v17[flexmap[v15 + 3]];
          settings = (float *)(4 * flexmap[v15 + 3]);
          if ( v27 != 0.0 || *(float *)((char *)v16 + (_DWORD)settings) != 0.0 )
          {
            ++v10->numsettings;
            *(_DWORD *)v13 = v15 + 3;
            v28 = settings;
            v29 = *(float *)((char *)v17 + (_DWORD)settings);
            v13 += 12;
            expr = (CExpression *)((char *)expr + 12);
            *(float *)(v13 - 8) = v29;
            *(float *)(v13 - 4) = *(float *)((char *)v16 + (_DWORD)v28);
          }
          v15 += 4;
          v9 = (unsigned int)expr & 0xFFFFFFFC;
        }
        while ( v15 < v61 );
      }
      if ( v15 < numflexmaps )
      {
        v30 = v13 + 8;
        do
        {
          v31 = flexmap[v15];
          if ( v62[v31] != 0.0 || v16[v31] != 0.0 )
          {
            ++v10->numsettings;
            v32 = v62;
            *(_DWORD *)(v30 - 8) = v15;
            *(float *)(v30 - 4) = v32[v31];
            v30 += 12;
            *(float *)(v30 - 12) = v16[v31];
          }
          ++v15;
          v9 = (v30 - 5) & 0xFFFFFFFC;
        }
        while ( v15 < numflexmaps );
      }
      v66 += 3652;
      fc_count += 24;
      ++v10;
      ++i;
    }
    while ( i < fhdr->numflexsettings );
  }
  v33 = fhdr;
  v34 = 1;
  if ( fhdr->numflexsettings > 0 )
  {
    numflexsettings = fhdr->numflexsettings;
    p_index = &pSetting->index;
    do
    {
      if ( *p_index >= v34 )
        v34 = *p_index + 1;
      p_index += 6;
      --numflexsettings;
    }
    while ( numflexsettings != 0 );
  }
  v37 = v9 - (_DWORD)pDataStart;
  v38 = (char *)((v9 + 4 * v34 + 3) & 0xFFFFFFFC);
  fhdr->numindexes = v34;
  v33->indexindex = v37;
  if ( v34 > 0 )
    memset((void *)v9, 0xFFu, 4 * v34);
  v39 = 0;
  if ( v33->numflexsettings > 0 )
  {
    v40 = &pSetting->index;
    do
    {
      *(_DWORD *)(v9 + 4 * *v40) = v39++;
      v40 += 6;
    }
    while ( v39 < v33->numflexsettings );
  }
  v41 = v33->numflexsettings <= 0;
  i = 0;
  if ( !v41 )
  {
    v66 = 0;
    fc_count = 0;
    do
    {
      if ( i < 0 || i >= v63->m_Expressions.m_Size )
        v42 = nullptr;
      else
        v42 = &v63->m_Expressions.m_Memory.m_pMemory->name[fc_count];
      *(int *)((char *)&pSetting->nameindex + v66) = &v38[-v66] - (char *)pSetting;
      strcpy(v38, v42);
      fc_count += 3652;
      v66 += 24;
      v38 += strlen(v42) + 1;
      ++i;
    }
    while ( i < v33->numflexsettings );
  }
  v43 = numflexmaps;
  v44 = (unsigned int)(v38 + 3) & 0xFFFFFFFC;
  v33->keynameindex = v44 - (_DWORD)pDataStart;
  v45 = 4 * v43 + v44;
  v46 = 0;
  v33->numkeys = v43;
  v63 = (CExpClass *)(4 * v43);
  if ( v43 > 0 )
  {
    v61 = v44 - (_DWORD)flexmap;
    do
    {
      v47 = flexmap[v46];
      *(int *)((char *)&flexmap[v46] + v61) = v45 - (_DWORD)pDataStart;
      GlobalFlexControllerName = GetGlobalFlexControllerName(index: v47);
      v49 = v45 - (_DWORD)GlobalFlexControllerName;
      do
      {
        v50 = *GlobalFlexControllerName;
        GlobalFlexControllerName[v49] = *GlobalFlexControllerName;
        ++GlobalFlexControllerName;
      }
      while ( v50 != 0 );
      ++v46;
      v45 += strlen(GetGlobalFlexControllerName(index: v47)) + 1;
    }
    while ( v46 < numflexmaps );
  }
  v51 = pDataStart;
  v52 = numflexmaps;
  v53 = v45 + 3;
  v54 = fhdr;
  v55 = (_BYTE *)(v53 & 0xFFFFFFFC);
  v56 = (char *)v63 + (v53 & 0xFFFFFFFC);
  fhdr->keymappingindex = v55 - pDataStart;
  if ( v52 > 0 )
    memset(v55, 0xFFu, 4 * v52);
  v54->length = ((unsigned int)(v56 + 3) & 0xFFFFFFFC) - (_DWORD)v51;
  filesystem->FullPathToRelativePath(this: filesystem, a2: vfefilename, a3: relative, a4: 512);
  MakeFileWriteable(filename: relative);
  v57 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: relative, a3: "wb", a4: 0);
  if ( v57 != nullptr )
  {
    filesystem->Write(this: &filesystem->IBaseFileSystem, a2: v51, a3: fhdr->length, a4: v57);
    filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v57);
  }
  else
  {
    Con_ErrorPrintf(fmt: "Unable to write to %s (read-only?)\n", relative);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00446550
// Name: public: void CExpClass::ReloadBitmaps(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::ReloadBitmaps(CExpClass *this)
{
  CExpClass *v1; // esi
  int v2; // edi
  int m_Size; // eax
  int v4; // ebx
  CExpression *v5; // esi
  mxbitmapdata_t *v6; // edi
  const char *BitmapFilename; // eax
  int c; // [esp+10h] [ebp-14h]
  int v10; // [esp+14h] [ebp-10h]
  int i; // [esp+18h] [ebp-Ch]
  int model; // [esp+1Ch] [ebp-8h]
  bool bUsingPerPlayerOverrides; // [esp+23h] [ebp-1h]

  v1 = this;
  bUsingPerPlayerOverrides = IsUsingPerPlayerExpressions();
  v2 = 0;
  c = models->Count(this: models);
  model = 0;
  for ( i = 164; i < 420; i += 16 )
  {
    if ( !bUsingPerPlayerOverrides || v2 == models->GetActiveModelIndex(this: models) )
    {
      models->ForceActiveModelIndex(this: models, a2: v2);
      m_Size = v1->m_Expressions.m_Size;
      v4 = 0;
      if ( m_Size > 0 )
      {
        v10 = 0;
        do
        {
          if ( v4 >= 0 && v4 < m_Size )
          {
            v5 = &v1->m_Expressions.m_Memory.m_pMemory[v10];
            if ( v5 != nullptr )
            {
              v6 = (mxbitmapdata_t *)&v5->name[i];
              if ( v5->name[i] != 0 )
              {
                DeleteObject(ho: *(HGDIOBJ *)&v5->name[i + 4]);
                v6->valid = false;
              }
              if ( model < c )
              {
                BitmapFilename = CExpression::GetBitmapFilename(this: v5, modelindex: model);
                if ( !LoadBitmapFromFile(relative: BitmapFilename, bitmap: v6) )
                  CExpression::CreateNewBitmap(this: v5, modelindex: model);
              }
            }
          }
          v1 = this;
          m_Size = this->m_Expressions.m_Size;
          ++v10;
          ++v4;
        }
        while ( v4 < m_Size );
        v2 = model;
      }
    }
    model = ++v2;
  }
  models->UnForceActiveModelIndex(this: models);
}

//------------------------------------------------------------------------------
// Address: 0x00446660
// Name: public: void CExpClass::DeleteExpression(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::DeleteExpression(CExpClass *this, const char *name)
{
  int v3; // ebx
  int i; // edi

  v3 = 0;
  if ( this->m_Expressions.m_Size > 0 )
  {
    for ( i = 0; _V_stricmp(s1: this->m_Expressions.m_Memory.m_pMemory[i].name, s2: name) != 0; ++i )
    {
      if ( ++v3 >= this->m_Expressions.m_Size )
        return;
    }
    this->m_bDirty = true;
    CExpression::~CExpression(this: &this->m_Expressions.m_Memory.m_pMemory[v3]);
    if ( this->m_Expressions.m_Size - v3 - 1 > 0 )
      _V_memmove(
        dest: &this->m_Expressions.m_Memory.m_pMemory[v3],
        src: &this->m_Expressions.m_Memory.m_pMemory[v3 + 1],
        count: 3652 * (this->m_Expressions.m_Size - v3 - 1));
    --this->m_Expressions.m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00446FD0
// Name: public: void CExpClass::Save(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::Save(CExpClass *this)
{
  CExpClass *v1; // edi
  StudioModel *(__thiscall *GetActiveStudioModel)(IFaceposerModels *); // edx
  int v3; // esi
  _DWORD *v4; // eax
  const studiohdr_t *v5; // eax
  _DWORD *v6; // esi
  int v7; // ebx
  int v8; // eax
  CExpression *v9; // esi
  float *Settings; // ebx
  float *v11; // eax
  int v12; // eax
  int k; // esi
  const char *GlobalFlexControllerName; // eax
  int v15; // eax
  CExpression *v16; // edi
  float *v17; // ebx
  int v18; // esi
  const char *v19; // eax
  void *v20; // eax
  void *v21; // esi
  int v22; // ebx
  CExpression *v23; // esi
  int index; // [esp+10h] [ebp-458h]
  int flexmap[128]; // [esp+20h] [ebp-448h]
  char relative[512]; // [esp+220h] [ebp-248h] BYREF
  CUtlBuffer buf; // [esp+420h] [ebp-48h] BYREF
  unsigned int v28; // [esp+450h] [ebp-18h]
  float *weights; // [esp+454h] [ebp-14h]
  int numflexmaps; // [esp+458h] [ebp-10h]
  int j; // [esp+45Ch] [ebp-Ch]
  int i; // [esp+460h] [ebp-8h]
  CExpClass *v33; // [esp+464h] [ebp-4h]

  v1 = this;
  GetActiveStudioModel = models->GetActiveStudioModel;
  v33 = this;
  v3 = (int)GetActiveStudioModel(this: models);
  v4 = *(_DWORD **)(v3 + 16);
  if ( v4 != nullptr )
  {
    if ( *v4 == 0 )
    {
      v5 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: *(unsigned __int16 *)(v3 + 424));
      CStudioHdr::Init(this: *(CStudioHdr **)(v3 + 16), pStudioHdr: v5, mdlcache: nullptr);
      v6 = *(_DWORD **)(v3 + 16);
      if ( *v6 == 0 )
        return;
      v4 = v6;
    }
    if ( v4 != nullptr && v1 != (CExpClass *)-260 && v1->m_szFileName[0] != 0 )
    {
      Con_Printf(fmt: "Saving changes to %s to file %s\n", v1->m_szClassName, v1->m_szFileName);
      CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
      v7 = 0;
      numflexmaps = 0;
      weights = (float *)GetGlobalFlexControllerCount();
      j = 0;
      if ( (int)weights > 0 )
      {
        do
        {
          v8 = 0;
          i = 0;
          if ( v1->m_Expressions.m_Size > 0 )
          {
            v28 = 0;
            while ( 1 )
            {
              v9 = v8 < 0 || v8 >= v1->m_Expressions.m_Size
                 ? nullptr
                 : &v1->m_Expressions.m_Memory.m_pMemory[v28 / 0xE44];
              Settings = CExpression::GetSettings(this: v9);
              v11 = CExpression::GetWeights(this: v9);
              if ( Settings[j] != 0.0 || v11[j] != 0.0 )
                break;
              v28 += 3652;
              if ( ++i >= v1->m_Expressions.m_Size )
                goto LABEL_21;
              v8 = i;
            }
            v12 = numflexmaps;
            flexmap[numflexmaps] = j;
            numflexmaps = v12 + 1;
          }
LABEL_21:
          ++j;
        }
        while ( j < (int)weights );
        v7 = numflexmaps;
      }
      CUtlBuffer::Printf(this: &buf, pFmt: "$keys");
      for ( k = 0; k < v7; ++k )
      {
        GlobalFlexControllerName = GetGlobalFlexControllerName(index: flexmap[k]);
        CUtlBuffer::Printf(this: &buf, pFmt: " %s", GlobalFlexControllerName);
      }
      CUtlBuffer::Printf(this: &buf, pFmt: "\n");
      CUtlBuffer::Printf(this: &buf, pFmt: "$hasweighting\n");
      v15 = 0;
      i = 0;
      if ( v1->m_Expressions.m_Size > 0 )
      {
        j = 0;
        while ( 1 )
        {
          if ( v15 < 0 || v15 >= v1->m_Expressions.m_Size )
            v16 = nullptr;
          else
            v16 = (CExpression *)((char *)v1->m_Expressions.m_Memory.m_pMemory + j);
          CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\" ", v16->name);
          index = v16->index;
          if ( index > 122 )
            CUtlBuffer::Printf(this: &buf, pFmt: "\"0x%04x\" ", index);
          else
            CUtlBuffer::Printf(this: &buf, pFmt: "\"%c\" ", index);
          v17 = CExpression::GetSettings(this: v16);
          v18 = 0;
          for ( weights = CExpression::GetWeights(this: v16); v18 < numflexmaps; ++v18 )
            CUtlBuffer::Printf(this: &buf, pFmt: "%.3f %.3f ", v17[flexmap[v18]], weights[flexmap[v18]]);
          if ( _V_strstr(s1: v16->name, search: "Right Side Smile") != nullptr )
          {
            v19 = CExpression::GetBitmapCheckSum(this: v16);
            Con_Printf(fmt: "wrote %s with checksum %s\n", v16->name, v19);
          }
          CUtlBuffer::Printf(this: &buf, pFmt: "\"%s\"\n", v16->description);
          j += 3652;
          ++i;
          v1 = v33;
          if ( i >= v33->m_Expressions.m_Size )
            break;
          v15 = i;
        }
      }
      filesystem->FullPathToRelativePath(this: filesystem, a2: v1->m_szFileName, a3: relative, a4: 512);
      MakeFileWriteable(filename: relative);
      v20 = filesystem->Open(this: &filesystem->IBaseFileSystem, a2: relative, a3: "wt", a4: 0);
      v21 = v20;
      if ( v20 != nullptr )
      {
        filesystem->Write(this: &filesystem->IBaseFileSystem, a2: buf.m_Memory.m_pMemory, a3: buf.m_Put, a4: v20);
        filesystem->Close(this: &filesystem->IBaseFileSystem, a2: v21);
        v22 = 0;
        v1->m_bDirty = false;
        if ( v1->m_Expressions.m_Size > 0 )
        {
          v33 = nullptr;
          do
          {
            if ( v22 >= 0 && v22 < v1->m_Expressions.m_Size )
            {
              v23 = (CExpression *)((char *)v33 + (unsigned int)v1->m_Expressions.m_Memory.m_pMemory);
              if ( v23 != nullptr )
              {
                CExpression::ResetUndo(this: v23);
                CExpression::SetDirty(this: v23, dirty: false);
              }
            }
            v33 = (CExpClass *)((char *)v33 + 3652);
            ++v22;
          }
          while ( v22 < v1->m_Expressions.m_Size );
        }
      }
      else
      {
        Con_ErrorPrintf(fmt: "Unable to write to %s (read-only?)\n", relative);
      }
      if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
        _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004473C0
// Name: public: void CExpClass::SwapExpressionOrder(int,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::SwapExpressionOrder(CExpClass *this, int exp1, int exp2)
{
  CUtlVector<CExpression,CUtlMemory<CExpression,int> > *p_m_Expressions; // esi
  int v4; // ebx
  CExpression v5; // [esp+Ch] [ebp-1C88h] BYREF
  CExpression src; // [esp+E50h] [ebp-E44h] BYREF

  p_m_Expressions = &this->m_Expressions;
  CExpression::CExpression(this: &v5, from: &this->m_Expressions.m_Memory.m_pMemory[exp1]);
  v4 = exp2;
  CExpression::CExpression(this: &src, from: &p_m_Expressions->m_Memory.m_pMemory[exp2]);
  CExpression::~CExpression(this: &p_m_Expressions->m_Memory.m_pMemory[exp1]);
  if ( p_m_Expressions->m_Size - exp1 - 1 > 0 )
    _V_memmove(
      dest: &p_m_Expressions->m_Memory.m_pMemory[exp1],
      src: &p_m_Expressions->m_Memory.m_pMemory[exp1 + 1],
      count: 3652 * (p_m_Expressions->m_Size - exp1 - 1));
  --p_m_Expressions->m_Size;
  CUtlVector<CExpression,CUtlMemory<CExpression,int>>::InsertBefore(this: p_m_Expressions, elem: exp1, &src);
  CExpression::~CExpression(this: &p_m_Expressions->m_Memory.m_pMemory[v4]);
  if ( p_m_Expressions->m_Size - exp2 - 1 > 0 )
    _V_memmove(
      dest: &p_m_Expressions->m_Memory.m_pMemory[v4],
      src: &p_m_Expressions->m_Memory.m_pMemory[v4 + 1],
      count: 3652 * (p_m_Expressions->m_Size - exp2 - 1));
  --p_m_Expressions->m_Size;
  CUtlVector<CExpression,CUtlMemory<CExpression,int>>::InsertBefore(this: p_m_Expressions, elem: exp2, src: &v5);
  CExpression::~CExpression(this: &src);
  CExpression::~CExpression(this: &v5);
}

//------------------------------------------------------------------------------
// Address: 0x004474B0
// Name: public: CExpClass::CExpClass(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CExpClass *__thiscall CExpClass::CExpClass(CExpClass *this, const char *classname)
{
  char *m_szClassName; // edi

  this->__vftable = (CExpClass_vtbl *)&CExpClass::`vftable';
  m_szClassName = this->m_szClassName;
  this->m_Expressions.m_Memory.m_pMemory = nullptr;
  this->m_Expressions.m_Memory.m_nAllocationCount = 0;
  this->m_Expressions.m_Memory.m_nGrowSize = 0;
  this->m_Expressions.m_Size = 0;
  this->m_Expressions.m_pElements = nullptr;
  V_strncpy(pDest: this->m_szClassName, pSrc: classname, maxLen: 128);
  V_FileBase(in: m_szClassName, out: this->m_szBaseName, maxlen: 128);
  this->m_szFileName[0] = 0;
  this->m_bDirty = false;
  this->m_nSelectedExpression = -1;
  this->m_bIsPhonemeClass = _V_strstr(s1: classname, search: "phonemes") != nullptr;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00447540
// Name: public: class CExpression __near * CExpClass::AddExpression(char const __near *,char const __near *,float __near *,float __near *,bool,bool)
// Source: json
//------------------------------------------------------------------------------
CExpression *__thiscall CExpClass::AddExpression(
        CExpClass *this,
        const char *name,
        const char *description,
        float *flexsettings,
        float *flexweights,
        bool selectnewitem,
        bool bDirtyClass)
{
  StudioModel *v8; // esi
  CStudioHdr *m_pStudioHdr; // eax
  const studiohdr_t *v10; // eax
  CStudioHdr *v11; // esi
  int v13; // eax
  CExpression *v14; // ebx
  int v15; // eax
  const char *BitmapFilename; // eax
  int v17; // eax
  mxbitmapdata_t *v18; // [esp-8h] [ebp-20h]
  int idx; // [esp+8h] [ebp-10h]
  float *weights; // [esp+Ch] [ebp-Ch]
  float *settings; // [esp+10h] [ebp-8h]

  v8 = models->GetActiveStudioModel(this: models);
  m_pStudioHdr = v8->m_pStudioHdr;
  if ( m_pStudioHdr == nullptr )
    return nullptr;
  if ( m_pStudioHdr->m_pStudioHdr == nullptr )
  {
    v10 = (const studiohdr_t *)((int (__stdcall *)(_DWORD))g_pMDLCache->GetStudioHdr)(a1: v8->m_MDLHandle);
    CStudioHdr::Init(this: v8->m_pStudioHdr, pStudioHdr: v10, mdlcache: nullptr);
    v11 = v8->m_pStudioHdr;
    if ( v11->m_pStudioHdr == nullptr )
      return nullptr;
    m_pStudioHdr = v11;
  }
  if ( m_pStudioHdr == nullptr )
    return nullptr;
  if ( CExpClass::FindExpression(this, name) != nullptr )
  {
    Con_ErrorPrintf(fmt: "Can't create, an expression with the name '%s' already exists.\n", name);
    return nullptr;
  }
  else
  {
    v13 = CUtlVector<CExpression,CUtlMemory<CExpression,int>>::InsertBefore(
            this: &this->m_Expressions,
            elem: this->m_Expressions.m_Size);
    v14 = &this->m_Expressions.m_Memory.m_pMemory[v13];
    idx = v13;
    settings = CExpression::GetSettings(this: v14);
    weights = CExpression::GetWeights(this: v14);
    CExpression::SetExpressionClass(this: v14, classname: this->m_szClassName);
    strcpy(v14->name, name);
    strcpy(v14->description, description);
    qmemcpy(settings, flexsettings, 0x600u);
    qmemcpy(weights, flexweights, 0x600u);
    v14->index = 95;
    if ( this->m_bIsPhonemeClass )
      v14->index = TextToPhoneme(text: name);
    v14->m_Bitmap[models->GetActiveModelIndex(this: models)].valid = false;
    v18 = &v14->m_Bitmap[models->GetActiveModelIndex(this: models)];
    v15 = models->GetActiveModelIndex(this: models);
    BitmapFilename = CExpression::GetBitmapFilename(this: v14, modelindex: v15);
    if ( !LoadBitmapFromFile(relative: BitmapFilename, bitmap: v18) )
    {
      v17 = models->GetActiveModelIndex(this: models);
      CExpression::CreateNewBitmap(this: v14, modelindex: v17);
    }
    if ( selectnewitem )
      CExpClass::SelectExpression(this, num: idx, deselect: true);
    if ( bDirtyClass )
      this->m_bDirty = true;
    return v14;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447780
// Name: private: void CExpClass::BuildValidChecksums(class CUtlRBTree<unsigned long,unsigned short,bool (*)(unsigned long const __near &,unsigned long const __near &),class CUtlMemory<struct UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __userpurge CExpClass::BuildValidChecksums(
        CExpClass *this@<ecx>,
        char *p_m_Data@<edi>,
        CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *tree)
{
  CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *v3; // esi
  CExpression *v4; // eax
  unsigned __int16 v5; // ax
  unsigned __int16 v6; // dx
  unsigned __int16 v7; // cx
  int v8; // edi
  UtlRBTreeNode_t<unsigned long,unsigned short> *v9; // eax
  int v10; // edx
  UtlRBTreeNode_t<unsigned long,unsigned short> *m_pMemory; // eax
  UtlRBTreeNode_t<unsigned long,unsigned short> *v12; // ecx
  int i; // [esp+4h] [ebp-14h]
  CExpClass *v14; // [esp+8h] [ebp-10h]
  unsigned int crc; // [esp+Ch] [ebp-Ch] BYREF
  unsigned __int16 parent[2]; // [esp+10h] [ebp-8h] BYREF
  unsigned int v17; // [esp+14h] [ebp-4h]

  v14 = this;
  i = 0;
  if ( this->m_Expressions.m_Size > 0 )
  {
    v3 = tree;
    v17 = 0;
    do
    {
      v4 = &this->m_Expressions.m_Memory.m_pMemory[v17 / 0xE44];
      if ( v4 != nullptr )
      {
        crc = CExpression::GetBitmapCRC(this: v4);
        *(_DWORD *)parent = 0xFFFF;
        HIBYTE(tree) = 0;
        CUtlRBTree<unsigned long,unsigned short,bool (__cdecl *)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>>::FindInsertionPosition(
          this: v3,
          insert: &crc,
          parent,
          leftchild: (bool *)&tree + 3);
        v5 = CUtlRBTree<CChoreoEventWidget *,unsigned short,bool (__cdecl *)(CChoreoEventWidget * const &,CChoreoEventWidget * const &),CUtlMemory<UtlRBTreeNode_t<CChoreoEventWidget *,unsigned short>,unsigned short>>::NewNode(
               this: (CUtlRBTree<CUtlSymbolTable::CStringPoolIndex,unsigned short,CUtlSymbolTable::CLess,CUtlMemory<UtlRBTreeNode_t<CUtlSymbolTable::CStringPoolIndex,unsigned short>,unsigned short> > *)v3,
               a2: p_m_Data);
        v6 = parent[0];
        v7 = v5;
        v8 = v5;
        v9 = &v3->m_Elements.m_pMemory[v8];
        v9->m_Right = -1;
        v9->m_Left = -1;
        v9->m_Parent = v6;
        v9->m_Tag = 0;
        if ( v6 == 0xFFFF )
        {
          v3->m_Root = v7;
        }
        else
        {
          v10 = v6;
          m_pMemory = v3->m_Elements.m_pMemory;
          if ( HIBYTE(tree) != 0 )
            m_pMemory[v10].m_Left = v7;
          else
            m_pMemory[v10].m_Right = v7;
        }
        CUtlRBTree<unsigned long,unsigned short,bool (__cdecl *)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>>::InsertRebalance(
          this: v3,
          elem: v7);
        v12 = v3->m_Elements.m_pMemory;
        ++v3->m_NumElements;
        p_m_Data = (char *)&v12[v8].m_Data;
        this = v14;
        if ( p_m_Data != nullptr )
          *(_DWORD *)p_m_Data = crc;
      }
      v17 += 3652;
      ++i;
    }
    while ( i < this->m_Expressions.m_Size );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447890
// Name: public: void CExpClass::CheckBitmapConsistency(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExpClass::CheckBitmapConsistency(CExpClass *this)
{
  char *m_szBaseName; // esi
  const char *(__thiscall *GetActiveModelName)(IFaceposerModels *); // edx
  const char *v3; // eax
  const char *v4; // eax
  CFmtStrN<256> *v5; // eax
  const char *(__thiscall *FindFirstEx)(IFileSystem *, const char *, const char *, int *); // edx
  char *m_Size; // edi
  CUtlString *m_pMemory; // ebx
  const char *v9; // esi
  char *v10; // esi
  CUtlString *v11; // esi
  int v12; // ebx
  const char *v13; // eax
  int v14; // eax
  const char *v15; // eax
  const char *v16; // [esp+18h] [ebp-570h]
  const char *v17; // [esp+1Ch] [ebp-56Ch]
  int v18; // [esp+20h] [ebp-568h]
  const char *v19; // [esp+28h] [ebp-560h]
  const char *v20; // [esp+28h] [ebp-560h]
  char path[512]; // [esp+38h] [ebp-550h] BYREF
  char kill[512]; // [esp+238h] [ebp-350h] BYREF
  CFmtStrN<256> v23; // [esp+438h] [ebp-150h] BYREF
  float v24; // [esp+544h] [ebp-44h]
  unsigned int check; // [esp+548h] [ebp-40h] BYREF
  char *v26; // [esp+54Ch] [ebp-3Ch]
  CUtlString s; // [esp+550h] [ebp-38h] BYREF
  int v28; // [esp+560h] [ebp-28h]
  int v29; // [esp+564h] [ebp-24h]
  int v30; // [esp+568h] [ebp-20h]
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > workList; // [esp+56Ch] [ebp-1Ch] BYREF
  int hFindFile; // [esp+580h] [ebp-8h] BYREF
  CExpClass *v33; // [esp+584h] [ebp-4h]

  m_szBaseName = this->m_szBaseName;
  v33 = this;
  GetActiveModelName = models->GetActiveModelName;
  v26 = this->m_szBaseName;
  v3 = (const char *)((int (__thiscall *)(IFaceposerModels *, char *))GetActiveModelName)(
                       a1: models,
                       a2: this->m_szBaseName);
  V_snprintf(pDest: path, maxLen: 512, pFormat: "expressions/%s/%s/*.bmp", v3, v19);
  V_FixSlashes(pname: path, separator: 92);
  _V_strlower(start: path);
  v4 = (const char *)((int (__thiscall *)(IFaceposerModels *, char *))models->GetActiveModelName)(
                       a1: models,
                       a2: m_szBaseName);
  v5 = CFmtStrN<256>::CFmtStrN<256>(this: &v23, pszFormat: "%s / %s - Reconcile Expression Thumbnails", v4, v20);
  g_pProgressDialog->Start(this: g_pProgressDialog, a2: v5->m_szBuf, a3: defaultValue, a4: true);
  FindFirstEx = filesystem->FindFirstEx;
  m_Size = nullptr;
  m_pMemory = nullptr;
  memset(&workList, 0, sizeof(workList));
  v9 = FindFirstEx(this: filesystem, a2: path, a3: "MOD", a4: &hFindFile);
  if ( v9 != nullptr )
  {
    do
    {
      if ( ((unsigned __int8 (__thiscall *)(IFileSystem *, int, int))filesystem->FindIsDirectory)(
             a1: filesystem,
             a2: hFindFile,
             a3: v18) == 0 )
      {
        CUtlString::CUtlString(this: (CUtlString *)&s.m_Storage.m_nActualLength, pString: v9);
        v10 = m_Size;
        if ( (int)(m_Size + 1) > workList.m_Memory.m_nAllocationCount )
        {
          CUtlMemory<SceneImageEntry_t,int>::Grow(
            this: (CUtlMemory<SceneImageEntry_t,int> *)&workList,
            num: (int)&m_Size[-workList.m_Memory.m_nAllocationCount + 1]);
          m_Size = (char *)workList.m_Size;
          m_pMemory = workList.m_Memory.m_pMemory;
        }
        workList.m_Size = (int)++m_Size;
        workList.m_pElements = m_pMemory;
        if ( m_Size - v10 - 1 > 0 )
          _V_memmove(dest: &m_pMemory[(int)v10 + 1], src: &m_pMemory[(_DWORD)v10], count: 16 * (m_Size - v10 - 1));
        v11 = &m_pMemory[(_DWORD)v10];
        if ( v11 != nullptr )
          CUtlString::CUtlString(this: v11, string: (const CUtlString *)&s.m_Storage.m_nActualLength);
        v30 = 0;
        if ( v29 >= 0 )
        {
          if ( s.m_Storage.m_nActualLength != 0 )
          {
            _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)s.m_Storage.m_nActualLength);
            s.m_Storage.m_nActualLength = 0;
          }
          v28 = 0;
        }
      }
      v18 = hFindFile;
      v9 = (const char *)((int (__thiscall *)(IFileSystem *))filesystem->FindNext)(a1: filesystem);
    }
    while ( v9 != nullptr );
    filesystem->FindClose(this: filesystem, a2: hFindFile);
  }
  memset(&s.m_Storage.m_Memory.m_nAllocationCount, 0, 12);
  v30 = 0;
  s.m_Storage.m_Memory.m_pMemory = (unsigned __int8 *)CDefOps<CChoreoEvent *>::LessFunc;
  v28 = 0xFFFF;
  v29 = -1;
  CExpClass::BuildValidChecksums(
    this: v33,
    p_m_Data: m_Size,
    tree: (CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *)&s);
  v12 = 0;
  if ( (int)m_Size > 0 )
  {
    v24 = (float)(int)m_Size;
    v33 = (CExpClass *)workList.m_Memory.m_pMemory;
    while ( 1 )
    {
      v13 = CUtlString::operator char const *(this: (CUtlString *)v33);
      V_StripExtension(in: v13, out: &v23.m_szBuf[7], outSize: 256);
      g_pProgressDialog->UpdateText(this: g_pProgressDialog, a2: "%s", &v23.m_szBuf[7]);
      ((void (__thiscall *)(IProgressDialog *, _DWORD))g_pProgressDialog->Update)(
        a1: g_pProgressDialog,
        a2: (float)v12 / v24);
      v14 = _V_strlen(str: &v23.m_szBuf[7]);
      V_hextobinary(in: &v23.m_szBuf[7], numchars: v14, out: (unsigned __int8 *)&check, maxoutputbytes: 4);
      if ( CUtlRBTree<unsigned long,unsigned short,bool (__cdecl *)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>>::Find(
             this: (CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *)&s,
             search: &check) == 0xFFFF )
      {
        v15 = (const char *)((int (__thiscall *)(IFaceposerModels *, char *, const char *))models->GetActiveModelName)(
                              a1: models,
                              a2: v26,
                              a3: v9);
        V_snprintf(pDest: kill, maxLen: 512, pFormat: "expressions/%s/%s/%s", v15, v16, v17);
        V_FixSlashes(pname: kill, separator: 92);
        _V_strlower(start: kill);
        Con_ErrorPrintf(fmt: "Removing unused bitmap file '%s'\n", kill);
        filesystem->RemoveFile(this: filesystem, a2: kill, a3: "MOD");
      }
      if ( g_pProgressDialog->IsCancelled(this: g_pProgressDialog) )
        break;
      v33 = (CExpClass *)((char *)v33 + 16);
      if ( ++v12 >= (int)m_Size )
        goto LABEL_23;
    }
    _Msg(a1: "Cancelled\n");
  }
LABEL_23:
  g_pProgressDialog->Finish(this: g_pProgressDialog);
  CUtlRBTree<unsigned long,unsigned short,bool (__cdecl *)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlRBTree<unsigned long,unsigned short,bool (__cdecl*)(unsigned long const &,unsigned long const &),CUtlMemory<UtlRBTreeNode_t<unsigned long,unsigned short>,unsigned short> > *)&s);
  if ( s.m_Storage.m_nActualLength >= 0 && s.m_Storage.m_Memory.m_nAllocationCount != 0 )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: (void *)s.m_Storage.m_Memory.m_nAllocationCount);
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int>>::RemoveAll(this: &workList);
  if ( workList.m_Memory.m_nGrowSize >= 0 && workList.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: workList.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x004564E0
// Name: public: char const __near * CExpClass::GetName(void)const
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CExpClass::GetName(CExpClass *this)
{
  return this->m_szClassName;
}
