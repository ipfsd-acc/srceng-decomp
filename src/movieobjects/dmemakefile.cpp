// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: movieobjects/dmemakefile.cpp
// Functions: 7
// ============================================================

#include "movieobjects\dmemakefile.h"

//------------------------------------------------------------------------------
// Address: 0x004B38A0
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = var;
  else
    v4 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x004B38E0
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = var;
    else
      v7 = g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B3AA0
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x004B3BA0
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x004B3BD0
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x004B3BE0
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x004B3C20
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

// ============================================================
// Overlay from elementviewer (Missing functions)
// ============================================================
namespace elementviewer {

//------------------------------------------------------------------------------
// Address: 0x00504C00
// Name: public: void CDmeSource::OpenEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OpenEditor(CDmeSource *this)
{
  if ( g_pDmeMakefileUtils != nullptr )
    g_pDmeMakefileUtils->PerformOpenEditor(this: g_pDmeMakefileUtils, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x00504C20
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = defaultValue;
  else
    v4 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00504C60
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = defaultValue;
    else
      v7 = g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00504E20
// Name: private: void CDmeMakefile::RelativePathToFullPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::RelativePathToFullPath(
        CDmeMakefile *this,
        const char *pRelativePath,
        char *pFullPath,
        int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v5; // eax
  char pRootDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( *pRelativePath != 0 )
  {
    m_fileId = this->m_fileId;
    if ( m_fileId == DMFILEID_INVALID )
      v5 = defaultValue;
    else
      v5 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
    V_ExtractFilePath(path: v5, dest: pRootDir, destSize: 260);
    V_ComposeFileName(path: pRootDir, filename: pRelativePath, dest: pFullPath, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
  }
  else
  {
    *pFullPath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00504EA0
// Name: private: void CDmeMakefile::FullPathToRelativePath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::FullPathToRelativePath(
        CDmeMakefile *this,
        const char *pFullPath,
        char *pRelativePath,
        int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v5; // eax
  char pRootDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( *pFullPath != 0 )
  {
    m_fileId = this->m_fileId;
    if ( m_fileId == DMFILEID_INVALID )
      v5 = defaultValue;
    else
      v5 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
    V_ExtractFilePath(path: v5, dest: pRootDir, destSize: 260);
    if ( pRootDir[0] != 0 )
    {
      V_MakeRelativePath(pFullPath, pDirectory: pRootDir, pRelativePath, nBufLen);
    }
    else
    {
      V_strncpy(pDest: pRelativePath, pSrc: pFullPath, maxLen: nBufLen);
      V_FixSlashes(pname: pRelativePath, separator: 92);
    }
  }
  else
  {
    *pRelativePath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00504F40
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x00504F60
// Name: public: class CDmeMakefile __near * CDmeSource::GetDependentMakefile(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__thiscall CDmeSource::GetDependentMakefile(CDmeSource *this)
{
  return (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_DependentMakefile.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x00504F80
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00504FB0
// Name: public: void CDmeMakefile::GetSourceFullPath(class CDmeSource __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetSourceFullPath(CDmeMakefile *this, CDmeSource *pSource, char *pFullPath, int nBufLen)
{
  const char *m_pAsString; // eax

  m_pAsString = pSource->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CDmeMakefile::RelativePathToFullPath(this, pRelativePath: m_pAsString, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00504FE0
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00504FF0
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00505030
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00505060
// Name: public: class CDmElement __near * CDmeMakefile::GetOutputElement(bool)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMakefile::GetOutputElement(CDmeMakefile *this, bool bCreateIfNecessary)
{
  CExpressionCalculator *v4; // eax
  DmElementHandle_t BufferType; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle) == nullptr )
  {
    if ( !bCreateIfNecessary )
      return nullptr;
    if ( g_pDmeMakefileUtils == nullptr || !g_pDmeMakefileUtils->IsCurrentlyCompiling(this: g_pDmeMakefileUtils) )
    {
      v4 = (CExpressionCalculator *)this->CreateOutputElement(this);
      if ( v4 != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: v4);
      else
        BufferType = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: BufferType);
    }
  }
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x005050F0
// Name: public: class CDmeSource __near * CDmeMakefile::FindSource(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::FindSource(CDmeMakefile *this, const char *pSourceType, const char *pFullPath)
{
  int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  const char *v10; // eax
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  char pRelativePath[260]; // [esp+Ch] [ebp-104h] BYREF
  int nCount; // [esp+11Ch] [ebp+Ch]

  CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
  v4 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
    v6 = v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeSource::m_classType) )
      v6 = nullptr;
    m_pAsString = v6->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: pSourceType, s2: m_pAsString) == 0 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeSource::m_classType) )
        v9 = nullptr;
      v10 = v9->m_Name.m_Storage.u.m_pAsString;
      if ( v10 == (const char *)-1 )
        v10 = defaultValue;
      if ( _V_stricmp(s1: pRelativePath, s2: v10) == 0 )
        break;
    }
    if ( ++v4 >= nCount )
      return nullptr;
  }
  v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
  v13 = v12;
  if ( v12 != nullptr && v12->IsA(this: v12, a2: CDmeSource::m_classType) )
    return (CDmeSource *)v13;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00505230
// Name: public: void CDmeMakefile::SetSourceFullPath(class CDmeSource __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::SetSourceFullPath(CDmeMakefile *this, CDmeSource *pSource, const char *pFullPath)
{
  const char *m_pAsString; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
  m_pAsString = pSource->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( _V_stricmp(s1: pRelativePath, s2: m_pAsString) != 0 )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFullPath, a3: pRelativePath);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: pSource->m_Name.m_pAttribute,
      value: (const CUtlSymbolLarge *)&pFullPath);
    CDmeHandle<CDmeMakefile,0>::Set(this: &pSource->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005052B0
// Name: public: class CDmeSource __near * CDmeMakefile::GetSource(int)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::GetSource(CDmeMakefile *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeSource::m_classType) )
    return (CDmeSource *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00505300
// Name: public: void CDmeMakefile::RemoveSource(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::RemoveSource(CDmeMakefile *this, CDmeSource *pSource)
{
  int v2; // edi
  CDmaElementArray<CDmeSource> *p_m_Sources; // ebx
  CDmElement *v4; // eax
  CDmeSource *v5; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount > 0 )
  {
    p_m_Sources = &this->m_Sources;
    while ( 1 )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Sources->m_Storage.m_Memory.m_pMemory[v2]);
      v5 = (CDmeSource *)v4;
      if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeSource::m_classType) )
        v5 = nullptr;
      if ( v5 == pSource )
        break;
      if ( ++v2 >= nCount )
        return;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
      this: p_m_Sources,
      elem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00505380
// Name: public: bool CDmeMakefile::HasSourceOfType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::HasSourceOfType(CDmeMakefile *this, const char *pSourceType)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax

  v3 = this->m_Sources.m_Storage.m_Size - 1;
  if ( v3 < 0 )
    return 0;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeSource::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = defaultValue;
    if ( _V_stricmp(s1: pSourceType, s2: m_pAsString) == 0 )
      break;
    if ( --v3 < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00505400
// Name: private: bool CDmeMakefile::UpdateSourceNames(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::UpdateSourceNames(
        CDmeMakefile *this,
        const char *pOldRootDir,
        const char *pNewRootDir,
        bool bApplyChanges)
{
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  const char *m_pAsString; // eax
  bool result; // al
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  char pNewSourcePath[260]; // [esp+Ch] [ebp-210h] BYREF
  char pOldSourcePath[260]; // [esp+110h] [ebp-10Ch] BYREF
  CUtlSymbolLarge value; // [esp+214h] [ebp-8h] BYREF
  int nCount; // [esp+218h] [ebp-4h]

  v5 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeSource::m_classType) )
        v7 = nullptr;
      m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 || *m_pAsString == 0 )
      {
        pNewSourcePath[0] = 0;
      }
      else
      {
        V_ComposeFileName(path: pOldRootDir, filename: m_pAsString, dest: pOldSourcePath, destSize: 260);
        V_RemoveDotSlashes(pFilename: pOldSourcePath, separator: 92);
        result = V_MakeRelativePath(
                   pFullPath: pOldSourcePath,
                   pDirectory: pNewRootDir,
                   pRelativePath: pNewSourcePath,
                   nBufLen: 260);
        if ( !result )
          return result;
      }
      if ( bApplyChanges )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v5]);
        v11 = v10;
        if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmeSource::m_classType) )
          v11 = nullptr;
        g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: pNewSourcePath);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11->m_Name.m_pAttribute, &value);
      }
      ++v5;
    }
    while ( v5 < nCount );
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x00505530
// Name: public: bool CDmeMakefile::SetFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::SetFileName(CDmeMakefile *this, const char *pFileName)
{
  const char *v4; // eax
  DmFileId_t m_fileId; // eax
  IDataModel_vtbl *v6; // edx
  DmFileId_t v7; // eax
  char pOldRootDir[260]; // [esp+8h] [ebp-208h] BYREF
  char pNewRootDir[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( !V_IsAbsolutePath(pStr: pFileName) )
    return 0;
  v4 = this->m_fileId == DMFILEID_INVALID
     ? defaultValue
     : g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
  V_ExtractFilePath(path: v4, dest: pOldRootDir, destSize: 260);
  V_ExtractFilePath(path: pFileName, dest: pNewRootDir, destSize: 260);
  if ( !CDmeMakefile::UpdateSourceNames(this, pOldRootDir, pNewRootDir, bApplyChanges: false) )
    return 0;
  CDmeMakefile::UpdateSourceNames(this, pOldRootDir, pNewRootDir, bApplyChanges: true);
  m_fileId = this->m_fileId;
  v6 = g_pDataModel->__vftable;
  if ( m_fileId == DMFILEID_INVALID )
  {
    v7 = ((int (__stdcall *)(const char *))v6->FindOrCreateFileId)(a1: pFileName);
    CDmElement::SetFileId(this, fileid: v7, depth: TD_DEEP, bOnlyIfMatch: false);
  }
  else
  {
    ((void (__stdcall *)(DmFileId_t, const char *))v6->SetFileName)(a1: m_fileId, a2: pFileName);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00505620
// Name: public: void CDmeMakefile::SetAssociation(class CDmeSource __near *,class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::SetAssociation(CDmeMakefile *this, CDmeSource *pSource, CDmeMakefile *pSourceMakefile)
{
  int v4; // edi
  CDmElement *v5; // eax
  CDmeSource *v6; // esi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // eax
  CDmeHandle<CDmeMakefile,0> *v10; // esi
  DmElementHandle_t BufferType; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pSource != nullptr )
  {
    v4 = 0;
    nCount = this->m_Sources.m_Storage.m_Size;
    if ( nCount > 0 )
    {
      while ( 1 )
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeSource *)v5;
        if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeSource::m_classType) )
          v6 = nullptr;
        if ( v6 == pSource )
          break;
        if ( ++v4 >= nCount )
          return;
      }
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
      v8 = v7;
      if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeSource::m_classType) )
        v8 = nullptr;
      if ( pSourceMakefile != g_pDataModel->GetElement(this: g_pDataModel, a2: v8[1].__vftable) )
      {
        v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
        v10 = (CDmeHandle<CDmeMakefile,0> *)v9;
        if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmeSource::m_classType) )
          v10 = nullptr;
        if ( pSourceMakefile != nullptr )
        {
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pSourceMakefile);
          CDmeHandle<CDmeMakefile,0>::Set(this: v10 + 17, h: BufferType);
        }
        else
        {
          CDmeHandle<CDmeMakefile,0>::Set(this: v10 + 17, h: DMELEMENT_HANDLE_INVALID);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00505740
// Name: public: class CDmeMakefile __near * CDmeMakefile::FindDependentMakefile(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__thiscall CDmeMakefile::FindDependentMakefile(CDmeMakefile *this, CDmeSource *pSource)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeSource *v5; // esi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pSource == nullptr )
    return nullptr;
  v3 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeSource *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeSource::m_classType) )
      v5 = nullptr;
    if ( v5 == pSource )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
  v8 = v7;
  if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeSource::m_classType) )
    v8 = nullptr;
  return (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v8[1].__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x00505800
// Name: public: class CDmeSource __near * CDmeMakefile::FindAssociatedSource(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::FindAssociatedSource(CDmeMakefile *this, CDmeMakefile *pChildMakefile)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pChildMakefile == nullptr )
    return nullptr;
  v3 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeSource::m_classType) )
      v5 = nullptr;
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v5[1].__vftable) == pChildMakefile )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeSource::m_classType) )
    return (CDmeSource *)v8;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005058C0
