// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/hlmv/viewersettings.cpp
// Functions: 20
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041E1D0
// Name: void InitViewerSettings(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitViewerSettings(const char *subkey)
{
  StudioModel *v1; // eax
  StudioModel *v2; // eax
  ViewerSettings save; // 0:^18.3364

  save = g_viewerSettings;
  memset(dst: (unsigned __int8 *)&g_viewerSettings, value: 0, count: sizeof(g_viewerSettings));
  g_viewerSettings.faceposerToolsDriveMouth = save.faceposerToolsDriveMouth;
  g_viewerSettings.showActivities = save.showActivities;
  g_viewerSettings.showHidden = save.showHidden;
  g_viewerSettings.showSequenceIndices = save.showSequenceIndices;
  *(_WORD *)&g_viewerSettings.sortSequences = *(_WORD *)&save.sortSequences;
  strcpy(g_viewerSettings.registrysubkey, subkey);
  v1 = g_pStudioModel;
  g_pStudioModel->m_angles.x = -90.0;
  v1->m_angles.y = 0.0;
  v1->m_angles.z = 0.0;
  v2 = g_pStudioModel;
  g_pStudioModel->m_origin.x = 0.0;
  v2->m_origin.y = 0.0;
  v2->m_origin.z = 50.0;
  g_viewerSettings.fov = 65.0;
  g_viewerSettings.bgColor[0] = 0.25;
  g_viewerSettings.bgColor[1] = 0.25;
  g_viewerSettings.bgColor[2] = 0.25;
  g_viewerSettings.thumbnailsize = 128;
  g_viewerSettings.thumbnailsizeanim = 128;
  g_viewerSettings.gColor[0] = 0.85000002;
  g_viewerSettings.gColor[1] = 0.85000002;
  g_viewerSettings.m_iEditAttachment = -1;
  g_viewerSettings.highlightHitbox = -1;
  g_viewerSettings.highlightBone = -1;
  g_viewerSettings.gColor[2] = 0.69;
  g_viewerSettings.aColor[0] = 0.30000001;
  g_viewerSettings.aColor[1] = 0.30000001;
  g_viewerSettings.aColor[2] = 0.30000001;
  g_viewerSettings.lightrot.x = 0.0;
  g_viewerSettings.lightrot.z = 0.0;
  *(_WORD *)&g_viewerSettings.showNormals = 0;
  g_viewerSettings.overlayWireframe = false;
  g_viewerSettings.application_mode = 0;
  g_viewerSettings.speechapiindex = 0;
  g_viewerSettings.cclanguageid = 0;
  g_viewerSettings.renderMode = 2;
  *(_DWORD *)&g_viewerSettings.enableNormalMapping = 16777472;
  g_viewerSettings.playSounds = true;
  g_viewerSettings.lColor[0] = 1.0;
  g_viewerSettings.lColor[1] = 1.0;
  g_viewerSettings.lColor[2] = 1.0;
  g_viewerSettings.lightrot.y = 180.0;
  g_viewerSettings.speedScale = 1.0;
  g_viewerSettings.xpos = 20;
  g_viewerSettings.ypos = 20;
  g_viewerSettings.width = 640;
  g_viewerSettings.height = 700;
  g_viewerSettings.originAxisLength = 10.0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E400
// Name: bool RegReadVector(struct HKEY__ __near *,char const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegReadVector(HKEY__ *hKey, const char *szSubKey, Vector *value)
{
  char szBuff[128]; // [esp+0h] [ebp-88h] BYREF
  unsigned int dwType; // [esp+80h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+84h] [ebp-4h] BYREF

  dwSize = 128;
  return RegQueryValueExA(
           hKey,
           lpValueName: szSubKey,
           lpReserved: nullptr,
           lpType: &dwType,
           lpData: (LPBYTE)szBuff,
           lpcbData: &dwSize) == 0
      && sscanf(string: szBuff, format: "(%f %f %f)", value, &value->y, &value->z) == 3;
}

//------------------------------------------------------------------------------
// Address: 0x0041E470
// Name: bool RegReadQAngle(struct HKEY__ __near *,char const __near *,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RegReadQAngle(HKEY__ *hKey, const char *szSubKey, QAngle *value)
{
  unsigned __int8 Data[128]; // [esp+0h] [ebp-94h] BYREF
  unsigned int Type; // [esp+80h] [ebp-14h] BYREF
  unsigned int cbData; // [esp+84h] [ebp-10h] BYREF
  Vector tmp; // [esp+88h] [ebp-Ch] BYREF

  cbData = 128;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: szSubKey,
         lpReserved: nullptr,
         lpType: &Type,
         lpData: Data,
         lpcbData: &cbData) != 0
    || sscanf(string: (const char *)Data, format: "(%f %f %f)", &tmp, &tmp.y, &tmp.z) != 3 )
  {
    return 0;
  }
  *value = (QAngle)tmp;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041E500
// Name: bool RegReadColor(struct HKEY__ __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegReadColor(HKEY__ *hKey, const char *szSubKey, float *value)
{
  char szBuff[128]; // [esp+0h] [ebp-88h] BYREF
  unsigned int dwType; // [esp+80h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+84h] [ebp-4h] BYREF

  dwSize = 128;
  return RegQueryValueExA(
           hKey,
           lpValueName: szSubKey,
           lpReserved: nullptr,
           lpType: &dwType,
           lpData: (LPBYTE)szBuff,
           lpcbData: &dwSize) == 0
      && sscanf(string: szBuff, format: "(%f %f %f %f)", value, value + 1, value + 2, value + 3) == 4;
}

//------------------------------------------------------------------------------
// Address: 0x0041E570
// Name: bool RegWriteVector(struct HKEY__ __near *,char const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteVector(HKEY__ *hKey, const char *szSubKey, Vector *value)
{
  char szBuff[128]; // [esp+18h] [ebp-80h] BYREF

  sprintf(string: szBuff, format: "(%f %f %f)", value->x, value->y, value->z);
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)szBuff,
           cbData: strlen(szBuff)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E5F0
// Name: bool RegWriteQAngle(struct HKEY__ __near *,char const __near *,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteQAngle(HKEY__ *hKey, const char *szSubKey, QAngle *value)
{
  char string[128]; // [esp+18h] [ebp-80h] BYREF

  sprintf(string, format: "(%f %f %f)", value->x, value->y, value->z);
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)string,
           cbData: strlen(string)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E670
// Name: bool RegWriteColor(struct HKEY__ __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteColor(HKEY__ *hKey, const char *szSubKey, float *value)
{
  char szBuff[128]; // [esp+20h] [ebp-80h] BYREF

  sprintf(string: szBuff, format: "(%f %f %f %f)", *value, value[1], value[2], value[3]);
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)szBuff,
           cbData: strlen(szBuff)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E700
// Name: bool RegReadBool(struct HKEY__ __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RegReadBool(HKEY__ *hKey, const char *szSubKey, bool *value)
{
  unsigned int dwTemp; // [esp+0h] [ebp-Ch] BYREF
  unsigned int dwType; // [esp+4h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+8h] [ebp-4h] BYREF

  dwSize = 4;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: szSubKey,
         lpReserved: nullptr,
         lpType: &dwType,
         lpData: (LPBYTE)&dwTemp,
         lpcbData: &dwSize) != 0
    || dwType != 4 )
  {
    return 0;
  }
  *value = dwTemp != 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041E750
