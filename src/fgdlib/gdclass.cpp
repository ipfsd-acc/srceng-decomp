// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: fgdlib/gdclass.cpp
// Functions: 22
// ============================================================

#include "fgdlib\gdclass.h"

//------------------------------------------------------------------------------
// Address: 0x100B99E0
// Name: public: class CClassOutput __near * GDclass::GetOutput(int)
// Source: json
//------------------------------------------------------------------------------
CClassOutput *__thiscall GDclass::GetOutput(GDclass *this, int nIndex)
{
  return this->m_Outputs.m_Memory.m_pMemory[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101F5930
// Name: public: int GDclass::GetBoundBox(class Vector __near &,class Vector __near &)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDclass::GetBoundBox(GDclass *this, Vector *pfMins, Vector *pfMaxs)
{
  if ( this->m_bGotSize )
  {
    *pfMins = this->m_bmins;
    *pfMaxs = this->m_bmaxs;
  }
  return this->m_bGotSize;
}

//------------------------------------------------------------------------------
// Address: 0x101F5980
// Name: private: bool GDclass::ParseColor(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseColor(GDclass *this, TokenReader *tr)
{
  bool result; // al
  unsigned __int8 v5; // bl
  unsigned __int8 v6; // al
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF
  unsigned __int8 r_3; // [esp+97h] [ebp+Bh]

  if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    return false;
  r_3 = atoi(nptr: szToken);
  if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    return false;
  v5 = atoi(nptr: szToken);
  result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr);
  if ( result )
  {
    v6 = atoi(nptr: szToken);
    this->m_rgbColor.r = r_3;
    this->m_rgbColor.g = v5;
    this->m_rgbColor.b = v6;
    this->m_rgbColor.a = 0;
    this->m_bGotColor = true;
    return GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")");
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F5A70
// Name: private: bool GDclass::ParseSize(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseSize(GDclass *this, TokenReader *tr)
{
  int v2; // esi
  Vector *p_m_bmins; // edi
  int v4; // esi
  float *p_x; // edi
  GDclass *v6; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  GDclass *v12; // [esp+90h] [ebp-4h]

  v12 = this;
  v2 = 0;
  p_m_bmins = &this->m_bmins;
  do
  {
    if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
      return false;
    p_m_bmins->x = atof(nptr: szToken);
    ++v2;
    p_m_bmins = (Vector *)((char *)p_m_bmins + 4);
  }
  while ( v2 < 3 );
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) == OPERATOR
    && _V_stricmp(s1: szToken, s2: ",") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
    v4 = 0;
    p_x = &v12->m_bmaxs.x;
    while ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    {
      *p_x = atof(nptr: szToken);
      ++v4;
      ++p_x;
      if ( v4 >= 3 )
      {
        v6 = v12;
        goto LABEL_12;
      }
    }
    return false;
  }
  v8 = v12->m_bmins.x * 0.5;
  v6 = v12;
  v12->m_bmaxs.x = v8;
  v6->m_bmins.x = -v8;
  v9 = v6->m_bmins.y * 0.5;
  v6->m_bmaxs.y = v9;
  v6->m_bmins.y = -v9;
  v10 = v6->m_bmins.z * 0.5;
  v6->m_bmaxs.z = v10;
  v6->m_bmins.z = -v10;
LABEL_12:
  v6->m_bGotSize = true;
  return GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")");
}