// Name: public: class CDmeSource __near * CDmeMakefile::AddSource(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::AddSource(CDmeMakefile *this, const char *pSourceType, const char *pFullPath)
{
  const char *v3; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  IDataModel_vtbl *v9; // edi
  int BufferType; // eax
  char pRelativePath[260]; // [esp+Ch] [ebp-104h] BYREF

  v3 = pFullPath;
  if ( *pFullPath != 0 && CDmeMakefile::FindSource(this, pSourceType, pFullPath) != nullptr )
  {
    _Warning(a1: "Attempted to add the same source twice %s!\n", v3);
    return nullptr;
  }
  v6 = g_pDataModel->CreateElement(
         this: g_pDataModel,
         a2: pSourceType,
         a3: defaultValue,
         a4: this->m_fileId,
         a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    if ( v8->IsA(this: v8, a2: CDmeSource::m_classType) )
    {
      CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFullPath, a3: pRelativePath);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v8->m_Name.m_pAttribute, value: (const CUtlSymbolLarge *)&pFullPath);
      pFullPath = (const char *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v8);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Sources,
        src: (DmElementHandle_t *)&pFullPath);
      return (CDmeSource *)v8;
    }
  }
  else
  {
    v8 = nullptr;
  }
  _Warning(a1: "Invalid source type name %s!\n", pSourceType);
  if ( v8 != nullptr )
  {
    v9 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v8);
    v9->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00505A00
// Name: public: void CDmeMakefile::GetSources(char const __near *,class CUtlVector<class CDmeHandle<class CDmeSource,0>,class CUtlMemory<class CDmeHandle<class CDmeSource,0>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetSources(
        CDmeMakefile *this,
        const char *pSourceType,
        CUtlMemory<vgui::TreeNode *,int> *sources)
{
  int m_Size; // ebx
  CDmeHandle<CDmeSource,0> *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  CDmeHandle<CDmeSource,0> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  int v10; // edi
  int m_nAllocationCount; // eax
  CDmeHandle<CDmeSource,0> *v12; // ecx
  int v13; // eax
  int v14; // ebx
  CDmeHandle<CDmeSource,0> *v15; // eax
  CDmElement *v16; // eax
  CDmElement *v17; // edi
  CExpressionCalculator *v18; // ecx
  CDmeElementRefHelper *v19; // edi
  DmElementHandle_t BufferType; // ebx
  CDmElement *v21; // eax
  int v22; // [esp+Ch] [ebp-Ch] BYREF
  int nCount; // [esp+10h] [ebp-8h]
  CDmeMakefile *v24; // [esp+14h] [ebp-4h]
  int i; // [esp+24h] [ebp+Ch]

  m_Size = this->m_Sources.m_Storage.m_Size;
  v24 = this;
  nCount = m_Size;
  if ( sources->m_nAllocationCount < m_Size && sources->m_nGrowSize >= 0 )
  {
    m_pMemory = (CDmeHandle<CDmeSource,0> *)sources->m_pMemory;
    sources->m_nAllocationCount = m_Size;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (CDmeHandle<CDmeSource,0> *)((int (__stdcall *)(CDmeHandle<CDmeSource,0> *, int))v6->Realloc_2)(
                                         a1: m_pMemory,
                                         a2: 4 * m_Size);
    else
      v7 = (CDmeHandle<CDmeSource,0> *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 4 * m_Size);
    sources->m_pMemory = (vgui::TreeNode **)v7;
  }
  sources[1].m_nAllocationCount = (int)sources->m_pMemory;
  for ( i = 0; i < m_Size; ++i )
  {
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v24->m_Sources.m_Storage.m_Memory.m_pMemory[i]);
    v9 = v8;
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeSource::m_classType) )
      v9 = nullptr;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v22, a3: pSourceType);
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))v9->IsA)(a1: v9, a2: v22) != 0 )
    {
      v10 = (int)sources[1].m_pMemory;
      m_nAllocationCount = sources->m_nAllocationCount;
      if ( v10 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: sources, num: v10 - m_nAllocationCount + 1);
      ++sources[1].m_pMemory;
      v12 = (CDmeHandle<CDmeSource,0> *)sources->m_pMemory;
      v13 = (int)sources[1].m_pMemory - v10 - 1;
      sources[1].m_nAllocationCount = (int)sources->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
      v14 = v10;
      v15 = (CDmeHandle<CDmeSource,0> *)&sources->m_pMemory[v10];
      if ( v15 != nullptr )
        v15->m_handle = DMELEMENT_HANDLE_INVALID;
      v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: v24->m_Sources.m_Storage.m_Memory.m_pMemory[i]);
      v17 = v16;
      if ( v16 != nullptr && v16->IsA(this: v16, a2: CDmeSource::m_classType) )
        v18 = (CExpressionCalculator *)v17;
      else
        v18 = nullptr;
      v19 = (CDmeElementRefHelper *)&sources->m_pMemory[v14];
      if ( v18 != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: v18);
      else
        BufferType = DMELEMENT_HANDLE_INVALID;
      if ( BufferType != *(_DWORD *)v19 )
      {
        CDmeElementRefHelper::Unref(this: v19, hElement: *(_DWORD *)v19, handleType: HT_WEAK);
        *(_DWORD *)v19 = BufferType;
        if ( BufferType != DMELEMENT_HANDLE_INVALID )
        {
          v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
          if ( v21 != nullptr && !v21->IsA(this: v21, a2: CDmeSource::m_classType) )
            *(_DWORD *)v19 = -1;
        }
        CDmeElementRefHelper::Ref(this: v19, hElement: *(_DWORD *)v19, handleType: HT_WEAK);
      }
      m_Size = nCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00505C50
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00505C80
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00505D70
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00505DF0
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x00505E00
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00505E30
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00505E70
// Name: protected: virtual int CDmeMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x00505E80
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00505ED0
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00506730
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x0067D2F0
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D350
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00681F90
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00681FA0
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0067D320
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D330
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0067D380
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0067D390
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00681FB0
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x00681FC0
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace elementviewer

// ============================================================
// Overlay from hammer_dll (Missing functions)
// ============================================================
namespace hammer_dll {

//------------------------------------------------------------------------------
// Address: 0x104D62A0
// Name: public: void CDmeSource::OpenEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OpenEditor(CDmeSource *this)
{
  if ( g_pDmeMakefileUtils != nullptr )
    g_pDmeMakefileUtils->PerformOpenEditor(this: g_pDmeMakefileUtils, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x104D62C0
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = (char *)&var;
  else
    v4 = (char *)g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x104D6300
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  char *v7; // eax
  unsigned int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = (char *)&var;
    else
      v7 = (char *)g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 0x104u);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) != 0 )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D64C0