// Name: bool RegReadInt(struct HKEY__ __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegReadInt(HKEY__ *hKey, const char *szSubKey, int *value)
{
  unsigned int dwType; // [esp+0h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+4h] [ebp-4h] BYREF

  dwSize = 4;
  return RegQueryValueExA(
           hKey,
           lpValueName: szSubKey,
           lpReserved: nullptr,
           lpType: &dwType,
           lpData: (LPBYTE)value,
           lpcbData: &dwSize) == 0
      && dwType == 4;
}

//------------------------------------------------------------------------------
// Address: 0x0041E790
// Name: bool RegReadFloat(struct HKEY__ __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RegReadFloat(HKEY__ *hKey, const char *szSubKey, float *value)
{
  char szBuff[128]; // [esp+0h] [ebp-88h] BYREF
  unsigned int dwType; // [esp+80h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+84h] [ebp-4h] BYREF

  dwSize = 128;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: szSubKey,
         lpReserved: nullptr,
         lpType: &dwType,
         lpData: (LPBYTE)szBuff,
         lpcbData: &dwSize) != 0 )
    return 0;
  *value = atof(nptr: szBuff);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041E7F0
// Name: bool RegWriteFloat(struct HKEY__ __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteFloat(HKEY__ *hKey, const char *szSubKey, float value)
{
  char szBuff[128]; // [esp+8h] [ebp-80h] BYREF

  sprintf(string: szBuff, format: "%f", value);
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)szBuff,
           cbData: strlen(szBuff)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E850
