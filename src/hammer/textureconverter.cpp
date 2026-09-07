// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: hammer/textureconverter.cpp
// Functions: 14
// ============================================================

#include "hammer\textureconverter.h"

//------------------------------------------------------------------------------
// Address: 0x100B5DD0
// Name: private: static bool CTextureConverter::CountMapSolids(class CMapSolid __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
int __cdecl CTextureConverter::CountMapSolids()
{
  ++CTextureConverter::m_nSolidCount;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B5DE0
// Name: private: static bool CTextureConverter::CountMapDecals(class CMapEntity __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CTextureConverter::CountMapDecals(CMapEntity *pEnt)
{
  if ( strcmp(pEnt->m_szClass, "infodecal") == 0 )
    ++CTextureConverter::m_nDecalCount;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B5E30
// Name: private: static void CTextureConverter::MsgConvertFace(class CMapFace __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CTextureConverter::MsgConvertFace(CMapFace *pFace, const char *format, ...)
{
  const char *v2; // eax
  int v3; // [esp-10h] [ebp-420h]
  int v4; // [esp-Ch] [ebp-41Ch]
  int v5; // [esp-8h] [ebp-418h]
  const char *v6; // [esp-4h] [ebp-414h]
  char message[1024]; // [esp+4h] [ebp-40Ch] BYREF
  Vector vecFaceCenter; // [esp+404h] [ebp-Ch] BYREF
  va_list ap; // [esp+420h] [ebp+10h] BYREF

  va_start(ap, format);
  CMapFace::GetCenter(this: pFace, Center: &vecFaceCenter);
  _vsnprintf(string: message, count: 0x400u, format, ap);
  v2 = (const char *)((int (__thiscall *)(IEditorTexture *, int, int, int, char *))pFace->m_pTexture->GetName)(
                       a1: pFace->m_pTexture,
                       a2: (int)vecFaceCenter.x,
                       a3: (int)vecFaceCenter.y,
                       a4: (int)vecFaceCenter.z,
                       a5: message);
  Msg(type: mwStatus, fmt: "[face] %s at (%d,%d,%d):  %s", v2, v3, v4, v5, v6);
}

//------------------------------------------------------------------------------
// Address: 0x100B5EA0
// Name: private: static void CTextureConverter::MsgConvertDecal(class CMapEntity __near *,char const __near *,...)
// Source: json
//------------------------------------------------------------------------------
void CTextureConverter::MsgConvertDecal(CMapEntity *pEnt, const char *format, ...)
{
  const char *Value; // eax
  char message[1024]; // [esp+4h] [ebp-40Ch] BYREF
  Vector vecOrigin; // [esp+404h] [ebp-Ch] BYREF
  va_list ap; // [esp+420h] [ebp+10h] BYREF

  va_start(ap, format);
  pEnt->GetOrigin(this: pEnt, a2: &vecOrigin);
  _vsnprintf(string: message, count: 0x400u, format, ap);
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pEnt->m_KeyValues, pszKey: "texture", piIndex: nullptr);
  Msg(
    type: mwStatus,
    fmt: "[decal] %s at (%d,%d,%d):  %s",
    Value,
    (int)vecOrigin.x,
    (int)vecOrigin.y,
    (int)vecOrigin.z,
    message);
}

//------------------------------------------------------------------------------
// Address: 0x100B5F20
// Name: private: static void CTextureConverter::DisplayStatistics(void)
// Source: json
//------------------------------------------------------------------------------
static void __cdecl CTextureConverter::DisplayStatistics()
{
  Msg(type: mwStatus, fmt: "==================");
  Msg(type: mwStatus, fmt: "Conversion summary:");
  Msg(type: mwStatus, fmt: "==================");
  Msg(type: mwStatus, fmt: "Total solids:                 %10d", CTextureConverter::m_nSolidCount);
  Msg(type: mwStatus, fmt: "Total faces:                  %10d", CTextureConverter::m_nFaceCount);
  Msg(type: mwStatus, fmt: "Total decals:                 %10d", CTextureConverter::m_nDecalCount);
  Msg(
    type: mwStatus,
    fmt: "Total conversions:            %10d",
    CTextureConverter::m_nFaceCount + CTextureConverter::m_nDecalCount);
  Msg(type: mwStatus, fmt: "Successful conversions:       %10d", CTextureConverter::m_nSuccesses);
  Msg(type: mwStatus, fmt: "Skipped conversions           %10d", CTextureConverter::m_nSkipped);
  Msg(type: mwStatus, fmt: "Conversion errors:            %10d", CTextureConverter::m_nErrors);
  Msg(type: mwStatus, fmt: "Conversion warnings:          %10d", CTextureConverter::m_nWarnings);
}

//------------------------------------------------------------------------------
// Address: 0x100B5FF0
// Name: private: static void CTextureConverter::RescaleFaceTexture(class CMapFace __near *,class IEditorTexture __near *)
// Source: json
//------------------------------------------------------------------------------
void __usercall CTextureConverter::RescaleFaceTexture(int a1@<ebx>, CMapFace *pFace, IEditorTexture *pNewTexture)
{
  const char *v3; // eax
  void *v4; // edi
  int v5; // ebx
  int v6; // edi
  int v7; // eax
  int v8; // edx
  int v9; // esi
  char line[512]; // [esp+8h] [ebp-408h] BYREF
  char resizeInfoFilename[512]; // [esp+208h] [ebp-208h] BYREF
  int nOldWidth; // [esp+408h] [ebp-8h] BYREF
  int nOldHeight; // [esp+40Ch] [ebp-4h] BYREF

  nOldWidth = -1;
  nOldHeight = -1;
  v3 = pNewTexture->GetName(this: pNewTexture);
  V_snprintf(pDest: resizeInfoFilename, maxLen: 512, pFormat: "materials\\%s.resizeinfo", v3);
  v4 = g_pFileSystem->Open(this: g_pFileSystem, a2: resizeInfoFilename, a3: "rt", a4: 0);
  if ( v4 != nullptr )
  {
    v5 = 0;
    if ( ((int (__thiscall *)(IFileSystem *, char *, int, void *, int))g_pFullFileSystem->ReadLine)(
           a1: g_pFullFileSystem,
           a2: line,
           a3: 512,
           a4: v4,
           a5: a1) != 0 )
      v5 = sscanf(string: line, format: "%d %d", &nOldWidth, &nOldHeight);
    g_pFileSystem->Close(this: g_pFileSystem, a2: v4);
    if ( v5 == 2 && nOldWidth >= 0 && nOldHeight >= 0 && nOldWidth <= 5000 && nOldHeight <= 5000 )
    {
      v6 = pNewTexture->GetWidth(this: pNewTexture);
      v7 = pNewTexture->GetHeight(this: pNewTexture);
      v8 = nOldWidth;
      v9 = nOldHeight;
      if ( nOldWidth != 0 && nOldHeight != 0 )
      {
        if ( v6 != 0 && v7 != 0 )
        {
          if ( nOldWidth != v6 )
          {
            pFace->texture.scale[0] = (float)((float)nOldWidth * pFace->texture.scale[0]) / (float)v6;
            pFace->texture.UAxis.w = (float)(pFace->texture.UAxis.w * (float)v6) / (float)v8;
          }
          if ( v9 != v7 )
          {
            pFace->texture.scale[1] = (float)((float)v9 * pFace->texture.scale[1]) / (float)v7;
            pFace->texture.VAxis.w = (float)((float)v7 * pFace->texture.VAxis.w) / (float)v9;
          }
          CMapFace::CalcTextureCoords(this: pFace);
        }
        else
        {
          CTextureConverter::MsgConvertFace(
            pFace,
            format: "WARNING: Invalid new material dimensions (%dx%d).  Texture converted but not re-scaled.",
            v6,
            v7);
          ++CTextureConverter::m_nWarnings;
        }
      }
      else
      {
        CTextureConverter::MsgConvertFace(
          pFace,
          format: "WARNING: Invalid old texture dimensions (%dx%d).  Texture converted but not re-scaled.",
          nOldWidth,
          nOldHeight);
        ++CTextureConverter::m_nWarnings;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B61E0
// Name: private: static void CTextureConverter::GetNewTextureMatches(char const __near *,class CUtlVector<class IEditorTexture __near *,class CUtlMemory<class IEditorTexture __near *,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTextureConverter::GetNewTextureMatches(
        const char *pszOldName,
        CUtlMemory<CCullTreeNode *,int> *tlMatchList)
{
  IEditorTexture *i; // ebx
  unsigned __int8 *v3; // edi
  int v4; // eax
  const char *v5; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  IEditorTexture **v8; // ecx
  int v9; // eax
  IEditorTexture **v10; // eax
  int nIndex; // [esp+8h] [ebp-4h] BYREF

  nIndex = 0;
  for ( i = CTextureSystem::EnumActiveTextures(this: &g_Textures, piIndex: &nIndex, eDesiredFormat: tfVMT);
        i != nullptr;
        i = CTextureSystem::EnumActiveTextures(this: &g_Textures, piIndex: &nIndex, eDesiredFormat: tfVMT) )
  {
    v3 = (unsigned __int8 *)i->GetName(this: i);
    strrchr(string: v3, chr: 0x2Fu);
    if ( v4 != 0 )
      v5 = (const char *)(v4 + 1);
    else
      v5 = (const char *)v3;
    if ( v5 != nullptr && strlen(v5) != 0 && _V_stricmp(s1: pszOldName, s2: v5) == 0 )
    {
      m_pMemory = (int)tlMatchList[1].m_pMemory;
      m_nAllocationCount = tlMatchList->m_nAllocationCount;
      if ( m_pMemory + 1 > m_nAllocationCount )
        CUtlMemory<CVisGroup *,int>::Grow(this: tlMatchList, num: m_pMemory - m_nAllocationCount + 1);
      ++tlMatchList[1].m_pMemory;
      v8 = (IEditorTexture **)tlMatchList->m_pMemory;
      v9 = (int)tlMatchList[1].m_pMemory - m_pMemory - 1;
      tlMatchList[1].m_nAllocationCount = (int)tlMatchList->m_pMemory;
      if ( v9 > 0 )
        _V_memmove(dest: &v8[m_pMemory + 1], src: &v8[m_pMemory], count: 4 * v9);
      v10 = (IEditorTexture **)&tlMatchList->m_pMemory[m_pMemory];
      if ( v10 != nullptr )
        *v10 = i;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100B62D0
// Name: private: static void CTextureConverter::ConvertFaceTexture(class CMapFace __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTextureConverter::ConvertFaceTexture(CMapFace *pFace)
{
  int v1; // ebx
  unsigned __int8 *v2; // edi
  unsigned int v3; // eax
  unsigned int v4; // esi
  unsigned int v5; // eax
  unsigned int v6; // eax
  int v7; // eax
  IEditorTexture *ActiveTexture; // eax
  IEditorTexture *v9; // esi
  IEditorTexture **m_pMemory; // ebx
  IEditorTexture *v11; // esi
  unsigned __int8 (__thiscall *v12)(IEditorTexture *); // eax
  IEditorTexture *v13; // ecx
  CMapFace *v14; // edi
  int m_nGrowSize; // esi
  const char *v16; // [esp-4h] [ebp-60h]
  char *replacements[6][2]; // [esp+Ch] [ebp-50h]
  CUtlVector<IEditorTexture *,CUtlMemory<IEditorTexture *,int> > tlMatches; // [esp+3Ch] [ebp-20h] BYREF
  int v19; // [esp+58h] [ebp-4h]

  v1 = 0;
  memset(&tlMatches, 0, sizeof(tlMatches));
  v19 = 1;
  v2 = (unsigned __int8 *)pFace->m_pTexture->GetName(this: pFace->m_pTexture);
  replacements[0][0] = "sky";
  replacements[0][1] = "tools/toolsskybox";
  replacements[1][0] = "skip";
  replacements[1][1] = "tools/toolsskip";
  replacements[2][0] = "aaatrigger";
  replacements[2][1] = "tools/toolstrigger";
  replacements[3][0] = "hint";
  replacements[3][1] = "tools/toolshint";
  replacements[4][0] = "clip";
  replacements[4][1] = "tools/toolsclip";
  replacements[5][0] = "null";
  replacements[5][1] = "tools/toolsnodraw";
  while ( 1 )
  {
    strrchr(string: v2, chr: 0x5Cu);
    v4 = v3;
    strrchr(string: v2, chr: 0x2Fu);
    if ( v5 > v4 )
    {
      strrchr(string: v2, chr: 0x2Fu);
      v4 = v6;
    }
    v16 = replacements[v1][0];
    v7 = v4 != 0 ? _V_stricmp(s1: (const char *)(v4 + 1), s2: v16) : _V_stricmp(s1: (const char *)v2, s2: v16);
    if ( v7 == 0 )
    {
      ActiveTexture = CTextureSystem::FindActiveTexture(
                        this: &g_Textures,
                        pszInputName: replacements[v1][1],
                        piIndex: nullptr,
                        bDummy: 1);
      v9 = ActiveTexture;
      if ( ActiveTexture != nullptr )
        break;
    }
    if ( (unsigned int)++v1 >= 6 )
    {
      CTextureConverter::GetNewTextureMatches(
        pszOldName: (const char *)v2,
        tlMatchList: (CUtlMemory<CCullTreeNode *,int> *)&tlMatches);
      m_pMemory = tlMatches.m_Memory.m_pMemory;
      if ( tlMatches.m_Size != 0 )
      {
        v11 = *tlMatches.m_Memory.m_pMemory;
        v12 = *(unsigned __int8 (__thiscall **)(IEditorTexture *))(**(_DWORD **)tlMatches.m_Memory.m_pMemory + 76);
        v13 = *tlMatches.m_Memory.m_pMemory;
        if ( tlMatches.m_Size == 1 )
        {
          v14 = pFace;
          if ( v12(a1: v13) == 0 )
          {
            CTextureConverter::MsgConvertFace(
              pFace,
              format: "WARNING: Couldn't load new material.  Texture converted but not re-scaled.");
            ++CTextureConverter::m_nWarnings;
          }
        }
        else
        {
          v14 = pFace;
          if ( v12(a1: v13) == 0 )
          {
            CTextureConverter::MsgConvertFace(
              pFace,
              format: "WARNING: Couldn't load new material.  Texture converted but not re-scaled.");
            ++CTextureConverter::m_nWarnings;
          }
        }
        CTextureConverter::RescaleFaceTexture(a1: (int)m_pMemory, pFace: v14, pNewTexture: v11);
        CMapFace::SetTexture(this: v14, pTexture: v11, bRescaleTextureCoordinates: false);
        ++CTextureConverter::m_nSuccesses;
      }
      else
      {
        CTextureConverter::MsgConvertFace(pFace, format: "ERROR: No matching material.  Cannot convert.");
        ++CTextureConverter::m_nErrors;
      }
      v19 = 3;
      m_nGrowSize = tlMatches.m_Memory.m_nGrowSize;
      tlMatches.m_Size = 0;
      if ( tlMatches.m_Memory.m_nGrowSize >= 0 )
      {
        if ( m_pMemory != nullptr )
        {
          free(pMem: m_pMemory);
          m_pMemory = nullptr;
          tlMatches.m_Memory.m_pMemory = nullptr;
        }
        tlMatches.m_Memory.m_nAllocationCount = 0;
      }
      tlMatches.m_pElements = m_pMemory;
      v19 = -1;
      if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
        free(pMem: m_pMemory);
      return;
    }
  }
  if ( !ActiveTexture->Load(this: ActiveTexture) )
  {
    CTextureConverter::MsgConvertFace(
      pFace,
      format: "WARNING: Couldn't load new material.  Texture converted but not re-scaled.");
    ++CTextureConverter::m_nWarnings;
  }
  CTextureConverter::RescaleFaceTexture(a1: v1, pFace, pNewTexture: v9);
  CMapFace::SetTexture(this: pFace, pTexture: v9, bRescaleTextureCoordinates: false);
  ++CTextureConverter::m_nSuccesses;
  tlMatches.m_Size = 0;
  tlMatches.m_pElements = nullptr;
  v19 = -1;
  tlMatches.m_Memory.m_nAllocationCount = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100B6560
// Name: private: static void CTextureConverter::ConvertDecalTexture(class CMapEntity __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTextureConverter::ConvertDecalTexture(CMapEntity *pEnt)
{
  const char *Value; // eax
  IEditorTexture *v2; // esi
  const char *v3; // eax
  CEditGameClass_vtbl *v4; // edi
  int v5; // eax
  IEditorTexture **m_pMemory; // ebx
  CEditGameClass_vtbl *v7; // esi
  int v8; // eax
  int m_nGrowSize; // edi
  CUtlVector<IEditorTexture *,CUtlMemory<IEditorTexture *,int> > tlMatches; // [esp+Ch] [ebp-20h] BYREF
  int v11; // [esp+28h] [ebp-4h]

  memset(&tlMatches, 0, sizeof(tlMatches));
  v11 = 1;
  Value = WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pEnt->m_KeyValues, pszKey: "texture", piIndex: nullptr);
  CTextureConverter::GetNewTextureMatches(pszOldName: Value, tlMatchList: (CUtlMemory<CCullTreeNode *,int> *)&tlMatches);
  if ( tlMatches.m_Size != 0 )
  {
    if ( tlMatches.m_Size == 1 )
    {
      m_pMemory = tlMatches.m_Memory.m_pMemory;
      v7 = pEnt->CEditGameClass::__vftable;
      v8 = (*(int (__thiscall **)(IEditorTexture *))(**(_DWORD **)tlMatches.m_Memory.m_pMemory + 32))(a1: *tlMatches.m_Memory.m_pMemory);
      v7->SetKeyValue(this: &pEnt->CEditGameClass, a2: "texture", a3: (const char *)v8);
      ++CTextureConverter::m_nSuccesses;
      goto LABEL_7;
    }
    v2 = *tlMatches.m_Memory.m_pMemory;
    v3 = (const char *)(*(int (__thiscall **)(IEditorTexture *))(**(_DWORD **)tlMatches.m_Memory.m_pMemory + 32))(a1: *tlMatches.m_Memory.m_pMemory);
    CTextureConverter::MsgConvertDecal(pEnt, format: "WARNING: Multiple matches found.  Using first match (%s).", v3);
    ++CTextureConverter::m_nWarnings;
    v4 = pEnt->CEditGameClass::__vftable;
    v5 = (int)v2->GetName(this: v2);
    v4->SetKeyValue(this: &pEnt->CEditGameClass, a2: "texture", a3: (const char *)v5);
    ++CTextureConverter::m_nSuccesses;
  }
  else
  {
    CTextureConverter::MsgConvertDecal(pEnt, format: "ERROR: No matching material.  Cannot convert.");
    ++CTextureConverter::m_nErrors;
  }
  m_pMemory = tlMatches.m_Memory.m_pMemory;
LABEL_7:
  v11 = 2;
  m_nGrowSize = tlMatches.m_Memory.m_nGrowSize;
  tlMatches.m_Size = 0;
  if ( tlMatches.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      free(pMem: m_pMemory);
      tlMatches.m_Memory.m_pMemory = nullptr;
      m_pMemory = nullptr;
    }
    tlMatches.m_Memory.m_nAllocationCount = 0;
  }
  tlMatches.m_pElements = m_pMemory;
  v11 = -1;
  if ( m_nGrowSize >= 0 && m_pMemory != nullptr )
    free(pMem: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x100B66B0
// Name: private: static bool CTextureConverter::CheckDecalTextures(class CMapEntity __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CTextureConverter::CheckDecalTextures(CMapEntity *pEnt)
{
  char *Value; // eax
  int v2; // eax

  if ( strcmp(pEnt->m_szClass, "infodecal") == 0 )
  {
    CProgressDlg::SetPos(this: CTextureConverter::m_pProgDlg, nPos: ++CTextureConverter::m_nCurrentDecal);
    Value = (char *)WCKeyValuesT<WCKVBase_Dict>::GetValue(this: &pEnt->m_KeyValues, pszKey: "texture", piIndex: nullptr);
    strchr(string: Value, chr: 0x2Fu);
    if ( v2 != 0 )
    {
      ++CTextureConverter::m_nSkipped;
      return 1;
    }
    CTextureConverter::ConvertDecalTexture(pEnt);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B6740
// Name: private: static bool CTextureConverter::CheckSolidTextures(class CMapSolid __near *,unsigned long)
// Source: json
//------------------------------------------------------------------------------
char __cdecl CTextureConverter::CheckSolidTextures(CMapSolid *pSolid)
{
  int v1; // ecx
  const char *nCount; // edi
  const char *i; // esi
  int v5; // eax
  CMapSolid *v6; // esi
  unsigned int v7; // esi
  CMapFace *v8; // esi
  char *v9; // eax
  int v10; // eax
  CMapSolid *pSolida; // [esp+8h] [ebp+8h]

  v1 = ++CTextureConverter::m_nCurrentSolid;
  if ( CTextureConverter::m_nCurrentSolid % 100 == 0 )
    CProgressDlg::SetPos(this: CTextureConverter::m_pProgDlg, nPos: v1);
  nCount = (const char *)pSolid->Faces.nCount;
  if ( pSolid->Faces.nCount != 0 )
  {
    for ( i = nCount + 1; ; i = (const char *)pSolida )
    {
      v5 = pSolid->Faces.nCount;
      --nCount;
      v6 = (CMapSolid *)(i - 1);
      pSolida = v6;
      if ( (int)nCount >= v5 )
      {
        _Error(this: (ISceneTokenProcessor *)&stru_105DC45C, a2: nCount, v5);
        if ( v6 != (CMapSolid *)pSolid->Faces.nCount )
        {
          v7 = (int)v6 / 6;
          if ( (int)(6 * v7) < (int)pSolida )
            ++v7;
          if ( v7 != pSolid->Faces.nBlocks )
          {
            if ( v7 > 0x57 )
              _Error(this: (ISceneTokenProcessor *)&stru_105DC428, a2: (const char *)6, 86);
            BlockArray<CMapFace,6,86>::GetBlocks(this: &pSolid->Faces, nNewBlocks: v7);
          }
          pSolid->Faces.nCount = (__int16)pSolida;
        }
      }
      v8 = &pSolid->Faces.Blocks[(int)nCount / 6][(int)nCount % 6];
      ++CTextureConverter::m_nFaceCount;
      if ( v8->m_pTexture->IsDummy(this: v8->m_pTexture) )
      {
        v9 = (char *)v8->m_pTexture->GetName(this: v8->m_pTexture);
        strchr(string: v9, chr: 0x2Fu);
        if ( v10 != 0 )
          ++CTextureConverter::m_nSkipped;
        else
          CTextureConverter::ConvertFaceTexture(pFace: v8);
      }
      else
      {
        ++CTextureConverter::m_nSkipped;
      }
      if ( nCount == nullptr )
        break;
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100B6890
// Name: private: static void CTextureConverter::ConvertDecals(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTextureConverter::ConvertDecals(CMapWorld *pWorld)
{
  CMapClass::EnumChildren(
    this: pWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CTextureConverter::CountMapDecals,
    dwParam: 0,
    Type: CMapEntity::__Type);
  CProgressDlg::SetRange(this: CTextureConverter::m_pProgDlg, nLower: 0, nUpper: CTextureConverter::m_nDecalCount);
  CProgressDlg::SetStep(this: CTextureConverter::m_pProgDlg, nStep: 3);
  CWnd::SetWindowTextA(this: CTextureConverter::m_pProgDlg, lpszString: "Converting decals...");
  CMapClass::EnumChildren(
    this: pWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CTextureConverter::CheckDecalTextures,
    dwParam: 0,
    Type: CMapEntity::__Type);
}

//------------------------------------------------------------------------------
// Address: 0x100B6900
// Name: private: static void CTextureConverter::ConvertSolids(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTextureConverter::ConvertSolids(CMapWorld *pWorld)
{
  CMapClass::EnumChildren(
    this: pWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CTextureConverter::CountMapSolids,
    dwParam: 0,
    Type: CMapSolid::__Type);
  CProgressDlg::SetRange(this: CTextureConverter::m_pProgDlg, nLower: 0, nUpper: CTextureConverter::m_nSolidCount);
  CProgressDlg::SetStep(this: CTextureConverter::m_pProgDlg, nStep: 2);
  CWnd::SetWindowTextA(this: CTextureConverter::m_pProgDlg, lpszString: "Converting solids...");
  CMapClass::EnumChildren(
    this: pWorld,
    pfn: (int (__cdecl *)(CMapClass *, unsigned int))CTextureConverter::CheckSolidTextures,
    dwParam: 0,
    Type: CMapSolid::__Type);
}

//------------------------------------------------------------------------------
// Address: 0x100B6970
// Name: public: static void CTextureConverter::ConvertWorldTextures(class CMapWorld __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CTextureConverter::ConvertWorldTextures(CMapWorld *pWorld)
{
  CProgressDlg *v1; // eax
  CProgressDlg *v2; // eax

  CTextureConverter::m_nSolidCount = 0;
  CTextureConverter::m_nCurrentSolid = 0;
  CTextureConverter::m_nFaceCount = 0;
  CTextureConverter::m_nDecalCount = 0;
  CTextureConverter::m_nCurrentDecal = 0;
  CTextureConverter::m_nSuccesses = 0;
  CTextureConverter::m_nErrors = 0;
  CTextureConverter::m_nSkipped = 0;
  CTextureConverter::m_nWarnings = 0;
  CMessageWnd::Activate(this: g_pwndMessage);
  Msg(type: mwStatus, fmt: "Converting textures from WAD to VMT format...");
  v1 = (CProgressDlg *)operator new(nSize: 0x120u);
  if ( v1 != nullptr )
    v2 = CProgressDlg::CProgressDlg(this: v1, nCaptionID: 0);
  else
    v2 = nullptr;
  CTextureConverter::m_pProgDlg = v2;
  CProgressDlg::Create(this: v2, pParent: nullptr);
  CProgressDlg::SetStep(this: CTextureConverter::m_pProgDlg, nStep: 1);
  CWnd::SetWindowTextA(this: CTextureConverter::m_pProgDlg, lpszString: "Preparing to convert textures...");
  CTextureConverter::ConvertSolids(pWorld);
  CTextureConverter::ConvertDecals(pWorld);
  CTextureConverter::DisplayStatistics();
  if ( CTextureConverter::m_pProgDlg != nullptr )
  {
    CTextureConverter::m_pProgDlg->DestroyWindow(this: CTextureConverter::m_pProgDlg);
    if ( CTextureConverter::m_pProgDlg != nullptr )
      ((void (__thiscall *)(CProgressDlg *, int))CTextureConverter::m_pProgDlg->dtr_CObject)(
        a1: CTextureConverter::m_pProgDlg,
        a2: 1);
    CTextureConverter::m_pProgDlg = nullptr;
  }
  AfxMessageBox(
    lpszText: "Conversion complete.  Check the Hammer \"Messages\" window for complete details.",
    nType: 0,
    nIDHelp: 0);
}
