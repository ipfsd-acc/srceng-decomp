// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: public/editor_sendcommand.cpp
// Functions: 10
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x101044B0
// Name: enum EditorSendResult_t Editor_SendCommand(char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_SendCommand(char *pszCommand, bool bShowUI)
{
  HWND WindowA; // eax
  char szError[1024]; // [esp+0h] [ebp-40Ch] BYREF
  tagCOPYDATASTRUCT CopyData; // [esp+400h] [ebp-Ch] BYREF

  WindowA = FindWindowA(lpClassName: "Worldcraft_ShellMessageWnd", lpWindowName: "Worldcraft_ShellMessageWnd");
  if ( WindowA != nullptr )
  {
    CopyData.cbData = strlen(pszCommand) + 1;
    CopyData.dwData = 0;
    CopyData.lpData = pszCommand;
    if ( SendMessageA(hWnd: WindowA, Msg: 0x4Au, wParam: 0, lParam: (LPARAM)&CopyData) != 0 )
    {
      return 0;
    }
    else
    {
      if ( bShowUI )
      {
        V_snprintf(
          pDest: szError,
          maxLen: 1024,
          pFormat: "Worldcraft did not accept the command: \n"
          "\n"
          "\"%s\"\n"
          "\n"
          " Make sure the command is valid and that Worldcraft is still running properly.",
          pszCommand);
        MessageBoxA(hWnd: nullptr, lpText: szError, lpCaption: "Editor_SendCommand Error", uType: 0);
      }
      return 2;
    }
  }
  else
  {
    if ( bShowUI )
    {
      V_snprintf(
        pDest: szError,
        maxLen: 1024,
        pFormat: "Could not contact Worldcraft to send the command: \n\n\"%s\"\n\n Worldcraft does not appear to be running.",
        pszCommand);
      MessageBoxA(hWnd: nullptr, lpText: szError, lpCaption: "Editor_SendCommand Error", uType: 0);
    }
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10104590
// Name: enum EditorSendResult_t Editor_BeginSession(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_BeginSession(const char *pszMapName, int nMapVersion, bool bShowUI)
{
  char szCommand[2048]; // [esp+0h] [ebp-800h] BYREF

  V_snprintf(pDest: szCommand, maxLen: 2048, pFormat: "session_begin %s %d", pszMapName, nMapVersion);
  return Editor_SendCommand(pszCommand: szCommand, bShowUI);
}

//------------------------------------------------------------------------------
// Address: 0x101045D0
// Name: enum EditorSendResult_t Editor_CheckVersion(char const __near *,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_CheckVersion(const char *pszMapName, int nMapVersion, bool bShowUI)
{
  char szCommand[2048]; // [esp+0h] [ebp-800h] BYREF

  V_snprintf(pDest: szCommand, maxLen: 2048, pFormat: "map_check_version %s %d", pszMapName, nMapVersion);
  return Editor_SendCommand(pszCommand: szCommand, bShowUI);
}

//------------------------------------------------------------------------------
// Address: 0x10104610
// Name: enum EditorSendResult_t Editor_CreateNode(char const __near *,int,float,float,float,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_CreateNode(const char *pszNodeClass, int nID, float x, float y, float z, bool bShowUI)
{
  char szCommand[2048]; // [esp+18h] [ebp-800h] BYREF

  V_snprintf(pDest: szCommand, maxLen: 2048, pFormat: "node_create %s %d %g %g %g", pszNodeClass, nID, x, y, z);
  return Editor_SendCommand(pszCommand: szCommand, bShowUI);
}

//------------------------------------------------------------------------------
// Address: 0x10104680
// Name: enum EditorSendResult_t Editor_CreateNodeLink(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_CreateNodeLink(int nStartID, int nEndID, bool bShowUI)
{
  char szCommand[2048]; // [esp+0h] [ebp-800h] BYREF

  V_snprintf(pDest: szCommand, maxLen: 2048, pFormat: "nodelink_create %d %d", nStartID, nEndID);
  return Editor_SendCommand(pszCommand: szCommand, bShowUI);
}

//------------------------------------------------------------------------------
// Address: 0x101046C0
// Name: enum EditorSendResult_t Editor_SetKeyValue(char const __near *,float,float,float,char const __near *,char const __near *,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_SetKeyValue(
        const char *pszEntity,
        float x,
        float y,
        float z,
        const char *pKey,
        const char *pValue,
        bool bShowUI)
{
  char szCommand[2048]; // [esp+20h] [ebp-800h] BYREF

  V_snprintf(
    pDest: szCommand,
    maxLen: 2048,
    pFormat: "entity_set_keyvalue %s %f %f %f \"%s\" \"%s\"",
    pszEntity,
    x,
    y,
    z,
    pKey,
    pValue);
  return Editor_SendCommand(pszCommand: szCommand, bShowUI);
}

//------------------------------------------------------------------------------
// Address: 0x10104730
// Name: enum EditorSendResult_t Editor_RotateEntity(char const __near *,float,float,float,class QAngle const __near &,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_RotateEntity(
        const char *pszEntity,
        float x,
        float y,
        float z,
        const QAngle *incrementalRotation,
        bool bShowUI)
{
  char szCommand[2048]; // [esp+30h] [ebp-800h] BYREF

  V_snprintf(
    pDest: szCommand,
    maxLen: 2048,
    pFormat: "entity_rotate_incremental %s %f %f %f %f %f %f",
    pszEntity,
    x,
    y,
    z,
    incrementalRotation->x,
    incrementalRotation->y,
    incrementalRotation->z);
  return Editor_SendCommand(pszCommand: szCommand, bShowUI);
}

//------------------------------------------------------------------------------
// Address: 0x101047D0
// Name: enum EditorSendResult_t Editor_DeleteNode(int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_DeleteNode(int nID, bool bShowUI)
{
  char szCommand[2048]; // [esp+0h] [ebp-800h] BYREF

  V_snprintf(pDest: szCommand, maxLen: 2048, pFormat: "node_delete %d", nID);
  return Editor_SendCommand(pszCommand: szCommand, bShowUI);
}

//------------------------------------------------------------------------------
// Address: 0x10104810
// Name: enum EditorSendResult_t Editor_DeleteNodeLink(int,int,bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_DeleteNodeLink(int nStartID, int nEndID, bool bShowUI)
{
  char szCommand[2048]; // [esp+0h] [ebp-800h] BYREF

  V_snprintf(pDest: szCommand, maxLen: 2048, pFormat: "nodelink_delete %d %d", nStartID, nEndID);
  return Editor_SendCommand(pszCommand: szCommand, bShowUI);
}

//------------------------------------------------------------------------------
// Address: 0x10104850
// Name: enum EditorSendResult_t Editor_EndSession(bool)
// Source: json
//------------------------------------------------------------------------------
int __cdecl Editor_EndSession(bool bShowUI)
{
  return Editor_SendCommand(pszCommand: "session_end", bShowUI);
}