//------------------------------------------------------------------------------
// Address: 0x101F5C10
// Name: protected: bool GDclass::ParseInputOutput(class TokenReader __near &,class CClassInputOutputBase __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseInputOutput(GDclass *this, TokenReader *tr, CClassInputOutputBase *pInputOutput)
{
  TokenReader *v3; // esi
  bool result; // al
  CClassInputOutputBase *v5; // edi
  char *v6; // eax
  int v7; // edx
  char v8; // cl
  char szToken[132]; // [esp+4h] [ebp-84h] BYREF

  v3 = tr;
  result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr);
  if ( result )
  {
    v5 = pInputOutput;
    v6 = szToken;
    v7 = pInputOutput->m_szName - szToken;
    do
    {
      v8 = *v6;
      v6[v7] = *v6;
      ++v6;
    }
    while ( v8 != 0 );
    if ( !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: "(")
      || !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr) )
    {
      return false;
    }
    if ( CClassInputOutputBase::SetType(this: v5, szType: szToken) == iotInvalid )
    {
      GDError(tr: v3, error: "bad input/output type '%s'", szToken);
      return false;
    }
    if ( !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")") )
      return false;
    if ( TokenReader::PeekTokenType(this: v3, pszStore: szToken, maxlen: 129) == OPERATOR
      && _V_stricmp(s1: szToken, s2: ":") == 0 )
    {
      TokenReader::NextToken(this: v3, pszStore: szToken, nSize: 129);
      if ( !GDGetTokenDynamic(tr: v3, ppszStore: (char **)&tr, ttexpecting: STRING, pszExpecting: nullptr) )
        return false;
      v5->m_pszDescription = (char *)tr;
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101F5D60
// Name: public: class CHelperInfo __near * GDclass::GetHelper(int)
// Source: json
//------------------------------------------------------------------------------
CHelperInfo *__thiscall GDclass::GetHelper(GDclass *this, int nIndex)
{
  return this->m_Helpers.m_Memory.m_pMemory[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101F5D80
// Name: public: class CClassInput __near * GDclass::GetInput(int)
// Source: json
//------------------------------------------------------------------------------
CClassInput *__thiscall GDclass::GetInput(GDclass *this, int nIndex)
{
  return this->m_Inputs.m_Memory.m_pMemory[nIndex];
}

//------------------------------------------------------------------------------
// Address: 0x101F5DA0
// Name: public: class GDinputvariable __near * GDclass::GetVariableAt(int)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDclass::GetVariableAt(GDclass *this, int iIndex)
{
  int v2; // eax
  __int16 v3; // dx
  GDclass *v4; // edx

  v2 = iIndex;
  if ( iIndex >= 0 )
  {
    while ( v2 < this->m_nVariables )
    {
      v3 = this->m_VariableMap[v2][0];
      if ( v3 == -1 )
        return this->m_Variables.m_Memory.m_pMemory[this->m_VariableMap[v2][1]];
      if ( v3 < this->Parent->m_Classes.m_Size )
        v4 = this->Parent->m_Classes.m_Memory.m_pMemory[v3];
      else
        v4 = nullptr;
      v2 = this->m_VariableMap[v2][1];
      this = v4;
      if ( v2 < 0 )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x101F5E00
// Name: public: class GDinputvariable __near * GDclass::VarForName(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDclass::VarForName(GDclass *this, const char *pszName, int *piIndex)
{
  int m_nVariables; // eax
  int v5; // ecx
  __int16 *j; // ebx
  __int16 v7; // ax
  GDinputvariable *v8; // esi
  int i; // [esp+Ch] [ebp-4h]

  m_nVariables = this->m_nVariables;
  v5 = 0;
  i = 0;
  if ( m_nVariables <= 0 )
    return nullptr;
  for ( j = &this->m_VariableMap[0][1]; ; j += 2 )
  {
    if ( v5 < 0 || v5 >= m_nVariables )
    {
      v8 = nullptr;
    }
    else
    {
      v7 = *(j - 1);
      if ( v7 == -1 )
        v8 = this->m_Variables.m_Memory.m_pMemory[*j];
      else
        v8 = v7 < this->Parent->m_Classes.m_Size
           ? GDclass::GetVariableAt(this: this->Parent->m_Classes.m_Memory.m_pMemory[v7], iIndex: *j)
           : GDclass::GetVariableAt(this: nullptr, iIndex: *j);
    }
    if ( _V_stricmp(s1: v8->m_szName, s2: pszName) == 0 )
      break;
    m_nVariables = this->m_nVariables;
    if ( ++i >= m_nVariables )
      return nullptr;
    v5 = i;
  }
  if ( piIndex != nullptr )
    *piIndex = i;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x101F5EC0
// Name: public: class CClassInput __near * GDclass::FindInput(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClassInput *__thiscall GDclass::FindInput(GDclass *this, const char *szName)
{
  int v3; // esi
  CClassInput *v4; // edi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Inputs.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_Inputs.m_Memory.m_pMemory[v3];
    if ( _V_stricmp(s1: v4->m_szName, s2: szName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101F5F20
// Name: public: class CClassOutput __near * GDclass::FindOutput(char const __near *)
// Source: json
//------------------------------------------------------------------------------
CClassOutput *__thiscall GDclass::FindOutput(GDclass *this, const char *szName)
{
  int v3; // esi
  CClassOutput *v4; // edi
  int nCount; // [esp+Ch] [ebp-4h]

  v3 = 0;
  nCount = this->m_Outputs.m_Size;
  if ( nCount <= 0 )
    return nullptr;
  while ( 1 )
  {
    v4 = this->m_Outputs.m_Memory.m_pMemory[v3];
    if ( _V_stricmp(s1: v4->m_szName, s2: szName) == 0 )
      break;
    if ( ++v3 >= nCount )
      return nullptr;
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x101F5F80
// Name: public: GDclass::GDclass(void)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GDclass::GDclass(GDclass *this)
{
  this->m_Variables.m_Memory.m_pMemory = nullptr;
  this->m_Variables.m_Memory.m_nAllocationCount = 0;
  this->m_Variables.m_Memory.m_nGrowSize = 0;
  this->m_Variables.m_Size = 0;
  this->m_Variables.m_pElements = nullptr;
  this->m_Bases.m_Memory.m_pMemory = nullptr;
  this->m_Bases.m_Memory.m_nAllocationCount = 0;
  this->m_Bases.m_Memory.m_nGrowSize = 0;
  this->m_Bases.m_Size = 0;
  this->m_Bases.m_pElements = nullptr;
  this->m_Inputs.m_Memory.m_pMemory = nullptr;
  this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  this->m_Inputs.m_Memory.m_nGrowSize = 0;
  this->m_Inputs.m_Size = 0;
  this->m_Inputs.m_pElements = nullptr;
  this->m_Outputs.m_Memory.m_pMemory = nullptr;
  this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  this->m_Outputs.m_Memory.m_nGrowSize = 0;
  this->m_Outputs.m_Size = 0;
  this->m_Outputs.m_pElements = nullptr;
  this->m_Helpers.m_Memory.m_pMemory = nullptr;
  this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  this->m_Helpers.m_Memory.m_nGrowSize = 0;
  this->m_Helpers.m_Size = 0;
  this->m_Helpers.m_pElements = nullptr;
  this->m_nVariables = 0;
  *(_DWORD *)&this->m_bBase = 0;
  *(_DWORD *)&this->m_bKeyFrame = 0;
  *(_WORD *)&this->m_bHalfGridSnap = 0;
  this->m_bGotColor = false;
  this->m_rgbColor = (color32_s)14425820;
  this->m_pszDescription = nullptr;
  this->m_bmins.x = -8.0;
  this->m_bmaxs.x = 8.0;
  this->m_bmins.y = -8.0;
  this->m_bmaxs.y = 8.0;
  this->m_bmins.z = -8.0;
  this->m_bmaxs.z = 8.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x101F6060
// Name: public: void GDclass::AddInput(class CClassInput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddInput(GDclass *this, CClassInput *pInput)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Inputs; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  if ( pInput != nullptr )
  {
    m_nAllocationCount = this->m_Inputs.m_Memory.m_nAllocationCount;
    p_m_Inputs = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Inputs;
    m_Size = this->m_Inputs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Inputs, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Inputs[1].m_pMemory;
    m_pMemory = p_m_Inputs->m_pMemory;
    v6 = (int)p_m_Inputs[1].m_pMemory - m_Size - 1;
    p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_Inputs->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (vgui::TreeNode *)pInput;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F60D0
// Name: public: void GDclass::AddOutput(class CClassOutput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddOutput(GDclass *this, CClassOutput *pOutput)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Outputs; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  if ( pOutput != nullptr )
  {
    m_nAllocationCount = this->m_Outputs.m_Memory.m_nAllocationCount;
    p_m_Outputs = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Outputs;
    m_Size = this->m_Outputs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Outputs, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Outputs[1].m_pMemory;
    m_pMemory = p_m_Outputs->m_pMemory;
    v6 = (int)p_m_Outputs[1].m_pMemory - m_Size - 1;
    p_m_Outputs[1].m_nAllocationCount = (int)p_m_Outputs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_Outputs->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (vgui::TreeNode *)pOutput;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6140
// Name: public: GDclass::~GDclass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::~GDclass(GDclass *this)
{
  int m_Size; // eax
  int v3; // edi
  GDinputvariable *v4; // ecx
  int v5; // eax
  int v6; // edi
  CHelperInfo *v7; // ecx
  int v8; // eax
  int v9; // edi
  CClassInput *v10; // ecx
  int v11; // eax
  int v12; // edi
  CClassOutput *v13; // ecx
  CHelperInfo **m_pMemory; // eax
  CClassOutput **v15; // eax
  CClassInput **v16; // eax
  GDclass **v17; // eax
  GDinputvariable **v18; // eax
  GDinputvariable *p; // [esp+Ch] [ebp-8h]
  CHelperInfo *pa; // [esp+Ch] [ebp-8h]
  int nCount; // [esp+10h] [ebp-4h]
  int nCounta; // [esp+10h] [ebp-4h]
  int nCountb; // [esp+10h] [ebp-4h]
  int nCountc; // [esp+10h] [ebp-4h]

  m_Size = this->m_Variables.m_Size;
  v3 = 0;
  for ( nCount = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = this->m_Variables.m_Memory.m_pMemory[v3];
    p = v4;
    if ( v4 != nullptr )
    {
      GDinputvariable::~GDinputvariable(this: v4);
      operator delete(p);
      m_Size = nCount;
    }
  }
  this->m_Variables.m_Size = 0;
  v5 = this->m_Helpers.m_Size;
  v6 = 0;
  for ( nCounta = v5; v6 < v5; ++v6 )
  {
    v7 = this->m_Helpers.m_Memory.m_pMemory[v6];
    pa = v7;
    if ( v7 != nullptr )
    {
      CHelperInfo::~CHelperInfo(this: v7);
      operator delete(p: pa);
      v5 = nCounta;
    }
  }
  this->m_Helpers.m_Size = 0;
  v8 = this->m_Inputs.m_Size;
  v9 = 0;
  for ( nCountb = v8; v9 < v8; ++v9 )
  {
    v10 = this->m_Inputs.m_Memory.m_pMemory[v9];
    if ( v10 != nullptr )
    {
      ((void (__thiscall *)(CClassInput *, int))v10->dtr_CClassInputOutputBase)(a1: v10, a2: 1);
      v8 = nCountb;
    }
  }
  this->m_Inputs.m_Size = 0;
  v11 = this->m_Outputs.m_Size;
  v12 = 0;
  for ( nCountc = v11; v12 < v11; ++v12 )
  {
    v13 = this->m_Outputs.m_Memory.m_pMemory[v12];
    if ( v13 != nullptr )
    {
      ((void (__thiscall *)(CClassOutput *, int))v13->dtr_CClassInputOutputBase)(a1: v13, a2: 1);
      v11 = nCountc;
    }
  }
  this->m_Outputs.m_Size = 0;
  operator delete(p: this->m_pszDescription);
  this->m_Helpers.m_Size = 0;
  if ( this->m_Helpers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Helpers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Helpers.m_Memory.m_pMemory);
      this->m_Helpers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Helpers.m_Memory.m_pMemory;
  this->m_Helpers.m_pElements = m_pMemory;
  if ( this->m_Helpers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Helpers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Outputs.m_Size = 0;
  if ( this->m_Outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Outputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Outputs.m_Memory.m_pMemory);
      this->m_Outputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  }
  v15 = this->m_Outputs.m_Memory.m_pMemory;
  this->m_Outputs.m_pElements = v15;
  if ( this->m_Outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      this->m_Outputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Inputs.m_Size = 0;
  if ( this->m_Inputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Inputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Inputs.m_Memory.m_pMemory);
      this->m_Inputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  }
  v16 = this->m_Inputs.m_Memory.m_pMemory;
  this->m_Inputs.m_pElements = v16;
  if ( this->m_Inputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      this->m_Inputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Bases.m_Size = 0;
  if ( this->m_Bases.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Bases.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Bases.m_Memory.m_pMemory);
      this->m_Bases.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bases.m_Memory.m_nAllocationCount = 0;
  }
  v17 = this->m_Bases.m_Memory.m_pMemory;
  this->m_Bases.m_pElements = v17;
  if ( this->m_Bases.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v17 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
      this->m_Bases.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bases.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Variables.m_Size = 0;
  if ( this->m_Variables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Variables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Variables.m_Memory.m_pMemory);
      this->m_Variables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Variables.m_Memory.m_nAllocationCount = 0;
  }
  v18 = this->m_Variables.m_Memory.m_pMemory;
  this->m_Variables.m_pElements = v18;
  if ( this->m_Variables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v18 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
      this->m_Variables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Variables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6420
// Name: public: int GDclass::AddVariable(class GDinputvariable __near *,class GDclass __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDclass::AddVariable(
        GDclass *this,
        GDinputvariable *pVar,
        GDclass *pBase,
        int iBaseIndex,
        __int16 iVarIndex)
{
  GDinputvariable *v6; // esi
  GDIV_TYPE m_eType; // eax
  GDinputvariable *v9; // eax
  GDinputvariable *v10; // esi
  int v11; // edx
  int v12; // edi
  int m_Size; // edx
  int v14; // eax
  GDinputvariable **m_pMemory; // ecx
  int v16; // edi
  int m_nAllocationCount; // eax
  GDinputvariable **v18; // ecx
  int v19; // eax
  GDinputvariable **v20; // edi
  int v21; // edi
  int v22; // eax
  GDinputvariable **v23; // ecx
  int v24; // eax
  GDinputvariable **v25; // edi
  int m_nVariables; // eax
  GDinputvariable *pThisVar; // [esp+Ch] [ebp-Ch]
  GDinputvariable *pAddVar; // [esp+10h] [ebp-8h]
  int iThisIndex; // [esp+14h] [ebp-4h] BYREF
  unsigned __int8 bReturn_3; // [esp+23h] [ebp+Bh]

  v6 = GDclass::VarForName(this, pszName: pVar->m_szName, piIndex: &iThisIndex);
  pThisVar = v6;
  if ( v6 != nullptr )
  {
    m_eType = pVar->m_eType;
    if ( v6->m_eType != m_eType )
      return 0;
    if ( m_eType == ivFlags || m_eType == ivChoices )
    {
      v9 = (GDinputvariable *)operator new(nSize: 0x1F0u);
      if ( v9 != nullptr )
        v10 = GDinputvariable::GDinputvariable(this: v9);
      else
        v10 = nullptr;
      GDinputvariable::operator=(this: v10, Other: pVar);
      GDinputvariable::Merge(this: v10, Other: pThisVar);
      pAddVar = v10;
      v6 = pThisVar;
      bReturn_3 = 0;
    }
    else
    {
      pAddVar = pVar;
      bReturn_3 = 1;
    }
    v11 = iThisIndex;
    v12 = -1;
    if ( this->m_VariableMap[iThisIndex][0] == -1 )
    {
      m_Size = this->m_Variables.m_Size;
      v14 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_Variables.m_Memory.m_pMemory;
        while ( *m_pMemory != v6 )
        {
          ++v14;
          ++m_pMemory;
          if ( v14 >= m_Size )
            goto LABEL_18;
        }
        v12 = v14;
      }
LABEL_18:
      GDinputvariable::~GDinputvariable(this: v6);
      operator delete(p: v6);
      this->m_Variables.m_Memory.m_pMemory[v12] = pAddVar;
      return bReturn_3;
    }
    else
    {
      this->m_VariableMap[iThisIndex][0] = iBaseIndex;
      if ( iBaseIndex == -1 )
      {
        v16 = this->m_Variables.m_Size;
        m_nAllocationCount = this->m_Variables.m_Memory.m_nAllocationCount;
        if ( v16 + 1 > m_nAllocationCount )
        {
          CUtlMemory<CVisGroup *,int>::Grow(
            this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_Variables,
            num: v16 - m_nAllocationCount + 1);
          v11 = iThisIndex;
        }
        ++this->m_Variables.m_Size;
        v18 = this->m_Variables.m_Memory.m_pMemory;
        v19 = this->m_Variables.m_Size - v16 - 1;
        this->m_Variables.m_pElements = v18;
        if ( v19 > 0 )
        {
          _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
          v11 = iThisIndex;
        }
        v20 = &this->m_Variables.m_Memory.m_pMemory[v16];
        if ( v20 != nullptr )
          *v20 = pAddVar;
        this->m_VariableMap[v11][1] = LOWORD(this->m_Variables.m_Size) - 1;
        return bReturn_3;
      }
      else
      {
        this->m_VariableMap[v11][1] = iVarIndex;
        return bReturn_3;
      }
    }
  }
  else
  {
    if ( iBaseIndex == -1 )
    {
      v21 = this->m_Variables.m_Size;
      v22 = this->m_Variables.m_Memory.m_nAllocationCount;
      if ( v21 + 1 > v22 )
        CUtlMemory<CVisGroup *,int>::Grow(
          this: (CUtlMemory<CCullTreeNode *,int> *)&this->m_Variables,
          num: v21 - v22 + 1);
      ++this->m_Variables.m_Size;
      v23 = this->m_Variables.m_Memory.m_pMemory;
      v24 = this->m_Variables.m_Size - v21 - 1;
      this->m_Variables.m_pElements = v23;
      if ( v24 > 0 )
        _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 4 * v24);
      v25 = &this->m_Variables.m_Memory.m_pMemory[v21];
      if ( v25 != nullptr )
        *v25 = pVar;
    }
    m_nVariables = this->m_nVariables;
    if ( m_nVariables == 128 )
      return 0;
    this->m_VariableMap[m_nVariables][0] = iBaseIndex;
    this->m_VariableMap[this->m_nVariables++][1] = iVarIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6640
// Name: private: bool GDclass::ParseHelper(class TokenReader __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseHelper(GDclass *this, TokenReader *tr, char *pszHelperName)
{
  CHelperInfo *v3; // eax
  CHelperInfo *v4; // ebx
  CHelperInfo *v5; // eax
  char v6; // cl
  trtoken_t v7; // eax
  GDclass *v9; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHelperInfo **m_pMemory; // ecx
  int v13; // eax
  CHelperInfo **v14; // eax
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  GDclass *v16; // [esp+90h] [ebp-4h]

  v16 = this;
  v3 = (CHelperInfo *)operator new(nSize: 0x114u);
  if ( v3 != nullptr )
  {
    v3->m_Parameters.m_Memory.m_pMemory = nullptr;
    v3->m_Parameters.m_Memory.m_nAllocationCount = 0;
    v3->m_Parameters.m_Memory.m_nGrowSize = 0;
    v3->m_Parameters.m_Size = 0;
    v3->m_Parameters.m_pElements = nullptr;
    v3->m_szName[0] = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  if ( pszHelperName != nullptr )
  {
    v5 = v4;
    do
    {
      v6 = v5->m_szName[pszHelperName - (char *)v4];
      v5->m_szName[0] = v6;
      v5 = (CHelperInfo *)((char *)v5 + 1);
    }
    while ( v6 != 0 );
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129);
      if ( v7 == OPERATOR )
        break;
      if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: v7, pszExpecting: nullptr) )
      {
LABEL_11:
        if ( v4 != nullptr )
        {
          CHelperInfo::~CHelperInfo(this: v4);
          operator delete(p: v4);
        }
        return 0;
      }
      CHelperInfo::AddParameter(this: v4, pszParameter: szToken);
    }
    if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: nullptr) )
      goto LABEL_11;
    if ( _V_stricmp(s1: szToken, s2: ")") == 0 )
      break;
    if ( _V_stricmp(s1: szToken, s2: "=") == 0 )
      goto LABEL_11;
  }
  v9 = v16;
  m_Size = v16->m_Helpers.m_Size;
  m_nAllocationCount = v16->m_Helpers.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<IDmFormatUpdater *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v16->m_Helpers,
      num: m_Size - m_nAllocationCount + 1);
  ++v9->m_Helpers.m_Size;
  m_pMemory = v9->m_Helpers.m_Memory.m_pMemory;
  v13 = v9->m_Helpers.m_Size - m_Size - 1;
  v9->m_Helpers.m_pElements = m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
  v14 = &v9->m_Helpers.m_Memory.m_pMemory[m_Size];
  if ( v14 != nullptr )
    *v14 = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x101F67C0
// Name: private: bool GDclass::ParseVariables(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseVariables(GDclass *this, TokenReader *tr)
{
  TokenReader *v2; // edi
  CClassInput *v4; // eax
  CClassInput *v5; // esi
  CClassOutput *v6; // eax
  GDinputvariable *v7; // eax
  GDinputvariable *v8; // esi
  GDinputvariable *v9; // eax
  char szError[260]; // [esp+Ch] [ebp-210h] BYREF
  char pszStore[132]; // [esp+110h] [ebp-10Ch] BYREF
  char szToken[132]; // [esp+194h] [ebp-88h] BYREF
  int nDupIndex; // [esp+218h] [ebp-4h] BYREF

  v2 = tr;
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) == OPERATOR )
    return 1;
  while ( _V_stricmp(s1: szToken, s2: "input") == 0 )
  {
    if ( !GDGetToken(tr: v2, pszStore, nSize: 129, ttexpecting: IDENT, pszExpecting: "input") )
      return 0;
    v4 = (CClassInput *)operator new(nSize: 0x10Cu);
    if ( v4 != nullptr )
      v5 = CClassInput::CClassInput(this: v4);
    else
      v5 = nullptr;
    if ( !GDclass::ParseInputOutput(this, tr: v2, pInputOutput: v5) )
      goto LABEL_31;
    GDclass::AddInput(this, pInput: v5);
LABEL_29:
    if ( TokenReader::PeekTokenType(this: v2, pszStore: szToken, maxlen: 129) == OPERATOR )
      return 1;
  }
  if ( _V_stricmp(s1: szToken, s2: "output") != 0 )
  {
    if ( _V_stricmp(s1: szToken, s2: "key") == 0 )
      GDGetToken(tr: v2, pszStore: szToken, nSize: 129, ttexpecting: TOKENNONE, pszExpecting: nullptr);
    v7 = (GDinputvariable *)operator new(nSize: 0x1F0u);
    if ( v7 != nullptr )
      v8 = GDinputvariable::GDinputvariable(this: v7);
    else
      v8 = nullptr;
    if ( GDinputvariable::InitFromTokens(this: v8, tr: v2) == 0 )
    {
      if ( v8 != nullptr )
      {
        GDinputvariable::~GDinputvariable(this: v8);
        operator delete(p: v8);
      }
      return 0;
    }
    v9 = GDclass::VarForName(this, pszName: v8->m_szName, piIndex: &nDupIndex);
    if ( v9 != nullptr && v9->m_eType != v8->m_eType )
    {
      sprintf(
        string: szError,
        format: "%s: Variable '%s' is multiply defined with different types.",
        this->m_szName,
        v8->m_szName);
      GDError(tr, error: szError);
    }
    if ( GDclass::AddVariable(this, pVar: v8, pBase: this, iBaseIndex: -1, iVarIndex: this->m_Variables.m_Size) == 0
      && v8 != nullptr )
    {
      GDinputvariable::~GDinputvariable(this: v8);
      operator delete(p: v8);
    }
    v2 = tr;
    goto LABEL_29;
  }
  if ( !GDGetToken(tr: v2, pszStore, nSize: 129, ttexpecting: IDENT, pszExpecting: "output") )
    return 0;
  v6 = (CClassOutput *)operator new(nSize: 0x10Cu);
  if ( v6 != nullptr )
    v5 = (CClassInput *)CClassOutput::CClassOutput(this: v6);
  else
    v5 = nullptr;
  if ( GDclass::ParseInputOutput(this, tr: v2, pInputOutput: v5) )
  {
    GDclass::AddOutput(this, pOutput: (CClassOutput *)v5);
    goto LABEL_29;
  }
LABEL_31:
  if ( v5 != nullptr )
  {
    ((void (__thiscall *)(CClassInput *, int))v5->dtr_CClassInputOutputBase)(a1: v5, a2: 1);
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6A10
// Name: private: bool GDclass::ParseBase(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseBase(GDclass *this, TokenReader *tr)
{
  GDclass *v2; // edi
  GDclass *v3; // ebx
  int i; // esi
  GDinputvariable *VariableAt; // eax
  CClassInput *v6; // eax
  CClassInput *v7; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Inputs; // esi
  int v10; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v12; // eax
  vgui::TreeNode **v13; // eax
  CClassInputOutputBase *v14; // edi
  CClassOutput *v15; // eax
  CClassOutput *v16; // esi
  GDclass *v17; // esi
  int v18; // edi
  int v19; // eax
  CClassOutput **v20; // ecx
  int v21; // eax
  int *v22; // eax
  bool result; // al
  int v24; // [esp-8h] [ebp-B0h]
  char szToken[132]; // [esp+Ch] [ebp-9Ch] BYREF
  int piIndex; // [esp+90h] [ebp-18h] BYREF
  CClassInputOutputBase *Other; // [esp+94h] [ebp-14h]
  int m_Size; // [esp+98h] [ebp-10h]
  GDclass *v29; // [esp+9Ch] [ebp-Ch]
  int j; // [esp+A0h] [ebp-8h]
  int v31; // [esp+A4h] [ebp-4h]

  v2 = this;
  v29 = this;
  if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr) )
  {
    while ( 1 )
    {
      v3 = GameData::ClassForName(this: v2->Parent, pszName: szToken, piIndex: nullptr);
      if ( v3 == nullptr )
      {
        GDError(tr, error: "undefined base class '%s", szToken);
        return false;
      }
      GameData::ClassForName(this: v2->Parent, pszName: v3->m_szName, &piIndex);
      for ( i = 0; i < v3->m_nVariables; ++i )
      {
        v24 = piIndex;
        VariableAt = GDclass::GetVariableAt(this: v3, iIndex: i);
        GDclass::AddVariable(this: v2, pVar: VariableAt, pBase: v3, iBaseIndex: v24, iVarIndex: i);
      }
      m_Size = v3->m_Inputs.m_Size;
      for ( j = 0; j < m_Size; ++j )
      {
        Other = v3->m_Inputs.m_Memory.m_pMemory[j];
        v6 = (CClassInput *)operator new(nSize: 0x10Cu);
        if ( v6 != nullptr )
        {
          v7 = CClassInput::CClassInput(this: v6);
          v31 = (int)v7;
        }
        else
        {
          v31 = 0;
          v7 = nullptr;
        }
        CClassInputOutputBase::operator=(this: v7, Other);
        if ( v7 != nullptr )
        {
          m_nAllocationCount = v2->m_Inputs.m_Memory.m_nAllocationCount;
          p_m_Inputs = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Inputs;
          v10 = v2->m_Inputs.m_Size;
          if ( v10 + 1 > m_nAllocationCount )
            CUtlMemory<IDmFormatUpdater *,int>::Grow(this: p_m_Inputs, num: v10 - m_nAllocationCount + 1);
          ++p_m_Inputs[1].m_pMemory;
          m_pMemory = p_m_Inputs->m_pMemory;
          v12 = (int)p_m_Inputs[1].m_pMemory - v10 - 1;
          p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * v12);
          v13 = &p_m_Inputs->m_pMemory[v10];
          v2 = v29;
          if ( v13 != nullptr )
            *v13 = (vgui::TreeNode *)v31;
        }
      }
      m_Size = v3->m_Outputs.m_Size;
      v31 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v14 = v3->m_Outputs.m_Memory.m_pMemory[v31];
          v15 = (CClassOutput *)operator new(nSize: 0x10Cu);
          if ( v15 != nullptr )
          {
            v16 = CClassOutput::CClassOutput(this: v15);
            j = (int)v16;
          }
          else
          {
            j = 0;
            v16 = nullptr;
          }
          CClassInputOutputBase::operator=(this: v16, Other: v14);
          if ( v16 != nullptr )
          {
            v17 = v29;
            v18 = v29->m_Outputs.m_Size;
            v19 = v29->m_Outputs.m_Memory.m_nAllocationCount;
            if ( v18 + 1 > v19 )
              CUtlMemory<IDmFormatUpdater *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v29->m_Outputs,
                num: v18 - v19 + 1);
            ++v17->m_Outputs.m_Size;
            v20 = v17->m_Outputs.m_Memory.m_pMemory;
            v21 = v17->m_Outputs.m_Size - v18 - 1;
            v17->m_Outputs.m_pElements = v20;
            if ( v21 > 0 )
              _V_memmove(dest: &v20[v18 + 1], src: &v20[v18], count: 4 * v21);
            v22 = (int *)&v17->m_Outputs.m_Memory.m_pMemory[v18];
            if ( v22 != nullptr )
              *v22 = j;
          }
          ++v31;
        }
        while ( v31 < m_Size );
        v2 = v29;
      }
      if ( !v2->m_bGotSize && v3->m_bGotSize )
      {
        v2->m_bmins.x = v3->m_bmins.x;
        v2->m_bmins.y = v3->m_bmins.y;
        v2->m_bmins.z = v3->m_bmins.z;
        v2->m_bmaxs.x = v3->m_bmaxs.x;
        v2->m_bmaxs.y = v3->m_bmaxs.y;
        v2->m_bmaxs.z = v3->m_bmaxs.z;
        if ( v3->m_bGotSize )
          v2->m_bGotSize = true;
      }
      if ( !v2->m_bGotColor )
      {
        v2->m_rgbColor = v3->m_rgbColor;
        v2->m_bGotColor = true;
      }
      if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: nullptr) )
        return false;
      if ( _V_stricmp(s1: szToken, s2: ")") == 0 )
        return true;
      if ( _V_stricmp(s1: szToken, s2: ",") != 0 )
        break;
      result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr);
      if ( !result )
        return result;
    }
    GDError(tr, error: "expecting ',' or ')', but found %s", szToken);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x101F6D80
// Name: private: bool GDclass::ParseSpecifiers(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseSpecifiers(GDclass *this, TokenReader *tr)
{
  char v3; // al
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF

  if ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) != IDENT )
    return 1;
  while ( 1 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
    if ( _V_stricmp(s1: szToken, s2: "halfgridsnap") != 0 )
      break;
    this->m_bHalfGridSnap = true;
LABEL_13:
    if ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) != IDENT )
      return 1;
  }
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "(") )
  {
    if ( _V_stricmp(s1: szToken, s2: "base") != 0 )
    {
      if ( _V_stricmp(s1: szToken, s2: "size") != 0 )
        v3 = _V_stricmp(s1: szToken, s2: "color") != 0
           ? GDclass::ParseHelper(this, tr, pszHelperName: szToken)
           : GDclass::ParseColor(this, tr);
      else
        v3 = GDclass::ParseSize(this, tr);
    }
    else
    {
      v3 = GDclass::ParseBase(this, tr);
    }
    if ( v3 != 0 )
      goto LABEL_13;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x101F6E90
// Name: public: void GDclass::GetHelperForGDVar(class GDinputvariable __near *,class CUtlVector<char const __near *,class CUtlMemory<char const __near *,int>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::GetHelperForGDVar(
        GDclass *this,
        CHelperInfo *pVar,
        CUtlMemory<CCullTreeNode *,int> *pszHelperName)
{
  int v3; // edx
  CHelperInfo *v5; // edi
  int v6; // ebx
  const char *v7; // eax
  int m_pMemory; // edi
  int m_nAllocationCount; // eax
  const char **v10; // ecx
  int v11; // eax
  const char **v12; // eax
  GDclass *v13; // [esp+0h] [ebp-Ch]
  char *pszName; // [esp+4h] [ebp-8h]
  int i; // [esp+8h] [ebp-4h]
  CHelperInfo *pHelper; // [esp+14h] [ebp+8h]
  int nParamCount; // [esp+18h] [ebp+Ch]

  v3 = 0;
  v13 = this;
  pszName = &pVar->m_szName[20];
  for ( i = 0; v3 < this->m_Helpers.m_Size; i = v3 )
  {
    v5 = this->m_Helpers.m_Memory.m_pMemory[v3];
    v6 = 0;
    pHelper = v5;
    nParamCount = v5->m_Parameters.m_Size;
    if ( nParamCount > 0 )
    {
      do
      {
        if ( v6 < v5->m_Parameters.m_Size )
          v7 = v5->m_Parameters.m_Memory.m_pMemory[v6];
        else
          v7 = nullptr;
        if ( _V_stricmp(s1: pszName, s2: v7) == 0 )
        {
          m_pMemory = (int)pszHelperName[1].m_pMemory;
          m_nAllocationCount = pszHelperName->m_nAllocationCount;
          if ( m_pMemory + 1 > m_nAllocationCount )
            CUtlMemory<CVisGroup *,int>::Grow(this: pszHelperName, num: m_pMemory - m_nAllocationCount + 1);
          ++pszHelperName[1].m_pMemory;
          v10 = (const char **)pszHelperName->m_pMemory;
          v11 = (int)pszHelperName[1].m_pMemory - m_pMemory - 1;
          pszHelperName[1].m_nAllocationCount = (int)pszHelperName->m_pMemory;
          if ( v11 > 0 )
            _V_memmove(dest: &v10[m_pMemory + 1], src: &v10[m_pMemory], count: 4 * v11);
          v12 = (const char **)&pszHelperName->m_pMemory[m_pMemory];
          v5 = pHelper;
          if ( v12 != nullptr )
            *v12 = (const char *)pHelper;
        }
        ++v6;
      }
      while ( v6 < nParamCount );
      this = v13;
      v3 = i;
    }
    ++v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101F6F80
// Name: public: int GDclass::InitFromTokens(class TokenReader __near &,class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDclass::InitFromTokens(GDclass *this, TokenReader *tr, GameData *pGD)
{
  __int16 *v4; // eax
  int i; // ecx
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF

  this->Parent = pGD;
  v4 = &this->m_VariableMap[0][1];
  for ( i = 128; i != 0; --i )
  {
    *(v4 - 1) = -1;
    *v4 = -1;
    v4 += 2;
  }
  if ( GDclass::ParseSpecifiers(this, tr) != 0
    && GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "=")
    && GDGetToken(tr, pszStore: this->m_szName, nSize: 65, ttexpecting: IDENT, pszExpecting: nullptr)
    && (TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) != OPERATOR
     || _V_stricmp(s1: szToken, s2: ":") != 0
     || (TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129),
         operator delete(p: this->m_pszDescription),
         this->m_pszDescription = nullptr,
         GDGetTokenDynamic(tr, ppszStore: &this->m_pszDescription, ttexpecting: STRING, pszExpecting: nullptr)))
    && GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "[")
    && GDclass::ParseVariables(this, tr) != 0 )
  {
    return GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "]");
  }
  else
  {
    return false;
  }
}

// ============================================================
// Overlay from missionchooser (Missing functions)
// ============================================================
namespace missionchooser {

//------------------------------------------------------------------------------
// Address: 0x100F99E0
// Name: private: bool GDclass::ParseColor(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseColor(GDclass *this, TokenReader *tr)
{
  char result; // al
  unsigned __int8 v5; // bl
  unsigned __int8 v6; // al
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF
  unsigned __int8 r_3; // [esp+97h] [ebp+Bh]

  if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
    return 0;
  r_3 = atoi(nptr: szToken);
  if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
    return 0;
  v5 = atoi(nptr: szToken);
  result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr);
  if ( result != 0 )
  {
    v6 = atoi(nptr: szToken);
    this->m_rgbColor.r = r_3;
    this->m_rgbColor.g = v5;
    this->m_rgbColor.b = v6;
    this->m_rgbColor.a = 0;
    this->m_bGotColor = true;
    return GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")") != 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F9AD0
// Name: private: bool GDclass::ParseSize(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseSize(GDclass *this, TokenReader *tr)
{
  int v2; // esi
  Vector *p_m_bmins; // edi
  int v4; // esi
  float *p_x; // edi
  GDclass *v6; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  GDclass *v12; // [esp+90h] [ebp-4h]

  v12 = this;
  v2 = 0;
  p_m_bmins = &this->m_bmins;
  do
  {
    if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) == 0 )
      return false;
    p_m_bmins->x = atof(nptr: szToken);
    ++v2;
    p_m_bmins = (Vector *)((char *)p_m_bmins + 4);
  }
  while ( v2 < 3 );
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) == OPERATOR
    && _V_stricmp(s1: szToken, s2: ",") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
    v4 = 0;
    p_x = &v12->m_bmaxs.x;
    while ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) != 0 )
    {
      *p_x = atof(nptr: szToken);
      ++v4;
      ++p_x;
      if ( v4 >= 3 )
      {
        v6 = v12;
        goto LABEL_12;
      }
    }
    return false;
  }
  v8 = v12->m_bmins.x * 0.5;
  v6 = v12;
  v12->m_bmaxs.x = v8;
  v6->m_bmins.x = -v8;
  v9 = v6->m_bmins.y * 0.5;
  v6->m_bmaxs.y = v9;
  v6->m_bmins.y = -v9;
  v10 = v6->m_bmins.z * 0.5;
  v6->m_bmaxs.z = v10;
  v6->m_bmins.z = -v10;
LABEL_12:
  v6->m_bGotSize = true;
  return GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")") != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100F9C70
