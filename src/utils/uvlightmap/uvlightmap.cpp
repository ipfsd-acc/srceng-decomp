// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/uvlightmap/uvlightmap.cpp
// Functions: 7
// ============================================================

#include "utils\uvlightmap\uvlightmap.h"

//------------------------------------------------------------------------------
// Address: 0x00410B20
// Name: public: void CChangeUndoScopeGuard::Release(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CChangeUndoScopeGuard::Release(CChangeUndoScopeGuard *this)
{
  bool v2; // zf

  if ( !this->m_bReleased )
  {
    ((void (__stdcall *)(bool))g_pDataModel->SetUndoEnabled)(a1: this->m_bOldValue);
    v2 = !this->m_bNotify;
    this->m_bReleased = true;
    if ( !v2 )
    {
      g_pDataModel->PopNotificationScope(this: g_pDataModel, a2: false);
      this->m_bNotify = false;
    }
    if ( this->m_pNotify != nullptr )
    {
      g_pDataModel->RemoveNotificationCallback(this: g_pDataModel, a2: this->m_pNotify);
      this->m_pNotify = nullptr;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410B80
// Name: void Usage(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Usage()
{
  _Msg(a1: "\n");
  _Msg(a1: "  uvlightmap [processing options] [input] [output]\n");
  _Msg(a1: "    processing options:\n");
  _Msg(a1: "      <none>         simply perform convertion\n");
  _Msg(a1: "      -uv            generate uv atlas\n");
  _Msg(a1: "    input:\n");
  _Msg(a1: "      -imdl <file>   use MDL file as input\n");
  _Msg(a1: "      -iobj <file>   use OBJ file as input\n");
  _Msg(a1: "      -igts <file>   use GTS file as input\n");
  _Msg(a1: "    output:\n");
  _Msg(a1: "      -odmx <file>   use DMX file as output\n");
  _Msg(a1: "      -oobj <file>   use OBJ file as output\n");
  _Msg(a1: "      -ogts <file>   use GTS file as output\n");
  _Msg(a1: "      -oss2 <file>   use SS2 file as output\n");
  _Msg(a1: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00410C00
// Name: long ProcessInput(class CMeshDataUv __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ProcessInput(CMeshDataUv *mesh)
{
  int v1; // eax
  const char *v2; // eax
  int v4; // eax
  char *v5; // eax
  int v6; // eax
  char *v7; // eax

  v1 = _CommandLine();
  v2 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v1 + 32))(a1: v1, a2: "-imdl", a3: 0);
  if ( v2 != nullptr )
  {
    g_eInput = IN_MDL;
    return CMeshDataUv::LoadGeometryFromMDL(this: mesh, strFileName: v2, pOptions: nullptr);
  }
  else
  {
    v4 = _CommandLine();
    v5 = (char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 32))(a1: v4, a2: "-iobj", a3: 0);
    if ( v5 != nullptr )
    {
      g_eInput = IN_OBJ;
      return CMeshDataUv::LoadGeometryFromOBJ(this: mesh, strFileName: v5, pOptions: nullptr);
    }
    else
    {
      v6 = _CommandLine();
      v7 = (char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 32))(a1: v6, a2: "-igts", a3: 0);
      if ( v7 != nullptr )
      {
        g_eInput = IN_GTS;
        return CMeshDataUv::LoadGeometryFromGTS(this: mesh, strFileName: v7, pOptions: nullptr);
      }
      else
      {
        return -2147024809;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410CA0
// Name: long ProcessOutput(class CMeshDataUv __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ProcessOutput(CMeshDataUv *mesh)
{
  int v1; // eax
  const char *v2; // eax
  int v4; // eax
  const char *v5; // eax
  int v6; // eax
  const char *v7; // eax
  int v8; // eax
  const char *v9; // eax

  v1 = _CommandLine();
  v2 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v1 + 32))(a1: v1, a2: "-odmx", a3: 0);
  if ( v2 != nullptr )
  {
    g_eOutput = OUT_DMX;
    return CMeshDataUv::ExportAsDMX(this: mesh, strFileName: v2);
  }
  v4 = _CommandLine();
  v5 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v4 + 32))(a1: v4, a2: "-oobj", a3: 0);
  if ( v5 != nullptr )
  {
    if ( g_eInput == IN_GTS )
    {
      g_eOutput = OUT_OBJ;
      return CMeshDataUv::ExportGTSAsOBJ(this: mesh, strFileName: v5);
    }
  }
  else
  {
    v6 = _CommandLine();
    v7 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v6 + 32))(
                         a1: v6,
                         a2: "-ogts",
                         a3: 0);
    if ( v7 != nullptr )
    {
      if ( g_eInput == IN_OBJ )
      {
        g_eOutput = OUT_GTS;
        return CMeshDataUv::ExportAsGTS(this: mesh, strFileName: v7);
      }
    }
    else
    {
      v8 = _CommandLine();
      v9 = (const char *)(*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v8 + 32))(
                           a1: v8,
                           a2: "-oss2",
                           a3: 0);
      if ( v9 != nullptr )
      {
        g_eOutput = OUT_SS2;
        return CMeshDataUv::ExportAsSS2(this: mesh, strFileName: v9);
      }
    }
  }
  return -2147024809;
}