// Name: private: void CDmeMakefile::RelativePathToFullPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::RelativePathToFullPath(
        CDmeMakefile *this,
        const char *pRelativePath,
        char *pFullPath,
        int nBufLen)
{
  DmFileId_t m_fileId; // eax
  char *v5; // eax
  char pRootDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( *pRelativePath != 0 )
  {
    m_fileId = this->m_fileId;
    if ( m_fileId == DMFILEID_INVALID )
      v5 = (char *)&var;
    else
      v5 = (char *)g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
    V_ExtractFilePath(path: v5, dest: pRootDir, destSize: 260);
    V_ComposeFileName(path: pRootDir, filename: pRelativePath, dest: pFullPath, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
  }
  else
  {
    *pFullPath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D6540
// Name: private: void CDmeMakefile::FullPathToRelativePath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::FullPathToRelativePath(
        CDmeMakefile *this,
        char *pFullPath,
        char *pRelativePath,
        int nBufLen)
{
  DmFileId_t m_fileId; // eax
  char *v5; // eax
  char pRootDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( *pFullPath != 0 )
  {
    m_fileId = this->m_fileId;
    if ( m_fileId == DMFILEID_INVALID )
      v5 = (char *)&var;
    else
      v5 = (char *)g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
    V_ExtractFilePath(path: v5, dest: pRootDir, destSize: 260);
    if ( pRootDir[0] != 0 )
    {
      V_MakeRelativePath(pFullPath, pDirectory: pRootDir, pRelativePath, nBufLen);
    }
    else
    {
      V_strncpy(pDest: pRelativePath, pSrc: pFullPath, maxLen: nBufLen);
      V_FixSlashes(pname: pRelativePath, separator: 92);
    }
  }
  else
  {
    *pRelativePath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D65E0
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x104D6600
// Name: public: class CDmeMakefile __near * CDmeSource::GetDependentMakefile(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__thiscall CDmeSource::GetDependentMakefile(CDmeSource *this)
{
  return (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_DependentMakefile.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x104D6620
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x104D6650
// Name: public: void CDmeMakefile::GetSourceFullPath(class CDmeSource __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetSourceFullPath(CDmeMakefile *this, CDmeSource *pSource, char *pFullPath, int nBufLen)
{
  const char *m_pAsString; // eax

  m_pAsString = pSource->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  CDmeMakefile::RelativePathToFullPath(this, pRelativePath: m_pAsString, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x104D6680
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x104D6690
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x104D66D0
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x104D6700
// Name: public: class CDmElement __near * CDmeMakefile::GetOutputElement(bool)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMakefile::GetOutputElement(CDmeMakefile *this, bool bCreateIfNecessary)
{
  CExpressionCalculator *v4; // eax
  DmElementHandle_t BufferType; // eax

  if ( g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle) == nullptr )
  {
    if ( !bCreateIfNecessary )
      return nullptr;
    if ( g_pDmeMakefileUtils == nullptr || !g_pDmeMakefileUtils->IsCurrentlyCompiling(this: g_pDmeMakefileUtils) )
    {
      v4 = (CExpressionCalculator *)this->CreateOutputElement(this);
      if ( v4 != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: v4);
      else
        BufferType = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: BufferType);
    }
  }
  return g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x104D6790
// Name: public: class CDmeSource __near * CDmeMakefile::FindSource(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::FindSource(CDmeMakefile *this, const char *pSourceType, char *pFullPath)
{
  int v4; // edi
  CDmElement *v5; // eax
  CDmElement *v6; // esi
  const char *m_pAsString; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // esi
  const char *v10; // eax
  CDmElement *v12; // eax
  CDmElement *v13; // esi
  char pRelativePath[260]; // [esp+Ch] [ebp-104h] BYREF
  int nCount; // [esp+11Ch] [ebp+Ch]

  CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
  v4 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
    v6 = v5;
    if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeSource::m_classType) )
      v6 = nullptr;
    m_pAsString = v6->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_stricmp(s1: pSourceType, s2: m_pAsString) == 0 )
    {
      v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
      v9 = v8;
      if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeSource::m_classType) )
        v9 = nullptr;
      v10 = v9->m_Name.m_Storage.u.m_pAsString;
      if ( v10 == (const char *)-1 )
        v10 = &var;
      if ( _V_stricmp(s1: pRelativePath, s2: v10) == 0 )
        break;
    }
    if ( ++v4 >= nCount )
      return nullptr;
  }
  v12 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
  v13 = v12;
  if ( v12 != nullptr && v12->IsA(this: v12, a2: CDmeSource::m_classType) )
    return (CDmeSource *)v13;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D68D0
// Name: public: void CDmeMakefile::SetSourceFullPath(class CDmeSource __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::SetSourceFullPath(CDmeMakefile *this, CDmeSource *pSource, char *pFullPath)
{
  const char *m_pAsString; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
  m_pAsString = pSource->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = &var;
  if ( _V_stricmp(s1: pRelativePath, s2: m_pAsString) != 0 )
  {
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFullPath, a3: pRelativePath);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: pSource->m_Name.m_pAttribute,
      value: (const CUtlSymbolLarge *)&pFullPath);
    CDmeHandle<CDmeMakefile,0>::Set(this: &pSource->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D6950
// Name: public: class CDmeSource __near * CDmeMakefile::GetSource(int)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::GetSource(CDmeMakefile *this, int nIndex)
{
  CDmElement *v2; // eax
  CDmElement *v3; // esi

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != nullptr && v2->IsA(this: v2, a2: CDmeSource::m_classType) )
    return (CDmeSource *)v3;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D69A0
// Name: public: void CDmeMakefile::RemoveSource(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::RemoveSource(CDmeMakefile *this, CDmeSource *pSource)
{
  int v2; // edi
  CDmaElementArray<CDmeSource> *p_m_Sources; // ebx
  CDmElement *v4; // eax
  CDmeSource *v5; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount > 0 )
  {
    p_m_Sources = &this->m_Sources;
    while ( 1 )
    {
      v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: p_m_Sources->m_Storage.m_Memory.m_pMemory[v2]);
      v5 = (CDmeSource *)v4;
      if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeSource::m_classType) )
        v5 = nullptr;
      if ( v5 == pSource )
        break;
      if ( ++v2 >= nCount )
        return;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
      this: p_m_Sources,
      elem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D6A20
// Name: public: bool CDmeMakefile::HasSourceOfType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::HasSourceOfType(CDmeMakefile *this, const char *pSourceType)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  const char *m_pAsString; // eax

  v3 = this->m_Sources.m_Storage.m_Size - 1;
  if ( v3 < 0 )
    return 0;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeSource::m_classType) )
      v5 = nullptr;
    m_pAsString = v5->m_Type.u.m_pAsString;
    if ( m_pAsString == (const char *)-1 )
      m_pAsString = &var;
    if ( _V_stricmp(s1: pSourceType, s2: m_pAsString) == 0 )
      break;
    if ( --v3 < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104D6AA0
// Name: private: bool CDmeMakefile::UpdateSourceNames(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::UpdateSourceNames(
        CDmeMakefile *this,
        char *pOldRootDir,
        const char *pNewRootDir,
        bool bApplyChanges)
{
  int v5; // edi
  CDmElement *v6; // eax
  CDmElement *v7; // esi
  const char *m_pAsString; // eax
  char result; // al
  CDmElement *v10; // eax
  CDmElement *v11; // esi
  char pNewSourcePath[260]; // [esp+Ch] [ebp-210h] BYREF
  char pOldSourcePath[260]; // [esp+110h] [ebp-10Ch] BYREF
  CUtlSymbolLarge value; // [esp+214h] [ebp-8h] BYREF
  int nCount; // [esp+218h] [ebp-4h]

  v5 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v6 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 == nullptr || !v6->IsA(this: v6, a2: CDmeSource::m_classType) )
        v7 = nullptr;
      m_pAsString = v7->m_Name.m_Storage.u.m_pAsString;
      if ( m_pAsString == (const char *)-1 || *m_pAsString == 0 )
      {
        pNewSourcePath[0] = 0;
      }
      else
      {
        V_ComposeFileName(path: pOldRootDir, filename: m_pAsString, dest: pOldSourcePath, destSize: 260);
        V_RemoveDotSlashes(pFilename: pOldSourcePath, separator: 92);
        result = V_MakeRelativePath(
                   pFullPath: pOldSourcePath,
                   pDirectory: pNewRootDir,
                   pRelativePath: pNewSourcePath,
                   nBufLen: 260);
        if ( result == 0 )
          return result;
      }
      if ( bApplyChanges )
      {
        v10 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v5]);
        v11 = v10;
        if ( v10 == nullptr || !v10->IsA(this: v10, a2: CDmeSource::m_classType) )
          v11 = nullptr;
        g_pDataModel->GetSymbol(this: g_pDataModel, result: &value, a3: pNewSourcePath);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: v11->m_Name.m_pAttribute, &value);
      }
      ++v5;
    }
    while ( v5 < nCount );
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104D6BD0
// Name: public: bool CDmeMakefile::SetFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::SetFileName(CDmeMakefile *this, char *pFileName)
{
  char *v4; // eax
  DmFileId_t m_fileId; // eax
  IDataModel_vtbl *v6; // edx
  DmFileId_t v7; // eax
  char pOldRootDir[260]; // [esp+8h] [ebp-208h] BYREF
  char pNewRootDir[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( !V_IsAbsolutePath(pStr: pFileName) )
    return 0;
  v4 = (char *)(this->m_fileId == DMFILEID_INVALID
              ? &var
              : g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId));
  V_ExtractFilePath(path: v4, dest: pOldRootDir, destSize: 260);
  V_ExtractFilePath(path: pFileName, dest: pNewRootDir, destSize: 260);
  if ( CDmeMakefile::UpdateSourceNames(this, pOldRootDir, pNewRootDir, bApplyChanges: false) == 0 )
    return 0;
  CDmeMakefile::UpdateSourceNames(this, pOldRootDir, pNewRootDir, bApplyChanges: true);
  m_fileId = this->m_fileId;
  v6 = g_pDataModel->__vftable;
  if ( m_fileId == DMFILEID_INVALID )
  {
    v7 = ((int (__stdcall *)(char *))v6->FindOrCreateFileId)(a1: pFileName);
    CDmElement::SetFileId(this, fileid: v7, depth: TD_DEEP, bOnlyIfMatch: false);
  }
  else
  {
    ((void (__stdcall *)(DmFileId_t, char *))v6->SetFileName)(a1: m_fileId, a2: pFileName);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x104D6CC0
// Name: public: void CDmeMakefile::SetAssociation(class CDmeSource __near *,class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::SetAssociation(CDmeMakefile *this, CDmeSource *pSource, CDmeMakefile *pSourceMakefile)
{
  int v4; // edi
  CDmElement *v5; // eax
  CDmeSource *v6; // esi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  CDmElement *v9; // eax
  CDmeHandle<CDmeMakefile,0> *v10; // esi
  DmElementHandle_t BufferType; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pSource != nullptr )
  {
    v4 = 0;
    nCount = this->m_Sources.m_Storage.m_Size;
    if ( nCount > 0 )
    {
      while ( 1 )
      {
        v5 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeSource *)v5;
        if ( v5 == nullptr || !v5->IsA(this: v5, a2: CDmeSource::m_classType) )
          v6 = nullptr;
        if ( v6 == pSource )
          break;
        if ( ++v4 >= nCount )
          return;
      }
      v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
      v8 = v7;
      if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeSource::m_classType) )
        v8 = nullptr;
      if ( pSourceMakefile != g_pDataModel->GetElement(this: g_pDataModel, a2: v8[1].__vftable) )
      {
        v9 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
        v10 = (CDmeHandle<CDmeMakefile,0> *)v9;
        if ( v9 == nullptr || !v9->IsA(this: v9, a2: CDmeSource::m_classType) )
          v10 = nullptr;
        if ( pSourceMakefile != nullptr )
        {
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pSourceMakefile);
          CDmeHandle<CDmeMakefile,0>::Set(this: v10 + 17, h: BufferType);
        }
        else
        {
          CDmeHandle<CDmeMakefile,0>::Set(this: v10 + 17, h: DMELEMENT_HANDLE_INVALID);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x104D6DE0
// Name: public: class CDmeMakefile __near * CDmeMakefile::FindDependentMakefile(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__thiscall CDmeMakefile::FindDependentMakefile(CDmeMakefile *this, CDmeSource *pSource)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmeSource *v5; // esi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pSource == nullptr )
    return nullptr;
  v3 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeSource *)v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeSource::m_classType) )
      v5 = nullptr;
    if ( v5 == pSource )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
  v8 = v7;
  if ( v7 == nullptr || !v7->IsA(this: v7, a2: CDmeSource::m_classType) )
    v8 = nullptr;
  return (CDmeMakefile *)g_pDataModel->GetElement(this: g_pDataModel, a2: (DmElementHandle_t)v8[1].__vftable);
}

//------------------------------------------------------------------------------
// Address: 0x104D6EA0
// Name: public: class CDmeSource __near * CDmeMakefile::FindAssociatedSource(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::FindAssociatedSource(CDmeMakefile *this, CDmeMakefile *pChildMakefile)
{
  int v3; // edi
  CDmElement *v4; // eax
  CDmElement *v5; // esi
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pChildMakefile == nullptr )
    return nullptr;
  v3 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == nullptr || !v4->IsA(this: v4, a2: CDmeSource::m_classType) )
      v5 = nullptr;
    if ( g_pDataModel->GetElement(this: g_pDataModel, a2: v5[1].__vftable) == pChildMakefile )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmeSource::m_classType) )
    return (CDmeSource *)v8;
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D6F60
// Name: public: class CDmeSource __near * CDmeMakefile::AddSource(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::AddSource(CDmeMakefile *this, const char *pSourceType, char *pFullPath)
{
  const char *v3; // esi
  DmElementHandle_t v6; // eax
  CDmElement *v7; // eax
  CDmElement *v8; // esi
  IDataModel_vtbl *v9; // edi
  int BufferType; // eax
  char pRelativePath[260]; // [esp+Ch] [ebp-104h] BYREF

  v3 = pFullPath;
  if ( *pFullPath != 0 && CDmeMakefile::FindSource(this, pSourceType, pFullPath) != nullptr )
  {
    _Warning(a1: "Attempted to add the same source twice %s!\n", v3);
    return nullptr;
  }
  v6 = g_pDataModel->CreateElement(this: g_pDataModel, a2: pSourceType, a3: &var, a4: this->m_fileId, a5: nullptr);
  v7 = g_pDataModel->GetElement(this: g_pDataModel, a2: v6);
  v8 = v7;
  if ( v7 != nullptr && v7->IsA(this: v7, a2: CDmElement::m_classType) )
  {
    if ( v8->IsA(this: v8, a2: CDmeSource::m_classType) )
    {
      CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
      g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&pFullPath, a3: pRelativePath);
      CDmAttribute::SetValue<CUtlSymbolLarge>(this: v8->m_Name.m_pAttribute, value: (const CUtlSymbolLarge *)&pFullPath);
      pFullPath = (char *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v8);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Sources,
        src: (DmElementHandle_t *)&pFullPath);
      return (CDmeSource *)v8;
    }
  }
  else
  {
    v8 = nullptr;
  }
  _Warning(a1: "Invalid source type name %s!\n", pSourceType);
  if ( v8 != nullptr )
  {
    v9 = g_pDataModel->__vftable;
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v8);
    v9->DestroyElement(this: g_pDataModel, a2: (DmElementHandle_t)BufferType);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x104D70A0