// Name: protected: bool GDclass::ParseInputOutput(class TokenReader __near &,class CClassInputOutputBase __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseInputOutput(GDclass *this, TokenReader *tr, CClassInputOutputBase *pInputOutput)
{
  TokenReader *v3; // esi
  char result; // al
  CClassInputOutputBase *v5; // edi
  char *v6; // eax
  int v7; // edx
  char v8; // cl
  char szToken[132]; // [esp+4h] [ebp-84h] BYREF

  v3 = tr;
  result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr);
  if ( result != 0 )
  {
    v5 = pInputOutput;
    v6 = szToken;
    v7 = pInputOutput->m_szName - szToken;
    do
    {
      v8 = *v6;
      v6[v7] = *v6;
      ++v6;
    }
    while ( v8 != 0 );
    if ( GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: "(") == 0
      || GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr) == 0 )
    {
      return 0;
    }
    if ( CClassInputOutputBase::SetType(this: v5, szType: szToken) == iotInvalid )
    {
      GDError(tr: v3, error: "bad input/output type '%s'", szToken);
      return 0;
    }
    if ( GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")") == 0 )
      return 0;
    if ( TokenReader::PeekTokenType(this: v3, pszStore: szToken, maxlen: 129) == OPERATOR
      && _V_stricmp(s1: szToken, s2: ":") == 0 )
    {
      TokenReader::NextToken(this: v3, pszStore: szToken, nSize: 129);
      if ( GDGetTokenDynamic(tr: v3, ppszStore: (char **)&tr, ttexpecting: STRING, pszExpecting: nullptr) == 0 )
        return 0;
      v5->m_pszDescription = (char *)tr;
    }
    return 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100F9DC0
// Name: public: class GDinputvariable __near * GDclass::GetVariableAt(int)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDclass::GetVariableAt(GDclass *this, int iIndex)
{
  int v2; // eax
  __int16 v3; // dx
  GDclass *v4; // edx

  v2 = iIndex;
  if ( iIndex >= 0 )
  {
    while ( v2 < this->m_nVariables )
    {
      v3 = this->m_VariableMap[v2][0];
      if ( v3 == -1 )
        return this->m_Variables.m_Memory.m_pMemory[this->m_VariableMap[v2][1]];
      if ( v3 < this->Parent->m_Classes.m_Size )
        v4 = this->Parent->m_Classes.m_Memory.m_pMemory[v3];
      else
        v4 = nullptr;
      v2 = this->m_VariableMap[v2][1];
      this = v4;
      if ( v2 < 0 )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100F9E20
// Name: public: class GDinputvariable __near * GDclass::VarForName(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDclass::VarForName(GDclass *this, const char *pszName, int *piIndex)
{
  int m_nVariables; // eax
  int v5; // ecx
  __int16 *j; // ebx
  __int16 v7; // ax
  GDinputvariable *v8; // esi
  int i; // [esp+Ch] [ebp-4h]

  m_nVariables = this->m_nVariables;
  v5 = 0;
  i = 0;
  if ( m_nVariables <= 0 )
    return nullptr;
  for ( j = &this->m_VariableMap[0][1]; ; j += 2 )
  {
    if ( v5 < 0 || v5 >= m_nVariables )
    {
      v8 = nullptr;
    }
    else
    {
      v7 = *(j - 1);
      if ( v7 == -1 )
        v8 = this->m_Variables.m_Memory.m_pMemory[*j];
      else
        v8 = v7 < this->Parent->m_Classes.m_Size
           ? GDclass::GetVariableAt(this: this->Parent->m_Classes.m_Memory.m_pMemory[v7], iIndex: *j)
           : GDclass::GetVariableAt(this: nullptr, iIndex: *j);
    }
    if ( _V_stricmp(s1: v8->m_szName, s2: pszName) == 0 )
      break;
    m_nVariables = this->m_nVariables;
    if ( ++i >= m_nVariables )
      return nullptr;
    v5 = i;
  }
  if ( piIndex != nullptr )
    *piIndex = i;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x100F9EE0
// Name: public: CHelperInfo::~CHelperInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHelperInfo::~CHelperInfo(CHelperInfo *this)
{
  int m_Size; // ebx
  int i; // edi
  char **m_pMemory; // eax

  m_Size = this->m_Parameters.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( this->m_Parameters.m_Memory.m_pMemory[i] != nullptr )
      free(pMem: this->m_Parameters.m_Memory.m_pMemory[i]);
  }
  this->m_Parameters.m_Size = 0;
  if ( this->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Parameters.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Parameters.m_Memory.m_pMemory);
      this->m_Parameters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Parameters.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Parameters.m_Memory.m_pMemory;
  this->m_Parameters.m_pElements = m_pMemory;
  if ( this->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Parameters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Parameters.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100F9F90
// Name: public: GDclass::GDclass(void)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GDclass::GDclass(GDclass *this)
{
  this->m_Variables.m_Memory.m_pMemory = nullptr;
  this->m_Variables.m_Memory.m_nAllocationCount = 0;
  this->m_Variables.m_Memory.m_nGrowSize = 0;
  this->m_Variables.m_Size = 0;
  this->m_Variables.m_pElements = nullptr;
  this->m_Bases.m_Memory.m_pMemory = nullptr;
  this->m_Bases.m_Memory.m_nAllocationCount = 0;
  this->m_Bases.m_Memory.m_nGrowSize = 0;
  this->m_Bases.m_Size = 0;
  this->m_Bases.m_pElements = nullptr;
  this->m_Inputs.m_Memory.m_pMemory = nullptr;
  this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  this->m_Inputs.m_Memory.m_nGrowSize = 0;
  this->m_Inputs.m_Size = 0;
  this->m_Inputs.m_pElements = nullptr;
  this->m_Outputs.m_Memory.m_pMemory = nullptr;
  this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  this->m_Outputs.m_Memory.m_nGrowSize = 0;
  this->m_Outputs.m_Size = 0;
  this->m_Outputs.m_pElements = nullptr;
  this->m_Helpers.m_Memory.m_pMemory = nullptr;
  this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  this->m_Helpers.m_Memory.m_nGrowSize = 0;
  this->m_Helpers.m_Size = 0;
  this->m_Helpers.m_pElements = nullptr;
  this->m_nVariables = 0;
  *(_DWORD *)&this->m_bBase = 0;
  *(_DWORD *)&this->m_bKeyFrame = 0;
  *(_WORD *)&this->m_bHalfGridSnap = 0;
  this->m_bGotColor = false;
  this->m_rgbColor = (color32_s)14425820;
  this->m_pszDescription = nullptr;
  this->m_bmins.x = -8.0;
  this->m_bmaxs.x = 8.0;
  this->m_bmins.y = -8.0;
  this->m_bmaxs.y = 8.0;
  this->m_bmins.z = -8.0;
  this->m_bmaxs.z = 8.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100FA070
// Name: public: bool CHelperInfo::AddParameter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHelperInfo::AddParameter(CHelperInfo *this, const char *pszParameter)
{
  int v3; // eax
  char *v4; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Parameters; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax

  if ( pszParameter == nullptr )
    return 0;
  if ( *pszParameter == 0 )
    return 0;
  v3 = strlen(pszParameter);
  if ( v3 <= 0 )
    return 0;
  v4 = (char *)operator new(nSize: v3 + 1);
  if ( v4 == nullptr )
    return 0;
  strcpy(v4, pszParameter);
  m_nAllocationCount = this->m_Parameters.m_Memory.m_nAllocationCount;
  p_m_Parameters = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Parameters;
  m_Size = this->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: p_m_Parameters,
      num: m_Size - m_nAllocationCount + 1);
  ++p_m_Parameters[1].m_pMemory;
  m_pMemory = p_m_Parameters->m_pMemory;
  v9 = (int)p_m_Parameters[1].m_pMemory - m_Size - 1;
  p_m_Parameters[1].m_nAllocationCount = (int)p_m_Parameters->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v9);
  v10 = (char **)&p_m_Parameters->m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA130
// Name: public: void GDclass::AddInput(class CClassInput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddInput(GDclass *this, vgui::TreeNode *pInput)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Inputs; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  if ( pInput != nullptr )
  {
    m_nAllocationCount = this->m_Inputs.m_Memory.m_nAllocationCount;
    p_m_Inputs = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Inputs;
    m_Size = this->m_Inputs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: p_m_Inputs,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_Inputs[1].m_pMemory;
    m_pMemory = p_m_Inputs->m_pMemory;
    v6 = (int)p_m_Inputs[1].m_pMemory - m_Size - 1;
    p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v7 = &p_m_Inputs->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = pInput;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA1A0
// Name: public: void GDclass::AddOutput(class CClassOutput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddOutput(GDclass *this, vgui::TreeNode *pOutput)
{
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Outputs; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v6; // eax
  vgui::TreeNode **v7; // eax

  if ( pOutput != nullptr )
  {
    m_nAllocationCount = this->m_Outputs.m_Memory.m_nAllocationCount;
    p_m_Outputs = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Outputs;
    m_Size = this->m_Outputs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
        this: p_m_Outputs,
        num: m_Size - m_nAllocationCount + 1);
    ++p_m_Outputs[1].m_pMemory;
    m_pMemory = p_m_Outputs->m_pMemory;
    v6 = (int)p_m_Outputs[1].m_pMemory - m_Size - 1;
    p_m_Outputs[1].m_nAllocationCount = (int)p_m_Outputs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v6);
    v7 = &p_m_Outputs->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = pOutput;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA210
// Name: public: GDclass::~GDclass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::~GDclass(GDclass *this)
{
  int m_Size; // eax
  int v3; // edi
  GDinputvariable *v4; // ecx
  int v5; // eax
  int v6; // edi
  CHelperInfo *v7; // ecx
  int v8; // eax
  int v9; // edi
  CClassInput *v10; // ecx
  int v11; // eax
  int v12; // edi
  CClassOutput *v13; // ecx
  CHelperInfo **m_pMemory; // eax
  CClassOutput **v15; // eax
  CClassInput **v16; // eax
  GDclass **v17; // eax
  GDinputvariable **v18; // eax
  GDinputvariable *pMem; // [esp+Ch] [ebp-8h]
  CHelperInfo *pMema; // [esp+Ch] [ebp-8h]
  int nCount; // [esp+10h] [ebp-4h]
  int nCounta; // [esp+10h] [ebp-4h]
  int nCountb; // [esp+10h] [ebp-4h]
  int nCountc; // [esp+10h] [ebp-4h]

  m_Size = this->m_Variables.m_Size;
  v3 = 0;
  for ( nCount = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = this->m_Variables.m_Memory.m_pMemory[v3];
    pMem = v4;
    if ( v4 != nullptr )
    {
      GDinputvariable::~GDinputvariable(this: v4);
      free(pMem);
      m_Size = nCount;
    }
  }
  this->m_Variables.m_Size = 0;
  v5 = this->m_Helpers.m_Size;
  v6 = 0;
  for ( nCounta = v5; v6 < v5; ++v6 )
  {
    v7 = this->m_Helpers.m_Memory.m_pMemory[v6];
    pMema = v7;
    if ( v7 != nullptr )
    {
      CHelperInfo::~CHelperInfo(this: v7);
      free(pMem: pMema);
      v5 = nCounta;
    }
  }
  this->m_Helpers.m_Size = 0;
  v8 = this->m_Inputs.m_Size;
  v9 = 0;
  for ( nCountb = v8; v9 < v8; ++v9 )
  {
    v10 = this->m_Inputs.m_Memory.m_pMemory[v9];
    if ( v10 != nullptr )
    {
      ((void (__thiscall *)(CClassInput *, int))v10->dtr_CClassInputOutputBase)(a1: v10, a2: 1);
      v8 = nCountb;
    }
  }
  this->m_Inputs.m_Size = 0;
  v11 = this->m_Outputs.m_Size;
  v12 = 0;
  for ( nCountc = v11; v12 < v11; ++v12 )
  {
    v13 = this->m_Outputs.m_Memory.m_pMemory[v12];
    if ( v13 != nullptr )
    {
      ((void (__thiscall *)(CClassOutput *, int))v13->dtr_CClassInputOutputBase)(a1: v13, a2: 1);
      v11 = nCountc;
    }
  }
  this->m_Outputs.m_Size = 0;
  free(pMem: this->m_pszDescription);
  this->m_Helpers.m_Size = 0;
  if ( this->m_Helpers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Helpers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Helpers.m_Memory.m_pMemory);
      this->m_Helpers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Helpers.m_Memory.m_pMemory;
  this->m_Helpers.m_pElements = m_pMemory;
  if ( this->m_Helpers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Helpers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Outputs.m_Size = 0;
  if ( this->m_Outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Outputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Outputs.m_Memory.m_pMemory);
      this->m_Outputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  }
  v15 = this->m_Outputs.m_Memory.m_pMemory;
  this->m_Outputs.m_pElements = v15;
  if ( this->m_Outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      this->m_Outputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Inputs.m_Size = 0;
  if ( this->m_Inputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Inputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Inputs.m_Memory.m_pMemory);
      this->m_Inputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  }
  v16 = this->m_Inputs.m_Memory.m_pMemory;
  this->m_Inputs.m_pElements = v16;
  if ( this->m_Inputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      this->m_Inputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Bases.m_Size = 0;
  if ( this->m_Bases.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Bases.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Bases.m_Memory.m_pMemory);
      this->m_Bases.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bases.m_Memory.m_nAllocationCount = 0;
  }
  v17 = this->m_Bases.m_Memory.m_pMemory;
  this->m_Bases.m_pElements = v17;
  if ( this->m_Bases.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v17 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
      this->m_Bases.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bases.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Variables.m_Size = 0;
  if ( this->m_Variables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Variables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Variables.m_Memory.m_pMemory);
      this->m_Variables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Variables.m_Memory.m_nAllocationCount = 0;
  }
  v18 = this->m_Variables.m_Memory.m_pMemory;
  this->m_Variables.m_pElements = v18;
  if ( this->m_Variables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v18 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
      this->m_Variables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Variables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA4F0
// Name: public: int GDclass::AddVariable(class GDinputvariable __near *,class GDclass __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDclass::AddVariable(
        GDclass *this,
        GDinputvariable *pVar,
        GDclass *pBase,
        int iBaseIndex,
        __int16 iVarIndex)
{
  GDinputvariable *v6; // esi
  GDIV_TYPE m_eType; // eax
  GDinputvariable *v9; // eax
  GDinputvariable *v10; // esi
  int v11; // edx
  int v12; // edi
  int m_Size; // edx
  int v14; // eax
  GDinputvariable **m_pMemory; // ecx
  int v16; // edi
  int m_nAllocationCount; // eax
  GDinputvariable **v18; // ecx
  int v19; // eax
  GDinputvariable **v20; // edi
  int v21; // edi
  int v22; // eax
  GDinputvariable **v23; // ecx
  int v24; // eax
  GDinputvariable **v25; // edi
  int m_nVariables; // eax
  GDinputvariable *pThisVar; // [esp+Ch] [ebp-Ch]
  GDinputvariable *pAddVar; // [esp+10h] [ebp-8h]
  int iThisIndex; // [esp+14h] [ebp-4h] BYREF
  unsigned __int8 bReturn_3; // [esp+23h] [ebp+Bh]

  v6 = GDclass::VarForName(this, pszName: pVar->m_szName, piIndex: &iThisIndex);
  pThisVar = v6;
  if ( v6 != nullptr )
  {
    m_eType = pVar->m_eType;
    if ( v6->m_eType != m_eType )
      return 0;
    if ( m_eType == ivFlags || m_eType == ivChoices )
    {
      v9 = (GDinputvariable *)operator new(nSize: 0x1F0u);
      if ( v9 != nullptr )
        v10 = GDinputvariable::GDinputvariable(this: v9);
      else
        v10 = nullptr;
      GDinputvariable::operator=(this: v10, Other: pVar);
      GDinputvariable::Merge(this: v10, Other: pThisVar);
      pAddVar = v10;
      v6 = pThisVar;
      bReturn_3 = 0;
    }
    else
    {
      pAddVar = pVar;
      bReturn_3 = 1;
    }
    v11 = iThisIndex;
    v12 = -1;
    if ( this->m_VariableMap[iThisIndex][0] == -1 )
    {
      m_Size = this->m_Variables.m_Size;
      v14 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_Variables.m_Memory.m_pMemory;
        while ( *m_pMemory != v6 )
        {
          ++v14;
          ++m_pMemory;
          if ( v14 >= m_Size )
            goto LABEL_18;
        }
        v12 = v14;
      }
LABEL_18:
      GDinputvariable::~GDinputvariable(this: v6);
      free(pMem: v6);
      this->m_Variables.m_Memory.m_pMemory[v12] = pAddVar;
      return bReturn_3;
    }
    else
    {
      this->m_VariableMap[iThisIndex][0] = iBaseIndex;
      if ( iBaseIndex == -1 )
      {
        v16 = this->m_Variables.m_Size;
        m_nAllocationCount = this->m_Variables.m_Memory.m_nAllocationCount;
        if ( v16 + 1 > m_nAllocationCount )
        {
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Variables,
            num: v16 - m_nAllocationCount + 1);
          v11 = iThisIndex;
        }
        ++this->m_Variables.m_Size;
        v18 = this->m_Variables.m_Memory.m_pMemory;
        v19 = this->m_Variables.m_Size - v16 - 1;
        this->m_Variables.m_pElements = v18;
        if ( v19 > 0 )
        {
          _V_memmove(dest: (unsigned __int8 *)&v18[v16 + 1], src: (unsigned __int8 *)&v18[v16], count: 4 * v19);
          v11 = iThisIndex;
        }
        v20 = &this->m_Variables.m_Memory.m_pMemory[v16];
        if ( v20 != nullptr )
          *v20 = pAddVar;
        this->m_VariableMap[v11][1] = LOWORD(this->m_Variables.m_Size) - 1;
        return bReturn_3;
      }
      else
      {
        this->m_VariableMap[v11][1] = iVarIndex;
        return bReturn_3;
      }
    }
  }
  else
  {
    if ( iBaseIndex == -1 )
    {
      v21 = this->m_Variables.m_Size;
      v22 = this->m_Variables.m_Memory.m_nAllocationCount;
      if ( v21 + 1 > v22 )
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_Variables,
          num: v21 - v22 + 1);
      ++this->m_Variables.m_Size;
      v23 = this->m_Variables.m_Memory.m_pMemory;
      v24 = this->m_Variables.m_Size - v21 - 1;
      this->m_Variables.m_pElements = v23;
      if ( v24 > 0 )
        _V_memmove(dest: (unsigned __int8 *)&v23[v21 + 1], src: (unsigned __int8 *)&v23[v21], count: 4 * v24);
      v25 = &this->m_Variables.m_Memory.m_pMemory[v21];
      if ( v25 != nullptr )
        *v25 = pVar;
    }
    m_nVariables = this->m_nVariables;
    if ( m_nVariables == 128 )
      return 0;
    this->m_VariableMap[m_nVariables][0] = iBaseIndex;
    this->m_VariableMap[this->m_nVariables++][1] = iVarIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FA710
// Name: private: bool GDclass::ParseHelper(class TokenReader __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseHelper(GDclass *this, TokenReader *tr, char *pszHelperName)
{
  CHelperInfo *v3; // eax
  CHelperInfo *v4; // ebx
  CHelperInfo *v5; // eax
  char v6; // cl
  trtoken_t v7; // eax
  GDclass *v9; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHelperInfo **m_pMemory; // ecx
  int v13; // eax
  CHelperInfo **v14; // eax
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  GDclass *v16; // [esp+90h] [ebp-4h]

  v16 = this;
  v3 = (CHelperInfo *)operator new(nSize: 0x114u);
  if ( v3 != nullptr )
  {
    v3->m_Parameters.m_Memory.m_pMemory = nullptr;
    v3->m_Parameters.m_Memory.m_nAllocationCount = 0;
    v3->m_Parameters.m_Memory.m_nGrowSize = 0;
    v3->m_Parameters.m_Size = 0;
    v3->m_Parameters.m_pElements = nullptr;
    v3->m_szName[0] = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  if ( pszHelperName != nullptr )
  {
    v5 = v4;
    do
    {
      v6 = v5->m_szName[pszHelperName - (char *)v4];
      v5->m_szName[0] = v6;
      v5 = (CHelperInfo *)((char *)v5 + 1);
    }
    while ( v6 != 0 );
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129);
      if ( v7 == OPERATOR )
        break;
      if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: v7, pszExpecting: nullptr) == 0 )
      {
LABEL_11:
        if ( v4 != nullptr )
        {
          CHelperInfo::~CHelperInfo(this: v4);
          free(pMem: v4);
        }
        return 0;
      }
      CHelperInfo::AddParameter(this: v4, pszParameter: szToken);
    }
    if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: nullptr) == 0 )
      goto LABEL_11;
    if ( _V_stricmp(s1: szToken, s2: ")") == 0 )
      break;
    if ( _V_stricmp(s1: szToken, s2: "=") == 0 )
      goto LABEL_11;
  }
  v9 = v16;
  m_Size = v16->m_Helpers.m_Size;
  m_nAllocationCount = v16->m_Helpers.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&v16->m_Helpers,
      num: m_Size - m_nAllocationCount + 1);
  ++v9->m_Helpers.m_Size;
  m_pMemory = v9->m_Helpers.m_Memory.m_pMemory;
  v13 = v9->m_Helpers.m_Size - m_Size - 1;
  v9->m_Helpers.m_pElements = m_pMemory;
  if ( v13 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v13);
  v14 = &v9->m_Helpers.m_Memory.m_pMemory[m_Size];
  if ( v14 != nullptr )
    *v14 = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100FA890
// Name: private: bool GDclass::ParseVariables(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseVariables(GDclass *this, TokenReader *tr)
{
  TokenReader *v2; // edi
  CClassInput *v4; // eax
  CClassInput *v5; // esi
  CClassOutput *v6; // eax
  GDinputvariable *v7; // eax
  GDinputvariable *v8; // esi
  GDinputvariable *v9; // eax
  char szError[260]; // [esp+Ch] [ebp-210h] BYREF
  char pszStore[132]; // [esp+110h] [ebp-10Ch] BYREF
  char szToken[132]; // [esp+194h] [ebp-88h] BYREF
  int nDupIndex; // [esp+218h] [ebp-4h] BYREF

  v2 = tr;
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) == OPERATOR )
    return 1;
  while ( _V_stricmp(s1: szToken, s2: "input") == 0 )
  {
    if ( GDGetToken(tr: v2, pszStore, nSize: 129, ttexpecting: IDENT, pszExpecting: "input") == 0 )
      return 0;
    v4 = (CClassInput *)operator new(nSize: 0x10Cu);
    if ( v4 != nullptr )
      v5 = CClassInput::CClassInput(this: v4);
    else
      v5 = nullptr;
    if ( GDclass::ParseInputOutput(this, tr: v2, pInputOutput: v5) == 0 )
      goto LABEL_31;
    GDclass::AddInput(this, pInput: (vgui::TreeNode *)v5);
LABEL_29:
    if ( TokenReader::PeekTokenType(this: v2, pszStore: szToken, maxlen: 129) == OPERATOR )
      return 1;
  }
  if ( _V_stricmp(s1: szToken, s2: "output") != 0 )
  {
    if ( _V_stricmp(s1: szToken, s2: "key") == 0 )
      GDGetToken(tr: v2, pszStore: szToken, nSize: 129, ttexpecting: TOKENNONE, pszExpecting: nullptr);
    v7 = (GDinputvariable *)operator new(nSize: 0x1F0u);
    if ( v7 != nullptr )
      v8 = GDinputvariable::GDinputvariable(this: v7);
    else
      v8 = nullptr;
    if ( GDinputvariable::InitFromTokens(this: v8, tr: v2) == 0 )
    {
      if ( v8 != nullptr )
      {
        GDinputvariable::~GDinputvariable(this: v8);
        free(pMem: v8);
      }
      return 0;
    }
    v9 = GDclass::VarForName(this, pszName: v8->m_szName, piIndex: &nDupIndex);
    if ( v9 != nullptr && v9->m_eType != v8->m_eType )
    {
      sprintf(
        string: szError,
        format: "%s: Variable '%s' is multiply defined with different types.",
        this->m_szName,
        v8->m_szName);
      GDError(tr, error: szError);
    }
    if ( GDclass::AddVariable(this, pVar: v8, pBase: this, iBaseIndex: -1, iVarIndex: this->m_Variables.m_Size) == 0
      && v8 != nullptr )
    {
      GDinputvariable::~GDinputvariable(this: v8);
      free(pMem: v8);
    }
    v2 = tr;
    goto LABEL_29;
  }
  if ( GDGetToken(tr: v2, pszStore, nSize: 129, ttexpecting: IDENT, pszExpecting: "output") == 0 )
    return 0;
  v6 = (CClassOutput *)operator new(nSize: 0x10Cu);
  if ( v6 != nullptr )
    v5 = (CClassInput *)CClassOutput::CClassOutput(this: v6);
  else
    v5 = nullptr;
  if ( GDclass::ParseInputOutput(this, tr: v2, pInputOutput: v5) != 0 )
  {
    GDclass::AddOutput(this, pOutput: (vgui::TreeNode *)v5);
    goto LABEL_29;
  }