//------------------------------------------------------------------------------
// Address: 0x00410D80
// Name: long ProcessMesh(class CMeshDataUv __near &)
// Source: json
//------------------------------------------------------------------------------
HRESULT __cdecl ProcessMesh(CMeshDataUv *mesh)
{
  int v2; // eax
  int D3DMesh; // esi
  HRESULT v4; // esi
  unsigned int savedregs; // [esp+0h] [ebp+0h] BYREF

  if ( g_eInput <= IN_NONE )
    return -2147418113;
  if ( g_eInput > IN_OBJ )
  {
    if ( g_eInput == IN_GTS )
      return 1;
    return -2147418113;
  }
  v2 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *))(*(_DWORD *)v2 + 40))(a1: v2, a2: "-uv") == 0 )
    return 1;
  g_eProcessing = PROC_UVATLAS;
  D3DMesh = CMeshDataUv::CreateD3DMesh(this: mesh);
  if ( D3DMesh >= 0 )
  {
    v4 = CMeshDataUv::CreateUvAtlas(this: mesh, a2: &savedregs, a3: (int)mesh, a4: D3DMesh);
    if ( v4 >= 0 )
    {
      return 0;
    }
    else
    {
      _Msg(a1: "ERROR: Failed to create uv atlas\n");
      return v4;
    }
  }
  else
  {
    _Msg(a1: "ERROR: Failed to create mesh\n");
    return D3DMesh;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00410E20
// Name: public: CDisableUndoScopeGuard::CDisableUndoScopeGuard(void)
// Source: json
//------------------------------------------------------------------------------
CDisableUndoScopeGuard *__thiscall CDisableUndoScopeGuard::CDisableUndoScopeGuard(CDisableUndoScopeGuard *this)
{
  *(_WORD *)&this->m_bReleased = 0;
  this->m_pNotify = nullptr;
  this->m_bOldValue = g_pDataModel->IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00410E60
// Name: int conapp_main(void)
// Source: json
//------------------------------------------------------------------------------
int __cdecl conapp_main()
{
  bool (__thiscall *IsUndoEnabled)(IDataModel *); // edx
  HWND MainWnd; // edi
  IDirect3D9 *v3; // esi
  __int64 v4; // kr00_8
  int v5; // eax
  __int64 v6; // rax
  int v7; // eax
  CMeshDataUv mesh; // [esp+8h] [ebp-1C8h] BYREF
  IDirect3DDevice9 *pDevice; // [esp+1C4h] [ebp-Ch] BYREF
  CDisableUndoScopeGuard noDmxUndo; // [esp+1C8h] [ebp-8h] BYREF

  InstallDmElementFactories();
  IsUndoEnabled = g_pDataModel->IsUndoEnabled;
  noDmxUndo.m_bNotify = false;
  noDmxUndo.m_pNotify = nullptr;
  *(_WORD *)&noDmxUndo.m_bOldValue = IsUndoEnabled(this: g_pDataModel);
  g_pDataModel->SetUndoEnabled(this: g_pDataModel, a2: false);
  MainWnd = CreateMainWnd();
  if ( MainWnd != nullptr )
  {
    v3 = Direct3DCreate9(SDKVersion: 0x20u);
    if ( v3 != nullptr )
    {
      pDevice = nullptr;
      CreateMainDevice(hWnd: MainWnd, pD3D: v3, ppDevice: &pDevice);
      if ( pDevice != nullptr )
      {
        v4 = _time64(timeptr: nullptr);
        CMeshDataUv::CMeshDataUv(this: &mesh);
        CMeshDataUv::SetD3DDevice(this: &mesh, pd3dDevice: pDevice);
        v5 = ProcessInput(&mesh);
        if ( v5 >= 0 )
        {
          if ( ProcessMesh(&mesh) >= 0 )
          {
            if ( ProcessOutput(&mesh) >= 0 )
            {
              CMeshDataUv::Destroy(this: &mesh);
              pDevice->Release(this: pDevice);
              v3->Release(this: v3);
              v6 = _time64(timeptr: nullptr);
              v7 = (int)_difftime64(b: v6, a: v4);
              if ( v7 <= 60 )
                _Msg(a1: "Time: %d sec\n", v7);
              else
                _Msg(a1: "Time: %d min %d sec\n", v7 / 60, v7 % 60);
              CMeshDataUv::~CMeshDataUv(this: &mesh);
              CChangeUndoScopeGuard::Release(this: &noDmxUndo);
              return 0;
            }
            else
            {
              _Msg(a1: "ERROR: Failed to export geometry.\n");
              CMeshDataUv::~CMeshDataUv(this: &mesh);
              CChangeUndoScopeGuard::Release(this: &noDmxUndo);
              return -1;
            }
          }
          else
          {
            _Msg(a1: "ERROR: Failed to process.\n");
            CMeshDataUv::~CMeshDataUv(this: &mesh);
            CChangeUndoScopeGuard::Release(this: &noDmxUndo);
            return -1;
          }
        }
        else
        {
          if ( v5 == -2147024809 )
            Usage();
          else
            _Msg(a1: "ERROR: Failed to load geometry.\n");
          CMeshDataUv::~CMeshDataUv(this: &mesh);
          CChangeUndoScopeGuard::Release(this: &noDmxUndo);
          return -1;
        }
      }
      else
      {
        _Msg(a1: "ERROR: Failed to create DirectX device\n");
        CChangeUndoScopeGuard::Release(this: &noDmxUndo);
        return -1;
      }
    }
    else
    {
      _Msg(a1: "ERROR: Failed to initialize DirectX\n");
      CChangeUndoScopeGuard::Release(this: &noDmxUndo);
      return -1;
    }
  }
  else
  {
    _Msg(a1: "ERROR: Failed to create window\n");
    CChangeUndoScopeGuard::Release(this: &noDmxUndo);
    return -1;
  }
}