// Name: public: void CDmeMakefile::GetSources(char const __near *,class CUtlVector<class CDmeHandle<class CDmeSource,0>,class CUtlMemory<class CDmeHandle<class CDmeSource,0>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetSources(
        CDmeMakefile *this,
        const char *pSourceType,
        CUtlMemory<vgui::TreeNode *,int> *sources)
{
  int m_Size; // ebx
  CDmeHandle<CDmeSource,0> *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  CDmeHandle<CDmeSource,0> *v7; // eax
  CDmElement *v8; // eax
  CDmElement *v9; // edi
  int v10; // edi
  int m_nAllocationCount; // eax
  CDmeHandle<CDmeSource,0> *v12; // ecx
  int v13; // eax
  int v14; // ebx
  CDmeHandle<CDmeSource,0> *v15; // eax
  CDmElement *v16; // eax
  CDmElement *v17; // edi
  CExpressionCalculator *v18; // ecx
  CDmeElementRefHelper *v19; // edi
  DmElementHandle_t BufferType; // ebx
  CDmElement *v21; // eax
  int v22; // [esp+Ch] [ebp-Ch] BYREF
  int nCount; // [esp+10h] [ebp-8h]
  CDmeMakefile *v24; // [esp+14h] [ebp-4h]
  int i; // [esp+24h] [ebp+Ch]

  m_Size = this->m_Sources.m_Storage.m_Size;
  v24 = this;
  nCount = m_Size;
  if ( sources->m_nAllocationCount < m_Size && sources->m_nGrowSize >= 0 )
  {
    m_pMemory = (CDmeHandle<CDmeSource,0> *)sources->m_pMemory;
    sources->m_nAllocationCount = m_Size;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (CDmeHandle<CDmeSource,0> *)((int (__stdcall *)(CDmeHandle<CDmeSource,0> *, int))v6->Realloc_2)(
                                         a1: m_pMemory,
                                         a2: 4 * m_Size);
    else
      v7 = (CDmeHandle<CDmeSource,0> *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 4 * m_Size);
    sources->m_pMemory = (vgui::TreeNode **)v7;
  }
  sources[1].m_nAllocationCount = (int)sources->m_pMemory;
  for ( i = 0; i < m_Size; ++i )
  {
    v8 = g_pDataModel->GetElement(this: g_pDataModel, a2: v24->m_Sources.m_Storage.m_Memory.m_pMemory[i]);
    v9 = v8;
    if ( v8 == nullptr || !v8->IsA(this: v8, a2: CDmeSource::m_classType) )
      v9 = nullptr;
    g_pDataModel->GetSymbol(this: g_pDataModel, result: (CUtlSymbolLarge *)&v22, a3: pSourceType);
    if ( ((unsigned __int8 (__thiscall *)(CDmElement *, int))v9->IsA)(a1: v9, a2: v22) != 0 )
    {
      v10 = (int)sources[1].m_pMemory;
      m_nAllocationCount = sources->m_nAllocationCount;
      if ( v10 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: sources, num: v10 - m_nAllocationCount + 1);
      ++sources[1].m_pMemory;
      v12 = (CDmeHandle<CDmeSource,0> *)sources->m_pMemory;
      v13 = (int)sources[1].m_pMemory - v10 - 1;
      sources[1].m_nAllocationCount = (int)sources->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v12[v10 + 1], src: (unsigned __int8 *)&v12[v10], count: 4 * v13);
      v14 = v10;
      v15 = (CDmeHandle<CDmeSource,0> *)&sources->m_pMemory[v10];
      if ( v15 != nullptr )
        v15->m_handle = DMELEMENT_HANDLE_INVALID;
      v16 = g_pDataModel->GetElement(this: g_pDataModel, a2: v24->m_Sources.m_Storage.m_Memory.m_pMemory[i]);
      v17 = v16;
      if ( v16 != nullptr && v16->IsA(this: v16, a2: CDmeSource::m_classType) )
        v18 = (CExpressionCalculator *)v17;
      else
        v18 = nullptr;
      v19 = (CDmeElementRefHelper *)&sources->m_pMemory[v14];
      if ( v18 != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: v18);
      else
        BufferType = DMELEMENT_HANDLE_INVALID;
      if ( BufferType != *(_DWORD *)v19 )
      {
        CDmeElementRefHelper::Unref(this: v19, hElement: *(_DWORD *)v19, handleType: HT_WEAK);
        *(_DWORD *)v19 = BufferType;
        if ( BufferType != DMELEMENT_HANDLE_INVALID )
        {
          v21 = g_pDataModel->GetElement(this: g_pDataModel, a2: BufferType);
          if ( v21 != nullptr && !v21->IsA(this: v21, a2: CDmeSource::m_classType) )
            *(_DWORD *)v19 = -1;
        }
        CDmeElementRefHelper::Ref(this: v19, hElement: *(_DWORD *)v19, handleType: HT_WEAK);
      }
      m_Size = nCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x105C6F30
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 0x48u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6F90
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 0x6Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD30
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD40
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x105C6F60
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6F70
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105C6FC0
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x105C6FD0
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD50
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x105CCD60
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::CTreeViewListControl::CColumnInfo,CUtlMemory<vgui::CTreeViewListControl::CColumnInfo,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace hammer_dll

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004B7F20
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = WindowName;
  else
    v4 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 364))(
                         a1: g_pDataModel.u,
                         a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x004B7F60
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = WindowName;
    else
      v7 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 364))(
                           a1: g_pDataModel.u,
                           a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004B8120
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return (*(const char *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 364))(
           a1: g_pDataModel.u,
           a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x004B8220
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x004B8250
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x004B8260
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x004B82A0
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x004B8330
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8360
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8450
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction();
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x004B84E0
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x004B84F0
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8520
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004B8560
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x004B85B0
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004B8E20
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x0059AD10
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AD70
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC70
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC80
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0059AD40
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059AD50
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059ADA0
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0059ADB0
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0059EC90
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0059ECA0
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace hlmv

// ============================================================
// Overlay from mdlcompile (Missing functions)
// ============================================================
namespace mdlcompile {

//------------------------------------------------------------------------------
// Address: 0x0050C4F0
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = pDeltaStateName;
  else
    v4 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 364))(
                         a1: g_pDataModel.u,
                         a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x0050C530
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = pDeltaStateName;
    else
      v7 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 364))(
                           a1: g_pDataModel.u,
                           a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0050C6F0
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return (*(const char *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 364))(
           a1: g_pDataModel.u,
           a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x0050C7F0
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x0050C820
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x0050C830
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x0050C870
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x0050C900
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050C930
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050CA20
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction();
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x0050CAD0
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x0050CAE0
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050CB10
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0050CB50
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x0050CBA0
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0050D400
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x005F02D0
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0330
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005F4240
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F4250
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005F0300
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0310
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F0360
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005F0370
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005F4260
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005F4270
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace mdlcompile

// ============================================================
// Overlay from particle_import (Missing functions)
// ============================================================
namespace particle_import {

//------------------------------------------------------------------------------
// Address: 0x00470B80
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = str;
  else
    v4 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00470BC0
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = str;
    else
      v7 = g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00470D80
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x00470E80
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00470EB0
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00470EC0
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00470F00
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00470F90
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00470FC0
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004710B0
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction();
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00471130
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x00471140
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00471170
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x004711B0
// Name: protected: virtual int CDmeMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x004711C0
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00471210
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x00471A80
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x00569ED0
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00569F30
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0056E170
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0056E180
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00569F00
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569F10
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00569F60
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00569F70
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0056E190
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0056E1A0
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace particle_import

// ============================================================
// Overlay from phogen (Missing functions)
// ============================================================
namespace phogen {

//------------------------------------------------------------------------------
// Address: 0x004748C0
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = &pParentName;
  else
    v4 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00474900
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = &pParentName;
    else
      v7 = g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00474AC0
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x00474BC0
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00474BF0
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00474C00
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00474C40
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00474CD0
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474D00
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474DF0
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction();
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00474E70
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x00474E80
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474EB0
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00474EF0
// Name: protected: virtual int CDmeMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x00474F00
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00474F50
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x004757B0
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x00579FD0
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A030
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2A0
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2B0
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057A000
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A010
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057A060
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057A070
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2C0
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057E2D0
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace phogen

// ============================================================
// Overlay from sceneviewer (Missing functions)
// ============================================================
namespace sceneviewer {

//------------------------------------------------------------------------------
// Address: 0x005205D0
// Name: public: void CDmeMakefile::GetSources<class CDmeSourceMayaFile>(class CUtlVector<class CDmeHandle<class CDmeSourceMayaFile,0>,class CUtlMemory<class CDmeHandle<class CDmeSourceMayaFile,0>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetSources<CDmeSourceMayaFile>(
        CDmeMakefile *this,
        CUtlMemory<vgui::TreeNode *,int> *sources)
{
  int m_Size; // ebx
  CDmeHandle<CDmeSourceMayaFile,0> *m_pMemory; // eax
  IMemAlloc_vtbl *v5; // edx
  CDmeHandle<CDmeSourceMayaFile,0> *v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // edi
  int m_nAllocationCount; // eax
  CDmeHandle<CDmeSourceMayaFile,0> *v11; // ecx
  int v12; // eax
  int v13; // edi
  int v14; // eax
  CExpressionCalculator *v15; // edi
  CExpressionCalculator *v16; // ecx
  CDmeElementRefHelper *v17; // edi
  int BufferType; // ebx
  int v19; // eax
  int nCount; // [esp+Ch] [ebp-Ch]
  int v21; // [esp+10h] [ebp-8h]
  int i; // [esp+20h] [ebp+8h]

  m_Size = this->m_Sources.m_Storage.m_Size;
  nCount = m_Size;
  if ( sources->m_nAllocationCount < m_Size && sources->m_nGrowSize >= 0 )
  {
    m_pMemory = (CDmeHandle<CDmeSourceMayaFile,0> *)sources->m_pMemory;
    sources->m_nAllocationCount = m_Size;
    v5 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v6 = (CDmeHandle<CDmeSourceMayaFile,0> *)((int (__stdcall *)(CDmeHandle<CDmeSourceMayaFile,0> *, int))v5->Realloc_2)(
                                                 a1: m_pMemory,
                                                 a2: 4 * m_Size);
    else
      v6 = (CDmeHandle<CDmeSourceMayaFile,0> *)((int (__stdcall *)(int))v5->Alloc_2)(a1: 4 * m_Size);
    sources->m_pMemory = (vgui::TreeNode **)v6;
  }
  sources[1].m_nAllocationCount = (int)sources->m_pMemory;
  i = 0;
  if ( m_Size > 0 )
  {
    do
    {
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[i]);
      v8 = v7;
      if ( v7 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeSource::m_classType.u) == 0 )
      {
        v8 = 0;
      }
      if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmeSourceMayaFile::m_classType.u) != 0 )
      {
        v9 = (int)sources[1].m_pMemory;
        m_nAllocationCount = sources->m_nAllocationCount;
        if ( v9 + 1 > m_nAllocationCount )
          CUtlMemory<IDmFormatUpdater *,int>::Grow(this: sources, num: v9 - m_nAllocationCount + 1);
        ++sources[1].m_pMemory;
        v11 = (CDmeHandle<CDmeSourceMayaFile,0> *)sources->m_pMemory;
        v12 = (int)sources[1].m_pMemory - v9 - 1;
        sources[1].m_nAllocationCount = (int)sources->m_pMemory;
        if ( v12 > 0 )
          _V_memmove(dest: &v11[v9 + 1], src: &v11[v9], count: 4 * v12);
        v13 = v9;
        v21 = v13 * 4;
        if ( &sources->m_pMemory[v13] != nullptr )
          sources->m_pMemory[v13] = (vgui::TreeNode *)-1;
        v14 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[i]);
        v15 = (CExpressionCalculator *)v14;
        if ( v14 != 0
          && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v14 + 16))(
               a1: v14,
               a2: CDmeSource::m_classType.u) != 0
          && (*((unsigned __int8 (__thiscall **)(CExpressionCalculator *, CUtlSymbolLarge::<unnamed_type_u>))v15->m_expr.m_Storage.m_Memory.m_pMemory
              + 4))(
               a1: v15,
               a2: CDmeSourceMayaFile::m_classType.u) != 0 )
        {
          v16 = v15;
        }
        else
        {
          v16 = nullptr;
        }
        v17 = (CDmeElementRefHelper *)sources->m_pMemory + v21;
        if ( v16 != nullptr )
          BufferType = CCodecBuffer_Block::GetBufferType(this: v16);
        else
          BufferType = -1;
        if ( BufferType != *(_DWORD *)v17 )
        {
          CDmeElementRefHelper::Unref(this: v17, hElement: *(_DWORD *)v17, handleType: HT_WEAK);
          *(_DWORD *)v17 = BufferType;
          if ( BufferType != -1 )
          {
            v19 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                    a1: g_pDataModel.u,
                    a2: BufferType);
            if ( v19 != 0
              && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v19 + 16))(
                   a1: v19,
                   a2: CDmeSourceMayaFile::m_classType.u) == 0 )
            {
              *(_DWORD *)v17 = -1;
            }
          }
          CDmeElementRefHelper::Ref(this: v17, hElement: *(_DWORD *)v17, handleType: HT_WEAK);
        }
      }
      ++i;
    }
    while ( i < nCount );
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4D50
// Name: public: void CDmeSource::OpenEditor(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OpenEditor(CDmeSource *this)
{
  if ( g_pDmeMakefileUtils != nullptr )
    g_pDmeMakefileUtils->PerformOpenEditor(this: g_pDmeMakefileUtils, a2: this);
}