LABEL_31:
  if ( v5 != nullptr )
  {
    ((void (__thiscall *)(CClassInput *, int))v5->dtr_CClassInputOutputBase)(a1: v5, a2: 1);
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FAAE0
// Name: public: void GDclass::AddBase(class GDclass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddBase(GDclass *this, CClassOutput *pBase)
{
  GDclass *v3; // edi
  GameData *Parent; // ecx
  int j; // esi
  GDinputvariable *VariableAt; // eax
  CClassInput *v7; // esi
  CClassInput *v8; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Inputs; // esi
  int m_Size; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v13; // eax
  CClassOutput **v14; // eax
  CClassOutput *v15; // esi
  CClassOutput *v16; // eax
  CClassOutput *v17; // edi
  GDclass *v18; // esi
  int v19; // edi
  int v20; // eax
  CClassOutput **v21; // ecx
  int v22; // eax
  CClassOutput **v23; // eax
  int v24; // [esp-8h] [ebp-24h]
  int iBaseIndex; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  GDclass *v28; // [esp+18h] [ebp-4h]
  CClassOutput *pNew; // [esp+24h] [ebp+8h]
  CClassOutput *pNewa; // [esp+24h] [ebp+8h]

  v3 = this;
  Parent = this->Parent;
  v28 = v3;
  GameData::ClassForName(this: Parent, pszName: &pBase->m_szName[15], piIndex: &iBaseIndex);
  for ( j = 0; j < *(_DWORD *)&pBase->m_szName[104]; ++j )
  {
    v24 = iBaseIndex;
    VariableAt = GDclass::GetVariableAt(this: (GDclass *)pBase, iIndex: j);
    GDclass::AddVariable(this: v3, pVar: VariableAt, (GDclass *)pBase, iBaseIndex: v24, iVarIndex: j);
  }
  nCount = *(_DWORD *)&pBase->m_szName[140];
  for ( i = 0; i < nCount; ++i )
  {
    v7 = *(CClassInput **)(*(_DWORD *)&pBase->m_szName[128] + 4 * i);
    v8 = (CClassInput *)operator new(nSize: 0x10Cu);
    if ( v8 != nullptr )
      pNew = (CClassOutput *)CClassInput::CClassInput(this: v8);
    else
      pNew = nullptr;
    CClassInputOutputBase::operator=(this: pNew, Other: v7);
    if ( pNew != nullptr )
    {
      m_nAllocationCount = v3->m_Inputs.m_Memory.m_nAllocationCount;
      p_m_Inputs = (CUtlMemory<vgui::TreeNode *,int> *)&v3->m_Inputs;
      m_Size = v3->m_Inputs.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
          this: p_m_Inputs,
          num: m_Size - m_nAllocationCount + 1);
      ++p_m_Inputs[1].m_pMemory;
      m_pMemory = p_m_Inputs->m_pMemory;
      v13 = (int)p_m_Inputs[1].m_pMemory - m_Size - 1;
      p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(
          dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
          src: (unsigned __int8 *)&m_pMemory[m_Size],
          count: 4 * v13);
      v14 = (CClassOutput **)&p_m_Inputs->m_pMemory[m_Size];
      v3 = v28;
      if ( v14 != nullptr )
        *v14 = pNew;
    }
  }
  nCount = *(_DWORD *)&pBase->m_szName[160];
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v15 = *(CClassOutput **)(*(_DWORD *)&pBase->m_szName[148] + 4 * i);
      v16 = (CClassOutput *)operator new(nSize: 0x10Cu);
      if ( v16 != nullptr )
      {
        v17 = CClassOutput::CClassOutput(this: v16);
        pNewa = v17;
      }
      else
      {
        pNewa = nullptr;
        v17 = nullptr;
      }
      CClassInputOutputBase::operator=(this: v17, Other: v15);
      if ( v17 != nullptr )
      {
        v18 = v28;
        v19 = v28->m_Outputs.m_Size;
        v20 = v28->m_Outputs.m_Memory.m_nAllocationCount;
        if ( v19 + 1 > v20 )
          CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&v28->m_Outputs,
            num: v19 - v20 + 1);
        ++v18->m_Outputs.m_Size;
        v21 = v18->m_Outputs.m_Memory.m_pMemory;
        v22 = v18->m_Outputs.m_Size - v19 - 1;
        v18->m_Outputs.m_pElements = v21;
        if ( v22 > 0 )
          _V_memmove(dest: (unsigned __int8 *)&v21[v19 + 1], src: (unsigned __int8 *)&v21[v19], count: 4 * v22);
        v23 = &v18->m_Outputs.m_Memory.m_pMemory[v19];
        if ( v23 != nullptr )
          *v23 = pNewa;
      }
      ++i;
    }
    while ( i < nCount );
    v3 = v28;
  }
  if ( !v3->m_bGotSize && pBase->m_szName[13] != 0 )
  {
    v3->m_bmins.x = *(float *)&pBase[2].m_szName[164];
    v3->m_bmins.y = *(float *)&pBase[2].m_szName[168];
    v3->m_bmins.z = *(float *)&pBase[2].m_szName[172];
    v3->m_bmaxs.x = *(float *)&pBase[2].m_szName[176];
    v3->m_bmaxs.y = *(float *)&pBase[2].m_szName[180];
    v3->m_bmaxs.z = *(float *)&pBase[2].m_szName[184];
    if ( pBase->m_szName[13] != 0 )
      v3->m_bGotSize = true;
  }
  if ( !v3->m_bGotColor )
  {
    v3->m_rgbColor = *(color32_s *)pBase->m_szName;
    v3->m_bGotColor = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100FAD50
// Name: private: bool GDclass::ParseBase(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseBase(GDclass *this, TokenReader *tr)
{
  GDclass *v2; // edi
  GDclass *v3; // ebx
  int i; // esi
  GDinputvariable *VariableAt; // eax
  CClassInput *v6; // eax
  CClassInput *v7; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<vgui::TreeNode *,int> *p_m_Inputs; // esi
  int v10; // edi
  vgui::TreeNode **m_pMemory; // ecx
  int v12; // eax
  vgui::TreeNode **v13; // eax
  CClassInputOutputBase *v14; // edi
  CClassOutput *v15; // eax
  CClassOutput *v16; // esi
  GDclass *v17; // esi
  int v18; // edi
  int v19; // eax
  CClassOutput **v20; // ecx
  int v21; // eax
  int *v22; // eax
  char result; // al
  int v24; // [esp-8h] [ebp-B0h]
  char szToken[132]; // [esp+Ch] [ebp-9Ch] BYREF
  int piIndex; // [esp+90h] [ebp-18h] BYREF
  CClassInputOutputBase *Other; // [esp+94h] [ebp-14h]
  int m_Size; // [esp+98h] [ebp-10h]
  GDclass *v29; // [esp+9Ch] [ebp-Ch]
  int j; // [esp+A0h] [ebp-8h]
  int v31; // [esp+A4h] [ebp-4h]

  v2 = this;
  v29 = this;
  if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr) != 0 )
  {
    while ( 1 )
    {
      v3 = GameData::ClassForName(this: v2->Parent, pszName: szToken, piIndex: nullptr);
      if ( v3 == nullptr )
      {
        GDError(tr, error: "undefined base class '%s", szToken);
        return 0;
      }
      GameData::ClassForName(this: v2->Parent, pszName: v3->m_szName, &piIndex);
      for ( i = 0; i < v3->m_nVariables; ++i )
      {
        v24 = piIndex;
        VariableAt = GDclass::GetVariableAt(this: v3, iIndex: i);
        GDclass::AddVariable(this: v2, pVar: VariableAt, pBase: v3, iBaseIndex: v24, iVarIndex: i);
      }
      m_Size = v3->m_Inputs.m_Size;
      for ( j = 0; j < m_Size; ++j )
      {
        Other = v3->m_Inputs.m_Memory.m_pMemory[j];
        v6 = (CClassInput *)operator new(nSize: 0x10Cu);
        if ( v6 != nullptr )
        {
          v7 = CClassInput::CClassInput(this: v6);
          v31 = (int)v7;
        }
        else
        {
          v31 = 0;
          v7 = nullptr;
        }
        CClassInputOutputBase::operator=(this: v7, Other);
        if ( v7 != nullptr )
        {
          m_nAllocationCount = v2->m_Inputs.m_Memory.m_nAllocationCount;
          p_m_Inputs = (CUtlMemory<vgui::TreeNode *,int> *)&v2->m_Inputs;
          v10 = v2->m_Inputs.m_Size;
          if ( v10 + 1 > m_nAllocationCount )
            CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
              this: p_m_Inputs,
              num: v10 - m_nAllocationCount + 1);
          ++p_m_Inputs[1].m_pMemory;
          m_pMemory = p_m_Inputs->m_pMemory;
          v12 = (int)p_m_Inputs[1].m_pMemory - v10 - 1;
          p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
          if ( v12 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&m_pMemory[v10 + 1],
              src: (unsigned __int8 *)&m_pMemory[v10],
              count: 4 * v12);
          v13 = &p_m_Inputs->m_pMemory[v10];
          v2 = v29;
          if ( v13 != nullptr )
            *v13 = (vgui::TreeNode *)v31;
        }
      }
      m_Size = v3->m_Outputs.m_Size;
      v31 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v14 = v3->m_Outputs.m_Memory.m_pMemory[v31];
          v15 = (CClassOutput *)operator new(nSize: 0x10Cu);
          if ( v15 != nullptr )
          {
            v16 = CClassOutput::CClassOutput(this: v15);
            j = (int)v16;
          }
          else
          {
            j = 0;
            v16 = nullptr;
          }
          CClassInputOutputBase::operator=(this: v16, Other: v14);
          if ( v16 != nullptr )
          {
            v17 = v29;
            v18 = v29->m_Outputs.m_Size;
            v19 = v29->m_Outputs.m_Memory.m_nAllocationCount;
            if ( v18 + 1 > v19 )
              CUtlMemory<ITilegenClassFactory<ITilegenExpression<CRoomCandidate const *>> *,int>::Grow(
                this: (CUtlMemory<vgui::TreeNode *,int> *)&v29->m_Outputs,
                num: v18 - v19 + 1);
            ++v17->m_Outputs.m_Size;
            v20 = v17->m_Outputs.m_Memory.m_pMemory;
            v21 = v17->m_Outputs.m_Size - v18 - 1;
            v17->m_Outputs.m_pElements = v20;
            if ( v21 > 0 )
              _V_memmove(dest: (unsigned __int8 *)&v20[v18 + 1], src: (unsigned __int8 *)&v20[v18], count: 4 * v21);
            v22 = (int *)&v17->m_Outputs.m_Memory.m_pMemory[v18];
            if ( v22 != nullptr )
              *v22 = j;
          }
          ++v31;
        }
        while ( v31 < m_Size );
        v2 = v29;
      }
      if ( !v2->m_bGotSize && v3->m_bGotSize )
      {
        v2->m_bmins.x = v3->m_bmins.x;
        v2->m_bmins.y = v3->m_bmins.y;
        v2->m_bmins.z = v3->m_bmins.z;
        v2->m_bmaxs.x = v3->m_bmaxs.x;
        v2->m_bmaxs.y = v3->m_bmaxs.y;
        v2->m_bmaxs.z = v3->m_bmaxs.z;
        if ( v3->m_bGotSize )
          v2->m_bGotSize = true;
      }
      if ( !v2->m_bGotColor )
      {
        v2->m_rgbColor = v3->m_rgbColor;
        v2->m_bGotColor = true;
      }
      if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: nullptr) == 0 )
        return 0;
      if ( _V_stricmp(s1: szToken, s2: ")") == 0 )
        return 1;
      if ( _V_stricmp(s1: szToken, s2: ",") != 0 )
        break;
      result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr);
      if ( result == 0 )
        return result;
    }
    GDError(tr, error: "expecting ',' or ')', but found %s", szToken);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FB0C0
// Name: private: bool GDclass::ParseSpecifiers(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseSpecifiers(GDclass *this, TokenReader *tr)
{
  char v3; // al
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF

  if ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) != IDENT )
    return 1;
  while ( 1 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
    if ( _V_stricmp(s1: szToken, s2: "halfgridsnap") != 0 )
      break;
    this->m_bHalfGridSnap = true;
LABEL_13:
    if ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) != IDENT )
      return 1;
  }
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "(") != 0 )
  {
    if ( _V_stricmp(s1: szToken, s2: "base") != 0 )
    {
      if ( _V_stricmp(s1: szToken, s2: "size") != 0 )
        v3 = _V_stricmp(s1: szToken, s2: "color") != 0
           ? GDclass::ParseHelper(this, tr, pszHelperName: szToken)
           : GDclass::ParseColor(this, tr);
      else
        v3 = GDclass::ParseSize(this, tr);
    }
    else
    {
      v3 = GDclass::ParseBase(this, tr);
    }
    if ( v3 != 0 )
      goto LABEL_13;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100FB1D0
// Name: public: int GDclass::InitFromTokens(class TokenReader __near &,class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDclass::InitFromTokens(GDclass *this, TokenReader *tr, GameData *pGD)
{
  __int16 *v4; // eax
  int i; // ecx
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF

  this->Parent = pGD;
  v4 = &this->m_VariableMap[0][1];
  for ( i = 128; i != 0; --i )
  {
    *(v4 - 1) = -1;
    *v4 = -1;
    v4 += 2;
  }
  if ( GDclass::ParseSpecifiers(this, tr) != 0
    && GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "=") != 0
    && GDGetToken(tr, pszStore: this->m_szName, nSize: 65, ttexpecting: IDENT, pszExpecting: nullptr) != 0
    && (TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) != OPERATOR
     || _V_stricmp(s1: szToken, s2: ":") != 0
     || (TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129),
         free(pMem: this->m_pszDescription),
         this->m_pszDescription = nullptr,
         GDGetTokenDynamic(tr, ppszStore: &this->m_pszDescription, ttexpecting: STRING, pszExpecting: nullptr) != 0))
    && GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "[") != 0
    && GDclass::ParseVariables(this, tr) != 0 )
  {
    return GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "]") != 0;
  }
  else
  {
    return false;
  }
}

} // namespace missionchooser

// ============================================================
// Overlay from vbsp (Missing functions)
// ============================================================
namespace vbsp {

//------------------------------------------------------------------------------
// Address: 0x00451DF0
// Name: private: bool GDclass::ParseColor(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseColor(GDclass *this, TokenReader *tr)
{
  bool result; // al
  unsigned __int8 v5; // bl
  unsigned __int8 v6; // al
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF
  unsigned __int8 r_3; // [esp+97h] [ebp+Bh]

  if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    return false;
  r_3 = atoi(nptr: szToken);
  if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    return false;
  v5 = atoi(nptr: szToken);
  result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr);
  if ( result )
  {
    v6 = atoi(nptr: szToken);
    this->m_rgbColor.r = r_3;
    this->m_rgbColor.g = v5;
    this->m_rgbColor.b = v6;
    this->m_rgbColor.a = 0;
    this->m_bGotColor = true;
    return GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")");
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00451EF0
// Name: private: bool GDclass::ParseSize(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseSize(GDclass *this, TokenReader *tr)
{
  int v2; // esi
  Vector *p_m_bmins; // edi
  int v4; // esi
  float *p_x; // edi
  GDclass *v6; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  GDclass *v12; // [esp+90h] [ebp-4h]

  v12 = this;
  v2 = 0;
  p_m_bmins = &this->m_bmins;
  do
  {
    if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
      return false;
    p_m_bmins->x = atof(nptr: szToken);
    ++v2;
    p_m_bmins = (Vector *)((char *)p_m_bmins + 4);
  }
  while ( v2 < 3 );
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) == OPERATOR
    && _V_stricmp(s1: szToken, s2: ",") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
    v4 = 0;
    p_x = &v12->m_bmaxs.x;
    while ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    {
      *p_x = atof(nptr: szToken);
      ++v4;
      ++p_x;
      if ( v4 >= 3 )
      {
        v6 = v12;
        goto LABEL_12;
      }
    }
    return false;
  }
  v8 = v12->m_bmins.x * 0.5;
  v6 = v12;
  v12->m_bmaxs.x = v8;
  v6->m_bmins.x = -v8;
  v9 = v6->m_bmins.y * 0.5;
  v6->m_bmaxs.y = v9;
  v6->m_bmins.y = -v9;
  v10 = v6->m_bmins.z * 0.5;
  v6->m_bmaxs.z = v10;
  v6->m_bmins.z = -v10;
LABEL_12:
  v6->m_bGotSize = true;
  return GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")");
}

