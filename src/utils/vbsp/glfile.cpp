// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/vbsp/glfile.cpp
// Functions: 3
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x00412A90
// Name: void OutputWinding(struct winding_t __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl OutputWinding(winding_t *w, void *glview)
{
  int v3; // edi
  float v4; // xmm0_4
  int v5; // ebx
  float light; // [esp+44h] [ebp+8h]

  CmdLib_FPrintf(hFile: glview, pFormat: "%i\n", w->numpoints);
  level += 28;
  v3 = 0;
  v4 = (double)(unsigned __int8)level * 0.00392156862745098;
  light = v4;
  if ( w->numpoints > 0 )
  {
    v5 = 0;
    while ( 1 )
    {
      CmdLib_FPrintf(
        hFile: glview,
        pFormat: "%6.3f %6.3f %6.3f %6.3f %6.3f %6.3f\n",
        w->p[v5].x,
        w->p[v5].y,
        w->p[v5].z,
        v4,
        v4,
        v4);
      ++v3;
      ++v5;
      if ( v3 >= w->numpoints )
        break;
      v4 = light;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412B60
// Name: void WriteGLView_r(struct node_t __near *,void __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteGLView_r(node_t *node, void *glview)
{
  portal_t *portals; // esi
  node_t *v3; // eax
  int contents; // eax
  int v5; // ecx
  int v6; // edi
  winding_t *winding; // ebx

  for ( ; node->planenum != -1; node = node->children[1] )
    WriteGLView_r(node: node->children[0], glview);
  portals = node->portals;
  while ( portals != nullptr )
  {
    v3 = portals->nodes[0];
    if ( v3 != node )
    {
      portals = portals->next[1];
      continue;
    }
    if ( portals->onnode != nullptr )
    {
      contents = v3->contents;
      v5 = portals->nodes[1]->contents;
      if ( contents != v5 )
      {
        if ( contents == 0 )
        {
          v6 = 1;
LABEL_11:
          ++c_glfaces;
          winding = portals->winding;
          if ( v6 == 2 )
            winding = ReverseWinding(w: portals->winding);
          OutputWinding(w: winding, glview);
          if ( v6 == 2 )
            FreeWinding(w: winding);
          goto LABEL_15;
        }
        if ( v5 == 0 )
        {
          v6 = 2;
          goto LABEL_11;
        }
      }
    }
LABEL_15:
    portals = portals->next[0];
  }
}

//------------------------------------------------------------------------------
// Address: 0x00412C20
// Name: void WriteGLView(struct tree_t __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl WriteGLView(tree_t *tree, char *source)
{
  void *v2; // esi
  char name[1024]; // [esp+8h] [ebp-400h] BYREF

  c_glfaces = 0;
  sprintf(string: name, format: "%s%s.gl", outbase, source);
  _Msg(a1: "Writing %s\n", name);
  v2 = g_pFileSystem->Open(this: g_pFileSystem, a2: name, a3: "w", a4: 0);
  if ( v2 == nullptr )
    _Error(a1: "Couldn't open %s", name);
  WriteGLView_r(node: tree->headnode, glview: v2);
  g_pFileSystem->Close(this: g_pFileSystem, a2: v2);
  _Msg(a1: "%5i c_glfaces\n", c_glfaces);
}