//------------------------------------------------------------------------------
// Address: 0x005D4D70
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = defaultValue;
  else
    v4 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 364))(
                         a1: g_pDataModel.u,
                         a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x005D4DB0
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = defaultValue;
    else
      v7 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 364))(
                           a1: g_pDataModel.u,
                           a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4F70
// Name: private: void CDmeMakefile::RelativePathToFullPath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::RelativePathToFullPath(
        CDmeMakefile *this,
        const char *pRelativePath,
        char *pFullPath,
        int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v5; // eax
  char pRootDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( *pRelativePath != 0 )
  {
    m_fileId = this->m_fileId;
    if ( m_fileId == DMFILEID_INVALID )
      v5 = defaultValue;
    else
      v5 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 364))(
                           a1: g_pDataModel.u,
                           a2: m_fileId);
    V_ExtractFilePath(path: v5, dest: pRootDir, destSize: 260);
    V_ComposeFileName(path: pRootDir, filename: pRelativePath, dest: pFullPath, destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
  }
  else
  {
    *pFullPath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D4FF0
// Name: private: void CDmeMakefile::FullPathToRelativePath(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::FullPathToRelativePath(
        CDmeMakefile *this,
        const char *pFullPath,
        char *pRelativePath,
        int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v5; // eax
  char pRootDir[260]; // [esp+4h] [ebp-104h] BYREF

  if ( *pFullPath != 0 )
  {
    m_fileId = this->m_fileId;
    if ( m_fileId == DMFILEID_INVALID )
      v5 = defaultValue;
    else
      v5 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 364))(
                           a1: g_pDataModel.u,
                           a2: m_fileId);
    V_ExtractFilePath(path: v5, dest: pRootDir, destSize: 260);
    if ( pRootDir[0] != 0 )
    {
      V_MakeRelativePath(pFullPath, pDirectory: pRootDir, pRelativePath, nBufLen);
    }
    else
    {
      V_strncpy(pDest: pRelativePath, pSrc: pFullPath, maxLen: nBufLen);
      V_FixSlashes(pname: pRelativePath, separator: 92);
    }
  }
  else
  {
    *pRelativePath = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D5090
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return (*(const char *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 364))(
           a1: g_pDataModel.u,
           a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x005D50B0
// Name: public: class CDmeMakefile __near * CDmeSource::GetDependentMakefile(void)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__thiscall CDmeSource::GetDependentMakefile(CDmeSource *this)
{
  return (*(CDmeMakefile *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                               + 72))(
           a1: g_pDataModel.u,
           a2: this->m_DependentMakefile.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x005D50D0
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x005D5100
// Name: public: void CDmeMakefile::GetSourceFullPath(class CDmeSource __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetSourceFullPath(CDmeMakefile *this, CDmeSource *pSource, char *pFullPath, int nBufLen)
{
  const char *m_pAsString; // eax

  m_pAsString = pSource->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  CDmeMakefile::RelativePathToFullPath(this, pRelativePath: m_pAsString, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x005D5130
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x005D5140
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x005D5180
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x005D51B0
// Name: public: class CDmElement __near * CDmeMakefile::GetOutputElement(bool)
// Source: json
//------------------------------------------------------------------------------
CDmElement *__thiscall CDmeMakefile::GetOutputElement(CDmeMakefile *this, bool bCreateIfNecessary)
{
  CExpressionCalculator *v4; // eax
  DmElementHandle_t BufferType; // eax

  if ( (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_hOutput.m_handle) == 0 )
  {
    if ( !bCreateIfNecessary )
      return nullptr;
    if ( g_pDmeMakefileUtils == nullptr || !g_pDmeMakefileUtils->IsCurrentlyCompiling(this: g_pDmeMakefileUtils) )
    {
      v4 = (CExpressionCalculator *)this->CreateOutputElement(this);
      if ( v4 != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: v4);
      else
        BufferType = DMELEMENT_HANDLE_INVALID;
      CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: BufferType);
    }
  }
  return (*(CDmElement *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 72))(
           a1: g_pDataModel.u,
           a2: this->m_hOutput.m_handle);
}

//------------------------------------------------------------------------------
// Address: 0x005D5240
// Name: public: class CDmeSource __near * CDmeMakefile::FindSource(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::FindSource(CDmeMakefile *this, const char *pSourceType, const char *pFullPath)
{
  int v4; // edi
  int v5; // eax
  int v6; // esi
  const char *v7; // eax
  int v8; // eax
  int v9; // esi
  const char *v10; // eax
  int v12; // eax
  int v13; // esi
  char pRelativePath[260]; // [esp+Ch] [ebp-104h] BYREF
  int nCount; // [esp+11Ch] [ebp+Ch]

  CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
  v4 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
    v6 = v5;
    if ( v5 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
           a1: v5,
           a2: CDmeSource::m_classType.u) == 0 )
    {
      v6 = 0;
    }
    v7 = *(const char **)(v6 + 52);
    if ( v7 == (const char *)-1 )
      v7 = defaultValue;
    if ( _V_stricmp(s1: pSourceType, s2: v7) == 0 )
    {
      v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
      v9 = v8;
      if ( v8 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
             a1: v8,
             a2: CDmeSource::m_classType.u) == 0 )
      {
        v9 = 0;
      }
      v10 = *(const char **)(v9 + 20);
      if ( v10 == (const char *)-1 )
        v10 = defaultValue;
      if ( _V_stricmp(s1: pRelativePath, s2: v10) == 0 )
        break;
    }
    if ( ++v4 >= nCount )
      return nullptr;
  }
  v12 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
          a1: g_pDataModel.u,
          a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
  v13 = v12;
  if ( v12 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v12 + 16))(
         a1: v12,
         a2: CDmeSource::m_classType.u) != 0 )
  {
    return (CDmeSource *)v13;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D5380
// Name: public: void CDmeMakefile::SetSourceFullPath(class CDmeSource __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::SetSourceFullPath(CDmeMakefile *this, CDmeSource *pSource, const char *pFullPath)
{
  const char *m_pAsString; // eax
  char pRelativePath[260]; // [esp+4h] [ebp-104h] BYREF

  CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
  m_pAsString = pSource->m_Name.m_Storage.u.m_pAsString;
  if ( m_pAsString == (const char *)-1 )
    m_pAsString = defaultValue;
  if ( _V_stricmp(s1: pRelativePath, s2: m_pAsString) != 0 )
  {
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 200))(
      a1: g_pDataModel.u,
      a2: &pFullPath,
      a3: pRelativePath);
    CDmAttribute::SetValue<CUtlSymbolLarge>(
      this: pSource->m_Name.m_pAttribute,
      value: (const CUtlSymbolLarge *)&pFullPath);
    CDmeHandle<CDmeMakefile,0>::Set(this: &pSource->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D5400
// Name: public: class CDmeSource __near * CDmeMakefile::GetSource(int)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::GetSource(CDmeMakefile *this, int nIndex)
{
  int v2; // eax
  int v3; // esi

  v2 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[nIndex]);
  v3 = v2;
  if ( v2 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v2 + 16))(
         a1: v2,
         a2: CDmeSource::m_classType.u) != 0 )
  {
    return (CDmeSource *)v3;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D5450
// Name: public: void CDmeMakefile::RemoveSource(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::RemoveSource(CDmeMakefile *this, CDmeSource *pSource)
{
  int v2; // edi
  CDmaElementArray<CDmeSource> *p_m_Sources; // ebx
  int v4; // eax
  CDmeSource *v5; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  v2 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount > 0 )
  {
    p_m_Sources = &this->m_Sources;
    while ( 1 )
    {
      v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: p_m_Sources->m_Storage.m_Memory.m_pMemory[v2]);
      v5 = (CDmeSource *)v4;
      if ( v4 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
             a1: v4,
             a2: CDmeSource::m_classType.u) == 0 )
      {
        v5 = nullptr;
      }
      if ( v5 == pSource )
        break;
      if ( ++v2 >= nCount )
        return;
    }
    CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::Remove(
      this: p_m_Sources,
      elem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D54D0
// Name: public: bool CDmeMakefile::HasSourceOfType(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::HasSourceOfType(CDmeMakefile *this, const char *pSourceType)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  const char *v6; // eax

  v3 = this->m_Sources.m_Storage.m_Size - 1;
  if ( v3 < 0 )
    return 0;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeSource::m_classType.u) == 0 )
    {
      v5 = 0;
    }
    v6 = *(const char **)(v5 + 52);
    if ( v6 == (const char *)-1 )
      v6 = defaultValue;
    if ( _V_stricmp(s1: pSourceType, s2: v6) == 0 )
      break;
    if ( --v3 < 0 )
      return 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005D5550