//------------------------------------------------------------------------------
// Address: 0x00452090
// Name: protected: bool GDclass::ParseInputOutput(class TokenReader __near &,class CClassInputOutputBase __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseInputOutput(GDclass *this, TokenReader *tr, CClassInputOutputBase *pInputOutput)
{
  TokenReader *v3; // esi
  bool result; // al
  CClassInputOutputBase *v5; // edi
  char *v6; // eax
  int v7; // edx
  char v8; // cl
  char szToken[132]; // [esp+4h] [ebp-84h] BYREF

  v3 = tr;
  result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr);
  if ( result )
  {
    v5 = pInputOutput;
    v6 = szToken;
    v7 = pInputOutput->m_szName - szToken;
    do
    {
      v8 = *v6;
      v6[v7] = *v6;
      ++v6;
    }
    while ( v8 != 0 );
    if ( !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: "(")
      || !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr) )
    {
      return false;
    }
    if ( CClassInputOutputBase::SetType(this: v5, szType: szToken) == iotInvalid )
    {
      GDError(tr: v3, error: "bad input/output type '%s'", szToken);
      return false;
    }
    if ( !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")") )
      return false;
    if ( TokenReader::PeekTokenType(this: v3, pszStore: szToken, maxlen: 129) == OPERATOR
      && _V_stricmp(s1: szToken, s2: ":") == 0 )
    {
      TokenReader::NextToken(this: v3, pszStore: szToken, nSize: 129);
      if ( !GDGetTokenDynamic(tr: v3, ppszStore: (char **)&tr, ttexpecting: STRING, pszExpecting: nullptr) )
        return false;
      v5->m_pszDescription = (char *)tr;
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004521E0
// Name: public: class GDinputvariable __near * GDclass::GetVariableAt(int)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDclass::GetVariableAt(GDclass *this, int iIndex)
{
  int v2; // eax
  __int16 v3; // dx
  GDclass *v4; // edx

  v2 = iIndex;
  if ( iIndex >= 0 )
  {
    while ( v2 < this->m_nVariables )
    {
      v3 = this->m_VariableMap[v2][0];
      if ( v3 == -1 )
        return this->m_Variables.m_Memory.m_pMemory[this->m_VariableMap[v2][1]];
      if ( v3 < this->Parent->m_Classes.m_Size )
        v4 = this->Parent->m_Classes.m_Memory.m_pMemory[v3];
      else
        v4 = nullptr;
      v2 = this->m_VariableMap[v2][1];
      this = v4;
      if ( v2 < 0 )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00452240
// Name: public: class GDinputvariable __near * GDclass::VarForName(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDclass::VarForName(GDclass *this, const char *pszName, int *piIndex)
{
  int m_nVariables; // eax
  int v5; // ecx
  __int16 *j; // ebx
  __int16 v7; // ax
  GDinputvariable *v8; // esi
  int i; // [esp+Ch] [ebp-4h]

  m_nVariables = this->m_nVariables;
  v5 = 0;
  i = 0;
  if ( m_nVariables <= 0 )
    return nullptr;
  for ( j = &this->m_VariableMap[0][1]; ; j += 2 )
  {
    if ( v5 < 0 || v5 >= m_nVariables )
    {
      v8 = nullptr;
    }
    else
    {
      v7 = *(j - 1);
      if ( v7 == -1 )
        v8 = this->m_Variables.m_Memory.m_pMemory[*j];
      else
        v8 = v7 < this->Parent->m_Classes.m_Size
           ? GDclass::GetVariableAt(this: this->Parent->m_Classes.m_Memory.m_pMemory[v7], iIndex: *j)
           : GDclass::GetVariableAt(this: nullptr, iIndex: *j);
    }
    if ( _V_stricmp(s1: v8->m_szName, s2: pszName) == 0 )
      break;
    m_nVariables = this->m_nVariables;
    if ( ++i >= m_nVariables )
      return nullptr;
    v5 = i;
  }
  if ( piIndex != nullptr )
    *piIndex = i;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00452300
// Name: public: CHelperInfo::~CHelperInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHelperInfo::~CHelperInfo(CHelperInfo *this)
{
  int m_Size; // ebx
  int i; // edi
  char **m_pMemory; // eax

  m_Size = this->m_Parameters.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( this->m_Parameters.m_Memory.m_pMemory[i] != nullptr )
      free(pMem: this->m_Parameters.m_Memory.m_pMemory[i]);
  }
  this->m_Parameters.m_Size = 0;
  if ( this->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Parameters.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Parameters.m_Memory.m_pMemory);
      this->m_Parameters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Parameters.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Parameters.m_Memory.m_pMemory;
  this->m_Parameters.m_pElements = m_pMemory;
  if ( this->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Parameters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Parameters.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004523B0
// Name: public: GDclass::GDclass(void)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GDclass::GDclass(GDclass *this)
{
  this->m_Variables.m_Memory.m_pMemory = nullptr;
  this->m_Variables.m_Memory.m_nAllocationCount = 0;
  this->m_Variables.m_Memory.m_nGrowSize = 0;
  this->m_Variables.m_Size = 0;
  this->m_Variables.m_pElements = nullptr;
  this->m_Bases.m_Memory.m_pMemory = nullptr;
  this->m_Bases.m_Memory.m_nAllocationCount = 0;
  this->m_Bases.m_Memory.m_nGrowSize = 0;
  this->m_Bases.m_Size = 0;
  this->m_Bases.m_pElements = nullptr;
  this->m_Inputs.m_Memory.m_pMemory = nullptr;
  this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  this->m_Inputs.m_Memory.m_nGrowSize = 0;
  this->m_Inputs.m_Size = 0;
  this->m_Inputs.m_pElements = nullptr;
  this->m_Outputs.m_Memory.m_pMemory = nullptr;
  this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  this->m_Outputs.m_Memory.m_nGrowSize = 0;
  this->m_Outputs.m_Size = 0;
  this->m_Outputs.m_pElements = nullptr;
  this->m_Helpers.m_Memory.m_pMemory = nullptr;
  this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  this->m_Helpers.m_Memory.m_nGrowSize = 0;
  this->m_Helpers.m_Size = 0;
  this->m_Helpers.m_pElements = nullptr;
  this->m_nVariables = 0;
  *(_DWORD *)&this->m_bBase = 0;
  *(_DWORD *)&this->m_bKeyFrame = 0;
  *(_WORD *)&this->m_bHalfGridSnap = 0;
  this->m_bGotColor = false;
  this->m_rgbColor = (color32_s)&unk_DC1EDC;
  this->m_pszDescription = nullptr;
  this->m_bmins.x = -8.0;
  this->m_bmaxs.x = 8.0;
  this->m_bmins.y = -8.0;
  this->m_bmaxs.y = 8.0;
  this->m_bmins.z = -8.0;
  this->m_bmaxs.z = 8.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00452490
// Name: public: bool CHelperInfo::AddParameter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHelperInfo::AddParameter(CHelperInfo *this, const char *pszParameter)
{
  int v3; // eax
  char *v4; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Parameters; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v9; // eax
  char **v10; // eax

  if ( pszParameter == nullptr )
    return 0;
  if ( *pszParameter == 0 )
    return 0;
  v3 = strlen(pszParameter);
  if ( v3 <= 0 )
    return 0;
  v4 = (char *)MemAlloc_Alloc(nSize: v3 + 1);
  if ( v4 == nullptr )
    return 0;
  strcpy(v4, pszParameter);
  m_nAllocationCount = this->m_Parameters.m_Memory.m_nAllocationCount;
  p_m_Parameters = (CUtlMemory<S3RGBA,int> *)&this->m_Parameters;
  m_Size = this->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CClassInput *,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Parameters[1].m_pMemory;
  m_pMemory = p_m_Parameters->m_pMemory;
  v9 = (int)p_m_Parameters[1].m_pMemory - m_Size - 1;
  p_m_Parameters[1].m_nAllocationCount = (int)p_m_Parameters->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  v10 = (char **)&p_m_Parameters->m_pMemory[m_Size];
  if ( v10 != nullptr )
    *v10 = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00452550
// Name: public: void GDclass::AddInput(class CClassInput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddInput(GDclass *this, CClassInput *pInput)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Inputs; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  if ( pInput != nullptr )
  {
    m_nAllocationCount = this->m_Inputs.m_Memory.m_nAllocationCount;
    p_m_Inputs = (CUtlMemory<S3RGBA,int> *)&this->m_Inputs;
    m_Size = this->m_Inputs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CClassInput *,int>::Grow(this: p_m_Inputs, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Inputs[1].m_pMemory;
    m_pMemory = p_m_Inputs->m_pMemory;
    v6 = (int)p_m_Inputs[1].m_pMemory - m_Size - 1;
    p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_Inputs->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (S3RGBA)pInput;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004525C0
// Name: public: void GDclass::AddOutput(class CClassOutput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddOutput(GDclass *this, CClassOutput *pOutput)
{
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Outputs; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v6; // eax
  S3RGBA *v7; // eax

  if ( pOutput != nullptr )
  {
    m_nAllocationCount = this->m_Outputs.m_Memory.m_nAllocationCount;
    p_m_Outputs = (CUtlMemory<S3RGBA,int> *)&this->m_Outputs;
    m_Size = this->m_Outputs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CClassInput *,int>::Grow(this: p_m_Outputs, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Outputs[1].m_pMemory;
    m_pMemory = p_m_Outputs->m_pMemory;
    v6 = (int)p_m_Outputs[1].m_pMemory - m_Size - 1;
    p_m_Outputs[1].m_nAllocationCount = (int)p_m_Outputs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_Outputs->m_pMemory[m_Size];
    if ( v7 != nullptr )
      *v7 = (S3RGBA)pOutput;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452630
// Name: public: GDclass::~GDclass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::~GDclass(GDclass *this)
{
  int m_Size; // eax
  int v3; // edi
  GDinputvariable *v4; // ecx
  int v5; // eax
  int v6; // edi
  CHelperInfo *v7; // ecx
  int v8; // eax
  int v9; // edi
  CClassInput *v10; // ecx
  int v11; // eax
  int v12; // edi
  CClassOutput *v13; // ecx
  CHelperInfo **m_pMemory; // eax
  CClassOutput **v15; // eax
  CClassInput **v16; // eax
  GDclass **v17; // eax
  GDinputvariable **v18; // eax
  GDinputvariable *pMem; // [esp+Ch] [ebp-8h]
  CHelperInfo *pMema; // [esp+Ch] [ebp-8h]
  int nCount; // [esp+10h] [ebp-4h]
  int nCounta; // [esp+10h] [ebp-4h]
  int nCountb; // [esp+10h] [ebp-4h]
  int nCountc; // [esp+10h] [ebp-4h]

  m_Size = this->m_Variables.m_Size;
  v3 = 0;
  for ( nCount = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = this->m_Variables.m_Memory.m_pMemory[v3];
    pMem = v4;
    if ( v4 != nullptr )
    {
      GDinputvariable::~GDinputvariable(this: v4);
      free(pMem);
      m_Size = nCount;
    }
  }
  this->m_Variables.m_Size = 0;
  v5 = this->m_Helpers.m_Size;
  v6 = 0;
  for ( nCounta = v5; v6 < v5; ++v6 )
  {
    v7 = this->m_Helpers.m_Memory.m_pMemory[v6];
    pMema = v7;
    if ( v7 != nullptr )
    {
      CHelperInfo::~CHelperInfo(this: v7);
      free(pMem: pMema);
      v5 = nCounta;
    }
  }
  this->m_Helpers.m_Size = 0;
  v8 = this->m_Inputs.m_Size;
  v9 = 0;
  for ( nCountb = v8; v9 < v8; ++v9 )
  {
    v10 = this->m_Inputs.m_Memory.m_pMemory[v9];
    if ( v10 != nullptr )
    {
      ((void (__thiscall *)(CClassInput *, int))v10->dtr_CClassInputOutputBase)(a1: v10, a2: 1);
      v8 = nCountb;
    }
  }
  this->m_Inputs.m_Size = 0;
  v11 = this->m_Outputs.m_Size;
  v12 = 0;
  for ( nCountc = v11; v12 < v11; ++v12 )
  {
    v13 = this->m_Outputs.m_Memory.m_pMemory[v12];
    if ( v13 != nullptr )
    {
      ((void (__thiscall *)(CClassOutput *, int))v13->dtr_CClassInputOutputBase)(a1: v13, a2: 1);
      v11 = nCountc;
    }
  }
  this->m_Outputs.m_Size = 0;
  free(pMem: this->m_pszDescription);
  this->m_Helpers.m_Size = 0;
  if ( this->m_Helpers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Helpers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Helpers.m_Memory.m_pMemory);
      this->m_Helpers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Helpers.m_Memory.m_pMemory;
  this->m_Helpers.m_pElements = m_pMemory;
  if ( this->m_Helpers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Helpers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Outputs.m_Size = 0;
  if ( this->m_Outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Outputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Outputs.m_Memory.m_pMemory);
      this->m_Outputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  }
  v15 = this->m_Outputs.m_Memory.m_pMemory;
  this->m_Outputs.m_pElements = v15;
  if ( this->m_Outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      this->m_Outputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Inputs.m_Size = 0;
  if ( this->m_Inputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Inputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Inputs.m_Memory.m_pMemory);
      this->m_Inputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  }
  v16 = this->m_Inputs.m_Memory.m_pMemory;
  this->m_Inputs.m_pElements = v16;
  if ( this->m_Inputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      this->m_Inputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Bases.m_Size = 0;
  if ( this->m_Bases.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Bases.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Bases.m_Memory.m_pMemory);
      this->m_Bases.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bases.m_Memory.m_nAllocationCount = 0;
  }
  v17 = this->m_Bases.m_Memory.m_pMemory;
  this->m_Bases.m_pElements = v17;
  if ( this->m_Bases.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v17 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
      this->m_Bases.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bases.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Variables.m_Size = 0;
  if ( this->m_Variables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Variables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Variables.m_Memory.m_pMemory);
      this->m_Variables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Variables.m_Memory.m_nAllocationCount = 0;
  }
  v18 = this->m_Variables.m_Memory.m_pMemory;
  this->m_Variables.m_pElements = v18;
  if ( this->m_Variables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v18 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
      this->m_Variables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Variables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452910
// Name: public: int GDclass::AddVariable(class GDinputvariable __near *,class GDclass __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDclass::AddVariable(
        GDclass *this,
        GDinputvariable *pVar,
        GDclass *pBase,
        int iBaseIndex,
        __int16 iVarIndex)
{
  GDinputvariable *v6; // esi
  GDIV_TYPE m_eType; // eax
  GDinputvariable *v9; // eax
  GDinputvariable *v10; // esi
  int v11; // edx
  int v12; // edi
  int m_Size; // edx
  int v14; // eax
  GDinputvariable **m_pMemory; // ecx
  int v16; // edi
  int m_nAllocationCount; // eax
  GDinputvariable **v18; // ecx
  int v19; // eax
  GDinputvariable **v20; // edi
  int v21; // edi
  int v22; // eax
  GDinputvariable **v23; // ecx
  int v24; // eax
  GDinputvariable **v25; // edi
  int m_nVariables; // eax
  GDinputvariable *pThisVar; // [esp+Ch] [ebp-Ch]
  GDinputvariable *pAddVar; // [esp+10h] [ebp-8h]
  int iThisIndex; // [esp+14h] [ebp-4h] BYREF
  unsigned __int8 bReturn_3; // [esp+23h] [ebp+Bh]

  v6 = GDclass::VarForName(this, pszName: pVar->m_szName, piIndex: &iThisIndex);
  pThisVar = v6;
  if ( v6 != nullptr )
  {
    m_eType = pVar->m_eType;
    if ( v6->m_eType != m_eType )
      return 0;
    if ( m_eType == ivFlags || m_eType == ivChoices )
    {
      v9 = (GDinputvariable *)MemAlloc_Alloc(nSize: 0x1F0u);
      if ( v9 != nullptr )
        v10 = GDinputvariable::GDinputvariable(this: v9);
      else
        v10 = nullptr;
      GDinputvariable::operator=(this: v10, Other: pVar);
      GDinputvariable::Merge(this: v10, Other: pThisVar);
      pAddVar = v10;
      v6 = pThisVar;
      bReturn_3 = 0;
    }
    else
    {
      pAddVar = pVar;
      bReturn_3 = 1;
    }
    v11 = iThisIndex;
    v12 = -1;
    if ( this->m_VariableMap[iThisIndex][0] == -1 )
    {
      m_Size = this->m_Variables.m_Size;
      v14 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_Variables.m_Memory.m_pMemory;
        while ( *m_pMemory != v6 )
        {
          ++v14;
          ++m_pMemory;
          if ( v14 >= m_Size )
            goto LABEL_18;
        }
        v12 = v14;
      }
LABEL_18:
      GDinputvariable::~GDinputvariable(this: v6);
      free(pMem: v6);
      this->m_Variables.m_Memory.m_pMemory[v12] = pAddVar;
      return bReturn_3;
    }
    else
    {
      this->m_VariableMap[iThisIndex][0] = iBaseIndex;
      if ( iBaseIndex == -1 )
      {
        v16 = this->m_Variables.m_Size;
        m_nAllocationCount = this->m_Variables.m_Memory.m_nAllocationCount;
        if ( v16 + 1 > m_nAllocationCount )
        {
          CUtlMemory<CClassInput *,int>::Grow(
            this: (CUtlMemory<S3RGBA,int> *)&this->m_Variables,
            num: v16 - m_nAllocationCount + 1);
          v11 = iThisIndex;
        }
        ++this->m_Variables.m_Size;
        v18 = this->m_Variables.m_Memory.m_pMemory;
        v19 = this->m_Variables.m_Size - v16 - 1;
        this->m_Variables.m_pElements = v18;
        if ( v19 > 0 )
        {
          _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
          v11 = iThisIndex;
        }
        v20 = &this->m_Variables.m_Memory.m_pMemory[v16];
        if ( v20 != nullptr )
          *v20 = pAddVar;
        this->m_VariableMap[v11][1] = LOWORD(this->m_Variables.m_Size) - 1;
        return bReturn_3;
      }
      else
      {
        this->m_VariableMap[v11][1] = iVarIndex;
        return bReturn_3;
      }
    }
  }
  else
  {
    if ( iBaseIndex == -1 )
    {
      v21 = this->m_Variables.m_Size;
      v22 = this->m_Variables.m_Memory.m_nAllocationCount;
      if ( v21 + 1 > v22 )
        CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&this->m_Variables, num: v21 - v22 + 1);
      ++this->m_Variables.m_Size;
      v23 = this->m_Variables.m_Memory.m_pMemory;
      v24 = this->m_Variables.m_Size - v21 - 1;
      this->m_Variables.m_pElements = v23;
      if ( v24 > 0 )
        _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 4 * v24);
      v25 = &this->m_Variables.m_Memory.m_pMemory[v21];
      if ( v25 != nullptr )
        *v25 = pVar;
    }
    m_nVariables = this->m_nVariables;
    if ( m_nVariables == 128 )
      return 0;
    this->m_VariableMap[m_nVariables][0] = iBaseIndex;
    this->m_VariableMap[this->m_nVariables++][1] = iVarIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00452B30
// Name: private: bool GDclass::ParseHelper(class TokenReader __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseHelper(GDclass *this, TokenReader *tr, char *pszHelperName)
{
  CHelperInfo *v3; // eax
  CHelperInfo *v4; // ebx
  CHelperInfo *v5; // eax
  char v6; // cl
  trtoken_t v7; // eax
  GDclass *v9; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHelperInfo **m_pMemory; // ecx
  int v13; // eax
  CHelperInfo **v14; // eax
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  GDclass *v16; // [esp+90h] [ebp-4h]

  v16 = this;
  v3 = (CHelperInfo *)MemAlloc_Alloc(nSize: 0x114u);
  if ( v3 != nullptr )
  {
    v3->m_Parameters.m_Memory.m_pMemory = nullptr;
    v3->m_Parameters.m_Memory.m_nAllocationCount = 0;
    v3->m_Parameters.m_Memory.m_nGrowSize = 0;
    v3->m_Parameters.m_Size = 0;
    v3->m_Parameters.m_pElements = nullptr;
    v3->m_szName[0] = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  if ( pszHelperName != nullptr )
  {
    v5 = v4;
    do
    {
      v6 = v5->m_szName[pszHelperName - (char *)v4];
      v5->m_szName[0] = v6;
      v5 = (CHelperInfo *)((char *)v5 + 1);
    }
    while ( v6 != 0 );
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129);
      if ( v7 == OPERATOR )
        break;
      if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: v7, pszExpecting: nullptr) )
      {
LABEL_11:
        if ( v4 != nullptr )
        {
          CHelperInfo::~CHelperInfo(this: v4);
          free(pMem: v4);
        }
        return 0;
      }
      CHelperInfo::AddParameter(this: v4, pszParameter: szToken);
    }
    if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: nullptr) )
      goto LABEL_11;
    if ( _V_stricmp(s1: szToken, s2: ")") == 0 )
      break;
    if ( _V_stricmp(s1: szToken, s2: "=") == 0 )
      goto LABEL_11;
  }
  v9 = v16;
  m_Size = v16->m_Helpers.m_Size;
  m_nAllocationCount = v16->m_Helpers.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CClassInput *,int>::Grow(
      this: (CUtlMemory<S3RGBA,int> *)&v16->m_Helpers,
      num: m_Size - m_nAllocationCount + 1);
  ++v9->m_Helpers.m_Size;
  m_pMemory = v9->m_Helpers.m_Memory.m_pMemory;
  v13 = v9->m_Helpers.m_Size - m_Size - 1;
  v9->m_Helpers.m_pElements = m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
  v14 = &v9->m_Helpers.m_Memory.m_pMemory[m_Size];
  if ( v14 != nullptr )
    *v14 = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00452CB0
// Name: private: bool GDclass::ParseVariables(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseVariables(GDclass *this, TokenReader *tr)
{
  TokenReader *v2; // edi
  CClassInput *v4; // eax
  CClassInput *v5; // esi
  CClassOutput *v6; // eax
  GDinputvariable *v7; // eax
  GDinputvariable *v8; // esi
  GDinputvariable *v9; // eax
  char szError[260]; // [esp+Ch] [ebp-210h] BYREF
  char pszStore[132]; // [esp+110h] [ebp-10Ch] BYREF
  char szToken[132]; // [esp+194h] [ebp-88h] BYREF
  int nDupIndex; // [esp+218h] [ebp-4h] BYREF

  v2 = tr;
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) == OPERATOR )
    return 1;
  while ( _V_stricmp(s1: szToken, s2: "input") == 0 )
  {
    if ( !GDGetToken(tr: v2, pszStore, nSize: 129, ttexpecting: IDENT, pszExpecting: "input") )
      return 0;
    v4 = (CClassInput *)MemAlloc_Alloc(nSize: 0x10Cu);
    if ( v4 != nullptr )
      v5 = CClassInput::CClassInput(this: v4);
    else
      v5 = nullptr;
    if ( !GDclass::ParseInputOutput(this, tr: v2, pInputOutput: v5) )
      goto LABEL_31;
    GDclass::AddInput(this, pInput: v5);
LABEL_29:
    if ( TokenReader::PeekTokenType(this: v2, pszStore: szToken, maxlen: 129) == OPERATOR )
      return 1;
  }
  if ( _V_stricmp(s1: szToken, s2: "output") != 0 )
  {
    if ( _V_stricmp(s1: szToken, s2: "key") == 0 )
      GDGetToken(tr: v2, pszStore: szToken, nSize: 129, ttexpecting: TOKENNONE, pszExpecting: nullptr);
    v7 = (GDinputvariable *)MemAlloc_Alloc(nSize: 0x1F0u);
    if ( v7 != nullptr )
      v8 = GDinputvariable::GDinputvariable(this: v7);
    else
      v8 = nullptr;
    if ( GDinputvariable::InitFromTokens(this: v8, tr: v2) == 0 )
    {
      if ( v8 != nullptr )
      {
        GDinputvariable::~GDinputvariable(this: v8);
        free(pMem: v8);
      }
      return 0;
    }
    v9 = GDclass::VarForName(this, pszName: v8->m_szName, piIndex: &nDupIndex);
    if ( v9 != nullptr && v9->m_eType != v8->m_eType )
    {
      sprintf(
        string: szError,
        format: "%s: Variable '%s' is multiply defined with different types.",
        this->m_szName,
        v8->m_szName);
      GDError(tr, error: szError);
    }
    if ( GDclass::AddVariable(this, pVar: v8, pBase: this, iBaseIndex: -1, iVarIndex: this->m_Variables.m_Size) == 0
      && v8 != nullptr )
    {
      GDinputvariable::~GDinputvariable(this: v8);
      free(pMem: v8);
    }
    v2 = tr;
    goto LABEL_29;
  }
  if ( !GDGetToken(tr: v2, pszStore, nSize: 129, ttexpecting: IDENT, pszExpecting: "output") )
    return 0;
  v6 = (CClassOutput *)MemAlloc_Alloc(nSize: 0x10Cu);
  if ( v6 != nullptr )
    v5 = (CClassInput *)CClassOutput::CClassOutput(this: v6);
  else
    v5 = nullptr;
  if ( GDclass::ParseInputOutput(this, tr: v2, pInputOutput: v5) )
  {
    GDclass::AddOutput(this, pOutput: (CClassOutput *)v5);
    goto LABEL_29;
  }
LABEL_31:
  if ( v5 != nullptr )
  {
    ((void (__thiscall *)(CClassInput *, int))v5->dtr_CClassInputOutputBase)(a1: v5, a2: 1);
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00452F00
// Name: public: void GDclass::AddBase(class GDclass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddBase(GDclass *this, CClassOutput *pBase)
{
  GDclass *v3; // edi
  GameData *Parent; // ecx
  int j; // esi
  GDinputvariable *VariableAt; // eax
  CClassInput *v7; // esi
  CClassInput *v8; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Inputs; // esi
  int m_Size; // edi
  S3RGBA *m_pMemory; // ecx
  int v13; // eax
  CClassOutput **v14; // eax
  CClassOutput *v15; // esi
  CClassOutput *v16; // eax
  CClassOutput *v17; // edi
  GDclass *v18; // esi
  int v19; // edi
  int v20; // eax
  CClassOutput **v21; // ecx
  int v22; // eax
  CClassOutput **v23; // eax
  int v24; // [esp-8h] [ebp-24h]
  int iBaseIndex; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  GDclass *v28; // [esp+18h] [ebp-4h]
  CClassOutput *pNew; // [esp+24h] [ebp+8h]
  CClassOutput *pNewa; // [esp+24h] [ebp+8h]

  v3 = this;
  Parent = this->Parent;
  v28 = v3;
  GameData::ClassForName(this: Parent, pszName: &pBase->m_szName[15], piIndex: &iBaseIndex);
  for ( j = 0; j < *(_DWORD *)&pBase->m_szName[104]; ++j )
  {
    v24 = iBaseIndex;
    VariableAt = GDclass::GetVariableAt(this: (GDclass *)pBase, iIndex: j);
    GDclass::AddVariable(this: v3, pVar: VariableAt, (GDclass *)pBase, iBaseIndex: v24, iVarIndex: j);
  }
  nCount = *(_DWORD *)&pBase->m_szName[140];
  for ( i = 0; i < nCount; ++i )
  {
    v7 = *(CClassInput **)(*(_DWORD *)&pBase->m_szName[128] + 4 * i);
    v8 = (CClassInput *)MemAlloc_Alloc(nSize: 0x10Cu);
    if ( v8 != nullptr )
      pNew = (CClassOutput *)CClassInput::CClassInput(this: v8);
    else
      pNew = nullptr;
    CClassInputOutputBase::operator=(this: pNew, Other: v7);
    if ( pNew != nullptr )
    {
      m_nAllocationCount = v3->m_Inputs.m_Memory.m_nAllocationCount;
      p_m_Inputs = (CUtlMemory<S3RGBA,int> *)&v3->m_Inputs;
      m_Size = v3->m_Inputs.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<CClassInput *,int>::Grow(this: p_m_Inputs, num: m_Size - m_nAllocationCount + 1);
      ++p_m_Inputs[1].m_pMemory;
      m_pMemory = p_m_Inputs->m_pMemory;
      v13 = (int)p_m_Inputs[1].m_pMemory - m_Size - 1;
      p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
      v14 = (CClassOutput **)&p_m_Inputs->m_pMemory[m_Size];
      v3 = v28;
      if ( v14 != nullptr )
        *v14 = pNew;
    }
  }
  nCount = *(_DWORD *)&pBase->m_szName[160];
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v15 = *(CClassOutput **)(*(_DWORD *)&pBase->m_szName[148] + 4 * i);
      v16 = (CClassOutput *)MemAlloc_Alloc(nSize: 0x10Cu);
      if ( v16 != nullptr )
      {
        v17 = CClassOutput::CClassOutput(this: v16);
        pNewa = v17;
      }
      else
      {
        pNewa = nullptr;
        v17 = nullptr;
      }
      CClassInputOutputBase::operator=(this: v17, Other: v15);
      if ( v17 != nullptr )
      {
        v18 = v28;
        v19 = v28->m_Outputs.m_Size;
        v20 = v28->m_Outputs.m_Memory.m_nAllocationCount;
        if ( v19 + 1 > v20 )
          CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v28->m_Outputs, num: v19 - v20 + 1);
        ++v18->m_Outputs.m_Size;
        v21 = v18->m_Outputs.m_Memory.m_pMemory;
        v22 = v18->m_Outputs.m_Size - v19 - 1;
        v18->m_Outputs.m_pElements = v21;
        if ( v22 > 0 )
          _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
        v23 = &v18->m_Outputs.m_Memory.m_pMemory[v19];
        if ( v23 != nullptr )
          *v23 = pNewa;
      }
      ++i;
    }
    while ( i < nCount );
    v3 = v28;
  }
  if ( !v3->m_bGotSize && pBase->m_szName[13] != 0 )
  {
    v3->m_bmins.x = *(float *)&pBase[2].m_szName[164];
    v3->m_bmins.y = *(float *)&pBase[2].m_szName[168];
    v3->m_bmins.z = *(float *)&pBase[2].m_szName[172];
    v3->m_bmaxs.x = *(float *)&pBase[2].m_szName[176];
    v3->m_bmaxs.y = *(float *)&pBase[2].m_szName[180];
    v3->m_bmaxs.z = *(float *)&pBase[2].m_szName[184];
    if ( pBase->m_szName[13] != 0 )
      v3->m_bGotSize = true;
  }
  if ( !v3->m_bGotColor )
  {
    v3->m_rgbColor = *(color32_s *)pBase->m_szName;
    v3->m_bGotColor = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00453170
// Name: private: bool GDclass::ParseBase(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseBase(GDclass *this, TokenReader *tr)
{
  GDclass *v2; // edi
  GDclass *v3; // ebx
  int i; // esi
  GDinputvariable *VariableAt; // eax
  CClassInput *v6; // eax
  CClassInput *v7; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<S3RGBA,int> *p_m_Inputs; // esi
  int v10; // edi
  S3RGBA *m_pMemory; // ecx
  int v12; // eax
  S3RGBA *v13; // eax
  CClassInputOutputBase *v14; // edi
  CClassOutput *v15; // eax
  CClassOutput *v16; // esi
  GDclass *v17; // esi
  int v18; // edi
  int v19; // eax
  CClassOutput **v20; // ecx
  int v21; // eax
  int *v22; // eax
  bool result; // al
  int v24; // [esp-8h] [ebp-B0h]
  char szToken[132]; // [esp+Ch] [ebp-9Ch] BYREF
  int piIndex; // [esp+90h] [ebp-18h] BYREF
  CClassInputOutputBase *Other; // [esp+94h] [ebp-14h]
  int m_Size; // [esp+98h] [ebp-10h]
  GDclass *v29; // [esp+9Ch] [ebp-Ch]
  int j; // [esp+A0h] [ebp-8h]
  int v31; // [esp+A4h] [ebp-4h]

  v2 = this;
  v29 = this;
  if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr) )
  {
    while ( 1 )
    {
      v3 = GameData::ClassForName(this: v2->Parent, pszName: szToken, piIndex: nullptr);
      if ( v3 == nullptr )
      {
        GDError(tr, error: "undefined base class '%s", szToken);
        return false;
      }
      GameData::ClassForName(this: v2->Parent, pszName: v3->m_szName, &piIndex);
      for ( i = 0; i < v3->m_nVariables; ++i )
      {
        v24 = piIndex;
        VariableAt = GDclass::GetVariableAt(this: v3, iIndex: i);
        GDclass::AddVariable(this: v2, pVar: VariableAt, pBase: v3, iBaseIndex: v24, iVarIndex: i);
      }
      m_Size = v3->m_Inputs.m_Size;
      for ( j = 0; j < m_Size; ++j )
      {
        Other = v3->m_Inputs.m_Memory.m_pMemory[j];
        v6 = (CClassInput *)MemAlloc_Alloc(nSize: 0x10Cu);
        if ( v6 != nullptr )
        {
          v7 = CClassInput::CClassInput(this: v6);
          v31 = (int)v7;
        }
        else
        {
          v31 = 0;
          v7 = nullptr;
        }
        CClassInputOutputBase::operator=(this: v7, Other);
        if ( v7 != nullptr )
        {
          m_nAllocationCount = v2->m_Inputs.m_Memory.m_nAllocationCount;
          p_m_Inputs = (CUtlMemory<S3RGBA,int> *)&v2->m_Inputs;
          v10 = v2->m_Inputs.m_Size;
          if ( v10 + 1 > m_nAllocationCount )
            CUtlMemory<CClassInput *,int>::Grow(this: p_m_Inputs, num: v10 - m_nAllocationCount + 1);
          ++p_m_Inputs[1].m_pMemory;
          m_pMemory = p_m_Inputs->m_pMemory;
          v12 = (int)p_m_Inputs[1].m_pMemory - v10 - 1;
          p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * v12);
          v13 = &p_m_Inputs->m_pMemory[v10];
          v2 = v29;
          if ( v13 != nullptr )
            *v13 = (S3RGBA)v31;
        }
      }
      m_Size = v3->m_Outputs.m_Size;
      v31 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v14 = v3->m_Outputs.m_Memory.m_pMemory[v31];
          v15 = (CClassOutput *)MemAlloc_Alloc(nSize: 0x10Cu);
          if ( v15 != nullptr )
          {
            v16 = CClassOutput::CClassOutput(this: v15);
            j = (int)v16;
          }
          else
          {
            j = 0;
            v16 = nullptr;
          }
          CClassInputOutputBase::operator=(this: v16, Other: v14);
          if ( v16 != nullptr )
          {
            v17 = v29;
            v18 = v29->m_Outputs.m_Size;
            v19 = v29->m_Outputs.m_Memory.m_nAllocationCount;
            if ( v18 + 1 > v19 )
              CUtlMemory<CClassInput *,int>::Grow(this: (CUtlMemory<S3RGBA,int> *)&v29->m_Outputs, num: v18 - v19 + 1);
            ++v17->m_Outputs.m_Size;
            v20 = v17->m_Outputs.m_Memory.m_pMemory;
            v21 = v17->m_Outputs.m_Size - v18 - 1;
            v17->m_Outputs.m_pElements = v20;
            if ( v21 > 0 )
              _V_memmove(dest: &v20[v18 + 1], src: &v20[v18], count: 4 * v21);
            v22 = (int *)&v17->m_Outputs.m_Memory.m_pMemory[v18];
            if ( v22 != nullptr )
              *v22 = j;
          }
          ++v31;
        }
        while ( v31 < m_Size );
        v2 = v29;
      }
      if ( !v2->m_bGotSize && v3->m_bGotSize )
      {
        v2->m_bmins.x = v3->m_bmins.x;
        v2->m_bmins.y = v3->m_bmins.y;
        v2->m_bmins.z = v3->m_bmins.z;
        v2->m_bmaxs.x = v3->m_bmaxs.x;
        v2->m_bmaxs.y = v3->m_bmaxs.y;
        v2->m_bmaxs.z = v3->m_bmaxs.z;
        if ( v3->m_bGotSize )
          v2->m_bGotSize = true;
      }
      if ( !v2->m_bGotColor )
      {
        v2->m_rgbColor = v3->m_rgbColor;
        v2->m_bGotColor = true;
      }
      if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: nullptr) )
        return false;
      if ( _V_stricmp(s1: szToken, s2: ")") == 0 )
        return true;
      if ( _V_stricmp(s1: szToken, s2: ",") != 0 )
        break;
      result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr);
      if ( !result )
        return result;
    }
    GDError(tr, error: "expecting ',' or ')', but found %s", szToken);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x004534E0
// Name: private: bool GDclass::ParseSpecifiers(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseSpecifiers(GDclass *this, TokenReader *tr)
{
  char v3; // al
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF

  if ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) != IDENT )
    return 1;
  while ( 1 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
    if ( _V_stricmp(s1: szToken, s2: "halfgridsnap") != 0 )
      break;
    this->m_bHalfGridSnap = true;
LABEL_13:
    if ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) != IDENT )
      return 1;
  }
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "(") )
  {
    if ( _V_stricmp(s1: szToken, s2: "base") != 0 )
    {
      if ( _V_stricmp(s1: szToken, s2: "size") != 0 )
        v3 = _V_stricmp(s1: szToken, s2: "color") != 0
           ? GDclass::ParseHelper(this, tr, pszHelperName: szToken)
           : GDclass::ParseColor(this, tr);
      else
        v3 = GDclass::ParseSize(this, tr);
    }
    else
    {
      v3 = GDclass::ParseBase(this, tr);
    }
    if ( v3 != 0 )
      goto LABEL_13;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x004535F0
// Name: public: int GDclass::InitFromTokens(class TokenReader __near &,class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDclass::InitFromTokens(GDclass *this, TokenReader *tr, GameData *pGD)
{
  __int16 *v4; // eax
  int i; // ecx
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF

  this->Parent = pGD;
  v4 = &this->m_VariableMap[0][1];
  for ( i = 128; i != 0; --i )
  {
    *(v4 - 1) = -1;
    *v4 = -1;
    v4 += 2;
  }
  if ( GDclass::ParseSpecifiers(this, tr) != 0
    && GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "=")
    && GDGetToken(tr, pszStore: this->m_szName, nSize: 65, ttexpecting: IDENT, pszExpecting: nullptr)
    && (TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) != OPERATOR
     || _V_stricmp(s1: szToken, s2: ":") != 0
     || (TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129),
         free(pMem: this->m_pszDescription),
         this->m_pszDescription = nullptr,
         GDGetTokenDynamic(tr, ppszStore: &this->m_pszDescription, ttexpecting: STRING, pszExpecting: nullptr)))
    && GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "[")
    && GDclass::ParseVariables(this, tr) != 0 )
  {
    return GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "]");
  }
  else
  {
    return false;
  }
}

} // namespace vbsp

