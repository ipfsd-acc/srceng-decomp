// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlfaceposer/faceposerworkspace.cpp
// Functions: 6
// ============================================================

#include "utils\hlfaceposer\faceposerworkspace.h"

//------------------------------------------------------------------------------
// Address: 0x004573F0
// Name: public: virtual void CWorkspaceFiles::StartStoringFiles(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceFiles::StartStoringFiles(CWorkspaceFiles *this, int type)
{
  this->m_nStoredFiles[type] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00457410
// Name: public: virtual void CWorkspaceFiles::Init(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceFiles::Init(CWorkspaceFiles *this, const char *pchShortName)
{
  char pDest[512]; // [esp+4h] [ebp-200h] BYREF

  V_snprintf(pDest, maxLen: 512, pFormat: "Software\\Valve\\faceposer\\workspace\\%s", pchShortName);
  RegCreateKeyExA(
    hKey: HKEY_CURRENT_USER,
    lpSubKey: pDest,
    Reserved: 0,
    lpClass: nullptr,
    dwOptions: 0,
    samDesired: 0xF003Fu,
    lpSecurityAttributes: nullptr,
    phkResult: &this->m_hKeyMain,
    lpdwDisposition: (LPDWORD)&pchShortName);
}

//------------------------------------------------------------------------------
// Address: 0x00457470
// Name: public: virtual int CWorkspaceFiles::GetNumStoredFiles(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall CWorkspaceFiles::GetNumStoredFiles(CWorkspaceFiles *this, int type)
{
  const char *v3; // eax
  HKEY__ *m_hKeyMain; // [esp-18h] [ebp-124h]
  char szKeyName[256]; // [esp+4h] [ebp-108h] BYREF
  unsigned int Type; // [esp+104h] [ebp-8h] BYREF
  unsigned int cbData; // [esp+108h] [ebp-4h] BYREF

  if ( type != 0 )
  {
    if ( type == 1 )
    {
      v3 = "choreodatafiles";
    }
    else if ( type == 2 )
    {
      v3 = "modelfiles";
    }
    else
    {
      v3 = "unknown";
    }
  }
  else
  {
    v3 = "expressionfiles";
  }
  V_snprintf(pDest: szKeyName, maxLen: 256, pFormat: "%s\\total", v3);
  m_hKeyMain = this->m_hKeyMain;
  type = 0;
  cbData = 4;
  RegQueryValueExA(
    hKey: m_hKeyMain,
    lpValueName: szKeyName,
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&type,
    lpcbData: &cbData);
  return type;
}

//------------------------------------------------------------------------------
// Address: 0x00457500
// Name: public: virtual char const __near * CWorkspaceFiles::GetStoredFile(int,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CWorkspaceFiles::GetStoredFile(CWorkspaceFiles *this, int type, int number)
{
  const char *v4; // eax
  HKEY__ *m_hKeyMain; // [esp-18h] [ebp-11Ch]
  char szKeyName[256]; // [esp+4h] [ebp-100h] BYREF

  if ( type != 0 )
  {
    if ( type == 1 )
    {
      v4 = "choreodatafiles";
    }
    else if ( type == 2 )
    {
      v4 = "modelfiles";
    }
    else
    {
      v4 = "unknown";
    }
  }
  else
  {
    v4 = "expressionfiles";
  }
  sprintf(string: szKeyName, format: "%s\\%04i", v4, number);
  filename_1[0] = 0;
  m_hKeyMain = this->m_hKeyMain;
  type = 256;
  RegQueryValueExA(
    hKey: m_hKeyMain,
    lpValueName: szKeyName,
    lpReserved: nullptr,
    lpType: (LPDWORD)&number,
    lpData: (LPBYTE)filename_1,
    lpcbData: (LPDWORD)&type);
  return filename_1;
}

//------------------------------------------------------------------------------
// Address: 0x00457590
// Name: public: virtual void CWorkspaceFiles::FinishStoringFiles(int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceFiles::FinishStoringFiles(CWorkspaceFiles *this, int type)
{
  int v2; // edi
  const char *v4; // eax
  char szKeyName[256]; // [esp+8h] [ebp-100h] BYREF

  v2 = type;
  if ( type != 0 )
  {
    if ( type == 1 )
    {
      v4 = "choreodatafiles";
    }
    else if ( type == 2 )
    {
      v4 = "modelfiles";
    }
    else
    {
      v4 = "unknown";
    }
  }
  else
  {
    v4 = "expressionfiles";
  }
  sprintf(string: szKeyName, format: "%s\\total", v4);
  type = this->m_nStoredFiles[v2];
  RegSetValueExA(
    hKey: this->m_hKeyMain,
    lpValueName: szKeyName,
    Reserved: 0,
    dwType: 4u,
    lpData: (const BYTE *)&type,
    cbData: 4u);
}

//------------------------------------------------------------------------------
// Address: 0x00457610
// Name: public: virtual void CWorkspaceFiles::StoreFile(int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CWorkspaceFiles::StoreFile(CWorkspaceFiles *this, int type, const char *filename)
{
  int v4; // ecx
  const char *v5; // eax
  char szKeyName[256]; // [esp+8h] [ebp-100h] BYREF

  v4 = this->m_nStoredFiles[type];
  this->m_nStoredFiles[type] = v4 + 1;
  if ( type != 0 )
  {
    if ( type == 1 )
    {
      v5 = "choreodatafiles";
    }
    else if ( type == 2 )
    {
      v5 = "modelfiles";
    }
    else
    {
      v5 = "unknown";
    }
  }
  else
  {
    v5 = "expressionfiles";
  }
  sprintf(string: szKeyName, format: "%s\\%04i", v5, v4);
  RegSetValueExA(
    hKey: this->m_hKeyMain,
    lpValueName: szKeyName,
    Reserved: 0,
    dwType: 1u,
    lpData: (const BYTE *)filename,
    cbData: strlen(filename) + 1);
}
