// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: engine/r_linefile.cpp
// Functions: 5
// ============================================================

#include "engine\r_linefile.h"

//------------------------------------------------------------------------------
// Address: 0x10106490
// Name: public: virtual char const __near * CBaseServer::GetMapName(void)const
// Source: json
//------------------------------------------------------------------------------
CCoreDispSurface *__thiscall CBaseServer::GetMapName(CCoreDispInfo *this)
{
  return &this->m_Surf;
}

//------------------------------------------------------------------------------
// Address: 0x101064A0
// Name: void Linefile_Draw(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Linefile_Draw()
{
  Vector *m_pMemory; // eax
  int v1; // edi
  Vector *v2; // esi

  m_pMemory = g_Points.m_Memory.m_pMemory;
  v1 = g_Points.m_Size - 1;
  if ( g_Points.m_Size - 1 > 0 )
  {
    do
    {
      v2 = m_pMemory + 1;
      RenderLine(v1: m_pMemory, v2: m_pMemory + 1, c: (Color)-16711681, bZBuffer: true);
      --v1;
      m_pMemory = v2;
    }
    while ( v1 != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101064E0
// Name: void Linefile_Read_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Linefile_Read_f()
{
  Vector *m_pMemory; // eax
  int v1; // edi
  int m_Size; // eax
  int v3; // esi
  Vector *v4; // ecx
  int v5; // eax
  Vector *v6; // eax
  char name[260]; // [esp+0h] [ebp-140h] BYREF
  CUtlBuffer buf; // [esp+104h] [ebp-3Ch] BYREF
  Vector org; // [esp+134h] [ebp-Ch] BYREF

  m_pMemory = g_Points.m_Memory.m_pMemory;
  g_Points.m_Size = 0;
  if ( g_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_Points.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_Points.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_Points.m_Memory.m_pMemory = nullptr;
    }
    g_Points.m_Memory.m_nAllocationCount = 0;
  }
  g_Points.m_pElements = m_pMemory;
  V_snprintf(pDest: name, maxLen: 260, pFormat: "maps/%s.lin", sv.m_szMapname);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1u);
  if ( g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: name,
         a3: nullptr,
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    ConMsg(a1: "Reading %s...\n", name);
    v1 = 0;
    while ( CUtlBuffer::Scanf(this: &buf, pFmt: "%f %f %f\n", &org, &org.y, &org.z) == 3 )
    {
      m_Size = g_Points.m_Size;
      ++v1;
      v3 = g_Points.m_Size;
      if ( g_Points.m_Size + 1 > g_Points.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&g_Points,
          num: g_Points.m_Size - g_Points.m_Memory.m_nAllocationCount + 1);
        m_Size = g_Points.m_Size;
      }
      v4 = g_Points.m_Memory.m_pMemory;
      g_Points.m_Size = m_Size + 1;
      v5 = m_Size - v3;
      g_Points.m_pElements = g_Points.m_Memory.m_pMemory;
      if ( v5 > 0 )
      {
        _V_memmove(dest: &g_Points.m_Memory.m_pMemory[v3 + 1], src: &g_Points.m_Memory.m_pMemory[v3], count: 12 * v5);
        v4 = g_Points.m_Memory.m_pMemory;
      }
      v6 = &v4[v3];
      if ( v6 != nullptr )
        *v6 = org;
    }
    ConMsg(a1: "%i lines read\n", v1);
  }
  else
  {
    ConMsg(a1: "couldn't open %s\n", name);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10314B20
// Name: _dynamic_initializer_for__linefile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__linefile__()
{
  ConCommand::ConCommand(
    this: &linefile,
    pName: &args.m_pArgSBuffer[88],
    callback: Linefile_Read_f,
    pHelpString: &args.m_pArgSBuffer[100],
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__linefile__);
}

//------------------------------------------------------------------------------
// Address: 0x10323050
// Name: _dynamic_atexit_destructor_for__linefile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__linefile__()
{
  ConCommand::~ConCommand(this: &linefile);
}

// ============================================================
// Overlay from engine_xlsp (Missing functions)
// ============================================================
namespace engine_xlsp {

//------------------------------------------------------------------------------
// Address: 0x100C08A0
// Name: public: virtual char const __near * CBaseServer::GetMapName(void)const
// Source: json
//------------------------------------------------------------------------------
CCoreDispSurface *__thiscall CBaseServer::GetMapName(CCoreDispInfo *this)
{
  return &this->m_Surf;
}

//------------------------------------------------------------------------------
// Address: 0x101064D0
// Name: void Linefile_Read_f(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl Linefile_Read_f()
{
  Vector *m_pMemory; // eax
  int v1; // edi
  int m_Size; // eax
  int v3; // esi
  Vector *v4; // ecx
  int v5; // eax
  Vector *v6; // eax
  char name[260]; // [esp+0h] [ebp-140h] BYREF
  CUtlBuffer buf; // [esp+104h] [ebp-3Ch] BYREF
  Vector org; // [esp+134h] [ebp-Ch] BYREF

  m_pMemory = g_Points.m_Memory.m_pMemory;
  g_Points.m_Size = 0;
  if ( g_Points.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_Points.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_Points.m_Memory.m_pMemory);
      m_pMemory = nullptr;
      g_Points.m_Memory.m_pMemory = nullptr;
    }
    g_Points.m_Memory.m_nAllocationCount = 0;
  }
  g_Points.m_pElements = m_pMemory;
  V_snprintf(pDest: name, maxLen: 260, pFormat: "maps/%s.lin", sv.m_szMapname);
  CUtlBuffer::CUtlBuffer(this: &buf, growSize: 0, initSize: 0, nFlags: 1);
  if ( g_pFileSystem->ReadFile(
         this: &g_pFileSystem->IBaseFileSystem,
         a2: name,
         a3: nullptr,
         a4: &buf,
         a5: 0,
         a6: 0,
         a7: nullptr) )
  {
    ConMsg(a1: "Reading %s...\n", name);
    v1 = 0;
    while ( CUtlBuffer::Scanf(this: &buf, pFmt: "%f %f %f\n", &org, &org.y, &org.z) == 3 )
    {
      m_Size = g_Points.m_Size;
      ++v1;
      v3 = g_Points.m_Size;
      if ( g_Points.m_Size + 1 > g_Points.m_Memory.m_nAllocationCount )
      {
        CUtlMemory<UtlLinkedListElem_t<vgui::TreeNode *,int>,int>::Grow(
          this: (CUtlMemory<CVTFTexture::ResourceMemorySection,int> *)&g_Points,
          num: g_Points.m_Size - g_Points.m_Memory.m_nAllocationCount + 1);
        m_Size = g_Points.m_Size;
      }
      v4 = g_Points.m_Memory.m_pMemory;
      g_Points.m_Size = m_Size + 1;
      v5 = m_Size - v3;
      g_Points.m_pElements = g_Points.m_Memory.m_pMemory;
      if ( v5 > 0 )
      {
        _V_memmove(dest: &g_Points.m_Memory.m_pMemory[v3 + 1], src: &g_Points.m_Memory.m_pMemory[v3], count: 12 * v5);
        v4 = g_Points.m_Memory.m_pMemory;
      }
      v6 = &v4[v3];
      if ( v6 != nullptr )
        *v6 = org;
    }
    ConMsg(a1: "%i lines read\n", v1);
  }
  else
  {
    ConMsg(a1: "couldn't open %s\n", name);
  }
  if ( buf.m_Memory.m_nGrowSize >= 0 && buf.m_Memory.m_pMemory != nullptr )
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: buf.m_Memory.m_pMemory);
}

//------------------------------------------------------------------------------
// Address: 0x10314CE0
// Name: _dynamic_initializer_for__linefile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
int dynamic_initializer_for__linefile__()
{
  ConCommand::ConCommand(
    this: &linefile,
    pName: &args.m_pArgSBuffer[88],
    callback: Linefile_Read_f,
    pHelpString: &args.m_pArgSBuffer[100],
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__linefile__);
}

//------------------------------------------------------------------------------
// Address: 0x10323230
// Name: _dynamic_atexit_destructor_for__linefile__
// Source: semantic_dyn_file_match
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__linefile__()
{
  ConCommand::~ConCommand(this: &linefile);
}

} // namespace engine_xlsp