// ============================================================
// Overlay from vbsp2 (Missing functions)
// ============================================================
namespace vbsp2 {

//------------------------------------------------------------------------------
// Address: 0x00447860
// Name: private: bool GDclass::ParseColor(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseColor(GDclass *this, TokenReader *tr)
{
  bool result; // al
  unsigned __int8 v5; // bl
  unsigned __int8 v6; // al
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF
  unsigned __int8 r_3; // [esp+97h] [ebp+Bh]

  if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    return false;
  r_3 = atoi(nptr: szToken);
  if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    return false;
  v5 = atoi(nptr: szToken);
  result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr);
  if ( result )
  {
    v6 = atoi(nptr: szToken);
    this->m_rgbColor.r = r_3;
    this->m_rgbColor.g = v5;
    this->m_rgbColor.b = v6;
    this->m_rgbColor.a = 0;
    this->m_bGotColor = true;
    return GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")");
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447950
// Name: private: bool GDclass::ParseSize(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseSize(GDclass *this, TokenReader *tr)
{
  int v2; // esi
  Vector *p_m_bmins; // edi
  int v4; // esi
  float *p_x; // edi
  GDclass *v6; // eax
  float v8; // xmm0_4
  float v9; // xmm0_4
  float v10; // xmm0_4
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  GDclass *v12; // [esp+90h] [ebp-4h]

  v12 = this;
  v2 = 0;
  p_m_bmins = &this->m_bmins;
  do
  {
    if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
      return false;
    p_m_bmins->x = atof(nptr: szToken);
    ++v2;
    p_m_bmins = (Vector *)((char *)p_m_bmins + 4);
  }
  while ( v2 < 3 );
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) == OPERATOR
    && _V_stricmp(s1: szToken, s2: ",") == 0 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
    v4 = 0;
    p_x = &v12->m_bmaxs.x;
    while ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: INTEGER, pszExpecting: nullptr) )
    {
      *p_x = atof(nptr: szToken);
      ++v4;
      ++p_x;
      if ( v4 >= 3 )
      {
        v6 = v12;
        goto LABEL_12;
      }
    }
    return false;
  }
  v8 = v12->m_bmins.x * 0.5;
  v6 = v12;
  v12->m_bmaxs.x = v8;
  v6->m_bmins.x = -v8;
  v9 = v6->m_bmins.y * 0.5;
  v6->m_bmaxs.y = v9;
  v6->m_bmins.y = -v9;
  v10 = v6->m_bmins.z * 0.5;
  v6->m_bmaxs.z = v10;
  v6->m_bmins.z = -v10;
LABEL_12:
  v6->m_bGotSize = true;
  return GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")");
}

//------------------------------------------------------------------------------
// Address: 0x00447AF0
// Name: protected: bool GDclass::ParseInputOutput(class TokenReader __near &,class CClassInputOutputBase __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseInputOutput(GDclass *this, TokenReader *tr, CClassInputOutputBase *pInputOutput)
{
  TokenReader *v3; // esi
  bool result; // al
  CClassInputOutputBase *v5; // edi
  char *v6; // eax
  int v7; // edx
  char v8; // cl
  char szToken[132]; // [esp+4h] [ebp-84h] BYREF

  v3 = tr;
  result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr);
  if ( result )
  {
    v5 = pInputOutput;
    v6 = szToken;
    v7 = pInputOutput->m_szName - szToken;
    do
    {
      v8 = *v6;
      v6[v7] = *v6;
      ++v6;
    }
    while ( v8 != 0 );
    if ( !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: "(")
      || !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr) )
    {
      return false;
    }
    if ( CClassInputOutputBase::SetType(this: v5, szType: szToken) == iotInvalid )
    {
      GDError(tr: v3, error: "bad input/output type '%s'", szToken);
      return false;
    }
    if ( !GDGetToken(tr: v3, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: ")") )
      return false;
    if ( TokenReader::PeekTokenType(this: v3, pszStore: szToken, maxlen: 129) == OPERATOR
      && _V_stricmp(s1: szToken, s2: ":") == 0 )
    {
      TokenReader::NextToken(this: v3, pszStore: szToken, nSize: 129);
      if ( !GDGetTokenDynamic(tr: v3, ppszStore: (char **)&tr, ttexpecting: STRING, pszExpecting: nullptr) )
        return false;
      v5->m_pszDescription = (char *)tr;
    }
    return true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00447C40
