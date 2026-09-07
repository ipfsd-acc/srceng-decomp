// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/glview/glview.cpp
// Functions: 19
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00401000
// Name: void KeyDown(int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl KeyDown(int key)
{
  switch ( key )
  {
    case 27:
      g_Update = 1;
      g_Active = 0;
      break;
    case 49:
      g_bShowList1 ^= 1u;
      g_Update = 1;
      break;
    case 50:
      g_bShowList2 ^= 1u;
      g_Update = 1;
      break;
    case 66:
      g_UseBlending ^= 1u;
      if ( g_UseBlending != 0 )
        glEnable(cap: 0xBE2u);
      else
        glDisable(cap: 0xBE2u);
      g_Update = 1;
      break;
    case 76:
      g_bShowLines ^= 1u;
      goto LABEL_12;
    case 80:
      g_bNoDepthPortals ^= 1u;
      g_Update = 1;
      break;
    case 112:
      glEnable(cap: 0xB44u);
      glCullFace(mode: 0x404u);
      g_Update = 1;
      break;
    default:
LABEL_12:
      g_Update = 1;
      break;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401140
// Name: void Cam_MouseMoved(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cam_MouseMoved()
{
  int top; // ecx
  int left; // eax
  int v2; // kr00_4
  int v3; // esi
  int v4; // edi
  tagRECT rect; // [esp+0h] [ebp-18h] BYREF
  tagPOINT cursorPoint; // [esp+10h] [ebp-8h] BYREF

  if ( g_Capture != 0 )
  {
    GetWindowRect(hWnd: camerawindow, lpRect: &rect);
    top = rect.top;
    if ( rect.top < 0 )
    {
      top = 0;
      rect.top = 0;
    }
    left = rect.left;
    if ( rect.left < 0 )
    {
      left = 0;
      rect.left = 0;
    }
    v2 = rect.right + left;
    v3 = (rect.right + left) / 2;
    v4 = (top + rect.bottom) / 2;
    GetCursorPos(lpPoint: &cursorPoint);
    SetCursorPos(X: v2 / 2, Y: v4);
    *(float *)&dword_43F420 = *(float *)&dword_43F420 - (float)((float)(cursorPoint.x - v3) * 0.2);
    angles[0] = angles[0] - (float)((float)(cursorPoint.y - v4) * 0.2);
    g_Update = 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401210
// Name: void Cam_Update(float)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cam_Update(float frametime)
{
  float v1; // xmm5_4
  BOOL v2; // ecx
  float v3; // xmm1_4
  int v4; // xmm2_4
  int v5; // xmm0_4
  BOOL v6; // ecx
  float v7; // xmm4_4
  float x; // xmm7_4
  BOOL v9; // ecx
  float v10; // xmm4_4
  BOOL v11; // ecx
  BOOL v12; // ecx
  BOOL v13; // ecx
  float v14; // xmm4_4
  BOOL v15; // ecx
  int v16; // xmm1_4
  BOOL v17; // ecx
  BOOL v18; // ecx
  BOOL v19; // ecx
  BOOL v20; // ecx
  float v21; // xmm0_4
  BOOL v22; // ecx
  BOOL v23; // ecx
  BOOL v24; // ecx

  v1 = g_flMovementSpeed;
  v2 = g_Keys[87] != 0;
  g_Keys[87] = g_Keys[87] & 1;
  if ( v2 )
  {
    v3 = (float)(vpn.x * (float)(g_flMovementSpeed * frametime)) + origin[0];
    *(float *)&v4 = (float)(vpn.y * (float)(g_flMovementSpeed * frametime)) + *(float *)&dword_43D01C;
    *(float *)&v5 = (float)(vpn.z * (float)(g_flMovementSpeed * frametime)) + *(float *)&dword_43D020;
    g_Update = 1;
    origin[0] = v3;
    dword_43D01C = v4;
    dword_43D020 = v5;
  }
  else
  {
    v5 = dword_43D020;
    v4 = dword_43D01C;
    v3 = origin[0];
  }
  v6 = g_Keys[83] != 0;
  g_Keys[83] = g_Keys[83] & 1;
  if ( v6 )
  {
    LODWORD(v7) = COERCE_UNSIGNED_INT(g_flMovementSpeed * frametime) ^ _mask__NegFloat_;
    v3 = v3 + (float)(vpn.x * v7);
    *(float *)&v4 = (float)(vpn.y * v7) + *(float *)&v4;
    *(float *)&v5 = (float)(vpn.z * v7) + *(float *)&v5;
    g_Update = 1;
    origin[0] = v3;
    dword_43D01C = v4;
    dword_43D020 = v5;
  }
  x = vright.x;
  v9 = g_Keys[65] != 0;
  g_Keys[65] = g_Keys[65] & 1;
  if ( v9 )
  {
    LODWORD(v10) = COERCE_UNSIGNED_INT(g_flMovementSpeed * frametime) ^ _mask__NegFloat_;
    v3 = v3 + (float)(vright.x * v10);
    *(float *)&v4 = *(float *)&v4 + (float)(vright.y * v10);
    *(float *)&v5 = *(float *)&v5 + (float)(vright.z * v10);
    x = vright.x;
    g_Update = 1;
    origin[0] = v3;
    dword_43D01C = v4;
    dword_43D020 = v5;
  }
  v11 = g_Keys[68] != 0;
  g_Keys[68] = g_Keys[68] & 1;
  if ( v11 )
  {
    v3 = v3 + (float)(x * (float)(g_flMovementSpeed * frametime));
    *(float *)&v4 = *(float *)&v4 + (float)(vright.y * (float)(g_flMovementSpeed * frametime));
    *(float *)&v5 = (float)(vright.z * (float)(g_flMovementSpeed * frametime)) + *(float *)&v5;
    g_Update = 1;
    origin[0] = v3;
    dword_43D01C = v4;
    dword_43D020 = v5;
  }
  v12 = g_Keys[38] != 0;
  g_Keys[38] = g_Keys[38] & 1;
  if ( v12 )
  {
    v3 = v3 + (float)(forward[0] * (float)(g_flMovementSpeed * frametime));
    *(float *)&v4 = *(float *)&v4 + (float)(*(float *)&dword_43F410 * (float)(g_flMovementSpeed * frametime));
    *(float *)&v5 = *(float *)&v5 + (float)(*(float *)&dword_43F414 * (float)(g_flMovementSpeed * frametime));
    g_Update = 1;
    origin[0] = v3;
    dword_43D01C = v4;
    dword_43D020 = v5;
  }
  v13 = g_Keys[40] != 0;
  g_Keys[40] = g_Keys[40] & 1;
  if ( v13 )
  {
    LODWORD(v14) = COERCE_UNSIGNED_INT(g_flMovementSpeed * frametime) ^ _mask__NegFloat_;
    *(float *)&v5 = *(float *)&v5 + (float)(*(float *)&dword_43F414 * v14);
    g_Update = 1;
    origin[0] = (float)(forward[0] * v14) + v3;
    *(float *)&dword_43D01C = (float)(*(float *)&dword_43F410 * v14) + *(float *)&v4;
    dword_43D020 = v5;
  }
  v15 = g_Keys[37] != 0;
  g_Keys[37] = g_Keys[37] & 1;
  if ( v15 )
  {
    *(float *)&v16 = (float)(frametime * 90.0) + *(float *)&dword_43F420;
    g_Update = 1;
    dword_43F420 = v16;
  }
  else
  {
    v16 = dword_43F420;
  }
  v17 = g_Keys[39] != 0;
  g_Keys[39] = g_Keys[39] & 1;
  if ( v17 )
  {
    g_Update = 1;
    *(float *)&dword_43F420 = *(float *)&v16 - (float)(frametime * 90.0);
  }
  v18 = g_Keys[70] != 0;
  g_Keys[70] = g_Keys[70] & 1;
  if ( v18 )
  {
    *(float *)&v5 = (float)(g_flMovementSpeed * frametime) + *(float *)&v5;
    g_Update = 1;
    dword_43D020 = v5;
  }
  v19 = g_Keys[67] != 0;
  g_Keys[67] = g_Keys[67] & 1;
  if ( v19 )
  {
    g_Update = 1;
    *(float *)&dword_43D020 = *(float *)&v5 - (float)(g_flMovementSpeed * frametime);
  }
  v20 = g_Keys[45] != 0;
  g_Keys[45] = g_Keys[45] & 1;
  if ( v20 )
  {
    g_Update = 1;
    angles[0] = (float)(frametime * 90.0) + angles[0];
    v21 = angles[0];
    if ( angles[0] > 85.0 )
    {
      v21 = 85.0;
      angles[0] = 85.0;
    }
  }
  else
  {
    v21 = angles[0];
  }
  v22 = g_Keys[46] != 0;
  g_Keys[46] = g_Keys[46] & 1;
  if ( v22 )
  {
    g_Update = 1;
    angles[0] = v21 - (float)(frametime * 90.0);
    if ( angles[0] < -85.0 )
      angles[0] = -85.0;
  }
  v23 = g_Keys[109] != 0;
  g_Keys[109] = g_Keys[109] & 1;
  if ( v23 )
  {
    v1 = g_flMovementSpeed - (float)(frametime * 100.0);
    g_Update = 1;
    g_flMovementSpeed = v1;
    if ( v1 < 0.0 )
    {
      v1 = 0.0;
      g_flMovementSpeed = 0.0;
    }
  }
  v24 = g_Keys[107] != 0;
  g_Keys[107] = g_Keys[107] & 1;
  if ( v24 )
  {
    g_Update = 1;
    g_flMovementSpeed = (float)(frametime * 100.0) + v1;
  }
  Cam_MouseMoved();
}

//------------------------------------------------------------------------------
// Address: 0x004016E0
// Name: void Cam_BuildMatrix(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Cam_BuildMatrix()
{
  float matrix[4][4]; // [esp+0h] [ebp-44h] BYREF
  float ya; // [esp+40h] [ebp-4h]

  ya = (float)(*(float *)&dword_43F420 * 0.0055555557) * 3.141592653589793;
  __libm_sse2_cos(x: *(long double *)&matrix[0][0]);
  forward[0] = ya;
  __libm_sse2_sin(x: *(long double *)&matrix[0][0]);
  dword_43F410 = LODWORD(ya);
  right[0] = ya;
  dword_43F83C = LODWORD(forward[0]) ^ _mask__NegFloat_;
  glGetFloatv(pname: 0xBA7u, params: matrix[0]);
  vup.x = matrix[0][1];
  vright.x = matrix[0][0];
  vpn.x = matrix[0][2];
  vup.y = matrix[1][1];
  vright.y = matrix[1][0];
  vpn.y = matrix[1][2];
  vup.z = matrix[2][1];
  vright.z = matrix[2][0];
  vpn.z = matrix[2][2];
  VectorNormalize(vec: &vright);
  VectorNormalize(vec: &vup);
  VectorNormalize(vec: &vpn);
}

//------------------------------------------------------------------------------
// Address: 0x00401810
// Name: void ReadPolyFileType(char const __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadPolyFileType(const char *name, GLuint nList, int drawLines)
{
  _iobuf *v3; // edi
  float v4; // xmm0_4
  int v5; // eax
  int i; // esi
  double v7; // xmm0_8
  double v8; // xmm0_8
  double v9; // xmm0_8
  float v10; // xmm1_4
  float v11; // xmm0_4
  long double v12; // [esp+10h] [ebp-30h]
  long double v13; // [esp+10h] [ebp-30h]
  long double v14; // [esp+10h] [ebp-30h]
  float v[8]; // [esp+18h] [ebp-28h] BYREF
  float divisor; // [esp+38h] [ebp-8h]
  int numverts; // [esp+3Ch] [ebp-4h] BYREF

  v3 = fopen(file: name, mode: "rt");
  if ( v3 == nullptr )
    _Error(a1: "Couldn't open %s", name);
  if ( g_bReadPortals != 0 )
    v4 = 2.0;
  else
    v4 = 1.0;
  divisor = v4;
  glNewList(list: nList, mode: 0x1300u);
  g_Center.x = 0.0;
  g_Center.y = 0.0;
  g_Center.z = 0.0;
  if ( drawLines != 0 )
    glLineWidth(width: 1.5);
  v5 = fscanf(stream: v3, format: "%i\n", &numverts);
  if ( v5 != 0 )
  {
    while ( 1 )
    {
      if ( v5 == -1 )
        goto LABEL_27;
      if ( drawLines == 0 )
        break;
      if ( numverts != 2 )
        goto LABEL_15;
      fscanf(stream: v3, format: "%f %f %f %f %f %f\n", v, &v[1], &v[2], &v[3], &v[4], &v[5]);
      fscanf(stream: v3, format: "%f %f %f %f %f %f\n", v, &v[1], &v[2], &v[3], &v[4], &v[5]);
LABEL_26:
      v5 = fscanf(stream: v3, format: "%i\n", &numverts);
      if ( v5 == 0 )
        goto LABEL_27;
    }
    if ( numverts == 2 )
LABEL_15:
      glBegin(mode: 2u);
    else
      glBegin(mode: 9u);
    for ( i = 0; i < numverts; g_Center.z = g_Center.z + v[2] )
    {
      fscanf(stream: v3, format: "%f %f %f %f %f %f\n", v, &v[1], &v[2], &v[3], &v[4], &v[5]);
      if ( drawLines != 0 )
      {
        glColor4f(red: 1.0, green: 1.0, blue: 0.0, alpha: 0.5);
      }
      else if ( g_bReadPortals != 0 )
      {
        if ( COERCE_FLOAT(COERCE_UNSIGNED_INT(COERCE_FLOAT(LODWORD(v[5]) & _mask__AbsFloat_) - 1.0) & _mask__AbsFloat_) >= 0.01 )
        {
          v[3] = (float)((float)(v[4] + v[5]) + v[3]) * 0.33333334;
          glColor4f(red: v[3] / divisor, green: v[3] / divisor, blue: v[3] / divisor, alpha: 0.60000002);
        }
        else
        {
          glColor4f(red: v[3], green: v[4], blue: v[5], alpha: 0.5);
        }
      }
      else
      {
        v7 = v[3];
        __libm_sse2_pow(x: v12, y: *(long double *)v);
        *(float *)&v7 = v7;
        v[3] = *(float *)&v7;
        v8 = v[4];
        __libm_sse2_pow(x: v13, y: *(long double *)v);
        *(float *)&v8 = v8;
        v[4] = *(float *)&v8;
        v9 = v[5];
        __libm_sse2_pow(x: v14, y: *(long double *)v);
        v10 = v9;
        v[5] = v10;
        glColor4f(
          red: (float)(1.0 / divisor) * v[3],
          green: (float)(1.0 / divisor) * v[4],
          blue: (float)(1.0 / divisor) * v10,
          alpha: 0.60000002);
      }
      glVertex3f(x: v[0], y: v[1], z: v[2]);
      ++g_nTotalPoints;
      g_Center.x = g_Center.x + v[0];
      g_Center.y = g_Center.y + v[1];
      ++i;
    }
    glEnd();
    goto LABEL_26;
  }
LABEL_27:
  if ( v3 != nullptr )
    fclose(stream: v3);
  glEndList();
  if ( g_nTotalPoints > 0 )
  {
    v11 = 1.0 / (float)g_nTotalPoints;
    g_Center.x = v11 * g_Center.x;
    g_Center.y = v11 * g_Center.y;
    g_Center.z = v11 * g_Center.z;
    *(Vector *)origin = g_Center;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401C10
// Name: void AddVCollideToList(struct phyheader_s __near &,struct vcollide_t __near &,struct phyviewparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __usercall AddVCollideToList(int a1@<esi>, phyheader_s *header, vcollide_t *collide, phyviewparams_t *params)
{
  int v5; // ebx
  int v6; // esi
  int k; // ebx
  matrix3x4_t xform; // [esp+8h] [ebp-7Ch] BYREF
  Vector verts[3]; // [esp+38h] [ebp-4Ch] BYREF
  Vector v2; // [esp+5Ch] [ebp-28h] BYREF
  Vector v1; // [esp+68h] [ebp-1Ch] BYREF
  Vector v0; // [esp+74h] [ebp-10h] BYREF
  int i; // [esp+80h] [ebp-4h]
  int j; // [esp+94h] [ebp+10h]

  AngleMatrix(angles: &params->angles, position: &params->offset, matrix: &xform);
  ClearBounds(mins: &params->mins, maxs: &params->maxs);
  v5 = 0;
  for ( i = 0; v5 < header->solidCount; i = v5 )
  {
    v6 = ((int (__thiscall *)(IPhysicsCollision *, CPhysCollide *, int))physcollision->CreateQueryModel)(
           a1: physcollision,
           a2: collide->solids[v5],
           a3: a1);
    j = 0;
    if ( (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6) > 0 )
    {
      do
      {
        for ( k = 0; k < (*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 8))(a1: v6, a2: j); ++k )
        {
          (*(void (__thiscall **)(int, int, int, Vector *))(*(_DWORD *)v6 + 16))(a1: v6, a2: j, a3: k, a4: verts);
          VectorTransform(in1: &verts[0].x, in2: &xform, out: &v0.x);
          VectorTransform(in1: &verts[1].x, in2: &xform, out: &v1.x);
          VectorTransform(in1: &verts[2].x, in2: &xform, out: &v2.x);
          AddPointToBounds(v: &v0, mins: &params->mins, maxs: &params->maxs);
          AddPointToBounds(v: &v1, mins: &params->mins, maxs: &params->maxs);
          AddPointToBounds(v: &v2, mins: &params->mins, maxs: &params->maxs);
          glBegin(mode: params->outputType);
          glColor3ub(red: 0xFFu, green: 0, blue: 0);
          glVertex3fv(v: &v0.x);
          glColor3ub(red: 0, green: 0xFFu, blue: 0);
          glVertex3fv(v: &v1.x);
          glColor3ub(red: 0, green: 0, blue: 0xFFu);
          glVertex3fv(v: &v2.x);
          glEnd();
        }
        ++j;
      }
      while ( j < (*(int (__thiscall **)(int))(*(_DWORD *)v6 + 4))(a1: v6) );
      v5 = i;
    }
    a1 = v6;
    ((void (__thiscall *)(IPhysicsCollision *))physcollision->DestroyQueryModel)(a1: physcollision);
    ++v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401DD0
// Name: void ReadPHYFile(char const __near *,struct phyviewparams_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadPHYFile(const char *name, phyviewparams_t *params)
{
  _iobuf *v2; // esi
  int v3; // ebx
  unsigned int v4; // edi
  void *v5; // esp
  _BYTE v6[12]; // [esp+0h] [ebp-2Ch] BYREF
  vcollide_t collide; // [esp+Ch] [ebp-20h] BYREF
  phyheader_s header; // [esp+1Ch] [ebp-10h] BYREF

  v2 = fopen(file: name, mode: "rb");
  if ( v2 == nullptr )
    _Error(a1: "Couldn't open %s", name);
  fread(buffer: &header, elementSize: 0x10u, count: 1u, stream: v2);
  if ( header.size == 16 && header.solidCount > 0 )
  {
    v3 = ftell(stream: v2);
    fseek(stream: v2, offset: 0, whence: 2);
    v4 = ftell(stream: v2) - v3;
    fseek(stream: v2, offset: v3, whence: 0);
    v5 = alloca(v4);
    fread(buffer: v6, elementSize: v4, count: 1u, stream: v2);
    fclose(stream: v2);
    physcollision->VCollideLoad(this: physcollision, a2: &collide, a3: header.solidCount, a4: v6, a5: v4, a6: false);
    AddVCollideToList(a1: (int)v2, &header, &collide, params);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00401EA0
// Name: void ReadPortalFile(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadPortalFile(char *name)
{
  _iobuf *v1; // esi
  int v2; // ebx
  int i; // eax
  int j; // edi
  char szDummy[80]; // [esp+1Ch] [ebp-84h] BYREF
  float v[8]; // [esp+6Ch] [ebp-34h] BYREF
  int nNumLeafs; // [esp+8Ch] [ebp-14h] BYREF
  int nNumPortals; // [esp+90h] [ebp-10h] BYREF
  int nLeafIndex[2]; // [esp+94h] [ebp-Ch] BYREF
  int numverts; // [esp+9Ch] [ebp-4h] BYREF

  v1 = fopen(file: name, mode: "r");
  if ( v1 == nullptr )
    _Error(a1: "Couldn't open %s", name);
  v2 = 0;
  glNewList(list: 2u, mode: 0x1300u);
  fscanf(stream: v1, format: "%79s\n", szDummy);
  fscanf(stream: v1, format: "%i\n", &nNumLeafs);
  fscanf(stream: v1, format: "%i\n", &nNumPortals);
  glLineWidth(width: 1.5);
  for ( i = fscanf(stream: v1, format: "%i %i %i ", &numverts, nLeafIndex, &nLeafIndex[1]);
        i != 0;
        i = fscanf(stream: v1, format: "%i %i %i ", &numverts, nLeafIndex, &nLeafIndex[1]) )
  {
    if ( i == -1 )
      break;
    glBegin(mode: 2u);
    for ( j = 0; j < numverts; ++j )
    {
      if ( fscanf(stream: v1, format: "(%f %f %f )\n", v, &v[1], &v[2]) != 3 )
        break;
      if ( v2 == g_nPortalHighlight || nLeafIndex[0] == g_nLeafHighlight || nLeafIndex[1] == g_nLeafHighlight )
        glColor4f(red: 1.0, green: 0.0, blue: 0.0, alpha: 1.0);
      else
        glColor4f(red: 1.0, green: 1.0, blue: 1.0, alpha: 1.0);
      glVertex3f(x: v[0], y: v[1], z: v[2]);
    }
    glEnd();
    ++v2;
  }
  if ( v1 != nullptr )
    fclose(stream: v1);
  glEndList();
}

//------------------------------------------------------------------------------
// Address: 0x00402080
// Name: int ReadDisplacementFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl ReadDisplacementFile(const char *filename)
{
  _iobuf *v1; // esi
  int v2; // ecx
  int v3; // eax
  _iobuf *pFile; // [esp+8h] [ebp-4h]

  v1 = fopen(file: filename, mode: "r");
  pFile = v1;
  if ( v1 == nullptr )
    _Error(a1: "Couldn't open %s", filename);
  v2 = dispPointCount;
  if ( dispPointCount < 4096 )
  {
    do
    {
      v1 = pFile;
      v3 = fscanf(
             stream: pFile,
             format: "%f %f %f %f %f %f",
             &dispPoints[v2],
             &dispPoints[v2].y,
             &dispPoints[v2].z,
             &dispNormals[v2],
             &dispNormals[v2].y,
             &dispNormals[v2].z);
      v2 = ++dispPointCount;
    }
    while ( v3 != 0 && v3 != -1 && v2 < 4096 );
  }
  fclose(stream: v1);
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402140
// Name: void DrawDisplacementData(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl DrawDisplacementData()
{
  int v0; // eax
  int v1; // edi
  int v2; // esi
  int v3; // esi
  int v4; // edi
  GLfloat *v5; // esi
  GLfloat *v6; // edi
  int v7; // edi
  int v8; // esi
  int v9; // edi
  int v10; // esi
  GLUquadric *pObject; // [esp+1Ch] [ebp-20h]
  int width; // [esp+20h] [ebp-1Ch]
  int widtha; // [esp+20h] [ebp-1Ch]
  int v14; // [esp+24h] [ebp-18h]
  int v15; // [esp+24h] [ebp-18h]
  int j; // [esp+24h] [ebp-18h]
  int v17; // [esp+28h] [ebp-14h]
  int i; // [esp+28h] [ebp-14h]
  float *p_y; // [esp+2Ch] [ebp-10h]
  int v20; // [esp+2Ch] [ebp-10h]
  int v21; // [esp+2Ch] [ebp-10h]
  float *v22; // [esp+30h] [ebp-Ch]
  int v23; // [esp+30h] [ebp-Ch]
  int v24; // [esp+30h] [ebp-Ch]
  int v25; // [esp+34h] [ebp-8h]
  int v26; // [esp+34h] [ebp-8h]
  int v27; // [esp+34h] [ebp-8h]
  int v28; // [esp+38h] [ebp-4h]

  pObject = gluNewQuadric();
  glEnable(cap: 0xB71u);
  v0 = dispPointCount;
  v1 = 0;
  if ( dispPointCount > 0 )
  {
    v2 = 0;
    do
    {
      glColor3f(red: 1.0, green: 0.0, blue: 0.0);
      glPushMatrix();
      glTranslatef(x: dispPoints[v2].x, y: dispPoints[v2].y, z: dispPoints[v2].z);
      gluSphere(qobj: pObject, radius: 5.0, slices: 5, stacks: 5);
      glPopMatrix();
      glColor3f(red: 1.0, green: 1.0, blue: 0.0);
      glBegin(mode: 1u);
      glVertex3f(x: dispPoints[v2].x, y: dispPoints[v2].y, z: dispPoints[v2].z);
      glVertex3f(
        x: (float)(dispNormals[v2].x * 50.0) + dispPoints[v2].x,
        y: (float)(dispNormals[v2].y * 50.0) + dispPoints[v2].y,
        z: (float)(dispNormals[v2].z * 50.0) + dispPoints[v2].z);
      glEnd();
      v0 = dispPointCount;
      ++v1;
      ++v2;
    }
    while ( v1 < dispPointCount );
  }
  v3 = (int)fsqrt((float)(v0 / 2));
  width = v3;
  glDisable(cap: 0xB44u);
  glColor3f(red: 0.0, green: 0.0, blue: 1.0);
  v4 = v3 - 1;
  v28 = v3 - 1;
  if ( v3 - 1 > 0 )
  {
    v25 = 12 * v3;
    p_y = &dispPoints[0].y;
    v22 = &dispPoints[v3].y;
    v14 = v3 - 1;
    do
    {
      v5 = v22;
      v6 = p_y;
      v17 = v28;
      do
      {
        glBegin(mode: 9u);
        glVertex3f(x: *(v6 - 1), y: *v6, z: v6[1]);
        glVertex3f(x: *(v5 - 1), y: *v5, z: v5[1]);
        glVertex3f(x: v5[2], y: v5[3], z: v5[4]);
        glVertex3f(x: v6[2], y: v6[3], z: v6[4]);
        glEnd();
        v5 += 3;
        v6 += 3;
        --v17;
      }
      while ( v17 != 0 );
      v22 = (float *)((char *)v22 + v25);
      p_y = (float *)((char *)p_y + v25);
      --v14;
    }
    while ( v14 != 0 );
    v3 = width;
    v4 = v28;
  }
  glColor3f(red: 0.0, green: 1.0, blue: 0.0);
  if ( v4 > 0 )
  {
    v20 = 0;
    v26 = 12 * v3;
    v23 = 12 * v3;
    for ( i = v4; i != 0; --i )
    {
      v7 = v20;
      v8 = v23;
      v15 = v28;
      do
      {
        glBegin(mode: 9u);
        glVertex3f(
          x: (float)(*(float *)((char *)&dispNormals[0].x + v7) * 150.0) + *(float *)((char *)&dispPoints[0].x + v7),
          y: (float)(*(float *)((char *)&dispNormals[0].y + v7) * 150.0) + *(float *)((char *)&dispPoints[0].y + v7),
          z: (float)(*(float *)((char *)&dispNormals[0].z + v7) * 150.0) + *(float *)((char *)&dispPoints[0].z + v7));
        glVertex3f(
          x: (float)(*(float *)((char *)&dispNormals[0].x + v8) * 150.0) + *(float *)((char *)&dispPoints[0].x + v8),
          y: (float)(*(float *)((char *)&dispNormals[0].y + v8) * 150.0) + *(float *)((char *)&dispPoints[0].y + v8),
          z: (float)(*(float *)((char *)&dispNormals[0].z + v8) * 150.0) + *(float *)((char *)&dispPoints[0].z + v8));
        glVertex3f(
          x: (float)(*(float *)((char *)&dispNormals[1].x + v8) * 150.0) + *(float *)((char *)&dispPoints[1].x + v8),
          y: (float)(*(float *)((char *)&dispNormals[1].y + v8) * 150.0) + *(float *)((char *)&dispPoints[1].y + v8),
          z: (float)(*(float *)((char *)&dispNormals[1].z + v8) * 150.0) + *(float *)((char *)&dispPoints[1].z + v8));
        glVertex3f(
          x: (float)(*(float *)((char *)&dispNormals[1].x + v7) * 150.0) + *(float *)((char *)&dispPoints[1].x + v7),
          y: (float)(*(float *)((char *)&dispNormals[1].y + v7) * 150.0) + *(float *)((char *)&dispPoints[1].y + v7),
          z: (float)(*(float *)((char *)&dispNormals[1].z + v7) * 150.0) + *(float *)((char *)&dispPoints[1].z + v7));
        glEnd();
        v8 += 12;
        v7 += 12;
        --v15;
      }
      while ( v15 != 0 );
      v20 += v26;
      v23 += v26;
    }
    v3 = width;
    v4 = v28;
  }
  glDisable(cap: 0xB71u);
  glColor3f(red: 0.0, green: 0.0, blue: 1.0);
  if ( v4 > 0 )
  {
    v21 = 0;
    v27 = 12 * v3;
    v24 = 12 * v3;
    for ( j = v4; j != 0; --j )
    {
      v9 = v21;
      v10 = v24;
      widtha = v28;
      do
      {
        glBegin(mode: 2u);
        glVertex3f(
          x: (float)(*(float *)((char *)&dispNormals[0].x + v9) * 150.0) + *(float *)((char *)&dispPoints[0].x + v9),
          y: (float)(*(float *)((char *)&dispNormals[0].y + v9) * 150.0) + *(float *)((char *)&dispPoints[0].y + v9),
          z: (float)(*(float *)((char *)&dispNormals[0].z + v9) * 150.0) + *(float *)((char *)&dispPoints[0].z + v9));
        glVertex3f(
          x: (float)(*(float *)((char *)&dispNormals[0].x + v10) * 150.0) + *(float *)((char *)&dispPoints[0].x + v10),
          y: (float)(*(float *)((char *)&dispNormals[0].y + v10) * 150.0) + *(float *)((char *)&dispPoints[0].y + v10),
          z: (float)(*(float *)((char *)&dispNormals[0].z + v10) * 150.0) + *(float *)((char *)&dispPoints[0].z + v10));
        glVertex3f(
          x: (float)(*(float *)((char *)&dispNormals[1].x + v10) * 150.0) + *(float *)((char *)&dispPoints[1].x + v10),
          y: (float)(*(float *)((char *)&dispNormals[1].y + v10) * 150.0) + *(float *)((char *)&dispPoints[1].y + v10),
          z: (float)(*(float *)((char *)&dispNormals[1].z + v10) * 150.0) + *(float *)((char *)&dispPoints[1].z + v10));
        glVertex3f(
          x: (float)(*(float *)((char *)&dispNormals[1].x + v9) * 150.0) + *(float *)((char *)&dispPoints[1].x + v9),
          y: (float)(*(float *)((char *)&dispNormals[1].y + v9) * 150.0) + *(float *)((char *)&dispPoints[1].y + v9),
          z: (float)(*(float *)((char *)&dispNormals[1].z + v9) * 150.0) + *(float *)((char *)&dispPoints[1].z + v9));
        glEnd();
        v10 += 12;
        v9 += 12;
        --widtha;
      }
      while ( widtha != 0 );
      v21 += v27;
      v24 += v27;
    }
  }
  gluDeleteQuadric(state: pObject);
}

//------------------------------------------------------------------------------
// Address: 0x00402820
// Name: int bSetupPixelFormat(struct HDC__ __near *)
// Source: json
//------------------------------------------------------------------------------
int __cdecl bSetupPixelFormat(HDC__ *hDC)
{
  int v1; // esi

  v1 = ChoosePixelFormat(hdc: hDC, ppfd: &pfd);
  if ( v1 == 0 )
    _Error(a1: "ChoosePixelFormat failed");
  if ( !SetPixelFormat(hdc: hDC, format: v1, ppfd: &pfd) )
    _Error(a1: "SetPixelFormat failed");
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00402870
// Name: void Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Draw()
{
  double v0; // xmm0_8
  GLdouble x; // [esp+8h] [ebp-20h]

  glClearColor(red: 0.0, green: 0.0, blue: 0.0, alpha: 0.0);
  glClear(mask: 0x4100u);
  glMatrixMode(mode: 0x1701u);
  glLoadIdentity();
  v0 = (float)(height / width);
  __libm_sse2_atan(x: (float)(width / height));
  *(float *)&v0 = v0;
  *(float *)&v0 = (float)((float)(*(float *)&v0 * 2.0) * 180.0) * 0.3183098861837907;
  gluPerspective(fovy: *(float *)&v0, aspect: x, zNear: 6.0, zFar: 20000.0);
  glRotatef(angle: -90.0, x: 1.0, y: 0.0, z: 0.0);
  glRotatef(angle: 90.0, x: 0.0, y: 0.0, z: 1.0);
  glRotatef(angle: angles[0], x: 0.0, y: 1.0, z: 0.0);
  glRotatef(angle: COERCE_GLFLOAT(dword_43F420 ^ _mask__NegFloat_), x: 0.0, y: 0.0, z: 1.0);
  glTranslatef(x: -origin[0], y: -origin[1], z: -origin[2]);
  Cam_BuildMatrix();
  glShadeModel(mode: 0x1D01u);
  glPolygonMode(face: 0x408u, mode: 0x1B02u);
  glFrontFace(mode: 0x900u);
  glCullFace(mode: 0x405u);
  glEnable(cap: 0xB44u);
  glDisable(cap: 0xDE1u);
  glBlendFunc(sfactor: 0x302u, dfactor: 0x303u);
  if ( g_UseBlending != 0 )
  {
    glEnable(cap: 0xBE2u);
    glDisable(cap: 0xB71u);
    glDisable(cap: 0xB44u);
  }
  else
  {
    glDisable(cap: 0xBE2u);
    glEnable(cap: 0xB71u);
  }
  glDepthFunc(func: 0x203u);
  if ( g_bDisp != 0 )
  {
    DrawDisplacementData();
  }
  else
  {
    if ( g_bShowList1 != 0 )
      glCallList(list: 1u);
    if ( g_bReadPortals != 0 )
    {
      if ( g_bNoDepthPortals != 0 )
        glDisable(cap: 0xB71u);
      glDisable(cap: 0xB44u);
      if ( g_bShowList2 != 0 )
        glCallList(list: 2u);
    }
    if ( g_bShowLines != 0 )
      glCallList(list: 3u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402B40
// Name: void ReadPolyFile(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ReadPolyFile(const char *name)
{
  void *(__cdecl *PhysicsFactory)(const char *, int *); // eax
  phyviewparams_t params; // [esp+4h] [ebp-38h] BYREF
  char ext[4]; // [esp+38h] [ebp-4h] BYREF

  V_ExtractFileExtension(path: name, dest: ext, destSize: 4);
  if ( _V_stricmp(s1: ext, s2: "phy") != 0 )
  {
    ReadPolyFileType(name, nList: 1u, drawLines: 0);
    ReadPolyFileType(name, nList: 3u, drawLines: 1);
  }
  else
  {
    PhysicsFactory = GetPhysicsFactory();
    physcollision = (IPhysicsCollision *)PhysicsFactory(a1: "VPhysicsCollision007", a2: nullptr);
    if ( physcollision != nullptr )
    {
      ClearBounds(mins: &params.mins, maxs: &params.maxs);
      memset(&params.offset, 0, 24);
      params.outputType = 9;
      glNewList(list: 1u, mode: 0x1300u);
      ReadPHYFile(name, &params);
      origin[0] = (float)(params.maxs.x + params.mins.x) * 0.5;
      origin[1] = (float)(params.maxs.y + params.mins.y) * 0.5;
      origin[2] = (float)(params.maxs.z + params.mins.z) * 0.5;
      glEndList();
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402C50
// Name: long WCam_WndProc(struct HWND__ __near *,unsigned int,unsigned int,long)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WCam_WndProc(HWND__ *hWnd, UINT uMsg, unsigned int wParam, LPARAM lParam)
{
  HGLRC Context; // eax
  int result; // eax
  HGLRC CurrentContext; // edi
  HDC CurrentDC; // ebx
  tagPAINTSTRUCT ps; // [esp+8h] [ebp-54h] BYREF
  tagRECT rect; // [esp+48h] [ebp-14h] BYREF
  int lRet; // [esp+58h] [ebp-4h]

  lRet = 1;
  GetClientRect(hWnd, lpRect: &rect);
  if ( uMsg > 0x100 )
  {
    if ( uMsg > 0x201 )
    {
      switch ( uMsg )
      {
        case 0x202u:
        case 0x205u:
        case 0x208u:
          if ( (wParam & 0x13) != 0 )
            return lRet;
          g_Capture = 0;
          ReleaseCapture();
          ShowCursor(bShow: true);
          result = lRet;
          break;
        case 0x204u:
        case 0x207u:
          goto $LN10;
        default:
          return DefWindowProcA(hWnd, Msg: uMsg, wParam, lParam);
      }
    }
    else if ( uMsg == 513 )
    {
$LN10:
      SetCapture(hWnd: camerawindow);
      ShowCursor(bShow: false);
      g_Capture = 1;
      return lRet;
    }
    else if ( uMsg == 257 )
    {
      g_Keys[(unsigned __int8)wParam] &= 2u;
      return lRet;
    }
    else
    {
      return DefWindowProcA(hWnd, Msg: uMsg, wParam, lParam);
    }
  }
  else if ( uMsg == 256 )
  {
    KeyDown(key: wParam);
    g_Keys[(unsigned __int8)wParam] = 3;
    return lRet;
  }
  else
  {
    switch ( uMsg )
    {
      case 1u:
        camdc = GetDC(hWnd);
        bSetupPixelFormat(hDC: camdc);
        Context = wglCreateContext(a1: camdc);
        baseRC = Context;
        if ( Context == nullptr )
        {
          _Error(a1: "wglCreateContext failed");
          Context = baseRC;
        }
        if ( !wglMakeCurrent(a1: camdc, a2: Context) )
          _Error(a1: "wglMakeCurrent failed");
        glCullFace(mode: 0x404u);
        glEnable(cap: 0xB44u);
        result = lRet;
        break;
      case 2u:
        CurrentContext = wglGetCurrentContext();
        CurrentDC = wglGetCurrentDC();
        wglMakeCurrent(a1: nullptr, a2: nullptr);
        if ( CurrentContext != nullptr )
          wglDeleteContext(a1: CurrentContext);
        if ( CurrentDC != nullptr )
          ReleaseDC(hWnd, hDC: CurrentDC);
        PostQuitMessage(nExitCode: 0);
        result = lRet;
        break;
      case 5u:
        InvalidateRect(hWnd: camerawindow, lpRect: nullptr, bErase: false);
        result = lRet;
        break;
      case 0xFu:
        BeginPaint(hWnd, lpPaint: &ps);
        if ( !wglMakeCurrent(a1: camdc, a2: baseRC) )
          _Error(a1: "wglMakeCurrent failed");
        Draw();
        SwapBuffers(a1: camdc);
        EndPaint(hWnd, lpPaint: &ps);
        result = lRet;
        break;
      case 0x10u:
        DestroyWindow(hWnd);
        result = lRet;
        break;
      case 0x83u:
        DefWindowProcA(hWnd, Msg: uMsg, wParam, lParam);
        result = 768;
        break;
      default:
        return DefWindowProcA(hWnd, Msg: uMsg, wParam, lParam);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402FA0
// Name: void WCam_Register(struct HINSTANCE__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WCam_Register(HINSTANCE__ *hInstance)
{
  tagWNDCLASSA wc; // [esp+4h] [ebp-28h] BYREF

  wc.style = 0;
  wc.lpfnWndProc = WCam_WndProc;
  wc.cbClsExtra = 0;
  wc.cbWndExtra = 0;
  wc.hInstance = hInstance;
  wc.hIcon = nullptr;
  wc.hCursor = LoadCursorA(hInstance: nullptr, lpCursorName: (LPCSTR)0x7F00);
  wc.hbrBackground = nullptr;
  wc.lpszMenuName = nullptr;
  wc.lpszClassName = "camera";
  if ( RegisterClassA(lpWndClass: &wc) == 0 )
    _Error(a1: "WCam_Register: failed");
}

//------------------------------------------------------------------------------
// Address: 0x00403020
// Name: void WCam_Create(struct HINSTANCE__ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WCam_Create(HINSTANCE__ *hInstance)
{
  int v1; // esi
  int v2; // edi
  int SystemMetrics; // eax
  HWND Window; // eax
  int nScx; // [esp+Ch] [ebp-4h]

  WCam_Register(hInstance);
  v1 = (int)width;
  v2 = (int)height;
  nScx = GetSystemMetrics(nIndex: 0);
  SystemMetrics = GetSystemMetrics(nIndex: 1);
  Window = CreateWindowExA(
             dwExStyle: 0,
             lpClassName: "camera",
             lpWindowName: "Camera View",
             dwStyle: 0x6CD0000u,
             X: (nScx - v1) / 2,
             Y: (SystemMetrics - v2) / 2,
             nWidth: v1,
             nHeight: v2,
             hWndParent: nullptr,
             hMenu: nullptr,
             hInstance,
             lpParam: nullptr);
  camerawindow = Window;
  if ( Window == nullptr )
  {
    _Error(a1: "Couldn't create camerawindow");
    Window = camerawindow;
  }
  ShowWindow(hWnd: Window, nCmdShow: 10);
}

//------------------------------------------------------------------------------
// Address: 0x004030C0
// Name: void AppRender(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl AppRender()
{
  double v0; // st7
  double time; // [esp+4h] [ebp-8h]

  v0 = (double)timeGetTime() * 0.001;
  time = v0 - lastTime;
  if ( v0 - lastTime > 0.2 )
    time = 0.2;
  lastTime = v0;
  if ( !wglMakeCurrent(a1: camdc, a2: baseRC) )
    _Error(a1: "wglMakeCurrent failed");
  Cam_Update(frametime: time);
  if ( g_Update != 0 )
  {
    Draw();
    SwapBuffers(a1: camdc);
    g_Update = 0;
  }
  else
  {
    Sleep(dwMilliseconds: 1u);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403190
// Name: WinMain(x,x,x,x)
// Source: json
//------------------------------------------------------------------------------
int __stdcall WinMain(HINSTANCE__ *hInstance, HINSTANCE__ *hPrevInstance, char *lpCmdLine, int nCmdShow)
{
  int *v4; // ebx
  int v5; // edi
  int CommandLine; // eax
  int v7; // ebx
  char *v8; // eax
  int v9; // edi
  int v10; // eax
  const char *v11; // edi
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  char *v19; // ecx
  char *v20; // eax
  char v21; // cl
  char v23; // [esp+3Fh] [ebp-121h] BYREF
  char szTempCmd[260]; // [esp+40h] [ebp-120h] BYREF
  tagMSG msg; // [esp+144h] [ebp-1Ch] BYREF
  char *lpCmdLinea; // [esp+170h] [ebp+10h]

  v4 = (int *)_CommandLine();
  v5 = *v4;
  CommandLine = _Plat_GetCommandLine();
  (*(void (__thiscall **)(int *, int))(v5 + 4))(a1: v4, a2: CommandLine);
  MathLib_Init(
    gamma: 2.2,
    texGamma: 2.2,
    brightness: 0.0,
    overbright: 2,
    bAllow3DNow: true,
    bAllowSSE: true,
    bAllowSSE2: true,
    bAllowMMX: true);
  if ( lpCmdLine == nullptr || *lpCmdLine == 0 )
    _Error(a1: "No file specified");
  main_instance = hInstance;
  v7 = _CommandLine();
  v8 = (char *)_CommandLine();
  v9 = *(_DWORD *)v8;
  lpCmdLinea = v8;
  v10 = (*(int (__thiscall **)(int))(*(_DWORD *)v7 + 36))(a1: v7);
  v11 = (const char *)(*(int (__thiscall **)(char *, int))(v9 + 44))(a1: lpCmdLinea, a2: v10 - 1);
  CmdLib_InitFileSystem(pFilename: v11, maxMemoryUsage: 0);
  v12 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v12 + 12))(a1: v12, a2: "-portal", a3: 0) != 0 )
  {
    g_bReadPortals = 1;
    v13 = _CommandLine();
    g_nPortalHighlight = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v13 + 28))(
                           a1: v13,
                           a2: "-portalhighlight",
                           a3: -1);
    v14 = _CommandLine();
    g_nLeafHighlight = (*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v14 + 28))(
                         a1: v14,
                         a2: "-leafhighlight",
                         a3: -1);
  }
  v15 = _CommandLine();
  g_flMovementSpeed = (float)(*(int (__thiscall **)(int, const char *, int))(*(_DWORD *)v15 + 28))(
                               a1: v15,
                               a2: "-speed",
                               a3: 320);
  v16 = _CommandLine();
  width = ((double (__thiscall *)(int, const char *, _DWORD))*(_DWORD *)(*(_DWORD *)v16 + 24))(
            a1: v16,
            a2: "-w",
            a3: LODWORD(width));
  v17 = _CommandLine();
  height = ((double (__thiscall *)(int, const char *, _DWORD))*(_DWORD *)(*(_DWORD *)v17 + 24))(
             a1: v17,
             a2: "-h",
             a3: LODWORD(height));
  WCam_Create(hInstance);
  v18 = _CommandLine();
  if ( (*(int (__thiscall **)(int, const char *, _DWORD))(*(_DWORD *)v18 + 12))(a1: v18, a2: "-disp", a3: 0) != 0 )
  {
    ReadDisplacementFile(filename: v11);
    g_bDisp = 1;
  }
  if ( v11 != nullptr && *v11 != 0 && g_bDisp == 0 )
    ReadPolyFile(name: v11);
  if ( g_bReadPortals != 0 )
  {
    strcpy(szTempCmd, v11);
    v19 = szTempCmd;
    do
    {
      if ( *v19 == 0 )
        break;
      if ( *v19 == 46 )
        break;
      ++v19;
    }
    while ( v19 != nullptr );
    *v19 = 0;
    v20 = &v23;
    do
      v21 = *++v20;
    while ( v21 != 0 );
    strcpy(v20, ".prt");
    ReadPortalFile(name: szTempCmd);
  }
  if ( g_Active == 0 )
    return 1;
  do
  {
    while ( PeekMessageA(lpMsg: &msg, hWnd: nullptr, wMsgFilterMin: 0, wMsgFilterMax: 0, wRemoveMsg: 1u) )
    {
      TranslateMessage(lpMsg: &msg);
      DispatchMessageA(lpMsg: &msg);
    }
    AppRender();
  }
  while ( g_Active != 0 );
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00403420
// Name: void __near * operator new(unsigned int)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl operator new(unsigned int nSize)
{
  return _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: nSize);
}