// Name: private: bool CDmeMakefile::UpdateSourceNames(char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::UpdateSourceNames(
        CDmeMakefile *this,
        const char *pOldRootDir,
        const char *pNewRootDir,
        bool bApplyChanges)
{
  int v5; // edi
  int v6; // eax
  int v7; // esi
  const char *v8; // eax
  bool result; // al
  int v10; // eax
  int v11; // esi
  char pNewSourcePath[260]; // [esp+Ch] [ebp-210h] BYREF
  char pOldSourcePath[260]; // [esp+110h] [ebp-10Ch] BYREF
  CUtlSymbolLarge value; // [esp+214h] [ebp-8h] BYREF
  int nCount; // [esp+218h] [ebp-4h]

  v5 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount > 0 )
  {
    do
    {
      v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v5]);
      v7 = v6;
      if ( v6 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v6 + 16))(
             a1: v6,
             a2: CDmeSource::m_classType.u) == 0 )
      {
        v7 = 0;
      }
      v8 = *(const char **)(v7 + 20);
      if ( v8 == (const char *)-1 || *v8 == 0 )
      {
        pNewSourcePath[0] = 0;
      }
      else
      {
        V_ComposeFileName(path: pOldRootDir, filename: v8, dest: pOldSourcePath, destSize: 260);
        V_RemoveDotSlashes(pFilename: pOldSourcePath, separator: 92);
        result = V_MakeRelativePath(
                   pFullPath: pOldSourcePath,
                   pDirectory: pNewRootDir,
                   pRelativePath: pNewSourcePath,
                   nBufLen: 260);
        if ( !result )
          return result;
      }
      if ( bApplyChanges )
      {
        v10 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                a1: g_pDataModel.u,
                a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v5]);
        v11 = v10;
        if ( v10 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v10 + 16))(
               a1: v10,
               a2: CDmeSource::m_classType.u) == 0 )
        {
          v11 = 0;
        }
        (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, CUtlSymbolLarge *, char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                             + 200))(
          a1: g_pDataModel.u,
          a2: &value,
          a3: pNewSourcePath);
        CDmAttribute::SetValue<CUtlSymbolLarge>(this: *(CDmAttribute **)(v11 + 24), &value);
      }
      ++v5;
    }
    while ( v5 < nCount );
  }
  return true;
}

//------------------------------------------------------------------------------
// Address: 0x005D5680
// Name: public: bool CDmeMakefile::SetFileName(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::SetFileName(CDmeMakefile *this, const char *pFileName)
{
  const char *v4; // eax
  DmFileId_t m_fileId; // eax
  int v6; // edx
  DmFileId_t v7; // eax
  char pOldRootDir[260]; // [esp+8h] [ebp-208h] BYREF
  char pNewRootDir[260]; // [esp+10Ch] [ebp-104h] BYREF

  if ( !V_IsAbsolutePath(pStr: pFileName) )
    return 0;
  v4 = this->m_fileId == DMFILEID_INVALID
     ? defaultValue
     : (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 364))(
                       a1: g_pDataModel.u,
                       a2: this->m_fileId);
  V_ExtractFilePath(path: v4, dest: pOldRootDir, destSize: 260);
  V_ExtractFilePath(path: pFileName, dest: pNewRootDir, destSize: 260);
  if ( !CDmeMakefile::UpdateSourceNames(this, pOldRootDir, pNewRootDir, bApplyChanges: false) )
    return 0;
  CDmeMakefile::UpdateSourceNames(this, pOldRootDir, pNewRootDir, bApplyChanges: true);
  m_fileId = this->m_fileId;
  v6 = *(_DWORD *)g_pDataModel.u.m_Id;
  if ( m_fileId == DMFILEID_INVALID )
  {
    v7 = (*(int (__stdcall **)(const char *))(v6 + 356))(a1: pFileName);
    CDmElement::SetFileId(this, fileid: v7, depth: TD_DEEP, bOnlyIfMatch: false);
  }
  else
  {
    (*(void (__stdcall **)(DmFileId_t, const char *))(v6 + 368))(a1: m_fileId, a2: pFileName);
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x005D5770
// Name: public: void CDmeMakefile::SetAssociation(class CDmeSource __near *,class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::SetAssociation(CDmeMakefile *this, CDmeSource *pSource, CDmeMakefile *pSourceMakefile)
{
  int v4; // edi
  int v5; // eax
  CDmeSource *v6; // esi
  int v7; // eax
  int v8; // esi
  int v9; // eax
  CDmeHandle<CDmeMakefile,0> *v10; // esi
  DmElementHandle_t BufferType; // eax
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pSource != nullptr )
  {
    v4 = 0;
    nCount = this->m_Sources.m_Storage.m_Size;
    if ( nCount > 0 )
    {
      while ( 1 )
      {
        v5 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
        v6 = (CDmeSource *)v5;
        if ( v5 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v5 + 16))(
               a1: v5,
               a2: CDmeSource::m_classType.u) == 0 )
        {
          v6 = nullptr;
        }
        if ( v6 == pSource )
          break;
        if ( ++v4 >= nCount )
          return;
      }
      v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 72))(
             a1: g_pDataModel.u,
             a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
      v8 = v7;
      if ( v7 == 0
        || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
             a1: v7,
             a2: CDmeSource::m_classType.u) == 0 )
      {
        v8 = 0;
      }
      if ( pSourceMakefile != (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                                                a1: g_pDataModel.u,
                                                a2: *(_DWORD *)(v8 + 68)) )
      {
        v9 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                         + 72))(
               a1: g_pDataModel.u,
               a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v4]);
        v10 = (CDmeHandle<CDmeMakefile,0> *)v9;
        if ( v9 == 0
          || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v9 + 16))(
               a1: v9,
               a2: CDmeSource::m_classType.u) == 0 )
        {
          v10 = nullptr;
        }
        if ( pSourceMakefile != nullptr )
        {
          BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)pSourceMakefile);
          CDmeHandle<CDmeMakefile,0>::Set(this: v10 + 17, h: BufferType);
        }
        else
        {
          CDmeHandle<CDmeMakefile,0>::Set(this: v10 + 17, h: DMELEMENT_HANDLE_INVALID);
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D5890
// Name: public: class CDmeMakefile __near * CDmeMakefile::FindDependentMakefile(class CDmeSource __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeMakefile *__thiscall CDmeMakefile::FindDependentMakefile(CDmeMakefile *this, CDmeSource *pSource)
{
  int v3; // edi
  int v4; // eax
  CDmeSource *v5; // esi
  int v7; // eax
  int v8; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pSource == nullptr )
    return nullptr;
  v3 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = (CDmeSource *)v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeSource::m_classType.u) == 0 )
    {
      v5 = nullptr;
    }
    if ( v5 == pSource )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
  v8 = v7;
  if ( v7 == 0
    || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmeSource::m_classType.u) == 0 )
  {
    v8 = 0;
  }
  return (*(CDmeMakefile *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
           a1: g_pDataModel.u,
           a2: *(_DWORD *)(v8 + 68));
}

