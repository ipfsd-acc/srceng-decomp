// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/common/utilmatlib.cpp
// Functions: 7
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x10070440
// Name: void __near * FindMaterial(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl FindMaterial(const char *materialName, bool *pFound, BOOL bComplain)
{
  IMaterial *result; // eax
  IMaterial *v4; // esi

  result = g_pMaterialSystem->FindMaterial(
             this: g_pMaterialSystem,
             a2: materialName,
             a3: "Other textures",
             a4: bComplain,
             a5: 0);
  v4 = result;
  if ( pFound != nullptr )
  {
    *pFound = true;
    if ( result == nullptr || result->IsErrorMaterial(this: result) )
      *pFound = false;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10070490
// Name: void GetMaterialDimensions(void __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialDimensions(void *materialHandle, int *width, int *height)
{
  int *v3; // esi
  int *v4; // edi
  ImageFormat dummyImageFormat; // [esp+8h] [ebp-4h] BYREF

  v3 = height;
  v4 = width;
  if ( (*(int (__thiscall **)(void *, int *, int *, ImageFormat *, char *))(*(_DWORD *)materialHandle + 8))(
         a1: materialHandle,
         a2: width,
         a3: height,
         a4: &dummyImageFormat,
         a5: (char *)&materialHandle + 3) != 1 )
  {
    *v4 = 128;
    *v3 = 128;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100704D0
// Name: void GetMaterialReflectivity(void __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialReflectivity(void *materialHandle, Vector *reflectivityVect)
{
  void *v2; // esi
  int v3; // eax
  Vector tmp; // [esp+4h] [ebp-Ch] BYREF

  v2 = materialHandle;
  v3 = (*(int (__thiscall **)(void *, const char *, char *, _DWORD))(*(_DWORD *)materialHandle + 44))(
         a1: materialHandle,
         a2: "$reflectivity",
         a3: (char *)&materialHandle + 3,
         a4: 0);
  if ( HIBYTE(materialHandle) != 0 )
  {
    (*(void (__thiscall **)(int, Vector *, int))(*(_DWORD *)v3 + 116))(a1: v3, a2: reflectivityVect, a3: 3);
  }
  else
  {
    (*(void (__thiscall **)(void *, Vector *))(*(_DWORD *)v2 + 124))(a1: v2, a2: &tmp);
    *reflectivityVect = tmp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10070540
// Name: int GetMaterialShaderPropertyBool(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialShaderPropertyBool(void *materialHandle, int propID)
{
  if ( propID == 0 )
    return (*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)materialHandle + 128))(a1: materialHandle, a2: 3);
  if ( propID == 1 )
    return (*(unsigned __int8 (__thiscall **)(void *, _DWORD))(*(_DWORD *)materialHandle + 128))(
             a1: materialHandle,
             a2: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10070580
// Name: int GetMaterialShaderPropertyInt(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialShaderPropertyInt(void *materialHandle, int propID)
{
  if ( propID != 2 )
    return 0;
  if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)materialHandle + 68))(a1: materialHandle) != 0 )
    return 2;
  return (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)materialHandle + 72))(a1: materialHandle) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100705C0
// Name: char const __near * GetMaterialVar(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialVar(void *materialHandle, const char *propertyName)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(void *, const char *, char *, _DWORD))(*(_DWORD *)materialHandle + 44))(
         a1: materialHandle,
         a2: propertyName,
         a3: (char *)&materialHandle + 3,
         a4: 0);
  if ( HIBYTE(materialHandle) != 0 )
    return (*(const char *(__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100705F0
// Name: char const __near * GetMaterialShaderName(void __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialShaderName(void *materialHandle)
{
  return (*(const char *(__thiscall **)(void *))(*(_DWORD *)materialHandle + 196))(a1: materialHandle);
}

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x0042A990
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x0042AA50
// Name: void LoadMaterialSystemInterface(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadMaterialSystemInterface(int a1@<edi>, int a2@<esi>)
{
  struct CSysModule *v2; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IMaterialSystem *v4; // eax

  if ( g_pMaterialSystem == nullptr )
  {
    v2 = (struct CSysModule *)((int (__thiscall *)(IFileSystem *, const char *, _DWORD, int, int, int))g_pFullFileSystem->LoadModule)(
                                a1: g_pFullFileSystem,
                                a2: "materialsystem.dll",
                                a3: 0,
                                a4: 1,
                                a5: a1,
                                a6: a2);
    if ( v2 == nullptr )
      _Error(a1: "Can't load MaterialSystem.dll\n");
    Factory = Sys_GetFactory(pModule: v2);
    if ( Factory != nullptr )
    {
      v4 = (IMaterialSystem *)Factory(a1: "VMaterialSystem080", a2: nullptr);
      g_pMaterialSystem = v4;
      if ( v4 != nullptr )
        goto LABEL_9;
      _Error(a1: "Could not get the material system interface from materialsystem.dll (..\\common\\utilmatlib.cpp)");
    }
    else
    {
      _Error(a1: "Could not find factory interface in library MaterialSystem.dll");
    }
    v4 = g_pMaterialSystem;
LABEL_9:
    if ( ((int (__thiscall *)(IMaterialSystem *, const char *, _DWORD))v4->Init_2)(
           a1: v4,
           a2: "shaderapiempty.dll",
           a3: 0) == 0 )
      _Error(a1: "Could not start the empty shader (shaderapiempty.dll)!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AAF0
// Name: void InitMaterialSystem(char const __near *,void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __usercall InitMaterialSystem(int a1@<edi>, int a2@<esi>)
{
  MaterialSystem_Config_t config; // [esp+0h] [ebp-64h] BYREF

  LoadMaterialSystemInterface(a1, a2);
  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x0042AB30
// Name: void ShutdownMaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownMaterialSystem()
{
  if ( g_pMaterialSystem != nullptr )
  {
    g_pMaterialSystem->Shutdown(this: g_pMaterialSystem);
    g_pMaterialSystem = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AB50
// Name: void __near * FindMaterial(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl FindMaterial(const char *materialName, bool *pFound, BOOL bComplain)
{
  IMaterial *result; // eax
  IMaterial *v4; // esi

  result = g_pMaterialSystem->FindMaterial(
             this: g_pMaterialSystem,
             a2: materialName,
             a3: "Other textures",
             a4: bComplain,
             a5: 0);
  v4 = result;
  if ( pFound != nullptr )
  {
    *pFound = true;
    if ( result == nullptr || result->IsErrorMaterial(this: result) )
      *pFound = false;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x0042ABA0
// Name: void GetMaterialDimensions(void __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialDimensions(void *materialHandle, int *width, int *height)
{
  int *v3; // esi
  int *v4; // edi
  ImageFormat dummyImageFormat; // [esp+8h] [ebp-4h] BYREF

  v3 = height;
  v4 = width;
  if ( (*(int (__thiscall **)(void *, int *, int *, ImageFormat *, char *))(*(_DWORD *)materialHandle + 8))(
         a1: materialHandle,
         a2: width,
         a3: height,
         a4: &dummyImageFormat,
         a5: (char *)&materialHandle + 3) != 1 )
  {
    *v4 = 128;
    *v3 = 128;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042ABE0
// Name: void GetMaterialReflectivity(void __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialReflectivity(void *materialHandle, Vector *reflectivityVect)
{
  void *v2; // esi
  int v3; // eax
  Vector tmp; // [esp+4h] [ebp-Ch] BYREF

  v2 = materialHandle;
  v3 = (*(int (__thiscall **)(void *, const char *, char *, _DWORD))(*(_DWORD *)materialHandle + 44))(
         a1: materialHandle,
         a2: "$reflectivity",
         a3: (char *)&materialHandle + 3,
         a4: 0);
  if ( HIBYTE(materialHandle) != 0 )
  {
    (*(void (__thiscall **)(int, Vector *, int))(*(_DWORD *)v3 + 116))(a1: v3, a2: reflectivityVect, a3: 3);
  }
  else
  {
    (*(void (__thiscall **)(void *, Vector *))(*(_DWORD *)v2 + 124))(a1: v2, a2: &tmp);
    *reflectivityVect = tmp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x0042AC50
// Name: int GetMaterialShaderPropertyBool(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialShaderPropertyBool(void *materialHandle, int propID)
{
  if ( propID == 0 )
    return (*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)materialHandle + 128))(a1: materialHandle, a2: 3);
  if ( propID == 1 )
    return (*(unsigned __int8 (__thiscall **)(void *, _DWORD))(*(_DWORD *)materialHandle + 128))(
             a1: materialHandle,
             a2: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042AC90
// Name: int GetMaterialShaderPropertyInt(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialShaderPropertyInt(void *materialHandle, int propID)
{
  if ( propID != 2 )
    return 0;
  if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)materialHandle + 68))(a1: materialHandle) != 0 )
    return 2;
  return (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)materialHandle + 72))(a1: materialHandle) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x0042ACD0
// Name: char const __near * GetMaterialVar(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialVar(void *materialHandle, const char *propertyName)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(void *, const char *, char *, _DWORD))(*(_DWORD *)materialHandle + 44))(
         a1: materialHandle,
         a2: propertyName,
         a3: (char *)&materialHandle + 3,
         a4: 0);
  if ( HIBYTE(materialHandle) != 0 )
    return (*(const char *(__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x0042AD00
// Name: char const __near * GetMaterialShaderName(void __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialShaderName(void *materialHandle)
{
  return (*(const char *(__thiscall **)(void *))(*(_DWORD *)materialHandle + 196))(a1: materialHandle);
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00422130
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004221F0
// Name: void LoadMaterialSystemInterface(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadMaterialSystemInterface(int a1@<edi>, int a2@<esi>)
{
  struct CSysModule *v2; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IMaterialSystem *v4; // eax

  if ( g_pMaterialSystem == nullptr )
  {
    v2 = (struct CSysModule *)((int (__thiscall *)(IFileSystem *, const char *, _DWORD, int, int, int))g_pFullFileSystem->LoadModule)(
                                a1: g_pFullFileSystem,
                                a2: "materialsystem.dll",
                                a3: 0,
                                a4: 1,
                                a5: a1,
                                a6: a2);
    if ( v2 == nullptr )
      _Error(a1: "Can't load MaterialSystem.dll\n");
    Factory = Sys_GetFactory(pModule: v2);
    if ( Factory != nullptr )
    {
      v4 = (IMaterialSystem *)Factory(a1: "VMaterialSystem080", a2: nullptr);
      g_pMaterialSystem = v4;
      if ( v4 != nullptr )
        goto LABEL_9;
      _Error(a1: "Could not get the material system interface from materialsystem.dll (..\\utils\\common\\utilmatlib.cpp)");
    }
    else
    {
      _Error(a1: "Could not find factory interface in library MaterialSystem.dll");
    }
    v4 = g_pMaterialSystem;
LABEL_9:
    if ( ((int (__thiscall *)(IMaterialSystem *, const char *, _DWORD))v4->Init_2)(
           a1: v4,
           a2: "shaderapiempty.dll",
           a3: 0) == 0 )
      _Error(a1: "Could not start the empty shader (shaderapiempty.dll)!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422290
// Name: void InitMaterialSystem(char const __near *,void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __usercall InitMaterialSystem(int a1@<edi>, int a2@<esi>)
{
  MaterialSystem_Config_t config; // [esp+0h] [ebp-64h] BYREF

  LoadMaterialSystemInterface(a1, a2);
  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x004222D0
// Name: void __near * FindMaterial(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl FindMaterial(const char *materialName, bool *pFound, BOOL bComplain)
{
  IMaterial *result; // eax
  IMaterial *v4; // esi

  result = g_pMaterialSystem->FindMaterial(
             this: g_pMaterialSystem,
             a2: materialName,
             a3: "Other textures",
             a4: bComplain,
             a5: 0);
  v4 = result;
  if ( pFound != nullptr )
  {
    *pFound = true;
    if ( result == nullptr || result->IsErrorMaterial(this: result) )
      *pFound = false;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00422320
// Name: void GetMaterialDimensions(void __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialDimensions(void *materialHandle, int *width, int *height)
{
  int *v3; // esi
  int *v4; // edi
  ImageFormat dummyImageFormat; // [esp+8h] [ebp-4h] BYREF

  v3 = height;
  v4 = width;
  if ( (*(int (__thiscall **)(void *, int *, int *, ImageFormat *, char *))(*(_DWORD *)materialHandle + 8))(
         a1: materialHandle,
         a2: width,
         a3: height,
         a4: &dummyImageFormat,
         a5: (char *)&materialHandle + 3) != 1 )
  {
    *v4 = 128;
    *v3 = 128;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00422360
// Name: void GetMaterialReflectivity(void __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialReflectivity(void *materialHandle, Vector *reflectivityVect)
{
  void *v2; // esi
  int v3; // eax
  Vector tmp; // [esp+4h] [ebp-Ch] BYREF

  v2 = materialHandle;
  v3 = (*(int (__thiscall **)(void *, const char *, char *, _DWORD))(*(_DWORD *)materialHandle + 44))(
         a1: materialHandle,
         a2: "$reflectivity",
         a3: (char *)&materialHandle + 3,
         a4: 0);
  if ( HIBYTE(materialHandle) != 0 )
  {
    (*(void (__thiscall **)(int, Vector *, int))(*(_DWORD *)v3 + 116))(a1: v3, a2: reflectivityVect, a3: 3);
  }
  else
  {
    (*(void (__thiscall **)(void *, Vector *))(*(_DWORD *)v2 + 124))(a1: v2, a2: &tmp);
    *reflectivityVect = tmp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004223D0
// Name: int GetMaterialShaderPropertyBool(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialShaderPropertyBool(void *materialHandle, int propID)
{
  if ( propID == 0 )
    return (*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)materialHandle + 128))(a1: materialHandle, a2: 3);
  if ( propID == 1 )
    return (*(unsigned __int8 (__thiscall **)(void *, _DWORD))(*(_DWORD *)materialHandle + 128))(
             a1: materialHandle,
             a2: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422410
// Name: int GetMaterialShaderPropertyInt(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialShaderPropertyInt(void *materialHandle, int propID)
{
  if ( propID != 2 )
    return 0;
  if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)materialHandle + 68))(a1: materialHandle) != 0 )
    return 2;
  return (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)materialHandle + 72))(a1: materialHandle) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x00422450
// Name: char const __near * GetMaterialVar(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialVar(void *materialHandle, const char *propertyName)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(void *, const char *, char *, _DWORD))(*(_DWORD *)materialHandle + 44))(
         a1: materialHandle,
         a2: propertyName,
         a3: (char *)&materialHandle + 3,
         a4: 0);
  if ( HIBYTE(materialHandle) != 0 )
    return (*(const char *(__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00422480
// Name: char const __near * GetMaterialShaderName(void __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialShaderName(void *materialHandle)
{
  return (*(const char *(__thiscall **)(void *))(*(_DWORD *)materialHandle + 196))(a1: materialHandle);
}

} // namespace vbsp2

// ============================================================
// Overlay from vmap (Missing functions)
// ============================================================
namespace vmap {

//------------------------------------------------------------------------------
// Address: 0x00433570
// Name: public: MaterialSystem_Config_t::MaterialSystem_Config_t(void)
// Source: json
//------------------------------------------------------------------------------
MaterialSystem_Config_t *__thiscall MaterialSystem_Config_t::MaterialSystem_Config_t(MaterialSystem_Config_t *this)
{
  unsigned int v2; // eax

  memset(dst: (unsigned __int8 *)this, value: 0, count: sizeof(MaterialSystem_Config_t));
  v2 = this->m_Flags & 0xFFF91A6C;
  this->m_fMonitorGamma = 2.2;
  this->m_Flags = v2 | 0x208;
  this->m_fGammaTVRangeMin = 16.0;
  this->m_fGammaTVRangeMax = 255.0;
  this->m_nAASamples = 1;
  *(_DWORD *)&this->bBufferPrimitives = 1;
  this->dxSupportLevel = 0;
  *(_WORD *)&this->m_bGammaTVEnabled = 0;
  this->bShowLowResImage = false;
  *(_DWORD *)&this->bNoTransparency = 0;
  *(_WORD *)&this->bEditMode = 0;
  this->m_bSuppressRendering = false;
  this->m_bPaintInMap = false;
  this->m_VideoMode.m_Width = 640;
  this->m_VideoMode.m_Height = 480;
  this->m_VideoMode.m_RefreshRate = 60;
  this->m_fGammaTVExponent = 2.5;
  *(_WORD *)&this->bShowSpecular = 257;
  *(_DWORD *)&this->bCompressedTextures = 65793;
  *(_DWORD *)&this->bShowNormalMap = 256;
  this->m_WindowedSizeLimitWidth = 1280;
  this->m_WindowedSizeLimitHeight = 1024;
  *(_DWORD *)&this->m_bShadowDepthTexture = 0x10000;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00433630
// Name: void LoadMaterialSystemInterface(void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __usercall LoadMaterialSystemInterface(int a1@<edi>, int a2@<esi>)
{
  struct CSysModule *v2; // esi
  void *(__cdecl *Factory)(const char *, int *); // eax
  IMaterialSystem *v4; // eax

  if ( g_pMaterialSystem == nullptr )
  {
    v2 = (struct CSysModule *)((int (__thiscall *)(IFileSystem *, const char *, _DWORD, int, int, int))g_pFullFileSystem->LoadModule)(
                                a1: g_pFullFileSystem,
                                a2: "materialsystem.dll",
                                a3: 0,
                                a4: 1,
                                a5: a1,
                                a6: a2);
    if ( v2 == nullptr )
      _Error(a1: "Can't load MaterialSystem.dll\n");
    Factory = Sys_GetFactory(pModule: v2);
    if ( Factory != nullptr )
    {
      v4 = (IMaterialSystem *)Factory(a1: "VMaterialSystem080", a2: nullptr);
      g_pMaterialSystem = v4;
      if ( v4 != nullptr )
        goto LABEL_9;
      _Error(
        a1: "Could not get the material system interface from materialsystem.dll (U:\\HiddenPath\\cstrike15\\src\\utils\\comm"
        "on\\utilmatlib.cpp)");
    }
    else
    {
      _Error(a1: "Could not find factory interface in library MaterialSystem.dll");
    }
    v4 = g_pMaterialSystem;
LABEL_9:
    if ( ((int (__thiscall *)(IMaterialSystem *, const char *, _DWORD))v4->Init_2)(
           a1: v4,
           a2: "shaderapiempty.dll",
           a3: 0) == 0 )
      _Error(a1: "Could not start the empty shader (shaderapiempty.dll)!");
  }
}

//------------------------------------------------------------------------------
// Address: 0x004336D0
// Name: void InitMaterialSystem(char const __near *,void __near * (*)(char const __near *,int __near *))
// Source: json
//------------------------------------------------------------------------------
void __usercall InitMaterialSystem(int a1@<edi>, int a2@<esi>)
{
  MaterialSystem_Config_t config; // [esp+0h] [ebp-64h] BYREF

  LoadMaterialSystemInterface(a1, a2);
  MaterialSystem_Config_t::MaterialSystem_Config_t(this: &config);
  g_pMaterialSystem->OverrideConfig(this: g_pMaterialSystem, a2: &config, a3: false);
}

//------------------------------------------------------------------------------
// Address: 0x00433710
// Name: void ShutdownMaterialSystem(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ShutdownMaterialSystem()
{
  if ( g_pMaterialSystem != nullptr )
  {
    g_pMaterialSystem->Shutdown(this: g_pMaterialSystem);
    g_pMaterialSystem = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433730
// Name: void __near * FindMaterial(char const __near *,bool __near *,bool)
// Source: json
//------------------------------------------------------------------------------
IMaterial *__cdecl FindMaterial(const char *materialName, bool *pFound, BOOL bComplain)
{
  IMaterial *result; // eax
  IMaterial *v4; // esi

  result = g_pMaterialSystem->FindMaterial(
             this: g_pMaterialSystem,
             a2: materialName,
             a3: "Other textures",
             a4: bComplain,
             a5: 0);
  v4 = result;
  if ( pFound != nullptr )
  {
    *pFound = true;
    if ( result == nullptr || result->IsErrorMaterial(this: result) )
      *pFound = false;
    return v4;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00433780
// Name: void GetMaterialDimensions(void __near *,int __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialDimensions(void *materialHandle, int *width, int *height)
{
  int *v3; // esi
  int *v4; // edi
  ImageFormat dummyImageFormat; // [esp+8h] [ebp-4h] BYREF

  v3 = height;
  v4 = width;
  if ( (*(int (__thiscall **)(void *, int *, int *, ImageFormat *, char *))(*(_DWORD *)materialHandle + 8))(
         a1: materialHandle,
         a2: width,
         a3: height,
         a4: &dummyImageFormat,
         a5: (char *)&materialHandle + 3) != 1 )
  {
    *v4 = 128;
    *v3 = 128;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004337C0
// Name: void GetMaterialReflectivity(void __near *,float __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl GetMaterialReflectivity(void *materialHandle, Vector *reflectivityVect)
{
  void *v2; // esi
  int v3; // eax
  Vector tmp; // [esp+4h] [ebp-Ch] BYREF

  v2 = materialHandle;
  v3 = (*(int (__thiscall **)(void *, const char *, char *, _DWORD))(*(_DWORD *)materialHandle + 44))(
         a1: materialHandle,
         a2: "$reflectivity",
         a3: (char *)&materialHandle + 3,
         a4: 0);
  if ( HIBYTE(materialHandle) != 0 )
  {
    (*(void (__thiscall **)(int, Vector *, int))(*(_DWORD *)v3 + 116))(a1: v3, a2: reflectivityVect, a3: 3);
  }
  else
  {
    (*(void (__thiscall **)(void *, Vector *))(*(_DWORD *)v2 + 124))(a1: v2, a2: &tmp);
    *reflectivityVect = tmp;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00433830
// Name: int GetMaterialShaderPropertyBool(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialShaderPropertyBool(void *materialHandle, int propID)
{
  if ( propID == 0 )
    return (*(unsigned __int8 (__thiscall **)(void *, int))(*(_DWORD *)materialHandle + 128))(a1: materialHandle, a2: 3);
  if ( propID == 1 )
    return (*(unsigned __int8 (__thiscall **)(void *, _DWORD))(*(_DWORD *)materialHandle + 128))(
             a1: materialHandle,
             a2: 0);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00433870
// Name: int GetMaterialShaderPropertyInt(void __near *,int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl GetMaterialShaderPropertyInt(void *materialHandle, int propID)
{
  if ( propID != 2 )
    return 0;
  if ( (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)materialHandle + 68))(a1: materialHandle) != 0 )
    return 2;
  return (*(unsigned __int8 (__thiscall **)(void *))(*(_DWORD *)materialHandle + 72))(a1: materialHandle) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x004338B0
// Name: char const __near * GetMaterialVar(void __near *,char const __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialVar(void *materialHandle, const char *propertyName)
{
  int v2; // eax

  v2 = (*(int (__thiscall **)(void *, const char *, char *, _DWORD))(*(_DWORD *)materialHandle + 44))(
         a1: materialHandle,
         a2: propertyName,
         a3: (char *)&materialHandle + 3,
         a4: 0);
  if ( HIBYTE(materialHandle) != 0 )
    return (*(const char *(__thiscall **)(int))(*(_DWORD *)v2 + 28))(a1: v2);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x004338E0
// Name: char const __near * GetMaterialShaderName(void __near *)
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl GetMaterialShaderName(void *materialHandle)
{
  return (*(const char *(__thiscall **)(void *))(*(_DWORD *)materialHandle + 196))(a1: materialHandle);
}

} // namespace vmap