// Name: bool RegReadString(struct HKEY__ __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegReadString(HKEY__ *hKey, const char *szSubKey, char *string, unsigned int size)
{
  unsigned int dwType; // [esp+0h] [ebp-4h] BYREF

  return RegQueryValueExA(
           hKey,
           lpValueName: szSubKey,
           lpReserved: nullptr,
           lpType: &dwType,
           lpData: (LPBYTE)string,
           lpcbData: &size) == 0
      && dwType == 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041E890
// Name: bool RegWriteString(struct HKEY__ __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteString(HKEY__ *hKey, const char *szSubKey, char *string)
{
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)string,
           cbData: strlen(string)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0041E8D0
// Name: long RegViewerSettingsKey(char const __near *,struct HKEY__ __near * __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
LSTATUS __cdecl RegViewerSettingsKey(const char *filename, HKEY__ **phKey, unsigned int *lpdwDisposition)
{
  const char *v3; // eax
  char v5; // cl
  char *i; // ecx
  char v7; // al
  char szModelKey[1024]; // [esp+4h] [ebp-804h] BYREF
  char szFileName[1028]; // [esp+404h] [ebp-404h] BYREF

  v3 = filename;
  if ( strlen(filename) == 0 )
    return 1018;
  do
  {
    v5 = *v3;
    v3[szFileName - filename] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  for ( i = szFileName; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i == 92 || v7 == 47 || v7 == 58 )
      *i = 46;
  }
  sprintf(string: szModelKey, format: "Software\\Valve\\%s\\%s", g_viewerSettings.registrysubkey, szFileName);
  return RegCreateKeyExA(
           hKey: HKEY_CURRENT_USER,
           lpSubKey: szModelKey,
           Reserved: 0,
           lpClass: nullptr,
           dwOptions: 0,
           samDesired: 0xF003Fu,
           lpSecurityAttributes: nullptr,
           phkResult: phKey,
           lpdwDisposition);
}

//------------------------------------------------------------------------------
// Address: 0x0041E990
// Name: bool LoadViewerSettingsInt(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadViewerSettingsInt(const char *keyname, int *value)
{
  HKEY__ *v3; // edx
  unsigned int Type; // [esp+0h] [ebp-10h] BYREF
  HKEY__ *hModelKey; // [esp+4h] [ebp-Ch] BYREF
  unsigned int cbData; // [esp+8h] [ebp-8h] BYREF
  unsigned int dwDisposition; // [esp+Ch] [ebp-4h] BYREF

  if ( RegViewerSettingsKey(filename: "hlfaceposer", phKey: &hModelKey, lpdwDisposition: &dwDisposition) != 0
    || dwDisposition == 1 )
  {
    return 0;
  }
  v3 = hModelKey;
  *value = 0;
  cbData = 4;
  RegQueryValueExA(
    hKey: v3,
    lpValueName: keyname,
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)value,
    lpcbData: &cbData);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041E9F0
// Name: bool SaveViewerSettingsInt(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SaveViewerSettingsInt(const char *keyname, int value)
{
  unsigned int dwDisposition; // [esp+0h] [ebp-Ch] BYREF
  HKEY__ *hModelKey; // [esp+4h] [ebp-8h] BYREF
  BYTE Data[4]; // [esp+8h] [ebp-4h] BYREF

  if ( RegViewerSettingsKey(filename: "hlfaceposer", phKey: &hModelKey, lpdwDisposition: &dwDisposition) != 0 )
    return 0;
  *(_DWORD *)Data = value;
  RegSetValueExA(hKey: hModelKey, lpValueName: keyname, Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041EA40
// Name: bool LoadViewerSettings(char const __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadViewerSettings(HKEY__ *filename, StudioModel *pModel)
{
  StudioModel *v2; // esi
  int v3; // eax
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  unsigned __int8 *mergeModelFile; // esi
  char szTemp[256]; // [esp+10h] [ebp-12Ch] BYREF
  char merge_buffer[32]; // [esp+110h] [ebp-2Ch] BYREF
  unsigned int Type; // [esp+130h] [ebp-Ch] BYREF
  unsigned int dwDisposition; // [esp+134h] [ebp-8h] BYREF
  unsigned int flTemp; // [esp+138h] [ebp-4h] BYREF

  if ( filename == nullptr )
    return 0;
  v2 = pModel;
  if ( pModel == nullptr
    || RegViewerSettingsKey((const char *)filename, phKey: &filename, lpdwDisposition: &dwDisposition) != 0
    || dwDisposition == 1 )
  {
    return 0;
  }
  RegReadQAngle(hKey: filename, szSubKey: "Rot", value: &v2->m_angles);
  RegReadVector(hKey: filename, szSubKey: "Trans", value: &v2->m_origin);
  RegReadColor(hKey: filename, szSubKey: "bgColor", value: g_viewerSettings.bgColor);
  RegReadColor(hKey: filename, szSubKey: "gColor", value: g_viewerSettings.gColor);
  RegReadColor(hKey: filename, szSubKey: "lColor", value: g_viewerSettings.lColor);
  RegReadColor(hKey: filename, szSubKey: "aColor", value: g_viewerSettings.aColor);
  RegReadQAngle(hKey: filename, szSubKey: "lightrot", value: &g_viewerSettings.lightrot);
  RegReadString(hKey: filename, szSubKey: aSequence_1, string: szTemp, size: 0x100u);
  v3 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  StudioModel::SetSequence(this: v2, iSequence: v3);
  RegReadString(hKey: filename, szSubKey: "overlaySequence0", string: szTemp, size: 0x100u);
  v4 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  RegReadFloat(hKey: filename, szSubKey: "overlayWeight0", value: (float *)&flTemp);
  StudioModel::SetOverlaySequence(this: v2, iLayer: 0, iSequence: v4, flWeight: *(float *)&flTemp);
  RegReadString(hKey: filename, szSubKey: "overlaySequence1", string: szTemp, size: 0x100u);
  v5 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  RegReadFloat(hKey: filename, szSubKey: "overlayWeight1", value: (float *)&flTemp);
  StudioModel::SetOverlaySequence(this: v2, iLayer: 1u, iSequence: v5, flWeight: *(float *)&flTemp);
  RegReadString(hKey: filename, szSubKey: "overlaySequence2", string: szTemp, size: 0x100u);
  v6 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  RegReadFloat(hKey: filename, szSubKey: "overlayWeight2", value: (float *)&flTemp);
  StudioModel::SetOverlaySequence(this: v2, iLayer: 2u, iSequence: v6, flWeight: *(float *)&flTemp);
  RegReadString(hKey: filename, szSubKey: "overlaySequence3", string: szTemp, size: 0x100u);
  v7 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  RegReadFloat(hKey: filename, szSubKey: "overlayWeight3", value: (float *)&flTemp);
  StudioModel::SetOverlaySequence(this: v2, iLayer: 3u, iSequence: v7, flWeight: *(float *)&flTemp);
  RegReadFloat(hKey: filename, szSubKey: "speedscale", value: &g_viewerSettings.speedScale);
  if ( g_viewerSettings.speedScale > 1.0 )
    g_viewerSettings.speedScale = 1.0;
  RegReadInt(hKey: filename, szSubKey: "viewermode", value: &g_viewerSettings.application_mode);
  RegReadInt(hKey: filename, szSubKey: "thumbnailsize", value: &g_viewerSettings.thumbnailsize);
  RegReadInt(hKey: filename, szSubKey: "thumbnailsizeanim", value: &g_viewerSettings.thumbnailsizeanim);
  if ( g_viewerSettings.thumbnailsize == 0 )
    g_viewerSettings.thumbnailsize = 128;
  if ( g_viewerSettings.thumbnailsizeanim == 0 )
    g_viewerSettings.thumbnailsizeanim = 128;
  RegReadInt(hKey: filename, szSubKey: "speechapiindex", value: &g_viewerSettings.speechapiindex);
  RegReadInt(hKey: filename, szSubKey: "cclanguageid", value: &g_viewerSettings.cclanguageid);
  RegReadBool(hKey: filename, szSubKey: "showground", value: &g_viewerSettings.showGround);
  RegReadBool(hKey: filename, szSubKey: "showbackground", value: &g_viewerSettings.showBackground);
  RegReadBool(hKey: filename, szSubKey: "showshadow", value: &g_viewerSettings.showShadow);
  RegReadBool(hKey: filename, szSubKey: "showillumpos", value: &g_viewerSettings.showIllumPosition);
  RegReadBool(hKey: filename, szSubKey: "enablenormalmapping", value: &g_viewerSettings.enableNormalMapping);
  RegReadBool(hKey: filename, szSubKey: "enabledisplacementmapping", value: &g_viewerSettings.enableDisplacementMapping);
  RegReadBool(hKey: filename, szSubKey: "playsounds", value: &g_viewerSettings.playSounds);
  RegReadBool(hKey: filename, szSubKey: "showoriginaxis", value: &g_viewerSettings.showOriginAxis);
  RegReadFloat(hKey: filename, szSubKey: "originaxislength", value: &g_viewerSettings.originAxisLength);
  v8 = 0;
  mergeModelFile = (unsigned __int8 *)g_viewerSettings.mergeModelFile;
  do
  {
    V_snprintf(pDest: merge_buffer, maxLen: 32, pFormat: "merge%d", ++v8);
    flTemp = 256;
    RegQueryValueExA(
      hKey: filename,
      lpValueName: merge_buffer,
      lpReserved: nullptr,
      lpType: &Type,
      lpData: mergeModelFile,
      lpcbData: &flTemp);
    mergeModelFile += 256;
  }
  while ( (int)mergeModelFile < (int)g_viewerSettings.mergeModelFile[12] );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041EE60
// Name: bool LoadViewerRootSettings(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadViewerRootSettings()
{
  char string[1024]; // [esp+0h] [ebp-414h] BYREF
  unsigned int dwDisposition; // [esp+400h] [ebp-14h] BYREF
  HKEY__ *hRootKey; // [esp+404h] [ebp-10h] BYREF
  unsigned int v4; // [esp+408h] [ebp-Ch] BYREF
  unsigned int Type; // [esp+40Ch] [ebp-8h] BYREF
  unsigned int cbData; // [esp+410h] [ebp-4h] BYREF

  sprintf(string, format: "Software\\Valve\\%s", g_viewerSettings.registrysubkey);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: string,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &hRootKey,
         lpdwDisposition: &dwDisposition) != 0 )
    return 0;
  cbData = 4;
  RegQueryValueExA(
    hKey: hRootKey,
    lpValueName: "renderxpos",
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&g_viewerSettings.xpos,
    lpcbData: &cbData);
  cbData = 4;
  RegQueryValueExA(
    hKey: hRootKey,
    lpValueName: "renderypos",
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&g_viewerSettings.ypos,
    lpcbData: &cbData);
  cbData = 4;
  RegQueryValueExA(
    hKey: hRootKey,
    lpValueName: "renderwidth",
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&g_viewerSettings.width,
    lpcbData: &cbData);
  cbData = 4;
  RegQueryValueExA(
    hKey: hRootKey,
    lpValueName: "renderheight",
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&g_viewerSettings.height,
    lpcbData: &cbData);
  cbData = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "faceposerToolsDriveMouth",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&Type,
         lpcbData: &cbData) == 0
    && v4 == 4 )
  {
    g_viewerSettings.faceposerToolsDriveMouth = Type != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "showHidden",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.showHidden = cbData != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "showActivities",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.showActivities = cbData != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "showSequenceIndices",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.showSequenceIndices = cbData != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "sortSequences",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.sortSequences = cbData != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "dotaMode",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.dotaMode = cbData != 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x0041F060
// Name: bool SaveViewerSettings(char const __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SaveViewerSettings(HKEY__ *filename, StudioModel *pModel)
{
  StudioModel *v2; // esi
  IMDLCache *v4; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CStudioHdr *StudioHdr; // edi
  int Sequence; // eax
  mstudioseqdesc_t *v8; // eax
  int OverlaySequence; // eax
  mstudioseqdesc_t *v10; // eax
  int v11; // eax
  mstudioseqdesc_t *v12; // eax
  int v13; // eax
  mstudioseqdesc_t *v14; // eax
  int v15; // eax
  mstudioseqdesc_t *v16; // eax
  int v17; // eax
  char *v18; // edi
  int v19; // ebx
  float value; // [esp+0h] [ebp-3Ch]
  float valuea; // [esp+0h] [ebp-3Ch]
  float valueb; // [esp+0h] [ebp-3Ch]
  float valuec; // [esp+0h] [ebp-3Ch]
  char merge_buffer[32]; // [esp+10h] [ebp-2Ch] BYREF
  unsigned int dwDisposition; // [esp+30h] [ebp-Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+34h] [ebp-8h]
  BYTE Data[4]; // [esp+38h] [ebp-4h] BYREF

  if ( filename == nullptr )
    return 0;
  v2 = pModel;
  if ( pModel == nullptr
    || RegViewerSettingsKey((const char *)filename, phKey: &filename, lpdwDisposition: &dwDisposition) != 0 )
  {
    return 0;
  }
  v4 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  StudioHdr = StudioModel::GetStudioHdr(this: v2);
  if ( StudioHdr != nullptr )
  {
    RegWriteQAngle(hKey: filename, szSubKey: "Rot", value: &v2->m_angles);
    RegWriteVector(hKey: filename, szSubKey: "Trans", value: &v2->m_origin);
    RegWriteColor(hKey: filename, szSubKey: "bgColor", value: g_viewerSettings.bgColor);
    RegWriteColor(hKey: filename, szSubKey: "gColor", value: g_viewerSettings.gColor);
    RegWriteColor(hKey: filename, szSubKey: "lColor", value: g_viewerSettings.lColor);
    RegWriteColor(hKey: filename, szSubKey: "aColor", value: g_viewerSettings.aColor);
    RegWriteQAngle(hKey: filename, szSubKey: "lightrot", value: &g_viewerSettings.lightrot);
    Sequence = StudioModel::GetSequence(this: v2);
    v8 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: Sequence);
    RegWriteString(hKey: filename, szSubKey: aSequence_1, string: (char *)v8 + v8->szlabelindex);
    OverlaySequence = StudioModel::GetOverlaySequence(this: v2, iLayer: 0);
    v10 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: OverlaySequence);
    RegWriteString(hKey: filename, szSubKey: "overlaySequence0", string: (char *)v10 + v10->szlabelindex);
    value = StudioModel::GetOverlaySequenceWeight(this: v2, iLayer: 0);
    RegWriteFloat(hKey: filename, szSubKey: "overlayWeight0", value);
    v11 = StudioModel::GetOverlaySequence(this: v2, iLayer: 1u);
    v12 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: v11);
    RegWriteString(hKey: filename, szSubKey: "overlaySequence1", string: (char *)v12 + v12->szlabelindex);
    valuea = StudioModel::GetOverlaySequenceWeight(this: v2, iLayer: 1u);
    RegWriteFloat(hKey: filename, szSubKey: "overlayWeight1", value: valuea);
    v13 = StudioModel::GetOverlaySequence(this: v2, iLayer: 2u);
    v14 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: v13);
    RegWriteString(hKey: filename, szSubKey: "overlaySequence2", string: (char *)v14 + v14->szlabelindex);
    valueb = StudioModel::GetOverlaySequenceWeight(this: v2, iLayer: 2u);
    RegWriteFloat(hKey: filename, szSubKey: "overlayWeight2", value: valueb);
    v15 = StudioModel::GetOverlaySequence(this: v2, iLayer: 3u);
    v16 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: v15);
    RegWriteString(hKey: filename, szSubKey: "overlaySequence3", string: (char *)v16 + v16->szlabelindex);
    valuec = StudioModel::GetOverlaySequenceWeight(this: v2, iLayer: 3u);
    RegWriteFloat(hKey: filename, szSubKey: "overlayWeight3", value: valuec);
    RegWriteFloat(hKey: filename, szSubKey: "speedscale", value: g_viewerSettings.speedScale);
    *(_DWORD *)Data = g_viewerSettings.application_mode;
    RegSetValueExA(hKey: filename, lpValueName: "viewermode", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.thumbnailsize;
    RegSetValueExA(hKey: filename, lpValueName: "thumbnailsize", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.thumbnailsizeanim;
    RegSetValueExA(hKey: filename, lpValueName: "thumbnailsizeanim", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.speechapiindex;
    RegSetValueExA(hKey: filename, lpValueName: "speechapiindex", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.cclanguageid;
    RegSetValueExA(hKey: filename, lpValueName: "cclanguageid", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showGround;
    RegSetValueExA(hKey: filename, lpValueName: "showground", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showBackground;
    RegSetValueExA(hKey: filename, lpValueName: "showbackground", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showShadow;
    RegSetValueExA(hKey: filename, lpValueName: "showshadow", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showIllumPosition;
    RegSetValueExA(hKey: filename, lpValueName: "showillumpos", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.enableNormalMapping;
    RegSetValueExA(
      hKey: filename,
      lpValueName: "enablenormalmapping",
      Reserved: 0,
      dwType: 4u,
      lpData: Data,
      cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.enableDisplacementMapping;
    RegSetValueExA(
      hKey: filename,
      lpValueName: "enabledisplacementmapping",
      Reserved: 0,
      dwType: 4u,
      lpData: Data,
      cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.playSounds;
    RegSetValueExA(hKey: filename, lpValueName: "playsounds", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showOriginAxis;
    RegSetValueExA(hKey: filename, lpValueName: "showoriginaxis", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    RegWriteFloat(hKey: filename, szSubKey: "originaxislength", value: g_viewerSettings.originAxisLength);
    v17 = 0;
    v18 = g_viewerSettings.mergeModelFile[0];
    do
    {
      v19 = v17 + 1;
      V_snprintf(pDest: merge_buffer, maxLen: 32, pFormat: "merge%d", v17 + 1);
      RegSetValueExA(
        hKey: filename,
        lpValueName: merge_buffer,
        Reserved: 0,
        dwType: 1u,
        lpData: (const BYTE *)v18,
        cbData: strlen(v18));
      v18 += 256;
      v17 = v19;
    }
    while ( (int)v18 < (int)g_viewerSettings.mergeModelFile[12] );
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 1;
  }
  else
  {
    v4->EndLock(this: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0041F4C0
// Name: bool SaveViewerRootSettings(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SaveViewerRootSettings()
{
  char string[1024]; // [esp+0h] [ebp-40Ch] BYREF
  unsigned int dwDisposition; // [esp+400h] [ebp-Ch] BYREF
  HKEY__ *hRootKey; // [esp+404h] [ebp-8h] BYREF
  BYTE Data[4]; // [esp+408h] [ebp-4h] BYREF

  sprintf(string, format: "Software\\Valve\\%s", g_viewerSettings.registrysubkey);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: string,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &hRootKey,
         lpdwDisposition: &dwDisposition) != 0 )
    return 0;
  *(_DWORD *)Data = g_viewerSettings.xpos;
  RegSetValueExA(hKey: hRootKey, lpValueName: "renderxpos", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.ypos;
  RegSetValueExA(hKey: hRootKey, lpValueName: "renderypos", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.width;
  RegSetValueExA(hKey: hRootKey, lpValueName: "renderwidth", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.height;
  RegSetValueExA(hKey: hRootKey, lpValueName: "renderheight", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.faceposerToolsDriveMouth;
  RegSetValueExA(
    hKey: hRootKey,
    lpValueName: "faceposerToolsDriveMouth",
    Reserved: 0,
    dwType: 4u,
    lpData: Data,
    cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.showHidden;
  RegSetValueExA(hKey: hRootKey, lpValueName: "showHidden", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.showActivities;
  RegSetValueExA(hKey: hRootKey, lpValueName: "showActivities", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.showSequenceIndices;
  RegSetValueExA(hKey: hRootKey, lpValueName: "showSequenceIndices", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.sortSequences;
  RegSetValueExA(hKey: hRootKey, lpValueName: "sortSequences", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.dotaMode;
  RegSetValueExA(hKey: hRootKey, lpValueName: "dotaMode", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  return 1;
}

// ============================================================
// Overlay from hlmv (Missing functions)
// ============================================================
namespace hlmv {

//------------------------------------------------------------------------------
// Address: 0x004288A0
// Name: void InitViewerSettings(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl InitViewerSettings(const char *subkey)
{
  StudioModel *v1; // eax
  StudioModel *v2; // eax
  ViewerSettings save; // 0:^18.3364

  save = g_viewerSettings;
  memset(dst: (unsigned __int8 *)&g_viewerSettings, value: 0, count: sizeof(g_viewerSettings));
  g_viewerSettings.faceposerToolsDriveMouth = save.faceposerToolsDriveMouth;
  g_viewerSettings.showActivities = save.showActivities;
  g_viewerSettings.showHidden = save.showHidden;
  g_viewerSettings.showSequenceIndices = save.showSequenceIndices;
  *(_WORD *)&g_viewerSettings.sortSequences = *(_WORD *)&save.sortSequences;
  strcpy(g_viewerSettings.registrysubkey, subkey);
  v1 = g_pStudioModel;
  g_pStudioModel->m_angles.x = -90.0;
  v1->m_angles.y = 0.0;
  v1->m_angles.z = 0.0;
  v2 = g_pStudioModel;
  g_pStudioModel->m_origin.x = 0.0;
  v2->m_origin.y = 0.0;
  v2->m_origin.z = 50.0;
  g_viewerSettings.fov = 65.0;
  g_viewerSettings.bgColor[0] = 0.25;
  g_viewerSettings.bgColor[1] = 0.25;
  g_viewerSettings.bgColor[2] = 0.25;
  g_viewerSettings.thumbnailsize = 128;
  g_viewerSettings.thumbnailsizeanim = 128;
  g_viewerSettings.gColor[0] = 0.85000002;
  g_viewerSettings.gColor[1] = 0.85000002;
  g_viewerSettings.m_iEditAttachment = -1;
  g_viewerSettings.highlightHitbox = -1;
  g_viewerSettings.highlightBone = -1;
  g_viewerSettings.gColor[2] = 0.69;
  g_viewerSettings.aColor[0] = 0.30000001;
  g_viewerSettings.aColor[1] = 0.30000001;
  g_viewerSettings.aColor[2] = 0.30000001;
  g_viewerSettings.lightrot.x = 0.0;
  g_viewerSettings.lightrot.z = 0.0;
  *(_WORD *)&g_viewerSettings.showNormals = 0;
  g_viewerSettings.overlayWireframe = false;
  g_viewerSettings.application_mode = 0;
  g_viewerSettings.speechapiindex = 0;
  g_viewerSettings.cclanguageid = 0;
  g_viewerSettings.renderMode = 2;
  *(_DWORD *)&g_viewerSettings.enableNormalMapping = 16777472;
  g_viewerSettings.playSounds = true;
  g_viewerSettings.lColor[0] = 1.0;
  g_viewerSettings.lColor[1] = 1.0;
  g_viewerSettings.lColor[2] = 1.0;
  g_viewerSettings.lightrot.y = 180.0;
  g_viewerSettings.speedScale = 1.0;
  g_viewerSettings.xpos = 20;
  g_viewerSettings.ypos = 20;
  g_viewerSettings.width = 640;
  g_viewerSettings.height = 700;
  g_viewerSettings.originAxisLength = 10.0;
}

//------------------------------------------------------------------------------
// Address: 0x00428AD0
// Name: bool RegReadVector(struct HKEY__ __near *,char const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegReadVector(HKEY__ *hKey, const char *szSubKey, Vector *value)
{
  char szBuff[128]; // [esp+0h] [ebp-88h] BYREF
  unsigned int dwType; // [esp+80h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+84h] [ebp-4h] BYREF

  dwSize = 128;
  return RegQueryValueExA(
           hKey,
           lpValueName: szSubKey,
           lpReserved: nullptr,
           lpType: &dwType,
           lpData: (LPBYTE)szBuff,
           lpcbData: &dwSize) == 0
      && sscanf(string: szBuff, format: "(%f %f %f)", value, &value->y, &value->z) == 3;
}

//------------------------------------------------------------------------------
// Address: 0x00428B40
// Name: bool RegReadQAngle(struct HKEY__ __near *,char const __near *,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RegReadQAngle(HKEY__ *hKey, const char *szSubKey, QAngle *value)
{
  unsigned __int8 Data[128]; // [esp+0h] [ebp-94h] BYREF
  unsigned int Type; // [esp+80h] [ebp-14h] BYREF
  unsigned int cbData; // [esp+84h] [ebp-10h] BYREF
  Vector tmp; // [esp+88h] [ebp-Ch] BYREF

  cbData = 128;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: szSubKey,
         lpReserved: nullptr,
         lpType: &Type,
         lpData: Data,
         lpcbData: &cbData) != 0
    || sscanf(string: (const char *)Data, format: "(%f %f %f)", &tmp, &tmp.y, &tmp.z) != 3 )
  {
    return 0;
  }
  *value = (QAngle)tmp;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428BD0
// Name: bool RegReadColor(struct HKEY__ __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegReadColor(HKEY__ *hKey, const char *szSubKey, float *value)
{
  char szBuff[128]; // [esp+0h] [ebp-88h] BYREF
  unsigned int dwType; // [esp+80h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+84h] [ebp-4h] BYREF

  dwSize = 128;
  return RegQueryValueExA(
           hKey,
           lpValueName: szSubKey,
           lpReserved: nullptr,
           lpType: &dwType,
           lpData: (LPBYTE)szBuff,
           lpcbData: &dwSize) == 0
      && sscanf(string: szBuff, format: "(%f %f %f %f)", value, value + 1, value + 2, value + 3) == 4;
}

//------------------------------------------------------------------------------
// Address: 0x00428C40
// Name: bool RegWriteVector(struct HKEY__ __near *,char const __near *,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteVector(HKEY__ *hKey, const char *szSubKey, Vector *value)
{
  char szBuff[128]; // [esp+18h] [ebp-80h] BYREF

  sprintf(string: szBuff, format: "(%f %f %f)", value->x, value->y, value->z);
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)szBuff,
           cbData: strlen(szBuff)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00428CC0
// Name: bool RegWriteQAngle(struct HKEY__ __near *,char const __near *,class QAngle __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteQAngle(HKEY__ *hKey, const char *szSubKey, QAngle *value)
{
  char string[128]; // [esp+18h] [ebp-80h] BYREF

  sprintf(string, format: "(%f %f %f)", value->x, value->y, value->z);
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)string,
           cbData: strlen(string)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00428D40
// Name: bool RegWriteColor(struct HKEY__ __near *,char const __near *,float __near * const)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteColor(HKEY__ *hKey, const char *szSubKey, float *value)
{
  char szBuff[128]; // [esp+20h] [ebp-80h] BYREF

  sprintf(string: szBuff, format: "(%f %f %f %f)", *value, value[1], value[2], value[3]);
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)szBuff,
           cbData: strlen(szBuff)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00428DD0
// Name: bool RegReadBool(struct HKEY__ __near *,char const __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RegReadBool(HKEY__ *hKey, const char *szSubKey, bool *value)
{
  unsigned int dwTemp; // [esp+0h] [ebp-Ch] BYREF
  unsigned int dwType; // [esp+4h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+8h] [ebp-4h] BYREF

  dwSize = 4;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: szSubKey,
         lpReserved: nullptr,
         lpType: &dwType,
         lpData: (LPBYTE)&dwTemp,
         lpcbData: &dwSize) != 0
    || dwType != 4 )
  {
    return 0;
  }
  *value = dwTemp != 0;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428E20
// Name: bool RegReadInt(struct HKEY__ __near *,char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegReadInt(HKEY__ *hKey, const char *szSubKey, int *value)
{
  unsigned int dwType; // [esp+0h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+4h] [ebp-4h] BYREF

  dwSize = 4;
  return RegQueryValueExA(
           hKey,
           lpValueName: szSubKey,
           lpReserved: nullptr,
           lpType: &dwType,
           lpData: (LPBYTE)value,
           lpcbData: &dwSize) == 0
      && dwType == 4;
}

//------------------------------------------------------------------------------
// Address: 0x00428E60
// Name: bool RegReadFloat(struct HKEY__ __near *,char const __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl RegReadFloat(HKEY__ *hKey, const char *szSubKey, float *value)
{
  char szBuff[128]; // [esp+0h] [ebp-88h] BYREF
  unsigned int dwType; // [esp+80h] [ebp-8h] BYREF
  unsigned int dwSize; // [esp+84h] [ebp-4h] BYREF

  dwSize = 128;
  if ( RegQueryValueExA(
         hKey,
         lpValueName: szSubKey,
         lpReserved: nullptr,
         lpType: &dwType,
         lpData: (LPBYTE)szBuff,
         lpcbData: &dwSize) != 0 )
    return 0;
  *value = atof(nptr: szBuff);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428EC0
// Name: bool RegWriteFloat(struct HKEY__ __near *,char const __near *,float)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteFloat(HKEY__ *hKey, const char *szSubKey, float value)
{
  char szBuff[128]; // [esp+8h] [ebp-80h] BYREF

  sprintf(string: szBuff, format: "%f", value);
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)szBuff,
           cbData: strlen(szBuff)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00428F20
// Name: bool RegReadString(struct HKEY__ __near *,char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegReadString(HKEY__ *hKey, const char *szSubKey, char *string, unsigned int size)
{
  unsigned int dwType; // [esp+0h] [ebp-4h] BYREF

  return RegQueryValueExA(
           hKey,
           lpValueName: szSubKey,
           lpReserved: nullptr,
           lpType: &dwType,
           lpData: (LPBYTE)string,
           lpcbData: &size) == 0
      && dwType == 1;
}

//------------------------------------------------------------------------------
// Address: 0x00428F60
// Name: bool RegWriteString(struct HKEY__ __near *,char const __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl RegWriteString(HKEY__ *hKey, const char *szSubKey, char *string)
{
  return RegSetValueExA(
           hKey,
           lpValueName: szSubKey,
           Reserved: 0,
           dwType: 1u,
           lpData: (const BYTE *)string,
           cbData: strlen(string)) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00428FA0
// Name: long RegViewerSettingsKey(char const __near *,struct HKEY__ __near * __near *,unsigned long __near *)
// Source: json
//------------------------------------------------------------------------------
LSTATUS __cdecl RegViewerSettingsKey(const char *filename, HKEY__ **phKey, unsigned int *lpdwDisposition)
{
  const char *v3; // eax
  char v5; // cl
  char *i; // ecx
  char v7; // al
  char szModelKey[1024]; // [esp+4h] [ebp-804h] BYREF
  char szFileName[1028]; // [esp+404h] [ebp-404h] BYREF

  v3 = filename;
  if ( strlen(filename) == 0 )
    return 1018;
  do
  {
    v5 = *v3;
    v3[szFileName - filename] = *v3;
    ++v3;
  }
  while ( v5 != 0 );
  for ( i = szFileName; *i != 0; ++i )
  {
    v7 = *i;
    if ( *i == 92 || v7 == 47 || v7 == 58 )
      *i = 46;
  }
  sprintf(string: szModelKey, format: "Software\\Valve\\%s\\%s", g_viewerSettings.registrysubkey, szFileName);
  return RegCreateKeyExA(
           hKey: HKEY_CURRENT_USER,
           lpSubKey: szModelKey,
           Reserved: 0,
           lpClass: nullptr,
           dwOptions: 0,
           samDesired: 0xF003Fu,
           lpSecurityAttributes: nullptr,
           phkResult: phKey,
           lpdwDisposition);
}

//------------------------------------------------------------------------------
// Address: 0x00429060
// Name: bool LoadViewerSettings(char const __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadViewerSettings(HKEY__ *filename, StudioModel *pModel)
{
  StudioModel *v2; // esi
  int v3; // eax
  int v4; // edi
  int v5; // edi
  int v6; // edi
  int v7; // edi
  int v8; // edi
  unsigned __int8 *mergeModelFile; // esi
  char szTemp[256]; // [esp+10h] [ebp-12Ch] BYREF
  char merge_buffer[32]; // [esp+110h] [ebp-2Ch] BYREF
  unsigned int Type; // [esp+130h] [ebp-Ch] BYREF
  unsigned int dwDisposition; // [esp+134h] [ebp-8h] BYREF
  unsigned int flTemp; // [esp+138h] [ebp-4h] BYREF

  if ( filename == nullptr )
    return 0;
  v2 = pModel;
  if ( pModel == nullptr
    || RegViewerSettingsKey((const char *)filename, phKey: &filename, lpdwDisposition: &dwDisposition) != 0
    || dwDisposition == 1 )
  {
    return 0;
  }
  RegReadQAngle(hKey: filename, szSubKey: "Rot", value: &v2->m_angles);
  RegReadVector(hKey: filename, szSubKey: "Trans", value: &v2->m_origin);
  RegReadColor(hKey: filename, szSubKey: "bgColor", value: g_viewerSettings.bgColor);
  RegReadColor(hKey: filename, szSubKey: "gColor", value: g_viewerSettings.gColor);
  RegReadColor(hKey: filename, szSubKey: "lColor", value: g_viewerSettings.lColor);
  RegReadColor(hKey: filename, szSubKey: "aColor", value: g_viewerSettings.aColor);
  RegReadQAngle(hKey: filename, szSubKey: "lightrot", value: &g_viewerSettings.lightrot);
  RegReadString(hKey: filename, szSubKey: "sequence", string: szTemp, size: 0x100u);
  v3 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  StudioModel::SetSequence(this: v2, iSequence: v3);
  RegReadString(hKey: filename, szSubKey: "overlaySequence0", string: szTemp, size: 0x100u);
  v4 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  RegReadFloat(hKey: filename, szSubKey: "overlayWeight0", value: (float *)&flTemp);
  StudioModel::SetOverlaySequence(this: v2, iLayer: 0, iSequence: v4, flWeight: *(float *)&flTemp);
  RegReadString(hKey: filename, szSubKey: "overlaySequence1", string: szTemp, size: 0x100u);
  v5 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  RegReadFloat(hKey: filename, szSubKey: "overlayWeight1", value: (float *)&flTemp);
  StudioModel::SetOverlaySequence(this: v2, iLayer: 1u, iSequence: v5, flWeight: *(float *)&flTemp);
  RegReadString(hKey: filename, szSubKey: "overlaySequence2", string: szTemp, size: 0x100u);
  v6 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  RegReadFloat(hKey: filename, szSubKey: "overlayWeight2", value: (float *)&flTemp);
  StudioModel::SetOverlaySequence(this: v2, iLayer: 2u, iSequence: v6, flWeight: *(float *)&flTemp);
  RegReadString(hKey: filename, szSubKey: "overlaySequence3", string: szTemp, size: 0x100u);
  v7 = StudioModel::LookupSequence(this: v2, szSequence: szTemp);
  RegReadFloat(hKey: filename, szSubKey: "overlayWeight3", value: (float *)&flTemp);
  StudioModel::SetOverlaySequence(this: v2, iLayer: 3u, iSequence: v7, flWeight: *(float *)&flTemp);
  RegReadFloat(hKey: filename, szSubKey: "speedscale", value: &g_viewerSettings.speedScale);
  if ( g_viewerSettings.speedScale > 1.0 )
    g_viewerSettings.speedScale = 1.0;
  RegReadInt(hKey: filename, szSubKey: "viewermode", value: &g_viewerSettings.application_mode);
  RegReadInt(hKey: filename, szSubKey: "thumbnailsize", value: &g_viewerSettings.thumbnailsize);
  RegReadInt(hKey: filename, szSubKey: "thumbnailsizeanim", value: &g_viewerSettings.thumbnailsizeanim);
  if ( g_viewerSettings.thumbnailsize == 0 )
    g_viewerSettings.thumbnailsize = 128;
  if ( g_viewerSettings.thumbnailsizeanim == 0 )
    g_viewerSettings.thumbnailsizeanim = 128;
  RegReadInt(hKey: filename, szSubKey: "speechapiindex", value: &g_viewerSettings.speechapiindex);
  RegReadInt(hKey: filename, szSubKey: "cclanguageid", value: &g_viewerSettings.cclanguageid);
  RegReadBool(hKey: filename, szSubKey: "showground", value: &g_viewerSettings.showGround);
  RegReadBool(hKey: filename, szSubKey: "showbackground", value: &g_viewerSettings.showBackground);
  RegReadBool(hKey: filename, szSubKey: "showshadow", value: &g_viewerSettings.showShadow);
  RegReadBool(hKey: filename, szSubKey: "showillumpos", value: &g_viewerSettings.showIllumPosition);
  RegReadBool(hKey: filename, szSubKey: "enablenormalmapping", value: &g_viewerSettings.enableNormalMapping);
  RegReadBool(hKey: filename, szSubKey: "enabledisplacementmapping", value: &g_viewerSettings.enableDisplacementMapping);
  RegReadBool(hKey: filename, szSubKey: "playsounds", value: &g_viewerSettings.playSounds);
  RegReadBool(hKey: filename, szSubKey: "showoriginaxis", value: &g_viewerSettings.showOriginAxis);
  RegReadFloat(hKey: filename, szSubKey: "originaxislength", value: &g_viewerSettings.originAxisLength);
  v8 = 0;
  mergeModelFile = (unsigned __int8 *)g_viewerSettings.mergeModelFile;
  do
  {
    V_snprintf(pDest: merge_buffer, maxLen: 32, pFormat: "merge%d", ++v8);
    flTemp = 256;
    RegQueryValueExA(
      hKey: filename,
      lpValueName: merge_buffer,
      lpReserved: nullptr,
      lpType: &Type,
      lpData: mergeModelFile,
      lpcbData: &flTemp);
    mergeModelFile += 256;
  }
  while ( (int)mergeModelFile < (int)g_viewerSettings.mergeModelFile[12] );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00429480
// Name: bool LoadViewerRootSettings(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadViewerRootSettings()
{
  char string[1024]; // [esp+0h] [ebp-414h] BYREF
  unsigned int dwDisposition; // [esp+400h] [ebp-14h] BYREF
  HKEY__ *hRootKey; // [esp+404h] [ebp-10h] BYREF
  unsigned int v4; // [esp+408h] [ebp-Ch] BYREF
  unsigned int Type; // [esp+40Ch] [ebp-8h] BYREF
  unsigned int cbData; // [esp+410h] [ebp-4h] BYREF

  sprintf(string, format: "Software\\Valve\\%s", g_viewerSettings.registrysubkey);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: string,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &hRootKey,
         lpdwDisposition: &dwDisposition) != 0 )
    return 0;
  cbData = 4;
  RegQueryValueExA(
    hKey: hRootKey,
    lpValueName: "renderxpos",
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&g_viewerSettings.xpos,
    lpcbData: &cbData);
  cbData = 4;
  RegQueryValueExA(
    hKey: hRootKey,
    lpValueName: "renderypos",
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&g_viewerSettings.ypos,
    lpcbData: &cbData);
  cbData = 4;
  RegQueryValueExA(
    hKey: hRootKey,
    lpValueName: "renderwidth",
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&g_viewerSettings.width,
    lpcbData: &cbData);
  cbData = 4;
  RegQueryValueExA(
    hKey: hRootKey,
    lpValueName: "renderheight",
    lpReserved: nullptr,
    lpType: &Type,
    lpData: (LPBYTE)&g_viewerSettings.height,
    lpcbData: &cbData);
  cbData = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "faceposerToolsDriveMouth",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&Type,
         lpcbData: &cbData) == 0
    && v4 == 4 )
  {
    g_viewerSettings.faceposerToolsDriveMouth = Type != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "showHidden",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.showHidden = cbData != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "showActivities",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.showActivities = cbData != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "showSequenceIndices",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.showSequenceIndices = cbData != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "sortSequences",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.sortSequences = cbData != 0;
  }
  Type = 4;
  if ( RegQueryValueExA(
         hKey: hRootKey,
         lpValueName: "dotaMode",
         lpReserved: nullptr,
         lpType: &v4,
         lpData: (LPBYTE)&cbData,
         lpcbData: &Type) == 0
    && v4 == 4 )
  {
    g_viewerSettings.dotaMode = cbData != 0;
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00429680
// Name: bool SaveViewerSettings(char const __near *,class StudioModel __near *)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SaveViewerSettings(HKEY__ *filename, StudioModel *pModel)
{
  StudioModel *v2; // esi
  IMDLCache *v4; // ebx
  void (__thiscall *BeginLock)(IMDLCache *); // edx
  CStudioHdr *StudioHdr; // edi
  int Sequence; // eax
  mstudioseqdesc_t *v8; // eax
  int OverlaySequence; // eax
  mstudioseqdesc_t *v10; // eax
  int v11; // eax
  mstudioseqdesc_t *v12; // eax
  int v13; // eax
  mstudioseqdesc_t *v14; // eax
  int v15; // eax
  mstudioseqdesc_t *v16; // eax
  int v17; // eax
  char *v18; // edi
  int v19; // ebx
  float value; // [esp+0h] [ebp-3Ch]
  float valuea; // [esp+0h] [ebp-3Ch]
  float valueb; // [esp+0h] [ebp-3Ch]
  float valuec; // [esp+0h] [ebp-3Ch]
  char merge_buffer[32]; // [esp+10h] [ebp-2Ch] BYREF
  unsigned int dwDisposition; // [esp+30h] [ebp-Ch] BYREF
  CMDLCacheCriticalSection cacheCriticalSection; // [esp+34h] [ebp-8h]
  BYTE Data[4]; // [esp+38h] [ebp-4h] BYREF

  if ( filename == nullptr )
    return 0;
  v2 = pModel;
  if ( pModel == nullptr
    || RegViewerSettingsKey((const char *)filename, phKey: &filename, lpdwDisposition: &dwDisposition) != 0 )
  {
    return 0;
  }
  v4 = g_pMDLCache;
  BeginLock = g_pMDLCache->BeginLock;
  cacheCriticalSection.m_pCache = g_pMDLCache;
  BeginLock(this: g_pMDLCache);
  StudioHdr = StudioModel::GetStudioHdr(this: v2);
  if ( StudioHdr != nullptr )
  {
    RegWriteQAngle(hKey: filename, szSubKey: "Rot", value: &v2->m_angles);
    RegWriteVector(hKey: filename, szSubKey: "Trans", value: &v2->m_origin);
    RegWriteColor(hKey: filename, szSubKey: "bgColor", value: g_viewerSettings.bgColor);
    RegWriteColor(hKey: filename, szSubKey: "gColor", value: g_viewerSettings.gColor);
    RegWriteColor(hKey: filename, szSubKey: "lColor", value: g_viewerSettings.lColor);
    RegWriteColor(hKey: filename, szSubKey: "aColor", value: g_viewerSettings.aColor);
    RegWriteQAngle(hKey: filename, szSubKey: "lightrot", value: &g_viewerSettings.lightrot);
    Sequence = StudioModel::GetSequence(this: v2);
    v8 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: Sequence);
    RegWriteString(hKey: filename, szSubKey: "sequence", string: (char *)v8 + v8->szlabelindex);
    OverlaySequence = StudioModel::GetOverlaySequence(this: v2, iLayer: 0);
    v10 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: OverlaySequence);
    RegWriteString(hKey: filename, szSubKey: "overlaySequence0", string: (char *)v10 + v10->szlabelindex);
    value = StudioModel::GetOverlaySequenceWeight(this: v2, iLayer: 0);
    RegWriteFloat(hKey: filename, szSubKey: "overlayWeight0", value);
    v11 = StudioModel::GetOverlaySequence(this: v2, iLayer: 1u);
    v12 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: v11);
    RegWriteString(hKey: filename, szSubKey: "overlaySequence1", string: (char *)v12 + v12->szlabelindex);
    valuea = StudioModel::GetOverlaySequenceWeight(this: v2, iLayer: 1u);
    RegWriteFloat(hKey: filename, szSubKey: "overlayWeight1", value: valuea);
    v13 = StudioModel::GetOverlaySequence(this: v2, iLayer: 2u);
    v14 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: v13);
    RegWriteString(hKey: filename, szSubKey: "overlaySequence2", string: (char *)v14 + v14->szlabelindex);
    valueb = StudioModel::GetOverlaySequenceWeight(this: v2, iLayer: 2u);
    RegWriteFloat(hKey: filename, szSubKey: "overlayWeight2", value: valueb);
    v15 = StudioModel::GetOverlaySequence(this: v2, iLayer: 3u);
    v16 = CStudioHdr::pSeqdesc(this: StudioHdr, iSequence: v15);
    RegWriteString(hKey: filename, szSubKey: "overlaySequence3", string: (char *)v16 + v16->szlabelindex);
    valuec = StudioModel::GetOverlaySequenceWeight(this: v2, iLayer: 3u);
    RegWriteFloat(hKey: filename, szSubKey: "overlayWeight3", value: valuec);
    RegWriteFloat(hKey: filename, szSubKey: "speedscale", value: g_viewerSettings.speedScale);
    *(_DWORD *)Data = g_viewerSettings.application_mode;
    RegSetValueExA(hKey: filename, lpValueName: "viewermode", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.thumbnailsize;
    RegSetValueExA(hKey: filename, lpValueName: "thumbnailsize", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.thumbnailsizeanim;
    RegSetValueExA(hKey: filename, lpValueName: "thumbnailsizeanim", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.speechapiindex;
    RegSetValueExA(hKey: filename, lpValueName: "speechapiindex", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.cclanguageid;
    RegSetValueExA(hKey: filename, lpValueName: "cclanguageid", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showGround;
    RegSetValueExA(hKey: filename, lpValueName: "showground", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showBackground;
    RegSetValueExA(hKey: filename, lpValueName: "showbackground", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showShadow;
    RegSetValueExA(hKey: filename, lpValueName: "showshadow", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showIllumPosition;
    RegSetValueExA(hKey: filename, lpValueName: "showillumpos", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.enableNormalMapping;
    RegSetValueExA(
      hKey: filename,
      lpValueName: "enablenormalmapping",
      Reserved: 0,
      dwType: 4u,
      lpData: Data,
      cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.enableDisplacementMapping;
    RegSetValueExA(
      hKey: filename,
      lpValueName: "enabledisplacementmapping",
      Reserved: 0,
      dwType: 4u,
      lpData: Data,
      cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.playSounds;
    RegSetValueExA(hKey: filename, lpValueName: "playsounds", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    *(_DWORD *)Data = g_viewerSettings.showOriginAxis;
    RegSetValueExA(hKey: filename, lpValueName: "showoriginaxis", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
    RegWriteFloat(hKey: filename, szSubKey: "originaxislength", value: g_viewerSettings.originAxisLength);
    v17 = 0;
    v18 = g_viewerSettings.mergeModelFile[0];
    do
    {
      v19 = v17 + 1;
      V_snprintf(pDest: merge_buffer, maxLen: 32, pFormat: "merge%d", v17 + 1);
      RegSetValueExA(
        hKey: filename,
        lpValueName: merge_buffer,
        Reserved: 0,
        dwType: 1u,
        lpData: (const BYTE *)v18,
        cbData: strlen(v18));
      v18 += 256;
      v17 = v19;
    }
    while ( (int)v18 < (int)g_viewerSettings.mergeModelFile[12] );
    cacheCriticalSection.m_pCache->EndLock(this: cacheCriticalSection.m_pCache);
    return 1;
  }
  else
  {
    v4->EndLock(this: v4);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00429AE0
// Name: bool SaveViewerRootSettings(void)
// Source: json
//------------------------------------------------------------------------------
char __cdecl SaveViewerRootSettings()
{
  char string[1024]; // [esp+0h] [ebp-40Ch] BYREF
  unsigned int dwDisposition; // [esp+400h] [ebp-Ch] BYREF
  HKEY__ *hRootKey; // [esp+404h] [ebp-8h] BYREF
  BYTE Data[4]; // [esp+408h] [ebp-4h] BYREF

  sprintf(string, format: "Software\\Valve\\%s", g_viewerSettings.registrysubkey);
  if ( RegCreateKeyExA(
         hKey: HKEY_CURRENT_USER,
         lpSubKey: string,
         Reserved: 0,
         lpClass: nullptr,
         dwOptions: 0,
         samDesired: 0xF003Fu,
         lpSecurityAttributes: nullptr,
         phkResult: &hRootKey,
         lpdwDisposition: &dwDisposition) != 0 )
    return 0;
  *(_DWORD *)Data = g_viewerSettings.xpos;
  RegSetValueExA(hKey: hRootKey, lpValueName: "renderxpos", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.ypos;
  RegSetValueExA(hKey: hRootKey, lpValueName: "renderypos", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.width;
  RegSetValueExA(hKey: hRootKey, lpValueName: "renderwidth", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.height;
  RegSetValueExA(hKey: hRootKey, lpValueName: "renderheight", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.faceposerToolsDriveMouth;
  RegSetValueExA(
    hKey: hRootKey,
    lpValueName: "faceposerToolsDriveMouth",
    Reserved: 0,
    dwType: 4u,
    lpData: Data,
    cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.showHidden;
  RegSetValueExA(hKey: hRootKey, lpValueName: "showHidden", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.showActivities;
  RegSetValueExA(hKey: hRootKey, lpValueName: "showActivities", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.showSequenceIndices;
  RegSetValueExA(hKey: hRootKey, lpValueName: "showSequenceIndices", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.sortSequences;
  RegSetValueExA(hKey: hRootKey, lpValueName: "sortSequences", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  *(_DWORD *)Data = g_viewerSettings.dotaMode;
  RegSetValueExA(hKey: hRootKey, lpValueName: "dotaMode", Reserved: 0, dwType: 4u, lpData: Data, cbData: 4u);
  return 1;
}

} // namespace hlmv