//------------------------------------------------------------------------------
// Address: 0x005D5950
// Name: public: class CDmeSource __near * CDmeMakefile::FindAssociatedSource(class CDmeMakefile __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::FindAssociatedSource(CDmeMakefile *this, CDmeMakefile *pChildMakefile)
{
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v7; // eax
  int v8; // esi
  int nCount; // [esp+Ch] [ebp-4h]

  if ( pChildMakefile == nullptr )
    return nullptr;
  v3 = 0;
  nCount = this->m_Sources.m_Storage.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
    v5 = v4;
    if ( v4 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v4 + 16))(
           a1: v4,
           a2: CDmeSource::m_classType.u) == 0 )
    {
      v5 = 0;
    }
    if ( (CDmeMakefile *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                          + 72))(
                           a1: g_pDataModel.u,
                           a2: *(_DWORD *)(v5 + 68)) == pChildMakefile )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: this->m_Sources.m_Storage.m_Memory.m_pMemory[v3]);
  v8 = v7;
  if ( v7 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmeSource::m_classType.u) != 0 )
  {
    return (CDmeSource *)v8;
  }
  else
  {
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D5A10
// Name: public: class CDmeSource __near * CDmeMakefile::AddSource(char const __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
CDmeSource *__thiscall CDmeMakefile::AddSource(CDmeMakefile *this, const char *pSourceType, const char *pFullPath)
{
  const char *v3; // esi
  int v6; // eax
  int v7; // eax
  int v8; // esi
  int v9; // edi
  int BufferType; // eax
  char pRelativePath[260]; // [esp+Ch] [ebp-104h] BYREF

  v3 = pFullPath;
  if ( *pFullPath != 0 && CDmeMakefile::FindSource(this, pSourceType, pFullPath) != nullptr )
  {
    _Warning(a1: "Attempted to add the same source twice %s!\n", v3);
    return nullptr;
  }
  v6 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char *, const char *, DmFileId_t, _DWORD))(*(_DWORD *)g_pDataModel.u.m_Id + 60))(
         a1: g_pDataModel.u,
         a2: pSourceType,
         a3: defaultValue,
         a4: this->m_fileId,
         a5: 0);
  v7 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
         a1: g_pDataModel.u,
         a2: v6);
  v8 = v7;
  if ( v7 != 0
    && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v7 + 16))(
         a1: v7,
         a2: CDmElement::m_classType.u) != 0 )
  {
    if ( (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
           a1: v8,
           a2: CDmeSource::m_classType.u) != 0 )
    {
      CDmeMakefile::FullPathToRelativePath(this, pFullPath, pRelativePath, nBufLen: 260);
      (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, const char **, char *))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                       + 200))(
        a1: g_pDataModel.u,
        a2: &pFullPath,
        a3: pRelativePath);
      CDmAttribute::SetValue<CUtlSymbolLarge>(
        this: *(CDmAttribute **)(v8 + 24),
        value: (const CUtlSymbolLarge *)&pFullPath);
      pFullPath = (const char *)CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v8);
      CDmaArrayBase<enum DmElementHandle_t,CDmaDataInternal<CUtlVector<enum DmElementHandle_t,CUtlMemory<enum DmElementHandle_t,int>>>>::AddToTail(
        this: &this->m_Sources,
        src: (const DmElementHandle_t *)&pFullPath);
      return (CDmeSource *)v8;
    }
  }
  else
  {
    v8 = 0;
  }
  _Warning(a1: "Invalid source type name %s!\n", pSourceType);
  if ( v8 != 0 )
  {
    v9 = *(_DWORD *)g_pDataModel.u.m_Id;
    BufferType = CCodecBuffer_Block::GetBufferType(this: (CExpressionCalculator *)v8);
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(v9 + 68))(a1: g_pDataModel.u, a2: BufferType);
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x005D5B50
// Name: public: void CDmeMakefile::GetSources(char const __near *,class CUtlVector<class CDmeHandle<class CDmeSource,0>,class CUtlMemory<class CDmeHandle<class CDmeSource,0>,int>> __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetSources(
        CDmeMakefile *this,
        const char *pSourceType,
        CUtlMemory<vgui::TreeNode *,int> *sources)
{
  int m_Size; // ebx
  CDmeHandle<CDmeSource,0> *m_pMemory; // eax
  IMemAlloc_vtbl *v6; // edx
  CDmeHandle<CDmeSource,0> *v7; // eax
  int v8; // eax
  int v9; // edi
  int v10; // edi
  int m_nAllocationCount; // eax
  CDmeHandle<CDmeSource,0> *v12; // ecx
  int v13; // eax
  int v14; // ebx
  CDmeHandle<CDmeSource,0> *v15; // eax
  int v16; // eax
  CExpressionCalculator *v17; // edi
  CExpressionCalculator *v18; // ecx
  CDmeElementRefHelper *v19; // edi
  int BufferType; // ebx
  int v21; // eax
  int v22; // [esp+Ch] [ebp-Ch] BYREF
  int nCount; // [esp+10h] [ebp-8h]
  CDmeMakefile *v24; // [esp+14h] [ebp-4h]
  int i; // [esp+24h] [ebp+Ch]

  m_Size = this->m_Sources.m_Storage.m_Size;
  v24 = this;
  nCount = m_Size;
  if ( sources->m_nAllocationCount < m_Size && sources->m_nGrowSize >= 0 )
  {
    m_pMemory = (CDmeHandle<CDmeSource,0> *)sources->m_pMemory;
    sources->m_nAllocationCount = m_Size;
    v6 = _g_pMemAlloc->__vftable;
    if ( m_pMemory != nullptr )
      v7 = (CDmeHandle<CDmeSource,0> *)((int (__stdcall *)(CDmeHandle<CDmeSource,0> *, int))v6->Realloc_2)(
                                         a1: m_pMemory,
                                         a2: 4 * m_Size);
    else
      v7 = (CDmeHandle<CDmeSource,0> *)((int (__stdcall *)(int))v6->Alloc_2)(a1: 4 * m_Size);
    sources->m_pMemory = (vgui::TreeNode **)v7;
  }
  sources[1].m_nAllocationCount = (int)sources->m_pMemory;
  for ( i = 0; i < m_Size; ++i )
  {
    v8 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                     + 72))(
           a1: g_pDataModel.u,
           a2: v24->m_Sources.m_Storage.m_Memory.m_pMemory[i]);
    v9 = v8;
    if ( v8 == 0
      || (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v8 + 16))(
           a1: v8,
           a2: CDmeSource::m_classType.u) == 0 )
    {
      v9 = 0;
    }
    (*(void (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int *, const char *))(*(_DWORD *)g_pDataModel.u.m_Id + 200))(
      a1: g_pDataModel.u,
      a2: &v22,
      a3: pSourceType);
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)v9 + 16))(a1: v9, a2: v22) != 0 )
    {
      v10 = (int)sources[1].m_pMemory;
      m_nAllocationCount = sources->m_nAllocationCount;
      if ( v10 + 1 > m_nAllocationCount )
        CUtlMemory<IDmFormatUpdater *,int>::Grow(this: sources, num: v10 - m_nAllocationCount + 1);
      ++sources[1].m_pMemory;
      v12 = (CDmeHandle<CDmeSource,0> *)sources->m_pMemory;
      v13 = (int)sources[1].m_pMemory - v10 - 1;
      sources[1].m_nAllocationCount = (int)sources->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &v12[v10 + 1], src: &v12[v10], count: 4 * v13);
      v14 = v10;
      v15 = (CDmeHandle<CDmeSource,0> *)&sources->m_pMemory[v10];
      if ( v15 != nullptr )
        v15->m_handle = DMELEMENT_HANDLE_INVALID;
      v16 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                        + 72))(
              a1: g_pDataModel.u,
              a2: v24->m_Sources.m_Storage.m_Memory.m_pMemory[i]);
      v17 = (CExpressionCalculator *)v16;
      if ( v16 != 0
        && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v16 + 16))(
             a1: v16,
             a2: CDmeSource::m_classType.u) != 0 )
      {
        v18 = v17;
      }
      else
      {
        v18 = nullptr;
      }
      v19 = (CDmeElementRefHelper *)&sources->m_pMemory[v14];
      if ( v18 != nullptr )
        BufferType = CCodecBuffer_Block::GetBufferType(this: v18);
      else
        BufferType = -1;
      if ( BufferType != *(_DWORD *)v19 )
      {
        CDmeElementRefHelper::Unref(this: v19, hElement: *(_DWORD *)v19, handleType: HT_WEAK);
        *(_DWORD *)v19 = BufferType;
        if ( BufferType != -1 )
        {
          v21 = (*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, int))(*(_DWORD *)g_pDataModel.u.m_Id + 72))(
                  a1: g_pDataModel.u,
                  a2: BufferType);
          if ( v21 != 0
            && (*(unsigned __int8 (__thiscall **)(int, CUtlSymbolLarge::<unnamed_type_u>))(*(_DWORD *)v21 + 16))(
                 a1: v21,
                 a2: CDmeSource::m_classType.u) == 0 )
          {
            *(_DWORD *)v19 = -1;
          }
        }
        CDmeElementRefHelper::Ref(this: v19, hElement: *(_DWORD *)v19, handleType: HT_WEAK);
      }
      m_Size = nCount;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x005D5DA0
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D5DD0
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D5E10
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x005D5ED0
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x005D5F50
// Name: protected: void CDmeMakefile::MakeOutputsWriteable(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::MakeOutputsWriteable(CDmeMakefile *this)
{
  void (__thiscall *GetOutputs)(CDmeMakefile *, CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > *); // eax
  int v2; // edi
  int m_Size; // ebx
  IBaseFileSystem_vtbl *v4; // esi
  const char *v5; // eax
  CUtlString *m_pMemory; // eax
  CUtlVector<CUtlString,CUtlMemory<CUtlString,int> > outputs; // [esp+8h] [ebp-14h] BYREF

  GetOutputs = this->GetOutputs;
  v2 = 0;
  memset(&outputs, 0, sizeof(outputs));
  GetOutputs(this, a2: &outputs);
  m_Size = outputs.m_Size;
  if ( outputs.m_Size > 0 )
  {
    do
    {
      v4 = g_pFullFileSystem->IBaseFileSystem::__vftable;
      v5 = CUtlString::operator char const *(this: &outputs.m_Memory.m_pMemory[v2]);
      v4->SetFileWritable(this: &g_pFullFileSystem->IBaseFileSystem, a2: v5, a3: true, a4: nullptr);
      ++v2;
      --m_Size;
    }
    while ( m_Size != 0 );
  }
  CUtlVector<CUtlBinaryBlock,CUtlMemory<CUtlBinaryBlock,int>>::RemoveAll(this: &outputs);
  m_pMemory = outputs.m_Memory.m_pMemory;
  if ( outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( outputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: outputs.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      outputs.m_Memory.m_pMemory = nullptr;
    }
    outputs.m_Memory.m_nAllocationCount = 0;
  }
  outputs.m_pElements = m_pMemory;
  if ( outputs.m_Memory.m_nGrowSize >= 0 && m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x005D6000
// Name: public: void CDmeMakefile::PreCompile(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PreCompile(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  CDmeMakefile::MakeOutputsWriteable(this);
  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x005D6040
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x005D6050
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D6080
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005D60C0
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x005D6110
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction((vgui::PropertyPage *)this);
}

//------------------------------------------------------------------------------
// Address: 0x006B0590
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B05F0
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B5110
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B5120
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B05C0
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B05D0
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B0620
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B0630
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B5130
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006B5140
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace sceneviewer

// ============================================================
// Overlay from sfmgen (Missing functions)
// ============================================================
namespace sfmgen {

//------------------------------------------------------------------------------
// Address: 0x00475620
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = &pch;
  else
    v4 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00475660
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = &pch;
    else
      v7 = g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00475820
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x004758B0
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x004758E0
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x004758F0
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00475930
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x004759C0
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x004759F0
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475A30
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x00475AF0
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction();
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00475B70
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x00475B80
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475BB0
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00475BF0
// Name: protected: virtual int CDmeMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x00475C00
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00475C50
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x0057BFC0
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C020
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x00580280
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x00580290
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057BFF0
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C000
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057C050
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x0057C060
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005802A0
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005802B0
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace sfmgen

// ============================================================
// Overlay from studiomdl (Missing functions)
// ============================================================
namespace studiomdl {

//------------------------------------------------------------------------------
// Address: 0x00505550
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = pDeltaStateName;
  else
    v4 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                            + 364))(
                         a1: g_pDataModel.u,
                         a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00505590
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = pDeltaStateName;
    else
      v7 = (const char *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                              + 364))(
                           a1: g_pDataModel.u,
                           a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00505750
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return (*(const char *(__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmFileId_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                      + 364))(
           a1: g_pDataModel.u,
           a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x00505850
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00505880
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00505890
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x005058D0
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00505960
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00505990
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x005059D0
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x00505A90
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction();
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00505B10
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x00505B20
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00505B50
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00505B90
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction();
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00505BE0
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = (CDmElement *)(*(int (__thiscall **)(CUtlSymbolLarge::<unnamed_type_u>, DmElementHandle_t))(*(_DWORD *)g_pDataModel.u.m_Id
                                                                                                 + 72))(
                       a1: g_pDataModel.u,
                       a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction();
}

//------------------------------------------------------------------------------
// Address: 0x005E9170
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005E91D0
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0E0
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005ED0F0
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005E91A0
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E91B0
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005E9200
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005E9210
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x005ED100
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x005ED110
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>::~CUtlVector<VertIndices_t,CUtlMemory<VertIndices_t,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace studiomdl

// ============================================================
// Overlay from uvlightmap (Missing functions)
// ============================================================
namespace uvlightmap {

//------------------------------------------------------------------------------
// Address: 0x0047F840
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = Ptr;
  else
    v4 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x0047F880
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = Ptr;
    else
      v7 = g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x0047FA40
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x0047FB40
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x0047FB70
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x0047FB80
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x0047FBC0
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x0047FC50
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FC80
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FCC0
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x0047FD80
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x0047FE00
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x0047FE10
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FE40
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x0047FE80
// Name: protected: virtual int CDmeMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x0047FE90
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x0047FEE0
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00579870
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 72,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x005798D0
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 108,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x0057D990
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9A0
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x005798A0
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x005798B0
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x00579900
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x00579910
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9B0
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x0057D9C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>::~CUtlVector<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,CUtlMemory<CUtlSymbolTableLargeBase<CThreadsafeTree<0>,0>::StringPool_t *,int>>(this: (CUtlVector<CMDLAttachmentData,CUtlMemory<CMDLAttachmentData,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace uvlightmap

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00582630
// Name: protected: void CDmeMakefile::GetMakefilePath(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::GetMakefilePath(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  DmFileId_t m_fileId; // eax
  const char *v4; // eax

  m_fileId = this->m_fileId;
  if ( m_fileId == DMFILEID_INVALID )
    v4 = var;
  else
    v4 = g_pDataModel->GetFileName(this: g_pDataModel, a2: m_fileId);
  V_ExtractFilePath(path: v4, dest: pFullPath, destSize: nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00582670
// Name: public: bool CDmeMakefile::GetDefaultDirectory(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetDefaultDirectory(
        CDmeMakefile *this,
        const char *pDefaultDirectoryID,
        char *pFullPath,
        int nBufLen)
{
  const char *v4; // esi
  char *v6; // edi
  const char *v7; // eax
  int v9; // [esp-4h] [ebp-520h]
  char pMakefileGamePath[260]; // [esp+8h] [ebp-514h] BYREF
  char pMakefilePath[260]; // [esp+10Ch] [ebp-410h] BYREF
  char pModDirectory[260]; // [esp+210h] [ebp-30Ch] BYREF
  char pRelativePath[260]; // [esp+314h] [ebp-208h] BYREF
  char pModContentDirectory[260]; // [esp+418h] [ebp-104h] BYREF

  v4 = pDefaultDirectoryID;
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "contentdir:") != nullptr )
  {
    v9 = nBufLen;
    v4 = pDefaultDirectoryID + 11;
LABEL_15:
    v6 = pFullPath;
    GetModContentSubdirectory(pSubDir: v4, pBuf: pFullPath, nBufLen: v9);
    goto LABEL_16;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "gamedir:") != nullptr )
  {
    v6 = pFullPath;
    GetModSubdirectory(pSubDir: pDefaultDirectoryID + 8, pBuf: pFullPath, nBufLen);
LABEL_16:
    V_RemoveDotSlashes(pFilename: v6, separator: 92);
    return 1;
  }
  if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefiledir:") != nullptr )
  {
    if ( this->m_fileId == DMFILEID_INVALID )
      v7 = var;
    else
      v7 = g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
    V_ExtractFilePath(path: v7, dest: pModContentDirectory, destSize: 260);
    V_ComposeFileName(
      path: pModContentDirectory,
      filename: pDefaultDirectoryID + 12,
      dest: pFullPath,
      destSize: nBufLen);
    V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
    return 1;
  }
  else
  {
    if ( StringAfterPrefix(str: pDefaultDirectoryID, prefix: "makefilegamedir:") == nullptr )
    {
      v9 = nBufLen;
      goto LABEL_15;
    }
    CDmeMakefile::GetMakefilePath(this, pFullPath: pMakefilePath, nBufLen: 260);
    GetModContentSubdirectory(pSubDir: nullptr, pBuf: pModContentDirectory, nBufLen: 260);
    if ( V_MakeRelativePath(pFullPath: pMakefilePath, pDirectory: pModContentDirectory, pRelativePath, nBufLen: 260) )
    {
      GetModSubdirectory(pSubDir: nullptr, pBuf: pModDirectory, nBufLen: 260);
      V_ComposeFileName(path: pModDirectory, filename: pRelativePath, dest: pMakefileGamePath, destSize: 260);
      V_ComposeFileName(path: pMakefileGamePath, filename: pDefaultDirectoryID + 16, dest: pFullPath, destSize: nBufLen);
      V_RemoveDotSlashes(pFilename: pFullPath, separator: 92);
      return 1;
    }
    else
    {
      *pFullPath = 0;
      return 0;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00582830
// Name: public: char const __near * CDmeMakefile::GetFileName(void)const
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetFileName(CDmeMakefile *this)
{
  return g_pDataModel->GetFileName(this: g_pDataModel, a2: this->m_fileId);
}

//------------------------------------------------------------------------------
// Address: 0x00582930
// Name: public: bool CDmeMakefile::GetOutputDirectory(char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CDmeMakefile::GetOutputDirectory(CDmeMakefile *this, char *pFullPath, int nBufLen)
{
  const char *v4; // eax

  v4 = this->GetOutputDirectoryID(this);
  return CDmeMakefile::GetDefaultDirectory(this, pDefaultDirectoryID: v4, pFullPath, nBufLen);
}

//------------------------------------------------------------------------------
// Address: 0x00582960
// Name: protected: void CDmeSource::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::OnConstruction(CDmeSource *this)
{
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00582970
// Name: protected: void CDmeMakefile::OnConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnConstruction(CDmeMakefile *this)
{
  CDmaElementArray<CDmeSource> *p_m_Sources; // edi

  p_m_Sources = &this->m_Sources;
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: p_m_Sources->m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x005829B0
// Name: protected: void CDmeMakefile::OnDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::OnDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00582A40
// Name: public: virtual bool CDmeSource::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeSource::IsA(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00582A70
// Name: public: virtual int CDmeSource::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::GetInheritanceDepth(CDmeSource *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeSource::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00582B60
// Name: protected: virtual void CDmeSource::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeSource::PerformConstruction(CDmeSource *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  CDmeHandle<CDmeMakefile,0>::Set(this: &this->m_DependentMakefile, h: DMELEMENT_HANDLE_INVALID);
}

//------------------------------------------------------------------------------
// Address: 0x00582BE0
// Name: private: virtual char const __near * CDmeMakefile::GetOutputDirectoryID(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CDmeMakefile::GetOutputDirectoryID(CDmeMakefile *this)
{
  return "makefilegamedir:";
}

//------------------------------------------------------------------------------
// Address: 0x00582BF0
// Name: public: virtual bool CDmeMakefile::IsA(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
bool __thiscall CDmeMakefile::IsA(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  return typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id
      || CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id
      || typeSymbol.u.m_Id == -1;
}

//------------------------------------------------------------------------------
// Address: 0x00582C20
// Name: public: virtual int CDmeMakefile::GetInheritanceDepth(class CUtlSymbolLarge)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::GetInheritanceDepth(CDmeMakefile *this, CUtlSymbolLarge typeSymbol)
{
  if ( typeSymbol.u.m_Id == CDmeMakefile::m_classType.u.m_Id )
    return 0;
  if ( CDmElement::m_classType.u.m_Id == typeSymbol.u.m_Id || typeSymbol.u.m_Id == -1 )
    return 1;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x00582C60
// Name: protected: virtual int CDmeMakefile::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeMakefile::AllocatedSize(CDmeMakefile *this)
{
  return 108;
}

//------------------------------------------------------------------------------
// Address: 0x00582C70
// Name: protected: virtual void CDmeMakefile::PerformConstruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformConstruction(CDmeMakefile *this)
{
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
  this->m_Sources.m_pAttribute = CDmElement::AddExternalAttribute(
                                   this,
                                   pAttributeName: "sources",
                                   type: AT_FIRST_ARRAY_TYPE,
                                   pMemory: &this->m_Sources);
  CDmAttribute::SetElementTypeSymbol(this: this->m_Sources.m_pAttribute, typeSymbol: CDmeSource::m_classType);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  this->m_hCompileProcess = nullptr;
  this->m_bIsDirty = false;
}

//------------------------------------------------------------------------------
// Address: 0x00582CC0
// Name: protected: virtual void CDmeMakefile::PerformDestruction(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CDmeMakefile::PerformDestruction(CDmeMakefile *this)
{
  CDmElement *v2; // eax

  v2 = g_pDataModel->GetElement(this: g_pDataModel, a2: this->m_hOutput.m_handle);
  this->DestroyOutputElement(this, a2: v2);
  CDmeHandle<CDmElement,0>::Set(this: &this->m_hOutput, h: DMELEMENT_HANDLE_INVALID);
  CDmeFXClip::OnDestruction((CDataManagerBase *)this);
}

//------------------------------------------------------------------------------
// Address: 0x00583520
// Name: protected: virtual int CDmeSource::AllocatedSize(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CDmeSource::AllocatedSize(CDmeSourceCollisionModel *this)
{
  return 72;
}

//------------------------------------------------------------------------------
// Address: 0x006B7780
// Name: _dynamic_initializer_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeSource::s_Allocator,
    blockSize: 0x48u,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeSource pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeSource::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006B77E0
// Name: _dynamic_initializer_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
int dynamic_initializer_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::CUtlMemoryPool(
    this: &CDmeMakefile::s_Allocator,
    blockSize: 0x6Cu,
    numElements: 1024,
    growMode: 2,
    pszAllocOwner: "CDmeMakefile pool",
    nAlignment: 0);
  return atexit(func: dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__);
}

//------------------------------------------------------------------------------
// Address: 0x006BC790
// Name: _dynamic_atexit_destructor_for__CDmeSource::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeSource::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeSource::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006BC7A0
// Name: _dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__
// Source: semantic_dyn_target_class
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__CDmeMakefile::s_Allocator__()
{
  CUtlMemoryPool::~CUtlMemoryPool(this: &CDmeMakefile::s_Allocator);
}

//------------------------------------------------------------------------------
// Address: 0x006B77B0
// Name: _dynamic_initializer_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeSource_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeSource_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B77C0
// Name: _dynamic_initializer_for__g_CDmeSource_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeSource_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeSource_Helper,
           classname: "DmeSource",
           pFactory: &g_CDmeSource_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006B7810
// Name: _dynamic_initializer_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CDmeMakefile_Factory__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__);
}

//------------------------------------------------------------------------------
// Address: 0x006B7820
// Name: _dynamic_initializer_for__g_CDmeMakefile_Helper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
CDmElementFactoryHelper *dynamic_initializer_for__g_CDmeMakefile_Helper__()
{
  return CDmElementFactoryHelper::CDmElementFactoryHelper(
           this: &g_CDmeMakefile_Helper,
           classname: "DmeMakefile",
           pFactory: &g_CDmeMakefile_Factory,
           bIsStandardFactory: true);
}

//------------------------------------------------------------------------------
// Address: 0x006BC7B0
// Name: _dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeMakefile_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeMakefile_Factory.m_CallBackList);
}

//------------------------------------------------------------------------------
// Address: 0x006BC7C0
// Name: _dynamic_atexit_destructor_for__g_CDmeSource_Factory__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CDmeSource_Factory__()
{
  CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>::~CUtlVector<TextureData_t,CUtlMemory<TextureData_t,int>>(this: (CUtlVector<CVTFTexture::ResourceMemorySection,CUtlMemory<CVTFTexture::ResourceMemorySection,int> > *)&g_CDmeSource_Factory.m_CallBackList);
}

} // namespace vmap