// Name: public: class GDinputvariable __near * GDclass::GetVariableAt(int)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDclass::GetVariableAt(GDclass *this, int iIndex)
{
  int v2; // eax
  __int16 v3; // dx
  GDclass *v4; // edx

  v2 = iIndex;
  if ( iIndex >= 0 )
  {
    while ( v2 < this->m_nVariables )
    {
      v3 = this->m_VariableMap[v2][0];
      if ( v3 == -1 )
        return this->m_Variables.m_Memory.m_pMemory[this->m_VariableMap[v2][1]];
      if ( v3 < this->Parent->m_Classes.m_Size )
        v4 = this->Parent->m_Classes.m_Memory.m_pMemory[v3];
      else
        v4 = nullptr;
      v2 = this->m_VariableMap[v2][1];
      this = v4;
      if ( v2 < 0 )
        return nullptr;
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00447CA0
// Name: public: class GDinputvariable __near * GDclass::VarForName(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
GDinputvariable *__thiscall GDclass::VarForName(GDclass *this, const char *pszName, int *piIndex)
{
  int m_nVariables; // eax
  int v5; // ecx
  __int16 *j; // ebx
  __int16 v7; // ax
  GDinputvariable *v8; // esi
  int i; // [esp+Ch] [ebp-4h]

  m_nVariables = this->m_nVariables;
  v5 = 0;
  i = 0;
  if ( m_nVariables <= 0 )
    return nullptr;
  for ( j = &this->m_VariableMap[0][1]; ; j += 2 )
  {
    if ( v5 < 0 || v5 >= m_nVariables )
    {
      v8 = nullptr;
    }
    else
    {
      v7 = *(j - 1);
      if ( v7 == -1 )
        v8 = this->m_Variables.m_Memory.m_pMemory[*j];
      else
        v8 = v7 < this->Parent->m_Classes.m_Size
           ? GDclass::GetVariableAt(this: this->Parent->m_Classes.m_Memory.m_pMemory[v7], iIndex: *j)
           : GDclass::GetVariableAt(this: nullptr, iIndex: *j);
    }
    if ( _V_stricmp(s1: v8->m_szName, s2: pszName) == 0 )
      break;
    m_nVariables = this->m_nVariables;
    if ( ++i >= m_nVariables )
      return nullptr;
    v5 = i;
  }
  if ( piIndex != nullptr )
    *piIndex = i;
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x00447D60
// Name: public: CHelperInfo::~CHelperInfo(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CHelperInfo::~CHelperInfo(CHelperInfo *this)
{
  int m_Size; // ebx
  int i; // edi
  char **m_pMemory; // eax

  m_Size = this->m_Parameters.m_Size;
  for ( i = 0; i < m_Size; ++i )
  {
    if ( this->m_Parameters.m_Memory.m_pMemory[i] != nullptr )
      free(pMem: this->m_Parameters.m_Memory.m_pMemory[i]);
  }
  this->m_Parameters.m_Size = 0;
  if ( this->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Parameters.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Parameters.m_Memory.m_pMemory);
      this->m_Parameters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Parameters.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Parameters.m_Memory.m_pMemory;
  this->m_Parameters.m_pElements = m_pMemory;
  if ( this->m_Parameters.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Parameters.m_Memory.m_pMemory = nullptr;
    }
    this->m_Parameters.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00447E10
// Name: public: GDclass::GDclass(void)
// Source: json
//------------------------------------------------------------------------------
GDclass *__thiscall GDclass::GDclass(GDclass *this)
{
  this->m_Variables.m_Memory.m_pMemory = nullptr;
  this->m_Variables.m_Memory.m_nAllocationCount = 0;
  this->m_Variables.m_Memory.m_nGrowSize = 0;
  this->m_Variables.m_Size = 0;
  this->m_Variables.m_pElements = nullptr;
  this->m_Bases.m_Memory.m_pMemory = nullptr;
  this->m_Bases.m_Memory.m_nAllocationCount = 0;
  this->m_Bases.m_Memory.m_nGrowSize = 0;
  this->m_Bases.m_Size = 0;
  this->m_Bases.m_pElements = nullptr;
  this->m_Inputs.m_Memory.m_pMemory = nullptr;
  this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  this->m_Inputs.m_Memory.m_nGrowSize = 0;
  this->m_Inputs.m_Size = 0;
  this->m_Inputs.m_pElements = nullptr;
  this->m_Outputs.m_Memory.m_pMemory = nullptr;
  this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  this->m_Outputs.m_Memory.m_nGrowSize = 0;
  this->m_Outputs.m_Size = 0;
  this->m_Outputs.m_pElements = nullptr;
  this->m_Helpers.m_Memory.m_pMemory = nullptr;
  this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  this->m_Helpers.m_Memory.m_nGrowSize = 0;
  this->m_Helpers.m_Size = 0;
  this->m_Helpers.m_pElements = nullptr;
  this->m_nVariables = 0;
  *(_DWORD *)&this->m_bBase = 0;
  *(_DWORD *)&this->m_bKeyFrame = 0;
  *(_WORD *)&this->m_bHalfGridSnap = 0;
  this->m_bGotColor = false;
  this->m_rgbColor = (color32_s)14425820;
  this->m_pszDescription = nullptr;
  this->m_bmins.x = -8.0;
  this->m_bmaxs.x = 8.0;
  this->m_bmins.y = -8.0;
  this->m_bmaxs.y = 8.0;
  this->m_bmins.z = -8.0;
  this->m_bmaxs.z = 8.0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00447EF0
// Name: public: bool CHelperInfo::AddParameter(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall CHelperInfo::AddParameter(CHelperInfo *this, const char *pszParameter)
{
  int v3; // eax
  char *v4; // ebx
  int m_nAllocationCount; // eax
  CUtlMemory<BSPCluster_t,int> *p_m_Parameters; // esi
  int m_Size; // edi
  BSPCluster_t *m_pMemory; // ecx
  int v9; // eax
  _DWORD *p_m_pLeafNode; // eax

  if ( pszParameter == nullptr )
    return 0;
  if ( *pszParameter == 0 )
    return 0;
  v3 = strlen(pszParameter);
  if ( v3 <= 0 )
    return 0;
  v4 = (char *)operator new(nSize: v3 + 1);
  if ( v4 == nullptr )
    return 0;
  strcpy(v4, pszParameter);
  m_nAllocationCount = this->m_Parameters.m_Memory.m_nAllocationCount;
  p_m_Parameters = (CUtlMemory<BSPCluster_t,int> *)&this->m_Parameters;
  m_Size = this->m_Parameters.m_Size;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ColorRGBExp32,int>::Grow(this: p_m_Parameters, num: m_Size - m_nAllocationCount + 1);
  ++p_m_Parameters[1].m_pMemory;
  m_pMemory = p_m_Parameters->m_pMemory;
  v9 = (int)p_m_Parameters[1].m_pMemory - m_Size - 1;
  p_m_Parameters[1].m_nAllocationCount = (int)p_m_Parameters->m_pMemory;
  if ( v9 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v9);
  p_m_pLeafNode = &p_m_Parameters->m_pMemory[m_Size].m_pLeafNode;
  if ( p_m_pLeafNode != nullptr )
    *p_m_pLeafNode = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00447FB0
// Name: public: void GDclass::AddInput(class CClassInput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddInput(GDclass *this, CClassInput *pInput)
{
  int m_nAllocationCount; // eax
  CUtlMemory<BSPCluster_t,int> *p_m_Inputs; // esi
  int m_Size; // edi
  BSPCluster_t *m_pMemory; // ecx
  int v6; // eax
  BSPCluster_t *v7; // eax

  if ( pInput != nullptr )
  {
    m_nAllocationCount = this->m_Inputs.m_Memory.m_nAllocationCount;
    p_m_Inputs = (CUtlMemory<BSPCluster_t,int> *)&this->m_Inputs;
    m_Size = this->m_Inputs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ColorRGBExp32,int>::Grow(this: p_m_Inputs, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Inputs[1].m_pMemory;
    m_pMemory = p_m_Inputs->m_pMemory;
    v6 = (int)p_m_Inputs[1].m_pMemory - m_Size - 1;
    p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_Inputs->m_pMemory[m_Size];
    if ( v7 != nullptr )
      v7->m_pLeafNode = (const CBSPNode *)pInput;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448020
// Name: public: void GDclass::AddOutput(class CClassOutput __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddOutput(GDclass *this, CClassOutput *pOutput)
{
  int m_nAllocationCount; // eax
  CUtlMemory<BSPCluster_t,int> *p_m_Outputs; // esi
  int m_Size; // edi
  BSPCluster_t *m_pMemory; // ecx
  int v6; // eax
  BSPCluster_t *v7; // eax

  if ( pOutput != nullptr )
  {
    m_nAllocationCount = this->m_Outputs.m_Memory.m_nAllocationCount;
    p_m_Outputs = (CUtlMemory<BSPCluster_t,int> *)&this->m_Outputs;
    m_Size = this->m_Outputs.m_Size;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<ColorRGBExp32,int>::Grow(this: p_m_Outputs, num: m_Size - m_nAllocationCount + 1);
    ++p_m_Outputs[1].m_pMemory;
    m_pMemory = p_m_Outputs->m_pMemory;
    v6 = (int)p_m_Outputs[1].m_pMemory - m_Size - 1;
    p_m_Outputs[1].m_nAllocationCount = (int)p_m_Outputs->m_pMemory;
    if ( v6 > 0 )
      _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v6);
    v7 = &p_m_Outputs->m_pMemory[m_Size];
    if ( v7 != nullptr )
      v7->m_pLeafNode = (const CBSPNode *)pOutput;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448090
// Name: public: GDclass::~GDclass(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::~GDclass(GDclass *this)
{
  int m_Size; // eax
  int v3; // edi
  GDinputvariable *v4; // ecx
  int v5; // eax
  int v6; // edi
  CHelperInfo *v7; // ecx
  int v8; // eax
  int v9; // edi
  CClassInput *v10; // ecx
  int v11; // eax
  int v12; // edi
  CClassOutput *v13; // ecx
  CHelperInfo **m_pMemory; // eax
  CClassOutput **v15; // eax
  CClassInput **v16; // eax
  GDclass **v17; // eax
  GDinputvariable **v18; // eax
  GDinputvariable *pMem; // [esp+Ch] [ebp-8h]
  CHelperInfo *pMema; // [esp+Ch] [ebp-8h]
  int nCount; // [esp+10h] [ebp-4h]
  int nCounta; // [esp+10h] [ebp-4h]
  int nCountb; // [esp+10h] [ebp-4h]
  int nCountc; // [esp+10h] [ebp-4h]

  m_Size = this->m_Variables.m_Size;
  v3 = 0;
  for ( nCount = m_Size; v3 < m_Size; ++v3 )
  {
    v4 = this->m_Variables.m_Memory.m_pMemory[v3];
    pMem = v4;
    if ( v4 != nullptr )
    {
      GDinputvariable::~GDinputvariable(this: v4);
      free(pMem);
      m_Size = nCount;
    }
  }
  this->m_Variables.m_Size = 0;
  v5 = this->m_Helpers.m_Size;
  v6 = 0;
  for ( nCounta = v5; v6 < v5; ++v6 )
  {
    v7 = this->m_Helpers.m_Memory.m_pMemory[v6];
    pMema = v7;
    if ( v7 != nullptr )
    {
      CHelperInfo::~CHelperInfo(this: v7);
      free(pMem: pMema);
      v5 = nCounta;
    }
  }
  this->m_Helpers.m_Size = 0;
  v8 = this->m_Inputs.m_Size;
  v9 = 0;
  for ( nCountb = v8; v9 < v8; ++v9 )
  {
    v10 = this->m_Inputs.m_Memory.m_pMemory[v9];
    if ( v10 != nullptr )
    {
      ((void (__thiscall *)(CClassInput *, int))v10->dtr_CClassInputOutputBase)(a1: v10, a2: 1);
      v8 = nCountb;
    }
  }
  this->m_Inputs.m_Size = 0;
  v11 = this->m_Outputs.m_Size;
  v12 = 0;
  for ( nCountc = v11; v12 < v11; ++v12 )
  {
    v13 = this->m_Outputs.m_Memory.m_pMemory[v12];
    if ( v13 != nullptr )
    {
      ((void (__thiscall *)(CClassOutput *, int))v13->dtr_CClassInputOutputBase)(a1: v13, a2: 1);
      v11 = nCountc;
    }
  }
  this->m_Outputs.m_Size = 0;
  free(pMem: this->m_pszDescription);
  this->m_Helpers.m_Size = 0;
  if ( this->m_Helpers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Helpers.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Helpers.m_Memory.m_pMemory);
      this->m_Helpers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  }
  m_pMemory = this->m_Helpers.m_Memory.m_pMemory;
  this->m_Helpers.m_pElements = m_pMemory;
  if ( this->m_Helpers.m_Memory.m_nGrowSize >= 0 )
  {
    if ( m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: m_pMemory);
      this->m_Helpers.m_Memory.m_pMemory = nullptr;
    }
    this->m_Helpers.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Outputs.m_Size = 0;
  if ( this->m_Outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Outputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Outputs.m_Memory.m_pMemory);
      this->m_Outputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  }
  v15 = this->m_Outputs.m_Memory.m_pMemory;
  this->m_Outputs.m_pElements = v15;
  if ( this->m_Outputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v15 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v15);
      this->m_Outputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Outputs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Inputs.m_Size = 0;
  if ( this->m_Inputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Inputs.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Inputs.m_Memory.m_pMemory);
      this->m_Inputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  }
  v16 = this->m_Inputs.m_Memory.m_pMemory;
  this->m_Inputs.m_pElements = v16;
  if ( this->m_Inputs.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v16 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v16);
      this->m_Inputs.m_Memory.m_pMemory = nullptr;
    }
    this->m_Inputs.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Bases.m_Size = 0;
  if ( this->m_Bases.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Bases.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Bases.m_Memory.m_pMemory);
      this->m_Bases.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bases.m_Memory.m_nAllocationCount = 0;
  }
  v17 = this->m_Bases.m_Memory.m_pMemory;
  this->m_Bases.m_pElements = v17;
  if ( this->m_Bases.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v17 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v17);
      this->m_Bases.m_Memory.m_pMemory = nullptr;
    }
    this->m_Bases.m_Memory.m_nAllocationCount = 0;
  }
  this->m_Variables.m_Size = 0;
  if ( this->m_Variables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( this->m_Variables.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_Variables.m_Memory.m_pMemory);
      this->m_Variables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Variables.m_Memory.m_nAllocationCount = 0;
  }
  v18 = this->m_Variables.m_Memory.m_pMemory;
  this->m_Variables.m_pElements = v18;
  if ( this->m_Variables.m_Memory.m_nGrowSize >= 0 )
  {
    if ( v18 != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: v18);
      this->m_Variables.m_Memory.m_pMemory = nullptr;
    }
    this->m_Variables.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448370
// Name: public: int GDclass::AddVariable(class GDinputvariable __near *,class GDclass __near *,int,int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall GDclass::AddVariable(
        GDclass *this,
        GDinputvariable *pVar,
        GDclass *pBase,
        int iBaseIndex,
        __int16 iVarIndex)
{
  GDinputvariable *v6; // esi
  GDIV_TYPE m_eType; // eax
  GDinputvariable *v9; // eax
  GDinputvariable *v10; // esi
  int v11; // edx
  int v12; // edi
  int m_Size; // edx
  int v14; // eax
  GDinputvariable **m_pMemory; // ecx
  int v16; // edi
  int m_nAllocationCount; // eax
  GDinputvariable **v18; // ecx
  int v19; // eax
  GDinputvariable **v20; // edi
  int v21; // edi
  int v22; // eax
  GDinputvariable **v23; // ecx
  int v24; // eax
  GDinputvariable **v25; // edi
  int m_nVariables; // eax
  GDinputvariable *pThisVar; // [esp+Ch] [ebp-Ch]
  GDinputvariable *pAddVar; // [esp+10h] [ebp-8h]
  int iThisIndex; // [esp+14h] [ebp-4h] BYREF
  unsigned __int8 bReturn_3; // [esp+23h] [ebp+Bh]

  v6 = GDclass::VarForName(this, pszName: pVar->m_szName, piIndex: &iThisIndex);
  pThisVar = v6;
  if ( v6 != nullptr )
  {
    m_eType = pVar->m_eType;
    if ( v6->m_eType != m_eType )
      return 0;
    if ( m_eType == ivFlags || m_eType == ivChoices )
    {
      v9 = (GDinputvariable *)operator new(nSize: 0x1F0u);
      if ( v9 != nullptr )
        v10 = GDinputvariable::GDinputvariable(this: v9);
      else
        v10 = nullptr;
      GDinputvariable::operator=(this: v10, Other: pVar);
      GDinputvariable::Merge(this: v10, Other: pThisVar);
      pAddVar = v10;
      v6 = pThisVar;
      bReturn_3 = 0;
    }
    else
    {
      pAddVar = pVar;
      bReturn_3 = 1;
    }
    v11 = iThisIndex;
    v12 = -1;
    if ( this->m_VariableMap[iThisIndex][0] == -1 )
    {
      m_Size = this->m_Variables.m_Size;
      v14 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_Variables.m_Memory.m_pMemory;
        while ( *m_pMemory != v6 )
        {
          ++v14;
          ++m_pMemory;
          if ( v14 >= m_Size )
            goto LABEL_18;
        }
        v12 = v14;
      }
LABEL_18:
      GDinputvariable::~GDinputvariable(this: v6);
      free(pMem: v6);
      this->m_Variables.m_Memory.m_pMemory[v12] = pAddVar;
      return bReturn_3;
    }
    else
    {
      this->m_VariableMap[iThisIndex][0] = iBaseIndex;
      if ( iBaseIndex == -1 )
      {
        v16 = this->m_Variables.m_Size;
        m_nAllocationCount = this->m_Variables.m_Memory.m_nAllocationCount;
        if ( v16 + 1 > m_nAllocationCount )
        {
          CUtlMemory<ColorRGBExp32,int>::Grow(
            this: (CUtlMemory<BSPCluster_t,int> *)&this->m_Variables,
            num: v16 - m_nAllocationCount + 1);
          v11 = iThisIndex;
        }
        ++this->m_Variables.m_Size;
        v18 = this->m_Variables.m_Memory.m_pMemory;
        v19 = this->m_Variables.m_Size - v16 - 1;
        this->m_Variables.m_pElements = v18;
        if ( v19 > 0 )
        {
          _V_memmove(dest: &v18[v16 + 1], src: &v18[v16], count: 4 * v19);
          v11 = iThisIndex;
        }
        v20 = &this->m_Variables.m_Memory.m_pMemory[v16];
        if ( v20 != nullptr )
          *v20 = pAddVar;
        this->m_VariableMap[v11][1] = LOWORD(this->m_Variables.m_Size) - 1;
        return bReturn_3;
      }
      else
      {
        this->m_VariableMap[v11][1] = iVarIndex;
        return bReturn_3;
      }
    }
  }
  else
  {
    if ( iBaseIndex == -1 )
    {
      v21 = this->m_Variables.m_Size;
      v22 = this->m_Variables.m_Memory.m_nAllocationCount;
      if ( v21 + 1 > v22 )
        CUtlMemory<ColorRGBExp32,int>::Grow(
          this: (CUtlMemory<BSPCluster_t,int> *)&this->m_Variables,
          num: v21 - v22 + 1);
      ++this->m_Variables.m_Size;
      v23 = this->m_Variables.m_Memory.m_pMemory;
      v24 = this->m_Variables.m_Size - v21 - 1;
      this->m_Variables.m_pElements = v23;
      if ( v24 > 0 )
        _V_memmove(dest: &v23[v21 + 1], src: &v23[v21], count: 4 * v24);
      v25 = &this->m_Variables.m_Memory.m_pMemory[v21];
      if ( v25 != nullptr )
        *v25 = pVar;
    }
    m_nVariables = this->m_nVariables;
    if ( m_nVariables == 128 )
      return 0;
    this->m_VariableMap[m_nVariables][0] = iBaseIndex;
    this->m_VariableMap[this->m_nVariables++][1] = iVarIndex;
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448590
// Name: private: bool GDclass::ParseHelper(class TokenReader __near &,char __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseHelper(GDclass *this, TokenReader *tr, char *pszHelperName)
{
  CHelperInfo *v3; // eax
  CHelperInfo *v4; // ebx
  CHelperInfo *v5; // eax
  char v6; // cl
  trtoken_t v7; // eax
  GDclass *v9; // esi
  int m_Size; // edi
  int m_nAllocationCount; // eax
  CHelperInfo **m_pMemory; // ecx
  int v13; // eax
  CHelperInfo **v14; // eax
  char szToken[132]; // [esp+Ch] [ebp-88h] BYREF
  GDclass *v16; // [esp+90h] [ebp-4h]

  v16 = this;
  v3 = (CHelperInfo *)operator new(nSize: 0x114u);
  if ( v3 != nullptr )
  {
    v3->m_Parameters.m_Memory.m_pMemory = nullptr;
    v3->m_Parameters.m_Memory.m_nAllocationCount = 0;
    v3->m_Parameters.m_Memory.m_nGrowSize = 0;
    v3->m_Parameters.m_Size = 0;
    v3->m_Parameters.m_pElements = nullptr;
    v3->m_szName[0] = 0;
    v4 = v3;
  }
  else
  {
    v4 = nullptr;
  }
  if ( pszHelperName != nullptr )
  {
    v5 = v4;
    do
    {
      v6 = v5->m_szName[pszHelperName - (char *)v4];
      v5->m_szName[0] = v6;
      v5 = (CHelperInfo *)((char *)v5 + 1);
    }
    while ( v6 != 0 );
  }
  while ( 1 )
  {
    while ( 1 )
    {
      v7 = TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129);
      if ( v7 == OPERATOR )
        break;
      if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: v7, pszExpecting: nullptr) )
      {
LABEL_11:
        if ( v4 != nullptr )
        {
          CHelperInfo::~CHelperInfo(this: v4);
          free(pMem: v4);
        }
        return 0;
      }
      CHelperInfo::AddParameter(this: v4, pszParameter: szToken);
    }
    if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: nullptr) )
      goto LABEL_11;
    if ( _V_stricmp(s1: szToken, s2: ")") == 0 )
      break;
    if ( _V_stricmp(s1: szToken, s2: "=") == 0 )
      goto LABEL_11;
  }
  v9 = v16;
  m_Size = v16->m_Helpers.m_Size;
  m_nAllocationCount = v16->m_Helpers.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<ColorRGBExp32,int>::Grow(
      this: (CUtlMemory<BSPCluster_t,int> *)&v16->m_Helpers,
      num: m_Size - m_nAllocationCount + 1);
  ++v9->m_Helpers.m_Size;
  m_pMemory = v9->m_Helpers.m_Memory.m_pMemory;
  v13 = v9->m_Helpers.m_Size - m_Size - 1;
  v9->m_Helpers.m_pElements = m_pMemory;
  if ( v13 > 0 )
    _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
  v14 = &v9->m_Helpers.m_Memory.m_pMemory[m_Size];
  if ( v14 != nullptr )
    *v14 = v4;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x00448710
// Name: private: bool GDclass::ParseVariables(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseVariables(GDclass *this, TokenReader *tr)
{
  TokenReader *v2; // edi
  CClassInput *v4; // eax
  CClassInput *v5; // esi
  CClassOutput *v6; // eax
  GDinputvariable *v7; // eax
  GDinputvariable *v8; // esi
  GDinputvariable *v9; // eax
  char szError[260]; // [esp+Ch] [ebp-210h] BYREF
  char pszStore[132]; // [esp+110h] [ebp-10Ch] BYREF
  char szToken[132]; // [esp+194h] [ebp-88h] BYREF
  int nDupIndex; // [esp+218h] [ebp-4h] BYREF

  v2 = tr;
  if ( TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) == OPERATOR )
    return 1;
  while ( _V_stricmp(s1: szToken, s2: "input") == 0 )
  {
    if ( !GDGetToken(tr: v2, pszStore, nSize: 129, ttexpecting: IDENT, pszExpecting: "input") )
      return 0;
    v4 = (CClassInput *)operator new(nSize: 0x10Cu);
    if ( v4 != nullptr )
      v5 = CClassInput::CClassInput(this: v4);
    else
      v5 = nullptr;
    if ( !GDclass::ParseInputOutput(this, tr: v2, pInputOutput: v5) )
      goto LABEL_31;
    GDclass::AddInput(this, pInput: v5);
LABEL_29:
    if ( TokenReader::PeekTokenType(this: v2, pszStore: szToken, maxlen: 129) == OPERATOR )
      return 1;
  }
  if ( _V_stricmp(s1: szToken, s2: "output") != 0 )
  {
    if ( _V_stricmp(s1: szToken, s2: "key") == 0 )
      GDGetToken(tr: v2, pszStore: szToken, nSize: 129, ttexpecting: TOKENNONE, pszExpecting: nullptr);
    v7 = (GDinputvariable *)operator new(nSize: 0x1F0u);
    if ( v7 != nullptr )
      v8 = GDinputvariable::GDinputvariable(this: v7);
    else
      v8 = nullptr;
    if ( GDinputvariable::InitFromTokens(this: v8, tr: v2) == 0 )
    {
      if ( v8 != nullptr )
      {
        GDinputvariable::~GDinputvariable(this: v8);
        free(pMem: v8);
      }
      return 0;
    }
    v9 = GDclass::VarForName(this, pszName: v8->m_szName, piIndex: &nDupIndex);
    if ( v9 != nullptr && v9->m_eType != v8->m_eType )
    {
      sprintf(
        string: szError,
        format: "%s: Variable '%s' is multiply defined with different types.",
        this->m_szName,
        v8->m_szName);
      GDError(tr, error: szError);
    }
    if ( GDclass::AddVariable(this, pVar: v8, pBase: this, iBaseIndex: -1, iVarIndex: this->m_Variables.m_Size) == 0
      && v8 != nullptr )
    {
      GDinputvariable::~GDinputvariable(this: v8);
      free(pMem: v8);
    }
    v2 = tr;
    goto LABEL_29;
  }
  if ( !GDGetToken(tr: v2, pszStore, nSize: 129, ttexpecting: IDENT, pszExpecting: "output") )
    return 0;
  v6 = (CClassOutput *)operator new(nSize: 0x10Cu);
  if ( v6 != nullptr )
    v5 = (CClassInput *)CClassOutput::CClassOutput(this: v6);
  else
    v5 = nullptr;
  if ( GDclass::ParseInputOutput(this, tr: v2, pInputOutput: v5) )
  {
    GDclass::AddOutput(this, pOutput: (CClassOutput *)v5);
    goto LABEL_29;
  }
LABEL_31:
  if ( v5 != nullptr )
  {
    ((void (__thiscall *)(CClassInput *, int))v5->dtr_CClassInputOutputBase)(a1: v5, a2: 1);
    return 0;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00448960
// Name: public: void GDclass::AddBase(class GDclass __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall GDclass::AddBase(GDclass *this, CClassOutput *pBase)
{
  GDclass *v3; // edi
  GameData *Parent; // ecx
  int j; // esi
  GDinputvariable *VariableAt; // eax
  CClassInput *v7; // esi
  CClassInput *v8; // eax
  int m_nAllocationCount; // eax
  CUtlMemory<BSPCluster_t,int> *p_m_Inputs; // esi
  int m_Size; // edi
  BSPCluster_t *m_pMemory; // ecx
  int v13; // eax
  _DWORD *p_m_pLeafNode; // eax
  CClassOutput *v15; // esi
  CClassOutput *v16; // eax
  CClassOutput *v17; // edi
  GDclass *v18; // esi
  int v19; // edi
  int v20; // eax
  CClassOutput **v21; // ecx
  int v22; // eax
  CClassOutput **v23; // eax
  int v24; // [esp-8h] [ebp-24h]
  int iBaseIndex; // [esp+Ch] [ebp-10h] BYREF
  int nCount; // [esp+10h] [ebp-Ch]
  int i; // [esp+14h] [ebp-8h]
  GDclass *v28; // [esp+18h] [ebp-4h]
  CClassOutput *pNew; // [esp+24h] [ebp+8h]
  CClassOutput *pNewa; // [esp+24h] [ebp+8h]

  v3 = this;
  Parent = this->Parent;
  v28 = v3;
  GameData::ClassForName(this: Parent, pszName: &pBase->m_szName[15], piIndex: &iBaseIndex);
  for ( j = 0; j < *(_DWORD *)&pBase->m_szName[104]; ++j )
  {
    v24 = iBaseIndex;
    VariableAt = GDclass::GetVariableAt(this: (GDclass *)pBase, iIndex: j);
    GDclass::AddVariable(this: v3, pVar: VariableAt, (GDclass *)pBase, iBaseIndex: v24, iVarIndex: j);
  }
  nCount = *(_DWORD *)&pBase->m_szName[140];
  for ( i = 0; i < nCount; ++i )
  {
    v7 = *(CClassInput **)(*(_DWORD *)&pBase->m_szName[128] + 4 * i);
    v8 = (CClassInput *)operator new(nSize: 0x10Cu);
    if ( v8 != nullptr )
      pNew = (CClassOutput *)CClassInput::CClassInput(this: v8);
    else
      pNew = nullptr;
    CClassInputOutputBase::operator=(this: pNew, Other: v7);
    if ( pNew != nullptr )
    {
      m_nAllocationCount = v3->m_Inputs.m_Memory.m_nAllocationCount;
      p_m_Inputs = (CUtlMemory<BSPCluster_t,int> *)&v3->m_Inputs;
      m_Size = v3->m_Inputs.m_Size;
      if ( m_Size + 1 > m_nAllocationCount )
        CUtlMemory<ColorRGBExp32,int>::Grow(this: p_m_Inputs, num: m_Size - m_nAllocationCount + 1);
      ++p_m_Inputs[1].m_pMemory;
      m_pMemory = p_m_Inputs->m_pMemory;
      v13 = (int)p_m_Inputs[1].m_pMemory - m_Size - 1;
      p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
      if ( v13 > 0 )
        _V_memmove(dest: &m_pMemory[m_Size + 1], src: &m_pMemory[m_Size], count: 4 * v13);
      p_m_pLeafNode = &p_m_Inputs->m_pMemory[m_Size].m_pLeafNode;
      v3 = v28;
      if ( p_m_pLeafNode != nullptr )
        *p_m_pLeafNode = pNew;
    }
  }
  nCount = *(_DWORD *)&pBase->m_szName[160];
  i = 0;
  if ( nCount > 0 )
  {
    do
    {
      v15 = *(CClassOutput **)(*(_DWORD *)&pBase->m_szName[148] + 4 * i);
      v16 = (CClassOutput *)operator new(nSize: 0x10Cu);
      if ( v16 != nullptr )
      {
        v17 = CClassOutput::CClassOutput(this: v16);
        pNewa = v17;
      }
      else
      {
        pNewa = nullptr;
        v17 = nullptr;
      }
      CClassInputOutputBase::operator=(this: v17, Other: v15);
      if ( v17 != nullptr )
      {
        v18 = v28;
        v19 = v28->m_Outputs.m_Size;
        v20 = v28->m_Outputs.m_Memory.m_nAllocationCount;
        if ( v19 + 1 > v20 )
          CUtlMemory<ColorRGBExp32,int>::Grow(this: (CUtlMemory<BSPCluster_t,int> *)&v28->m_Outputs, num: v19 - v20 + 1);
        ++v18->m_Outputs.m_Size;
        v21 = v18->m_Outputs.m_Memory.m_pMemory;
        v22 = v18->m_Outputs.m_Size - v19 - 1;
        v18->m_Outputs.m_pElements = v21;
        if ( v22 > 0 )
          _V_memmove(dest: &v21[v19 + 1], src: &v21[v19], count: 4 * v22);
        v23 = &v18->m_Outputs.m_Memory.m_pMemory[v19];
        if ( v23 != nullptr )
          *v23 = pNewa;
      }
      ++i;
    }
    while ( i < nCount );
    v3 = v28;
  }
  if ( !v3->m_bGotSize && pBase->m_szName[13] != 0 )
  {
    v3->m_bmins.x = *(float *)&pBase[2].m_szName[164];
    v3->m_bmins.y = *(float *)&pBase[2].m_szName[168];
    v3->m_bmins.z = *(float *)&pBase[2].m_szName[172];
    v3->m_bmaxs.x = *(float *)&pBase[2].m_szName[176];
    v3->m_bmaxs.y = *(float *)&pBase[2].m_szName[180];
    v3->m_bmaxs.z = *(float *)&pBase[2].m_szName[184];
    if ( pBase->m_szName[13] != 0 )
      v3->m_bGotSize = true;
  }
  if ( !v3->m_bGotColor )
  {
    v3->m_rgbColor = *(color32_s *)pBase->m_szName;
    v3->m_bGotColor = true;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00448BD0
// Name: private: bool GDclass::ParseBase(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall GDclass::ParseBase(GDclass *this, TokenReader *tr)
{
  GDclass *v2; // edi
  GDclass *v3; // ebx
  int i; // esi
  GDinputvariable *VariableAt; // eax
  CClassInput *v6; // eax
  CClassInput *v7; // esi
  int m_nAllocationCount; // eax
  CUtlMemory<BSPCluster_t,int> *p_m_Inputs; // esi
  int v10; // edi
  BSPCluster_t *m_pMemory; // ecx
  int v12; // eax
  BSPCluster_t *v13; // eax
  CClassInputOutputBase *v14; // edi
  CClassOutput *v15; // eax
  CClassOutput *v16; // esi
  GDclass *v17; // esi
  int v18; // edi
  int v19; // eax
  CClassOutput **v20; // ecx
  int v21; // eax
  int *v22; // eax
  bool result; // al
  int v24; // [esp-8h] [ebp-B0h]
  char szToken[132]; // [esp+Ch] [ebp-9Ch] BYREF
  int piIndex; // [esp+90h] [ebp-18h] BYREF
  CClassInputOutputBase *Other; // [esp+94h] [ebp-14h]
  int m_Size; // [esp+98h] [ebp-10h]
  GDclass *v29; // [esp+9Ch] [ebp-Ch]
  int j; // [esp+A0h] [ebp-8h]
  int v31; // [esp+A4h] [ebp-4h]

  v2 = this;
  v29 = this;
  if ( GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr) )
  {
    while ( 1 )
    {
      v3 = GameData::ClassForName(this: v2->Parent, pszName: szToken, piIndex: nullptr);
      if ( v3 == nullptr )
      {
        GDError(tr, error: "undefined base class '%s", szToken);
        return false;
      }
      GameData::ClassForName(this: v2->Parent, pszName: v3->m_szName, &piIndex);
      for ( i = 0; i < v3->m_nVariables; ++i )
      {
        v24 = piIndex;
        VariableAt = GDclass::GetVariableAt(this: v3, iIndex: i);
        GDclass::AddVariable(this: v2, pVar: VariableAt, pBase: v3, iBaseIndex: v24, iVarIndex: i);
      }
      m_Size = v3->m_Inputs.m_Size;
      for ( j = 0; j < m_Size; ++j )
      {
        Other = v3->m_Inputs.m_Memory.m_pMemory[j];
        v6 = (CClassInput *)operator new(nSize: 0x10Cu);
        if ( v6 != nullptr )
        {
          v7 = CClassInput::CClassInput(this: v6);
          v31 = (int)v7;
        }
        else
        {
          v31 = 0;
          v7 = nullptr;
        }
        CClassInputOutputBase::operator=(this: v7, Other);
        if ( v7 != nullptr )
        {
          m_nAllocationCount = v2->m_Inputs.m_Memory.m_nAllocationCount;
          p_m_Inputs = (CUtlMemory<BSPCluster_t,int> *)&v2->m_Inputs;
          v10 = v2->m_Inputs.m_Size;
          if ( v10 + 1 > m_nAllocationCount )
            CUtlMemory<ColorRGBExp32,int>::Grow(this: p_m_Inputs, num: v10 - m_nAllocationCount + 1);
          ++p_m_Inputs[1].m_pMemory;
          m_pMemory = p_m_Inputs->m_pMemory;
          v12 = (int)p_m_Inputs[1].m_pMemory - v10 - 1;
          p_m_Inputs[1].m_nAllocationCount = (int)p_m_Inputs->m_pMemory;
          if ( v12 > 0 )
            _V_memmove(dest: &m_pMemory[v10 + 1], src: &m_pMemory[v10], count: 4 * v12);
          v13 = &p_m_Inputs->m_pMemory[v10];
          v2 = v29;
          if ( v13 != nullptr )
            v13->m_pLeafNode = (const CBSPNode *)v31;
        }
      }
      m_Size = v3->m_Outputs.m_Size;
      v31 = 0;
      if ( m_Size > 0 )
      {
        do
        {
          v14 = v3->m_Outputs.m_Memory.m_pMemory[v31];
          v15 = (CClassOutput *)operator new(nSize: 0x10Cu);
          if ( v15 != nullptr )
          {
            v16 = CClassOutput::CClassOutput(this: v15);
            j = (int)v16;
          }
          else
          {
            j = 0;
            v16 = nullptr;
          }
          CClassInputOutputBase::operator=(this: v16, Other: v14);
          if ( v16 != nullptr )
          {
            v17 = v29;
            v18 = v29->m_Outputs.m_Size;
            v19 = v29->m_Outputs.m_Memory.m_nAllocationCount;
            if ( v18 + 1 > v19 )
              CUtlMemory<ColorRGBExp32,int>::Grow(
                this: (CUtlMemory<BSPCluster_t,int> *)&v29->m_Outputs,
                num: v18 - v19 + 1);
            ++v17->m_Outputs.m_Size;
            v20 = v17->m_Outputs.m_Memory.m_pMemory;
            v21 = v17->m_Outputs.m_Size - v18 - 1;
            v17->m_Outputs.m_pElements = v20;
            if ( v21 > 0 )
              _V_memmove(dest: &v20[v18 + 1], src: &v20[v18], count: 4 * v21);
            v22 = (int *)&v17->m_Outputs.m_Memory.m_pMemory[v18];
            if ( v22 != nullptr )
              *v22 = j;
          }
          ++v31;
        }
        while ( v31 < m_Size );
        v2 = v29;
      }
      if ( !v2->m_bGotSize && v3->m_bGotSize )
      {
        v2->m_bmins.x = v3->m_bmins.x;
        v2->m_bmins.y = v3->m_bmins.y;
        v2->m_bmins.z = v3->m_bmins.z;
        v2->m_bmaxs.x = v3->m_bmaxs.x;
        v2->m_bmaxs.y = v3->m_bmaxs.y;
        v2->m_bmaxs.z = v3->m_bmaxs.z;
        if ( v3->m_bGotSize )
          v2->m_bGotSize = true;
      }
      if ( !v2->m_bGotColor )
      {
        v2->m_rgbColor = v3->m_rgbColor;
        v2->m_bGotColor = true;
      }
      if ( !GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: OPERATOR, pszExpecting: nullptr) )
        return false;
      if ( _V_stricmp(s1: szToken, s2: ")") == 0 )
        return true;
      if ( _V_stricmp(s1: szToken, s2: ",") != 0 )
        break;
      result = GDGetToken(tr, pszStore: szToken, nSize: 129, ttexpecting: IDENT, pszExpecting: nullptr);
      if ( !result )
        return result;
    }
    GDError(tr, error: "expecting ',' or ')', but found %s", szToken);
  }
  return false;
}

//------------------------------------------------------------------------------
// Address: 0x00448F40
// Name: private: bool GDclass::ParseSpecifiers(class TokenReader __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall GDclass::ParseSpecifiers(GDclass *this, TokenReader *tr)
{
  char v3; // al
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF

  if ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) != IDENT )
    return 1;
  while ( 1 )
  {
    TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129);
    if ( _V_stricmp(s1: szToken, s2: "halfgridsnap") != 0 )
      break;
    this->m_bHalfGridSnap = true;
LABEL_13:
    if ( TokenReader::PeekTokenType(this: tr, pszStore: nullptr, maxlen: 0) != IDENT )
      return 1;
  }
  if ( GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "(") )
  {
    if ( _V_stricmp(s1: szToken, s2: "base") != 0 )
    {
      if ( _V_stricmp(s1: szToken, s2: "size") != 0 )
        v3 = _V_stricmp(s1: szToken, s2: "color") != 0
           ? GDclass::ParseHelper(this, tr, pszHelperName: szToken)
           : GDclass::ParseColor(this, tr);
      else
        v3 = GDclass::ParseSize(this, tr);
    }
    else
    {
      v3 = GDclass::ParseBase(this, tr);
    }
    if ( v3 != 0 )
      goto LABEL_13;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x00449050
// Name: public: int GDclass::InitFromTokens(class TokenReader __near &,class GameData __near *)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall GDclass::InitFromTokens(GDclass *this, TokenReader *tr, GameData *pGD)
{
  __int16 *v4; // eax
  int i; // ecx
  char szToken[132]; // [esp+8h] [ebp-84h] BYREF

  this->Parent = pGD;
  v4 = &this->m_VariableMap[0][1];
  for ( i = 128; i != 0; --i )
  {
    *(v4 - 1) = -1;
    *v4 = -1;
    v4 += 2;
  }
  if ( GDclass::ParseSpecifiers(this, tr) != 0
    && GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "=")
    && GDGetToken(tr, pszStore: this->m_szName, nSize: 65, ttexpecting: IDENT, pszExpecting: nullptr)
    && (TokenReader::PeekTokenType(this: tr, pszStore: szToken, maxlen: 129) != OPERATOR
     || _V_stricmp(s1: szToken, s2: ":") != 0
     || (TokenReader::NextToken(this: tr, pszStore: szToken, nSize: 129),
         free(pMem: this->m_pszDescription),
         this->m_pszDescription = nullptr,
         GDGetTokenDynamic(tr, ppszStore: &this->m_pszDescription, ttexpecting: STRING, pszExpecting: nullptr)))
    && GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "[")
    && GDclass::ParseVariables(this, tr) != 0 )
  {
    return GDSkipToken(tr, ttexpecting: OPERATOR, pszExpecting: "]");
  }
  else
  {
    return false;
  }
}

} // namespace vbsp2
