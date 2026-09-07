// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/shadercompile/cfgprocessor.cpp
// Functions: 466
// ============================================================

#include "utils\shadercompile\cfgprocessor.h"

//------------------------------------------------------------------------------
// Address: 0x10001070
// Name: public: static int std::char_traits<char>::compare(char const __near *,char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
int __cdecl std::char_traits<char>::compare(const char *_First1, const char *_First2, unsigned int _Count)
{
  unsigned int v5; // esi
  int v6; // eax

  v5 = _Count;
  if ( _Count < 4 )
  {
LABEL_4:
    if ( v5 == 0 )
      return 0;
  }
  else
  {
    while ( *(_DWORD *)_First1 == *(_DWORD *)_First2 )
    {
      v5 -= 4;
      _First2 += 4;
      _First1 += 4;
      if ( v5 < 4 )
        goto LABEL_4;
    }
  }
  v6 = *(unsigned __int8 *)_First1 - *(unsigned __int8 *)_First2;
  if ( v6 != 0 )
    return (v6 >> 31) | 1;
  if ( v5 <= 1 )
    return 0;
  v6 = *((unsigned __int8 *)_First1 + 1) - *((unsigned __int8 *)_First2 + 1);
  if ( v6 != 0 )
    return (v6 >> 31) | 1;
  if ( v5 <= 2 )
    return 0;
  v6 = *((unsigned __int8 *)_First1 + 2) - *((unsigned __int8 *)_First2 + 2);
  if ( v6 != 0 )
    return (v6 >> 31) | 1;
  if ( v5 > 3 )
  {
    v6 = *((unsigned __int8 *)_First1 + 3) - *((unsigned __int8 *)_First2 + 3);
    return (v6 >> 31) | 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100010F0
// Name: public: virtual int CExprVariable::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExprVariable::Evaluate(CExprVariable *this, IEvaluationContext *pCtx)
{
  int m_nSlot; // eax

  m_nSlot = this->m_nSlot;
  if ( m_nSlot < 0 )
    return 0;
  else
    return pCtx->GetVariableValue(this: pCtx, a2: m_nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10001110
// Name: public: virtual void CExprVariable::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprVariable::Print(CExprVariable *this, IEvaluationContext *pCtx)
{
  int m_nSlot; // eax
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  const char *v5; // [esp-4h] [ebp-4h]

  m_nSlot = this->m_nSlot;
  if ( m_nSlot < 0 )
  {
    v4 = __iob_func();
    `anonymous namespace'::OutputF(f: v4 + 1, szFmt: "$**@**");
  }
  else
  {
    v5 = pCtx->GetVariableName(this: pCtx, a2: m_nSlot);
    v3 = __iob_func();
    `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "$%s", v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001160
// Name: public: virtual int CExprUnary_Negate::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CExprUnary_Negate::Evaluate(CExprUnary_Negate *this, IEvaluationContext *pCtx)
{
  return this->m_x->Evaluate(this: this->m_x, a2: pCtx) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001180
// Name: public: virtual void CExprUnary_Negate::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprUnary_Negate::Print(CExprUnary_Negate *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "!");
  this->m_x->Print(this: this->m_x, a2: pCtx);
}

//------------------------------------------------------------------------------
// Address: 0x100011B0
// Name: public: virtual int CExprBinary_And::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CExprBinary_And::Evaluate(CExprBinary_And *this, IEvaluationContext *pCtx)
{
  return this->m_x->Evaluate(this: this->m_x, a2: pCtx) != 0 && this->m_y->Evaluate(this: this->m_y, a2: pCtx) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x100011F0
// Name: public: virtual void CExprBinary_And::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprBinary_And::Print(CExprBinary_And *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "( ");
  this->m_x->Print(this: this->m_x, a2: pCtx);
  v4 = __iob_func();
  `anonymous namespace'::OutputF(f: v4 + 1, szFmt: " && ");
  this->m_y->Print(this: this->m_y, a2: pCtx);
  v5 = __iob_func();
  `anonymous namespace'::OutputF(f: v5 + 1, szFmt: " )");
}

//------------------------------------------------------------------------------
// Address: 0x10001260
// Name: public: virtual int CExprBinary_And::Priority(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExprBinary_And::Priority(CExprBinary_And *this)
{
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10001270
// Name: public: virtual int CExprBinary_Or::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExprBinary_Or::Evaluate(CExprBinary_Or *this, IEvaluationContext *pCtx)
{
  int result; // eax

  if ( this->m_x->Evaluate(this: this->m_x, a2: pCtx) != 0 )
    return 1;
  result = this->m_y->Evaluate(this: this->m_y, a2: pCtx);
  if ( result != 0 )
    return 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100012B0
// Name: public: virtual void CExprBinary_Or::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprBinary_Or::Print(CExprBinary_Or *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "( ");
  this->m_x->Print(this: this->m_x, a2: pCtx);
  v4 = __iob_func();
  `anonymous namespace'::OutputF(f: v4 + 1, szFmt: " || ");
  this->m_y->Print(this: this->m_y, a2: pCtx);
  v5 = __iob_func();
  `anonymous namespace'::OutputF(f: v5 + 1, szFmt: " )");
}

//------------------------------------------------------------------------------
// Address: 0x10001320
// Name: public: virtual int CExprBinary_Or::Priority(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExprBinary_Or::Priority(CExprBinary_Or *this)
{
  return 2;
}

//------------------------------------------------------------------------------
// Address: 0x10001330
// Name: public: virtual int CExprBinary_Eq::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CExprBinary_Eq::Evaluate(CExprBinary_Eq *this, IEvaluationContext *pCtx)
{
  IExpression *m_x; // esi
  int v3; // ebx

  m_x = this->m_x;
  v3 = this->m_y->Evaluate(this: this->m_y, a2: pCtx);
  return m_x->Evaluate(this: m_x, a2: pCtx) == v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001370
// Name: public: virtual void CExprBinary_Eq::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprBinary_Eq::Print(CExprBinary_Eq *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "( ");
  this->m_x->Print(this: this->m_x, a2: pCtx);
  v4 = __iob_func();
  `anonymous namespace'::OutputF(f: v4 + 1, szFmt: " == ");
  this->m_y->Print(this: this->m_y, a2: pCtx);
  v5 = __iob_func();
  `anonymous namespace'::OutputF(f: v5 + 1, szFmt: " )");
}

//------------------------------------------------------------------------------
// Address: 0x100013E0
// Name: public: virtual int CExprBinary_Neq::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CExprBinary_Neq::Evaluate(CExprBinary_Neq *this, IEvaluationContext *pCtx)
{
  IExpression *m_x; // esi
  int v3; // ebx

  m_x = this->m_x;
  v3 = this->m_y->Evaluate(this: this->m_y, a2: pCtx);
  return m_x->Evaluate(this: m_x, a2: pCtx) != v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001420
// Name: public: virtual void CExprBinary_Neq::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprBinary_Neq::Print(CExprBinary_Neq *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "( ");
  this->m_x->Print(this: this->m_x, a2: pCtx);
  v4 = __iob_func();
  `anonymous namespace'::OutputF(f: v4 + 1, szFmt: " != ");
  this->m_y->Print(this: this->m_y, a2: pCtx);
  v5 = __iob_func();
  `anonymous namespace'::OutputF(f: v5 + 1, szFmt: " )");
}

//------------------------------------------------------------------------------
// Address: 0x10001490
// Name: public: virtual int CExprBinary_L::Priority(void)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExprBinary_L::Priority(ConVar *this)
{
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100014A0
// Name: public: virtual int CExprBinary_G::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CExprBinary_G::Evaluate(CExprBinary_G *this, IEvaluationContext *pCtx)
{
  IExpression *m_x; // esi
  int v3; // ebx

  m_x = this->m_x;
  v3 = this->m_y->Evaluate(this: this->m_y, a2: pCtx);
  return m_x->Evaluate(this: m_x, a2: pCtx) > v3;
}

//------------------------------------------------------------------------------
// Address: 0x100014E0
// Name: public: virtual void CExprBinary_G::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprBinary_G::Print(CExprBinary_G *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "( ");
  this->m_x->Print(this: this->m_x, a2: pCtx);
  v4 = __iob_func();
  `anonymous namespace'::OutputF(f: v4 + 1, szFmt: " > ");
  this->m_y->Print(this: this->m_y, a2: pCtx);
  v5 = __iob_func();
  `anonymous namespace'::OutputF(f: v5 + 1, szFmt: " )");
}

//------------------------------------------------------------------------------
// Address: 0x10001550
// Name: public: virtual int CExprBinary_Ge::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CExprBinary_Ge::Evaluate(CExprBinary_Ge *this, IEvaluationContext *pCtx)
{
  IExpression *m_x; // esi
  int v3; // ebx

  m_x = this->m_x;
  v3 = this->m_y->Evaluate(this: this->m_y, a2: pCtx);
  return m_x->Evaluate(this: m_x, a2: pCtx) >= v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001590
// Name: public: virtual void CExprBinary_Ge::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprBinary_Ge::Print(CExprBinary_Ge *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "( ");
  this->m_x->Print(this: this->m_x, a2: pCtx);
  v4 = __iob_func();
  `anonymous namespace'::OutputF(f: v4 + 1, szFmt: " >= ");
  this->m_y->Print(this: this->m_y, a2: pCtx);
  v5 = __iob_func();
  `anonymous namespace'::OutputF(f: v5 + 1, szFmt: " )");
}

//------------------------------------------------------------------------------
// Address: 0x10001600
// Name: public: virtual int CExprBinary_L::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CExprBinary_L::Evaluate(CExprBinary_L *this, IEvaluationContext *pCtx)
{
  IExpression *m_x; // esi
  int v3; // ebx

  m_x = this->m_x;
  v3 = this->m_y->Evaluate(this: this->m_y, a2: pCtx);
  return m_x->Evaluate(this: m_x, a2: pCtx) < v3;
}

//------------------------------------------------------------------------------
// Address: 0x10001640
// Name: public: virtual void CExprBinary_L::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprBinary_L::Print(CExprBinary_L *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "( ");
  this->m_x->Print(this: this->m_x, a2: pCtx);
  v4 = __iob_func();
  `anonymous namespace'::OutputF(f: v4 + 1, szFmt: " < ");
  this->m_y->Print(this: this->m_y, a2: pCtx);
  v5 = __iob_func();
  `anonymous namespace'::OutputF(f: v5 + 1, szFmt: " )");
}

//------------------------------------------------------------------------------
// Address: 0x100016B0
// Name: public: virtual int CExprBinary_Le::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall CExprBinary_Le::Evaluate(CExprBinary_Le *this, IEvaluationContext *pCtx)
{
  IExpression *m_x; // esi
  int v3; // ebx

  m_x = this->m_x;
  v3 = this->m_y->Evaluate(this: this->m_y, a2: pCtx);
  return m_x->Evaluate(this: m_x, a2: pCtx) <= v3;
}

//------------------------------------------------------------------------------
// Address: 0x100016F0
// Name: public: virtual void CExprBinary_Le::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprBinary_Le::Print(CExprBinary_Le *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  _iobuf *v4; // eax
  _iobuf *v5; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "( ");
  this->m_x->Print(this: this->m_x, a2: pCtx);
  v4 = __iob_func();
  `anonymous namespace'::OutputF(f: v4 + 1, szFmt: " <= ");
  this->m_y->Print(this: this->m_y, a2: pCtx);
  v5 = __iob_func();
  `anonymous namespace'::OutputF(f: v5 + 1, szFmt: " )");
}

//------------------------------------------------------------------------------
// Address: 0x10001760
// Name: public: bool ConfigurationProcessing::ComboHandleImpl::IsSkipped(void)
// Source: json
//------------------------------------------------------------------------------
BOOL __thiscall ConfigurationProcessing::ComboHandleImpl::IsSkipped(ConfigurationProcessing::ComboHandleImpl *this)
{
  return this->m_pEntry->m_pExpr->Evaluate(this: this->m_pEntry->m_pExpr, a2: this) != 0;
}

//------------------------------------------------------------------------------
// Address: 0x10001780
// Name: char __near * ConfigurationProcessing::NextLine(void)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ConfigurationProcessing::NextLine()
{
  const char *LinePtr; // eax
  _iobuf *v1; // eax
  const char *v2; // edi
  unsigned int i; // esi
  int v4; // eax

  if ( dword_101645F8 != nullptr )
  {
    LinePtr = CUtlInplaceBuffer::InplaceGetLinePtr(this: dword_101645F8);
  }
  else
  {
    if ( (_S1 & 1) != 0 )
    {
      v1 = (_iobuf *)dword_101645F0;
    }
    else
    {
      _S1 |= 1u;
      v1 = __iob_func();
      dword_101645F0 = (int)v1;
    }
    if ( v1 == nullptr )
      return nullptr;
    LinePtr = fgets(string: g_chTmpBuffer, count: 0x100000, str: v1);
  }
  v2 = LinePtr;
  if ( LinePtr == nullptr )
    return nullptr;
  for ( i = strlen(LinePtr); i != 0; v2[i] = 0 )
  {
    v4 = v2[--i];
    if ( isspace(c: v4) == 0 )
      break;
  }
  return (char *)v2;
}

//------------------------------------------------------------------------------
// Address: 0x10001810
// Name: char __near * ConfigurationProcessing::WaitFor(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__cdecl ConfigurationProcessing::WaitFor(const char *szWaitString, unsigned int nMatchLength)
{
  const char *Line; // esi

  Line = ConfigurationProcessing::NextLine();
  if ( Line == nullptr )
    return nullptr;
  while ( strncmp(first: Line, last: szWaitString, count: nMatchLength) != 0 )
  {
    Line = ConfigurationProcessing::NextLine();
    if ( Line == nullptr )
      return nullptr;
  }
  return (char *)Line;
}

//------------------------------------------------------------------------------
// Address: 0x10001850
// Name: unsigned __int64 CfgProcessor::Combo_GetCommandNum(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __cdecl CfgProcessor::Combo_GetCommandNum(CfgProcessor::<unnamed_type_ComboHandle> *hCombo)
{
  if ( hCombo != nullptr )
    return *(_QWORD *)&hCombo[8];
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001870
// Name: unsigned __int64 CfgProcessor::Combo_GetComboNum(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __cdecl CfgProcessor::Combo_GetComboNum(CfgProcessor::<unnamed_type_ComboHandle> *hCombo)
{
  if ( hCombo != nullptr )
    return *(_QWORD *)&hCombo[16];
  else
    return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10001890
// Name: struct CfgProcessor::CfgEntryInfo const __near * CfgProcessor::Combo_GetEntryInfo(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *)
// Source: json
//------------------------------------------------------------------------------
const CfgProcessor::CfgEntryInfo *__cdecl CfgProcessor::Combo_GetEntryInfo(
        CfgProcessor::<unnamed_type_ComboHandle> *hCombo)
{
  if ( hCombo != nullptr )
    return (const CfgProcessor::CfgEntryInfo *)(*(_DWORD *)&hCombo[32] + 72);
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x100018B0
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Max(struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Max(
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100018D0
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Min(struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Min(
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100018F0
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Max(struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Max(
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001920
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *i; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( this->_Ptr->_Isnil == 0 )
  {
    Right = Ptr->_Right;
    if ( Right->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Right )
          break;
        result->_Ptr = i;
      }
      result->_Ptr = i;
    }
    else
    {
      for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
        Right = j;
      result->_Ptr = Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001970
// Name: protected: void std::_Tree<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Rrotate(struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Rrotate(
        std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *this,
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Parent; // ecx

  Left = _Wherenode->_Left;
  _Wherenode->_Left = _Wherenode->_Left->_Right;
  Right = Left->_Right;
  if ( Right->_Isnil == 0 )
    Right->_Parent = _Wherenode;
  Left->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Right )
      Parent->_Right = Left;
    else
      Parent->_Left = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100019D0
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Min(struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Min(
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100019F0
// Name: protected: void std::_Tree<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Rrotate(
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Parent; // ecx

  Left = _Wherenode->_Left;
  _Wherenode->_Left = _Wherenode->_Left->_Right;
  Right = Left->_Right;
  if ( Right->_Isnil == 0 )
    Right->_Parent = _Wherenode;
  Left->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Right )
      Parent->_Right = Left;
    else
      Parent->_Left = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001A50
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Max(struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Max(
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001A70
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Min(struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Min(
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001A90
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *j; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *i; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( this->_Ptr->_Isnil == 0 )
  {
    Right = Ptr->_Right;
    if ( Right->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Right )
          break;
        result->_Ptr = i;
      }
      result->_Ptr = i;
    }
    else
    {
      for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
        Right = j;
      result->_Ptr = Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001AF0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *i; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( this->_Ptr->_Isnil == 0 )
  {
    Right = Ptr->_Right;
    if ( Right->_Isnil != 0 )
    {
      for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
      {
        if ( result->_Ptr != i->_Right )
          break;
        result->_Ptr = i;
      }
      result->_Ptr = i;
    }
    else
    {
      for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
        Right = j;
      result->_Ptr = Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001B60
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v5; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( Ptr->_Isnil != 0 )
  {
    result->_Ptr = Ptr->_Right;
    return result;
  }
  Left = Ptr->_Left;
  if ( Ptr->_Left->_Isnil == 0 )
  {
    Right = Left->_Right;
    if ( Right->_Isnil == 0 )
    {
      do
      {
        v5 = Right;
        Right = Right->_Right;
      }
      while ( Right->_Isnil == 0 );
      result->_Ptr = v5;
      return result;
    }
LABEL_11:
    result->_Ptr = Left;
    return result;
  }
  for ( Left = Ptr->_Parent; Left->_Isnil == 0; Left = Left->_Parent )
  {
    if ( result->_Ptr != Left->_Left )
      break;
    result->_Ptr = Left;
  }
  if ( result->_Ptr->_Isnil == 0 )
    goto LABEL_11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001BC0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v5; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( Ptr->_Isnil != 0 )
  {
    result->_Ptr = Ptr->_Right;
    return result;
  }
  Left = Ptr->_Left;
  if ( Ptr->_Left->_Isnil == 0 )
  {
    Right = Left->_Right;
    if ( Right->_Isnil == 0 )
    {
      do
      {
        v5 = Right;
        Right = Right->_Right;
      }
      while ( Right->_Isnil == 0 );
      result->_Ptr = v5;
      return result;
    }
LABEL_11:
    result->_Ptr = Left;
    return result;
  }
  for ( Left = Ptr->_Parent; Left->_Isnil == 0; Left = Left->_Parent )
  {
    if ( result->_Ptr != Left->_Left )
      break;
    result->_Ptr = Left;
  }
  if ( result->_Ptr->_Isnil == 0 )
    goto LABEL_11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001C20
// Name: public: virtual int CExprConstant::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CExprConstant::Evaluate(CExprConstant *this, IEvaluationContext *pCtx)
{
  return this->m_value;
}

//------------------------------------------------------------------------------
// Address: 0x10001C30
// Name: public: virtual void CExprConstant::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CExprConstant::Print(CExprConstant *this, IEvaluationContext *pCtx)
{
  _iobuf *v2; // eax
  int m_value; // [esp-4h] [ebp-4h]

  m_value = this->m_value;
  v2 = __iob_func();
  `anonymous namespace'::OutputF(f: v2 + 1, szFmt: "%d", m_value);
}

//------------------------------------------------------------------------------
// Address: 0x10001C50
// Name: public: int std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::compare(unsigned int,unsigned int,char const __near *,unsigned int)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall std::string::compare(
        std::string *this,
        unsigned int _Off,
        unsigned int _N0,
        const char *_Ptr,
        unsigned int _Count)
{
  unsigned int Mysize; // eax
  unsigned int v6; // esi
  unsigned int v7; // eax
  unsigned int v8; // edx
  std::string *Ptr; // eax
  int result; // eax

  Mysize = this->_Mysize;
  if ( Mysize < _Off )
    std::_Xout_of_range(_Message: "invalid string position");
  v6 = _N0;
  v7 = Mysize - _Off;
  if ( v7 < _N0 )
    v6 = v7;
  v8 = v6;
  if ( v6 >= _Count )
    v8 = _Count;
  if ( this->_Myres < 0x10 )
    Ptr = this;
  else
    Ptr = (std::string *)this->_Bx._Ptr;
  result = std::char_traits<char>::compare(_First1: &Ptr->_Bx._Buf[_Off], _First2: _Ptr, _Count: v8);
  if ( result == 0 )
  {
    if ( v6 >= _Count )
      return v6 != _Count;
    else
      return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001CC0
// Name: public: char __near * std::allocator<char>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall std::allocator<char>::allocate(std::allocator<char> *this, unsigned int _Count)
{
  char *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 )
  {
    result = (char *)operator new(nSize: _Count);
    if ( result == nullptr )
    {
      _Count = 0;
      std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
      pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
      _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001D10
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v5; // edx

  result = this;
  Ptr = this->_Ptr;
  if ( Ptr->_Isnil != 0 )
  {
    result->_Ptr = Ptr->_Right;
    return result;
  }
  Left = Ptr->_Left;
  if ( Ptr->_Left->_Isnil == 0 )
  {
    Right = Left->_Right;
    if ( Right->_Isnil == 0 )
    {
      do
      {
        v5 = Right;
        Right = Right->_Right;
      }
      while ( Right->_Isnil == 0 );
      result->_Ptr = v5;
      return result;
    }
LABEL_11:
    result->_Ptr = Left;
    return result;
  }
  for ( Left = Ptr->_Parent; Left->_Isnil == 0; Left = Left->_Parent )
  {
    if ( result->_Ptr != Left->_Left )
      break;
    result->_Ptr = Left;
  }
  if ( result->_Ptr->_Isnil == 0 )
    goto LABEL_11;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001D90
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::erase(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::erase(std::string *this, unsigned int _Off, unsigned int _Count)
{
  unsigned int Mysize; // eax
  unsigned int v5; // edi
  unsigned int v6; // eax
  unsigned int Myres; // edx
  std::string *Ptr; // ebx
  std::string *v9; // edx
  unsigned int v10; // eax
  bool v11; // cf

  Mysize = this->_Mysize;
  if ( Mysize < _Off )
    std::_Xout_of_range(_Message: "invalid string position");
  v5 = _Count;
  v6 = Mysize - _Off;
  if ( v6 < _Count )
    v5 = v6;
  if ( v5 != 0 )
  {
    Myres = this->_Myres;
    if ( Myres < 0x10 )
      Ptr = this;
    else
      Ptr = (std::string *)this->_Bx._Ptr;
    if ( Myres < 0x10 )
      v9 = this;
    else
      v9 = (std::string *)this->_Bx._Ptr;
    memmove(
      dst: (unsigned __int8 *)&v9->_Bx._Buf[_Off],
      src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Off + v5],
      count: v6 - v5);
    v10 = this->_Mysize - v5;
    v11 = this->_Myres < 0x10;
    this->_Mysize = v10;
    if ( !v11 )
    {
      this->_Bx._Ptr[v10] = 0;
      return this;
    }
    this->_Bx._Buf[v10] = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10001E20
// Name: protected: void std::_Tree<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Lrotate(
        std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Parent; // ecx

  Right = _Wherenode->_Right;
  _Wherenode->_Right = Right->_Left;
  if ( Right->_Left->_Isnil == 0 )
    Right->_Left->_Parent = _Wherenode;
  Right->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Left )
      Parent->_Left = Right;
    else
      Parent->_Right = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001E80
// Name: protected: void std::_Tree<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Rrotate(
        std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Parent; // ecx

  Left = _Wherenode->_Left;
  _Wherenode->_Left = _Wherenode->_Left->_Right;
  Right = Left->_Right;
  if ( Right->_Isnil == 0 )
    Right->_Parent = _Wherenode;
  Left->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Right )
      Parent->_Right = Left;
    else
      Parent->_Left = Left;
    Left->_Right = _Wherenode;
    _Wherenode->_Parent = Left;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001EE0
// Name: public: class Define __near * std::allocator<class Define>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
Define *__thiscall std::allocator<Define>::allocate(std::allocator<Define> *this, unsigned int _Count)
{
  Define *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x6666666 || (result = (Define *)operator new(nSize: 40 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10001F40
// Name: protected: void std::_Tree<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Lrotate(struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Lrotate(
        std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *this,
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Parent; // ecx

  Right = _Wherenode->_Right;
  _Wherenode->_Right = Right->_Left;
  if ( Right->_Left->_Isnil == 0 )
    Right->_Left->_Parent = _Wherenode;
  Right->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Left )
      Parent->_Left = Right;
    else
      Parent->_Right = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10001FA0
// Name: protected: void std::_Tree<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Lrotate(
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Parent; // ecx

  Right = _Wherenode->_Right;
  _Wherenode->_Right = Right->_Left;
  if ( Right->_Left->_Isnil == 0 )
    Right->_Left->_Parent = _Wherenode;
  Right->_Parent = _Wherenode->_Parent;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead->_Parent )
  {
    Myhead->_Parent = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
  else
  {
    Parent = _Wherenode->_Parent;
    if ( _Wherenode == Parent->_Left )
      Parent->_Left = Right;
    else
      Parent->_Right = Right;
    Right->_Left = _Wherenode;
    _Wherenode->_Parent = Right;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002000
// Name: public: class IExpression __near * __near * std::allocator<class IExpression __near *>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *__thiscall std::allocator<IExpression *>::allocate(
        std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *this,
        unsigned int _Count)
{
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0
    && (_Count > 0x3FFFFFFF
     || (result = (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)operator new(nSize: 4 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10002060
// Name: void std::fill<char __near *,char>(char __near *,char __near *,char const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::fill<char *,char>(char *_First, char *_Last, char *_Val)
{
  char *i; // eax

  for ( i = _First; i != _Last; ++i )
    *i = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x10002080
// Name: void std::fill<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>(class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::fill<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_First,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Last,
        const std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Val)
{
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *i; // eax

  for ( i = _First; i != _Last; ++i )
    i->_Ptr = _Val->_Ptr;
}

//------------------------------------------------------------------------------
// Address: 0x100020A0
// Name: class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near * std::_Copy_backward<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *>(class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *)
// Source: json
//------------------------------------------------------------------------------
std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *__cdecl std::_Copy_backward<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *>(
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_First,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Last,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Dest)
{
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v3; // ecx
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *result; // eax
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Ptr; // esi

  v3 = _Last;
  for ( result = _Dest; v3 != _First; result->_Ptr = Ptr )
  {
    Ptr = v3[-1]._Ptr;
    --v3;
    --result;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100020D0
// Name: protected: bool std::vector<int,class std::allocator<int>>::_Buy(unsigned int)
// Source: json
//------------------------------------------------------------------------------
char __thiscall std::vector<int>::_Buy(std::vector<int> *this, unsigned int _Capacity)
{
  int *v4; // eax

  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
  if ( _Capacity == 0 )
    return 0;
  if ( _Capacity > 0x3FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  v4 = (int *)std::allocator<IExpression *>::allocate(
                this: (std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *)&this->_Alval,
                _Count: _Capacity);
  this->_Myfirst = v4;
  this->_Mylast = v4;
  this->_Myend = &v4[_Capacity];
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x10002120
// Name: protected: void std::vector<int,class std::allocator<int>>::_Tidy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<int>::_Tidy(std::vector<int> *this)
{
  if ( this->_Myfirst != nullptr )
    free(pMem: this->_Myfirst);
  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002150
// Name: public: unsigned int stdext::hash_compare<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>::operator()(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall stdext::hash_compare<std::string,std::less<std::string>>::operator()(
        stdext::hash_compare<std::string,std::less<std::string > > *this,
        const std::string *_Keyval)
{
  const std::string *Ptr; // ecx
  const std::string *v3; // edx
  int i; // eax
  int v5; // esi
  _ldiv_t v6; // rax

  if ( _Keyval->_Myres < 0x10 )
    Ptr = _Keyval;
  else
    Ptr = (const std::string *)_Keyval->_Bx._Ptr;
  v3 = (const std::string *)((char *)Ptr + _Keyval->_Mysize);
  for ( i = -2128831035; Ptr != v3; i = v5 ^ (16777619 * i) )
  {
    v5 = Ptr->_Bx._Buf[0];
    Ptr = (const std::string *)((char *)Ptr + 1);
  }
  v6 = ldiv(numer: i & 0x7FFFFFFF, denom: 127773);
  return 16807 * v6.rem - 2836 * v6.quot + (16807 * v6.rem - 2836 * v6.quot < 0 ? 0x7FFFFFFF : 0);
}

//------------------------------------------------------------------------------
// Address: 0x100021B0
// Name: public: void std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::_Copy(unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::string::_Copy(std::string *this, unsigned int _Newsize, unsigned int _Oldlen)
{
  std::string *v3; // esi
  unsigned int v4; // edi
  unsigned int Myres; // ebx
  unsigned int v6; // ecx
  char *v7; // ebx
  unsigned int v8; // ecx
  unsigned __int8 *Ptr; // eax
  int v10; // [esp+0h] [ebp-24h] BYREF
  char *_Ptr; // [esp+Ch] [ebp-18h]
  std::string *v12; // [esp+10h] [ebp-14h]
  int *v13; // [esp+14h] [ebp-10h]
  int v14; // [esp+20h] [ebp-4h]

  v13 = &v10;
  v3 = this;
  v12 = this;
  v4 = _Newsize | 0xF;
  if ( (_Newsize | 0xF) == 0xFFFFFFFF )
  {
    v4 = _Newsize;
  }
  else
  {
    Myres = this->_Myres;
    v6 = Myres >> 1;
    if ( Myres >> 1 > v4 / 3 )
    {
      v4 = v6 + Myres;
      if ( Myres > -2 - v6 )
        v4 = -2;
    }
  }
  v14 = 0;
  v7 = std::allocator<char>::allocate(this: &v3->_Alval, _Count: v4 + 1);
  _Ptr = v7;
  v14 = -1;
  v8 = _Oldlen;
  if ( _Oldlen != 0 )
  {
    if ( v3->_Myres < 0x10 )
      Ptr = (unsigned __int8 *)v3;
    else
      Ptr = (unsigned __int8 *)v3->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)v7, src: Ptr, count: _Oldlen);
    v8 = _Oldlen;
  }
  if ( v3->_Myres >= 0x10 )
  {
    free(pMem: v3->_Bx._Ptr);
    v8 = _Oldlen;
  }
  v3->_Bx._Buf[0] = 0;
  v3->_Bx._Ptr = v7;
  v3->_Myres = v4;
  v3->_Mysize = v8;
  if ( v4 >= 0x10 )
    v3 = (std::string *)v7;
  v3->_Bx._Buf[v8] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x100022F0
// Name: protected: char __near * std::vector<char,class std::allocator<char>>::_Umove<char __near *>(char __near *,char __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall std::vector<char>::_Umove<char *>(std::vector<char> *this, char *_First, char *_Last, char *_Ptr)
{
  int v4; // eax

  memmove(dst: (unsigned __int8 *)_Ptr, src: (unsigned __int8 *)_First, count: _Last - _First);
  return (char *)(_Last - _First + v4);
}

//------------------------------------------------------------------------------
// Address: 0x10002320
// Name: protected: class CExprBinary __near * __near * std::vector<class CExprBinary __near *,class std::allocator<class CExprBinary __near *>>::_Umove<class CExprBinary __near * __near *>(class CExprBinary __near * __near *,class CExprBinary __near * __near *,class CExprBinary __near * __near *)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall std::vector<CExprBinary *>::_Umove<CExprBinary * *>(
        std::vector<int> *this,
        int *_First,
        int *_Last,
        int *_Ptr)
{
  int v4; // eax

  memmove(dst: (unsigned __int8 *)_Ptr, src: (unsigned __int8 *)_First, count: 4 * (_Last - _First));
  return (int *)(4 * (_Last - _First) + v4);
}

//------------------------------------------------------------------------------
// Address: 0x10002350
// Name: protected: struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near * std::_Tree<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Lbound(unsigned __int64 const __near &)const
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *__thiscall std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Lbound(
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        const unsigned __int64 *_Keyval)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Parent; // ecx

  result = this->_Myhead;
  Parent = result->_Parent;
  while ( Parent->_Isnil == 0 )
  {
    if ( Parent->_Myval.first >= *_Keyval )
    {
      result = Parent;
      Parent = Parent->_Left;
    }
    else
    {
      Parent = Parent->_Right;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100023A0
// Name: void (*std::_For_each<class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>,struct std::_Iterator_base0>,void (*)(class ConfigurationProcessing::CfgEntry const __near &)>(class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>,struct std::_Iterator_base0>,class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>,struct std::_Iterator_base0>,void (*)(class ConfigurationProcessing::CfgEntry const __near &)))(class ConfigurationProcessing::CfgEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
void (__cdecl *__cdecl std::_For_each<std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>,void (__cdecl *)(ConfigurationProcessing::CfgEntry const &)>(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> _First,
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> _Last,
        void (__cdecl *_Func)(const ConfigurationProcessing::CfgEntry *)))(const ConfigurationProcessing::CfgEntry *)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *j; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *i; // eax

  Ptr = _First._Ptr;
  if ( _First._Ptr == _Last._Ptr )
    return _Func;
  do
  {
    _Func(a1: &Ptr->_Myval);
    Ptr = _First._Ptr;
    if ( _First._Ptr->_Isnil == 0 )
    {
      Right = _First._Ptr->_Right;
      if ( Right->_Isnil != 0 )
      {
        for ( i = _First._Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
        {
          if ( Ptr != i->_Right )
            break;
          Ptr = i;
        }
        Ptr = i;
      }
      else
      {
        Ptr = _First._Ptr->_Right;
        for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
          Ptr = j;
      }
      _First._Ptr = Ptr;
    }
  }
  while ( Ptr != _Last._Ptr );
  return _Func;
}

//------------------------------------------------------------------------------
// Address: 0x10002430
// Name: void std::_Cons_val<class std::allocator<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>(class std::allocator<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>> __near &,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
        std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *_Alval,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Pdest,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Src)
{
  if ( _Pdest != nullptr )
    _Pdest->_Ptr = _Src->_Ptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002450
// Name: public: unsigned __int64 ComboGenerator::NumCombos(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ComboGenerator::NumCombos(ComboGenerator *this)
{
  Define *Myfirst; // edi
  int v2; // esi
  int v3; // ebx
  __int64 v4; // kr00_8
  int *p_m_min; // edi
  bool v6; // cc
  __int64 v7; // rax

  Myfirst = this->m_arrDefines._Myfirst;
  v2 = this->m_arrDefines._Mylast - Myfirst;
  v3 = 0;
  v4 = 1;
  if ( v2 > 0 )
  {
    p_m_min = &Myfirst->m_min;
    v6 = v2 == 0;
    do
    {
      if ( v6 )
        std::_Xout_of_range(_Message: "invalid vector<T> subscript");
      v7 = (p_m_min[1] - *p_m_min + 1) * v4;
      ++v3;
      p_m_min += 10;
      v4 = v7;
      v6 = v2 <= (unsigned int)v3;
    }
    while ( v2 > v3 );
  }
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100024D0
// Name: public: unsigned __int64 ComboGenerator::NumCombos(bool)
// Source: json
//------------------------------------------------------------------------------
unsigned __int64 __thiscall ComboGenerator::NumCombos(ComboGenerator *this, bool bStaticCombos)
{
  Define *Myfirst; // edi
  int v3; // ebx
  int v4; // esi
  int *p_m_max; // edi
  bool v6; // cc
  unsigned __int64 numCombos; // [esp+Ch] [ebp-8h]

  Myfirst = this->m_arrDefines._Myfirst;
  v3 = 0;
  v4 = this->m_arrDefines._Mylast - Myfirst;
  numCombos = 1;
  if ( v4 > 0 )
  {
    p_m_max = &Myfirst->m_max;
    v6 = v4 == 0;
    do
    {
      if ( v6 )
        std::_Xout_of_range(_Message: "invalid vector<T> subscript");
      if ( *((_BYTE *)p_m_max + 4) == bStaticCombos )
        numCombos *= *p_m_max - *(p_m_max - 1) + 1;
      ++v3;
      p_m_max += 10;
      v6 = v4 <= (unsigned int)v3;
    }
    while ( v4 > v3 );
  }
  return numCombos;
}

//------------------------------------------------------------------------------
// Address: 0x10002550
// Name: public: bool ConfigurationProcessing::ComboHandleImpl::AdvanceCommands(unsigned __int64 __near &)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ConfigurationProcessing::ComboHandleImpl::AdvanceCommands(
        ConfigurationProcessing::ComboHandleImpl *this,
        unsigned __int64 *riAdvanceMore)
{
  int *Mylast; // eax
  int *Myfirst; // edx
  int *v6; // edi
  ComboGenerator *m_pCg; // eax
  Define *v8; // edx
  Define *v9; // ebx
  unsigned int v10; // edx
  unsigned int m_iComboNumber_high; // eax
  unsigned int m_iComboNumber; // edx
  bool v13; // cf
  int *v14; // ebx
  int v15; // eax
  unsigned __int64 v16; // [esp+4h] [ebp-Ch]
  int *pnValuesEnd; // [esp+Ch] [ebp-4h]
  unsigned __int64 *riAdvanceMorea; // [esp+18h] [ebp+8h]

  v16 = *riAdvanceMore;
  if ( *riAdvanceMore == 0 )
    return 1;
  Mylast = this->m_arrVarSlots._Mylast;
  Myfirst = this->m_arrVarSlots._Myfirst;
  if ( Myfirst == Mylast )
  {
    v6 = nullptr;
  }
  else
  {
    if ( Mylast - Myfirst == 0 )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    v6 = this->m_arrVarSlots._Myfirst;
  }
  pnValuesEnd = &v6[Mylast - Myfirst];
  m_pCg = this->m_pEntry->m_pCg;
  v8 = m_pCg->m_arrDefines._Mylast;
  v9 = m_pCg->m_arrDefines._Myfirst;
  if ( v9 == v8 )
  {
    riAdvanceMorea = nullptr;
  }
  else
  {
    v10 = (int)((unsigned __int64)(1717986919LL * ((char *)v8 - (char *)v9)) >> 32) >> 4;
    if ( v10 + (v10 >> 31) == 0 )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    riAdvanceMorea = (unsigned __int64 *)m_pCg->m_arrDefines._Myfirst;
  }
  m_iComboNumber_high = HIDWORD(this->m_iComboNumber);
  m_iComboNumber = this->m_iComboNumber;
  if ( __PAIR64__(m_iComboNumber_high, m_iComboNumber) >= v16 )
  {
    v13 = __CFADD__((_DWORD)v16, this->m_iTotalCommand);
    LODWORD(this->m_iTotalCommand) += v16;
    HIDWORD(this->m_iTotalCommand) += HIDWORD(v16) + v13;
    this->m_iComboNumber = __PAIR64__(m_iComboNumber_high, m_iComboNumber) - *riAdvanceMore;
    if ( v6 < pnValuesEnd )
    {
      v14 = (int *)(riAdvanceMorea + 4);
      do
      {
        if ( *((_DWORD *)riAdvanceMore + 1) == 0 && *(_DWORD *)riAdvanceMore == 0 )
          break;
        *riAdvanceMore += *v14 - *v6;
        *v6 = *v14;
        v15 = *v14 - *(v14 - 1) + 1;
        *v6++ -= *riAdvanceMore % v15;
        v14 += 10;
        *riAdvanceMore /= (unsigned __int64)v15;
      }
      while ( v6 < pnValuesEnd );
    }
    return 1;
  }
  else
  {
    *riAdvanceMore = v16 - __PAIR64__(m_iComboNumber_high, m_iComboNumber);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100026A0
// Name: public: bool ConfigurationProcessing::ComboHandleImpl::NextNotSkipped(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ConfigurationProcessing::ComboHandleImpl::NextNotSkipped(
        ConfigurationProcessing::ComboHandleImpl *this,
        unsigned __int64 iTotalCommand)
{
  int *Myfirst; // ecx
  int *Mylast; // eax
  int *v5; // edi
  ComboGenerator *m_pCg; // eax
  Define *v7; // ecx
  Define *v8; // eax
  Define *v9; // ebx
  unsigned int m_iComboNumber; // eax
  unsigned int m_iComboNumber_high; // ecx
  bool v12; // cf
  int *v13; // eax
  int *p_m_max; // ecx
  int *pnValuesEnd; // [esp+Ch] [ebp-4h]

  Myfirst = this->m_arrVarSlots._Myfirst;
  Mylast = this->m_arrVarSlots._Mylast;
  if ( Myfirst == Mylast )
  {
    v5 = nullptr;
  }
  else
  {
    if ( Mylast - Myfirst == 0 )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    v5 = Myfirst;
  }
  pnValuesEnd = &v5[Mylast - Myfirst];
  m_pCg = this->m_pEntry->m_pCg;
  v7 = m_pCg->m_arrDefines._Myfirst;
  v8 = m_pCg->m_arrDefines._Mylast;
  if ( v7 == v8 )
  {
    v9 = nullptr;
  }
  else
  {
    if ( v8 - v7 == 0 )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    v9 = v7;
  }
  if ( this->m_iTotalCommand + 1 < iTotalCommand )
  {
next_combo_iteration:
    m_iComboNumber = this->m_iComboNumber;
    m_iComboNumber_high = HIDWORD(this->m_iComboNumber);
    if ( this->m_iComboNumber != 0 )
    {
      v12 = __CFADD__(LODWORD(this->m_iTotalCommand)++, 1);
      this->m_iComboNumber = __PAIR64__(m_iComboNumber_high, m_iComboNumber) - 1;
      HIDWORD(this->m_iTotalCommand) += v12;
      v13 = v5;
      p_m_max = &v9->m_max;
      while ( v13 < pnValuesEnd )
      {
        if ( --*v13 >= *(p_m_max - 1) )
        {
          if ( this->m_pEntry->m_pExpr->Evaluate(this: this->m_pEntry->m_pExpr, a2: this) == 0 )
            return 1;
          if ( this->m_iTotalCommand + 1 < iTotalCommand )
            goto next_combo_iteration;
          return 0;
        }
        *v13++ = *p_m_max;
        p_m_max += 10;
      }
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100027B0
// Name: public: void ConfigurationProcessing::ComboHandleImpl::FormatCommand(char __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ConfigurationProcessing::ComboHandleImpl::FormatCommand(
        ConfigurationProcessing::ComboHandleImpl *this,
        char *pchBuffer)
{
  int *Myfirst; // ecx
  int *Mylast; // eax
  int *v5; // edi
  const ConfigurationProcessing::CfgEntry *m_pEntry; // esi
  ComboGenerator *m_pCg; // eax
  Define *v8; // ecx
  Define *v9; // eax
  const char *Buf; // eax
  char *v11; // esi
  Define *v12; // ebx
  char *i; // esi
  Define *v14; // eax
  const char *v15; // eax
  Define *Ptr; // [esp-8h] [ebp-20h]
  ConfigurationProcessing::ComboHandleImpl *v17; // [esp+Ch] [ebp-Ch]
  int *pnValuesEnd; // [esp+10h] [ebp-8h]
  Define *v19; // [esp+14h] [ebp-4h]

  Myfirst = this->m_arrVarSlots._Myfirst;
  Mylast = this->m_arrVarSlots._Mylast;
  v17 = this;
  if ( Myfirst == Mylast )
  {
    v5 = nullptr;
  }
  else
  {
    if ( Mylast - Myfirst == 0 )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    v5 = Myfirst;
  }
  m_pEntry = this->m_pEntry;
  pnValuesEnd = &v5[Mylast - Myfirst];
  m_pCg = m_pEntry->m_pCg;
  v8 = m_pCg->m_arrDefines._Myfirst;
  v9 = m_pCg->m_arrDefines._Mylast;
  if ( v8 == v9 )
  {
    v19 = nullptr;
  }
  else
  {
    if ( v9 - v8 == 0 )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    v19 = v8;
  }
  Buf = m_pEntry->m_sPrefix._Bx._Buf;
  if ( m_pEntry->m_sPrefix._Myres >= 0x10 )
    Buf = *(const char **)Buf;
  sprintf(string: pchBuffer, format: "%s ", Buf);
  v11 = &pchBuffer[strlen(pchBuffer)];
  if ( g_bIsPS3 )
    sprintf(string: v11, format: "-DSHADERCOMBO=%d ", LODWORD(this->m_iComboNumber));
  else
    sprintf(string: v11, format: "/DSHADERCOMBO=%d ", LODWORD(this->m_iComboNumber));
  v12 = v19;
  for ( i = &v11[strlen(v11)]; v5 < pnValuesEnd; ++v12 )
  {
    if ( g_bIsPS3 )
    {
      if ( v12->m_sName._Myres < 0x10 )
        Ptr = v12;
      else
        Ptr = (Define *)v12->m_sName._Bx._Ptr;
      sprintf(string: i, format: "-D%s=%d ", Ptr, *v5);
    }
    else
    {
      if ( v12->m_sName._Myres < 0x10 )
        v14 = v12;
      else
        v14 = (Define *)v12->m_sName._Bx._Ptr;
      sprintf(string: i, format: "/D%s=%d ", v14, *v5);
    }
    ++v5;
    i += strlen(i);
  }
  v15 = v17->m_pEntry->m_sSuffix._Bx._Buf;
  if ( v17->m_pEntry->m_sSuffix._Myres >= 0x10 )
    v15 = *(const char **)v15;
  sprintf(string: i, format: "%s\n", v15);
}

//------------------------------------------------------------------------------
// Address: 0x10002930
// Name: void CfgProcessor::Combo_FormatCommand(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *,char __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CfgProcessor::Combo_FormatCommand(CfgProcessor::<unnamed_type_ComboHandle> *hCombo, char *pchBuffer)
{
  ConfigurationProcessing::ComboHandleImpl::FormatCommand(
    this: (ConfigurationProcessing::ComboHandleImpl *)hCombo,
    pchBuffer);
}

//------------------------------------------------------------------------------
// Address: 0x10002950
// Name: protected: struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near * std::_Tree<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Lbound(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *__thiscall std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Lbound(
        std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        const std::string *_Keyval)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Parent; // edi
  const std::string *Ptr; // edx
  unsigned int Mysize; // ebx
  const char *Buf; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // sf
  unsigned int Myres; // [esp+4h] [ebp-8h]
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Wherenode; // [esp+8h] [ebp-4h]

  result = this->_Myhead;
  Parent = result->_Parent;
  _Wherenode = result;
  if ( Parent->_Isnil == 0 )
  {
    Ptr = _Keyval;
    Mysize = _Keyval->_Mysize;
    Myres = _Keyval->_Myres;
    while ( 1 )
    {
      Buf = Parent->_Myval._Bx._Buf;
      if ( Myres >= 0x10 )
        Ptr = (const std::string *)Ptr->_Bx._Ptr;
      v7 = Parent->_Myval._Mysize;
      v8 = v7;
      if ( v7 >= Mysize )
        v8 = Mysize;
      if ( Parent->_Myval._Myres >= 0x10 )
        Buf = *(const char **)Buf;
      v9 = std::char_traits<char>::compare(_First1: Buf, _First2: Ptr->_Bx._Buf, _Count: v8);
      v10 = v9 < 0;
      if ( v9 == 0 )
      {
        if ( v7 < Mysize )
          goto LABEL_14;
        LOBYTE(v9) = v7 != Mysize;
        v10 = v9 < 0;
      }
      if ( v10 )
      {
LABEL_14:
        Parent = Parent->_Right;
        goto LABEL_16;
      }
      _Wherenode = Parent;
      Parent = Parent->_Left;
LABEL_16:
      if ( Parent->_Isnil != 0 )
        return _Wherenode;
      Ptr = _Keyval;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100029E0
// Name: protected: char __near * std::vector<char,class std::allocator<char>>::_Ufill(char __near *,unsigned int,char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall std::vector<char>::_Ufill(std::vector<char> *this, char *_Ptr, unsigned int _Count, const char *_Pval)
{
  unsigned int v4; // eax
  char *i; // ecx

  v4 = _Count;
  for ( i = _Ptr; v4 != 0; --v4 )
    *i++ = *_Pval;
  return &_Ptr[_Count];
}

//------------------------------------------------------------------------------
// Address: 0x10002A10
// Name: public: void std::vector<int,class std::allocator<int>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<int>::reserve(std::vector<int> *this, unsigned int _Count)
{
  int *v3; // ebx
  int v4; // edi
  int v5; // [esp+0h] [ebp-20h] BYREF
  int *_Ptr; // [esp+Ch] [ebp-14h]
  int *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( _Count > 0x3FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = (int *)std::allocator<IExpression *>::allocate(
                  this: (std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *)&this->_Alval,
                  _Count);
    _Ptr = v3;
    v8 = 0;
    std::vector<CExprBinary *>::_Umove<CExprBinary * *>(this, _First: this->_Myfirst, _Last: this->_Mylast, _Ptr: v3);
    v8 = -1;
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      free(pMem: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = &v3[v4];
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002AD0
// Name: public: void std::list<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>::_Splice_same(class std::_List_const_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>,class std::list<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>> __near &,class std::_List_const_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>,class std::_List_const_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>,unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::list<std::pair<std::string const,int>>::_Splice_same(
        std::list<std::pair<std::string const ,int>> *this,
        std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> > _Where,
        std::list<std::pair<std::string const ,int>> *_Right,
        std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> > _First,
        std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> > _Last,
        unsigned int _Count)
{
  unsigned int Mysize; // edx
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Prev; // ecx

  if ( this != _Right )
  {
    Mysize = this->_Mysize;
    if ( 134217726 - Mysize < _Count )
      std::_Xlength_error(_Message: "list<T> too long");
    this->_Mysize = _Count + Mysize;
    _Right->_Mysize -= _Count;
  }
  _First._Ptr->_Prev->_Next = _Last._Ptr;
  _Last._Ptr->_Prev->_Next = _Where._Ptr;
  _Where._Ptr->_Prev->_Next = _First._Ptr;
  Prev = _Where._Ptr->_Prev;
  _Where._Ptr->_Prev = _Last._Ptr->_Prev;
  _Last._Ptr->_Prev = _First._Ptr->_Prev;
  _First._Ptr->_Prev = Prev;
}

//------------------------------------------------------------------------------
// Address: 0x10002B50
// Name: void std::_Uninit_fill_n<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,unsigned int,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>,class std::allocator<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>(class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,unsigned int,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> const __near *,class std::allocator<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>> __near &,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Uninit_fill_n<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,unsigned int,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>,std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_First,
        unsigned int _Count,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Pval,
        std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *_Al)
{
  _DWORD v6[7]; // [esp+0h] [ebp-1Ch] BYREF

  v6[3] = v6;
  v6[6] = 0;
  while ( _Count != 0 )
  {
    std::_Cons_val<std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
      _Alval: _Al,
      _Pdest: _First,
      _Src: _Pval);
    --_Count;
    ++_First;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10002BC0
// Name: int __near * std::_Uninit_copy<class std::_Vector_const_iterator<class std::_Vector_val<int,class std::allocator<int>>>,int __near *,class std::allocator<int>>(class std::_Vector_const_iterator<class std::_Vector_val<int,class std::allocator<int>>>,class std::_Vector_const_iterator<class std::_Vector_val<int,class std::allocator<int>>>,int __near *,class std::allocator<int> __near &,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
int *__cdecl std::_Uninit_copy<std::_Vector_const_iterator<std::_Vector_val<int>>,int *,std::allocator<int>>(
        std::_Vector_const_iterator<std::_Vector_val<int> > _First,
        std::_Vector_const_iterator<std::_Vector_val<int> > _Last,
        int *_Dest,
        std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *_Al)
{
  int *i; // eax
  _DWORD v7[7]; // [esp+0h] [ebp-1Ch] BYREF

  v7[3] = v7;
  v7[6] = 0;
  for ( i = _First._Ptr; i != _Last._Ptr; i = ++_First._Ptr )
    std::_Cons_val<std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
      _Alval: _Al,
      _Pdest: (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)_Dest++,
      _Src: (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)i);
  return _Dest;
}

//------------------------------------------------------------------------------
// Address: 0x10002C40
// Name: class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near * std::_Uninit_move<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::allocator<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>(class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::allocator<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>> __near &,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *__cdecl std::_Uninit_move<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_First,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Last,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Dest,
        std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *_Al)
{
  _DWORD v7[7]; // [esp+0h] [ebp-1Ch] BYREF

  v7[3] = v7;
  v7[6] = 0;
  while ( _First != _Last )
    std::_Cons_val<std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
      _Alval: _Al,
      _Pdest: _Dest++,
      _Src: _First++);
  return _Dest;
}

//------------------------------------------------------------------------------
// Address: 0x10002CC0
// Name: public: ConfigurationProcessing::ComboHandleImpl::~ComboHandleImpl(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ConfigurationProcessing::ComboHandleImpl::~ComboHandleImpl(
        ConfigurationProcessing::ComboHandleImpl *this)
{
  if ( this->m_arrVarSlots._Myfirst != nullptr )
    free(pMem: this->m_arrVarSlots._Myfirst);
  this->m_arrVarSlots._Myfirst = nullptr;
  this->m_arrVarSlots._Mylast = nullptr;
  this->m_arrVarSlots._Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002CF0
// Name: void CfgProcessor::DescribeConfiguration(class CArrayAutoPtr<struct CfgProcessor::CfgEntryInfo> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CfgProcessor::DescribeConfiguration(CArrayAutoPtr<CfgProcessor::CfgEntryInfo> *rarrEntries)
{
  CArrayAutoPtr<CfgProcessor::CfgEntryInfo> *v1; // edi
  CfgProcessor::CfgEntryInfo *v2; // eax
  CArrayAutoPtr<CfgProcessor::CfgEntryInfo> *v3; // esi
  CArrayAutoPtr<CfgProcessor::CfgEntryInfo> *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Left; // ecx
  __int64 i; // kr08_8
  CArrayAutoPtr<CfgProcessor::CfgEntryInfo> *v7; // edi
  CfgProcessor::CfgEntryInfo *v8; // edx
  unsigned __int64 v9; // rax
  CfgProcessor::CfgEntryInfo *v10; // ecx
  CfgProcessor::CfgEntryInfo *v11; // kr00_4
  CfgProcessor::CfgEntryInfo *m_p; // [esp-4h] [ebp-20h]
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *itEnd; // [esp+14h] [ebp-8h]
  std::reverse_iterator<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > > it; // [esp+18h] [ebp-4h] BYREF

  v1 = rarrEntries;
  m_p = rarrEntries->m_p;
  rarrEntries->m_p = nullptr;
  free(pMem: m_p);
  v2 = (CfgProcessor::CfgEntryInfo *)operator new(nSize: 48 * (ConfigurationProcessing::s_setEntries._Mysize + 1));
  v1->m_p = v2;
  v3 = (CArrayAutoPtr<CfgProcessor::CfgEntryInfo> *)v2;
  Myhead = (CArrayAutoPtr<CfgProcessor::CfgEntryInfo> *)ConfigurationProcessing::s_setEntries._Myhead;
  Left = ConfigurationProcessing::s_setEntries._Myhead->_Left;
  it.current._Ptr = ConfigurationProcessing::s_setEntries._Myhead;
  itEnd = Left;
  for ( i = 0; it.current._Ptr != itEnd; v3 += 12 )
  {
    rarrEntries = Myhead;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>::operator--(this: (std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> *)&rarrEntries);
    v7 = rarrEntries;
    v3->m_p = rarrEntries[4].m_p;
    v3[1].m_p = v7[5].m_p;
    *(_QWORD *)&v3[8].m_p = i;
    v3[2].m_p = (CfgProcessor::CfgEntryInfo *)ComboGenerator::NumCombos(this: (ComboGenerator *)v7[6].m_p);
    v3[3].m_p = v8;
    *(_QWORD *)&v3[4].m_p = ComboGenerator::NumCombos(this: (ComboGenerator *)v7[6].m_p, bStaticCombos: false);
    v9 = ComboGenerator::NumCombos(this: (ComboGenerator *)v7[6].m_p, bStaticCombos: true);
    v10 = v3[3].m_p;
    v3[6].m_p = (CfgProcessor::CfgEntryInfo *)v9;
    LODWORD(v9) = v3[2];
    v11 = v3[8].m_p;
    v3[7].m_p = *(CfgProcessor::CfgEntryInfo **)((char *)&v9 + 4);
    *(_QWORD *)&v3[10].m_p = __PAIR64__((unsigned int)v10, (unsigned int)v11) + __PAIR64__(v3[9].m_p, v9);
    *(_QWORD *)&v7[22].m_p = *(_QWORD *)&v3->m_p;
    *(_QWORD *)&v7[24].m_p = *(_QWORD *)&v3[2].m_p;
    *(_QWORD *)&v7[26].m_p = *(_QWORD *)&v3[4].m_p;
    *(_QWORD *)&v7[28].m_p = *(_QWORD *)&v3[6].m_p;
    *(_QWORD *)&v7[30].m_p = *(_QWORD *)&v3[8].m_p;
    *(_QWORD *)&v7[32].m_p = *(_QWORD *)&v3[10].m_p;
    i += *(_QWORD *)&v3[2].m_p;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>::operator--(this: &it.current);
    Myhead = (CArrayAutoPtr<CfgProcessor::CfgEntryInfo> *)it.current._Ptr;
  }
  memset(dst: (unsigned __int8 *)v3, value: 0, count: 0x30u);
  v3[9].m_p = *(CfgProcessor::CfgEntryInfo **)((char *)&i + 4);
  v3[11].m_p = *(CfgProcessor::CfgEntryInfo **)((char *)&i + 4);
  v3[8].m_p = (CfgProcessor::CfgEntryInfo *)i;
  v3[10].m_p = (CfgProcessor::CfgEntryInfo *)i;
}

//------------------------------------------------------------------------------
// Address: 0x10002E40
// Name: void CfgProcessor::Combo_Free(struct CfgProcessor::_unnamed_type_ComboHandle_ __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CfgProcessor::Combo_Free(CfgProcessor::<unnamed_type_ComboHandle> **rhComboFree)
{
  int v1; // esi

  v1 = (int)*rhComboFree;
  if ( *rhComboFree != nullptr )
  {
    if ( *(_DWORD *)(v1 + 36) != 0 )
      free(pMem: *(void **)(v1 + 36));
    *(_DWORD *)(v1 + 36) = 0;
    *(_DWORD *)(v1 + 40) = 0;
    *(_DWORD *)(v1 + 44) = 0;
    free(pMem: (void *)v1);
  }
  *rhComboFree = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10002E90
// Name: protected: void std::vector<char,class std::allocator<char>>::_Insert_n(class std::_Vector_const_iterator<class std::_Vector_val<char,class std::allocator<char>>>,unsigned int,char const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<char>::_Insert_n(
        std::vector<char> *this,
        std::_Vector_const_iterator<std::_Vector_val<char> > _Where,
        unsigned int _Count,
        const char *_Val)
{
  unsigned __int8 *Mylast; // edi
  char *Myfirst; // ecx
  unsigned int v8; // edx
  unsigned int v9; // eax
  unsigned int v10; // eax
  char *v11; // edi
  int v12; // eax
  int v13; // ebx
  int v14; // eax
  int v15; // [esp+0h] [ebp-28h] BYREF
  char *_Newvec; // [esp+Ch] [ebp-1Ch]
  char *v17; // [esp+10h] [ebp-18h]
  int _Ncopied; // [esp+14h] [ebp-14h]
  int *v19; // [esp+18h] [ebp-10h]
  int v20; // [esp+24h] [ebp-4h]
  unsigned int _Counta; // [esp+34h] [ebp+Ch]

  v19 = &v15;
  if ( _Count != 0 )
  {
    Mylast = (unsigned __int8 *)this->_Mylast;
    Myfirst = this->_Myfirst;
    if ( this->_Myfirst - (char *)Mylast - 1 < _Count )
      std::_Xlength_error(_Message: "vector<T> too long");
    v8 = _Count + Mylast - (unsigned __int8 *)Myfirst;
    v9 = this->_Myend - Myfirst;
    if ( v9 >= v8 )
    {
      HIBYTE(_Val) = *_Val;
      if ( Mylast - (unsigned __int8 *)_Where._Ptr >= _Count )
      {
        memmove(dst: Mylast, src: &Mylast[-_Count], count: _Count);
        this->_Mylast = (char *)(_Count + v14);
        memmove(
          dst: (unsigned __int8 *)&_Where._Ptr[_Count],
          src: (unsigned __int8 *)_Where._Ptr,
          count: Mylast - (unsigned __int8 *)_Where._Ptr - _Count);
        std::fill<char *,char>(_First: _Where._Ptr, _Last: &_Where._Ptr[_Count], _Val: (char *)&_Val + 3);
      }
      else
      {
        memmove(
          dst: (unsigned __int8 *)&_Where._Ptr[_Count],
          src: (unsigned __int8 *)_Where._Ptr,
          count: Mylast - (unsigned __int8 *)_Where._Ptr);
        v20 = 2;
        std::vector<char>::_Ufill(
          this,
          _Ptr: this->_Mylast,
          _Count: _Count + _Where._Ptr - this->_Mylast,
          _Pval: (const char *)&_Val + 3);
        v20 = -1;
        this->_Mylast += _Count;
        std::fill<char *,char>(_First: _Where._Ptr, _Last: &this->_Mylast[-_Count], _Val: (char *)&_Val + 3);
      }
    }
    else
    {
      if ( -1 - (v9 >> 1) >= v9 )
      {
        v10 = (v9 >> 1) + v9;
        _Counta = v10;
      }
      else
      {
        _Counta = 0;
        v10 = 0;
      }
      if ( v10 < v8 )
      {
        _Counta = v8;
        v10 = v8;
      }
      v11 = std::allocator<char>::allocate(this: &this->_Alval, _Count: v10);
      _Newvec = v11;
      v12 = _Where._Ptr - this->_Myfirst;
      v20 = 0;
      v17 = &v11[v12];
      std::vector<char>::_Ufill(this, _Ptr: &v11[v12], _Count, _Pval: _Val);
      _Ncopied = 1;
      std::vector<char>::_Umove<char *>(this, _First: this->_Myfirst, _Last: _Where._Ptr, _Ptr: v11);
      _Ncopied = 2;
      std::vector<char>::_Umove<char *>(this, _First: _Where._Ptr, _Last: this->_Mylast, _Ptr: &v17[_Count]);
      v20 = -1;
      v13 = this->_Mylast - this->_Myfirst + _Count;
      if ( this->_Myfirst != nullptr )
        free(pMem: this->_Myfirst);
      this->_Myend = &v11[_Counta];
      this->_Mylast = &v11[v13];
      this->_Myfirst = v11;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100030A0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &,unsigned int,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::assign(
        std::string *this,
        const std::string *_Right,
        unsigned int _Roff,
        unsigned int _Count)
{
  const std::string *Ptr; // ecx
  unsigned int Mysize; // edi
  unsigned int v7; // edi
  unsigned int Myres; // eax
  std::string *v10; // eax
  bool v11; // cf

  Ptr = _Right;
  Mysize = _Right->_Mysize;
  if ( Mysize < _Roff )
    std::_Xout_of_range(_Message: "invalid string position");
  v7 = Mysize - _Roff;
  if ( _Count < v7 )
    v7 = _Count;
  if ( this == _Right )
  {
    std::string::erase(this, _Off: _Roff + v7, _Count: 0xFFFFFFFF);
    std::string::erase(this, _Off: 0, _Count: _Roff);
    return this;
  }
  if ( v7 == -1 )
    std::_Xlength_error(_Message: "string too long");
  Myres = this->_Myres;
  if ( Myres < v7 )
  {
    std::string::_Copy(this, _Newsize: v7, _Oldlen: this->_Mysize);
    Ptr = _Right;
    if ( v7 == 0 )
      return this;
LABEL_11:
    if ( Ptr->_Myres >= 0x10 )
      Ptr = (const std::string *)Ptr->_Bx._Ptr;
    if ( this->_Myres < 0x10 )
      v10 = this;
    else
      v10 = (std::string *)this->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)v10, src: (unsigned __int8 *)&Ptr->_Bx._Buf[_Roff], count: v7);
    v11 = this->_Myres < 0x10;
    this->_Mysize = v7;
    if ( !v11 )
    {
      this->_Bx._Ptr[v7] = 0;
      return this;
    }
    this->_Bx._Buf[v7] = 0;
    return this;
  }
  if ( v7 != 0 )
    goto LABEL_11;
  this->_Mysize = 0;
  if ( Myres < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003190
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::assign(std::string *this, char *_Ptr, unsigned int _Count)
{
  unsigned int Myres; // ecx
  std::string *v5; // eax
  std::string *v6; // eax
  unsigned int v8; // eax
  std::string *Ptr; // eax
  bool v10; // cf

  if ( _Ptr != nullptr )
  {
    Myres = this->_Myres;
    v5 = Myres < 0x10 ? this : (std::string *)this->_Bx._Ptr;
    if ( _Ptr >= (char *)v5 )
    {
      v6 = Myres < 0x10 ? this : (std::string *)this->_Bx._Ptr;
      if ( (char *)v6 + this->_Mysize > _Ptr )
      {
        if ( Myres < 0x10 )
          return std::string::assign(this, _Right: this, _Roff: _Ptr - (char *)this, _Count);
        else
          return std::string::assign(this, _Right: this, _Roff: _Ptr - this->_Bx._Ptr, _Count);
      }
    }
  }
  if ( _Count == -1 )
    std::_Xlength_error(_Message: "string too long");
  v8 = this->_Myres;
  if ( v8 < _Count )
  {
    std::string::_Copy(this, _Newsize: _Count, _Oldlen: this->_Mysize);
    if ( _Count == 0 )
      return this;
LABEL_17:
    if ( this->_Myres < 0x10 )
      Ptr = this;
    else
      Ptr = (std::string *)this->_Bx._Ptr;
    memcpy(dst: (unsigned __int8 *)Ptr, src: (unsigned __int8 *)_Ptr, count: _Count);
    v10 = this->_Myres < 0x10;
    this->_Mysize = _Count;
    if ( !v10 )
    {
      this->_Bx._Ptr[_Count] = 0;
      return this;
    }
    this->_Bx._Buf[_Count] = 0;
    return this;
  }
  if ( _Count != 0 )
    goto LABEL_17;
  this->_Mysize = 0;
  if ( v8 < 0x10 )
    this->_Bx._Buf[0] = 0;
  else
    *this->_Bx._Ptr = 0;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003290
// Name: protected: void std::vector<int,class std::allocator<int>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<int>::_Reserve(std::vector<int> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x3FFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x3FFFFFFF - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<int>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003300
// Name: public: class ConfigurationProcessing::ComboHandleImpl const __near & QuickMap<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl>::GetLessOrEq(unsigned __int64 __near &,class ConfigurationProcessing::ComboHandleImpl const __near &)const
// Source: json
//------------------------------------------------------------------------------
const ConfigurationProcessing::ComboHandleImpl *__thiscall QuickMap<unsigned __int64,ConfigurationProcessing::ComboHandleImpl>::GetLessOrEq(
        QuickMap<unsigned __int64,ConfigurationProcessing::ComboHandleImpl> *this,
        unsigned __int64 *k,
        const ConfigurationProcessing::ComboHandleImpl *v)
{
  unsigned __int64 *v3; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // ebx

  v3 = k;
  v5 = std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Lbound(
         this,
         _Keyval: k);
  Myhead = this->_Myhead;
  k = (unsigned __int64 *)v5;
  if ( Myhead == v5 )
  {
    if ( this->_Mysize == 0 )
      return v;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator--(this: (std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *)&k);
    v5 = (std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *)k;
  }
  if ( *v3 < v5->_Myval.first )
  {
    if ( Myhead->_Left == v5 )
      return v;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator--(this: (std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *)&k);
    v5 = (std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *)k;
  }
  *(_DWORD *)v3 = v5->_Myval.first;
  *((_DWORD *)v3 + 1) = HIDWORD(v5->_Myval.first);
  return &v5->_Myval.second;
}

//------------------------------------------------------------------------------
// Address: 0x10003370
// Name: public: ConfigurationProcessing::CfgEntry::CfgEntry(class ConfigurationProcessing::CfgEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
ConfigurationProcessing::CfgEntry *__thiscall ConfigurationProcessing::CfgEntry::CfgEntry(
        ConfigurationProcessing::CfgEntry *this,
        const ConfigurationProcessing::CfgEntry *__that)
{
  std::string *p_m_sPrefix; // ecx

  this->m_szName = __that->m_szName;
  this->m_szShaderSrc = __that->m_szShaderSrc;
  this->m_pCg = __that->m_pCg;
  p_m_sPrefix = &this->m_sPrefix;
  this->m_pExpr = __that->m_pExpr;
  p_m_sPrefix->_Myres = 15;
  p_m_sPrefix->_Mysize = 0;
  p_m_sPrefix->_Bx._Buf[0] = 0;
  std::string::assign(this: p_m_sPrefix, _Right: &__that->m_sPrefix, _Roff: 0, _Count: 0xFFFFFFFF);
  this->m_sSuffix._Myres = 15;
  this->m_sSuffix._Mysize = 0;
  this->m_sSuffix._Bx._Buf[0] = 0;
  std::string::assign(this: &this->m_sSuffix, _Right: &__that->m_sSuffix, _Roff: 0, _Count: 0xFFFFFFFF);
  this->m_eiInfo = __that->m_eiInfo;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003420
// Name: public: virtual char const __near * ConfigurationProcessing::ComboHandleImpl::GetVariableName(int)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall ConfigurationProcessing::ComboHandleImpl::GetVariableName(
        ConfigurationProcessing::ComboHandleImpl *this,
        int nSlot)
{
  return this->m_pEntry->m_pCg->GetVariableName(this: this->m_pEntry->m_pCg, a2: nSlot);
}

//------------------------------------------------------------------------------
// Address: 0x10003440
// Name: public: virtual int ConfigurationProcessing::ComboHandleImpl::GetVariableSlot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ConfigurationProcessing::ComboHandleImpl::GetVariableSlot(
        ConfigurationProcessing::ComboHandleImpl *this,
        const char *szVariableName)
{
  return this->m_pEntry->m_pCg->GetVariableSlot(this: this->m_pEntry->m_pCg, a2: szVariableName);
}

//------------------------------------------------------------------------------
// Address: 0x10003460
// Name: public: virtual int ConfigurationProcessing::ComboHandleImpl::GetVariableValue(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ConfigurationProcessing::ComboHandleImpl::GetVariableValue(
        ConfigurationProcessing::ComboHandleImpl *this,
        unsigned int nSlot)
{
  int *Myfirst; // eax

  Myfirst = this->m_arrVarSlots._Myfirst;
  if ( this->m_arrVarSlots._Mylast - Myfirst <= nSlot )
    std::_Xout_of_range(_Message: "invalid vector<T> subscript");
  return Myfirst[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x10003490
// Name: public: class std::vector<int,class std::allocator<int>> __near & std::vector<int,class std::allocator<int>>::operator=(class std::vector<int,class std::allocator<int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::vector<int> *__thiscall std::vector<int>::operator=(std::vector<int> *this, const std::vector<int> *_Right)
{
  int *Mylast; // ecx
  int *Myfirst; // eax
  int *v6; // edi
  int *v7; // ecx
  unsigned int v9; // edx
  unsigned __int8 *v10; // edi
  unsigned int v11; // ebx
  int v12; // eax
  unsigned int _Righta; // [esp+10h] [ebp+8h]

  if ( this != _Right )
  {
    Mylast = _Right->_Mylast;
    Myfirst = _Right->_Myfirst;
    v6 = this->_Myfirst;
    _Righta = Mylast - _Right->_Myfirst;
    if ( _Righta != 0 )
    {
      v9 = this->_Mylast - v6;
      if ( _Righta <= v9 )
      {
        memmove(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)Myfirst, count: 4 * (Mylast - Myfirst));
        this->_Mylast = &this->_Myfirst[_Right->_Mylast - _Right->_Myfirst];
        return this;
      }
      if ( _Righta <= this->_Myend - v6 )
      {
        v10 = (unsigned __int8 *)&Myfirst[v9];
        memmove(
          dst: (unsigned __int8 *)this->_Myfirst,
          src: (unsigned __int8 *)Myfirst,
          count: 4 * ((int)(4 * v9) >> 2));
        v11 = 4 * (((char *)_Right->_Mylast - (char *)v10) >> 2);
        memmove(dst: (unsigned __int8 *)this->_Mylast, src: v10, count: v11);
        this->_Mylast = (int *)(v11 + v12);
        return this;
      }
      if ( v6 != nullptr )
        free(pMem: v6);
      if ( std::vector<int>::_Buy(this, _Capacity: _Right->_Mylast - _Right->_Myfirst) != 0 )
        this->_Mylast = std::vector<CExprBinary *>::_Umove<CExprBinary * *>(
                          this,
                          _First: _Right->_Myfirst,
                          _Last: _Right->_Mylast,
                          _Ptr: this->_Myfirst);
    }
    else
    {
      v7 = this->_Mylast;
      if ( v6 != v7 )
      {
        memmove(dst: (unsigned __int8 *)v6, src: (unsigned __int8 *)v7, count: 0);
        this->_Mylast = v6;
        return this;
      }
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x100035C0
// Name: public: void std::vector<int,class std::allocator<int>>::push_back(int const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<int>::push_back(std::vector<int> *this, int *_Val)
{
  int *Mylast; // eax
  int v4; // edi
  int *v5; // eax
  int *v6; // eax

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<int>::_Reserve(this, _Count: 1u);
    v6 = this->_Mylast;
    if ( v6 != nullptr )
      *v6 = *_Val;
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<int>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      *v5 = this->_Myfirst[v4];
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x10003630
// Name: protected: class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near * std::vector<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>,class std::allocator<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>>::_Ufill(class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,unsigned int,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> const __near *)
// Source: json
//------------------------------------------------------------------------------
std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *__thiscall std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Ufill(
        std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >> *this,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Ptr,
        unsigned int _Count,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Pval)
{
  std::_Uninit_fill_n<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,unsigned int,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>,std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
    _First: _Ptr,
    _Count,
    _Pval,
    _Al: &this->_Alval);
  return &_Ptr[_Count];
}

//------------------------------------------------------------------------------
// Address: 0x10003660
// Name: protected: int __near * std::vector<int,class std::allocator<int>>::_Ucopy<class std::_Vector_const_iterator<class std::_Vector_val<int,class std::allocator<int>>>>(class std::_Vector_const_iterator<class std::_Vector_val<int,class std::allocator<int>>>,class std::_Vector_const_iterator<class std::_Vector_val<int,class std::allocator<int>>>,int __near *)
// Source: json
//------------------------------------------------------------------------------
int *__thiscall std::vector<int>::_Ucopy<std::_Vector_const_iterator<std::_Vector_val<int>>>(
        std::vector<int> *this,
        std::_Vector_const_iterator<std::_Vector_val<int> > _First,
        std::_Vector_const_iterator<std::_Vector_val<int> > _Last,
        int *_Ptr)
{
  return std::_Uninit_copy<std::_Vector_const_iterator<std::_Vector_val<int>>,int *,std::allocator<int>>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: (std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *)&this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x10003690
// Name: protected: class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near * std::vector<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>,class std::allocator<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>>>::_Umove<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *>(class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> __near *)
// Source: json
//------------------------------------------------------------------------------
std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *__thiscall std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Umove<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *>(
        std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >> *this,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_First,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Last,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Ptr)
{
  return std::_Uninit_move<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: &this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x100036C0
// Name: public: QuickString::QuickString(char const __near *,unsigned int)
// Source: json
//------------------------------------------------------------------------------
QuickString *__thiscall QuickString::QuickString(QuickString *this, char *szValue, unsigned int len)
{
  unsigned int v3; // edi

  v3 = len;
  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
  if ( v3 == -1 )
    v3 = strlen(szValue);
  LOBYTE(len) = 0;
  if ( v3 != -1 )
    std::vector<char>::_Insert_n(this, _Where: 0, _Count: v3 + 1, _Val: (const char *)&len);
  if ( this->_Mylast == this->_Myfirst )
    std::_Xout_of_range(_Message: "invalid vector<T> subscript");
  memcpy(dst: (unsigned __int8 *)this->_Myfirst, src: (unsigned __int8 *)szValue, count: v3);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003740
// Name: public: virtual int CComplexExpression::Evaluate(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall CComplexExpression::Evaluate(CComplexExpression *this, IEvaluationContext *pCtx)
{
  IEvaluationContext *m_pContext; // eax

  if ( this->m_pRoot == nullptr )
    return 0;
  m_pContext = pCtx;
  if ( pCtx == nullptr )
    m_pContext = this->m_pContext;
  return this->m_pRoot->Evaluate(this: this->m_pRoot, a2: m_pContext);
}

//------------------------------------------------------------------------------
// Address: 0x10003770
// Name: public: virtual void CComplexExpression::Print(class IEvaluationContext __near *)const
// Source: json
//------------------------------------------------------------------------------
void __thiscall CComplexExpression::Print(CComplexExpression *this, IEvaluationContext *pCtx)
{
  _iobuf *v3; // eax
  IEvaluationContext *m_pContext; // eax
  _iobuf *v5; // eax
  _iobuf *v6; // eax

  v3 = __iob_func();
  `anonymous namespace'::OutputF(f: v3 + 1, szFmt: "[ ");
  if ( this->m_pRoot != nullptr )
  {
    m_pContext = pCtx;
    if ( pCtx == nullptr )
      m_pContext = this->m_pContext;
    this->m_pRoot->Print(this: this->m_pRoot, a2: m_pContext);
  }
  else
  {
    v5 = __iob_func();
    `anonymous namespace'::OutputF(f: v5 + 1, szFmt: "**NEXPR**");
  }
  v6 = __iob_func();
  `anonymous namespace'::OutputF(f: v6 + 1, szFmt: " ]\n");
}

//------------------------------------------------------------------------------
// Address: 0x100037E0
// Name: public: void CComplexExpression::Clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CComplexExpression::Clear(CComplexExpression *this)
{
  IExpression **Myfirst; // ecx
  int v3; // eax
  int v4; // edi
  bool v5; // cf
  bool v6; // zf
  int v7; // eax
  unsigned __int8 *Mylast; // ecx
  unsigned __int8 *v9; // edi

  Myfirst = this->m_arrAllExpressions._Myfirst;
  v3 = this->m_arrAllExpressions._Mylast - Myfirst;
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = false;
    v6 = v3 == 0;
    do
    {
      if ( v5 || v6 )
        std::_Xout_of_range(_Message: "invalid vector<T> subscript");
      free(pMem: Myfirst[v4]);
      Myfirst = this->m_arrAllExpressions._Myfirst;
      ++v4;
      v7 = this->m_arrAllExpressions._Mylast - Myfirst;
      v5 = v7 < (unsigned int)v4;
      v6 = v7 == v4;
    }
    while ( v7 > v4 );
  }
  Mylast = (unsigned __int8 *)this->m_arrAllExpressions._Mylast;
  v9 = (unsigned __int8 *)this->m_arrAllExpressions._Myfirst;
  if ( v9 != Mylast )
  {
    memmove(dst: v9, src: Mylast, count: 0);
    this->m_arrAllExpressions._Mylast = (IExpression **)v9;
  }
  this->m_pRoot = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10003860
// Name: public: std::vector<int,class std::allocator<int>>::vector<int,class std::allocator<int>>(class std::vector<int,class std::allocator<int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::vector<int> *__thiscall std::vector<int>::vector<int>(std::vector<int> *this, const std::vector<int> *_Right)
{
  unsigned int v3; // edi
  int *v4; // eax
  int v6; // [esp+0h] [ebp-20h] BYREF
  std::vector<int> *v7; // [esp+Ch] [ebp-14h]
  int *v8; // [esp+10h] [ebp-10h]
  int v9; // [esp+1Ch] [ebp-4h]

  v8 = &v6;
  v7 = this;
  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
  v3 = _Right->_Mylast - _Right->_Myfirst;
  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
  if ( v3 != 0 )
  {
    if ( v3 > 0x3FFFFFFF )
      std::_Xlength_error(_Message: "vector<T> too long");
    v4 = (int *)std::allocator<IExpression *>::allocate(
                  this: (std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > > *)&this->_Alval,
                  _Count: v3);
    this->_Myfirst = v4;
    this->_Mylast = v4;
    this->_Myend = &v4[v3];
    v9 = 0;
    this->_Mylast = std::vector<int>::_Ucopy<std::_Vector_const_iterator<std::_Vector_val<int>>>(
                      this,
                      _First: (std::_Vector_const_iterator<std::_Vector_val<int> >)_Right->_Myfirst,
                      _Last: (std::_Vector_const_iterator<std::_Vector_val<int> >)_Right->_Mylast,
                      _Ptr: this->_Myfirst);
    v9 = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10003B60
// Name: protected: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>> std::_Tree<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > *__thiscall std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Insert(
        std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x9249248 )
  {
    if ( _Newnode->_Myval._Myres >= 0x10 )
      free(pMem: _Newnode->_Myval._Bx._Ptr);
    _Newnode->_Myval._Myres = 15;
    _Newnode->_Myval._Mysize = 0;
    _Newnode->_Myval._Bx._Buf[0] = 0;
    free(pMem: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  v6 = _Newnode;
  this->_Mysize = Mysize + 1;
  _Newnode->_Parent = _Wherenode;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead )
  {
    Myhead->_Parent = _Newnode;
    this->_Myhead->_Left = _Newnode;
    this->_Myhead->_Right = _Newnode;
  }
  else if ( _Addleft )
  {
    _Wherenode->_Left = _Newnode;
    v8 = this->_Myhead;
    if ( _Wherenode == v8->_Left )
      v8->_Left = _Newnode;
  }
  else
  {
    _Wherenode->_Right = _Newnode;
    v9 = this->_Myhead;
    if ( _Wherenode == v9->_Right )
      v9->_Right = _Newnode;
  }
  v10 = _Newnode;
  while ( v10->_Parent->_Color == 0 )
  {
    Parent = v10->_Parent;
    v12 = Parent->_Parent;
    if ( Parent == v12->_Left )
    {
      Right = v12->_Right;
      if ( Right->_Color != 0 )
      {
        if ( v10 == Parent->_Right )
        {
          v10 = v10->_Parent;
          v14 = Parent->_Right;
          v10->_Right = v14->_Left;
          if ( v14->_Left->_Isnil == 0 )
            v14->_Left->_Parent = v10;
          v14->_Parent = v10->_Parent;
          v15 = this->_Myhead;
          if ( v10 == v15->_Parent )
          {
            v15->_Parent = v14;
          }
          else
          {
            v16 = v10->_Parent;
            if ( v10 == v16->_Left )
              v16->_Left = v14;
            else
              v16->_Right = v14;
          }
          v14->_Left = v10;
          v10->_Parent = v14;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Left;
        v17->_Left = v17->_Left->_Right;
        v19 = Left->_Right;
        if ( v19->_Isnil == 0 )
          v19->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v20 = this->_Myhead;
        if ( v17 == v20->_Parent )
        {
          v20->_Parent = Left;
          Left->_Right = v17;
        }
        else
        {
          v21 = v17->_Parent;
          if ( v17 == v21->_Right )
            v21->_Right = Left;
          else
            v21->_Left = Left;
          Left->_Right = v17;
        }
LABEL_52:
        v6 = _Newnode;
        v17->_Parent = Left;
        continue;
      }
      Parent->_Color = 1;
      Right->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    else
    {
      v22 = v12->_Left;
      if ( v22->_Color != 0 )
      {
        if ( v10 == Parent->_Left )
        {
          v10 = v10->_Parent;
          v23 = Parent->_Left;
          v10->_Left = v23->_Right;
          v24 = v23->_Right;
          if ( v24->_Isnil == 0 )
            v24->_Parent = v10;
          v23->_Parent = v10->_Parent;
          v25 = this->_Myhead;
          if ( v10 == v25->_Parent )
          {
            v25->_Parent = v23;
          }
          else
          {
            v26 = v10->_Parent;
            if ( v10 == v26->_Right )
              v26->_Right = v23;
            else
              v26->_Left = v23;
          }
          v23->_Right = v10;
          v10->_Parent = v23;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Right;
        v17->_Right = Left->_Left;
        if ( Left->_Left->_Isnil == 0 )
          Left->_Left->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v27 = this->_Myhead;
        if ( v17 == v27->_Parent )
        {
          v27->_Parent = Left;
        }
        else
        {
          v28 = v17->_Parent;
          if ( v17 == v28->_Left )
            v28->_Left = Left;
          else
            v28->_Right = Left;
        }
        Left->_Left = v17;
        goto LABEL_52;
      }
      Parent->_Color = 1;
      v22->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
  }
  v29 = this->_Myhead->_Parent;
  result->_Ptr = v6;
  v29->_Color = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003DB0
// Name: void std::_Cons_val<class std::allocator<class ConfigurationProcessing::CfgEntry>,class ConfigurationProcessing::CfgEntry,class ConfigurationProcessing::CfgEntry __near &>(class std::allocator<class ConfigurationProcessing::CfgEntry> __near &,class ConfigurationProcessing::CfgEntry __near *,class ConfigurationProcessing::CfgEntry __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<ConfigurationProcessing::CfgEntry>,ConfigurationProcessing::CfgEntry,ConfigurationProcessing::CfgEntry &>(
        std::allocator<ConfigurationProcessing::CfgEntry> *_Alval,
        ConfigurationProcessing::CfgEntry *_Pdest,
        ConfigurationProcessing::CfgEntry *_Src)
{
  if ( _Pdest != nullptr )
    ConfigurationProcessing::CfgEntry::CfgEntry(this: _Pdest, __that: _Src);
}

//------------------------------------------------------------------------------
// Address: 0x10003DD0
// Name: void std::_Cons_val<class std::allocator<class Define>,class Define,class Define>(class std::allocator<class Define> __near &,class Define __near *,class Define __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<Define>,Define,Define>(
        std::allocator<Define> *_Alval,
        Define *_Pdest,
        Define *_Src)
{
  if ( _Pdest != nullptr )
  {
    _Pdest->m_sName._Myres = 15;
    _Pdest->m_sName._Mysize = 0;
    _Pdest->m_sName._Bx._Buf[0] = 0;
    std::string::assign(this: &_Pdest->m_sName, _Right: &_Src->m_sName, _Roff: 0, _Count: 0xFFFFFFFF);
    _Pdest->m_min = _Src->m_min;
    _Pdest->m_max = _Src->m_max;
    _Pdest->m_bStatic = _Src->m_bStatic;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10003E20
// Name: public: char const __near * QuickStrUnique::Lookup(char const __near *)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall QuickStrUnique::Lookup(QuickStrUnique *this, char *szString)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v3; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Myhead; // esi
  unsigned int Mysize; // ebx
  std::string *p_Myval; // eax
  unsigned int v7; // edx
  std::string *Ptr; // ecx
  int v9; // eax
  bool v10; // sf
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node **p_szString; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v12; // esi
  std::string *result; // eax
  std::string _Keyval; // [esp+Ch] [ebp-20h] BYREF
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v15; // [esp+28h] [ebp-4h] BYREF

  _Keyval._Myres = 15;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::string::assign(this: &_Keyval, _Ptr: szString, _Count: strlen(szString));
  v3 = std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Lbound(
         this,
         &_Keyval);
  Myhead = this->_Myhead;
  szString = (char *)v3;
  if ( v3 == Myhead )
    goto LABEL_13;
  Mysize = v3->_Myval._Mysize;
  p_Myval = &v3->_Myval;
  if ( p_Myval->_Myres >= 0x10 )
    p_Myval = (std::string *)p_Myval->_Bx._Ptr;
  v7 = _Keyval._Mysize;
  if ( _Keyval._Mysize >= Mysize )
    v7 = Mysize;
  Ptr = (std::string *)_Keyval._Bx._Ptr;
  if ( _Keyval._Myres < 0x10 )
    Ptr = &_Keyval;
  v9 = std::char_traits<char>::compare(_First1: Ptr->_Bx._Buf, _First2: p_Myval->_Bx._Buf, _Count: v7);
  v10 = v9 < 0;
  if ( v9 == 0 )
  {
    if ( _Keyval._Mysize < Mysize )
      goto LABEL_13;
    v10 = false;
  }
  if ( !v10 )
  {
    p_szString = (std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node **)&szString;
    goto LABEL_14;
  }
LABEL_13:
  v15 = Myhead;
  p_szString = &v15;
LABEL_14:
  v12 = *p_szString;
  if ( _Keyval._Myres >= 0x10 )
    free(pMem: _Keyval._Bx._Ptr);
  _Keyval._Myres = 15;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  if ( this->_Myhead == v12 )
    return nullptr;
  result = &v12->_Myval;
  if ( v12->_Myval._Myres >= 0x10 )
    return (std::string *)result->_Bx._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10003F10
// Name: public: bool ConfigurationProcessing::ComboHandleImpl::Initialize(unsigned __int64,class ConfigurationProcessing::CfgEntry const __near *)
// Source: json
//------------------------------------------------------------------------------
char __thiscall ConfigurationProcessing::ComboHandleImpl::Initialize(
        ConfigurationProcessing::ComboHandleImpl *this,
        unsigned __int64 iTotalCommand,
        const ConfigurationProcessing::CfgEntry *pEntry)
{
  const ConfigurationProcessing::CfgEntry *v4; // eax
  int v5; // eax
  int v6; // edx
  const ConfigurationProcessing::CfgEntry *m_pEntry; // edx
  ComboGenerator *m_pCg; // ecx
  Define *Myfirst; // esi
  Define *Mylast; // eax
  Define *v11; // edi
  Define *v12; // ecx
  Define *v13; // ebx
  unsigned int v14; // eax
  const ConfigurationProcessing::CfgEntry *v15; // edi
  int *v16; // eax
  int *v17; // edx
  int *v18; // ecx
  int v19; // edi
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  int *v24; // eax
  int *Myend; // ecx
  int *v26; // edx
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // ecx
  int *v31; // eax
  const Define *pDefVarsEnd; // [esp+Ch] [ebp-8h]
  unsigned int v35; // [esp+20h] [ebp+Ch]

  LODWORD(this->m_iTotalCommand) = iTotalCommand;
  v4 = pEntry;
  HIDWORD(this->m_iTotalCommand) = HIDWORD(iTotalCommand);
  this->m_pEntry = v4;
  v5 = ComboGenerator::NumCombos(this: v4->m_pCg);
  HIDWORD(this->m_numCombos) = v6;
  m_pEntry = this->m_pEntry;
  LODWORD(this->m_numCombos) = v5;
  m_pCg = m_pEntry->m_pCg;
  Myfirst = m_pCg->m_arrDefines._Myfirst;
  Mylast = m_pCg->m_arrDefines._Mylast;
  if ( Myfirst == Mylast )
  {
    v11 = nullptr;
  }
  else
  {
    if ( Mylast - Myfirst == 0 )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    v11 = m_pCg->m_arrDefines._Myfirst;
  }
  v12 = m_pCg->m_arrDefines._Mylast;
  if ( Myfirst == v12 )
  {
    v13 = nullptr;
  }
  else
  {
    if ( v12 - Myfirst == 0 )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    v13 = Myfirst;
  }
  pDefVarsEnd = &v13[v12 - Myfirst];
  v14 = (unsigned int)v11;
  v35 = (unsigned int)v11;
  if ( v11 < pDefVarsEnd )
  {
    do
    {
      v15 = *(const ConfigurationProcessing::CfgEntry **)(v14 + 32);
      v16 = this->m_arrVarSlots._Mylast;
      pEntry = v15;
      if ( &pEntry >= (const ConfigurationProcessing::CfgEntry **)v16
        || (v17 = this->m_arrVarSlots._Myfirst) > (int *)&pEntry )
      {
        Myend = this->m_arrVarSlots._Myend;
        if ( v16 == Myend )
        {
          v26 = this->m_arrVarSlots._Myfirst;
          v27 = v16 - v26;
          if ( v27 > 0x3FFFFFFE )
LABEL_38:
            std::_Xlength_error(_Message: "vector<T> too long");
          v28 = v27 + 1;
          v29 = Myend - v26;
          if ( v28 > v29 )
          {
            if ( 0x3FFFFFFF - (v29 >> 1) >= v29 )
              v30 = (v29 >> 1) + v29;
            else
              v30 = 0;
            if ( v30 < v28 )
              v30 = v28;
            std::vector<int>::reserve(this: &this->m_arrVarSlots, _Count: v30);
          }
        }
        v31 = this->m_arrVarSlots._Mylast;
        if ( v31 != nullptr )
          *v31 = (int)v15;
      }
      else
      {
        v18 = this->m_arrVarSlots._Myend;
        v19 = ((char *)&pEntry - (char *)v17) >> 2;
        if ( v16 == v18 )
        {
          v20 = v16 - v17;
          if ( v20 > 0x3FFFFFFE )
            goto LABEL_38;
          v21 = v20 + 1;
          v22 = v18 - v17;
          if ( v21 > v22 )
          {
            if ( 0x3FFFFFFF - (v22 >> 1) >= v22 )
              v23 = (v22 >> 1) + v22;
            else
              v23 = 0;
            if ( v23 < v21 )
              v23 = v21;
            std::vector<int>::reserve(this: &this->m_arrVarSlots, _Count: v23);
          }
        }
        v24 = this->m_arrVarSlots._Mylast;
        if ( v24 != nullptr )
          *v24 = this->m_arrVarSlots._Myfirst[v19];
      }
      ++this->m_arrVarSlots._Mylast;
      v14 = v35 + 40;
      v35 = v14;
    }
    while ( v14 < (unsigned int)pDefVarsEnd );
  }
  this->m_iComboNumber = this->m_numCombos - 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x100040E0
// Name: protected: void std::_Tree<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Erase(
        std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v2; // esi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *i; // edi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    if ( v2->_Myval._Myres >= 0x10 )
      free(pMem: v2->_Myval._Bx._Ptr);
    v2->_Myval._Myres = 15;
    v2->_Myval._Mysize = 0;
    v2->_Myval._Bx._Buf[0] = 0;
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004140
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>> std::_Tree<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > *__thiscall std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::erase(
        std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > _Where)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *v7; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v14; // eax
  std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *i; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
  if ( Ptr->_Left->_Isnil != 0 )
  {
    Right = Ptr->_Right;
LABEL_8:
    Parent = Ptr->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    v7 = this;
    Myhead = this->_Myhead;
    if ( Myhead->_Parent == Ptr )
    {
      Myhead->_Parent = Right;
    }
    else if ( Parent->_Left == Ptr )
    {
      Parent->_Left = Right;
    }
    else
    {
      Parent->_Right = Right;
    }
    if ( this->_Myhead->_Left == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v9 = Parent;
      }
      else
      {
        v9 = std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Min(_Pnode: Right);
        v7 = this;
      }
      v7->_Myhead->_Left = v9;
    }
    v10 = v7->_Myhead;
    if ( v10->_Right == Ptr )
    {
      if ( Right->_Isnil != 0 )
        v10->_Right = Parent;
      else
        v10->_Right = std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Max(_Pnode: Right);
    }
    goto LABEL_35;
  }
  if ( Ptr->_Right->_Isnil != 0 )
  {
    Right = Ptr->_Left;
    goto LABEL_8;
  }
  v5 = _Where._Ptr;
  Right = _Where._Ptr->_Right;
  if ( _Where._Ptr == Ptr )
    goto LABEL_8;
  Ptr->_Left->_Parent = _Where._Ptr;
  v5->_Left = Ptr->_Left;
  if ( v5 == Ptr->_Right )
  {
    Parent = v5;
  }
  else
  {
    Parent = v5->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    Parent->_Left = Right;
    v5->_Right = Ptr->_Right;
    Ptr->_Right->_Parent = v5;
  }
  v11 = this->_Myhead;
  if ( v11->_Parent == Ptr )
  {
    v11->_Parent = v5;
  }
  else
  {
    v12 = Ptr->_Parent;
    if ( v12->_Left == Ptr )
      v12->_Left = v5;
    else
      v12->_Right = v5;
  }
  v5->_Parent = Ptr->_Parent;
  Color = v5->_Color;
  v5->_Color = Ptr->_Color;
  Ptr->_Color = Color;
LABEL_35:
  v14 = _Erasednode;
  if ( _Erasednode->_Color == 1 )
  {
    for ( i = this; Right != i->_Myhead->_Parent; Parent = Parent->_Parent )
    {
      if ( Right->_Color != 1 )
        break;
      Left = Parent->_Left;
      if ( Right == Parent->_Left )
      {
        Left = Parent->_Right;
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Right;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Left->_Color != 1 || Left->_Right->_Color != 1 )
        {
          if ( Left->_Right->_Color == 1 )
          {
            Left->_Left->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      else
      {
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Left;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Right->_Color != 1 || Left->_Left->_Color != 1 )
        {
          if ( Left->_Left->_Color == 1 )
          {
            Left->_Right->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      Left->_Color = 0;
LABEL_53:
      Right = Parent;
    }
    v14 = _Erasednode;
    Right->_Color = 1;
  }
  if ( v14->_Myval._Myres >= 0x10 )
    free(pMem: v14->_Myval._Bx._Ptr);
  _Erasednode->_Myval._Myres = 15;
  _Erasednode->_Myval._Mysize = 0;
  _Erasednode->_Myval._Bx._Buf[0] = 0;
  free(pMem: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100043C0
// Name: public: struct std::pair<class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>>,bool> std::_Tree<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >,bool> *__thiscall std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Linsert(
        std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >,bool> *result,
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Node,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > _Leftish)
{
  std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *v4; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Parent; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v7; // edi
  std::string *p_Myval; // ebx
  bool v9; // al
  std::string *v10; // eax
  std::string *Ptr; // edx
  unsigned int Mysize; // esi
  unsigned int v13; // edi
  unsigned int v14; // ecx
  int v15; // eax
  bool v16; // sf
  unsigned int v17; // edi
  unsigned int v18; // esi
  unsigned int v19; // edx
  std::string *v20; // ecx
  int v21; // eax
  bool v22; // sf
  int v23; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v25; // esi
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > *v26; // eax
  std::string *v28; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Wherenode; // [esp+Ch] [ebp-10h]
  std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *v30; // [esp+10h] [ebp-Ch]
  bool _Addleft; // [esp+14h] [ebp-8h]
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *_Trynode; // [esp+18h] [ebp-4h]

  v4 = this;
  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v7 = Myhead;
  p_Myval = &_Node->_Myval;
  v9 = true;
  v30 = v4;
  _Trynode = Parent;
  _Addleft = true;
  if ( Parent->_Isnil == 0 )
  {
    while ( 1 )
    {
      _Wherenode = Parent;
      v10 = &Parent->_Myval;
      if ( LOBYTE(_Leftish._Ptr) != 0 )
      {
        if ( _Node->_Myval._Myres < 0x10 )
          Ptr = &_Node->_Myval;
        else
          Ptr = (std::string *)p_Myval->_Bx._Ptr;
        Mysize = Parent->_Myval._Mysize;
        v13 = _Node->_Myval._Mysize;
        v14 = Mysize;
        if ( Mysize >= v13 )
          v14 = _Node->_Myval._Mysize;
        if ( v10->_Myres >= 0x10 )
          v10 = (std::string *)v10->_Bx._Ptr;
        v15 = std::char_traits<char>::compare(_First1: v10->_Bx._Buf, _First2: Ptr->_Bx._Buf, _Count: v14);
        v16 = v15 < 0;
        if ( v15 == 0 )
        {
          if ( Mysize < v13 )
          {
            v9 = false;
            goto LABEL_30;
          }
          v16 = false;
        }
        v9 = !v16;
      }
      else
      {
        v17 = Parent->_Myval._Mysize;
        if ( Parent->_Myval._Myres >= 0x10 )
          v10 = (std::string *)v10->_Bx._Ptr;
        v18 = _Node->_Myval._Mysize;
        v19 = v18;
        if ( v18 >= v17 )
          v19 = Parent->_Myval._Mysize;
        if ( _Node->_Myval._Myres < 0x10 )
          v20 = &_Node->_Myval;
        else
          v20 = (std::string *)p_Myval->_Bx._Ptr;
        v21 = std::char_traits<char>::compare(_First1: v20->_Bx._Buf, _First2: v10->_Bx._Buf, _Count: v19);
        v22 = v21 < 0;
        if ( v21 == 0 )
        {
          if ( v18 >= v17 )
            v23 = v18 != v17;
          else
            v23 = -1;
          v22 = v23 < 0;
        }
        v9 = v22;
      }
LABEL_30:
      _Addleft = v9;
      if ( v9 )
        Left = _Trynode->_Left;
      else
        Left = _Trynode->_Right;
      _Trynode = Left;
      if ( Left->_Isnil != 0 )
      {
        v7 = _Wherenode;
        v4 = v30;
        break;
      }
      Parent = Left;
    }
  }
  v25 = v7;
  _Leftish._Ptr = v7;
  if ( v9 )
  {
    if ( v7 == v4->_Myhead->_Left )
    {
      v26 = std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Insert(
              this: v4,
              result: &_Leftish,
              _Addleft: true,
              _Wherenode: v7,
              _Newnode: _Node);
LABEL_38:
      result->first = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >)v26->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    v25 = _Leftish._Ptr;
  }
  if ( _Node->_Myval._Myres < 0x10 )
    v28 = &_Node->_Myval;
  else
    v28 = (std::string *)p_Myval->_Bx._Ptr;
  if ( std::string::compare(
         this: &v25->_Myval,
         _Off: 0,
         _N0: v25->_Myval._Mysize,
         _Ptr: v28->_Bx._Buf,
         _Count: _Node->_Myval._Mysize) < 0 )
  {
    v26 = std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Insert(
            this: v30,
            result: &_Leftish,
            _Addleft,
            _Wherenode: v7,
            _Newnode: _Node);
    goto LABEL_38;
  }
  if ( _Node->_Myval._Myres >= 0x10 )
    free(pMem: p_Myval->_Bx._Ptr);
  _Node->_Myval._Myres = 15;
  _Node->_Myval._Mysize = 0;
  p_Myval->_Bx._Buf[0] = 0;
  free(pMem: _Node);
  result->first._Ptr = v25;
  result->second = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10004580
// Name: protected: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>> std::_Tree<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Insert(bool,struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near *,struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > *__thiscall std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Insert(
        std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v7; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v9; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v11; // esi
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v13; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v15; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v16; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v17; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v18; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Left; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v20; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v21; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v22; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v24; // edx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x2222221 )
  {
    if ( _Newnode->_Myval.m_sSuffix._Myres >= 0x10 )
      free(pMem: _Newnode->_Myval.m_sSuffix._Bx._Ptr);
    _Newnode->_Myval.m_sSuffix._Myres = 15;
    _Newnode->_Myval.m_sSuffix._Mysize = 0;
    _Newnode->_Myval.m_sSuffix._Bx._Buf[0] = 0;
    if ( _Newnode->_Myval.m_sPrefix._Myres >= 0x10 )
      free(pMem: _Newnode->_Myval.m_sPrefix._Bx._Ptr);
    _Newnode->_Myval.m_sPrefix._Myres = 15;
    _Newnode->_Myval.m_sPrefix._Mysize = 0;
    _Newnode->_Myval.m_sPrefix._Bx._Buf[0] = 0;
    free(pMem: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  v7 = _Newnode;
  this->_Mysize = Mysize + 1;
  _Newnode->_Parent = _Wherenode;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead )
  {
    Myhead->_Parent = _Newnode;
    this->_Myhead->_Left = _Newnode;
    v9 = this->_Myhead;
LABEL_13:
    v9->_Right = _Newnode;
    goto LABEL_14;
  }
  if ( !_Addleft )
  {
    _Wherenode->_Right = _Newnode;
    v9 = this->_Myhead;
    if ( _Wherenode != v9->_Right )
      goto LABEL_14;
    goto LABEL_13;
  }
  _Wherenode->_Left = _Newnode;
  v10 = this->_Myhead;
  if ( _Wherenode == v10->_Left )
    v10->_Left = _Newnode;
LABEL_14:
  v11 = _Newnode;
  while ( v11->_Parent->_Color == 0 )
  {
    Parent = v11->_Parent;
    v13 = Parent->_Parent;
    if ( Parent == v13->_Left )
    {
      Right = v13->_Right;
      if ( Right->_Color != 0 )
      {
        if ( v11 == Parent->_Right )
        {
          v11 = v11->_Parent;
          v15 = Parent->_Right;
          v11->_Right = v15->_Left;
          if ( v15->_Left->_Isnil == 0 )
            v15->_Left->_Parent = v11;
          v15->_Parent = v11->_Parent;
          v16 = this->_Myhead;
          if ( v11 == v16->_Parent )
          {
            v16->_Parent = v15;
          }
          else
          {
            v17 = v11->_Parent;
            if ( v11 == v17->_Left )
              v17->_Left = v15;
            else
              v17->_Right = v15;
          }
          v15->_Left = v11;
          v11->_Parent = v15;
        }
        v11->_Parent->_Color = 1;
        v11->_Parent->_Parent->_Color = 0;
        v18 = v11->_Parent->_Parent;
        Left = v18->_Left;
        v18->_Left = v18->_Left->_Right;
        v20 = Left->_Right;
        if ( v20->_Isnil == 0 )
          v20->_Parent = v18;
        Left->_Parent = v18->_Parent;
        v21 = this->_Myhead;
        if ( v18 == v21->_Parent )
        {
          v21->_Parent = Left;
          Left->_Right = v18;
        }
        else
        {
          v22 = v18->_Parent;
          if ( v18 == v22->_Right )
            v22->_Right = Left;
          else
            v22->_Left = Left;
          Left->_Right = v18;
        }
LABEL_46:
        v7 = _Newnode;
        v18->_Parent = Left;
        continue;
      }
    }
    else
    {
      Right = v13->_Left;
      if ( Right->_Color != 0 )
      {
        if ( v11 == Parent->_Left )
        {
          v11 = v11->_Parent;
          std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Rrotate(
            this,
            _Wherenode: Parent);
        }
        v11->_Parent->_Color = 1;
        v11->_Parent->_Parent->_Color = 0;
        v18 = v11->_Parent->_Parent;
        Left = v18->_Right;
        v18->_Right = Left->_Left;
        if ( Left->_Left->_Isnil == 0 )
          Left->_Left->_Parent = v18;
        Left->_Parent = v18->_Parent;
        v23 = this->_Myhead;
        if ( v18 == v23->_Parent )
        {
          v23->_Parent = Left;
        }
        else
        {
          v24 = v18->_Parent;
          if ( v18 == v24->_Left )
            v24->_Left = Left;
          else
            v24->_Right = Left;
        }
        Left->_Left = v18;
        goto LABEL_46;
      }
    }
    Parent->_Color = 1;
    Right->_Color = 1;
    v11->_Parent->_Parent->_Color = 0;
    v11 = v11->_Parent->_Parent;
  }
  this->_Myhead->_Parent->_Color = 1;
  result->_Ptr = v7;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100047D0
// Name: void std::_Cons_val<class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,char const __near * __near &>(class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>> __near &,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::string>,std::string,char const * &>(
        std::allocator<std::string > *_Alval,
        std::string *_Pdest,
        char **_Src)
{
  char *v3; // esi
  const char *v4; // eax

  if ( _Pdest != nullptr )
  {
    v3 = *_Src;
    v4 = *_Src;
    _Pdest->_Myres = 15;
    _Pdest->_Mysize = 0;
    _Pdest->_Bx._Buf[0] = 0;
    std::string::assign(this: _Pdest, _Ptr: v3, _Count: strlen(v4));
  }
}

//------------------------------------------------------------------------------
// Address: 0x10004810
// Name: public: struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Buynode<class ConfigurationProcessing::CfgEntry __near &>(class ConfigurationProcessing::CfgEntry __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *__thiscall std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Buynode<ConfigurationProcessing::CfgEntry &>(
        std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *this,
        ConfigurationProcessing::CfgEntry *_Val)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *pMem; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node **)operator new(nSize: 0x90u);
  pMem = v3;
  if ( v3 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *v3 = this->_Myhead;
  v3[1] = this->_Myhead;
  v3[2] = this->_Myhead;
  *((_WORD *)v3 + 68) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<ConfigurationProcessing::CfgEntry>,ConfigurationProcessing::CfgEntry,ConfigurationProcessing::CfgEntry &>(
    _Alval: &this->_Alval,
    _Pdest: (ConfigurationProcessing::CfgEntry *)(v3 + 4),
    _Src: _Val);
  v9 = -1;
  return (std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x100048D0
// Name: void std::_Dest_val<class std::allocator<class Define>,class Define>(class std::allocator<class Define> __near &,class Define __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Dest_val<std::allocator<Define>,Define>(std::allocator<Define> *_Alval, Define *_Pdest)
{
  if ( _Pdest->m_sName._Myres >= 0x10 )
    free(pMem: _Pdest->m_sName._Bx._Ptr);
  _Pdest->m_sName._Myres = 15;
  _Pdest->m_sName._Mysize = 0;
  _Pdest->m_sName._Bx._Buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x10004900
// Name: class Define __near * std::_Uninit_move<class Define __near *,class Define __near *,class std::allocator<class Define>,class Define>(class Define __near *,class Define __near *,class Define __near *,class std::allocator<class Define> __near &,class Define __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
Define *__cdecl std::_Uninit_move<Define *,Define *,std::allocator<Define>,Define>(
        Define *_First,
        Define *_Last,
        Define *_Dest,
        std::allocator<Define> *_Al)
{
  Define *v4; // edi
  int v7; // [esp+0h] [ebp-20h] BYREF
  Define *_Next; // [esp+Ch] [ebp-14h]
  int *v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-4h]

  v9 = &v7;
  v4 = _Dest;
  _Next = _Dest;
  v10 = 0;
  while ( _First != _Last )
    std::_Cons_val<std::allocator<Define>,Define,Define>(_Alval: _Al, _Pdest: v4++, _Src: _First++);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x100049A0
// Name: void std::_Cons_val<class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>(class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>> __near &,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int> __near *,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int> __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::pair<std::string const,int>>,std::pair<std::string const,int>,std::pair<std::string const,int>>(
        std::allocator<std::pair<std::string const ,int> > *_Alval,
        std::pair<std::string const ,int> *_Pdest,
        std::pair<std::string const ,int> *_Src)
{
  if ( _Pdest != nullptr )
  {
    _Pdest->first._Myres = 15;
    _Pdest->first._Mysize = 0;
    _Pdest->first._Bx._Buf[0] = 0;
    std::string::assign(this: (std::string *)&_Pdest->first, _Right: &_Src->first, _Roff: 0, _Count: 0xFFFFFFFF);
    _Pdest->second = _Src->second;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100049E0
// Name: protected: class IExpression __near * CComplexExpression::ParseInternal(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
IExpression *__thiscall CComplexExpression::ParseInternal(CComplexExpression *this, char **szExpression)
{
  const char **v2; // esi
  bool v3; // zf
  char v5; // cl
  IExpression *result; // eax
  int v7; // esi
  char **v8; // eax
  IExpression *v9; // ebx
  char **v10; // esi
  const char *v11; // eax
  char v12; // cl
  const char *v13; // ecx
  _BYTE *v14; // edi
  char v15; // al
  unsigned int i; // ebx
  QuickString *v17; // eax
  int v18; // edi
  char **v19; // eax
  IExpression *v20; // esi
  char **v21; // eax
  QuickString v22; // [esp+8h] [ebp-14h] BYREF
  CComplexExpression *v23; // [esp+18h] [ebp-4h]

  v2 = (const char **)szExpression;
  v3 = **szExpression == 0;
  v23 = this;
  if ( !v3 )
  {
    do
    {
      if ( isspace(c: **v2) == 0 )
        break;
      ++*v2;
    }
    while ( **v2 != 0 );
  }
  v5 = **v2;
  if ( v5 == 0 )
  {
    **v2 = 0;
    return this->m_pDefFalse;
  }
  if ( isdigit(c: v5) != 0 )
  {
    v7 = strtol(nptr: *v2, endptr: (char **)v2, ibase: 10);
    v8 = (char **)operator new(nSize: 8u);
    if ( v8 != nullptr )
    {
      *v8 = (char *)&CExprConstant::`vftable';
      v8[1] = (char *)v7;
      szExpression = v8;
    }
    else
    {
      szExpression = nullptr;
    }
    std::vector<int>::push_back(this: (std::vector<int> *)&this->m_arrAllExpressions, _Val: (int *)&szExpression);
    return (IExpression *)szExpression;
  }
  if ( strncmp(first: *v2, last: "defined", count: 7u) == 0 )
  {
    *v2 += 7;
    v9 = CComplexExpression::ParseInternal(this, szExpression: (char **)v2);
    v10 = (char **)operator new(nSize: 8u);
    if ( v10 != nullptr )
    {
      v10[1] = (char *)v9->Evaluate(this: v9, a2: this->m_pContext);
      *v10 = (char *)&CExprConstant::`vftable';
      szExpression = v10;
    }
    else
    {
      szExpression = nullptr;
    }
    goto LABEL_14;
  }
  v11 = *v2;
  v12 = **v2;
  if ( v12 == 40 )
  {
    *v2 = v11 + 1;
    result = CComplexExpression::ParseTopLevel(this, szExpression: (char **)v2);
    v13 = *v2;
    if ( **v2 == 41 )
    {
      *v2 = v13 + 1;
    }
    else
    {
      *v13 = 0;
      return this->m_pDefFalse;
    }
    return result;
  }
  if ( v12 != 36 )
  {
    if ( v12 != 33 )
    {
      *v11 = 0;
      return this->m_pDefFalse;
    }
    *v2 = v11 + 1;
    v20 = CComplexExpression::ParseInternal(this, szExpression: (char **)v2);
    v21 = (char **)operator new(nSize: 8u);
    if ( v21 != nullptr )
    {
      v21[1] = (char *)v20;
      *v21 = (char *)&CExprUnary_Negate::`vftable';
      szExpression = v21;
    }
    else
    {
      szExpression = nullptr;
    }
LABEL_14:
    std::vector<int>::push_back(this: (std::vector<int> *)&this->m_arrAllExpressions, _Val: (int *)&szExpression);
    return (IExpression *)szExpression;
  }
  v14 = v11 + 1;
  v15 = v11[1];
  for ( i = 0; v15 != 0; ++i )
  {
    if ( isalnum(c: v15) == 0 && *v14 != 95 )
      break;
    v15 = *++v14;
  }
  v17 = QuickString::QuickString(this: &v22, szValue: (char *)*v2 + 1, len: i);
  if ( v17->_Mylast == v17->_Myfirst )
    std::_Xout_of_range(_Message: "invalid vector<T> subscript");
  v18 = v23->m_pContext->GetVariableSlot(this: v23->m_pContext, a2: v17->_Myfirst);
  if ( v22._Myfirst != nullptr )
    free(pMem: v22._Myfirst);
  *v2 += i + 1;
  v19 = (char **)operator new(nSize: 8u);
  if ( v19 != nullptr )
  {
    *v19 = (char *)&CExprVariable::`vftable';
    v19[1] = (char *)v18;
    szExpression = v19;
  }
  else
  {
    szExpression = nullptr;
  }
  std::vector<int>::push_back(this: (std::vector<int> *)&v23->m_arrAllExpressions, _Val: (int *)&szExpression);
  return (IExpression *)szExpression;
}

//------------------------------------------------------------------------------
// Address: 0x10004C80
// Name: public: ConfigurationProcessing::ComboHandleImpl::ComboHandleImpl(class ConfigurationProcessing::ComboHandleImpl const __near &)
// Source: json
//------------------------------------------------------------------------------
ConfigurationProcessing::ComboHandleImpl *__thiscall ConfigurationProcessing::ComboHandleImpl::ComboHandleImpl(
        ConfigurationProcessing::ComboHandleImpl *this,
        const ConfigurationProcessing::ComboHandleImpl *__that)
{
  this->__vftable = (ConfigurationProcessing::ComboHandleImpl_vtbl *)&ConfigurationProcessing::ComboHandleImpl::`vftable';
  this->m_iTotalCommand = __that->m_iTotalCommand;
  this->m_iComboNumber = __that->m_iComboNumber;
  this->m_numCombos = __that->m_numCombos;
  this->m_pEntry = __that->m_pEntry;
  std::vector<int>::vector<int>(this: &this->m_arrVarSlots, _Right: &__that->m_arrVarSlots);
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10004CD0
// Name: struct CfgProcessor::_unnamed_type_ComboHandle_ __near * CfgProcessor::Combo_GetNext(unsigned __int64 __near &,struct CfgProcessor::_unnamed_type_ComboHandle_ __near * __near &,unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
ConfigurationProcessing::ComboHandleImpl *__cdecl CfgProcessor::Combo_GetNext(
        unsigned __int64 *riCommandNumber,
        ConfigurationProcessing::ComboHandleImpl **rhCombo,
        unsigned __int64 iCommandEnd)
{
  ConfigurationProcessing::ComboHandleImpl *v3; // esi
  unsigned __int64 *v4; // edi
  int v5; // eax
  const ConfigurationProcessing::ComboHandleImpl *LessOrEq; // esi
  const ConfigurationProcessing::CfgEntry *m_pEntry; // eax
  ConfigurationProcessing::ComboHandleImpl *v8; // eax
  unsigned __int64 v9; // kr00_8
  ConfigurationProcessing::ComboHandleImpl *v10; // esi
  unsigned __int64 v12; // kr08_8
  unsigned int v13; // ecx
  unsigned int v14; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Ptr; // ecx
  _DWORD *v18; // edi
  ConfigurationProcessing::ComboHandleImpl *v19; // eax
  _DWORD v20[2]; // [esp+Ch] [ebp-7Ch] BYREF
  __int64 v21; // [esp+14h] [ebp-74h]
  __int64 v22; // [esp+1Ch] [ebp-6Ch]
  __int64 v23; // [esp+24h] [ebp-64h]
  int v24; // [esp+2Ch] [ebp-5Ch]
  int v25; // [esp+30h] [ebp-58h]
  int v26; // [esp+34h] [ebp-54h]
  int v27; // [esp+38h] [ebp-50h]
  ConfigurationProcessing::ComboHandleImpl emptyCPCHI; // [esp+44h] [ebp-44h] BYREF
  unsigned __int64 iCommandLookup; // [esp+7Ch] [ebp-Ch] BYREF
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> v30; // [esp+84h] [ebp-4h] BYREF

  v3 = *rhCombo;
  v4 = riCommandNumber;
  if ( *rhCombo == nullptr )
  {
    v5 = *(_DWORD *)riCommandNumber;
    HIDWORD(iCommandLookup) = *((_DWORD *)riCommandNumber + 1);
    memset(&emptyCPCHI.m_iTotalCommand, 0, 40);
    LODWORD(iCommandLookup) = v5;
    emptyCPCHI.__vftable = (ConfigurationProcessing::ComboHandleImpl_vtbl *)&ConfigurationProcessing::ComboHandleImpl::`vftable';
    LessOrEq = QuickMap<unsigned __int64,ConfigurationProcessing::ComboHandleImpl>::GetLessOrEq(
                 this: &ConfigurationProcessing::s_mapComboCommands,
                 k: &iCommandLookup,
                 v: &emptyCPCHI);
    m_pEntry = LessOrEq->m_pEntry;
    if ( m_pEntry == nullptr
      || m_pEntry->m_pCg == nullptr
      || m_pEntry->m_pExpr == nullptr
      || LessOrEq->m_iTotalCommand > *riCommandNumber )
    {
      return nullptr;
    }
    v8 = (ConfigurationProcessing::ComboHandleImpl *)operator new(nSize: 0x38u);
    if ( v8 != nullptr )
      v3 = ConfigurationProcessing::ComboHandleImpl::ComboHandleImpl(this: v8, __that: LessOrEq);
    else
      v3 = nullptr;
    *rhCombo = v3;
    v9 = *riCommandNumber - iCommandLookup;
    iCommandLookup = v9;
    ConfigurationProcessing::ComboHandleImpl::AdvanceCommands(this: v3, riAdvanceMore: &iCommandLookup);
    if ( !ConfigurationProcessing::ComboHandleImpl::IsSkipped(this: v3) )
    {
      v10 = *rhCombo;
      ConfigurationProcessing::ComboHandleImpl::~ComboHandleImpl(this: &emptyCPCHI);
      return v10;
    }
    ConfigurationProcessing::ComboHandleImpl::~ComboHandleImpl(this: &emptyCPCHI);
  }
  if ( ConfigurationProcessing::ComboHandleImpl::NextNotSkipped(this: v3, iTotalCommand: iCommandEnd) != 0 )
  {
LABEL_35:
    *(_DWORD *)v4 = v3->m_iTotalCommand;
    *((_DWORD *)v4 + 1) = HIDWORD(v3->m_iTotalCommand);
    return *rhCombo;
  }
  while ( 1 )
  {
    v12 = v3->m_iTotalCommand + 1;
    if ( v12 >= iCommandEnd )
      break;
    *v4 = v12;
    if ( v3->m_arrVarSlots._Myfirst != nullptr )
      free(pMem: v3->m_arrVarSlots._Myfirst);
    v3->m_arrVarSlots._Myfirst = nullptr;
    v3->m_arrVarSlots._Mylast = nullptr;
    v3->m_arrVarSlots._Myend = nullptr;
    free(pMem: v3);
    *rhCombo = nullptr;
    v13 = *(_DWORD *)v4;
    v14 = *((_DWORD *)v4 + 1);
    Myhead = ConfigurationProcessing::s_mapComboCommands._Myhead;
    Parent = ConfigurationProcessing::s_mapComboCommands._Myhead->_Parent;
    v21 = 0;
    v22 = 0;
    iCommandLookup = __PAIR64__(v14, v13);
    v20[0] = &ConfigurationProcessing::ComboHandleImpl::`vftable';
    v23 = 0;
    v24 = 0;
    v25 = 0;
    v26 = 0;
    v27 = 0;
    Ptr = ConfigurationProcessing::s_mapComboCommands._Myhead;
    while ( Parent->_Isnil == 0 )
    {
      if ( Parent->_Myval.first >= iCommandLookup )
      {
        Ptr = Parent;
        Parent = Parent->_Left;
      }
      else
      {
        Parent = Parent->_Right;
      }
    }
    v30._Ptr = Ptr;
    if ( ConfigurationProcessing::s_mapComboCommands._Myhead == Ptr )
    {
      if ( ConfigurationProcessing::s_mapComboCommands._Mysize == 0 )
      {
        v18 = v20;
        goto LABEL_30;
      }
      std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator--(this: &v30);
      Ptr = v30._Ptr;
    }
    if ( iCommandLookup < Ptr->_Myval.first )
    {
      if ( Myhead->_Left == Ptr )
      {
        v18 = v20;
        goto LABEL_30;
      }
      std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator--(this: &v30);
      Ptr = v30._Ptr;
    }
    v18 = &Ptr->_Myval.second.__vftable;
LABEL_30:
    v19 = (ConfigurationProcessing::ComboHandleImpl *)operator new(nSize: 0x38u);
    v3 = v19;
    if ( v19 != nullptr )
    {
      v19->__vftable = (ConfigurationProcessing::ComboHandleImpl_vtbl *)&ConfigurationProcessing::ComboHandleImpl::`vftable';
      LODWORD(v19->m_iTotalCommand) = v18[2];
      HIDWORD(v19->m_iTotalCommand) = v18[3];
      LODWORD(v19->m_iComboNumber) = v18[4];
      HIDWORD(v19->m_iComboNumber) = v18[5];
      LODWORD(v19->m_numCombos) = v18[6];
      HIDWORD(v19->m_numCombos) = v18[7];
      v19->m_pEntry = (const ConfigurationProcessing::CfgEntry *)v18[8];
      std::vector<int>::vector<int>(this: &v19->m_arrVarSlots, _Right: (const std::vector<int> *)(v18 + 9));
    }
    else
    {
      v3 = nullptr;
    }
    *rhCombo = v3;
    if ( v3->m_pEntry->m_pExpr->Evaluate(this: v3->m_pEntry->m_pExpr, a2: v3) == 0 )
      return *rhCombo;
    v4 = riCommandNumber;
    if ( ConfigurationProcessing::ComboHandleImpl::NextNotSkipped(this: v3, iTotalCommand: iCommandEnd) != 0 )
      goto LABEL_35;
  }
  if ( v3->m_arrVarSlots._Myfirst != nullptr )
    free(pMem: v3->m_arrVarSlots._Myfirst);
  v3->m_arrVarSlots._Myfirst = nullptr;
  v3->m_arrVarSlots._Mylast = nullptr;
  v3->m_arrVarSlots._Myend = nullptr;
  free(pMem: v3);
  *rhCombo = nullptr;
  *v4 = iCommandEnd;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10004FD0
// Name: struct CfgProcessor::_unnamed_type_ComboHandle_ __near * CfgProcessor::Combo_Alloc(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *)
// Source: json
//------------------------------------------------------------------------------
ConfigurationProcessing::ComboHandleImpl *__cdecl CfgProcessor::Combo_Alloc(
        CfgProcessor::<unnamed_type_ComboHandle> *hComboCopyFrom)
{
  ConfigurationProcessing::ComboHandleImpl *result; // eax

  result = (ConfigurationProcessing::ComboHandleImpl *)operator new(nSize: 0x38u);
  if ( hComboCopyFrom != nullptr )
  {
    if ( result != nullptr )
      return ConfigurationProcessing::ComboHandleImpl::ComboHandleImpl(
               this: result,
               __that: (const ConfigurationProcessing::ComboHandleImpl *)hComboCopyFrom);
  }
  else if ( result != nullptr )
  {
    LODWORD(result->m_iTotalCommand) = 0;
    HIDWORD(result->m_iTotalCommand) = 0;
    LODWORD(result->m_iComboNumber) = 0;
    HIDWORD(result->m_iComboNumber) = 0;
    LODWORD(result->m_numCombos) = 0;
    HIDWORD(result->m_numCombos) = 0;
    result->m_pEntry = nullptr;
    result->__vftable = (ConfigurationProcessing::ComboHandleImpl_vtbl *)&ConfigurationProcessing::ComboHandleImpl::`vftable';
    result->m_arrVarSlots._Myfirst = nullptr;
    result->m_arrVarSlots._Mylast = nullptr;
    result->m_arrVarSlots._Myend = nullptr;
    return result;
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10005030
// Name: void CfgProcessor::Combo_Assign(struct CfgProcessor::_unnamed_type_ComboHandle_ __near *,struct CfgProcessor::_unnamed_type_ComboHandle_ __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CfgProcessor::Combo_Assign(
        CfgProcessor::<unnamed_type_ComboHandle> *hComboDst,
        CfgProcessor::<unnamed_type_ComboHandle> *hComboSrc)
{
  *(_DWORD *)&hComboDst[8] = *(_DWORD *)&hComboSrc[8];
  *(_DWORD *)&hComboDst[12] = *(_DWORD *)&hComboSrc[12];
  *(_DWORD *)&hComboDst[16] = *(_DWORD *)&hComboSrc[16];
  *(_DWORD *)&hComboDst[20] = *(_DWORD *)&hComboSrc[20];
  *(_DWORD *)&hComboDst[24] = *(_DWORD *)&hComboSrc[24];
  *(_DWORD *)&hComboDst[28] = *(_DWORD *)&hComboSrc[28];
  *(_DWORD *)&hComboDst[32] = *(_DWORD *)&hComboSrc[32];
  std::vector<int>::operator=(
    this: (std::vector<int> *)&hComboDst[36],
    _Right: (const std::vector<int> *)&hComboSrc[36]);
}

//------------------------------------------------------------------------------
// Address: 0x10005080
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>> std::_Tree<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > *__thiscall std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::erase(
        std::_Tree<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > _Last)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v7; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > v9; // edx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *i; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > v14; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Erase(
      this,
      _Rootnode: Myhead->_Parent);
    this->_Myhead->_Parent = this->_Myhead;
    this->_Myhead->_Left = this->_Myhead;
    this->_Myhead->_Right = this->_Myhead;
    v7 = this->_Myhead;
    this->_Mysize = 0;
    result->_Ptr = v7->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v9._Ptr = Ptr;
      if ( Ptr->_Isnil == 0 )
      {
        Right = Ptr->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( Ptr != i->_Right )
              break;
            Ptr = i;
          }
          _First._Ptr = i;
        }
        else
        {
          v11 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v11 = j;
          _First._Ptr = v11;
        }
      }
      std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::erase(
        this,
        result: &v14,
        _Where: v9);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005140
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>> std::_Tree<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > *__thiscall std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::erase(
        std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > _Where)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Ptr; // edi
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Right; // ebx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Parent; // esi
  std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *v7; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Left; // eax
  unsigned int Mysize; // eax

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>::operator++(this: &_Where);
  if ( Ptr->_Left->_Isnil != 0 )
  {
    Right = Ptr->_Right;
LABEL_8:
    Parent = Ptr->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    v7 = this;
    Myhead = this->_Myhead;
    if ( Myhead->_Parent == Ptr )
    {
      Myhead->_Parent = Right;
    }
    else if ( Parent->_Left == Ptr )
    {
      Parent->_Left = Right;
    }
    else
    {
      Parent->_Right = Right;
    }
    if ( this->_Myhead->_Left == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v9 = Parent;
      }
      else
      {
        v9 = std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Min(_Pnode: Right);
        v7 = this;
      }
      v7->_Myhead->_Left = v9;
    }
    if ( v7->_Myhead->_Right == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v7->_Myhead->_Right = Parent;
      }
      else
      {
        v10 = std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Max(_Pnode: Right);
        v7 = this;
        this->_Myhead->_Right = v10;
      }
    }
    goto LABEL_35;
  }
  if ( Ptr->_Right->_Isnil != 0 )
  {
    Right = Ptr->_Left;
    goto LABEL_8;
  }
  v5 = _Where._Ptr;
  Right = _Where._Ptr->_Right;
  if ( _Where._Ptr == Ptr )
    goto LABEL_8;
  Ptr->_Left->_Parent = _Where._Ptr;
  v5->_Left = Ptr->_Left;
  if ( v5 == Ptr->_Right )
  {
    Parent = v5;
  }
  else
  {
    Parent = v5->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    Parent->_Left = Right;
    v5->_Right = Ptr->_Right;
    Ptr->_Right->_Parent = v5;
  }
  v11 = this->_Myhead;
  if ( v11->_Parent == Ptr )
  {
    v11->_Parent = v5;
  }
  else
  {
    v12 = Ptr->_Parent;
    if ( v12->_Left == Ptr )
      v12->_Left = v5;
    else
      v12->_Right = v5;
  }
  v5->_Parent = Ptr->_Parent;
  Color = v5->_Color;
  v5->_Color = Ptr->_Color;
  Ptr->_Color = Color;
  v7 = this;
LABEL_35:
  if ( Ptr->_Color == 1 )
  {
    for ( ; Right != v7->_Myhead->_Parent; Parent = Parent->_Parent )
    {
      if ( Right->_Color != 1 )
        break;
      Left = Parent->_Left;
      if ( Right == Parent->_Left )
      {
        Left = Parent->_Right;
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Lrotate(
            this: v7,
            _Wherenode: Parent);
          Left = Parent->_Right;
          v7 = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Left->_Color != 1 || Left->_Right->_Color != 1 )
        {
          if ( Left->_Right->_Color == 1 )
          {
            Left->_Left->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Rrotate(
              this: v7,
              _Wherenode: Left);
            Left = Parent->_Right;
            v7 = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Lrotate(
            this: v7,
            _Wherenode: Parent);
          break;
        }
      }
      else
      {
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Rrotate(
            this: v7,
            _Wherenode: Parent);
          Left = Parent->_Left;
          v7 = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Right->_Color != 1 || Left->_Left->_Color != 1 )
        {
          if ( Left->_Left->_Color == 1 )
          {
            Left->_Right->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Lrotate(
              this: v7,
              _Wherenode: Left);
            Left = Parent->_Left;
            v7 = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Rrotate(
            this: v7,
            _Wherenode: Parent);
          break;
        }
      }
      Left->_Color = 0;
LABEL_53:
      Right = Parent;
    }
    Right->_Color = 1;
  }
  if ( Ptr->_Myval.m_sSuffix._Myres >= 0x10 )
    free(pMem: Ptr->_Myval.m_sSuffix._Bx._Ptr);
  Ptr->_Myval.m_sSuffix._Myres = 15;
  Ptr->_Myval.m_sSuffix._Mysize = 0;
  Ptr->_Myval.m_sSuffix._Bx._Buf[0] = 0;
  if ( Ptr->_Myval.m_sPrefix._Myres >= 0x10 )
    free(pMem: Ptr->_Myval.m_sPrefix._Bx._Ptr);
  Ptr->_Myval.m_sPrefix._Myres = 15;
  Ptr->_Myval.m_sPrefix._Mysize = 0;
  Ptr->_Myval.m_sPrefix._Bx._Buf[0] = 0;
  free(pMem: Ptr);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005470
// Name: protected: void std::_Tree<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Erase(struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Erase(
        std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *this,
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v2; // esi
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *i; // edi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    if ( v2->_Myval.m_sSuffix._Myres >= 0x10 )
      free(pMem: v2->_Myval.m_sSuffix._Bx._Ptr);
    v2->_Myval.m_sSuffix._Myres = 15;
    v2->_Myval.m_sSuffix._Mysize = 0;
    v2->_Myval.m_sSuffix._Bx._Buf[0] = 0;
    if ( v2->_Myval.m_sPrefix._Myres >= 0x10 )
      free(pMem: v2->_Myval.m_sPrefix._Bx._Ptr);
    v2->_Myval.m_sPrefix._Myres = 15;
    v2->_Myval.m_sPrefix._Mysize = 0;
    v2->_Myval.m_sPrefix._Bx._Buf[0] = 0;
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005500
// Name: protected: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>> std::_Tree<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Insert(
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x3FFFFFE )
  {
    if ( _Newnode->_Myval.second.m_arrVarSlots._Myfirst != nullptr )
      free(pMem: _Newnode->_Myval.second.m_arrVarSlots._Myfirst);
    _Newnode->_Myval.second.m_arrVarSlots._Myfirst = nullptr;
    _Newnode->_Myval.second.m_arrVarSlots._Mylast = nullptr;
    _Newnode->_Myval.second.m_arrVarSlots._Myend = nullptr;
    free(pMem: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  v6 = _Newnode;
  this->_Mysize = Mysize + 1;
  _Newnode->_Parent = _Wherenode;
  Myhead = this->_Myhead;
  if ( _Wherenode == Myhead )
  {
    Myhead->_Parent = _Newnode;
    this->_Myhead->_Left = _Newnode;
    v8 = this->_Myhead;
LABEL_11:
    v8->_Right = _Newnode;
    goto LABEL_12;
  }
  if ( !_Addleft )
  {
    _Wherenode->_Right = _Newnode;
    v8 = this->_Myhead;
    if ( _Wherenode != v8->_Right )
      goto LABEL_12;
    goto LABEL_11;
  }
  _Wherenode->_Left = _Newnode;
  v9 = this->_Myhead;
  if ( _Wherenode == v9->_Left )
    v9->_Left = _Newnode;
LABEL_12:
  v10 = _Newnode;
  while ( v10->_Parent->_Color == 0 )
  {
    Parent = v10->_Parent;
    v12 = Parent->_Parent;
    if ( Parent == v12->_Left )
    {
      Right = v12->_Right;
      if ( Right->_Color != 0 )
      {
        if ( v10 == Parent->_Right )
        {
          v10 = v10->_Parent;
          v14 = Parent->_Right;
          v10->_Right = v14->_Left;
          if ( v14->_Left->_Isnil == 0 )
            v14->_Left->_Parent = v10;
          v14->_Parent = v10->_Parent;
          v15 = this->_Myhead;
          if ( v10 == v15->_Parent )
          {
            v15->_Parent = v14;
          }
          else
          {
            v16 = v10->_Parent;
            if ( v10 == v16->_Left )
              v16->_Left = v14;
            else
              v16->_Right = v14;
          }
          v14->_Left = v10;
          v10->_Parent = v14;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Left;
        v17->_Left = v17->_Left->_Right;
        v19 = Left->_Right;
        if ( v19->_Isnil == 0 )
          v19->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v20 = this->_Myhead;
        if ( v17 == v20->_Parent )
        {
          v20->_Parent = Left;
          Left->_Right = v17;
        }
        else
        {
          v21 = v17->_Parent;
          if ( v17 == v21->_Right )
            v21->_Right = Left;
          else
            v21->_Left = Left;
          Left->_Right = v17;
        }
LABEL_52:
        v6 = _Newnode;
        v17->_Parent = Left;
        continue;
      }
      Parent->_Color = 1;
      Right->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
    else
    {
      v22 = v12->_Left;
      if ( v22->_Color != 0 )
      {
        if ( v10 == Parent->_Left )
        {
          v10 = v10->_Parent;
          v23 = Parent->_Left;
          v10->_Left = v23->_Right;
          v24 = v23->_Right;
          if ( v24->_Isnil == 0 )
            v24->_Parent = v10;
          v23->_Parent = v10->_Parent;
          v25 = this->_Myhead;
          if ( v10 == v25->_Parent )
          {
            v25->_Parent = v23;
          }
          else
          {
            v26 = v10->_Parent;
            if ( v10 == v26->_Right )
              v26->_Right = v23;
            else
              v26->_Left = v23;
          }
          v23->_Right = v10;
          v10->_Parent = v23;
        }
        v10->_Parent->_Color = 1;
        v10->_Parent->_Parent->_Color = 0;
        v17 = v10->_Parent->_Parent;
        Left = v17->_Right;
        v17->_Right = Left->_Left;
        if ( Left->_Left->_Isnil == 0 )
          Left->_Left->_Parent = v17;
        Left->_Parent = v17->_Parent;
        v27 = this->_Myhead;
        if ( v17 == v27->_Parent )
        {
          v27->_Parent = Left;
        }
        else
        {
          v28 = v17->_Parent;
          if ( v17 == v28->_Left )
            v28->_Left = Left;
          else
            v28->_Right = Left;
        }
        Left->_Left = v17;
        goto LABEL_52;
      }
      Parent->_Color = 1;
      v22->_Color = 1;
      v10->_Parent->_Parent->_Color = 0;
      v10 = v10->_Parent->_Parent;
    }
  }
  v29 = this->_Myhead->_Parent;
  result->_Ptr = v6;
  v29->_Color = 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005740
// Name: public: struct std::_Tree_nod<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,0>>::_Buynode<char const __near * __near &>(char const __near * __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *__thiscall std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Buynode<char const * &>(
        std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > *this,
        char **_Val)
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *pMem; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node **)operator new(nSize: 0x2Cu);
  pMem = v3;
  if ( v3 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *v3 = this->_Myhead;
  v3[1] = this->_Myhead;
  v3[2] = this->_Myhead;
  *((_WORD *)v3 + 20) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<std::string>,std::string,char const * &>(
    _Alval: &this->_Alval,
    _Pdest: (std::string *)(v3 + 3),
    _Src: _Val);
  v9 = -1;
  return (std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10005800
// Name: void std::_Destroy_range<class std::allocator<class Define>>(class Define __near *,class Define __near *,class std::allocator<class Define> __near &,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Destroy_range<std::allocator<Define>>(Define *_First, Define *_Last)
{
  Define *i; // esi

  for ( i = _First; i != _Last; ++i )
  {
    if ( i->m_sName._Myres >= 0x10 )
      free(pMem: i->m_sName._Bx._Ptr);
    i->m_sName._Myres = 15;
    i->m_sName._Mysize = 0;
    i->m_sName._Bx._Buf[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10005840
// Name: public: struct std::pair<class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>>,bool> std::_Tree<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Linsert(struct std::_Tree_nod<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > >,bool> *__thiscall std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Linsert(
        std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *this,
        std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > >,bool> *result,
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Node,
        bool _Leftish)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Parent; // esi
  int v6; // ebx
  unsigned int v7; // edx
  unsigned int v8; // edi
  unsigned __int64 v9; // rax
  unsigned __int64 v10; // rax
  std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *v12; // [esp+4h] [ebp-Ch]
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *_Wherenode; // [esp+8h] [ebp-8h]
  bool _Addleft; // [esp+Ch] [ebp-4h]

  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v12 = this;
  _Addleft = true;
  if ( Parent->_Isnil == 0 )
  {
    while ( 1 )
    {
      _Wherenode = Parent;
      v6 = ComboGenerator::NumCombos(this: Parent->_Myval.m_pCg);
      v8 = v7;
      if ( _Leftish )
      {
        LODWORD(v9) = ComboGenerator::NumCombos(this: _Node->_Myval.m_pCg);
        LOBYTE(v9) = __PAIR64__(v8, v6) < v9;
        _Addleft = (_BYTE)v9 == 0;
        if ( (_BYTE)v9 != 0 )
          goto LABEL_8;
        Parent = Parent->_Left;
      }
      else
      {
        LODWORD(v10) = ComboGenerator::NumCombos(this: _Node->_Myval.m_pCg);
        if ( v10 >= __PAIR64__(v8, v6) )
        {
          _Addleft = false;
LABEL_8:
          Parent = Parent->_Right;
          goto LABEL_9;
        }
        Parent = Parent->_Left;
        _Addleft = true;
      }
LABEL_9:
      if ( Parent->_Isnil != 0 )
      {
        Myhead = _Wherenode;
        this = v12;
        break;
      }
    }
  }
  result->first = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > >)std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Insert(this, result: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > *)&_Leftish, _Addleft, _Wherenode: Myhead, _Newnode: _Node)->_Ptr;
  result->second = true;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10005900
// Name: public: struct std::_List_nod<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>::_Node __near * std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>::_Buynode<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>(struct std::_List_nod<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>::_Node __near *,struct std::_List_nod<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>::_Node __near *,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int> __near &&)
// Source: json
//------------------------------------------------------------------------------
std::_List_nod<std::pair<std::string const ,int>>::_Node *__thiscall std::_List_val<std::pair<std::string const,int>>::_Buynode<std::pair<std::string const,int>>(
        std::_List_val<std::pair<std::string const ,int>> *this,
        std::_List_nod<std::pair<std::string const ,int>>::_Node *_Next,
        std::_List_nod<std::pair<std::string const ,int>>::_Node *_Prev,
        std::pair<std::string const ,int> *_Val)
{
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  int v8; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *pMem; // [esp+18h] [ebp-14h]
  int *v11; // [esp+1Ch] [ebp-10h]
  int v12; // [esp+28h] [ebp-4h]

  v11 = &v8;
  v5 = operator new(nSize: 0x28u);
  v6 = v5;
  pMem = v5;
  if ( v5 == nullptr )
  {
    _Next = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Next);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  v12 = 0;
  *v5 = _Next;
  v5[1] = _Prev;
  std::_Cons_val<std::allocator<std::pair<std::string const,int>>,std::pair<std::string const,int>,std::pair<std::string const,int>>(
    _Alval: &this->_Alval,
    _Pdest: (std::pair<std::string const ,int> *)(v5 + 2),
    _Src: _Val);
  v12 = -1;
  return (std::_List_nod<std::pair<std::string const ,int>>::_Node *)v6;
}

//------------------------------------------------------------------------------
// Address: 0x100059C0
// Name: protected: class IExpression __near * CComplexExpression::ParseTopLevel(char __near * __near &)
// Source: json
//------------------------------------------------------------------------------
IExpression *__thiscall CComplexExpression::ParseTopLevel(CComplexExpression *this, char **szExpression)
{
  const char **v2; // esi
  CExprBinary **v3; // edi
  char v4; // cl
  CExprBinary *v5; // eax
  CExprBinary *v6; // edi
  CExprBinary *v7; // eax
  CExprBinary *v8; // eax
  CExprBinary *v9; // eax
  CExprBinary *v10; // eax
  CExprBinary *v11; // eax
  char v12; // al
  CExprBinary *v13; // eax
  CExprBinary *v14; // eax
  CComplexExpression *v15; // esi
  IExpression **Mylast; // eax
  IExpression **v17; // edx
  IExpression **v18; // ecx
  int v19; // ebx
  unsigned int v20; // eax
  unsigned int v21; // eax
  unsigned int v22; // ecx
  unsigned int v23; // ecx
  IExpression **v24; // eax
  IExpression **Myend; // ecx
  IExpression **Myfirst; // edx
  unsigned int v27; // eax
  unsigned int v28; // eax
  unsigned int v29; // ecx
  unsigned int v30; // ecx
  _DWORD *v31; // eax
  CExprBinary **v32; // ebx
  int v33; // eax
  CExprBinary *v34; // esi
  int v35; // ebx
  unsigned int v36; // ecx
  int v37; // eax
  CExprBinary **v38; // edx
  unsigned int v39; // eax
  CExprBinary *v40; // ecx
  int v41; // edi
  unsigned int v42; // ecx
  unsigned int v43; // eax
  unsigned int v44; // eax
  unsigned int v45; // ecx
  unsigned int v46; // eax
  unsigned int v47; // eax
  CComplexExpression *v48; // ecx
  IExpression *m_pDefFalse; // esi
  int v50; // eax
  unsigned int v51; // edx
  QuickStack<CExprBinary *> exprStack; // [esp+Ch] [ebp-24h] BYREF
  int nPriority; // [esp+1Ch] [ebp-14h]
  IExpression *pFirstToken; // [esp+20h] [ebp-10h]
  CComplexExpression *v56; // [esp+24h] [ebp-Ch]
  CExprBinary *v57; // [esp+28h] [ebp-8h] BYREF
  CExprBinary *pBinaryExpression; // [esp+2Ch] [ebp-4h] BYREF

  v2 = (const char **)szExpression;
  v3 = nullptr;
  v56 = this;
  memset(&exprStack, 0, 12);
  pFirstToken = CComplexExpression::ParseInternal(this, szExpression);
  while ( 1 )
  {
    for ( ; **v2 != 0; ++*v2 )
    {
      if ( isspace(c: **v2) == 0 )
        break;
    }
    v4 = **v2;
    if ( v4 == 0 || v4 == 41 )
      break;
    if ( strncmp(first: *v2, last: "&&", count: 2u) == 0 )
    {
      v5 = (CExprBinary *)operator new(nSize: 0xCu);
      if ( v5 != nullptr )
      {
        v5->m_x = nullptr;
        v5->m_y = nullptr;
        v5->__vftable = (CExprBinary_vtbl *)&CExprBinary_And::`vftable';
        *v2 += 2;
        v6 = v5;
        goto LABEL_34;
      }
LABEL_25:
      v6 = nullptr;
      *v2 += 2;
      goto LABEL_34;
    }
    if ( strncmp(first: *v2, last: "||", count: 2u) == 0 )
    {
      v7 = (CExprBinary *)operator new(nSize: 0xCu);
      if ( v7 != nullptr )
      {
        v7->m_x = nullptr;
        v7->m_y = nullptr;
        v7->__vftable = (CExprBinary_vtbl *)&CExprBinary_Or::`vftable';
        *v2 += 2;
        v6 = v7;
        goto LABEL_34;
      }
      goto LABEL_25;
    }
    if ( strncmp(first: *v2, last: ">=", count: 2u) == 0 )
    {
      v8 = (CExprBinary *)operator new(nSize: 0xCu);
      if ( v8 != nullptr )
      {
        v8->m_x = nullptr;
        v8->m_y = nullptr;
        v8->__vftable = (CExprBinary_vtbl *)&CExprBinary_Ge::`vftable';
        *v2 += 2;
        v6 = v8;
        goto LABEL_34;
      }
      goto LABEL_25;
    }
    if ( strncmp(first: *v2, last: "<=", count: 2u) == 0 )
    {
      v9 = (CExprBinary *)operator new(nSize: 0xCu);
      if ( v9 != nullptr )
      {
        v9->m_x = nullptr;
        v9->m_y = nullptr;
        v9->__vftable = (CExprBinary_vtbl *)&CExprBinary_Le::`vftable';
        *v2 += 2;
        v6 = v9;
        goto LABEL_34;
      }
      goto LABEL_25;
    }
    if ( strncmp(first: *v2, last: "==", count: 2u) == 0 )
    {
      v10 = (CExprBinary *)operator new(nSize: 0xCu);
      if ( v10 != nullptr )
      {
        v10->m_x = nullptr;
        v10->m_y = nullptr;
        v10->__vftable = (CExprBinary_vtbl *)&CExprBinary_Eq::`vftable';
        *v2 += 2;
        v6 = v10;
        goto LABEL_34;
      }
      goto LABEL_25;
    }
    if ( strncmp(first: *v2, last: "!=", count: 2u) == 0 )
    {
      v11 = (CExprBinary *)operator new(nSize: 0xCu);
      if ( v11 != nullptr )
      {
        v11->m_x = nullptr;
        v11->m_y = nullptr;
        v11->__vftable = (CExprBinary_vtbl *)&CExprBinary_Neq::`vftable';
        *v2 += 2;
        v6 = v11;
        goto LABEL_34;
      }
      goto LABEL_25;
    }
    v12 = **v2;
    if ( v12 == 62 )
    {
      v13 = (CExprBinary *)operator new(nSize: 0xCu);
      if ( v13 == nullptr )
        goto LABEL_32;
      v13->m_x = nullptr;
      v13->m_y = nullptr;
      v13->__vftable = (CExprBinary_vtbl *)&CExprBinary_G::`vftable';
      v6 = v13;
    }
    else
    {
      if ( v12 != 60 )
      {
        v48 = v56;
        **v2 = 0;
        m_pDefFalse = v48->m_pDefFalse;
        goto LABEL_103;
      }
      v14 = (CExprBinary *)operator new(nSize: 0xCu);
      if ( v14 == nullptr )
      {
LABEL_32:
        v6 = nullptr;
        goto LABEL_33;
      }
      v14->m_x = nullptr;
      v14->m_y = nullptr;
      v14->__vftable = (CExprBinary_vtbl *)&CExprBinary_L::`vftable';
      v6 = v14;
    }
LABEL_33:
    ++*v2;
LABEL_34:
    v15 = v56;
    Mylast = v56->m_arrAllExpressions._Mylast;
    pBinaryExpression = v6;
    v57 = v6;
    if ( &v57 >= Mylast || (v17 = v56->m_arrAllExpressions._Myfirst) > &v57 )
    {
      Myend = v56->m_arrAllExpressions._Myend;
      if ( Mylast == Myend )
      {
        Myfirst = v56->m_arrAllExpressions._Myfirst;
        v27 = Mylast - Myfirst;
        if ( v27 > 0x3FFFFFFE )
          goto LABEL_95;
        v28 = v27 + 1;
        v29 = Myend - Myfirst;
        if ( v28 > v29 )
        {
          if ( 0x3FFFFFFF - (v29 >> 1) >= v29 )
            v30 = (v29 >> 1) + v29;
          else
            v30 = 0;
          if ( v30 < v28 )
            v30 = v28;
          std::vector<int>::reserve(this: (std::vector<int> *)&v56->m_arrAllExpressions, _Count: v30);
        }
      }
      v31 = v15->m_arrAllExpressions._Mylast;
      if ( v31 != nullptr )
        *v31 = v6;
    }
    else
    {
      v18 = v56->m_arrAllExpressions._Myend;
      v19 = &v57 - (CExprBinary **)v17;
      nPriority = v19;
      if ( Mylast == v18 )
      {
        v20 = Mylast - v17;
        if ( v20 > 0x3FFFFFFE )
          goto LABEL_95;
        v21 = v20 + 1;
        v22 = v18 - v17;
        if ( v21 > v22 )
        {
          if ( 0x3FFFFFFF - (v22 >> 1) >= v22 )
            v23 = (v22 >> 1) + v22;
          else
            v23 = 0;
          if ( v23 < v21 )
            v23 = v21;
          std::vector<int>::reserve(this: (std::vector<int> *)&v56->m_arrAllExpressions, _Count: v23);
          v19 = nPriority;
        }
      }
      v24 = v15->m_arrAllExpressions._Mylast;
      if ( v24 != nullptr )
        *v24 = v15->m_arrAllExpressions._Myfirst[v19];
    }
    v32 = exprStack._Mylast;
    ++v15->m_arrAllExpressions._Mylast;
    v6->m_y = CComplexExpression::ParseInternal(this: v15, szExpression);
    v33 = v6->Priority(this: v6);
    v34 = (CExprBinary *)pFirstToken;
    nPriority = v33;
    if ( (((char *)v32 - (char *)exprStack._Myfirst) & 0xFFFFFFFC) != 0 )
    {
      v35 = (char *)v32 - (char *)exprStack._Myfirst;
      do
      {
        v36 = (v35 >> 2) - 1;
        if ( v35 >> 2 <= v36 )
          goto $LN465;
        v34 = exprStack._Myfirst[v36];
        v37 = v34->Priority(this: v34);
        if ( nPriority <= v37 )
          break;
        if ( exprStack._Myfirst != exprStack._Mylast )
        {
          --exprStack._Mylast;
          v35 -= 4;
        }
      }
      while ( (v35 & 0xFFFFFFFC) != 0 );
      v32 = exprStack._Mylast;
    }
    v38 = exprStack._Myfirst;
    v39 = v32 - exprStack._Myfirst;
    if ( v39 != 0 )
    {
      v40 = exprStack._Myfirst[v39 - 1];
      v6->m_x = v40->m_y;
      v40->m_y = v6;
    }
    else
    {
      v6->m_x = v34;
    }
    if ( &pBinaryExpression >= v32 || v38 > &pBinaryExpression )
    {
      if ( v32 == exprStack._Myend )
      {
        if ( v39 > 0x3FFFFFFE )
LABEL_95:
          std::_Xlength_error(_Message: "vector<T> too long");
        v45 = v39 + 1;
        v46 = exprStack._Myend - v38;
        if ( v45 > v46 )
        {
          if ( 0x3FFFFFFF - (v46 >> 1) >= v46 )
            v47 = (v46 >> 1) + v46;
          else
            v47 = 0;
          if ( v47 < v45 )
            v47 = v45;
          std::vector<int>::reserve(this: (std::vector<int> *)&exprStack, _Count: v47);
          v32 = exprStack._Mylast;
        }
      }
      if ( v32 != nullptr )
        *v32 = v6;
      v2 = (const char **)szExpression;
      v3 = exprStack._Myfirst;
      exprStack._Mylast = v32 + 1;
    }
    else
    {
      v41 = &pBinaryExpression - v38;
      if ( v32 == exprStack._Myend )
      {
        if ( v39 > 0x3FFFFFFE )
          goto LABEL_95;
        v42 = v39 + 1;
        v43 = exprStack._Myend - v38;
        if ( v42 > v43 )
        {
          if ( 0x3FFFFFFF - (v43 >> 1) >= v43 )
            v44 = (v43 >> 1) + v43;
          else
            v44 = 0;
          if ( v44 < v42 )
            v44 = v42;
          std::vector<int>::reserve(this: (std::vector<int> *)&exprStack, _Count: v44);
          v32 = exprStack._Mylast;
          v38 = exprStack._Myfirst;
        }
      }
      if ( v32 != nullptr )
        *v32 = v38[v41];
      v2 = (const char **)szExpression;
      v3 = exprStack._Myfirst;
      exprStack._Mylast = v32 + 1;
    }
  }
  m_pDefFalse = pFirstToken;
  v50 = (char *)exprStack._Mylast - (char *)v3;
  while ( (v50 & 0xFFFFFFFC) != 0 )
  {
    v51 = (v50 >> 2) - 1;
    if ( v50 >> 2 <= v51 )
$LN465:
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    m_pDefFalse = v3[v51];
    if ( v3 != (CExprBinary **)((char *)v3 + v50) )
      v50 -= 4;
  }
LABEL_103:
  if ( v3 != nullptr )
    free(pMem: v3);
  return m_pDefFalse;
}

//------------------------------------------------------------------------------
// Address: 0x10005E90
// Name: struct CfgProcessor::_unnamed_type_ComboHandle_ __near * CfgProcessor::Combo_GetCombo(unsigned __int64)
// Source: json
//------------------------------------------------------------------------------
ConfigurationProcessing::ComboHandleImpl *__cdecl CfgProcessor::Combo_GetCombo(unsigned __int64 iCommandNumber)
{
  unsigned int v1; // ebx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Parent; // eax
  unsigned int v4; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v5; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v6; // eax
  ConfigurationProcessing::ComboHandleImpl *p_emptyCPCHI; // esi
  int first_high; // edx
  ConfigurationProcessing::ComboHandleImpl *v9; // eax
  ConfigurationProcessing::ComboHandleImpl *v10; // esi
  ConfigurationProcessing::ComboHandleImpl emptyCPCHI; // [esp+8h] [ebp-40h] BYREF
  unsigned __int64 iCommandFound; // [esp+40h] [ebp-8h]

  v1 = HIDWORD(iCommandNumber);
  Myhead = ConfigurationProcessing::s_mapComboCommands._Myhead;
  Parent = ConfigurationProcessing::s_mapComboCommands._Myhead->_Parent;
  memset(&emptyCPCHI.m_iTotalCommand, 0, 40);
  v4 = iCommandNumber;
  iCommandFound = iCommandNumber;
  emptyCPCHI.__vftable = (ConfigurationProcessing::ComboHandleImpl_vtbl *)&ConfigurationProcessing::ComboHandleImpl::`vftable';
  v5 = ConfigurationProcessing::s_mapComboCommands._Myhead;
  while ( Parent->_Isnil == 0 )
  {
    if ( Parent->_Myval.first >= iCommandNumber )
    {
      v5 = Parent;
      Parent = Parent->_Left;
    }
    else
    {
      Parent = Parent->_Right;
    }
  }
  v6 = v5;
  HIDWORD(iCommandNumber) = v5;
  if ( ConfigurationProcessing::s_mapComboCommands._Myhead == v5 )
  {
    if ( ConfigurationProcessing::s_mapComboCommands._Mysize == 0 )
    {
      p_emptyCPCHI = &emptyCPCHI;
      goto LABEL_15;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator--(
      this: (std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *)&iCommandNumber
    + 1);
    v6 = (std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *)HIDWORD(iCommandNumber);
  }
  if ( __PAIR64__(v1, v4) < v6->_Myval.first )
  {
    if ( Myhead->_Left == v6 )
    {
      p_emptyCPCHI = &emptyCPCHI;
      goto LABEL_15;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator--(
      this: (std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >,std::_Iterator_base0> *)&iCommandNumber
    + 1);
    v6 = (std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *)HIDWORD(iCommandNumber);
  }
  first_high = HIDWORD(v6->_Myval.first);
  LODWORD(iCommandFound) = v6->_Myval.first;
  HIDWORD(iCommandFound) = first_high;
  p_emptyCPCHI = &v6->_Myval.second;
LABEL_15:
  if ( p_emptyCPCHI->m_iTotalCommand > __PAIR64__(v1, v4) )
    return nullptr;
  v9 = (ConfigurationProcessing::ComboHandleImpl *)operator new(nSize: 0x38u);
  if ( v9 != nullptr )
    v10 = ConfigurationProcessing::ComboHandleImpl::ComboHandleImpl(this: v9, __that: p_emptyCPCHI);
  else
    v10 = nullptr;
  iCommandNumber = __PAIR64__(v1, v4) - iCommandFound;
  ConfigurationProcessing::ComboHandleImpl::AdvanceCommands(this: v10, riAdvanceMore: &iCommandNumber);
  return v10;
}

//------------------------------------------------------------------------------
// Address: 0x10005FB0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>> std::_Tree<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > _Where)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *v7; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *i; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
  if ( Ptr->_Left->_Isnil != 0 )
  {
    Right = Ptr->_Right;
LABEL_8:
    Parent = Ptr->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    v7 = this;
    Myhead = this->_Myhead;
    if ( Myhead->_Parent == Ptr )
    {
      Myhead->_Parent = Right;
    }
    else if ( Parent->_Left == Ptr )
    {
      Parent->_Left = Right;
    }
    else
    {
      Parent->_Right = Right;
    }
    if ( this->_Myhead->_Left == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v9 = Parent;
      }
      else
      {
        v9 = std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Min(_Pnode: Right);
        v7 = this;
      }
      v7->_Myhead->_Left = v9;
    }
    v10 = v7->_Myhead;
    if ( v10->_Right == Ptr )
    {
      if ( Right->_Isnil != 0 )
        v10->_Right = Parent;
      else
        v10->_Right = std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Max(_Pnode: Right);
    }
    goto LABEL_35;
  }
  if ( Ptr->_Right->_Isnil != 0 )
  {
    Right = Ptr->_Left;
    goto LABEL_8;
  }
  v5 = _Where._Ptr;
  Right = _Where._Ptr->_Right;
  if ( _Where._Ptr == Ptr )
    goto LABEL_8;
  Ptr->_Left->_Parent = _Where._Ptr;
  v5->_Left = Ptr->_Left;
  if ( v5 == Ptr->_Right )
  {
    Parent = v5;
  }
  else
  {
    Parent = v5->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    Parent->_Left = Right;
    v5->_Right = Ptr->_Right;
    Ptr->_Right->_Parent = v5;
  }
  v11 = this->_Myhead;
  if ( v11->_Parent == Ptr )
  {
    v11->_Parent = v5;
  }
  else
  {
    v12 = Ptr->_Parent;
    if ( v12->_Left == Ptr )
      v12->_Left = v5;
    else
      v12->_Right = v5;
  }
  v5->_Parent = Ptr->_Parent;
  Color = v5->_Color;
  v5->_Color = Ptr->_Color;
  Ptr->_Color = Color;
LABEL_35:
  if ( _Erasednode->_Color == 1 )
  {
    for ( i = this; Right != i->_Myhead->_Parent; Parent = Parent->_Parent )
    {
      if ( Right->_Color != 1 )
        break;
      Left = Parent->_Left;
      if ( Right == Parent->_Left )
      {
        Left = Parent->_Right;
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Right;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Left->_Color != 1 || Left->_Right->_Color != 1 )
        {
          if ( Left->_Right->_Color == 1 )
          {
            Left->_Left->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Lrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      else
      {
        if ( Left->_Color == 0 )
        {
          Left->_Color = 1;
          Parent->_Color = 0;
          std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          Left = Parent->_Left;
          i = this;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Right->_Color != 1 || Left->_Left->_Color != 1 )
        {
          if ( Left->_Left->_Color == 1 )
          {
            Left->_Right->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Rrotate(
            this: i,
            _Wherenode: Parent);
          break;
        }
      }
      Left->_Color = 0;
LABEL_53:
      Right = Parent;
    }
    Right->_Color = 1;
  }
  if ( _Erasednode->_Myval.second.m_arrVarSlots._Myfirst != nullptr )
    free(pMem: _Erasednode->_Myval.second.m_arrVarSlots._Myfirst);
  _Erasednode->_Myval.second.m_arrVarSlots._Myfirst = nullptr;
  _Erasednode->_Myval.second.m_arrVarSlots._Mylast = nullptr;
  _Erasednode->_Myval.second.m_arrVarSlots._Myend = nullptr;
  free(pMem: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006220
// Name: protected: void std::_Tree<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Erase(
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v2; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *i; // edi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    if ( v2->_Myval.second.m_arrVarSlots._Myfirst != nullptr )
      free(pMem: v2->_Myval.second.m_arrVarSlots._Myfirst);
    v2->_Myval.second.m_arrVarSlots._Myfirst = nullptr;
    v2->_Myval.second.m_arrVarSlots._Mylast = nullptr;
    v2->_Myval.second.m_arrVarSlots._Myend = nullptr;
    free(pMem: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006280
// Name: protected: class Define __near * std::vector<class Define,class std::allocator<class Define>>::_Umove<class Define __near *>(class Define __near *,class Define __near *,class Define __near *)
// Source: json
//------------------------------------------------------------------------------
Define *__thiscall std::vector<Define>::_Umove<Define *>(
        std::vector<Define> *this,
        Define *_First,
        Define *_Last,
        Define *_Ptr)
{
  return std::_Uninit_move<Define *,Define *,std::allocator<Define>,Define>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: &this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x100062B0
// Name: public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>>,bool> std::_Tree<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > >,bool> *__thiscall std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Linsert(
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > >,bool> *result,
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *_Node,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > _Leftish)
{
  std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *v4; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v7; // ebx
  bool v9; // cl
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Ptr; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > *v11; // eax
  std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *v13; // [esp+Ch] [ebp-4h]
  bool _Addleft; // [esp+1Ch] [ebp+Ch]

  v4 = this;
  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v7 = Myhead;
  v9 = true;
  v13 = v4;
  _Addleft = true;
  while ( Parent->_Isnil == 0 )
  {
    v7 = Parent;
    if ( LOBYTE(_Leftish._Ptr) != 0 )
    {
      v9 = Parent->_Myval.first >= _Node->_Myval.first;
      _Addleft = v9;
      if ( Parent->_Myval.first < _Node->_Myval.first )
        goto LABEL_8;
      Parent = Parent->_Left;
    }
    else
    {
      if ( _Node->_Myval.first >= Parent->_Myval.first )
      {
        v9 = false;
        _Addleft = false;
LABEL_8:
        Parent = Parent->_Right;
        continue;
      }
      Parent = Parent->_Left;
      v9 = true;
      _Addleft = true;
    }
  }
  Ptr = v7;
  _Leftish._Ptr = v7;
  if ( v9 )
  {
    if ( v7 == v4->_Myhead->_Left )
    {
      v11 = std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Insert(
              this: v4,
              result: &_Leftish,
              _Addleft: true,
              _Wherenode: v7,
              _Newnode: _Node);
LABEL_13:
      result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > >)v11->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    Ptr = _Leftish._Ptr;
    v4 = v13;
  }
  if ( Ptr->_Myval.first < _Node->_Myval.first )
  {
    v11 = std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Insert(
            this: v4,
            result: &_Leftish,
            _Addleft,
            _Wherenode: v7,
            _Newnode: _Node);
    goto LABEL_13;
  }
  if ( _Node->_Myval.second.m_arrVarSlots._Myfirst != nullptr )
    free(pMem: _Node->_Myval.second.m_arrVarSlots._Myfirst);
  _Node->_Myval.second.m_arrVarSlots._Myfirst = nullptr;
  _Node->_Myval.second.m_arrVarSlots._Mylast = nullptr;
  _Node->_Myval.second.m_arrVarSlots._Myend = nullptr;
  free(pMem: _Node);
  result->first._Ptr = Ptr;
  result->second = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100063C0
// Name: public: class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> std::list<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>::erase(class std::_List_const_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>)
// Source: json
//------------------------------------------------------------------------------
std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *__thiscall std::list<std::pair<std::string const,int>>::erase(
        std::list<std::pair<std::string const ,int>> *this,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *result,
        std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> > _Where)
{
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Next; // ecx
  std::_List_nod<std::pair<std::string const ,int>>::_Node *_Wherea; // [esp+14h] [ebp+Ch]

  Next = _Where._Ptr->_Next;
  _Wherea = _Where._Ptr->_Next;
  if ( _Where._Ptr == this->_Myhead )
  {
    result->_Ptr = Next;
    return result;
  }
  else
  {
    _Where._Ptr->_Prev->_Next = _Where._Ptr->_Next;
    _Where._Ptr->_Next->_Prev = _Where._Ptr->_Prev;
    if ( _Where._Ptr->_Myval.first._Myres >= 0x10 )
      free(pMem: _Where._Ptr->_Myval.first._Bx._Ptr);
    _Where._Ptr->_Myval.first._Myres = 15;
    _Where._Ptr->_Myval.first._Mysize = 0;
    _Where._Ptr->_Myval.first._Bx._Buf[0] = 0;
    free(pMem: _Where._Ptr);
    --this->_Mysize;
    result->_Ptr = _Wherea;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006430
// Name: public: void CComplexExpression::Parse(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CComplexExpression::Parse(CComplexExpression *this, char *szExpression)
{
  char *v3; // eax
  char *v4; // eax
  char *v5; // eax
  char *Myfirst; // edi
  const char *v7; // eax
  unsigned int v8; // eax
  char *v9; // ebx
  QuickString qs; // [esp+Ch] [ebp-1Ch] BYREF
  unsigned int count; // [esp+1Ch] [ebp-Ch]
  char *szParse; // [esp+20h] [ebp-8h] BYREF
  char _Val[4]; // [esp+24h] [ebp-4h] BYREF

  CComplexExpression::Clear(this);
  v3 = (char *)operator new(nSize: 8u);
  if ( v3 != nullptr )
  {
    *(_DWORD *)v3 = &CExprConstant::`vftable';
    *((_DWORD *)v3 + 1) = 1;
    szParse = v3;
  }
  else
  {
    szParse = nullptr;
  }
  std::vector<int>::push_back(this: (std::vector<int> *)&this->m_arrAllExpressions, _Val: (int *)&szParse);
  this->m_pDefTrue = (IExpression *)szParse;
  v4 = (char *)operator new(nSize: 8u);
  if ( v4 != nullptr )
  {
    *(_DWORD *)v4 = &CExprConstant::`vftable';
    *((_DWORD *)v4 + 1) = 0;
    szParse = v4;
  }
  else
  {
    szParse = nullptr;
  }
  std::vector<int>::push_back(this: (std::vector<int> *)&this->m_arrAllExpressions, _Val: (int *)&szParse);
  v5 = szParse;
  this->m_pDefFalse = (IExpression *)szParse;
  this->m_pRoot = (IExpression *)v5;
  if ( szExpression != nullptr )
  {
    Myfirst = nullptr;
    memset(&qs, 0, 12);
    v7 = &szExpression[strlen(szExpression) + 1];
    count = v7 - (szExpression + 1);
    v8 = v7 - szExpression;
    _Val[0] = 0;
    if ( v8 != 0 )
    {
      std::vector<char>::_Insert_n(this: &qs, _Where: 0, _Count: v8, _Val);
      Myfirst = qs._Myfirst;
    }
    v9 = (char *)(qs._Mylast - Myfirst);
    if ( qs._Mylast == Myfirst )
      std::_Xout_of_range(_Message: "invalid vector<T> subscript");
    memcpy(dst: (unsigned __int8 *)Myfirst, src: (unsigned __int8 *)szExpression, count);
    szParse = Myfirst;
    this->m_pRoot = CComplexExpression::ParseTopLevel(this, szExpression: &szParse);
    if ( szParse != &Myfirst[(_DWORD)v9 - 1] )
      this->m_pRoot = this->m_pDefFalse;
    if ( Myfirst != nullptr )
      free(pMem: Myfirst);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006550
// Name: public: void std::list<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::list<std::pair<std::string const,int>>::clear(std::list<std::pair<std::string const ,int>> *this)
{
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Next; // esi
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v3; // ebx

  Next = this->_Myhead->_Next;
  this->_Myhead->_Next = this->_Myhead;
  this->_Myhead->_Prev = this->_Myhead;
  this->_Mysize = 0;
  if ( Next != this->_Myhead )
  {
    do
    {
      v3 = Next->_Next;
      if ( Next->_Myval.first._Myres >= 0x10 )
        free(pMem: Next->_Myval.first._Bx._Ptr);
      Next->_Myval.first._Myres = 15;
      Next->_Myval.first._Mysize = 0;
      Next->_Myval.first._Bx._Buf[0] = 0;
      free(pMem: Next);
      Next = v3;
    }
    while ( v3 != this->_Myhead );
  }
}

//------------------------------------------------------------------------------
// Address: 0x100065B0
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>> std::_Tree<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<class ConfigurationProcessing::CfgEntry,struct std::less<class ConfigurationProcessing::CfgEntry>,class std::allocator<class ConfigurationProcessing::CfgEntry>,1>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > *__thiscall std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::erase(
        std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > _Last)
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v7; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > v9; // edx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *j; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *i; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > v14; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Erase(
      this,
      _Rootnode: Myhead->_Parent);
    this->_Myhead->_Parent = this->_Myhead;
    this->_Myhead->_Left = this->_Myhead;
    this->_Myhead->_Right = this->_Myhead;
    v7 = this->_Myhead;
    this->_Mysize = 0;
    result->_Ptr = v7->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v9._Ptr = Ptr;
      if ( Ptr->_Isnil == 0 )
      {
        Right = Ptr->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( Ptr != i->_Right )
              break;
            Ptr = i;
          }
          _First._Ptr = i;
        }
        else
        {
          v11 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v11 = j;
          _First._Ptr = v11;
        }
      }
      std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::erase(
        this,
        result: &v14,
        _Where: v9);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006680
// Name: public: void std::vector<class Define,class std::allocator<class Define>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Define>::reserve(std::vector<Define> *this, unsigned int _Count)
{
  int v3; // edi
  Define *v4; // eax
  int v5; // [esp+0h] [ebp-20h] BYREF
  Define *_Ptr; // [esp+Ch] [ebp-14h]
  int *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( _Count > 0x6666666 )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    _Ptr = std::allocator<Define>::allocate(this: &this->_Alval, _Count);
    v8 = 0;
    std::vector<Define>::_Umove<Define *>(this, _First: this->_Myfirst, _Last: this->_Mylast, _Ptr);
    v8 = -1;
    v3 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
    {
      std::_Destroy_range<std::allocator<Define>>(_First: this->_Myfirst, _Last: this->_Mylast);
      free(pMem: this->_Myfirst);
    }
    v4 = _Ptr;
    this->_Myend = &_Ptr[_Count];
    this->_Mylast = &v4[v3];
    this->_Myfirst = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006780
// Name: protected: void std::_Hash<class std::_Hmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,int,class stdext::hash_compare<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>,0>>::_Check_size(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Check_size(
        std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string > >,std::allocator<std::pair<std::string const ,int> >,0> > *this)
{
  unsigned int Mysize; // eax
  unsigned int Maxidx; // esi
  int i; // eax
  std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >> *p_Vec; // ecx
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *Myfirst; // edi
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Myhead; // [esp-8h] [ebp-14h]
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > _Val; // [esp+8h] [ebp-4h] BYREF

  Mysize = this->_List._Mysize;
  Maxidx = this->_Maxidx;
  _Val._Ptr = (std::_List_nod<std::pair<std::string const ,int>>::_Node *)Maxidx;
  if ( (double)Mysize / (double)Maxidx > this->_Max_bucket_size )
  {
    for ( i = 0; i < 3; ++i )
    {
      if ( Maxidx >= 0x1FFFFFFF )
        break;
      Maxidx *= 2;
    }
    p_Vec = &this->_Vec;
    Myfirst = this->_Vec._Myfirst;
    _Val._Ptr = this->_List._Myhead;
    if ( Myfirst != this->_Vec._Mylast )
    {
      p_Vec = &this->_Vec;
      this->_Vec._Mylast = Myfirst;
    }
    std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Insert_n(
      this: p_Vec,
      _Where: (std::_Vector_const_iterator<std::_Vector_val<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >> >)p_Vec->_Myfirst,
      _Count: 2 * Maxidx,
      &_Val);
    this->_Mask = Maxidx - 1;
    Myhead = this->_List._Myhead;
    this->_Maxidx = Maxidx;
    std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Reinsert(
      this,
      _Last: (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >)Myhead);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006830
// Name: protected: void std::vector<class Define,class std::allocator<class Define>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Define>::_Reserve(std::vector<Define> *this, unsigned int _Count)
{
  unsigned int v2; // esi
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // eax

  v2 = this->_Mylast - this->_Myfirst;
  if ( 107374182 - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 107374182 - (v4 >> 1) >= v4 )
    {
      v5 = (v4 >> 1) + v4;
      if ( v5 < v3 )
        v5 = v3;
    }
    else
    {
      v5 = 0;
      if ( v3 != 0 )
        v5 = v3;
    }
    std::vector<Define>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100068C0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>> std::_Tree<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > _Last)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v7; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > v9; // edx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *i; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > v14; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Erase(
      this,
      _Rootnode: Myhead->_Parent);
    this->_Myhead->_Parent = this->_Myhead;
    this->_Myhead->_Left = this->_Myhead;
    this->_Myhead->_Right = this->_Myhead;
    v7 = this->_Myhead;
    this->_Mysize = 0;
    result->_Ptr = v7->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v9._Ptr = Ptr;
      if ( Ptr->_Isnil == 0 )
      {
        Right = Ptr->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = Ptr->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( Ptr != i->_Right )
              break;
            Ptr = i;
          }
          _First._Ptr = i;
        }
        else
        {
          v11 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v11 = j;
          _First._Ptr = v11;
        }
      }
      std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::erase(
        this,
        result: &v14,
        _Where: v9);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006980
// Name: protected: struct std::pair<class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>,bool> std::_Hash<class std::_Hmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,int,class stdext::hash_compare<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>,0>>::_Insert(struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int> const __near &,class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >,bool> *__thiscall std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Insert(
        std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string > >,std::allocator<std::pair<std::string const ,int> >,0> > *this,
        std::pair<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >,bool> *result,
        const std::pair<std::string const ,int> *_Val,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > _Plist)
{
  std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string > >,std::allocator<std::pair<std::string const ,int> >,0> > *v4; // ebx
  unsigned int Mask; // esi
  unsigned int v6; // edi
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *Myfirst; // edx
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Ptr; // ecx
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Myhead; // esi
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v10; // eax
  std::list<std::pair<std::string const ,int>> *p_List; // edx
  unsigned int Mysize; // ebx
  unsigned int v13; // edi
  const char *Buf; // eax
  unsigned int v15; // edx
  const std::pair<std::string const ,int> *v16; // ecx
  int v17; // eax
  bool v18; // sf
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v19; // ecx
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v20; // eax
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v21; // edx
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v22; // eax
  const std::pair<std::string const ,int> *v23; // eax
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Next; // edx
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v26; // eax
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v27; // [esp+Ch] [ebp-14h]
  unsigned int Myres; // [esp+10h] [ebp-10h]
  std::list<std::pair<std::string const ,int>> *v29; // [esp+14h] [ebp-Ch]
  unsigned int v31; // [esp+1Ch] [ebp-4h]

  v4 = this;
  Mask = this->_Mask;
  v6 = Mask
     & stdext::hash_compare<std::string,std::less<std::string>>::operator()(this: &this->comp, _Keyval: &_Val->first);
  v31 = v6;
  if ( v4->_Maxidx <= v6 )
  {
    v6 += -1 - (Mask >> 1);
    v31 = v6;
  }
  Myfirst = v4->_Vec._Myfirst;
  Ptr = Myfirst[2 * v6]._Ptr;
  Myhead = v4->_List._Myhead;
  v10 = &Myfirst[2 * v6];
  p_List = &v4->_List;
  v27 = Ptr;
  v29 = &v4->_List;
  if ( Myhead == Ptr || (Myhead = v10[1]._Ptr->_Next) == Ptr )
  {
LABEL_18:
    v19 = _Plist._Ptr;
    if ( Myhead != _Plist._Ptr->_Next )
    {
      std::list<std::pair<std::string const,int>>::_Splice_same(
        this: p_List,
        _Where: (std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> >)Myhead,
        _Right: p_List,
        _First: _Plist.std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> >,
        _Last: (std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> >)_Plist._Ptr->_Next,
        _Count: 1u);
      v19 = _Plist._Ptr;
    }
    v20 = v4->_Vec._Myfirst;
    v21 = v20[2 * v6]._Ptr;
    v22 = &v20[2 * v6];
    if ( v21 == v29->_Myhead )
    {
      v22->_Ptr = v19;
      this->_Vec._Myfirst[2 * v31 + 1]._Ptr = v19;
    }
    else if ( v21 == Myhead )
    {
      v22->_Ptr = v19;
    }
    else
    {
      Next = v22[1]._Ptr->_Next;
      v22[1]._Ptr = Next;
      if ( Next != v19 )
      {
        v26 = &this->_Vec._Myfirst[2 * v31 + 1];
        v26->_Ptr = v26->_Ptr->_Prev;
      }
    }
    std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Check_size(this);
    result->first = _Plist;
    result->second = true;
    return result;
  }
  Mysize = _Val->first._Mysize;
  Myres = _Val->first._Myres;
  while ( 1 )
  {
    Myhead = Myhead->_Prev;
    v13 = Myhead->_Myval.first._Mysize;
    Buf = Myhead->_Myval.first._Bx._Buf;
    if ( Myhead->_Myval.first._Myres >= 0x10 )
      Buf = *(const char **)Buf;
    v15 = Mysize;
    if ( Mysize >= v13 )
      v15 = Myhead->_Myval.first._Mysize;
    v16 = _Val;
    if ( Myres >= 0x10 )
      v16 = (const std::pair<std::string const ,int> *)_Val->first._Bx._Ptr;
    v17 = std::char_traits<char>::compare(_First1: v16->first._Bx._Buf, _First2: Buf, _Count: v15);
    v18 = v17 < 0;
    if ( v17 != 0 )
      break;
    if ( Mysize >= v13 )
    {
      LOBYTE(v17) = Mysize != v13;
      v18 = v17 < 0;
      break;
    }
LABEL_16:
    if ( Myhead == v27 )
      goto LABEL_17;
  }
  if ( v18 )
    goto LABEL_16;
  if ( Myres < 0x10 )
    v23 = _Val;
  else
    v23 = (const std::pair<std::string const ,int> *)_Val->first._Bx._Ptr;
  if ( std::string::compare(
         this: (std::string *)&Myhead->_Myval.first,
         _Off: 0,
         _N0: Myhead->_Myval.first._Mysize,
         _Ptr: v23->first._Bx._Buf,
         _Count: Mysize) < 0 )
  {
    Myhead = Myhead->_Next;
LABEL_17:
    v4 = this;
    v6 = v31;
    p_List = v29;
    goto LABEL_18;
  }
  std::list<std::pair<std::string const,int>>::erase(
    this: v29,
    result: (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)&_Val,
    _Where: _Plist.std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> >);
  result->first._Ptr = Myhead;
  result->second = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10006B00
// Name: protected: void std::_Hash<class std::_Hmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,int,class stdext::hash_compare<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>,0>>::_Reinsert(class std::_List_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>>)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Reinsert(
        std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string > >,std::allocator<std::pair<std::string const ,int> >,0> > *this,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > _Last)
{
  bool v3; // bl
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Next; // [esp-8h] [ebp-14h]
  std::pair<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >,bool> result; // [esp+4h] [ebp-8h] BYREF
  std::_List_nod<std::pair<std::string const ,int>>::_Node *_Lasta; // [esp+14h] [ebp+8h]

  if ( this->_List._Myhead->_Next != _Last._Ptr )
  {
    _Lasta = _Last._Ptr->_Prev;
    do
    {
      Next = this->_List._Myhead->_Next;
      v3 = Next == _Lasta;
      std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Insert(
        this,
        &result,
        _Val: &Next->_Myval,
        _Plist: (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >)Next);
    }
    while ( !v3 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006B50
// Name: void std::_Cons_val<class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>,struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>(class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>> __near &,struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl> __near *,struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl> __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>,std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>(
        std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> > *_Alval,
        std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> *_Pdest,
        std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> *_Src)
{
  if ( _Pdest != nullptr )
  {
    _Pdest->first = _Src->first;
    _Pdest->second.__vftable = (ConfigurationProcessing::ComboHandleImpl_vtbl *)&ConfigurationProcessing::ComboHandleImpl::`vftable';
    _Pdest->second.m_iTotalCommand = _Src->second.m_iTotalCommand;
    _Pdest->second.m_iComboNumber = _Src->second.m_iComboNumber;
    _Pdest->second.m_numCombos = _Src->second.m_numCombos;
    _Pdest->second.m_pEntry = _Src->second.m_pEntry;
    std::vector<int>::vector<int>(this: &_Pdest->second.m_arrVarSlots, _Right: &_Src->second.m_arrVarSlots);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006BB0
// Name: public: std::_Hash<class std::_Hmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,int,class stdext::hash_compare<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>,0>>::_Hash<class std::_Hmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,int,class stdext::hash_compare<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>,0>>(class stdext::hash_compare<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>> const __near &,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string > >,std::allocator<std::pair<std::string const ,int> >,0> > *__thiscall std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>(
        std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string > >,std::allocator<std::pair<std::string const ,int> >,0> > *this,
        std::_List_nod<std::pair<std::string const ,int>>::_Node *_Parg,
        const std::allocator<std::pair<std::string const ,int> > *_Al)
{
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v4; // eax
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Myhead; // edx
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *Myfirst; // edi
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *Mylast; // eax
  std::exception pExceptionObject; // [esp+8h] [ebp-Ch] BYREF

  this->comp.comp.std::binary_function<std::string,std::string,bool> = (std::binary_function<std::string,std::string,bool>)_Parg->_Next;
  this->_List._Mysize = 0;
  v4 = (std::_List_nod<std::pair<std::string const ,int>>::_Node *)operator new(nSize: 0x28u);
  if ( v4 == nullptr )
  {
    _Parg = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Parg);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  this->_List._Myhead = v4;
  v4->_Next = v4;
  this->_List._Myhead->_Prev = this->_List._Myhead;
  this->_Vec._Myfirst = nullptr;
  this->_Vec._Mylast = nullptr;
  this->_Vec._Myend = nullptr;
  Myhead = this->_List._Myhead;
  this->_Max_bucket_size = 1.0;
  Myfirst = this->_Vec._Myfirst;
  Mylast = this->_Vec._Mylast;
  _Parg = Myhead;
  if ( Myfirst != Mylast )
    this->_Vec._Mylast = Myfirst;
  std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Insert_n(
    this: &this->_Vec,
    _Where: (std::_Vector_const_iterator<std::_Vector_val<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >> >)this->_Vec._Myfirst,
    _Count: 0x10u,
    _Val: (const std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)&_Parg);
  this->_Mask = 7;
  this->_Maxidx = 8;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10006C70
// Name: public: void std::vector<class Define,class std::allocator<class Define>>::push_back(class Define const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<Define>::push_back(std::vector<Define> *this, const Define *_Val)
{
  Define *Mylast; // ecx
  int v4; // esi
  int v5; // eax
  Define *v6; // esi
  Define *v7; // ebx
  Define *v8; // ebx

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<Define>::_Reserve(this, _Count: 1u);
    v8 = this->_Mylast;
    if ( v8 != nullptr )
    {
      v8->m_sName._Myres = 15;
      v8->m_sName._Mysize = 0;
      v8->m_sName._Bx._Buf[0] = 0;
      std::string::assign(this: &v8->m_sName, _Right: &_Val->m_sName, _Roff: 0, _Count: 0xFFFFFFFF);
      v8->m_min = _Val->m_min;
      v8->m_max = _Val->m_max;
      v8->m_bStatic = _Val->m_bStatic;
    }
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<Define>::_Reserve(this, _Count: 1u);
    v5 = v4;
    v6 = this->_Mylast;
    v7 = &this->_Myfirst[v5];
    if ( v6 != nullptr )
    {
      v6->m_sName._Myres = 15;
      v6->m_sName._Mysize = 0;
      v6->m_sName._Bx._Buf[0] = 0;
      std::string::assign(this: &v6->m_sName, _Right: &v7->m_sName, _Roff: 0, _Count: 0xFFFFFFFF);
      v6->m_min = v7->m_min;
      v6->m_max = v7->m_max;
      v6->m_bStatic = v7->m_bStatic;
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x10006E10
// Name: public: void QuickStrIdx::Append(char const __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall QuickStrIdx::Append(QuickStrIdx *this, char *szName, int idx)
{
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Myhead; // ecx
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Next; // edi
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v6; // eax
  unsigned int Mysize; // ecx
  std::pair<std::string const ,int> v8; // [esp+Ch] [ebp-28h] BYREF
  std::pair<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >,bool> result; // [esp+2Ch] [ebp-8h] BYREF

  v8.first._Myres = 15;
  v8.first._Mysize = 0;
  v8.first._Bx._Buf[0] = 0;
  std::string::assign(this: (std::string *)&v8.first, _Ptr: szName, _Count: strlen(szName));
  Myhead = this->_List._Myhead;
  v8.second = idx;
  Next = Myhead->_Next;
  v6 = std::_List_val<std::pair<std::string const,int>>::_Buynode<std::pair<std::string const,int>>(
         this: &this->_List,
         _Next: Myhead->_Next,
         _Prev: Myhead->_Next->_Prev,
         _Val: &v8);
  Mysize = this->_List._Mysize;
  if ( Mysize == 134217726 )
    std::_Xlength_error(_Message: "list<T> too long");
  this->_List._Mysize = Mysize + 1;
  Next->_Prev = v6;
  v6->_Prev->_Next = v6;
  std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Insert(
    this,
    &result,
    _Val: &this->_List._Myhead->_Next->_Myval,
    _Plist: (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >)this->_List._Myhead->_Next);
  if ( v8.first._Myres >= 0x10 )
    free(pMem: v8.first._Bx._Ptr);
}

//------------------------------------------------------------------------------
// Address: 0x10006EC0
// Name: public: void ComboGenerator::AddDefine(class Define const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ComboGenerator::AddDefine(ComboGenerator *this, const Define *df)
{
  const Define *v2; // ebx

  v2 = df;
  if ( df->m_sName._Myres >= 0x10 )
    df = (const Define *)df->m_sName._Bx._Ptr;
  QuickStrIdx::Append(
    this: &this->m_mapDefines,
    szName: df->m_sName._Bx._Buf,
    idx: this->m_arrDefines._Mylast - this->m_arrDefines._Myfirst);
  std::vector<Define>::push_back(this: &this->m_arrDefines, _Val: v2);
  df = (const Define *)1;
  std::vector<int>::push_back(this: &this->m_arrVarSlots, _Val: (int *)&df);
}

//------------------------------------------------------------------------------
// Address: 0x10006F30
// Name: public: ComboGenerator::~ComboGenerator(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall ComboGenerator::~ComboGenerator(ComboGenerator *this)
{
  Define *Myfirst; // eax

  if ( this->m_arrVarSlots._Myfirst != nullptr )
    free(pMem: this->m_arrVarSlots._Myfirst);
  this->m_arrVarSlots._Myfirst = nullptr;
  this->m_arrVarSlots._Mylast = nullptr;
  this->m_arrVarSlots._Myend = nullptr;
  if ( this->m_mapDefines._Vec._Myfirst != nullptr )
    free(pMem: this->m_mapDefines._Vec._Myfirst);
  this->m_mapDefines._Vec._Myfirst = nullptr;
  this->m_mapDefines._Vec._Mylast = nullptr;
  this->m_mapDefines._Vec._Myend = nullptr;
  std::list<std::pair<std::string const,int>>::clear(this: &this->m_mapDefines._List);
  free(pMem: this->m_mapDefines._List._Myhead);
  Myfirst = this->m_arrDefines._Myfirst;
  if ( Myfirst != nullptr )
  {
    std::_Destroy_range<std::allocator<Define>>(_First: Myfirst, _Last: this->m_arrDefines._Mylast);
    free(pMem: this->m_arrDefines._Myfirst);
  }
  this->m_arrDefines._Myfirst = nullptr;
  this->m_arrDefines._Mylast = nullptr;
  this->m_arrDefines._Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10006FC0
// Name: public: virtual int ComboGenerator::GetVariableValue(int)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ComboGenerator::GetVariableValue(ComboGenerator *this, unsigned int nSlot)
{
  int *Myfirst; // eax

  Myfirst = this->m_arrVarSlots._Myfirst;
  if ( this->m_arrVarSlots._Mylast - Myfirst <= nSlot )
    std::_Xout_of_range(_Message: "invalid vector<T> subscript");
  return Myfirst[nSlot];
}

//------------------------------------------------------------------------------
// Address: 0x10006FF0
// Name: public: virtual char const __near * ComboGenerator::GetVariableName(int)
// Source: json
//------------------------------------------------------------------------------
Define *__thiscall ComboGenerator::GetVariableName(ComboGenerator *this, unsigned int nSlot)
{
  Define *Myfirst; // esi
  Define *result; // eax

  Myfirst = this->m_arrDefines._Myfirst;
  if ( this->m_arrDefines._Mylast - Myfirst <= nSlot )
    std::_Xout_of_range(_Message: "invalid vector<T> subscript");
  result = &Myfirst[nSlot];
  if ( result->m_sName._Myres >= 0x10 )
    return (Define *)result->m_sName._Bx._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007040
// Name: public: class std::_List_const_iterator<class std::_List_val<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>>> std::_Hash<class std::_Hmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,int,class stdext::hash_compare<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,int>>,0>>::lower_bound(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> > *__thiscall std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::lower_bound(
        std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string > >,std::allocator<std::pair<std::string const ,int> >,0> > *this,
        std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> > *result,
        const std::string *_Keyval)
{
  unsigned int Mask; // edi
  unsigned int v6; // eax
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *Myfirst; // edx
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Ptr; // ecx
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Myhead; // esi
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v10; // eax
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v11; // edx
  std::_List_nod<std::pair<std::string const ,int>>::_Node *Next; // eax
  unsigned int Mysize; // esi
  std::pair<std::string const ,int> *p_Myval; // eax
  const std::string *v15; // edx
  unsigned int v16; // edi
  unsigned int v17; // ecx
  int v18; // eax
  bool v19; // sf
  unsigned int v20; // esi
  const char *Buf; // eax
  unsigned int v22; // edi
  unsigned int v23; // edx
  const std::string *v24; // ecx
  int v25; // eax
  bool v26; // sf
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v28; // [esp+Ch] [ebp-Ch]
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v29; // [esp+10h] [ebp-8h]
  std::_List_nod<std::pair<std::string const ,int>>::_Node *v30; // [esp+14h] [ebp-4h]
  std::_List_nod<std::pair<std::string const ,int>>::_Node *_Where; // [esp+24h] [ebp+Ch]

  Mask = this->_Mask;
  v6 = Mask & stdext::hash_compare<std::string,std::less<std::string>>::operator()(this: &this->comp, _Keyval);
  if ( this->_Maxidx <= v6 )
    v6 += -1 - (Mask >> 1);
  Myfirst = this->_Vec._Myfirst;
  Ptr = Myfirst[2 * v6]._Ptr;
  Myhead = this->_List._Myhead;
  v10 = &Myfirst[2 * v6];
  v11 = Ptr;
  v29 = v10;
  v28 = Ptr;
  _Where = Ptr;
  v30 = Myhead;
  while ( 1 )
  {
    if ( Ptr == Myhead )
      Next = Myhead;
    else
      Next = v10[1]._Ptr->_Next;
    if ( v11 == Next )
    {
      result->_Ptr = Myhead;
      return result;
    }
    Mysize = _Keyval->_Mysize;
    p_Myval = &v11->_Myval;
    if ( _Keyval->_Myres < 0x10 )
      v15 = _Keyval;
    else
      v15 = (const std::string *)_Keyval->_Bx._Ptr;
    v16 = p_Myval->first._Mysize;
    v17 = v16;
    if ( v16 >= Mysize )
      v17 = _Keyval->_Mysize;
    if ( p_Myval->first._Myres >= 0x10 )
      p_Myval = (std::pair<std::string const ,int> *)p_Myval->first._Bx._Ptr;
    v18 = std::char_traits<char>::compare(_First1: p_Myval->first._Bx._Buf, _First2: v15->_Bx._Buf, _Count: v17);
    v19 = v18 < 0;
    if ( v18 == 0 )
    {
      if ( v16 < Mysize )
        goto LABEL_19;
      LOBYTE(v18) = v16 != Mysize;
      v19 = v18 < 0;
    }
    if ( !v19 )
      break;
LABEL_19:
    v11 = _Where->_Next;
    Myhead = v30;
    v10 = v29;
    Ptr = v28;
    _Where = _Where->_Next;
  }
  v20 = _Where->_Myval.first._Mysize;
  Buf = _Where->_Myval.first._Bx._Buf;
  if ( _Where->_Myval.first._Myres >= 0x10 )
    Buf = *(const char **)Buf;
  v22 = _Keyval->_Mysize;
  v23 = v22;
  if ( v22 >= v20 )
    v23 = _Where->_Myval.first._Mysize;
  if ( _Keyval->_Myres < 0x10 )
    v24 = _Keyval;
  else
    v24 = (const std::string *)_Keyval->_Bx._Ptr;
  v25 = std::char_traits<char>::compare(_First1: v24->_Bx._Buf, _First2: Buf, _Count: v23);
  v26 = v25 < 0;
  if ( v25 == 0 )
  {
    if ( v22 >= v20 )
    {
      LOBYTE(v25) = v22 != v20;
      v26 = v25 < 0;
      goto LABEL_30;
    }
LABEL_31:
    result->_Ptr = v30;
    return result;
  }
LABEL_30:
  if ( v26 )
    goto LABEL_31;
  result->_Ptr = _Where;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10007180
// Name: public: int QuickStrIdx::Get(char const __near *)const
// Source: json
//------------------------------------------------------------------------------
int __thiscall QuickStrIdx::Get(QuickStrIdx *this, char *szName)
{
  std::string _Keyval; // [esp+8h] [ebp-1Ch] BYREF

  _Keyval._Myres = 15;
  _Keyval._Mysize = 0;
  _Keyval._Bx._Buf[0] = 0;
  std::string::assign(this: &_Keyval, _Ptr: szName, _Count: strlen(szName));
  std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::lower_bound(
    this,
    result: (std::_List_const_iterator<std::_List_val<std::pair<std::string const ,int>> > *)&szName,
    &_Keyval);
  if ( _Keyval._Myres >= 0x10 )
    free(pMem: _Keyval._Bx._Ptr);
  if ( (char *)this->_List._Myhead == szName )
    return -1;
  else
    return *((_DWORD *)szName + 9);
}

//------------------------------------------------------------------------------
// Address: 0x10007200
// Name: public: virtual int ComboGenerator::GetVariableSlot(char const __near *)
// Source: json
//------------------------------------------------------------------------------
int __thiscall ComboGenerator::GetVariableSlot(ComboGenerator *this, char *szVariableName)
{
  return QuickStrIdx::Get(this: &this->m_mapDefines, szName: szVariableName);
}

//------------------------------------------------------------------------------
// Address: 0x10007210
// Name: bool ConfigurationProcessing::ProcessSection(class ConfigurationProcessing::CfgEntry __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl ConfigurationProcessing::ProcessSection(ConfigurationProcessing::CfgEntry *cfge)
{
  char *Line; // eax
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v2; // eax
  std::string *p_Myval; // eax
  char *v4; // esi
  ComboGenerator *v6; // esi
  _DWORD *v7; // eax
  char *i; // esi
  char j; // al
  _BYTE *v10; // eax
  unsigned __int8 *v11; // ebx
  char *k; // edi
  int v13; // eax
  int v14; // edi
  int v15; // ebx
  char *v16; // eax
  char *v17; // eax
  char *v18; // eax
  Define v19; // [esp+8h] [ebp-38h] BYREF
  std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >,bool> v20; // [esp+30h] [ebp-10h] BYREF
  ComboGenerator *v21; // [esp+38h] [ebp-8h]
  bool bStaticDefines; // [esp+3Fh] [ebp-1h] BYREF

  Line = ConfigurationProcessing::NextLine();
  if ( Line != nullptr )
  {
    *(_DWORD *)&v20.second = Line;
    v2 = std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Buynode<char const * &>(
           this: &ConfigurationProcessing::s_strPool,
           _Val: (char **)&v20.second);
    std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Linsert(
      this: &ConfigurationProcessing::s_strPool,
      result: &v20,
      _Node: v2,
      _Leftish: 0);
    if ( ConfigurationProcessing::s_strPool._Myhead == v20.first._Ptr )
    {
      p_Myval = nullptr;
    }
    else
    {
      p_Myval = &v20.first._Ptr->_Myval;
      if ( v20.first._Ptr->_Myval._Myres >= 0x10 )
        p_Myval = (std::string *)p_Myval->_Bx._Ptr;
    }
    cfge->m_szShaderSrc = (const char *)p_Myval;
  }
  v4 = ConfigurationProcessing::NextLine();
  if ( v4 == nullptr )
    return false;
  while ( strncmp(first: v4, last: "#DEFINES-", count: 9u) != 0 )
  {
    v4 = ConfigurationProcessing::NextLine();
    if ( v4 == nullptr )
      return false;
  }
  bStaticDefines = v4[9] == 83;
  v6 = (ComboGenerator *)operator new(nSize: 0x50u);
  if ( v6 != nullptr )
  {
    v6->__vftable = (ComboGenerator_vtbl *)&ComboGenerator::`vftable';
    v6->m_arrDefines._Myfirst = nullptr;
    v6->m_arrDefines._Mylast = nullptr;
    v6->m_arrDefines._Myend = nullptr;
    std::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>::_Hash<std::_Hmap_traits<std::string,int,stdext::hash_compare<std::string,std::less<std::string>>,std::allocator<std::pair<std::string const,int>>,0>>(
      this: &v6->m_mapDefines,
      _Parg: (std::_List_nod<std::pair<std::string const ,int>>::_Node *)&bStaticDefines,
      _Al: (const std::allocator<std::pair<std::string const ,int> > *)&bStaticDefines);
    v6->m_arrVarSlots._Myfirst = nullptr;
    v6->m_arrVarSlots._Mylast = nullptr;
    v6->m_arrVarSlots._Myend = nullptr;
    v21 = v6;
  }
  else
  {
    v21 = nullptr;
    v6 = nullptr;
  }
  cfge->m_pCg = v6;
  v7 = operator new(nSize: 0x24u);
  if ( v7 != nullptr )
  {
    *v7 = &CComplexExpression::`vftable';
    v7[1] = 0;
    v7[2] = 0;
    v7[3] = 0;
    v7[5] = 0;
    v7[6] = v6;
    *(_DWORD *)&v20.second = v7;
  }
  else
  {
    *(_DWORD *)&v20.second = 0;
  }
  cfge->m_pExpr = *(CComplexExpression **)&v20.second;
  for ( i = ConfigurationProcessing::NextLine(); i != nullptr; i = ConfigurationProcessing::NextLine() )
  {
    if ( strncmp(first: i, last: "#SKIP", count: 5u) == 0 )
      break;
    if ( strncmp(first: i, last: "#DEFINES-", count: 9u) == 0 )
    {
      bStaticDefines = i[9] == 83;
    }
    else
    {
      for ( j = *i; j != 0; j = *++i )
      {
        if ( isspace(c: j) == 0 )
          break;
      }
      strchr(string: (unsigned __int8 *)i, chr: 0x3Du);
      if ( v10 == nullptr )
        continue;
      v11 = v10 + 1;
      *v10 = 0;
      for ( k = v10 - 1; k >= i; *k-- = 0 )
      {
        if ( isspace(c: *k) == 0 )
          break;
      }
      if ( *i == 0 )
        continue;
      strstr(str1: v11, str2: "..");
      if ( v13 == 0 )
        continue;
      v14 = atoi(nptr: (const char *)(v13 + 2));
      v15 = atoi(nptr: (const char *)v11);
      v19.m_sName._Myres = 15;
      v19.m_sName._Mysize = 0;
      v19.m_sName._Bx._Buf[0] = 0;
      std::string::assign(this: &v19.m_sName, _Ptr: i, _Count: strlen(i));
      v19.m_min = v15;
      v19.m_max = v14;
      v19.m_bStatic = bStaticDefines;
      if ( v14 >= v15 )
      {
        ComboGenerator::AddDefine(this: v21, df: &v19);
        if ( v19.m_sName._Myres >= 0x10 )
LABEL_34:
          free(pMem: v19.m_sName._Bx._Ptr);
      }
      else if ( v19.m_sName._Myres >= 0x10 )
      {
        goto LABEL_34;
      }
    }
  }
  v16 = ConfigurationProcessing::NextLine();
  if ( v16 == nullptr )
    return false;
  CComplexExpression::Parse(this: *(CComplexExpression **)&v20.second, szExpression: v16);
  if ( ConfigurationProcessing::WaitFor(szWaitString: "#COMMAND", nMatchLength: 8u) == nullptr )
    return false;
  v17 = ConfigurationProcessing::NextLine();
  if ( v17 != nullptr )
    std::string::assign(this: &cfge->m_sPrefix, _Ptr: v17, _Count: strlen(v17));
  v18 = ConfigurationProcessing::NextLine();
  if ( v18 != nullptr )
    std::string::assign(this: &cfge->m_sSuffix, _Ptr: v18, _Count: strlen(v18));
  return ConfigurationProcessing::WaitFor(szWaitString: "#END", nMatchLength: 4u) != nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10007510
// Name: void ConfigurationProcessing::ProcessConfiguration(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigurationProcessing::ProcessConfiguration()
{
  char *Line; // esi
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *Left; // ecx
  const char *v3; // ebx
  unsigned int v4; // esi
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v5; // eax
  unsigned __int64 v6; // rax
  __int64 v7; // rdi
  unsigned int v8; // kr00_4
  unsigned __int64 v9; // rdi
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v11; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v12; // eax
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v13; // eax
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > >,bool> result; // [esp+Ch] [ebp-ECh] BYREF
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > >,bool> v15; // [esp+14h] [ebp-E4h] BYREF
  std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > >,bool> v16; // [esp+1Ch] [ebp-DCh] BYREF
  ConfigurationProcessing::CfgEntry cfge; // [esp+24h] [ebp-D4h] BYREF
  std::reverse_iterator<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > > itEnd; // [esp+9Ch] [ebp-5Ch]
  unsigned __int64 iAdvance; // [esp+A0h] [ebp-58h] BYREF
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0> v20; // [esp+A8h] [ebp-50h] BYREF
  unsigned __int64 v21; // [esp+ACh] [ebp-4Ch]
  ConfigurationProcessing::ComboHandleImpl chi; // [esp+B4h] [ebp-44h] BYREF
  unsigned __int64 nCurrentCommand; // [esp+ECh] [ebp-Ch]
  std::reverse_iterator<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > > it; // [esp+F4h] [ebp-4h] BYREF

  while ( 1 )
  {
    Line = ConfigurationProcessing::NextLine();
    if ( Line == nullptr )
      break;
    while ( strncmp(first: Line, last: "#BEGIN", count: 6u) != 0 )
    {
      Line = ConfigurationProcessing::NextLine();
      if ( Line == nullptr )
        goto LABEL_4;
    }
    if ( Line[6] == 32 )
    {
      it.current._Ptr = (std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *)(Line + 7);
      v10 = std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Buynode<char const * &>(
              this: &ConfigurationProcessing::s_uniqueSections,
              _Val: (char **)&it);
      std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::_Linsert(
        this: &ConfigurationProcessing::s_uniqueSections,
        result: (std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >,bool> *)&iAdvance,
        _Node: v10,
        _Leftish: 0);
      if ( BYTE4(iAdvance) == 0 )
        continue;
    }
    cfge.m_szName = setName;
    cfge.m_szShaderSrc = setName;
    memset(&cfge.m_pCg, 0, 9);
    cfge.m_sPrefix._Myres = 15;
    cfge.m_sPrefix._Mysize = 0;
    cfge.m_sSuffix._Myres = 15;
    cfge.m_sSuffix._Mysize = 0;
    cfge.m_sSuffix._Bx._Buf[0] = 0;
    memset(dst: (unsigned __int8 *)&cfge.m_eiInfo, value: 0, count: sizeof(cfge.m_eiInfo));
    cfge.m_szName = (const char *)QuickStrUnique::Lookup(
                                    this: &ConfigurationProcessing::s_uniqueSections,
                                    szString: Line + 7);
    ConfigurationProcessing::ProcessSection(&cfge);
    v11 = std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Buynode<ConfigurationProcessing::CfgEntry &>(
            this: &ConfigurationProcessing::s_setEntries,
            _Val: &cfge);
    std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::_Linsert(
      this: &ConfigurationProcessing::s_setEntries,
      result: &v16,
      _Node: v11,
      _Leftish: false);
    if ( cfge.m_sSuffix._Myres >= 0x10 )
      free(pMem: cfge.m_sSuffix._Bx._Ptr);
    cfge.m_sSuffix._Myres = 15;
    cfge.m_sSuffix._Mysize = 0;
    cfge.m_sSuffix._Bx._Buf[0] = 0;
    if ( cfge.m_sPrefix._Myres >= 0x10 )
      free(pMem: cfge.m_sPrefix._Bx._Ptr);
  }
LABEL_4:
  Myhead = ConfigurationProcessing::s_setEntries._Myhead;
  Left = ConfigurationProcessing::s_setEntries._Myhead->_Left;
  nCurrentCommand = 0;
  v3 = nullptr;
  it.current._Ptr = ConfigurationProcessing::s_setEntries._Myhead;
  for ( itEnd.current._Ptr = Left; it.current._Ptr != itEnd.current._Ptr; Myhead = it.current._Ptr )
  {
    memset(&chi.m_iTotalCommand, 0, 40);
    chi.__vftable = (ConfigurationProcessing::ComboHandleImpl_vtbl *)&ConfigurationProcessing::ComboHandleImpl::`vftable';
    v20._Ptr = Myhead;
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>::operator--(this: &v20);
    v4 = nCurrentCommand;
    ConfigurationProcessing::ComboHandleImpl::Initialize(
      this: &chi,
      iTotalCommand: __PAIR64__((unsigned int)v3, nCurrentCommand),
      pEntry: &v20._Ptr->_Myval);
    *(_QWORD *)&cfge.m_eiInfo.m_szName = chi.m_iTotalCommand;
    cfge.m_eiInfo.m_numDynamicCombos = chi.m_numCombos;
    cfge.m_eiInfo.m_numCombos = chi.m_iComboNumber;
    LODWORD(cfge.m_eiInfo.m_numStaticCombos) = chi.m_pEntry;
    *(_DWORD *)&cfge.m_sSuffix._Bx._Alias[12] = v4;
    cfge.m_sSuffix._Mysize = (unsigned int)v3;
    cfge.m_sSuffix._Myres = (unsigned int)&ConfigurationProcessing::ComboHandleImpl::`vftable';
    std::vector<int>::vector<int>(
      this: (std::vector<int> *)((char *)&cfge.m_eiInfo.m_numStaticCombos + 4),
      _Right: &chi.m_arrVarSlots);
    v5 = std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Buynode<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>(
           this: &ConfigurationProcessing::s_mapComboCommands,
           _Val: (std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> *)&cfge.m_sSuffix._Bx._Alias[12]);
    std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Linsert(
      this: &ConfigurationProcessing::s_mapComboCommands,
      &result,
      _Node: v5,
      _Leftish: 0);
    if ( HIDWORD(cfge.m_eiInfo.m_numStaticCombos) != 0 )
      free(pMem: (void *)HIDWORD(cfge.m_eiInfo.m_numStaticCombos));
    v6 = chi.m_numCombos / 0x1F4;
    if ( chi.m_numCombos / 0x1F4 < 0x3E8 )
      LODWORD(v6) = 1000;
    v6 = (int)v6;
    LODWORD(v7) = v6;
    v8 = v4;
    HIDWORD(v7) = (int)v6 >> 31;
    v9 = __PAIR64__((unsigned int)v3, v8) + v7;
    v21 = (int)v6;
    v16.first._Ptr = (std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *)(nCurrentCommand + LODWORD(chi.m_numCombos));
    if ( v9 < __PAIR64__((unsigned int)v3, nCurrentCommand) + chi.m_numCombos )
    {
      while ( 1 )
      {
        iAdvance = v6;
        ConfigurationProcessing::ComboHandleImpl::AdvanceCommands(this: &chi, riAdvanceMore: &iAdvance);
        *(_QWORD *)&cfge.m_eiInfo.m_szName = chi.m_iTotalCommand;
        cfge.m_eiInfo.m_numCombos = chi.m_iComboNumber;
        cfge.m_eiInfo.m_numDynamicCombos = chi.m_numCombos;
        *(_QWORD *)&cfge.m_sSuffix._Bx._Alias[12] = v9;
        cfge.m_sSuffix._Myres = (unsigned int)&ConfigurationProcessing::ComboHandleImpl::`vftable';
        LODWORD(cfge.m_eiInfo.m_numStaticCombos) = chi.m_pEntry;
        std::vector<int>::vector<int>(
          this: (std::vector<int> *)((char *)&cfge.m_eiInfo.m_numStaticCombos + 4),
          _Right: &chi.m_arrVarSlots);
        v12 = std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Buynode<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>(
                this: &ConfigurationProcessing::s_mapComboCommands,
                _Val: (std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> *)&cfge.m_sSuffix._Bx._Alias[12]);
        std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Linsert(
          this: &ConfigurationProcessing::s_mapComboCommands,
          result: &v15,
          _Node: v12,
          _Leftish: 0);
        if ( HIDWORD(cfge.m_eiInfo.m_numStaticCombos) != 0 )
          free(pMem: (void *)HIDWORD(cfge.m_eiInfo.m_numStaticCombos));
        v9 += v21;
        if ( v9 >= __PAIR64__((unsigned int)v3, nCurrentCommand) + chi.m_numCombos )
          break;
        v6 = v21;
      }
    }
    v3 = (const char *)((chi.m_numCombos + __PAIR64__((unsigned int)v3, nCurrentCommand)) >> 32);
    LODWORD(nCurrentCommand) = LODWORD(chi.m_numCombos) + nCurrentCommand;
    if ( chi.m_arrVarSlots._Myfirst != nullptr )
      free(pMem: chi.m_arrVarSlots._Myfirst);
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>::operator--(this: &it.current);
  }
  if ( (_S2 & 1) == 0 )
  {
    _S2 |= 1u;
    s_term.m_szName = setName;
    s_term.m_szShaderSrc = setName;
    s_term.m_pCg = nullptr;
    s_term.m_pExpr = nullptr;
    s_term.m_sPrefix._Myres = 15;
    s_term.m_sPrefix._Mysize = 0;
    s_term.m_sPrefix._Bx._Buf[0] = 0;
    s_term.m_sSuffix._Myres = 15;
    s_term.m_sSuffix._Mysize = 0;
    s_term.m_sSuffix._Bx._Buf[0] = 0;
    memset(dst: (unsigned __int8 *)&s_term.m_eiInfo, value: 0, count: sizeof(s_term.m_eiInfo));
    atexit(func: ConfigurationProcessing::ProcessConfiguration_::_11_::_dynamic_atexit_destructor_for__s_term__);
  }
  s_term.m_eiInfo.m_numDynamicCombos = 1;
  s_term.m_eiInfo.m_numStaticCombos = 1;
  s_term.m_eiInfo.m_numCombos = 1;
  memset(&chi.m_iComboNumber, 0, 16);
  chi.__vftable = (ConfigurationProcessing::ComboHandleImpl_vtbl *)&ConfigurationProcessing::ComboHandleImpl::`vftable';
  cfge.m_sSuffix._Myres = (unsigned int)&ConfigurationProcessing::ComboHandleImpl::`vftable';
  memset(&cfge.m_eiInfo.m_numCombos, 0, 16);
  LODWORD(s_term.m_eiInfo.m_iCommandEnd) = nCurrentCommand;
  HIDWORD(s_term.m_eiInfo.m_iCommandEnd) = v3;
  LODWORD(s_term.m_eiInfo.m_iCommandStart) = nCurrentCommand;
  HIDWORD(s_term.m_eiInfo.m_iCommandStart) = v3;
  s_term.m_eiInfo.m_szShaderFileName = setName;
  s_term.m_eiInfo.m_szName = setName;
  memset(&chi.m_arrVarSlots, 0, 12);
  chi.m_iTotalCommand = __PAIR64__((unsigned int)v3, nCurrentCommand);
  chi.m_pEntry = &s_term;
  *(_DWORD *)&cfge.m_sSuffix._Bx._Alias[12] = nCurrentCommand;
  cfge.m_sSuffix._Mysize = (unsigned int)v3;
  cfge.m_eiInfo.m_szName = (const char *)nCurrentCommand;
  cfge.m_eiInfo.m_szShaderFileName = v3;
  LODWORD(cfge.m_eiInfo.m_numStaticCombos) = &s_term;
  std::vector<int>::vector<int>(
    this: (std::vector<int> *)((char *)&cfge.m_eiInfo.m_numStaticCombos + 4),
    _Right: &chi.m_arrVarSlots);
  v13 = std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Buynode<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>(
          this: &ConfigurationProcessing::s_mapComboCommands,
          _Val: (std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> *)&cfge.m_sSuffix._Bx._Alias[12]);
  std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Linsert(
    this: &ConfigurationProcessing::s_mapComboCommands,
    result: &v15,
    _Node: v13,
    _Leftish: 0);
  if ( HIDWORD(cfge.m_eiInfo.m_numStaticCombos) != 0 )
    free(pMem: (void *)HIDWORD(cfge.m_eiInfo.m_numStaticCombos));
}

//------------------------------------------------------------------------------
// Address: 0x10007A50
// Name: void CfgProcessor::ReadConfiguration(class CUtlInplaceBuffer __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CfgProcessor::ReadConfiguration(CUtlInplaceBuffer *fInputStream)
{
  CUtlInplaceBuffer *v1; // esi

  v1 = dword_101645F8;
  dword_101645F8 = fInputStream;
  ConfigurationProcessing::ProcessConfiguration();
  dword_101645F8 = v1;
}

//------------------------------------------------------------------------------
// Address: 0x10007A70
// Name: public: static void ConfigurationProcessing::CfgEntry::Destroy(class ConfigurationProcessing::CfgEntry const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigurationProcessing::CfgEntry::Destroy(const ConfigurationProcessing::CfgEntry *x)
{
  ComboGenerator *m_pCg; // esi
  CComplexExpression *m_pExpr; // esi
  CComplexExpression *v3; // ecx

  m_pCg = x->m_pCg;
  if ( m_pCg != nullptr )
  {
    ComboGenerator::~ComboGenerator(this: x->m_pCg);
    free(pMem: m_pCg);
  }
  m_pExpr = x->m_pExpr;
  if ( m_pExpr != nullptr )
  {
    v3 = x->m_pExpr;
    m_pExpr->__vftable = (CComplexExpression_vtbl *)&CComplexExpression::`vftable';
    CComplexExpression::Clear(this: v3);
    if ( m_pExpr->m_arrAllExpressions._Myfirst != nullptr )
      free(pMem: m_pExpr->m_arrAllExpressions._Myfirst);
    m_pExpr->m_arrAllExpressions._Myfirst = nullptr;
    m_pExpr->m_arrAllExpressions._Mylast = nullptr;
    m_pExpr->m_arrAllExpressions._Myend = nullptr;
    free(pMem: m_pExpr);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036A12
// Name: void std::_Xlength_error(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn std::_Xlength_error(const char *_Message)
{
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  std::exception::exception(this: &pExceptionObject, _What: &_Message);
  pExceptionObject.__vftable = (std::exception_vtbl *)&std::length_error::`vftable';
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI3_AVlength_error_std__);
}

//------------------------------------------------------------------------------
// Address: 0x10036A5F
// Name: void std::_Xout_of_range(char const __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __noreturn std::_Xout_of_range(const char *_Message)
{
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  std::exception::exception(this: &pExceptionObject, _What: &_Message);
  pExceptionObject.__vftable = (std::exception_vtbl *)&std::out_of_range::`vftable';
  _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI3_AVout_of_range_std__);
}

//------------------------------------------------------------------------------
// Address: 0x10050B90
// Name: ConfigurationProcessing::_dynamic_initializer_for__s_uniqueSections__
// Source: json
//------------------------------------------------------------------------------
int ConfigurationProcessing::_dynamic_initializer_for__s_uniqueSections__()
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v0; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  char *_What; // [esp+Ch] [ebp-4h] BYREF

  v0 = (std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *)operator new(nSize: 0x2Cu);
  if ( v0 == nullptr )
  {
    _What = nullptr;
    std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  ConfigurationProcessing::s_uniqueSections._Myhead = v0;
  v0->_Left = v0;
  ConfigurationProcessing::s_uniqueSections._Myhead->_Parent = ConfigurationProcessing::s_uniqueSections._Myhead;
  ConfigurationProcessing::s_uniqueSections._Myhead->_Right = ConfigurationProcessing::s_uniqueSections._Myhead;
  ConfigurationProcessing::s_uniqueSections._Myhead->_Color = 1;
  ConfigurationProcessing::s_uniqueSections._Myhead->_Isnil = 1;
  return atexit(func: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_uniqueSections__);
}

//------------------------------------------------------------------------------
// Address: 0x10050C10
// Name: ConfigurationProcessing::_dynamic_initializer_for__s_strPool__
// Source: json
//------------------------------------------------------------------------------
int ConfigurationProcessing::_dynamic_initializer_for__s_strPool__()
{
  std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *v0; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  char *_What; // [esp+Ch] [ebp-4h] BYREF

  v0 = (std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *)operator new(nSize: 0x2Cu);
  if ( v0 == nullptr )
  {
    _What = nullptr;
    std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  ConfigurationProcessing::s_strPool._Myhead = v0;
  v0->_Left = v0;
  ConfigurationProcessing::s_strPool._Myhead->_Parent = ConfigurationProcessing::s_strPool._Myhead;
  ConfigurationProcessing::s_strPool._Myhead->_Right = ConfigurationProcessing::s_strPool._Myhead;
  ConfigurationProcessing::s_strPool._Myhead->_Color = 1;
  ConfigurationProcessing::s_strPool._Myhead->_Isnil = 1;
  return atexit(func: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_strPool__);
}

//------------------------------------------------------------------------------
// Address: 0x10050C90
// Name: ConfigurationProcessing::_dynamic_initializer_for__s_setEntries__
// Source: json
//------------------------------------------------------------------------------
int ConfigurationProcessing::_dynamic_initializer_for__s_setEntries__()
{
  std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *v0; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  char *_What; // [esp+Ch] [ebp-4h] BYREF

  v0 = (std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *)operator new(nSize: 0x90u);
  if ( v0 == nullptr )
  {
    _What = nullptr;
    std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  ConfigurationProcessing::s_setEntries._Myhead = v0;
  v0->_Left = v0;
  ConfigurationProcessing::s_setEntries._Myhead->_Parent = ConfigurationProcessing::s_setEntries._Myhead;
  ConfigurationProcessing::s_setEntries._Myhead->_Right = ConfigurationProcessing::s_setEntries._Myhead;
  ConfigurationProcessing::s_setEntries._Myhead->_Color = 1;
  ConfigurationProcessing::s_setEntries._Myhead->_Isnil = 1;
  return atexit(func: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_setEntries__);
}

//------------------------------------------------------------------------------
// Address: 0x10050D20
// Name: ConfigurationProcessing::_dynamic_initializer_for__s_mapComboCommands__
// Source: json
//------------------------------------------------------------------------------
int ConfigurationProcessing::_dynamic_initializer_for__s_mapComboCommands__()
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *v0; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-10h] BYREF
  char *_What; // [esp+Ch] [ebp-4h] BYREF

  v0 = (std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *)operator new(nSize: 0x58u);
  if ( v0 == nullptr )
  {
    _What = nullptr;
    std::exception::exception(this: &pExceptionObject, (const char *const *)&_What);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  ConfigurationProcessing::s_mapComboCommands._Myhead = v0;
  v0->_Left = v0;
  ConfigurationProcessing::s_mapComboCommands._Myhead->_Parent = ConfigurationProcessing::s_mapComboCommands._Myhead;
  ConfigurationProcessing::s_mapComboCommands._Myhead->_Right = ConfigurationProcessing::s_mapComboCommands._Myhead;
  ConfigurationProcessing::s_mapComboCommands._Myhead->_Color = 1;
  ConfigurationProcessing::s_mapComboCommands._Myhead->_Isnil = 1;
  return atexit(func: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_mapComboCommands__);
}

//------------------------------------------------------------------------------
// Address: 0x10050DA0
// Name: ConfigurationProcessing::_dynamic_initializer_for__s_autoDestroyEntries__
// Source: json
//------------------------------------------------------------------------------
int ConfigurationProcessing::_dynamic_initializer_for__s_autoDestroyEntries__()
{
  return atexit(func: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_autoDestroyEntries__);
}

//------------------------------------------------------------------------------
// Address: 0x10051810
// Name: _ConfigurationProcessing::ProcessConfiguration_::_11_::_dynamic_atexit_destructor_for__s_term__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigurationProcessing::ProcessConfiguration_::_11_::_dynamic_atexit_destructor_for__s_term__()
{
  if ( s_term.m_sSuffix._Myres >= 0x10 )
    free(pMem: s_term.m_sSuffix._Bx._Ptr);
  s_term.m_sSuffix._Myres = 15;
  s_term.m_sSuffix._Mysize = 0;
  s_term.m_sSuffix._Bx._Buf[0] = 0;
  if ( s_term.m_sPrefix._Myres >= 0x10 )
    free(pMem: s_term.m_sPrefix._Bx._Ptr);
  s_term.m_sPrefix._Mysize = 0;
  s_term.m_sPrefix._Bx._Buf[0] = 0;
  s_term.m_sPrefix._Myres = 15;
}

//------------------------------------------------------------------------------
// Address: 0x10051870
// Name: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_strPool__
// Source: json
//------------------------------------------------------------------------------
void __thiscall ConfigurationProcessing::_dynamic_atexit_destructor_for__s_strPool__(
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *this)
{
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > result; // [esp+0h] [ebp-4h] BYREF

  result._Ptr = this;
  std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::erase(
    this: &ConfigurationProcessing::s_strPool,
    &result,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >)ConfigurationProcessing::s_strPool._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >)ConfigurationProcessing::s_strPool._Myhead);
  free(pMem: ConfigurationProcessing::s_strPool._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x100518A0
// Name: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_uniqueSections__
// Source: json
//------------------------------------------------------------------------------
void __thiscall ConfigurationProcessing::_dynamic_atexit_destructor_for__s_uniqueSections__(
        std::_Tree_nod<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> >::_Node *this)
{
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > > result; // [esp+0h] [ebp-4h] BYREF

  result._Ptr = this;
  std::_Tree<std::_Tset_traits<std::string,std::less<std::string>,std::allocator<std::string>,0>>::erase(
    this: &ConfigurationProcessing::s_uniqueSections,
    &result,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >)ConfigurationProcessing::s_uniqueSections._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<std::string,std::less<std::string >,std::allocator<std::string >,0> > >)ConfigurationProcessing::s_uniqueSections._Myhead);
  free(pMem: ConfigurationProcessing::s_uniqueSections._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x100518D0
// Name: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_setEntries__
// Source: json
//------------------------------------------------------------------------------
void __thiscall ConfigurationProcessing::_dynamic_atexit_destructor_for__s_setEntries__(
        std::_Tree_nod<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >::_Node *this)
{
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > > result; // [esp+0h] [ebp-4h] BYREF

  result._Ptr = this;
  std::_Tree<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>::erase(
    this: &ConfigurationProcessing::s_setEntries,
    &result,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > >)ConfigurationProcessing::s_setEntries._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> > >)ConfigurationProcessing::s_setEntries._Myhead);
  free(pMem: ConfigurationProcessing::s_setEntries._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x10051900
// Name: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_mapComboCommands__
// Source: json
//------------------------------------------------------------------------------
void __thiscall ConfigurationProcessing::_dynamic_atexit_destructor_for__s_mapComboCommands__(
        std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *this)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > > result; // [esp+0h] [ebp-4h] BYREF

  result._Ptr = this;
  std::_Tree<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::erase(
    this: &ConfigurationProcessing::s_mapComboCommands,
    &result,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > >)ConfigurationProcessing::s_mapComboCommands._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > >)ConfigurationProcessing::s_mapComboCommands._Myhead);
  free(pMem: ConfigurationProcessing::s_mapComboCommands._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x10051930
// Name: ConfigurationProcessing::_dynamic_atexit_destructor_for__s_autoDestroyEntries__
// Source: json
//------------------------------------------------------------------------------
void __cdecl ConfigurationProcessing::_dynamic_atexit_destructor_for__s_autoDestroyEntries__()
{
  std::_For_each<std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1>>,std::_Iterator_base0>,void (__cdecl *)(ConfigurationProcessing::CfgEntry const &)>(
    _First: (std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0>)ConfigurationProcessing::s_setEntries._Myhead->_Left,
    _Last: (std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<ConfigurationProcessing::CfgEntry,std::less<ConfigurationProcessing::CfgEntry>,std::allocator<ConfigurationProcessing::CfgEntry>,1> >,std::_Iterator_base0>)ConfigurationProcessing::s_setEntries._Myhead,
    _Func: ConfigurationProcessing::CfgEntry::Destroy);
}

//------------------------------------------------------------------------------
// Address: 0x10003920
// Name: ?_Insert_n@?$vector@V?$_List_iterator@V?$_List_val@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@@2@@std@@@std@@V?$allocator@V?$_List_iterator@V?$_List_val@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@@2@@std@@@std@@@2@@std@@IAEXV?$_Vector_const_iterator@V?$_Vector_val@V?$_List_iterator@V?$_List_val@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@@2@@std@@@std@@V?$allocator@V?$_List_iterator@V?$_List_val@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@@2@@std@@@std@@@2@@std@@@2@IABV?$_List_iterator@V?$_List_val@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@V?$allocator@U?$pair@$$CBV?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@H@std@@@2@@std@@@2@@Z
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __thiscall std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Insert_n(
        std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >> *this,
        std::_Vector_const_iterator<std::_Vector_val<std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> >> > _Where,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > _Count,
        std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Val)
{
  unsigned int Ptr; // edi
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *Mylast; // ebx
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *Myfirst; // ecx
  int v8; // eax
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > v9; // edx
  unsigned int v10; // eax
  unsigned int v11; // eax
  int v12; // ebx
  unsigned int v13; // eax
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v14; // ebx
  unsigned int v15; // edi
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v16; // eax
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *v17; // edi
  int v18; // [esp+0h] [ebp-24h] BYREF
  int _Ncopied; // [esp+Ch] [ebp-18h]
  std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *_Newvec; // [esp+10h] [ebp-14h]
  int *v21; // [esp+14h] [ebp-10h]
  int v22; // [esp+20h] [ebp-4h]

  v21 = &v18;
  Ptr = (unsigned int)_Count._Ptr;
  if ( _Count._Ptr != nullptr )
  {
    Mylast = this->_Mylast;
    Myfirst = this->_Myfirst;
    v8 = this->_Mylast - this->_Myfirst;
    if ( 0x3FFFFFFF - v8 < (unsigned int)_Count._Ptr )
      std::_Xlength_error(_Message: "vector<T> too long");
    v9._Ptr = (std::_List_nod<std::pair<std::string const ,int>>::_Node *)((char *)_Count._Ptr + v8);
    v10 = this->_Myend - Myfirst;
    if ( v10 >= (unsigned int)v9._Ptr )
    {
      if ( Mylast - _Where._Ptr >= (unsigned int)_Count._Ptr )
      {
        _Count._Ptr = _Val->_Ptr;
        _Val = (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)(4 * Ptr);
        v17 = &Mylast[-Ptr];
        this->_Mylast = std::_Uninit_move<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
                          _First: v17,
                          _Last: Mylast,
                          _Dest: Mylast,
                          _Al: &this->_Alval);
        std::_Copy_backward<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *>(
          _First: _Where._Ptr,
          _Last: v17,
          _Dest: Mylast);
        std::fill<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
          _First: _Where._Ptr,
          _Last: (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)((char *)_Where._Ptr
                                                                                    + (unsigned int)_Val),
          _Val: &_Count);
      }
      else
      {
        _Count._Ptr = _Val->_Ptr;
        _Val = (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)(4 * Ptr);
        std::_Uninit_move<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::allocator<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
          _First: _Where._Ptr,
          _Last: Mylast,
          _Dest: &_Where._Ptr[Ptr],
          _Al: &this->_Alval);
        v22 = 2;
        std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Ufill(
          this,
          _Ptr: this->_Mylast,
          _Count: Ptr - (this->_Mylast - _Where._Ptr),
          _Pval: &_Count);
        v22 = -1;
        v16 = _Val;
        this->_Mylast = (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)((char *)this->_Mylast
                                                                                                  + (unsigned int)_Val);
        std::fill<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *,std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>(
          _First: _Where._Ptr,
          _Last: (std::_List_iterator<std::_List_val<std::pair<std::string const ,int>> > *)((char *)this->_Mylast - (char *)v16),
          _Val: &_Count);
      }
    }
    else
    {
      if ( 0x3FFFFFFF - (v10 >> 1) >= v10 )
      {
        v11 = (v10 >> 1) + v10;
        _Count._Ptr = (std::_List_nod<std::pair<std::string const ,int>>::_Node *)v11;
      }
      else
      {
        _Count._Ptr = nullptr;
        v11 = 0;
      }
      if ( v11 < (unsigned int)v9._Ptr )
      {
        _Count._Ptr = v9._Ptr;
        v11 = (unsigned int)v9._Ptr;
      }
      _Newvec = std::allocator<IExpression *>::allocate(this: &this->_Alval, _Count: v11);
      v12 = _Where._Ptr - this->_Myfirst;
      v22 = 0;
      std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Ufill(
        this,
        _Ptr: &_Newvec[v12],
        _Count: Ptr,
        _Pval: _Val);
      _Ncopied = 1;
      std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Umove<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *>(
        this,
        _First: this->_Myfirst,
        _Last: _Where._Ptr,
        _Ptr: _Newvec);
      _Ncopied = 2;
      v13 = v12 + Ptr;
      v14 = _Newvec;
      std::vector<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>>>::_Umove<std::_List_iterator<std::_List_val<std::pair<std::string const,int>>> *>(
        this,
        _First: _Where._Ptr,
        _Last: this->_Mylast,
        _Ptr: &_Newvec[v13]);
      v22 = -1;
      v15 = this->_Mylast - this->_Myfirst + Ptr;
      if ( this->_Myfirst != nullptr )
        free(pMem: this->_Myfirst);
      this->_Myend = &v14[(int)_Count._Ptr];
      this->_Mylast = &v14[v15];
      this->_Myfirst = v14;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10006D50
// Name: public: struct std::_Tree_nod<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<unsigned __int64,class ConfigurationProcessing::ComboHandleImpl,struct std::less<unsigned __int64>,class std::allocator<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>,0>>::_Buynode<struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl>>(struct std::pair<unsigned __int64 const,class ConfigurationProcessing::ComboHandleImpl> __near &&)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *__thiscall std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,0>>::_Buynode<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>(
        std::_Tree_val<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> > *this,
        std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> *_Val)
{
  std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *pMem; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node **)operator new(nSize: 0x58u);
  pMem = v3;
  if ( v3 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  *v3 = this->_Myhead;
  v3[1] = this->_Myhead;
  v3[2] = this->_Myhead;
  *((_WORD *)v3 + 40) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>,std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>,std::pair<unsigned __int64 const,ConfigurationProcessing::ComboHandleImpl>>(
    _Alval: &this->_Alval,
    _Pdest: (std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> *)(v3 + 4),
    _Src: _Val);
  v9 = -1;
  return (std::_Tree_nod<std::_Tmap_traits<unsigned __int64,ConfigurationProcessing::ComboHandleImpl,std::less<unsigned __int64>,std::allocator<std::pair<unsigned __int64 const ,ConfigurationProcessing::ComboHandleImpl> >,0> >::_Node *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x10036A42
// Name: public: std::length_error::length_error(class std::length_error const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::length_error *__thiscall std::length_error::length_error(std::length_error *this, const std::length_error *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::length_error_vtbl *)&std::length_error::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10036A8F
// Name: public: std::out_of_range::out_of_range(class std::out_of_range const __near &)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
std::out_of_range *__thiscall std::out_of_range::out_of_range(std::out_of_range *this, const std::out_of_range *__that)
{
  std::exception::exception(this, _That: __that);
  this->__vftable = (std::out_of_range_vtbl *)&std::out_of_range::`vftable';
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10036AE0
// Name: _strchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strchr(char *string, unsigned __int8 chr)
{
  char *v2; // edx
  char v3; // cl
  int v4; // ecx
  int v5; // esi
  int v6; // eax
  unsigned int v7; // eax
  unsigned int v8; // eax
  unsigned int v9; // eax

  v2 = string;
  if ( ((unsigned __int8)string & 3) != 0 )
  {
    while ( 1 )
    {
      v3 = *v2++;
      if ( v3 == chr || v3 == 0 )
        break;
      if ( ((unsigned __int8)v2 & 3) == 0 )
        goto main_loop;
    }
  }
  else
  {
    do
    {
main_loop:
      while ( 1 )
      {
        v4 = ((chr << 8) | chr | (((chr << 8) | chr) << 16)) ^ *(_DWORD *)v2;
        v5 = *(_DWORD *)v2 + 2130640639;
        v6 = v5 ^ ~*(_DWORD *)v2;
        v2 += 4;
        if ( (((v4 + 2130640639) ^ ~v4) & 0x81010100) != 0 )
          break;
        v7 = v6 & 0x81010100;
        if ( v7 != 0 && ((v7 & 0x1010100) != 0 || (v5 & 0x80000000) == 0) )
          return;
      }
      v8 = *((_DWORD *)v2 - 1);
      if ( (_BYTE)v8 == chr )
        break;
      if ( (_BYTE)v8 == 0 )
        break;
      if ( BYTE1(v8) == chr )
        break;
      if ( BYTE1(v8) == 0 )
        break;
      v9 = HIWORD(v8);
      if ( (_BYTE)v9 == chr )
        break;
    }
    while ( (_BYTE)v9 != 0 && BYTE1(v9) != chr && BYTE1(v9) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036BA0
// Name: _strstr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strstr(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 v2; // dl
  unsigned __int8 v4; // dh
  unsigned __int8 *v5; // ecx
  unsigned __int8 *v6; // esi
  char v7; // al
  unsigned __int8 v8; // ah
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al

  v2 = *str2;
  if ( *str2 != 0 )
  {
    v4 = str2[1];
    if ( v4 == 0 )
      JUMPOUT(0x10036AE6);
findnext:
    v5 = str2;
    v6 = str1 + 1;
    if ( *str1 == v2 )
      goto first_char_found;
    if ( *str1 != 0 )
    {
      while ( 2 )
      {
        v7 = *v6++;
        while ( v7 == v2 )
        {
first_char_found:
          v7 = *v6++;
          if ( v7 == v4 )
          {
            str1 = v6 - 1;
            while ( 1 )
            {
              v8 = v5[2];
              if ( v8 == 0 )
                break;
              v9 = *v6;
              v6 += 2;
              if ( v9 != v8 )
                goto findnext;
              v10 = v5[3];
              if ( v10 == 0 )
                break;
              v5 += 2;
              if ( v10 != *(v6 - 1) )
                goto findnext;
            }
            return;
          }
        }
        if ( v7 != 0 )
          continue;
        break;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036C9F
// Name: __time64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
__int64 __cdecl _time64(__int64 *timeptr)
{
  __int64 result; // rax
  FT nt_time; // [esp+0h] [ebp-8h] BYREF

  GetSystemTimeAsFileTime(lpSystemTimeAsFileTime: (LPFILETIME)&nt_time);
  result = (nt_time.ft_scalar - 116444736000000000LL) / 0x989680;
  if ( result > 0x793406FFFLL )
    result = -1;
  if ( timeptr != nullptr )
    *timeptr = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10036CF0
// Name: _printf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int printf(const char *format, ...)
{
  _iobuf *v2; // eax
  _iobuf *v3; // eax
  int v4; // edi
  _iobuf *v5; // eax
  _iobuf *v6; // eax
  _iobuf *v7; // eax
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+38h] [ebp+Ch] BYREF

  va_start(argptr, format);
  if ( format != nullptr )
  {
    v2 = __iob_func();
    _lock_file2(i: 1, s: &v2[1]);
    v3 = __iob_func();
    v4 = _stbuf(str: v3 + 1);
    v5 = __iob_func();
    retval = _output_l(stream: v5 + 1, format, plocinfo: nullptr, argptr);
    v6 = __iob_func();
    _ftbuf(flag: v4, str: v6 + 1);
    v7 = __iob_func();
    _unlock_file2(i: 1, s: &v7[1]);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036D97
// Name: __get_printf_count_output
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL _get_printf_count_output()
{
  return _enable_percent_n == (__security_cookie | 1);
}

//------------------------------------------------------------------------------
// Address: 0x10036DAD
// Name: _vfprintf_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfprintf_helper(
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        _iobuf *str,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int v6; // eax
  ioinfo *v7; // ecx
  ioinfo *v8; // eax
  int v9; // esi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v6 = _fileno(stream: str);
      if ( v6 == -1 || v6 == -2 )
        v7 = &__badioinfo;
      else
        v7 = &__pioinfo[v6 >> 5][v6 & 0x1F];
      if ( (*((_BYTE *)v7 + 36) & 0x7F) != 0
        || (v6 == -1 || v6 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v6 >> 5][v6 & 0x1F]), *((char *)v8 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v9 = _stbuf(str);
      retval = outfn(a1: str, a2: format, a3: plocinfo, a4: ap);
      _ftbuf(flag: v9, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10036EB8
// Name: _vfprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl vfprintf(_iobuf *str, const char *format, char *ap)
{
  return vfprintf_helper(outfn: _output_l, str, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x10037050
// Name: _memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memcpy(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1;
          case 2u:
            goto TrailDown2;
          case 3u:
            goto TrailDown3;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0[ecx*4]; jumptable 100370A9 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0;
      case 1u:
        goto UnwindUp1;
      case 2u:
        goto UnwindUp2;
      case 3u:
        goto UnwindUp3;
      case 4u:
        goto UnwindUp4;
      case 5u:
        goto UnwindUp5;
      case 6u:
        goto UnwindUp6;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1;
          case 2u:
            goto TrailUp2;
          case 3u:
            goto TrailUp3;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100373C0
// Name: _memmove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memmove(unsigned __int8 *dst, unsigned __int8 *src, unsigned int count)
{
  unsigned __int8 *v3; // esi
  unsigned __int8 *v4; // edi
  unsigned int v5; // ecx
  unsigned __int8 *v6; // esi
  unsigned __int8 *v7; // edi
  unsigned int v8; // ecx

  v3 = src;
  v4 = dst;
  if ( dst > src && dst < &src[count] )
  {
    v6 = &src[count - 4];
    v7 = &dst[count - 4];
    if ( ((unsigned __int8)v7 & 3) != 0 )
    {
      switch ( count )
      {
        case 0u:
          return;
        case 1u:
TrailDown1_0:
          v7[3] = v6[3];
          break;
        case 2u:
TrailDown2_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          break;
        case 3u:
TrailDown3_0:
          v7[3] = v6[3];
          v7[2] = v6[2];
          v7[1] = v6[1];
          break;
        default:
          __asm { jmp     dword ptr ds:(ByteCopyDown_0+4)[eax*4] }
          return;
      }
    }
    else
    {
      v8 = count >> 2;
      if ( count >> 2 < 8 )
      {
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
      else
      {
        while ( v8 != 0 )
        {
          *(_DWORD *)v7 = *(_DWORD *)v6;
          v6 -= 4;
          v7 -= 4;
          --v8;
        }
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailDown1_0;
          case 2u:
            goto TrailDown2_0;
          case 3u:
            goto TrailDown3_0;
        }
      }
    }
  }
  else if ( count >= 0x80
         && __sse2_available != 0
         && (v3 = src, v4 = dst, ((unsigned __int8)dst & 0xF) == ((unsigned __int8)src & 0xF)) )
  {
    _VEC_memcpy(dst, src, len: count);
  }
  else
  {
    if ( ((unsigned __int8)v4 & 3) != 0 )
    {
      if ( count >= 4 )
        __asm { jmp     dword ptr ds:(CopyUnwindUp_0+4)[eax*4] }
      __asm { jmp     dword ptr ds:TrailUp0_0[ecx*4]; jumptable 10037419 case 0 }
    }
    v5 = count >> 2;
    switch ( v5 )
    {
      case 0u:
        goto UnwindUp0_0;
      case 1u:
        goto UnwindUp1_0;
      case 2u:
        goto UnwindUp2_0;
      case 3u:
        goto UnwindUp3_0;
      case 4u:
        goto UnwindUp4_0;
      case 5u:
        goto UnwindUp5_0;
      case 6u:
        goto UnwindUp6_0;
      case 7u:
        *(_DWORD *)&v4[4 * v5 - 28] = *(_DWORD *)&v3[4 * v5 - 28];
UnwindUp6_0:
        *(_DWORD *)&v4[4 * v5 - 24] = *(_DWORD *)&v3[4 * v5 - 24];
UnwindUp5_0:
        *(_DWORD *)&v4[4 * v5 - 20] = *(_DWORD *)&v3[4 * v5 - 20];
UnwindUp4_0:
        *(_DWORD *)&v4[4 * v5 - 16] = *(_DWORD *)&v3[4 * v5 - 16];
UnwindUp3_0:
        *(_DWORD *)&v4[4 * v5 - 12] = *(_DWORD *)&v3[4 * v5 - 12];
UnwindUp2_0:
        *(_DWORD *)&v4[4 * v5 - 8] = *(_DWORD *)&v3[4 * v5 - 8];
UnwindUp1_0:
        *(_DWORD *)&v4[4 * v5 - 4] = *(_DWORD *)&v3[4 * v5 - 4];
        v3 += 4 * v5;
        v4 += 4 * v5;
UnwindUp0_0:
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
            goto TrailUp1_0;
          case 2u:
            goto TrailUp2_0;
          case 3u:
            goto TrailUp3_0;
        }
      default:
        qmemcpy(v4, v3, 4 * v5);
        v3 += 4 * v5;
        v4 += 4 * v5;
        switch ( count & 3 )
        {
          case 0u:
            return;
          case 1u:
TrailUp1_0:
            *v4 = *v3;
            break;
          case 2u:
TrailUp2_0:
            *v4 = *v3;
            v4[1] = v3[1];
            break;
          case 3u:
TrailUp3_0:
            *v4 = *v3;
            v4[1] = v3[1];
            v4[2] = v3[2];
            break;
        }
        break;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003774B
// Name: ___iob_func
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl __iob_func()
{
  return _iob;
}

//------------------------------------------------------------------------------
// Address: 0x10037751
// Name: ___initstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initstdio()
{
  unsigned int v0; // eax
  void **v1; // eax
  int v3; // edx
  _iobuf *v4; // ecx
  int v5; // edx
  _DWORD *v6; // ecx
  int osfhnd; // eax

  v0 = _nstream;
  if ( _nstream == 0 )
  {
    v0 = 512;
LABEL_5:
    _nstream = v0;
    goto LABEL_6;
  }
  if ( (int)_nstream < 20 )
  {
    v0 = 20;
    goto LABEL_5;
  }
LABEL_6:
  v1 = (void **)calloc(count: v0, size: 4u);
  __piob = v1;
  if ( v1 == nullptr )
  {
    _nstream = 20;
    v1 = (void **)calloc(count: 0x14u, size: 4u);
    __piob = v1;
    if ( v1 == nullptr )
      return 26;
  }
  v3 = 0;
  v4 = _iob;
  while ( 1 )
  {
    v1[v3++] = v4++;
    if ( (int)v4 >= (int)errtable )
      break;
    v1 = __piob;
  }
  v5 = 0;
  v6 = &unk_10062DA0;
  do
  {
    osfhnd = __pioinfo[v5 >> 5][v5 & 0x1F].osfhnd;
    if ( osfhnd == -1 || osfhnd == -2 || osfhnd == 0 )
      *v6 = -2;
    v6 += 8;
    ++v5;
  }
  while ( (int)v6 < (int)dword_10062E00 );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10037802
// Name: ___endstdio
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __endstdio()
{
  _flushall();
  if ( _exitflag != 0 )
    _fcloseall();
  free(pMem: __piob);
}

//------------------------------------------------------------------------------
// Address: 0x10037822
// Name: __lock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_10062FF0 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    _lock(locknum: pf - _iob + 16);
    pf->_flag |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037863
// Name: __lock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    _lock(locknum: i + 16);
    *((_DWORD *)s + 3) |= 0x8000u;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037895
// Name: __unlock_file
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file(_iobuf *pf)
{
  if ( pf < _iob || pf > &stru_10062FF0 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)&pf[1]);
  }
  else
  {
    pf->_flag &= ~0x8000u;
    _unlock(locknum: pf - _iob + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100378D1
// Name: __unlock_file2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock_file2(int i, char *s)
{
  if ( i >= 20 )
  {
    LeaveCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)(s + 32));
  }
  else
  {
    *((_DWORD *)s + 3) &= ~0x8000u;
    _unlock(locknum: i + 16);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10037900
// Name: _fgets
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fgets(_iobuf *string, int count, _iobuf *str)
{
  char *v3; // edi
  int v5; // eax
  ioinfo *v6; // ecx
  ioinfo *v7; // eax
  int v9; // eax
  char *retval; // [esp+18h] [ebp-1Ch]

  v3 = (char *)string;
  retval = (char *)string;
  if ( string == nullptr && count != 0 || count < 0 || str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( count == 0 )
    return nullptr;
  _lock_file(pf: str);
  if ( (str->_flag & 0x40) == 0 )
  {
    v5 = _fileno(stream: str);
    if ( v5 == -1 || v5 == -2 )
      v6 = &__badioinfo;
    else
      v6 = &__pioinfo[v5 >> 5][v5 & 0x1F];
    if ( (*((_BYTE *)v6 + 36) & 0x7F) != 0
      || (v5 == -1 || v5 == -2 ? (v7 = &__badioinfo) : (v7 = &__pioinfo[v5 >> 5][v5 & 0x1F]), *((char *)v7 + 36) < 0) )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      retval = nullptr;
    }
  }
  if ( retval != nullptr )
  {
    do
    {
      if ( --count == 0 )
        break;
      if ( --str->_cnt < 0 )
        v9 = _filbuf(str);
      else
        v9 = *(unsigned __int8 *)str->_ptr++;
      if ( v9 == -1 )
      {
        if ( v3 == (char *)string )
        {
          retval = nullptr;
          goto done_0;
        }
        break;
      }
      *v3++ = v9;
    }
    while ( (_BYTE)v9 != 10 );
    *v3 = 0;
  }
done_0:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10037A38
// Name: _strncmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strncmp(const char *first, const char *last, unsigned int count)
{
  const char *v4; // ecx
  const char *v5; // eax
  char v6; // dl
  char v7; // dl
  char v8; // dl
  char v9; // dl
  int v10; // eax
  int v11; // ecx
  unsigned int i; // esi
  unsigned int n; // [esp+4h] [ebp-4h]

  n = 0;
  if ( count == 0 )
    return 0;
  if ( count <= 4 )
  {
    v4 = last;
    v5 = first;
LABEL_20:
    for ( i = n; ; ++i )
    {
      if ( i >= count )
        return 0;
      if ( *v5 == 0 || *v5 != *v4 )
        break;
      ++v5;
      ++v4;
    }
    v10 = *(unsigned __int8 *)v5;
    v11 = *(unsigned __int8 *)v4;
  }
  else
  {
    v4 = last;
    v5 = first;
    while ( 1 )
    {
      v6 = *v5;
      v5 += 4;
      v4 += 4;
      if ( v6 == 0 || v6 != *(v4 - 4) )
        break;
      v7 = *(v5 - 3);
      if ( v7 == 0 || v7 != *(v4 - 3) )
      {
        v10 = *((unsigned __int8 *)v5 - 3);
        v11 = *((unsigned __int8 *)v4 - 3);
        return v10 - v11;
      }
      v8 = *(v5 - 2);
      if ( v8 == 0 || v8 != *(v4 - 2) )
      {
        v10 = *((unsigned __int8 *)v5 - 2);
        v11 = *((unsigned __int8 *)v4 - 2);
        return v10 - v11;
      }
      v9 = *(v5 - 1);
      if ( v9 == 0 || v9 != *(v4 - 1) )
      {
        v10 = *((unsigned __int8 *)v5 - 1);
        v11 = *((unsigned __int8 *)v4 - 1);
        return v10 - v11;
      }
      n += 4;
      if ( n >= count - 4 )
        goto LABEL_20;
    }
    v10 = *((unsigned __int8 *)v5 - 4);
    v11 = *((unsigned __int8 *)v4 - 4);
  }
  return v10 - v11;
}

//------------------------------------------------------------------------------
// Address: 0x10037AF8
// Name: public: _LocaleUpdate::_LocaleUpdate(struct localeinfo_struct __near *)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_LocaleUpdate *__thiscall _LocaleUpdate::_LocaleUpdate(_LocaleUpdate *this, localeinfo_struct *plocinfo)
{
  _tiddata *v3; // eax
  _tiddata *ptd; // eax

  this->updated = false;
  if ( plocinfo != nullptr )
  {
    this->localeinfo = *plocinfo;
  }
  else
  {
    v3 = _getptd();
    this->ptd = v3;
    this->localeinfo.locinfo = v3->ptlocinfo;
    this->localeinfo.mbcinfo = v3->ptmbcinfo;
    if ( this->localeinfo.locinfo != __ptlocinfo && (__globallocalestatus & v3->_ownlocale) == 0 )
      this->localeinfo.locinfo = __updatetlocinfo();
    if ( this->localeinfo.mbcinfo != __ptmbcinfo && (__globallocalestatus & this->ptd->_ownlocale) == 0 )
      this->localeinfo.mbcinfo = __updatetmbcinfo();
    ptd = this->ptd;
    if ( (ptd->_ownlocale & 2) == 0 )
    {
      ptd->_ownlocale |= 2u;
      this->updated = true;
    }
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x10037B7F
// Name: __isalpha_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalpha_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x103;
  else
    result = _isctype_l(c, mask: 259, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037BD5
// Name: _isalpha
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalpha(int c)
{
  if ( __locale_changed != 0 )
    return _isalpha_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x103;
}

//------------------------------------------------------------------------------
// Address: 0x10037C05
// Name: __isdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 4;
  else
    result = _isctype_l(c, mask: 4, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037C56
// Name: _isdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 4;
}

//------------------------------------------------------------------------------
// Address: 0x10037C84
// Name: __isxdigit_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isxdigit_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x80;
  else
    result = _isctype_l(c, mask: 128, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037CDA
// Name: _isxdigit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isxdigit(int c)
{
  if ( __locale_changed != 0 )
    return _isxdigit_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x80;
}

//------------------------------------------------------------------------------
// Address: 0x10037D0A
// Name: __isspace_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isspace_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 8;
  else
    result = _isctype_l(c, mask: 8, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037D5B
// Name: _isspace
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isspace(int c)
{
  if ( __locale_changed != 0 )
    return _isspace_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 8;
}

//------------------------------------------------------------------------------
// Address: 0x10037D89
// Name: __isalnum_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isalnum_l(int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    result = _loc_update.localeinfo.locinfo->pctype[c] & 0x107;
  else
    result = _isctype_l(c, mask: 263, plocinfo: &_loc_update.localeinfo);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10037DDF
// Name: _isalnum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isalnum(int c)
{
  if ( __locale_changed != 0 )
    return _isalnum_l(c, plocinfo: nullptr);
  else
    return __initiallocinfo.pctype[c] & 0x107;
}

//------------------------------------------------------------------------------
// Address: 0x10037E5B
// Name: _ldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ldiv(int numer, int denom)
{
  return numer / denom;
}

//------------------------------------------------------------------------------
// Address: 0x10038036
// Name: TranslatorGuardHandler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_EXCEPTION_DISPOSITION __cdecl TranslatorGuardHandler(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext)
{
  void *pContinue; // [esp+4h] [ebp-4h] BYREF

  if ( (pExcept->ExceptionFlags & 0x66) != 0 )
  {
    pRN[3].pNext = (EHRegistrationNode *)1;
    return ExceptionContinueSearch;
  }
  else
  {
    __InternalCxxFrameHandler(
      pExcept,
      pRN: (EHRegistrationNode *)pRN[1].frameHandler,
      pContext,
      pDC: nullptr,
      pFuncInfo: (const _s_FuncInfo *)pRN[1].pNext,
      CatchDepth: pRN[1].state,
      pMarkerRN: pRN[2].pNext,
      recursive: 1u);
    if ( pRN[3].pNext == nullptr )
      _UnwindNestedFrames(pRN, pExcept);
    _CallSETranslator(
      pExcept: (EHExceptionRecord *)0x123,
      pRN: (EHRegistrationNode *)&pContinue,
      pContext: nullptr,
      pDC: nullptr,
      pFuncInfo: nullptr,
      CatchDepth: 0,
      pMarkerRN: nullptr);
    return ((_EXCEPTION_DISPOSITION (*)(void))pContinue)();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038148
// Name: __CreateFrameInfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
FrameInfo *__cdecl _CreateFrameInfo(FrameInfo *pFrameInfo, void *pExceptionObject)
{
  pFrameInfo->pExceptionObject = pExceptionObject;
  pFrameInfo->pNext = (FrameInfo *)_getptd()->_pFrameInfoChain;
  _getptd()->_pFrameInfoChain = pFrameInfo;
  return pFrameInfo;
}

//------------------------------------------------------------------------------
// Address: 0x10038174
// Name: __IsExceptionObjectToBeDestroyed
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _IsExceptionObjectToBeDestroyed(void *pExceptionObject)
{
  void **i; // eax

  for ( i = (void **)_getptd()->_pFrameInfoChain; ; i = (void **)i[1] )
  {
    if ( i == nullptr )
      return 1;
    if ( *i == pExceptionObject )
      break;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003819B
// Name: __FindAndUnlinkFrame
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _FindAndUnlinkFrame(FrameInfo *pFrameInfo)
{
  _DWORD *i; // eax

  if ( pFrameInfo == _getptd()->_pFrameInfoChain )
  {
    _getptd()->_pFrameInfoChain = pFrameInfo->pNext;
  }
  else
  {
    for ( i = _getptd()->_pFrameInfoChain; ; i = (_DWORD *)i[1] )
    {
      if ( i[1] == 0 )
        _inconsistency();
      if ( pFrameInfo == (FrameInfo *)i[1] )
        break;
    }
    i[1] = pFrameInfo->pNext;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100381ED
// Name: void __near * _CallCatchBlock2(struct EHRegistrationNode __near *,struct _s_FuncInfo const __near *,void __near *,int,unsigned long)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _CallCatchBlock2(
        EHRegistrationNode *pRN,
        const _s_FuncInfo *pFuncInfo,
        void *handlerAddress,
        int CatchDepth,
        unsigned int NLGCode)
{
  _CallSettingFrame(funclet: (unsigned int)handlerAddress, (unsigned int)pRN, dwInCode: NLGCode);
}

//------------------------------------------------------------------------------
// Address: 0x10038250
// Name: __allmul
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _allmul(__int64 a1, __int64 a2)
{
  if ( (HIDWORD(a1) | HIDWORD(a2)) != 0 )
    return a1 * a2;
  else
    return (unsigned int)a2 * (unsigned __int64)(unsigned int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x10038290
// Name: __aulldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldiv(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v3; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = v6 / v5;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    return v8;
  }
  else
  {
    LODWORD(v3) = a1;
    HIDWORD(v3) = HIDWORD(a1) % (unsigned int)a2;
    return v3 / (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038300
// Name: __aullrem
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __stdcall _aullrem(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  bool v7; // cf
  int v8; // ecx
  unsigned __int64 v9; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v8 = HIDWORD(a2) * (v6 / v5);
    v9 = (unsigned int)a2 * (unsigned __int64)(unsigned int)(v6 / v5);
    v7 = __CFADD__(v8, HIDWORD(v9));
    HIDWORD(v9) += v8;
    if ( v7 || v9 > a1 )
      v9 -= a2;
    return a1 - v9;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 % (unsigned int)a2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10038375
// Name: _sprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf(char *string, const char *format, ...)
{
  int v3; // eax
  bool v4; // sf
  int v5; // esi
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  va_list argptr; // [esp+38h] [ebp+10h] BYREF

  va_start(argptr, format);
  memset(&str, 0, sizeof(str));
  if ( format != nullptr && string != nullptr )
  {
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    str._flag = 66;
    v3 = _output_l(stream: &str, format, plocinfo: nullptr, argptr);
    v4 = --str._cnt < 0;
    v5 = v3;
    if ( v4 )
      _flsbuf(ch: 0, &str);
    else
      *str._ptr = 0;
    return v5;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100383F9
// Name: _sprintf_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sprintf_s(char *string, unsigned int sizeInBytes, const char *format, ...)
{
  va_list ap; // [esp+14h] [ebp+14h] BYREF

  va_start(ap, format);
  return _vsprintf_s_l(string, sizeInBytes, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x10038420
// Name: _memset
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memset(int dst, unsigned __int8 *value, unsigned int count)
{
  unsigned int v3; // edx
  int v4; // eax
  unsigned __int8 *v5; // edi
  int v6; // ecx
  unsigned int v7; // ecx
  unsigned int v8; // ecx

  v3 = count;
  if ( count != 0 )
  {
    LOBYTE(v4) = (_BYTE)value;
    if ( (_BYTE)value != 0 || count < 0x80 || __sse2_available == 0 )
    {
      v5 = (unsigned __int8 *)dst;
      if ( count < 4 )
        goto LABEL_15;
      v6 = -dst & 3;
      if ( v6 != 0 )
      {
        v3 = count - v6;
        do
        {
          *v5++ = (unsigned __int8)value;
          --v6;
        }
        while ( v6 != 0 );
      }
      v4 = 16843009 * (unsigned __int8)value;
      v7 = v3;
      v3 &= 3u;
      v8 = v7 >> 2;
      if ( v8 == 0 || (memset32(v5, v4, v8), v5 += 4 * v8, v3 != 0) )
      {
LABEL_15:
        do
        {
          *v5++ = v4;
          --v3;
        }
        while ( v3 != 0 );
      }
    }
    else
    {
      _VEC_memzero((void *)dst, val: (int)value, len: count);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003849A
// Name: strtoxl
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtoxl(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        unsigned int ibase,
        int flags)
{
  threadlocaleinfostruct *locinfo; // ecx
  unsigned __int8 v7; // bl
  const char *i; // edi
  int v9; // eax
  unsigned int v10; // eax
  const unsigned __int16 *pctype; // esi
  unsigned int v12; // ecx
  int v13; // ecx
  const char *v14; // edi
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-1Ch] BYREF
  unsigned int v16; // [esp+18h] [ebp-8h]
  unsigned int number; // [esp+1Ch] [ebp-4h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && ((int)ibase < 2 || (int)ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  number = 0;
  locinfo = _loc_update.localeinfo.locinfo;
  v7 = *nptr;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[v7] & 8;
    }
    else
    {
      v9 = _isctype_l(c: v7, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    v7 = *i;
  }
  if ( v7 == 45 )
  {
    flags |= 2u;
  }
  else if ( v7 != 43 )
  {
    goto LABEL_20;
  }
  v7 = *i++;
LABEL_20:
  if ( ibase != 0 )
  {
    if ( ibase != 16 || v7 != 48 )
      goto LABEL_32;
  }
  else
  {
    if ( v7 != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( *i == 120 || *i == 88 )
  {
    v7 = i[1];
    i += 2;
  }
LABEL_32:
  v10 = 0xFFFFFFFF / ibase;
  pctype = locinfo->pctype;
  v16 = 0xFFFFFFFF % ibase;
  while ( 1 )
  {
    if ( (pctype[v7] & 4) != 0 )
    {
      v12 = (char)v7 - 48;
    }
    else
    {
      if ( (pctype[v7] & 0x103) == 0 )
        break;
      v13 = (char)v7;
      if ( (unsigned __int8)(v7 - 97) <= 0x19u )
        v13 = (char)v7 - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < v10 || number == v10 && v12 <= v16 )
    {
      number = v12 + ibase * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v7 = *i++;
  }
  v14 = i - 1;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0 && ((flags & 2) != 0 && number > 0x80000000 || (flags & 2) == 0 && number > 0x7FFFFFFF) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
        number = -1;
      else
        number = ((flags & 2) != 0) + 0x7FFFFFFF;
    }
  }
  else
  {
    if ( endptr != nullptr )
      v14 = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = v14;
  if ( (flags & 2) != 0 )
    number = -number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x100386C5
// Name: _strtol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl strtol(const char *nptr, char **endptr, unsigned int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxl(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 0);
  else
    return strtoxl(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100386F0
// Name: _atol
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl atol(const char *nptr)
{
  return strtol(nptr, endptr: nullptr, ibase: 0xAu);
}

//------------------------------------------------------------------------------
// Address: 0x10038706
// Name: _atoi
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl atoi(const char *nptr)
{
  return atol(nptr);
}

//------------------------------------------------------------------------------
// Address: 0x10038834
// Name: _atexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl atexit(void (__cdecl *func)())
{
  return (_onexit((int (__cdecl *)())func) != nullptr) - 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003884B
// Name: IsRootUNCName
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __usercall IsRootUNCName@<eax>(const char *path@<esi>)
{
  unsigned int v1; // eax
  char v2; // al
  char v3; // al
  const char *v4; // eax
  char v5; // cl
  char *v6; // eax
  char v7; // cl
  unsigned __int8 *v9; // [esp+0h] [ebp-4h]

  strlen(buf: v9);
  if ( v1 < 5 || *path != 92 && *path != 47 )
    return false;
  v2 = path[1];
  if ( v2 != 92 && v2 != 47 )
    return false;
  v3 = path[2];
  if ( v3 == 92 )
    return false;
  if ( v3 == 47 )
    return false;
  v4 = path + 3;
  v5 = path[3];
  if ( v5 == 0 )
    return false;
  do
  {
    if ( v5 == 92 )
      break;
    if ( v5 == 47 )
      break;
    v5 = *++v4;
  }
  while ( *v4 != 0 );
  if ( *v4 == 0 )
    return false;
  v6 = (char *)(v4 + 1);
  if ( *v6 == 0 )
    return false;
  v7 = *v6;
  do
  {
    if ( v7 == 92 )
      break;
    if ( v7 == 47 )
      break;
    v7 = *++v6;
  }
  while ( *v6 != 0 );
  return *v6 == 0 || v6[1] == 0;
}

//------------------------------------------------------------------------------
// Address: 0x100388C5
// Name: _fullpath_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl fullpath_helper(char *buf, const char *path, unsigned int sz, char **pBuf)
{
  int v4; // esi
  char *v5; // edi
  int *v6; // eax
  char *result; // eax

  v4 = *_errno();
  *_errno() = 0;
  v5 = _fullpath(UserBuf: buf, path, maxlen: sz);
  v6 = _errno();
  if ( v5 != nullptr )
  {
    *v6 = v4;
    return v5;
  }
  else if ( *v6 == 34 )
  {
    *_errno() = v4;
    result = _fullpath(UserBuf: nullptr, path, maxlen: 0);
    *pBuf = result;
  }
  else
  {
    return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038925
// Name: __stat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stat64i32(const char *name, _stat64i32 *buf)
{
  const char *dwHighDateTime; // esi
  unsigned int v3; // eax
  unsigned __int8 *v4; // eax
  const char *v5; // esi
  int v6; // eax
  __int64 v7; // rax
  int v8; // esi
  DWORD LastError; // eax
  int retval; // [esp+Ch] [ebp-26Ch]
  int drive; // [esp+10h] [ebp-268h]
  _FILETIME LocalFTime; // [esp+14h] [ebp-264h] BYREF
  int fd; // [esp+1Ch] [ebp-25Ch] BYREF
  _WIN32_FIND_DATAA findbuf; // [esp+20h] [ebp-258h] BYREF
  _SYSTEMTIME SystemTime; // [esp+160h] [ebp-118h] BYREF
  char pathbuf[260]; // [esp+170h] [ebp-108h] BYREF

  dwHighDateTime = name;
  LocalFTime.dwHighDateTime = (unsigned int)name;
  retval = 0;
  if ( name == nullptr || buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "?*") != nullptr )
  {
LABEL_5:
    *_errno() = 2;
    *__doserrno() = 2;
    return -1;
  }
  if ( name[1] == 58 )
  {
    if ( *name != 0 && name[2] == 0 )
      goto LABEL_5;
    v3 = _mbctolower(c: *name) - 96;
  }
  else
  {
    v3 = _getdrive();
  }
  drive = v3;
  fd = (int)FindFirstFileExA(
              lpFileName: name,
              fInfoLevelId: FindExInfoStandard,
              lpFindFileData: &findbuf,
              fSearchOp: FindExSearchNameMatch,
              lpSearchFilter: nullptr,
              dwAdditionalFlags: 0);
  if ( fd != -1 )
  {
    if ( (findbuf.dwFileAttributes & 0x400) != 0 && findbuf.dwReserved0 == -1610612724 )
    {
      fd = -1;
      if ( _sopen_s(pfh: &fd, path: name, oflag: 0, shflag: 64, pmode: 0) == 0 && fd != -1 )
      {
        v8 = _fstat64i32(fildes: fd, buf);
        _close(fh: fd);
        return v8;
      }
      goto LABEL_5;
    }
    if ( findbuf.ftLastWriteTime.dwLowDateTime != 0 || findbuf.ftLastWriteTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastWriteTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_mtime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_mtime = 0;
    }
    if ( findbuf.ftLastAccessTime.dwLowDateTime != 0 || findbuf.ftLastAccessTime.dwHighDateTime != 0 )
    {
      if ( !FileTimeToLocalFileTime(lpFileTime: &findbuf.ftLastAccessTime, lpLocalFileTime: &LocalFTime)
        || !FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
      {
        goto LABEL_49;
      }
      buf->st_atime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
    }
    else
    {
      buf->st_atime = buf->st_mtime;
    }
    if ( findbuf.ftCreationTime.dwLowDateTime == 0 && findbuf.ftCreationTime.dwHighDateTime == 0 )
    {
      buf->st_ctime = buf->st_mtime;
LABEL_45:
      FindClose(hFindFile: (HANDLE)fd);
      goto LABEL_46;
    }
    if ( FileTimeToLocalFileTime(lpFileTime: &findbuf.ftCreationTime, lpLocalFileTime: &LocalFTime)
      && FileTimeToSystemTime(lpFileTime: &LocalFTime, lpSystemTime: &SystemTime) )
    {
      buf->st_ctime = __loctotime64_t(
                        yr: SystemTime.wYear,
                        mo: SystemTime.wMonth,
                        dy: SystemTime.wDay,
                        hr: SystemTime.wHour,
                        mn: SystemTime.wMinute,
                        sc: SystemTime.wSecond,
                        dstflag: -1);
      goto LABEL_45;
    }
LABEL_49:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    FindClose(hFindFile: (HANDLE)fd);
    return -1;
  }
  fd = 0;
  if ( _mbspbrk(string: (const unsigned __int8 *)name, charset: "./\\") == nullptr )
    goto LABEL_5;
  v4 = (unsigned __int8 *)fullpath_helper(buf: pathbuf, path: name, sz: 0x104u, pBuf: (char **)&fd);
  v5 = (const char *)v4;
  if ( v4 == nullptr || (strlen(buf: v4), v6 != 3) && !IsRootUNCName(path: v5) || GetDriveTypeA(lpRootPathName: v5) <= 1 )
  {
    if ( fd != 0 )
      free(pMem: (void *)fd);
    goto LABEL_5;
  }
  if ( fd != 0 )
    free(pMem: (void *)fd);
  findbuf.dwFileAttributes = 16;
  findbuf.nFileSizeHigh = 0;
  findbuf.nFileSizeLow = 0;
  findbuf.cFileName[0] = 0;
  v7 = __loctotime64_t(yr: 1980, mo: 1, dy: 1, hr: 0, mn: 0, sc: 0, dstflag: -1);
  dwHighDateTime = (const char *)LocalFTime.dwHighDateTime;
  buf->st_mtime = v7;
  buf->st_atime = v7;
  buf->st_ctime = v7;
LABEL_46:
  buf->st_mode = __dtoxmode(attr: findbuf.dwFileAttributes, name: dwHighDateTime);
  buf->st_nlink = 1;
  buf->st_size = findbuf.nFileSizeLow;
  if ( findbuf.nFileSizeHigh != 0 )
  {
    retval = -1;
    buf->st_size = 0;
  }
  buf->st_ino = 0;
  buf->st_gid = 0;
  buf->st_uid = 0;
  buf->st_dev = drive - 1;
  buf->st_rdev = drive - 1;
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10038D7C
// Name: _setvbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl setvbuf(_iobuf *str, char *buffer, int type, unsigned int size)
{
  unsigned int v5; // edi
  int v6; // edi
  int flag; // ecx
  int v8; // ecx
  char *p_charbuf; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  if ( str == nullptr )
    goto LABEL_2;
  if ( type != 4 )
  {
    if ( type == 0 )
      goto LABEL_7;
    if ( type != 64 )
    {
LABEL_2:
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return -1;
    }
  }
  if ( type != 64 )
  {
    v5 = size;
    goto LABEL_10;
  }
LABEL_7:
  v5 = size;
  if ( size - 2 > 0x7FFFFFFD )
    goto LABEL_2;
LABEL_10:
  v6 = v5 & 0xFFFFFFFE;
  _lock_file(pf: str);
  _flush(str);
  _freebuf(stream: str);
  str->_flag &= 0xFFFFC2F3;
  flag = str->_flag;
  if ( (type & 4) != 0 )
  {
    v8 = flag | 4;
    p_charbuf = (char *)&str->_charbuf;
    v6 = 2;
LABEL_17:
    str->_flag = v8;
    goto LABEL_18;
  }
  p_charbuf = buffer;
  if ( buffer != nullptr )
  {
    v8 = flag | 0x500;
    goto LABEL_17;
  }
  p_charbuf = (char *)operator new(nSize: v6);
  if ( p_charbuf != nullptr )
  {
    str->_flag |= 0x408u;
LABEL_18:
    str->_bufsiz = v6;
    str->_base = p_charbuf;
    str->_ptr = p_charbuf;
    str->_cnt = 0;
    goto done_1;
  }
  ++_cflush;
  retval = -1;
done_1:
  _unlock_file(pf: str);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10038E72
// Name: __initp_heap_handler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_heap_handler(int (__cdecl *enull)(unsigned int))
{
  _pnhHeap = enull;
}

//------------------------------------------------------------------------------
// Address: 0x10038E81
// Name: __validdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _validdrive(unsigned int drive)
{
  BOOL result; // eax
  wchar_t drvstr[4]; // [esp+0h] [ebp-Ch] BYREF

  result = true;
  if ( drive != 0 )
  {
    drvstr[0] = drive + 64;
    wcscpy(&drvstr[1], L":\\");
    if ( GetDriveTypeW(lpRootPathName: drvstr) <= 1 )
      return false;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10038EDB
// Name: __getdcwd_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getdcwd_nolock(unsigned int drive, char *pnbuf, int maxlen)
{
  int v3; // ebx
  char *v5; // edi
  signed int FullPathNameA; // eax
  char *v7; // eax
  signed int v8; // eax
  DWORD LastError; // eax
  char *pname; // [esp+4h] [ebp-8h] BYREF
  int count; // [esp+8h] [ebp-4h]

  v3 = drive;
  if ( drive != 0 )
  {
    if ( !_validdrive(drive) )
    {
      *__doserrno() = 15;
      *_errno() = 13;
      _invalid_parameter_noinfo();
      return nullptr;
    }
  }
  else
  {
    v3 = _getdrive();
  }
  v5 = pnbuf;
  if ( pnbuf != nullptr )
  {
    if ( maxlen <= 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    count = maxlen;
    *pnbuf = 0;
  }
  else
  {
    count = 0;
  }
  if ( v3 != 0 )
  {
    LOBYTE(drive) = v3 + 64;
    strcpy((char *)&drive + 1, ":.");
  }
  else
  {
    strcpy((char *)&drive, ".");
  }
  FullPathNameA = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: count, lpBuffer: v5, lpFilePart: &pname);
  if ( FullPathNameA == 0 )
    goto LABEL_24;
  if ( v5 == nullptr )
  {
    if ( FullPathNameA > maxlen )
      maxlen = FullPathNameA;
    v7 = (char *)calloc(count: maxlen, size: 1u);
    v5 = v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      *__doserrno() = 8;
      return nullptr;
    }
    v8 = GetFullPathNameA(lpFileName: (LPCSTR)&drive, nBufferLength: maxlen, lpBuffer: v7, lpFilePart: &pname);
    if ( v8 != 0 && v8 < maxlen )
      return v5;
LABEL_24:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return nullptr;
  }
  if ( FullPathNameA < count )
    return v5;
  *_errno() = 34;
  *v5 = 0;
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x10038FFF
// Name: __getcwd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _getcwd(char *pnbuf, int maxlen)
{
  char *retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = _getdcwd_nolock(drive: 0, pnbuf, maxlen);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x10039048
// Name: __mkdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mkdir(const char *path)
{
  DWORD LastError; // eax

  if ( CreateDirectoryA(lpPathName: path, lpSecurityAttributes: nullptr) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x10039080
// Name: __alloca_probe_16
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _alloca_probe_16()
{
  return _chkstk();
}

//------------------------------------------------------------------------------
// Address: 0x100390AC
// Name: ___crtCorExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __crtCorExitProcess(int status)
{
  HMODULE ModuleHandleW; // eax
  FARPROC CorExitProcess; // eax

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"mscoree.dll");
  if ( ModuleHandleW != nullptr )
  {
    CorExitProcess = GetProcAddress(hModule: ModuleHandleW, lpProcName: "CorExitProcess");
    if ( CorExitProcess != nullptr )
      ((void (__stdcall *)(int))CorExitProcess)(a1: status);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100390D7
// Name: ___crtExitProcess
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn __crtExitProcess(int status)
{
  __crtCorExitProcess(status);
  ExitProcess(uExitCode: status);
}

//------------------------------------------------------------------------------
// Address: 0x100390EF
// Name: __lockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _lockexit()
{
  _lock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x100390F8
// Name: __unlockexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _unlockexit()
{
  _unlock(locknum: 8);
}

//------------------------------------------------------------------------------
// Address: 0x10039101
// Name: __init_pointers
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _init_pointers()
{
  int (__cdecl *v0)(unsigned int); // esi

  v0 = (int (__cdecl *)(unsigned int))_encoded_null();
  _initp_heap_handler(enull: v0);
  _initp_misc_invarg(enull: v0);
  _initp_misc_purevirt(enull: v0);
  _initp_misc_rand_s(enull: v0);
  _initp_misc_winsig(enull: v0);
  _initp_eh_hooks(enull: v0);
}

//------------------------------------------------------------------------------
// Address: 0x10039134
// Name: __initterm_e
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _initterm_e(int (__cdecl **pfbegin)(), int (__cdecl **pfend)())
{
  int result; // eax

  result = 0;
  while ( pfbegin < pfend && result == 0 )
  {
    if ( *pfbegin != nullptr )
      result = (*pfbegin)();
    ++pfbegin;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039158
// Name: __cinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cinit(int initFloatingPrecision)
{
  int result; // eax
  void (**i)(void); // edi

  if ( _fpmath != nullptr && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&_FPinit) != 0 )
    _fpmath(initPrecision: initFloatingPrecision);
  _initp_misc_cfltcvt_tab();
  result = _initterm_e(pfbegin: __xi_a, pfend: __xi_z);
  if ( result == 0 )
  {
    atexit(func: _RTC_Terminate);
    for ( i = __xc_a; i < __xc_z; ++i )
    {
      if ( *i != nullptr )
        (*i)();
    }
    if ( __dyn_tls_init_callback != nullptr
      && _IsNonwritableInCurrentImage(pTarget: (unsigned __int8 *)&__dyn_tls_init_callback) != 0 )
    {
      __dyn_tls_init_callback(a1: nullptr, a2: 2u, a3: nullptr);
    }
    return 0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100391EF
// Name: doexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl doexit(int code, int quick, int retcaller)
{
  PVOID *v3; // ebx
  PVOID *v4; // edi
  void (*v5)(void); // ebx
  void (__cdecl **v6)(); // ebx
  void (__cdecl **v7)(); // eax
  void (__cdecl **onexitbegin)(); // [esp+10h] [ebp-30h]
  void (__cdecl **onexitend_saved)(); // [esp+18h] [ebp-28h]
  void (__cdecl **onexitbegin_saved)(); // [esp+1Ch] [ebp-24h]
  void (**j)(void); // [esp+20h] [ebp-20h]
  void (**i)(void); // [esp+24h] [ebp-1Ch]

  _lock(locknum: 8);
  if ( _C_Exit_Done != 1 )
  {
    _C_Termination_Done = 1;
    _exitflag = retcaller;
    if ( quick == 0 )
    {
      v3 = (PVOID *)DecodePointer(Ptr: __onexitbegin);
      onexitbegin = (void (__cdecl **)())v3;
      if ( v3 != nullptr )
      {
        v4 = (PVOID *)DecodePointer(Ptr: __onexitend);
        onexitbegin_saved = (void (__cdecl **)())v3;
        onexitend_saved = (void (__cdecl **)())v4;
        while ( --v4 >= v3 )
        {
          if ( *v4 != (PVOID)_encoded_null() )
          {
            if ( v4 < v3 )
              break;
            v5 = (void (*)(void))DecodePointer(Ptr: *v4);
            *v4 = (PVOID)_encoded_null();
            v5();
            v6 = (void (__cdecl **)())DecodePointer(Ptr: __onexitbegin);
            v7 = (void (__cdecl **)())DecodePointer(Ptr: __onexitend);
            if ( onexitbegin_saved != v6 || onexitend_saved != v7 )
            {
              onexitbegin_saved = v6;
              onexitbegin = v6;
              onexitend_saved = v7;
              v4 = (PVOID *)v7;
            }
            v3 = (PVOID *)onexitbegin;
          }
        }
      }
      for ( i = __xp_a; i < __xp_z; ++i )
      {
        if ( *i != nullptr )
          (*i)();
      }
    }
    for ( j = __xt_a; j < __xt_z; ++j )
    {
      if ( *j != nullptr )
        (*j)();
    }
  }
  if ( retcaller != 0 )
    _unlock(locknum: 8);
  if ( retcaller == 0 )
  {
    _C_Exit_Done = 1;
    _unlock(locknum: 8);
    __crtExitProcess(status: code);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003932F
// Name: _exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn exit(int code)
{
  doexit(code, quick: 0, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x10039345
// Name: __exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _exit(int code)
{
  doexit(code, quick: 1, retcaller: 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003935B
// Name: __cexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cexit()
{
  doexit(code: 0, quick: 0, retcaller: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003936A
// Name: __amsg_exit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _amsg_exit(int rterrnum)
{
  _FF_MSGBANNER();
  _NMSG_WRITE(rterrnum);
  _exit(code: 255);
}

//------------------------------------------------------------------------------
// Address: 0x10039388
// Name: __findclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findclose(void *hFile)
{
  if ( FindClose(hFindFile: hFile) )
    return 0;
  *_errno() = 22;
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100393AE
// Name: ___time64_t_from_ft
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __time64_t_from_ft(_FILETIME *pft)
{
  _FILETIME lft; // [esp+0h] [ebp-1Ch] BYREF
  _SYSTEMTIME st; // [esp+8h] [ebp-14h] BYREF

  if ( (pft->dwLowDateTime != 0 || pft->dwHighDateTime != 0)
    && FileTimeToLocalFileTime(lpFileTime: pft, lpLocalFileTime: &lft)
    && FileTimeToSystemTime(lpFileTime: &lft, lpSystemTime: &st) )
  {
    return __loctotime64_t(
             yr: st.wYear,
             mo: st.wMonth,
             dy: st.wDay,
             hr: st.wHour,
             mn: st.wMinute,
             sc: st.wSecond,
             dstflag: 0);
  }
  else
  {
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003942A
// Name: __findfirst64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findfirst64i32(const char *szWild, _finddata64i32_t *pfd)
{
  HANDLE FirstFile; // ebx
  DWORD LastError; // eax
  int v5; // edx
  int v6; // edx
  int v7; // edx
  _WIN32_FIND_DATAA wfd; // [esp+8h] [ebp-144h] BYREF

  if ( pfd == nullptr || szWild == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  FirstFile = FindFirstFileExA(
                lpFileName: szWild,
                fInfoLevelId: FindExInfoStandard,
                lpFindFileData: &wfd,
                fSearchOp: FindExSearchNameMatch,
                lpSearchFilter: nullptr,
                dwAdditionalFlags: 0);
  if ( FirstFile == (HANDLE)-1 )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_13;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_13:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v5;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v6;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v7;
  if ( strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName) != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return (int)FirstFile;
}

//------------------------------------------------------------------------------
// Address: 0x10039551
// Name: __findnext64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _findnext64i32(void *hFile, _finddata64i32_t *pfd)
{
  int result; // eax
  DWORD LastError; // eax
  int v4; // edx
  int v5; // edx
  int v6; // edx
  _WIN32_FIND_DATAA wfd; // [esp+4h] [ebp-144h] BYREF

  if ( hFile == (void *)-1 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( pfd == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !FindNextFileA(hFindFile: hFile, lpFindFileData: &wfd) )
  {
    LastError = GetLastError();
    if ( LastError >= 2 )
    {
      if ( LastError <= 3 )
        goto LABEL_14;
      if ( LastError == 8 )
      {
        *_errno() = 12;
        return -1;
      }
      if ( LastError == 18 )
      {
LABEL_14:
        *_errno() = 2;
        return -1;
      }
    }
    *_errno() = 22;
    return -1;
  }
  pfd->attrib = wfd.dwFileAttributes != 128 ? wfd.dwFileAttributes : 0;
  LODWORD(pfd->time_create) = __time64_t_from_ft(pft: &wfd.ftCreationTime);
  HIDWORD(pfd->time_create) = v4;
  LODWORD(pfd->time_access) = __time64_t_from_ft(pft: &wfd.ftLastAccessTime);
  HIDWORD(pfd->time_access) = v5;
  LODWORD(pfd->time_write) = __time64_t_from_ft(pft: &wfd.ftLastWriteTime);
  pfd->size = wfd.nFileSizeLow;
  HIDWORD(pfd->time_write) = v6;
  result = strcpy_s(_Dst: pfd->name, _SizeInBytes: 0x104u, _Src: wfd.cFileName);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003967F
// Name: __fsopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _fsopen(_iobuf *file, const char *mode, int shflag)
{
  _iobuf *v5; // eax
  _iobuf *retval; // [esp+10h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+14h] [ebp-18h] BYREF
  _iobuf *stream; // [esp+34h] [ebp+8h]

  if ( file == nullptr || mode == nullptr || *mode == 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  v5 = _getstream();
  stream = v5;
  if ( v5 == nullptr )
  {
    *_errno() = 24;
    return nullptr;
  }
  ms_exc.registration.TryLevel = 0;
  if ( LOBYTE(file->_ptr) == 0 )
  {
    *_errno() = 22;
    _local_unwind4(a1: &__security_cookie, a2: &ms_exc.registration, a3: -2);
    return nullptr;
  }
  retval = _openfile(filename: (const char *)file, mode, shflag, str: v5);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003973B
// Name: _fopen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl fopen(_iobuf *file, const char *mode)
{
  return _fsopen(file, mode, shflag: 64);
}

//------------------------------------------------------------------------------
// Address: 0x10039752
// Name: __fread_nolock_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fread_nolock_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int num,
        _iobuf *stream)
{
  unsigned int v6; // edi
  unsigned int v7; // ebx
  int cnt; // eax
  unsigned int v9; // edi
  unsigned int v10; // edx
  int v11; // eax
  unsigned int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  char *v16; // ecx
  unsigned int v17; // [esp-4h] [ebp-20h]
  unsigned int streambufsize; // [esp+10h] [ebp-Ch]
  char *data; // [esp+14h] [ebp-8h]
  unsigned int dataSize; // [esp+18h] [ebp-4h]

  data = buffer;
  dataSize = bufferSize;
  if ( elementSize == 0 || num == 0 )
    return 0;
  if ( buffer != nullptr )
  {
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
      goto LABEL_13;
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    if ( stream != nullptr && num <= 0xFFFFFFFF / elementSize )
    {
LABEL_13:
      v6 = num * elementSize;
      v7 = num * elementSize;
      if ( (stream->_flag & 0x10C) != 0 )
        streambufsize = stream->_bufsiz;
      else
        streambufsize = 4096;
      if ( v6 == 0 )
        return num;
      while ( 1 )
      {
        if ( (stream->_flag & 0x10C) != 0 )
        {
          cnt = stream->_cnt;
          if ( cnt != 0 )
          {
            if ( cnt < 0 )
              goto LABEL_44;
            v9 = v7;
            if ( v7 >= cnt )
              v9 = stream->_cnt;
            if ( v9 > dataSize )
              goto LABEL_41;
            memcpy_s(dst: data, sizeInBytes: dataSize, src: stream->_ptr, count: v9);
            stream->_cnt -= v9;
            stream->_ptr += v9;
            data += v9;
            v7 -= v9;
            dataSize -= v9;
            v6 = num * elementSize;
            goto LABEL_39;
          }
        }
        if ( v7 < streambufsize )
          break;
        if ( streambufsize != 0 )
        {
          if ( v7 <= 0x7FFFFFFF )
          {
            v10 = v7 % streambufsize;
            v11 = v7;
          }
          else
          {
            v10 = 0x7FFFFFFF % streambufsize;
            v11 = 0x7FFFFFFF;
          }
          v12 = v11 - v10;
        }
        else
        {
          v12 = 0x7FFFFFFF;
          if ( v7 <= 0x7FFFFFFF )
            v12 = v7;
        }
        if ( v12 > dataSize )
          goto LABEL_41;
        v17 = v12;
        v13 = _fileno(stream);
        v14 = _read(fh: v13, buf: data, cnt: v17);
        if ( v14 == 0 )
        {
          stream->_flag |= 0x10u;
          return (v6 - v7) / elementSize;
        }
        if ( v14 == -1 )
        {
LABEL_44:
          stream->_flag |= 0x20u;
          return (v6 - v7) / elementSize;
        }
        data += v14;
        v7 -= v14;
        dataSize -= v14;
LABEL_39:
        if ( v7 == 0 )
          return num;
      }
      v15 = _filbuf(str: stream);
      if ( v15 == -1 )
        return (v6 - v7) / elementSize;
      if ( dataSize != 0 )
      {
        v16 = data++;
        *v16 = v15;
        --v7;
        --dataSize;
        streambufsize = stream->_bufsiz;
        goto LABEL_39;
      }
LABEL_41:
      if ( bufferSize != -1 )
        memset(dst: (int)buffer, value: nullptr, count: bufferSize);
      *_errno() = 34;
LABEL_5:
      _invalid_parameter_noinfo();
      return 0;
    }
  }
  *_errno() = 22;
  goto LABEL_5;
}

//------------------------------------------------------------------------------
// Address: 0x1003990E
// Name: _fread_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread_s(
        char *buffer,
        unsigned int bufferSize,
        unsigned int elementSize,
        unsigned int count,
        _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( elementSize == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    if ( bufferSize != -1 )
      memset(dst: (int)buffer, value: nullptr, count: bufferSize);
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fread_nolock_s(buffer, bufferSize, elementSize, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003999C
// Name: _fread
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fread(char *buffer, unsigned int elementSize, unsigned int count, _iobuf *stream)
{
  return fread_s(buffer, bufferSize: 0xFFFFFFFF, elementSize, count, stream);
}

//------------------------------------------------------------------------------
// Address: 0x100399B9
// Name: __ftell_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ftell_nolock(_iobuf *str)
{
  int v3; // eax
  int v4; // esi
  int v5; // eax
  int flag; // edx
  char *ptr; // eax
  char *base; // ecx
  char *v9; // ebx
  char *v10; // edx
  int cnt; // edx
  ioinfo **v12; // ebx
  int v13; // esi
  char *v14; // eax
  char *v15; // ecx
  bool v16; // zf
  int bufsiz; // eax
  int v18; // ecx
  unsigned int offset; // [esp+8h] [ebp-Ch]
  int fd; // [esp+Ch] [ebp-8h]
  int filepos; // [esp+10h] [ebp-4h]
  unsigned int rdcnt; // [esp+1Ch] [ebp+8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v3 = _fileno(stream: str);
  v4 = v3;
  fd = v3;
  if ( str->_cnt < 0 )
    str->_cnt = 0;
  v5 = _lseek(fh: v3, pos: 0, mthd: 1);
  filepos = v5;
  if ( v5 < 0 )
    return -1;
  flag = str->_flag;
  if ( (flag & 0x108) == 0 )
    return v5 - str->_cnt;
  ptr = str->_ptr;
  base = str->_base;
  v9 = (char *)(str->_ptr - base);
  offset = (unsigned int)v9;
  if ( (flag & 3) != 0 )
  {
    if ( __pioinfo[v4 >> 5][v4 & 0x1F].osfile < 0 )
    {
      v10 = str->_base;
      if ( base < ptr )
      {
        do
        {
          if ( *v10 == 10 )
            ++v9;
          ++v10;
        }
        while ( v10 < ptr );
        offset = (unsigned int)v9;
      }
    }
  }
  else if ( (flag & 0x80u) == 0 )
  {
    *_errno() = 22;
    return -1;
  }
  if ( filepos == 0 )
    return (int)v9;
  if ( (str->_flag & 1) == 0 )
    return filepos + offset;
  cnt = str->_cnt;
  if ( cnt != 0 )
  {
    v12 = &__pioinfo[fd >> 5];
    rdcnt = cnt + ptr - base;
    v13 = (fd & 0x1F) << 6;
    if ( *(&(*v12)->osfile + v13) >= 0 )
    {
LABEL_39:
      filepos -= rdcnt;
      return filepos + offset;
    }
    if ( _lseek(fh: fd, pos: 0, mthd: 2) == filepos )
    {
      v14 = str->_base;
      v15 = &v14[rdcnt];
      while ( v14 < v15 )
      {
        if ( *v14 == 10 )
          ++rdcnt;
        ++v14;
      }
      v16 = (str->_flag & 0x2000) == 0;
LABEL_37:
      if ( !v16 )
        ++rdcnt;
      goto LABEL_39;
    }
    if ( _lseek(fh: fd, pos: filepos, mthd: 0) >= 0 )
    {
      bufsiz = 512;
      if ( rdcnt > 0x200 || ((v18 = str->_flag) & 8) == 0 || (v18 & 0x400) != 0 )
        bufsiz = str->_bufsiz;
      rdcnt = bufsiz;
      v16 = (*(&(*v12)->osfile + v13) & 4) == 0;
      goto LABEL_37;
    }
    return -1;
  }
  offset = 0;
  return filepos + offset;
}

//------------------------------------------------------------------------------
// Address: 0x10039B4D
// Name: _ftell
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl ftell(_iobuf *stream)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr )
  {
    _lock_file(pf: stream);
    retval = _ftell_nolock(str: stream);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039BB2
// Name: __fseek_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fseek_nolock(_iobuf *str, int offset, int whence)
{
  int flag; // eax
  int v5; // eax
  int v6; // eax

  flag = str->_flag;
  if ( (flag & 0x83) != 0 )
  {
    str->_flag = flag & 0xFFFFFFEF;
    if ( whence == 1 )
    {
      offset += _ftell_nolock(str);
      whence = 0;
    }
    _flush(str);
    v5 = str->_flag;
    if ( (v5 & 0x80u) == 0 )
    {
      if ( (v5 & 1) != 0 && (v5 & 8) != 0 && (v5 & 0x400) == 0 )
        str->_bufsiz = 512;
    }
    else
    {
      str->_flag = v5 & 0xFFFFFFFC;
    }
    v6 = _fileno(stream: str);
    return (_lseek(fh: v6, pos: offset, mthd: whence) != -1) - 1;
  }
  else
  {
    *_errno() = 22;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039C3C
// Name: _fseek
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fseek(_iobuf *stream, int offset, unsigned int whence)
{
  int retval; // [esp+10h] [ebp-1Ch]

  if ( stream != nullptr && whence <= 2 )
  {
    _lock_file(pf: stream);
    retval = _fseek_nolock(str: stream, offset, whence);
    _unlock_file(pf: stream);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039CB8
// Name: __fclose_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fclose_nolock(_iobuf *str)
{
  int v1; // edi
  int v3; // eax

  v1 = -1;
  if ( str != nullptr )
  {
    if ( (str->_flag & 0x83) != 0 )
    {
      v1 = _flush(str);
      _freebuf(stream: str);
      v3 = _fileno(stream: str);
      if ( _close(fh: v3) >= 0 )
      {
        if ( str->_tmpfname != nullptr )
        {
          free(pMem: str->_tmpfname);
          str->_tmpfname = nullptr;
        }
      }
      else
      {
        v1 = -1;
      }
    }
    str->_flag = 0;
    return v1;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039D25
// Name: _fclose
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fclose(_iobuf *stream)
{
  int v2; // [esp+10h] [ebp-1Ch]

  v2 = -1;
  if ( stream != nullptr )
  {
    if ( (stream->_flag & 0x40) != 0 )
    {
      stream->_flag = 0;
    }
    else
    {
      _lock_file(pf: stream);
      v2 = _fclose_nolock(str: stream);
      _unlock_file(pf: stream);
    }
    return v2;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10039D99
// Name: __vsnprintf_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_l(char *string, unsigned int count, const char *format, localeinfo_struct *plocinfo, char *ap)
{
  int result; // eax
  int v6; // edi
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( format != nullptr && (count == 0 || string != nullptr) )
  {
    str._cnt = 0x7FFFFFFF;
    if ( count <= 0x7FFFFFFF )
      str._cnt = count;
    str._flag = 66;
    str._base = string;
    str._ptr = string;
    result = _output_l(stream: &str, format, plocinfo, argptr: ap);
    v6 = result;
    if ( string != nullptr )
    {
      if ( --str._cnt < 0 )
        _flsbuf(ch: 0, &str);
      else
        *str._ptr = 0;
      return v6;
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10039E45
// Name: __vsnprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf(char *string, unsigned int count, const char *format, char *ap)
{
  return _vsnprintf_l(string, count, format, plocinfo: nullptr, ap);
}

//------------------------------------------------------------------------------
// Address: 0x10039E70
// Name: _strrchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strrchr(unsigned __int8 *string, unsigned __int8 chr)
{
  unsigned int v2; // ecx
  unsigned __int8 *v3; // edi
  bool v4; // zf

  v2 = strlen((const char *)string) + 1;
  v3 = &string[v2 - 1];
  do
  {
    if ( v2 == 0 )
      break;
    v4 = *v3-- == chr;
    --v2;
  }
  while ( !v4 );
}

//------------------------------------------------------------------------------
// Address: 0x10039E9D
// Name: __chmod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chmod(const char *path, char mode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax
  DWORD v5; // eax

  if ( path == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1
    || (mode >= 0 ? (v5 = FileAttributesA | 1) : (v5 = FileAttributesA & 0xFFFFFFFE),
        !SetFileAttributesA(lpFileName: path, dwFileAttributes: v5)) )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10039F02
// Name: _fprintf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int fprintf(_iobuf *str, const char *format, ...)
{
  int v3; // eax
  ioinfo *v4; // ecx
  ioinfo *v5; // eax
  int v6; // esi
  int retval; // [esp+10h] [ebp-1Ch]
  va_list argptr; // [esp+3Ch] [ebp+10h] BYREF

  va_start(argptr, format);
  retval = 0;
  if ( str != nullptr && format != nullptr )
  {
    _lock_file(pf: str);
    if ( (str->_flag & 0x40) == 0 )
    {
      v3 = _fileno(stream: str);
      if ( v3 == -1 || v3 == -2 )
        v4 = &__badioinfo;
      else
        v4 = &__pioinfo[v3 >> 5][v3 & 0x1F];
      if ( (*((_BYTE *)v4 + 36) & 0x7F) != 0
        || (v3 == -1 || v3 == -2 ? (v5 = &__badioinfo) : (v5 = &__pioinfo[v3 >> 5][v3 & 0x1F]), *((char *)v5 + 36) < 0) )
      {
        *_errno() = 22;
        _invalid_parameter_noinfo();
        retval = -1;
      }
    }
    if ( retval == 0 )
    {
      v6 = _stbuf(str);
      retval = _output_l(stream: str, format, plocinfo: nullptr, argptr);
      _ftbuf(flag: v6, str);
    }
    _unlock_file(pf: str);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A00E
// Name: vscan_fn
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall vscan_fn@<eax>(
        char *string@<esi>,
        int (__cdecl *inputfn)(_iobuf *, const unsigned __int8 *, localeinfo_struct *, char *),
        const char *format,
        localeinfo_struct *plocinfo,
        char *arglist)
{
  unsigned int v6; // eax
  _iobuf str; // [esp+4h] [ebp-20h] BYREF

  memset(&str, 0, sizeof(str));
  if ( string != nullptr && format != nullptr )
  {
    strlen(buf: (unsigned __int8 *)string);
    str._flag = 73;
    str._base = string;
    str._ptr = string;
    str._cnt = 0x7FFFFFFF;
    if ( v6 <= 0x7FFFFFFF )
      str._cnt = v6;
    return inputfn(a1: &str, a2: (const unsigned __int8 *)format, a3: plocinfo, a4: arglist);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A07C
// Name: _sscanf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int sscanf(char *string, const char *format, ...)
{
  va_list arglist; // [esp+14h] [ebp+10h] BYREF

  va_start(arglist, format);
  return vscan_fn(string, inputfn: _input_l, format, plocinfo: nullptr, arglist);
}

//------------------------------------------------------------------------------
// Address: 0x1003A0A0
// Name: __chkstk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__usercall _chkstk@<eax>(unsigned int a1@<eax>, int a2@<ecx>)
{
  unsigned int v2; // ecx
  unsigned int i; // eax
  int v5; // [esp-4h] [ebp-4h] BYREF
  _UNKNOWN *retaddr; // [esp+0h] [ebp+0h] BYREF

  v5 = a2;
  v2 = ~((unsigned int)((unsigned int)&retaddr - (unsigned __int64)a1) >> 32) & ((unsigned int)&retaddr - a1);
  for ( i = (unsigned int)&v5 & 0xFFFFF000; v2 < i; i -= 4096 )
    ;
  return retaddr;
}

//------------------------------------------------------------------------------
// Address: 0x1003A0CB
// Name: _system
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl system(char *command)
{
  int v1; // esi
  int v2; // ebx
  int *v3; // eax
  char *argv[4]; // [esp+8h] [ebp-14h] BYREF
  char *envbuf; // [esp+18h] [ebp-4h] BYREF

  envbuf = nullptr;
  v1 = 0;
  if ( _dupenv_s(pBuffer: &envbuf, pBufferSizeInTChars: nullptr, varname: "COMSPEC") == 22 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  argv[0] = envbuf;
  if ( command == nullptr )
  {
    if ( envbuf != nullptr )
      v1 = _access_s(path: envbuf, amode: 0) == 0;
    goto cleanup;
  }
  argv[1] = "/c";
  argv[2] = command;
  argv[3] = nullptr;
  if ( envbuf == nullptr )
  {
LABEL_12:
    argv[0] = "cmd.exe";
    v1 = _spawnvpe(modeflag: 0, filename: "cmd.exe", (const char *const *)argv, envptr: nullptr);
    goto cleanup;
  }
  v2 = *_errno();
  *_errno() = 0;
  v1 = _spawnve(mode: 0, name: argv[0], (const char *const *)argv, envp: nullptr);
  v3 = _errno();
  if ( v1 != -1 )
  {
    *v3 = v2;
    goto cleanup;
  }
  if ( *v3 == 2 || *_errno() == 13 )
  {
    *_errno() = v2;
    goto LABEL_12;
  }
cleanup:
  free(pMem: envbuf);
  return v1;
}

//------------------------------------------------------------------------------
// Address: 0x1003A1B0
// Name: shortsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shortsort(
        char *hi@<eax>,
        char *lo,
        unsigned int width,
        int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edx
  char *v5; // edi
  unsigned int v6; // ecx
  char *v7; // esi
  char *v8; // ebx
  unsigned int v9; // esi
  char *v10; // eax
  int v11; // ecx
  char v12; // dl

  v4 = lo;
  v5 = hi;
  if ( hi > lo )
  {
    v6 = width;
    do
    {
      v7 = &lo[width];
      v8 = v4;
      if ( &lo[width] <= v5 )
      {
        do
        {
          if ( comp(a1: v7, a2: v8) > 0 )
            v8 = v7;
          v7 += width;
        }
        while ( v7 <= v5 );
        v6 = width;
        v4 = lo;
      }
      v9 = v6;
      v10 = v5;
      if ( v8 != v5 && v6 != 0 )
      {
        v11 = v8 - v5;
        do
        {
          v12 = v10[v11];
          v10[v11] = *v10;
          *v10++ = v12;
          --v9;
        }
        while ( v9 != 0 );
        v6 = width;
        v4 = lo;
      }
      v5 -= v6;
    }
    while ( v5 > v4 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A240
// Name: _qsort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl qsort(char *base, unsigned int num, unsigned int width, int (__cdecl *comp)(const void *, const void *))
{
  char *v4; // edi
  unsigned int v5; // ebx
  char *v6; // esi
  unsigned int v7; // eax
  char *v8; // ebx
  unsigned int v9; // edx
  char *v10; // eax
  int v11; // ecx
  unsigned int v12; // ecx
  char *v13; // eax
  int v14; // edi
  unsigned int v15; // ecx
  char *v16; // eax
  int v17; // edi
  unsigned int v18; // edx
  char *v19; // eax
  int v20; // ecx
  char *v21; // eax
  char *v22; // edx
  int v23; // ecx
  int v24; // ecx
  int v25; // eax
  char *v26; // edx
  char *v27; // eax
  char *histk[30]; // [esp+8h] [ebp-100h]
  char *lostk[30]; // [esp+80h] [ebp-88h]
  unsigned int v30; // [esp+F8h] [ebp-10h]
  int stkptr; // [esp+FCh] [ebp-Ch]
  char *hi; // [esp+100h] [ebp-8h]
  char *lo; // [esp+104h] [ebp-4h]
  char base_3; // [esp+113h] [ebp+Bh]
  char base_3a; // [esp+113h] [ebp+Bh]
  char base_3b; // [esp+113h] [ebp+Bh]
  char base_3c; // [esp+113h] [ebp+Bh]

  v4 = base;
  if ( base == nullptr && num != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  v5 = width;
  if ( width == 0 || comp == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return;
  }
  if ( num >= 2 )
  {
    v6 = &base[width * (num - 1)];
    stkptr = 0;
    lo = base;
    hi = v6;
    while ( 1 )
    {
      v7 = (v6 - v4) / v5 + 1;
      if ( v7 <= 8 )
      {
        shortsort(hi: v6, lo: v4, width: v5, comp);
        goto LABEL_57;
      }
      v8 = &v4[(v7 >> 1) * v5];
      if ( comp(a1: v4, a2: v8) > 0 )
      {
        v9 = width;
        v10 = v8;
        if ( v4 != v8 )
        {
          v11 = v4 - v8;
          do
          {
            v30 = v9 - 1;
            base_3 = v10[v11];
            v10[v11] = *v10;
            *v10 = base_3;
            v9 = v30;
            ++v10;
          }
          while ( v30 != 0 );
        }
      }
      if ( comp(a1: v4, a2: v6) > 0 )
      {
        v12 = width;
        v13 = v6;
        if ( v4 != v6 )
        {
          v14 = v4 - v6;
          do
          {
            base_3a = v13[v14];
            v13[v14] = *v13;
            *v13++ = base_3a;
            --v12;
          }
          while ( v12 != 0 );
          v4 = lo;
        }
      }
      if ( comp(a1: v8, a2: v6) > 0 )
      {
        v15 = width;
        v16 = v6;
        if ( v8 != v6 )
        {
          v17 = v8 - v6;
          do
          {
            base_3b = v16[v17];
            v16[v17] = *v16;
            *v16++ = base_3b;
            --v15;
          }
          while ( v15 != 0 );
          v4 = lo;
        }
      }
      while ( 1 )
      {
        if ( v8 > v4 )
        {
          while ( 1 )
          {
            v4 += width;
            if ( v4 >= v8 )
              break;
            if ( comp(a1: v4, a2: v8) > 0 )
            {
              if ( v8 > v4 )
                goto LABEL_32;
              goto LABEL_30;
            }
          }
        }
        do
LABEL_30:
          v4 += width;
        while ( v4 <= hi && comp(a1: v4, a2: v8) <= 0 );
        do
LABEL_32:
          v6 -= width;
        while ( v6 > v8 && comp(a1: v6, a2: v8) > 0 );
        if ( v4 > v6 )
          break;
        v18 = width;
        v19 = v6;
        if ( v4 != v6 )
        {
          v20 = v4 - v6;
          do
          {
            v30 = v18 - 1;
            base_3c = v19[v20];
            v19[v20] = *v19;
            *v19 = base_3c;
            v18 = v30;
            ++v19;
          }
          while ( v30 != 0 );
        }
        if ( v8 == v6 )
          v8 = v4;
      }
      v6 += width;
      if ( v8 >= v6 )
        goto LABEL_44;
      do
      {
        v6 -= width;
        if ( v6 <= v8 )
          goto LABEL_44;
      }
      while ( comp(a1: v6, a2: v8) == 0 );
      if ( v8 < v6 )
      {
LABEL_46:
        v21 = lo;
      }
      else
      {
LABEL_44:
        while ( 1 )
        {
          v6 -= width;
          v21 = lo;
          if ( v6 <= lo )
            break;
          if ( comp(a1: v6, a2: v8) != 0 )
            goto LABEL_46;
        }
      }
      v22 = hi;
      if ( v6 - v21 < hi - v4 )
      {
        if ( v4 < hi )
        {
          v24 = stkptr;
          lostk[stkptr] = v4;
          histk[v24] = v22;
          stkptr = v24 + 1;
        }
        if ( v21 >= v6 )
          goto LABEL_56;
        v4 = lo;
        v5 = width;
        hi = v6;
      }
      else
      {
        if ( v21 < v6 )
        {
          v23 = stkptr;
          lostk[stkptr] = v21;
          histk[v23] = v6;
          stkptr = v23 + 1;
        }
        if ( v4 >= v22 )
        {
LABEL_56:
          v5 = width;
LABEL_57:
          v25 = --stkptr;
          if ( stkptr < 0 )
            return;
          v26 = lostk[v25];
          v27 = histk[v25];
          lo = v26;
          hi = v27;
          v6 = v27;
          v4 = v26;
        }
        else
        {
          v6 = hi;
          v5 = width;
          lo = v4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003A4CB
// Name: __fwrite_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _fwrite_nolock(unsigned __int8 *buffer, unsigned int size, unsigned int num, _iobuf *stream)
{
  unsigned int v5; // edi
  unsigned int v6; // ebx
  int cnt; // eax
  unsigned int v8; // edi
  unsigned int v9; // edi
  int v10; // eax
  unsigned int v11; // eax
  unsigned int v12; // ecx
  unsigned int v13; // eax
  unsigned int bufsize; // [esp+10h] [ebp-8h]
  unsigned __int8 *data; // [esp+14h] [ebp-4h]

  if ( size == 0 || num == 0 )
    return 0;
  if ( stream == nullptr || buffer == nullptr || num > 0xFFFFFFFF / size )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  v5 = num * size;
  data = buffer;
  v6 = num * size;
  if ( (stream->_flag & 0x10C) != 0 )
    bufsize = stream->_bufsiz;
  else
    bufsize = 4096;
  if ( v5 == 0 )
    return num;
  while ( 1 )
  {
    if ( (stream->_flag & 0x108) != 0 )
    {
      cnt = stream->_cnt;
      if ( cnt != 0 )
      {
        if ( cnt < 0 )
        {
          stream->_flag |= 0x20u;
LABEL_34:
          v13 = v5;
          return (v13 - v6) / size;
        }
        v8 = v6;
        if ( v6 >= cnt )
          v8 = stream->_cnt;
        memcpy(dst: (unsigned __int8 *)stream->_ptr, src: data, count: v8);
        stream->_cnt -= v8;
        stream->_ptr += v8;
        v6 -= v8;
        data += v8;
        goto LABEL_27;
      }
    }
    if ( v6 >= bufsize )
      break;
    if ( _flsbuf(ch: (char)*data, str: stream) == -1 )
      goto LABEL_34;
    ++data;
    --v6;
    bufsize = stream->_bufsiz;
    if ( (int)bufsize <= 0 )
      bufsize = 1;
LABEL_31:
    if ( v6 == 0 )
      return num;
  }
  if ( (stream->_flag & 0x108) != 0 && _flush(str: stream) != 0 )
    goto LABEL_34;
  v9 = v6;
  if ( bufsize != 0 )
    v9 = v6 - v6 % bufsize;
  v10 = _fileno(stream);
  v11 = _write(fh: v10, buf: data, cnt: v9);
  if ( v11 != -1 )
  {
    v12 = v9;
    if ( v11 <= v9 )
      v12 = v11;
    data += v12;
    v6 -= v12;
    if ( v11 >= v9 )
    {
LABEL_27:
      v5 = num * size;
      goto LABEL_31;
    }
  }
  stream->_flag |= 0x20u;
  v13 = num * size;
  return (v13 - v6) / size;
}

//------------------------------------------------------------------------------
// Address: 0x1003A622
// Name: _fwrite
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl fwrite(unsigned __int8 *buffer, unsigned int size, unsigned int count, _iobuf *stream)
{
  unsigned int retval; // [esp+10h] [ebp-1Ch]

  if ( size == 0 || count == 0 )
    return 0;
  if ( stream == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 0;
  }
  _lock_file(pf: stream);
  retval = _fwrite_nolock(buffer, size, num: count, stream);
  _unlock_file(pf: stream);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003A69C
// Name: strtoxq
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl strtoxq(
        localeinfo_struct *plocinfo,
        const char *nptr,
        const char **endptr,
        int ibase,
        int flags)
{
  char v6; // cl
  threadlocaleinfostruct *locinfo; // esi
  const char *i; // edi
  int v9; // eax
  char v10; // al
  const unsigned __int16 *pctype; // ebx
  unsigned int v12; // esi
  int v13; // eax
  char v14; // al
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-3Ch] BYREF
  int v16; // [esp+18h] [ebp-28h]
  unsigned __int64 v17; // [esp+1Ch] [ebp-24h]
  unsigned __int64 maxval; // [esp+24h] [ebp-1Ch]
  unsigned __int64 number; // [esp+2Ch] [ebp-14h]
  const char *p; // [esp+38h] [ebp-8h]
  char c; // [esp+3Fh] [ebp-1h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr || ibase != 0 && (ibase < 2 || ibase > 36) )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  v6 = *nptr;
  locinfo = _loc_update.localeinfo.locinfo;
  number = 0;
  c = v6;
  for ( i = nptr + 1; ; ++i )
  {
    if ( locinfo->mb_cur_max <= 1 )
    {
      v9 = locinfo->pctype[(unsigned __int8)c] & 8;
    }
    else
    {
      v9 = _isctype_l((unsigned __int8)c, mask: 8, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v9 == 0 )
      break;
    c = *i;
  }
  p = i;
  if ( c == 45 )
  {
    flags |= 2u;
  }
  else if ( c != 43 )
  {
    goto LABEL_20;
  }
  v10 = *i++;
  p = i;
  c = v10;
LABEL_20:
  if ( ibase == 0 )
  {
    if ( c != 48 )
    {
      ibase = 10;
      goto LABEL_32;
    }
    if ( *i != 120 && *i != 88 )
    {
      ibase = 8;
      goto LABEL_32;
    }
    ibase = 16;
  }
  if ( ibase == 16 && c == 48 && (*i == 120 || *i == 88) )
  {
    c = i[1];
    p = i + 2;
  }
LABEL_32:
  v16 = ibase >> 31;
  pctype = locinfo->pctype;
  v17 = 0xFFFFFFFFFFFFFFFFuLL % ibase;
  maxval = 0xFFFFFFFFFFFFFFFFuLL / ibase;
  while ( 1 )
  {
    if ( (pctype[(unsigned __int8)c] & 4) != 0 )
    {
      v12 = c - 48;
    }
    else
    {
      if ( (pctype[(unsigned __int8)c] & 0x103) == 0 )
        break;
      v13 = c;
      if ( (unsigned __int8)(c - 97) <= 0x19u )
        v13 = c - 32;
      v12 = v13 - 55;
    }
    if ( v12 >= ibase )
      break;
    flags |= 8u;
    if ( number < maxval || number == maxval && v12 <= v17 )
    {
      number = v12 + __PAIR64__(v16, ibase) * number;
    }
    else
    {
      flags |= 4u;
      if ( endptr == nullptr )
        break;
    }
    v14 = *p++;
    c = v14;
  }
  --p;
  if ( (flags & 8) != 0 )
  {
    if ( (flags & 4) != 0
      || (flags & 1) == 0
      && ((flags & 2) != 0 && number > 0x8000000000000000uLL
       || (flags & 2) == 0 && (number & 0x8000000000000000uLL) != 0LL) )
    {
      *_errno() = 34;
      if ( (flags & 1) != 0 )
      {
        number = -1;
      }
      else if ( (flags & 2) != 0 )
      {
        number = 0x8000000000000000uLL;
      }
      else
      {
        number = 0x7FFFFFFFFFFFFFFFLL;
      }
    }
  }
  else
  {
    if ( endptr != nullptr )
      p = nptr;
    number = 0;
  }
  if ( endptr != nullptr )
    *endptr = p;
  if ( (flags & 2) != 0 )
    number = -(__int64)number;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return number;
}

//------------------------------------------------------------------------------
// Address: 0x1003A939
// Name: __strtoui64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __cdecl _strtoui64(const char *nptr, char **endptr, int ibase)
{
  if ( __locale_changed != 0 )
    return strtoxq(plocinfo: nullptr, nptr, (const char **)endptr, ibase, flags: 1);
  else
    return strtoxq(plocinfo: &__initiallocalestructinfo, nptr, (const char **)endptr, ibase, flags: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003A965
// Name: __getenv_helper_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const char *__cdecl _getenv_helper_nolock(char *option)
{
  unsigned __int8 **v1; // esi
  unsigned int v3; // eax
  unsigned int v4; // edi
  unsigned int v5; // eax

  v1 = (unsigned __int8 **)_environ;
  if ( __env_initialized == 0 )
    return nullptr;
  if ( _environ != nullptr
    || _wenviron != nullptr && __wtomb_environ() == 0 && (v1 = (unsigned __int8 **)_environ, _environ != nullptr) )
  {
    if ( option != nullptr )
    {
      strlen(buf: (unsigned __int8 *)option);
      v4 = v3;
      while ( *v1 != nullptr )
      {
        strlen(buf: *v1);
        if ( v5 > v4 && (*v1)[v4] == 61 && _mbsnbicoll(s1: *v1, s2: (const unsigned __int8 *)option, n: v4) == 0 )
          return (const char *)&(*v1)[v4 + 1];
        ++v1;
      }
    }
  }
  return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1003A9EC
// Name: _getenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl getenv(char *option)
{
  char *retval; // [esp+14h] [ebp-1Ch]

  if ( option != nullptr && strnlen(str: option, maxsize: 0x7FFFu) < 0x7FFF )
  {
    _lock(locknum: 7);
    retval = (char *)_getenv_helper_nolock(option);
    _unlock(locknum: 7);
    return retval;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003AA66
// Name: __dupenv_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _dupenv_s(char **pBuffer, unsigned int *pBufferSizeInTChars, char *varname)
{
  int v3; // esi
  unsigned __int8 *v4; // eax
  const char *v5; // ebx
  int v6; // eax
  unsigned int v7; // esi
  char *v8; // eax
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  v3 = 0;
  if ( pBuffer != nullptr )
  {
    *pBuffer = nullptr;
    if ( pBufferSizeInTChars != nullptr )
      *pBufferSizeInTChars = 0;
    if ( varname != nullptr )
    {
      v4 = (unsigned __int8 *)_getenv_helper_nolock(option: varname);
      v5 = (const char *)v4;
      if ( v4 == nullptr )
        goto LABEL_3;
      strlen(buf: v4);
      v7 = v6 + 1;
      v8 = (char *)calloc(count: v6 + 1, size: 1u);
      *pBuffer = v8;
      if ( v8 != nullptr )
      {
        if ( strcpy_s(_Dst: v8, _SizeInBytes: v7, _Src: v5) != 0 )
          _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
        if ( pBufferSizeInTChars != nullptr )
          *pBufferSizeInTChars = v7;
        retval = 0;
      }
      else
      {
        *_errno() = 12;
        retval = *_errno();
      }
LABEL_14:
      _unlock(locknum: 7);
      return retval;
    }
  }
  v3 = 22;
  *_errno() = 22;
  _invalid_parameter_noinfo();
LABEL_3:
  retval = v3;
  goto LABEL_14;
}

//------------------------------------------------------------------------------
// Address: 0x1003AB3D
// Name: _remove
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl remove(const char *path)
{
  DWORD LastError; // eax

  if ( DeleteFileA(lpFileName: path) )
    LastError = 0;
  else
    LastError = GetLastError();
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AB6D
// Name: _unlink
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unlink(const char *path)
{
  return remove(path);
}

//------------------------------------------------------------------------------
// Address: 0x1003AB78
// Name: __chdir
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _chdir(const char *path)
{
  char *v1; // esi
  signed int CurrentDirectoryA; // eax
  DWORD v4; // edi
  char *v5; // eax
  char v6; // al
  DWORD LastError; // eax
  int memfree; // [esp+4h] [ebp-118h]
  int retval; // [esp+8h] [ebp-114h]
  char env_var[4]; // [esp+Ch] [ebp-110h] BYREF
  char abspath[264]; // [esp+10h] [ebp-10Ch] BYREF

  memfree = 0;
  retval = -1;
  v1 = abspath;
  if ( path == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( !SetCurrentDirectoryA(lpPathName: path) )
    goto LABEL_14;
  CurrentDirectoryA = GetCurrentDirectoryA(nBufferLength: 0x105u, lpBuffer: abspath);
  v4 = CurrentDirectoryA;
  if ( CurrentDirectoryA > 260 )
  {
    v5 = (char *)calloc(count: CurrentDirectoryA + 1, size: 1u);
    v1 = v5;
    if ( v5 == nullptr || (memfree = 1, v4 == 0) )
    {
LABEL_14:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      goto LABEL_15;
    }
    v4 = GetCurrentDirectoryA(nBufferLength: v4 + 1, lpBuffer: v5);
  }
  if ( v4 == 0 )
    goto LABEL_14;
  if ( (v6 = *v1, *v1 != 92) && v6 != 47 || v6 != v1[1] )
  {
    env_var[0] = 61;
    env_var[1] = _mbctoupper(c: (unsigned __int8)*v1);
    strcpy(&env_var[2], ":");
    if ( !SetEnvironmentVariableA(lpName: env_var, lpValue: v1) )
      goto LABEL_14;
  }
  retval = 0;
LABEL_15:
  if ( memfree != 0 )
    free(pMem: v1);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003ACB0
// Name: __ftol2_sse
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse@<eax>(double a1@<st0>)
{
  if ( __sse2_available != 0 )
    return _ftol2_pentium4();
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1003ACB9
// Name: __ftol2_pentium4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_pentium4@<eax>(double a1@<st0>)
{
  return (int)a1;
}

//------------------------------------------------------------------------------
// Address: 0x1003ACCC
// Name: __ftol2_sse_excpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall _ftol2_sse_excpt@<eax>(double a1@<st0>)
{
  char v2; // [esp+0h] [ebp-4h]

  if ( __sse2_available != 0 && (v2 & 0x7F) == 0x7F )
    return _ftol2_pentium4(a1);
  else
    return _ftol2(a1);
}

//------------------------------------------------------------------------------
// Address: 0x1003ACE6
// Name: __ftol2
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __usercall _ftol2@<eax>(double a1@<st0>)
{
  int v1; // edx
  unsigned int result; // eax
  float v3; // [esp+0h] [ebp-20h]
  int v4; // [esp+18h] [ebp-8h]

  *(float *)&v4 = a1;
  v1 = v4;
  result = (__int64)a1;
  if ( result != 0 || ((v1 = (unsigned __int64)(__int64)a1 >> 32) & 0x7FFFFFFF) != 0 )
  {
    if ( v1 >= 0 )
    {
      v3 = a1 - (double)(__int64)a1;
      result -= __CFADD__(LODWORD(v3), 0x7FFFFFFF);
    }
    else
    {
      return (__PAIR64__(result, -(float)(a1 - (double)(__int64)a1)) + 0x7FFFFFFF) >> 32;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003AD5B
// Name: _feof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl feof(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_flag & 0x10;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003AD83
// Name: _CRT_INIT(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _CRT_INIT(void *hDllHandle, unsigned int dwReason, void *lpreserved)
{
  CFileSystemPassThru *v4; // ecx
  CFileSystemPassThru *v5; // ecx
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  unsigned int v9; // [esp-8h] [ebp-30h]
  _tiddata *v10; // [esp-4h] [ebp-2Ch]

  if ( dwReason == 1 )
  {
    if ( _heap_init() == 0 )
      return 0;
    if ( _mtinit() == 0 )
    {
LABEL_5:
      _heap_term(this: v4);
      return 0;
    }
    _RTC_Initialize();
    _acmdln = GetCommandLineA();
    _aenvptr = (char *)__crtGetEnvironmentStringsA();
    if ( _ioinit() < 0 )
    {
LABEL_7:
      _mtterm();
      goto LABEL_5;
    }
    if ( _setargv() < 0 || _setenvp() < 0 || _cinit(initFloatingPrecision: 0) != 0 )
    {
      _ioterm();
      goto LABEL_7;
    }
    ++*(_DWORD *)&_proc_attached;
  }
  else if ( dwReason != 0 )
  {
    if ( dwReason == 2 )
    {
      __set_flsgetvalue();
      v6 = (_tiddata *)calloc(count: 1u, size: 0x214u);
      v7 = v6;
      if ( v6 == nullptr )
        return 0;
      v10 = v6;
      v9 = __flsindex;
      v8 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v8(a1: v9, a2: v10) == 0 )
      {
        free(pMem: v7);
        return 0;
      }
      _initptd(ptd: v7, ptloci: nullptr);
      v7->_tid = GetCurrentThreadId();
      v7->_thandle = -1;
    }
    else if ( dwReason == 3 )
    {
      _freeptd(ptd: nullptr);
    }
  }
  else
  {
    if ( *(int *)&_proc_attached <= 0 )
      return 0;
    --*(_DWORD *)&_proc_attached;
    if ( _C_Termination_Done == 0 )
      _cexit();
    if ( lpreserved == nullptr )
    {
      _ioterm();
      _mtterm();
      _heap_term(this: v5);
      if ( __flsindex != -1 )
        _mtterm();
    }
  }
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003AEE7
// Name: __DllMainCRTStartup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _DllMainCRTStartup(void *lpreserved, unsigned int dwReason, HINSTANCE hDllHandle)
{
  BOOL v5; // eax
  int retcode; // [esp+10h] [ebp-1Ch]

  if ( dwReason == 0 && *(_DWORD *)&_proc_attached == 0
    || (dwReason == 1 || dwReason == 2) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
  {
    return 0;
  }
  v5 = DllMain(hinstDLL: hDllHandle, fdwReason: dwReason, lpvReserved: lpreserved);
  retcode = v5;
  if ( dwReason == 1 && !v5 )
  {
    DllMain(hinstDLL: hDllHandle, fdwReason: 0, lpvReserved: lpreserved);
    _CRT_INIT(hDllHandle, dwReason: 0, lpreserved);
  }
  if ( (dwReason == 0 || dwReason == 3) && _CRT_INIT(hDllHandle, dwReason, lpreserved) == 0 )
    return 0;
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x1003AFDD
// Name: _DllMainCRTStartup(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __stdcall _DllMainCRTStartup(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
  if ( fdwReason == 1 )
    __security_init_cookie();
  return _DllMainCRTStartup(lpreserved: lpReserved, dwReason: fdwReason, hDllHandle: hinstDLL);
}

//------------------------------------------------------------------------------
// Address: 0x1003B000
// Name: __aullshr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int64 __usercall _aullshr@<edx:eax>(unsigned __int64 a1@<edx:eax>, unsigned __int8 a2@<cl>)
{
  if ( a2 >= 0x40u )
    return 0;
  else
    return a1 >> a2;
}

//------------------------------------------------------------------------------
// Address: 0x1003B01F
// Name: __strtod_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl _strtod_l(char *nptr, char **endptr, localeinfo_struct *plocinfo)
{
  const char *v3; // esi
  int v5; // eax
  _flt *v6; // eax
  _flt *v7; // ecx
  int flags; // eax
  long double v9; // st7
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-34h] BYREF
  long double tmp; // [esp+1Ch] [ebp-24h]
  _flt answerstruct; // [esp+24h] [ebp-1Ch] BYREF

  v3 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( endptr != nullptr )
    *endptr = nptr;
  if ( nptr == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  while ( 1 )
  {
    v5 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
       ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v3] & 8
       : _isctype_l(c: *(unsigned __int8 *)v3, mask: 8, plocinfo: &_loc_update.localeinfo);
    if ( v5 == 0 )
      break;
    ++v3;
  }
  v6 = _fltin2(flt: &answerstruct, str: v3, _Locale: &_loc_update.localeinfo);
  v7 = v6;
  if ( endptr != nullptr )
    *endptr = (char *)&v3[v6->nbytes];
  flags = v6->flags;
  if ( (v7->flags & 0x240) != 0 )
  {
    tmp = 0.0;
    if ( endptr != nullptr )
      *endptr = nptr;
    goto LABEL_24;
  }
  if ( (flags & 0x81) != 0 )
  {
    v9 = _HUGE;
    if ( *v3 == 45 )
      v9 = -_HUGE;
  }
  else if ( (flags & 0x100) == 0 || (v9 = 0.0, 0.0 != v7->dval) )
  {
    tmp = v7->dval;
    goto LABEL_24;
  }
  tmp = v9;
  *_errno() = 34;
LABEL_24:
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return tmp;
}

//------------------------------------------------------------------------------
// Address: 0x1003B142
// Name: _strtod
// Source: linker_block_proximity
//------------------------------------------------------------------------------
double __cdecl strtod(char *nptr, char **endptr)
{
  return _strtod_l(nptr, endptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003B159
// Name: __tolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _tolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+18h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+1Ch] [ebp-4h] BYREF
  int ca; // [esp+28h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x100u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 1;
    }
    else
    {
      v4 = _isctype_l(c, mask: 1, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pclmap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x1003B26E
// Name: _tolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl tolower(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _tolower_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 65 <= 0x19 )
    return c + 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B29A
// Name: __freea
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freea(_DWORD *_Memory)
{
  if ( _Memory != nullptr && *(_Memory - 2) == 56797 )
    free(pMem: _Memory - 2);
}

//------------------------------------------------------------------------------
// Address: 0x1003B2C0
// Name: _strncat
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl strncat(char *Destination, const char *Source, size_t Count)
{
  size_t v3; // ecx
  char *v4; // edi
  char v5; // al
  int v6; // eax
  int v7; // eax
  char *v8; // edi
  const char *v9; // esi
  char v10; // bl
  size_t v11; // ecx
  int v12; // edx
  char v13; // dl
  int v15; // eax

  v3 = Count;
  if ( Count == 0 )
    return Destination;
  v4 = Destination;
  if ( ((unsigned __int8)Destination & 3) == 0 )
    goto find_end_of_front_string_loop;
  do
  {
    v5 = *v4++;
    if ( v5 == 0 )
    {
start_byte_3:
      v8 = v4 - 1;
      goto copy_start;
    }
  }
  while ( ((unsigned __int8)v4 & 3) != 0 );
  while ( 1 )
  {
    do
    {
find_end_of_front_string_loop:
      v6 = (*(_DWORD *)v4 + 2130640639) ^ ~*(_DWORD *)v4;
      v4 += 4;
    }
    while ( (v6 & 0x81010100) == 0 );
    v7 = *((_DWORD *)v4 - 1);
    if ( (_BYTE)v7 == 0 )
      break;
    if ( BYTE1(v7) == 0 )
    {
      v8 = v4 - 3;
      goto copy_start;
    }
    if ( (v7 & 0xFF0000) == 0 )
    {
      v8 = v4 - 2;
      goto copy_start;
    }
    if ( (v7 & 0xFF000000) == 0 )
      goto start_byte_3;
  }
  v8 = v4 - 4;
copy_start:
  v9 = Source;
  if ( ((unsigned __int8)Source & 3) == 0 )
  {
    v10 = Count;
    v11 = Count >> 2;
    if ( Count >> 2 != 0 )
      goto main_loop_entrance;
tail_loop_start:
    v3 = v10 & 3;
    if ( (v10 & 3) != 0 )
    {
      while ( 1 )
      {
        v13 = *v9++;
        *v8++ = v13;
        if ( v13 == 0 )
          break;
        if ( --v3 == 0 )
          goto empty_counter;
      }
    }
    else
    {
empty_counter:
      *v8 = v3;
    }
    return Destination;
  }
  do
  {
    LOBYTE(v12) = *v9++;
    if ( (_BYTE)v12 == 0 )
    {
LABEL_26:
      *v8 = v12;
      return Destination;
    }
    *v8++ = v12;
    if ( --v3 == 0 )
      goto empty_counter;
  }
  while ( ((unsigned __int8)v9 & 3) != 0 );
  v10 = v3;
  v11 = v3 >> 2;
  if ( v11 == 0 )
    goto tail_loop_start;
  while ( 1 )
  {
main_loop_entrance:
    v15 = (*(_DWORD *)v9 + 2130640639) ^ ~*(_DWORD *)v9;
    v12 = *(_DWORD *)v9;
    v9 += 4;
    if ( (v15 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v12 == 0 )
        goto LABEL_26;
      if ( BYTE1(v12) == 0 )
        break;
      if ( (v12 & 0xFF0000) == 0 )
      {
        *(_WORD *)v8 = v12;
        v8[2] = 0;
        return Destination;
      }
      if ( (v12 & 0xFF000000) == 0 )
      {
        *(_DWORD *)v8 = v12;
        return Destination;
      }
    }
    *(_DWORD *)v8 = v12;
    v8 += 4;
    if ( --v11 == 0 )
      goto tail_loop_start;
  }
  *(_WORD *)v8 = (unsigned __int8)v12;
  return Destination;
}

//------------------------------------------------------------------------------
// Address: 0x1003B3F5
// Name: __isleadbyte_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isleadbyte_l(unsigned __int8 c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+0h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  result = _loc_update.localeinfo.locinfo->pctype[c] & 0x8000;
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B42D
// Name: _isleadbyte
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl isleadbyte(unsigned __int8 c)
{
  return _isleadbyte_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003B440
// Name: _strncpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strncpy(unsigned __int8 *dest, unsigned __int8 *source, unsigned int count)
{
  unsigned int v3; // ecx
  unsigned int v4; // ebx
  unsigned __int8 *v5; // esi
  unsigned int v7; // ecx
  unsigned __int8 v8; // al
  unsigned int v9; // ecx
  int v10; // eax
  int v11; // edx

  v3 = count;
  if ( count == 0 )
    return;
  v4 = count;
  v5 = source;
  if ( ((unsigned __int8)source & 3) == 0 )
  {
    v7 = count >> 2;
    if ( count >> 2 != 0 )
      goto main_loop_entrance_0;
copy_tail_loop:
    while ( 1 )
    {
      v8 = *v5++;
      *dest++ = v8;
      if ( v8 == 0 )
        break;
      if ( --v4 == 0 )
        return;
    }
    while ( --v4 != 0 )
finish_loop:
      *dest++ = v8;
    return;
  }
  do
  {
    v8 = *v5++;
    *dest++ = v8;
    if ( --v3 == 0 )
      return;
    if ( v8 == 0 )
    {
      while ( ((unsigned __int8)dest & 3) != 0 )
      {
        *dest++ = 0;
        if ( --v3 == 0 )
          return;
      }
      v4 = v3;
      v9 = v3 >> 2;
      if ( v9 == 0 )
        goto finish_loop;
      goto fill_dwords_with_EOS;
    }
  }
  while ( ((unsigned __int8)v5 & 3) != 0 );
  LOBYTE(v4) = v3;
  v7 = v3 >> 2;
  if ( v7 == 0 )
  {
tail_loop_start_0:
    v4 &= 3u;
    if ( v4 != 0 )
      goto copy_tail_loop;
    return;
  }
  while ( 1 )
  {
main_loop_entrance_0:
    v10 = (*(_DWORD *)v5 + 2130640639) ^ ~*(_DWORD *)v5;
    v11 = *(_DWORD *)v5;
    v5 += 4;
    if ( (v10 & 0x81010100) != 0 )
    {
      if ( (_BYTE)v11 == 0 )
        break;
      if ( BYTE1(v11) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int8)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF0000) == 0 )
      {
        *(_DWORD *)dest = (unsigned __int16)v11;
        goto fill_with_EOS_dwords;
      }
      if ( (v11 & 0xFF000000) == 0 )
      {
        *(_DWORD *)dest = v11;
        goto fill_with_EOS_dwords;
      }
    }
    *(_DWORD *)dest = v11;
    dest += 4;
    if ( --v7 == 0 )
      goto tail_loop_start_0;
  }
  *(_DWORD *)dest = 0;
fill_with_EOS_dwords:
  dest += 4;
  v8 = 0;
  v9 = v7 - 1;
  if ( v9 != 0 )
  {
fill_dwords_with_EOS:
    v8 = 0;
    do
    {
      *(_DWORD *)dest = 0;
      dest += 4;
      --v9;
    }
    while ( v9 != 0 );
  }
  v4 &= 3u;
  if ( v4 != 0 )
    goto finish_loop;
}

//------------------------------------------------------------------------------
// Address: 0x1003B570
// Name: __alldiv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __stdcall _alldiv(unsigned __int64 a1, __int64 a2)
{
  int v2; // edi
  int v3; // eax
  unsigned __int64 v4; // rtt
  __int64 v5; // rax
  unsigned __int64 v6; // rcx
  unsigned __int64 v7; // rax
  unsigned int v8; // esi
  unsigned __int64 v9; // rax

  v2 = 0;
  if ( (a1 & 0x8000000000000000uLL) != 0LL )
  {
    v2 = 1;
    HIDWORD(a1) = -HIDWORD(a1) - ((_DWORD)a1 != 0);
    LODWORD(a1) = -(int)a1;
  }
  v3 = HIDWORD(a2);
  if ( a2 < 0 )
  {
    ++v2;
    v3 = -HIDWORD(a2) - ((_DWORD)a2 != 0);
    HIDWORD(a2) = v3;
    LODWORD(a2) = -(int)a2;
  }
  if ( v3 != 0 )
  {
    v6 = __PAIR64__(v3, a2);
    v7 = a1;
    do
    {
      v6 >>= 1;
      v7 >>= 1;
    }
    while ( HIDWORD(v6) != 0 );
    v8 = v7 / (unsigned int)v6;
    v9 = v8 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v8, HIDWORD(v9)) || (HIDWORD(v9) = (a2 * (unsigned __int64)v8) >> 32, v9 > a1) )
      --v8;
    v5 = v8;
  }
  else
  {
    LODWORD(v4) = a1;
    HIDWORD(v4) = HIDWORD(a1) % (unsigned int)a2;
    LODWORD(v5) = v4 / (unsigned int)a2;
    HIDWORD(v5) = HIDWORD(a1) / (unsigned int)a2;
  }
  if ( v2 == 1 )
    return -v5;
  return v5;
}

//------------------------------------------------------------------------------
// Address: 0x1003B61A
// Name: __toupper_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _toupper_l(unsigned int c, localeinfo_struct *plocinfo)
{
  threadlocaleinfostruct *locinfo; // ecx
  int v4; // eax
  unsigned int result; // eax
  int v6; // ecx
  int v7; // eax
  bool v8; // zf
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char outbuffer[4]; // [esp+14h] [ebp-8h] BYREF
  char inbuffer[4]; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c >= 0x100 )
  {
    if ( _loc_update.localeinfo.locinfo->mb_cur_max > 1
      && (ca = (int)c >> 8, _isleadbyte_l(c: BYTE1(c), plocinfo: &_loc_update.localeinfo) != 0) )
    {
      inbuffer[0] = ca;
      inbuffer[1] = c;
      inbuffer[2] = 0;
      v6 = 2;
    }
    else
    {
      *_errno() = 42;
      inbuffer[0] = c;
      inbuffer[1] = 0;
      v6 = 1;
    }
    v7 = __crtLCMapStringA(
           plocinfo: &_loc_update.localeinfo,
           Locale: _loc_update.localeinfo.locinfo->lc_handle[2],
           dwMapFlags: 0x200u,
           lpSrcStr: inbuffer,
           cchSrc: v6,
           lpDestStr: outbuffer,
           cchDest: 3,
           code_page: _loc_update.localeinfo.locinfo->lc_codepage,
           bError: 1);
    if ( v7 != 0 )
    {
      v8 = v7 == 1;
      result = (unsigned __int8)outbuffer[0];
      if ( !v8 )
        result = (unsigned __int8)outbuffer[1] | ((unsigned __int8)outbuffer[0] << 8);
      goto LABEL_17;
    }
  }
  else
  {
    locinfo = _loc_update.localeinfo.locinfo;
    if ( _loc_update.localeinfo.locinfo->mb_cur_max <= 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->pctype[c] & 2;
    }
    else
    {
      v4 = _isctype_l(c, mask: 2, plocinfo: &_loc_update.localeinfo);
      locinfo = _loc_update.localeinfo.locinfo;
    }
    if ( v4 != 0 )
    {
      result = locinfo->pcumap[c];
LABEL_17:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x1003B730
// Name: _toupper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl toupper(unsigned int c)
{
  unsigned int result; // eax

  if ( __locale_changed != 0 )
    return _toupper_l(c, plocinfo: nullptr);
  result = c;
  if ( c - 97 <= 0x19 )
    return c - 32;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B75C
// Name: __access_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _access_s(const char *path, int amode)
{
  DWORD FileAttributesA; // eax
  DWORD LastError; // eax

  if ( path == nullptr || (amode & 0xFFFFFFF9) != 0 )
  {
    *__doserrno() = 0;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  FileAttributesA = GetFileAttributesA(lpFileName: path);
  if ( FileAttributesA == -1 )
  {
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    return *_errno();
  }
  if ( (FileAttributesA & 0x10) == 0 && (FileAttributesA & 1) != 0 && (amode & 2) != 0 )
  {
    *__doserrno() = 5;
    *_errno() = 13;
    return *_errno();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003B7DB
// Name: _access
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl access(const char *path, int amode)
{
  return -(_access_s(path, amode) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003B7F3
// Name: __atof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl _atof_l(const char *nptr, localeinfo_struct *plocinfo)
{
  const char *v2; // esi
  long double result; // st7
  int v4; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-2Ch] BYREF
  _flt fltstruct; // [esp+14h] [ebp-1Ch] BYREF

  v2 = nptr;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( nptr != nullptr )
  {
    while ( 1 )
    {
      v4 = _loc_update.localeinfo.locinfo->mb_cur_max <= 1
         ? _loc_update.localeinfo.locinfo->pctype[*(unsigned __int8 *)v2] & 8
         : _isctype_l(c: *(unsigned __int8 *)v2, mask: 8, plocinfo: &_loc_update.localeinfo);
      if ( v4 == 0 )
        break;
      ++v2;
    }
    result = _fltin2(flt: &fltstruct, str: v2, _Locale: &_loc_update.localeinfo)->dval;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0.0;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003B89E
// Name: _atof
// Source: linker_block_proximity
//------------------------------------------------------------------------------
long double __cdecl atof(const char *nptr)
{
  return _atof_l(nptr, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003B8B1
// Name: _srand
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl srand(unsigned int seed)
{
  _getptd()->_holdrand = seed;
}

//------------------------------------------------------------------------------
// Address: 0x1003B8D0
// Name: _memchr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl memchr(unsigned __int8 *buf, unsigned __int8 chr, unsigned int cnt)
{
  unsigned int v3; // eax
  unsigned __int8 *v4; // edx
  int v5; // ebx
  unsigned __int8 v6; // cl
  bool v7; // cf
  unsigned int v8; // eax
  unsigned int i; // eax
  unsigned __int8 v10; // cl
  int v11; // ecx
  unsigned int v12; // ecx
  unsigned int v13; // ecx

  v3 = cnt;
  if ( cnt != 0 )
  {
    v4 = buf;
    LOBYTE(v5) = chr;
    if ( ((unsigned __int8)buf & 3) != 0 )
    {
      while ( 1 )
      {
        v6 = *v4++;
        if ( chr == v6 )
          break;
        if ( --v3 == 0 )
          break;
        if ( ((unsigned __int8)v4 & 3) == 0 )
          goto main_loop_start_0;
      }
    }
    else
    {
main_loop_start_0:
      v7 = v3 < 4;
      v8 = v3 - 4;
      if ( v7 )
      {
tail_less_then_4:
        for ( i = v8 + 4; i != 0; --i )
        {
          v10 = *v4++;
          if ( (unsigned __int8)v5 == v10 )
            break;
        }
      }
      else
      {
        v5 = 16843009 * chr;
        while ( 1 )
        {
          v11 = v5 ^ *(_DWORD *)v4;
          v4 += 4;
          if ( (((v11 + 2130640639) ^ ~v11) & 0x81010100) != 0 )
          {
            v12 = *((_DWORD *)v4 - 1);
            LOBYTE(v12) = chr ^ v12;
            if ( (_BYTE)v12 == 0 )
              break;
            BYTE1(v12) ^= chr;
            if ( BYTE1(v12) == 0 )
              break;
            v13 = HIWORD(v12);
            if ( chr == (unsigned __int8)v13 || chr == BYTE1(v13) )
              break;
          }
          v7 = v8 < 4;
          v8 -= 4;
          if ( v7 )
            goto tail_less_then_4;
        }
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003B97D
// Name: _putenv_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl putenv_helper(char *name, const char *value)
{
  const CHAR *v3; // edi
  const unsigned __int8 *v4; // eax
  int v5; // eax
  unsigned int v6; // esi
  char *v7; // eax
  unsigned int v8; // edi
  unsigned int v9; // eax
  unsigned int v10; // esi
  char *v11; // eax
  int v12; // edi
  int v13; // eax
  unsigned __int16 *v14; // eax
  unsigned int v15; // eax
  char *newoption; // [esp+4h] [ebp-8h] BYREF
  unsigned __int16 *woption; // [esp+8h] [ebp-4h] BYREF

  newoption = nullptr;
  if ( __env_initialized == 0 )
    return -1;
  v3 = name;
  if ( name == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( value != nullptr )
  {
    v8 = strnlen(str: name, maxsize: 0x7FFFu);
    v9 = strnlen(str: value, maxsize: 0x7FFFu);
    if ( v8 < 0x7FFF && v9 < 0x7FFF )
    {
      v10 = v9 + v8 + 2;
      v11 = (char *)calloc(count: v10, size: 1u);
      newoption = v11;
      if ( v11 != nullptr )
      {
        strcpy_s(_Dst: v11, _SizeInBytes: v10, _Src: name);
        newoption[v8] = 61;
        strcpy_s(_Dst: &newoption[v8 + 1], _SizeInBytes: v10 - (v8 + 1), _Src: value);
        v3 = name;
        goto LABEL_16;
      }
      return -1;
    }
LABEL_13:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  v4 = _mbschr(string: (const unsigned __int8 *)name, c: 0x3Du);
  if ( v4 != nullptr
    && (v4 - (const unsigned __int8 *)name >= 0x7FFF || strnlen(str: (const char *)v4 + 1, maxsize: 0x7FFFu) >= 0x7FFF) )
  {
    goto LABEL_13;
  }
  strlen(buf: (unsigned __int8 *)name);
  v6 = v5 + 1;
  v7 = (char *)calloc(count: v5 + 1, size: 1u);
  newoption = v7;
  if ( v7 == nullptr )
    return -1;
  strcpy_s(_Dst: v7, _SizeInBytes: v6, _Src: name);
LABEL_16:
  if ( __crtsetenv(poption: &newoption, primary: 1) != 0 )
  {
    if ( newoption != nullptr )
      free(pMem: newoption);
    return -1;
  }
  if ( _wenviron == nullptr )
    return 0;
  woption = nullptr;
  v12 = MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: v3,
          cbMultiByte: -1,
          lpWideCharStr: nullptr,
          cchWideChar: 0);
  if ( v12 == 0 )
    goto LABEL_29;
  if ( value != nullptr )
  {
    v13 = MultiByteToWideChar(
            CodePage: 0,
            dwFlags: 0,
            lpMultiByteStr: value,
            cbMultiByte: -1,
            lpWideCharStr: nullptr,
            cchWideChar: 0);
    if ( v13 == 0 )
    {
LABEL_29:
      *_errno() = 42;
      return -1;
    }
    v12 += v13 + 1;
  }
  v14 = (unsigned __int16 *)calloc(count: v12, size: 2u);
  woption = v14;
  if ( v14 == nullptr )
    return -1;
  if ( MultiByteToWideChar(
         CodePage: 0,
         dwFlags: 0,
         lpMultiByteStr: name,
         cbMultiByte: -1,
         lpWideCharStr: v14,
         cchWideChar: v12) == 0
    || value != nullptr
    && (v15 = wcslen(wcs: woption),
        woption[v15] = 61,
        MultiByteToWideChar(
          CodePage: 0,
          dwFlags: 0,
          lpMultiByteStr: value,
          cbMultiByte: -1,
          lpWideCharStr: &woption[v15 + 1],
          cchWideChar: v12 - (v15 + 1)) == 0) )
  {
    free(pMem: woption);
    goto LABEL_29;
  }
  if ( __crtwsetenv(poption: &woption, primary: 0) != 0 )
  {
    if ( woption != nullptr )
      free(pMem: woption);
    return -1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003BB7A
// Name: __putenv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _putenv(char *option)
{
  int retval; // [esp+10h] [ebp-1Ch]

  _lock(locknum: 7);
  retval = putenv_helper(name: option, value: nullptr);
  _unlock(locknum: 7);
  return retval;
}

//------------------------------------------------------------------------------
// Address: 0x1003BBBF
// Name: __spawnv
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _spawnv(int modeflag, const char *pathname, const char *const *argv)
{
  if ( pathname != nullptr && *pathname != 0 && argv != nullptr && *argv != nullptr && **(_BYTE **)argv != 0 )
    return _spawnve(mode: modeflag, name: pathname, argv, envp: nullptr);
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003BC09
// Name: __localtime64_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _localtime64_s(tm *ptm, const __int64 *ptime)
{
  int result; // eax
  int v3; // eax
  unsigned int v4; // ecx
  int v5; // eax
  __int64 v6; // kr00_8
  __int64 v7; // kr10_8
  __int64 v8; // kr20_8
  __int64 v9; // rax
  int v10; // ecx
  int v11; // edx
  __int64 ltime; // [esp+8h] [ebp-14h] BYREF
  int dstbias; // [esp+10h] [ebp-Ch] BYREF
  int daylight; // [esp+14h] [ebp-8h] BYREF
  int timezone; // [esp+18h] [ebp-4h] BYREF

  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( ptm == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  memset(dst: (int)ptm, value: (unsigned __int8 *)0xFF, count: sizeof(tm));
  if ( ptime == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  v3 = *((_DWORD *)ptime + 1);
  v4 = *(_DWORD *)ptime;
  if ( v3 < 0 || __SPAIR64__(v3, v4) > 0x793406FFFLL )
  {
    *_errno() = 22;
    return 22;
  }
  __tzset(a1: v4);
  if ( _get_daylight(_Daylight: &daylight) != 0
    || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
    || _get_timezone(_Timezone: &timezone) != 0 )
  {
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  }
  if ( *ptime <= 259200 )
  {
    result = _gmtime64_s(ptm, timp: ptime);
    if ( result == 0 )
    {
      if ( daylight != 0 && _isindst(tb: ptm) != 0 )
      {
        v5 = dstbias + timezone;
        ptm->tm_isdst = 1;
        v6 = ptm->tm_sec - (__int64)v5;
      }
      else
      {
        v6 = ptm->tm_sec - (__int64)timezone;
      }
      ptm->tm_sec = v6 % 60;
      if ( v6 % 60 < 0 )
      {
        ptm->tm_sec = v6 % 60 + 60;
        v6 = __PAIR64__((unsigned int)__CFADD__((_DWORD)v6, -60) + HIDWORD(v6) - 1, (int)v6 - 60);
      }
      v7 = ptm->tm_min + v6 / 60;
      ptm->tm_min = v7 % 60;
      if ( v7 % 60 < 0 )
      {
        ptm->tm_min = v7 % 60 + 60;
        v7 -= 60;
      }
      v8 = ptm->tm_hour + v7 / 60;
      ptm->tm_hour = v8 % 24;
      if ( v8 % 24 < 0 )
      {
        ptm->tm_hour = v8 % 24 + 24;
        v8 -= 24;
      }
      v9 = v8 / 24;
      v10 = v8 / 24;
      if ( (((unsigned __int64)(v8 / 24) >> 32) & 0x80000000) != 0LL )
      {
        HIDWORD(v9) = ((int)v9 + ptm->tm_wday + 7) % 7;
        ptm->tm_mday += v9;
        LODWORD(v9) = ptm->tm_mday;
        ptm->tm_wday = HIDWORD(v9);
        if ( (int)v9 <= 0 )
        {
          ptm->tm_yday += v10 + 365;
          --ptm->tm_year;
          ptm->tm_mday = v9 + 31;
          ptm->tm_mon = 11;
          return 0;
        }
      }
      else
      {
        if ( v9 <= 0 )
          return 0;
        v11 = (v10 + ptm->tm_wday) % 7;
        ptm->tm_mday += v10;
        ptm->tm_wday = v11;
      }
      ptm->tm_yday += v10;
      return 0;
    }
  }
  else
  {
    ltime = *ptime - timezone;
    result = _gmtime64_s(ptm, timp: &ltime);
    if ( result == 0 )
    {
      if ( daylight == 0 || _isindst(tb: ptm) == 0 )
        return 0;
      ltime -= dstbias;
      result = _gmtime64_s(ptm, timp: &ltime);
      if ( result == 0 )
      {
        ptm->tm_isdst = 1;
        return 0;
      }
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003BE91
// Name: __localtime64
// Source: linker_block_proximity
//------------------------------------------------------------------------------
tm *__cdecl _localtime64(const __int64 *ptime)
{
  tm *result; // eax

  result = (tm *)__getgmtimebuf();
  if ( result != nullptr )
    return _localtime64_s(ptm: result, ptime) == 0 ? result : nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003BEB8
// Name: __flush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flush(_iobuf *str)
{
  int flag; // eax
  int v2; // ebx
  char *base; // eax
  char *v4; // edi
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  char *v9; // [esp-Ch] [ebp-14h]
  char *v10; // [esp-8h] [ebp-10h]

  flag = str->_flag;
  v2 = 0;
  if ( (flag & 3) == 2 && (flag & 0x108) != 0 )
  {
    base = str->_base;
    v4 = (char *)(str->_ptr - base);
    if ( (int)v4 > 0 )
    {
      v10 = (char *)(str->_ptr - base);
      v9 = str->_base;
      v5 = _fileno(stream: str);
      if ( (char *)_write(fh: v5, buf: v9, cnt: (unsigned int)v10) == v4 )
      {
        v6 = str->_flag;
        if ( (v6 & 0x80u) != 0 )
          str->_flag = v6 & 0xFFFFFFFD;
      }
      else
      {
        str->_flag |= 0x20u;
        v2 = -1;
      }
    }
  }
  v7 = str->_base;
  str->_cnt = 0;
  str->_ptr = v7;
  return v2;
}

//------------------------------------------------------------------------------
// Address: 0x1003BF20
// Name: __fflush_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fflush_nolock(_iobuf *str)
{
  int v2; // eax

  if ( str == nullptr )
    return flsall(flushflag: 0);
  if ( _flush(str) != 0 )
    return -1;
  if ( (str->_flag & 0x4000) == 0 )
    return 0;
  v2 = _fileno(stream: str);
  return -(_commit(filedes: v2) != 0);
}

//------------------------------------------------------------------------------
// Address: 0x1003BF68
// Name: flsall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl flsall(int flushflag)
{
  int i; // esi
  char **v2; // eax
  char *v3; // eax
  int v4; // ecx
  int result; // eax
  int err; // [esp+10h] [ebp-24h]
  int count; // [esp+18h] [ebp-1Ch]

  count = 0;
  err = 0;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = (char **)&__piob[i];
    if ( *v2 != nullptr )
    {
      v3 = *v2;
      if ( (v3[12] & 0x83) != 0 )
      {
        _lock_file2(i, s: v3);
        v4 = *((_DWORD *)__piob[i] + 3);
        if ( (v4 & 0x83) != 0 )
        {
          if ( flushflag == 1 )
          {
            if ( _fflush_nolock(str: (_iobuf *)__piob[i]) != -1 )
              ++count;
          }
          else if ( flushflag == 0 && (v4 & 2) != 0 && _fflush_nolock(str: (_iobuf *)__piob[i]) == -1 )
          {
            err = -1;
          }
        }
        _unlock_file2(i, s: (char *)__piob[i]);
      }
    }
  }
  _unlock(locknum: 1);
  result = count;
  if ( flushflag != 1 )
    return err;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003C042
// Name: _fflush
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl fflush(_iobuf *stream)
{
  int rc; // [esp+10h] [ebp-1Ch]

  if ( stream == nullptr )
    return flsall(flushflag: 0);
  _lock_file(pf: stream);
  rc = _fflush_nolock(str: stream);
  _unlock_file(pf: stream);
  return rc;
}

//------------------------------------------------------------------------------
// Address: 0x1003C095
// Name: __flushall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flushall()
{
  return flsall(flushflag: 1);
}

//------------------------------------------------------------------------------
// Address: 0x1003C09E
// Name: _asctime
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl asctime(const tm *tb)
{
  char *asctimebuf; // edi
  _tiddata *v2; // eax
  _tiddata *v3; // esi
  char *v4; // eax
  char *v5; // ecx
  int tm_mon; // edi
  int tm_mday; // edx
  int tm_wday; // eax
  int v10; // edx
  int i; // eax
  char v12; // dl
  char v13; // dl
  char v14; // dl
  char v15; // dl
  char v16; // dl
  int v17; // edx
  char *p; // [esp+10h] [ebp-4h]

  asctimebuf = buf_0;
  p = buf_0;
  v2 = _getptd_noexit();
  v3 = v2;
  if ( v2 != nullptr )
  {
    if ( v2->_asctimebuf != nullptr
      || (v4 = (char *)calloc(count: 0x1Au, size: 1u), v3->_asctimebuf = v4, v4 != nullptr) )
    {
      asctimebuf = v3->_asctimebuf;
      p = asctimebuf;
    }
  }
  v5 = asctimebuf;
  if ( asctimebuf != nullptr
    && (*asctimebuf = 0, tb != nullptr)
    && tb->tm_year >= 0
    && (unsigned int)(tm_mon = tb->tm_mon) < 0xC
    && tb->tm_hour < 0x18u
    && tb->tm_min < 0x3Cu
    && tb->tm_sec < 0x3Cu
    && (tm_mday = tb->tm_mday) >= 1
    && (dword_10063CD8[tm_mon] - _days[tm_mon] >= tm_mday
     || ((tb->tm_year + 1900) % 4 == 0 && (tb->tm_year + 1900) % 100 != 0 || (tb->tm_year + 1900) % 400 == 0)
     && tm_mon == 1
     && tb->tm_mday <= 29)
    && (unsigned int)(tm_wday = tb->tm_wday) <= 6 )
  {
    v10 = 3 * tm_wday;
    for ( i = 0; i < 3; ++i )
    {
      *v5 = __dnames[v10 + i];
      p[i + 4] = __mnames[3 * tm_mon + i];
      ++v5;
    }
    *v5 = 32;
    v5[4] = 32;
    v12 = tb->tm_mday % 10;
    v5[5] = tb->tm_mday / 10 + 48;
    v5[6] = v12 + 48;
    v5[7] = 32;
    v13 = tb->tm_hour % 10;
    v5[8] = tb->tm_hour / 10 + 48;
    v5[9] = v13 + 48;
    v5[10] = 58;
    v14 = tb->tm_min % 10;
    v5[11] = tb->tm_min / 10 + 48;
    v5[12] = v14 + 48;
    v5[13] = 58;
    v15 = tb->tm_sec % 10;
    v5[14] = tb->tm_sec / 10 + 48;
    v5[15] = v15 + 48;
    v5[16] = 32;
    v16 = (tb->tm_year / 100 + 19) % 10;
    v5[17] = (tb->tm_year / 100 + 19) / 10 + 48;
    v5[18] = v16 + 48;
    v17 = tb->tm_year % 100;
    v5[19] = v17 / 10 + 48;
    v5[20] = v17 % 10 + 48;
    *(_WORD *)(v5 + 21) = 10;
    return p;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C280
// Name: __aulldvrm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __stdcall _aulldvrm(unsigned __int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rtt
  unsigned int v3; // esi
  unsigned int v4; // ecx
  unsigned int v5; // ebx
  unsigned __int64 v6; // rax
  char v7; // cf
  unsigned __int64 v8; // rax

  if ( HIDWORD(a2) != 0 )
  {
    v4 = HIDWORD(a2);
    v5 = a2;
    v6 = a1;
    do
    {
      v7 = v4 & 1;
      v4 >>= 1;
      v5 = (v5 >> 1) | (v7 << 31);
      v6 >>= 1;
    }
    while ( v4 != 0 );
    v3 = v6 / v5;
    v8 = v3 * (unsigned __int64)(unsigned int)a2;
    if ( __CFADD__(HIDWORD(a2) * v3, HIDWORD(v8)) || (HIDWORD(v8) = (a2 * (unsigned __int64)v3) >> 32, v8 > a1) )
      --v3;
  }
  else
  {
    LODWORD(v2) = a1;
    HIDWORD(v2) = HIDWORD(a1) % (unsigned int)a2;
    return v2 / (unsigned int)a2;
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1003C315
// Name: __get_errno_from_oserr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _get_errno_from_oserr(unsigned int oserrno)
{
  unsigned int i; // ecx

  for ( i = 0; i < 0x2D; ++i )
  {
    if ( oserrno == errtable[i].oscode )
      return errtable[i].errnocode;
  }
  if ( oserrno - 19 > 0x11 )
    return oserrno - 188 > 0xE ? 22 : 8;
  else
    return 13;
}

//------------------------------------------------------------------------------
// Address: 0x1003C357
// Name: __errno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int *__cdecl _errno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_terrno;
  else
    return &ErrnoNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x1003C36A
// Name: ___doserrno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int *__cdecl __doserrno()
{
  _tiddata *v0; // eax

  v0 = _getptd_noexit();
  if ( v0 != nullptr )
    return &v0->_tdoserrno;
  else
    return &DoserrorNoMem;
}

//------------------------------------------------------------------------------
// Address: 0x1003C37D
// Name: __dosmaperr
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _dosmaperr(unsigned int oserrno)
{
  int errno_from_oserr; // esi

  *__doserrno() = oserrno;
  errno_from_oserr = _get_errno_from_oserr(oserrno);
  *_errno() = errno_from_oserr;
}

//------------------------------------------------------------------------------
// Address: 0x1003C3A0
// Name: __forcdecpt_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt_l(char *buffer, localeinfo_struct *_Locale)
{
  char *v2; // esi
  bool i; // zf
  char v4; // al
  char *v5; // esi
  char v6; // cl
  char v7; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buffer;
  for ( i = tolower(c: *buffer) == 101; !i; i = isdigit(c: (unsigned __int8)*v2) == 0 )
    ++v2;
  if ( tolower(c: *v2) == 120 )
    v2 += 2;
  v4 = *v2;
  *v2 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
  v5 = v2 + 1;
  do
  {
    v6 = *v5;
    *v5 = v4;
    v4 = v6;
    v7 = *v5++;
  }
  while ( v7 != 0 );
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x1003C414
// Name: __cropzeros_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros_l(char *buf, localeinfo_struct *_Locale)
{
  char *v2; // eax
  char i; // cl
  char v4; // cl
  char *v5; // eax
  char v6; // cl
  char *v7; // edx
  char v8; // cl
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: _Locale);
  v2 = buf;
  for ( i = *buf; *v2 != 0; i = *++v2 )
  {
    if ( i == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      break;
  }
  v4 = *v2;
  v5 = v2 + 1;
  if ( v4 != 0 )
  {
    while ( 1 )
    {
      v6 = *v5;
      if ( *v5 == 0 || v6 == 101 || v6 == 69 )
        break;
      ++v5;
    }
    v7 = v5;
    do
      --v5;
    while ( *v5 == 48 );
    if ( *v5 == *_loc_update.localeinfo.locinfo->lconv->decimal_point )
      --v5;
    do
    {
      v8 = *v7;
      ++v5;
      ++v7;
      *v5 = v8;
    }
    while ( v8 != 0 );
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x1003C496
// Name: __positive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _positive(long double *arg)
{
  return *arg >= 0.0;
}

//------------------------------------------------------------------------------
// Address: 0x1003C4B2
// Name: __fassign_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign_l(_CRT_FLOAT flag, char *argument, char *number, localeinfo_struct *plocinfo)
{
  _CRT_DOUBLE doubletemp; // [esp+0h] [ebp-8h] BYREF

  if ( LODWORD(flag.f) != 0 )
  {
    _atodbl_l(d: &doubletemp, str: number, plocinfo);
    *(_CRT_DOUBLE *)argument = doubletemp;
  }
  else
  {
    _atoflt_l(d: &flag, str: number, plocinfo);
    *(_CRT_FLOAT *)argument = flag;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C4F4
// Name: __fassign
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _fassign(int flag, char *argument, char *number)
{
  _fassign_l((_CRT_FLOAT)flag, argument, number, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003C50E
// Name: _shift
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall shift(char *s@<eax>, int dist@<edi>)
{
  int v3; // eax

  if ( dist != 0 )
  {
    strlen(buf: (unsigned __int8 *)s);
    memmove(dst: (unsigned __int8 *)&s[dist], src: (unsigned __int8 *)s, count: v3 + 1);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003C52D
// Name: __forcdecpt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _forcdecpt(char *buffer)
{
  _forcdecpt_l(buffer, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003C540
// Name: __cropzeros
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _cropzeros(char *buf)
{
  _cropzeros_l(buf, _Locale: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003C553
// Name: _cftoe2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftoe2_l@<eax>(
        char *buf@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        _strflt *pflt,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int *v8; // eax
  int v10; // eax
  char *v11; // esi
  threadlocaleinfostruct *locinfo; // eax
  char *v13; // esi
  unsigned int v14; // ebx
  int v15; // eax
  int v16; // [esp-4h] [ebp-1Ch]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v8 = _errno();
    v16 = 22;
LABEL_3:
    *v8 = v16;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v16;
  }
  if ( ndec <= 0 )
    v10 = 0;
  else
    v10 = ndec;
  if ( sizeInBytes <= v10 + 9 )
  {
    v8 = _errno();
    v16 = 34;
    goto LABEL_3;
  }
  if ( g_fmt != 0 )
    shift(s: &buf[pflt->sign == 45], dist: ndec > 0);
  v11 = buf;
  if ( pflt->sign == 45 )
  {
    *buf = 45;
    v11 = buf + 1;
  }
  if ( ndec > 0 )
  {
    locinfo = _loc_update.localeinfo.locinfo;
    *v11 = v11[1];
    *++v11 = *locinfo->lconv->decimal_point;
  }
  v13 = &v11[ndec + (g_fmt == 0)];
  if ( sizeInBytes == -1 )
    v14 = -1;
  else
    v14 = sizeInBytes + buf - v13;
  if ( strcpy_s(_Dst: v13, _SizeInBytes: v14, _Src: "e+000") != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  if ( caps != 0 )
    *v13 = 69;
  if ( *pflt->mantissa != 48 )
  {
    v15 = pflt->decpt - 1;
    if ( v15 < 0 )
    {
      v15 = 1 - pflt->decpt;
      v13[1] = 45;
    }
    if ( v15 >= 100 )
    {
      v13[2] += v15 / 100;
      v15 %= 100;
    }
    if ( v15 >= 10 )
    {
      v13[3] += v15 / 10;
      LOBYTE(v15) = v15 % 10;
    }
    v13[4] += v15;
  }
  if ( (_outputformat & 1) != 0 && v13[2] == 48 )
    memmove(dst: (unsigned __int8 *)v13 + 2, src: (unsigned __int8 *)v13 + 3, count: 3u);
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003C6B4
// Name: __cftoe_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // eax
  _strflt retstrflt; // [esp+Ch] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+1Ch] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - (retstrflt.sign == 45) - (ndec > 0);
    result = _fptostr(
               buf: &buf[(retstrflt.sign == 45) + (ndec > 0)],
               sizeInBytes: v7,
               digits: ndec + 1,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003C77B
// Name: __cftoe
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoe(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, int caps)
{
  return _cftoe_l(pvalue, buf, sizeInBytes, ndec, caps, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1003C79B
// Name: __cftoa_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftoa_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  char *v6; // esi
  int *v7; // eax
  int result; // eax
  unsigned int v9; // eax
  bool v10; // zf
  _BYTE *v11; // eax
  char *v12; // esi
  char *v13; // eax
  char *v14; // esi
  int x_low; // eax
  unsigned int v16; // eax
  unsigned int v17; // ecx
  char *i; // eax
  __int64 v19; // rax
  __int64 v20; // rcx
  _BYTE *v21; // esi
  _BYTE *v22; // edi
  __int64 v23; // rax
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // rcx
  __int64 v27; // rcx
  __int64 v28; // [esp-Ch] [ebp-38h]
  int v29; // [esp-4h] [ebp-30h]
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-24h] BYREF
  __int64 exponent; // [esp+18h] [ebp-14h]
  unsigned __int64 mask; // [esp+20h] [ebp-Ch]
  int maskpos; // [esp+28h] [ebp-4h]
  char *pos; // [esp+38h] [ebp+Ch]

  LODWORD(exponent) = 1023;
  maskpos = 48;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( ndec < 0 )
    ndec = 0;
  v6 = buf;
  if ( buf == nullptr || sizeInBytes == 0 )
  {
    v7 = _errno();
    v29 = 22;
LABEL_5:
    *v7 = v29;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return v29;
  }
  *buf = 0;
  if ( sizeInBytes <= ndec + 11 )
  {
    v7 = _errno();
    v29 = 34;
    goto LABEL_5;
  }
  LODWORD(mask) = LODWORD(pvalue->x);
  if ( ((HIDWORD(pvalue->x) >> 20) & 0x7FF) == 0x7FF )
  {
    v9 = sizeInBytes;
    if ( sizeInBytes != -1 )
      v9 = sizeInBytes - 2;
    result = _cftoe(pvalue, buf: buf + 2, sizeInBytes: v9, ndec, caps: 0);
    if ( result != 0 )
    {
      v10 = !_loc_update.updated;
      *buf = 0;
      if ( !v10 )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    }
    if ( buf[2] == 45 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    strrchr(string: (unsigned __int8 *)v6 + 2, chr: 0x65u);
    if ( v11 != nullptr )
    {
      *v11 = caps == 0 ? 112 : 80;
      v11[3] = 0;
    }
  }
  else
  {
    if ( (HIDWORD(pvalue->x) & 0x80000000) != 0 )
    {
      *buf = 45;
      v6 = buf + 1;
    }
    *v6 = 48;
    v6[1] = caps == 0 ? 120 : 88;
    if ( (HIDWORD(pvalue->x) & 0x7FF00000) != 0 )
    {
      v6[2] = 49;
      v12 = v6 + 3;
    }
    else
    {
      v6[2] = 48;
      v12 = v6 + 3;
      if ( (HIDWORD(pvalue->x) & 0xFFFFF | LODWORD(pvalue->x)) != 0 )
        LODWORD(exponent) = 1022;
      else
        LODWORD(exponent) = 0;
    }
    v13 = v12;
    v14 = v12 + 1;
    pos = v13;
    if ( ndec != 0 )
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
    else
      *v13 = 0;
    x_low = LODWORD(pvalue->x);
    HIDWORD(mask) = HIDWORD(pvalue->x) & 0xFFFFF;
    if ( HIDWORD(mask) != 0 || x_low != 0 )
    {
      mask = 0xF000000000000LL;
      do
      {
        if ( ndec <= 0 )
          break;
        v16 = (unsigned __int16)(((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48);
        if ( v16 > 0x39 )
          LOBYTE(v16) = (caps != 0 ? 7 : 39) + ((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) + 48;
        v17 = HIDWORD(mask);
        maskpos -= 4;
        *v14++ = v16;
        --ndec;
        mask = __PAIR64__(v17, mask) >> 4;
      }
      while ( (maskpos & 0x8000u) == 0 );
      if ( (maskpos & 0x8000u) == 0
        && (unsigned __int16)((mask & *(_QWORD *)&pvalue->x & 0xFFFFFFFFFFFFFLL) >> maskpos) > 8u )
      {
        for ( i = v14 - 1; *i == 102 || *i == 70; --i )
          *i = 48;
        if ( i == pos )
        {
          ++*(i - 1);
        }
        else if ( *i == 57 )
        {
          *i = caps != 0 ? 65 : 97;
        }
        else
        {
          ++*i;
        }
      }
    }
    if ( ndec > 0 )
    {
      memset(dst: (int)v14, value: (unsigned __int8 *)0x30, count: ndec);
      v14 += ndec;
    }
    if ( *pos == 0 )
      v14 = pos;
    *v14 = caps == 0 ? 112 : 80;
    HIDWORD(v20) = 0;
    v19 = ((*(_QWORD *)&pvalue->x >> 52) & 0x7FFLL) - (unsigned int)exponent;
    if ( v19 < 0 )
    {
      v14[1] = 45;
      v21 = v14 + 2;
      v19 = -v19;
    }
    else
    {
      v14[1] = 43;
      v21 = v14 + 2;
    }
    v22 = v21;
    *v21 = 48;
    if ( v19 >= 0 )
    {
      LODWORD(v20) = 1000;
      if ( v19 >= 1000 )
      {
        v28 = v20;
        v24 = v19 % v20;
        v23 = v19 / v28;
        *v21++ = v23 + 48;
        HIDWORD(exponent) = HIDWORD(v23);
        v19 = v24;
        if ( v21 != v22 )
          goto LABEL_60;
      }
    }
    if ( v19 >= 100 )
    {
LABEL_60:
      v26 = v19 % 100;
      v25 = v19 / 100;
      *v21 = v25 + 48;
      HIDWORD(exponent) = HIDWORD(v25);
      ++v21;
      v19 = v26;
    }
    if ( v21 != v22 || v19 >= 10 )
    {
      v27 = v19 % 10;
      *v21++ = v19 / 10 + 48;
      LOBYTE(v19) = v19 % 10;
      HIDWORD(exponent) = HIDWORD(v27);
    }
    *v21 = v19 + 48;
    v21[1] = 0;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003CB11
// Name: _cftof2_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall cftof2_l@<eax>(
        char *buf@<ecx>,
        _strflt *pflt@<eax>,
        unsigned int sizeInBytes,
        int ndec,
        char g_fmt,
        localeinfo_struct *plocinfo)
{
  int v8; // esi
  char *v10; // esi
  int decpt; // eax
  int v12; // eax
  unsigned __int8 *v13; // esi
  int v14; // eax
  int v15; // edi
  int v16; // edi
  _LocaleUpdate _loc_update; // [esp+Ch] [ebp-10h] BYREF

  v8 = pflt->decpt - 1;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    if ( g_fmt != 0 && v8 == ndec )
      *(_WORD *)&buf[v8 + (pflt->sign == 45)] = 48;
    v10 = buf;
    if ( pflt->sign == 45 )
    {
      *buf = 45;
      v10 = buf + 1;
    }
    decpt = pflt->decpt;
    if ( decpt > 0 )
    {
      v13 = (unsigned __int8 *)&v10[decpt];
    }
    else
    {
      strlen(buf: (unsigned __int8 *)v10);
      memmove(dst: (unsigned __int8 *)v10 + 1, src: (unsigned __int8 *)v10, count: v12 + 1);
      *v10 = 48;
      v13 = (unsigned __int8 *)(v10 + 1);
    }
    if ( ndec > 0 )
    {
      strlen(buf: v13);
      memmove(dst: v13 + 1, src: v13, count: v14 + 1);
      *v13 = *_loc_update.localeinfo.locinfo->lconv->decimal_point;
      v15 = pflt->decpt;
      if ( v15 < 0 )
      {
        v16 = -v15;
        if ( g_fmt != 0 || ndec >= v16 )
          ndec = v16;
        shift(s: (char *)v13 + 1, dist: ndec);
        memset(dst: (int)(v13 + 1), value: (unsigned __int8 *)0x30, count: ndec);
      }
    }
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 0;
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return 22;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CC14
// Name: __cftof_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftof_l(_CRT_DOUBLE *pvalue, char *buf, unsigned int sizeInBytes, int ndec, localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v6; // eax
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && sizeInBytes != 0 )
  {
    v6 = -1;
    if ( sizeInBytes != -1 )
      v6 = sizeInBytes - (retstrflt.sign == 45);
    result = _fptostr(
               buf: &buf[retstrflt.sign == 45],
               sizeInBytes: v6,
               digits: ndec + retstrflt.decpt,
               pflt: &retstrflt);
    if ( result != 0 )
      *buf = 0;
    else
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 0, plocinfo);
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003CCD5
// Name: __cftog_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _cftog_l(
        _CRT_DOUBLE *pvalue,
        char *buf,
        unsigned int sizeInBytes,
        int ndec,
        int caps,
        localeinfo_struct *plocinfo)
{
  int result; // eax
  unsigned int v7; // ecx
  int v8; // ebx
  BOOL v9; // eax
  char *v10; // edi
  _strflt retstrflt; // [esp+8h] [ebp-2Ch] BYREF
  char resstr[24]; // [esp+18h] [ebp-1Ch] BYREF

  _fltout2(x: *(_CRT_DOUBLE *)&pvalue->x, flt: &retstrflt, resultstr: resstr, resultsize: 0x16u);
  if ( buf != nullptr && (v7 = sizeInBytes, sizeInBytes != 0) )
  {
    v8 = retstrflt.decpt - 1;
    v9 = retstrflt.sign == 45;
    v10 = &buf[v9];
    if ( sizeInBytes != -1 )
      v7 = sizeInBytes - v9;
    result = _fptostr(buf: v10, sizeInBytes: v7, digits: ndec, pflt: &retstrflt);
    if ( result != 0 )
    {
      *buf = 0;
    }
    else if ( retstrflt.decpt - 1 < -4 || retstrflt.decpt - 1 >= ndec )
    {
      return cftoe2_l(buf, sizeInBytes, ndec, caps, pflt: &retstrflt, g_fmt: 1, plocinfo);
    }
    else
    {
      if ( v8 < retstrflt.decpt - 1 )
        v10[strlen(v10) - 1] = 0;
      return cftof2_l(buf, pflt: &retstrflt, sizeInBytes, ndec, g_fmt: 1, plocinfo);
    }
  }
  else
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003CE90
// Name: __setdefaultprecision
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int _setdefaultprecision()
{
  int result; // eax

  result = _controlfp_s(_CurrentState: nullptr, newctrl: 0x10000u, mask: 0x30000u);
  if ( result != 0 )
    _invoke_watson(pszExpression: nullptr, pszFunction: nullptr, pszFile: nullptr, nLine: 0, pReserved: 0);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003CEB8
// Name: __stbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _stbuf(_iobuf *str)
{
  int v1; // eax
  int v2; // eax
  char **v3; // edi
  char *v4; // eax
  char *v5; // edi

  v1 = _fileno(stream: str);
  if ( _isatty(fh: v1) == 0 )
    return 0;
  if ( str == &__iob_func()[1] )
  {
    v2 = 0;
  }
  else
  {
    if ( str != &__iob_func()[2] )
      return 0;
    v2 = 1;
  }
  ++_cflush;
  if ( (str->_flag & 0x10C) != 0 )
    return 0;
  v3 = (char **)&_stdbuf[v2];
  if ( *v3 != nullptr || (v4 = (char *)operator new(nSize: 0x1000u), *v3 = v4, v4 != nullptr) )
  {
    v5 = *v3;
    str->_base = v5;
    str->_ptr = v5;
    str->_bufsiz = 4096;
    str->_cnt = 4096;
  }
  else
  {
    str->_base = (char *)&str->_charbuf;
    str->_ptr = (char *)&str->_charbuf;
    str->_bufsiz = 2;
    str->_cnt = 2;
  }
  str->_flag |= 0x1102u;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1003CF54
// Name: __ftbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _ftbuf(int flag, _iobuf *str)
{
  if ( flag != 0 && (str->_flag & 0x1000) != 0 )
  {
    _flush(str);
    str->_flag &= 0xFFFFEEFF;
    str->_bufsiz = 0;
    str->_ptr = nullptr;
    str->_base = nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003CF88
// Name: __output_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  int *v4; // ebx
  const char *v5; // edi
  int v7; // eax
  ioinfo *v8; // ecx
  ioinfo *v9; // eax
  char v10; // dl
  STATE v11; // ecx
  char *v12; // edi
  int v13; // eax
  char v14; // al
  bool v15; // zf
  char v16; // al
  _output_l::__l2::<unnamed_type_buffer> *p_buffer; // edi
  int v18; // ecx
  _output_l::__l2::<unnamed_type_text> v19; // ebx
  char *sz; // eax
  char *v21; // ebx
  __int16 *v22; // eax
  _output_l::__l2::<unnamed_type_text> v23; // ecx
  signed int v24; // eax
  _WORD *v25; // esi
  __int64 v26; // rax
  int *v27; // ebx
  int v28; // esi
  char *v29; // eax
  int v30; // eax
  char *v31; // ebx
  void (__cdecl *v32)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v33; // ebx
  void (__cdecl *v34)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v35)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v36; // ebx
  unsigned int v37; // edi
  char *j; // esi
  int v39; // eax
  unsigned __int64 v40; // rcx
  int v41; // ecx
  char *v42; // eax
  _BYTE *v43; // esi
  _BYTE *i; // eax
  int v45; // ebx
  int v46; // edi
  _iobuf *v47; // edi
  int v48; // ebx
  wchar_t *v49; // esi
  int v50; // ebx
  char v51; // al
  int v52; // [esp-14h] [ebp-298h]
  int v53; // [esp-10h] [ebp-294h]
  unsigned __int64 v54; // [esp-10h] [ebp-294h]
  int v55; // [esp-Ch] [ebp-290h]
  int v56; // [esp-8h] [ebp-28Ch]
  wchar_t v57; // [esp-4h] [ebp-288h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-278h] BYREF
  int capexp; // [esp+14h] [ebp-270h]
  STATE state; // [esp+18h] [ebp-26Ch]
  int padding; // [esp+20h] [ebp-264h]
  int retval; // [esp+24h] [ebp-260h] BYREF
  _LocaleUpdate _loc_update; // [esp+28h] [ebp-25Ch] BYREF
  char *heapbuf; // [esp+38h] [ebp-24Ch]
  int hexadd; // [esp+3Ch] [ebp-248h]
  int no_output; // [esp+40h] [ebp-244h]
  _iobuf *f; // [esp+44h] [ebp-240h]
  char *v68; // [esp+48h] [ebp-23Ch]
  int bufferiswide; // [esp+4Ch] [ebp-238h]
  int fldwidth; // [esp+50h] [ebp-234h]
  int prefixlen; // [esp+54h] [ebp-230h]
  char prefix[4]; // [esp+58h] [ebp-22Ch] BYREF
  char *v73; // [esp+5Ch] [ebp-228h]
  int charsout; // [esp+60h] [ebp-224h] BYREF
  int radix; // [esp+64h] [ebp-220h] BYREF
  _output_l::__l2::<unnamed_type_text> text; // [esp+68h] [ebp-21Ch]
  int precision; // [esp+6Ch] [ebp-218h]
  char v78; // [esp+73h] [ebp-211h]
  int flags; // [esp+74h] [ebp-210h]
  _output_l::__l2::<unnamed_type_buffer> buffer; // [esp+78h] [ebp-20Ch] BYREF
  char L_buffer[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = (int *)argptr;
  v5 = format;
  f = stream;
  v73 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( stream != nullptr
    && ((stream->_flag & 0x40) != 0
     || ((v7 = _fileno(stream)) == -1 || v7 == -2 ? (v8 = &__badioinfo) : (v8 = &__pioinfo[v7 >> 5][v7 & 0x1F]),
         (*((_BYTE *)v8 + 36) & 0x7F) == 0
      && (v7 == -1 || v7 == -2 ? (v9 = &__badioinfo) : (v9 = &__pioinfo[v7 >> 5][v7 & 0x1F]), *((char *)v9 + 36) >= 0)))
    && format != nullptr )
  {
    v10 = *format;
    v11 = ST_NORMAL;
    charsout = 0;
    radix = 0;
    heapbuf = nullptr;
    v78 = v10;
    if ( v10 != 0 )
    {
      while ( 1 )
      {
        v12 = (char *)(v5 + 1);
        v68 = v12;
        if ( charsout < 0 )
          break;
        if ( (unsigned __int8)(v10 - 32) > 0x58u )
          v13 = 0;
        else
          v13 = Src[v10] & 0xF;
        state = __lookuptable[8 * v13 + v11] >> 4;
        switch ( state )
        {
          case ST_NORMAL:
            goto NORMAL_STATE;
          case ST_PERCENT:
            precision = -1;
            capexp = 0;
            no_output = 0;
            fldwidth = 0;
            prefixlen = 0;
            flags = 0;
            bufferiswide = 0;
            goto LABEL_224;
          case ST_FLAG:
            switch ( v10 )
            {
              case ' ':
                flags |= 2u;
                break;
              case '#':
                flags |= 0x80u;
                break;
              case '+':
                flags |= 1u;
                break;
              case '-':
                flags |= 4u;
                break;
              case '0':
                flags |= 8u;
                break;
              default:
                break;
            }
            goto LABEL_224;
          case ST_WIDTH:
            if ( v10 == 42 )
            {
              v73 = (char *)(v4 + 1);
              fldwidth = *v4;
              if ( fldwidth < 0 )
              {
                flags |= 4u;
                fldwidth = -fldwidth;
              }
            }
            else
            {
              fldwidth = 10 * fldwidth + v10 - 48;
            }
            goto LABEL_224;
          case ST_DOT:
            precision = 0;
            goto LABEL_224;
          case ST_PRECIS:
            if ( v10 == 42 )
            {
              v73 = (char *)(v4 + 1);
              precision = *v4;
              if ( precision < 0 )
                precision = -1;
            }
            else
            {
              precision = 10 * precision + v10 - 48;
            }
            goto LABEL_224;
          case ST_SIZE:
            switch ( v10 )
            {
              case 'I':
                v14 = *v12;
                if ( *v12 == 54 && v12[1] == 52 )
                {
                  flags |= 0x8000u;
                  v68 = v12 + 2;
                }
                else if ( v14 == 51 && v12[1] == 50 )
                {
                  flags &= ~0x8000u;
                  v68 = v12 + 2;
                }
                else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
                {
                  state = ST_NORMAL;
NORMAL_STATE:
                  bufferiswide = 0;
                  v15 = _isleadbyte_l(c: v10, plocinfo: &_loc_update.localeinfo) == 0;
                  v16 = v78;
                  if ( !v15 )
                  {
                    write_char(ch: v78, f, pnumwritten: &charsout);
                    v16 = *v12;
                    v68 = v12 + 1;
                    if ( v16 == 0 )
                      goto LABEL_2;
                  }
                  write_char(ch: v16, f, pnumwritten: &charsout);
                }
                break;
              case 'h':
                flags |= 0x20u;
                break;
              case 'l':
                if ( *v12 == 108 )
                {
                  flags |= 0x1000u;
                  v68 = v12 + 1;
                }
                else
                {
                  flags |= 0x10u;
                }
                break;
              case 'w':
                flags |= 0x800u;
                break;
              default:
                break;
            }
            goto LABEL_224;
          case ST_TYPE:
            if ( v10 <= 100 )
            {
              if ( v10 == 100 )
              {
LABEL_118:
                flags |= 0x40u;
                goto LABEL_119;
              }
              if ( v10 > 83 )
              {
                if ( v10 == 88 )
                  goto LABEL_140;
                if ( v10 == 90 )
                {
                  v22 = (__int16 *)*v4;
                  v73 = (char *)(v4 + 1);
                  if ( v22 != nullptr && (v23.sz = *(char **)(v22 + 2), v23.sz != nullptr) )
                  {
                    v24 = *v22;
                    text.sz = v23.sz;
                    if ( (flags & 0x800) != 0 )
                    {
                      v24 /= 2;
                      bufferiswide = 1;
                    }
                    else
                    {
                      bufferiswide = 0;
                    }
                  }
                  else
                  {
                    text.sz = __nullstring;
                    strlen(buf: (unsigned __int8 *)__nullstring);
                  }
                  goto LABEL_189;
                }
                if ( v10 != 97 )
                {
                  if ( v10 != 99 )
                    goto LABEL_190;
                  goto LABEL_93;
                }
              }
              else
              {
                if ( v10 == 83 )
                {
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
                  goto LABEL_83;
                }
                if ( v10 != 65 )
                {
                  if ( v10 != 67 )
                  {
                    if ( v10 != 69 && v10 != 71 )
                      goto LABEL_190;
                    goto LABEL_76;
                  }
                  if ( (flags & 0x830) == 0 )
                    flags |= 0x800u;
LABEL_93:
                  v21 = (char *)(v4 + 1);
                  v73 = v21;
                  if ( (flags & 0x810) != 0 )
                  {
                    if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v21 - 2)) != 0 )
                      no_output = 1;
                  }
                  else
                  {
                    buffer.sz[0] = *(v21 - 4);
                    radix = 1;
                  }
                  text.sz = (char *)&buffer;
                  goto LABEL_190;
                }
LABEL_76:
                v10 += 32;
                capexp = 1;
                v78 = v10;
              }
LABEL_77:
              flags |= 0x40u;
              p_buffer = &buffer;
              text.sz = (char *)&buffer;
              padding = 512;
              if ( precision >= 0 )
              {
                if ( precision != 0 )
                {
                  if ( precision > 512 )
                    precision = 512;
                  if ( precision > 163 )
                  {
                    v28 = precision + 349;
                    v29 = (char *)operator new(nSize: precision + 349);
                    v10 = v78;
                    heapbuf = v29;
                    if ( v29 != nullptr )
                    {
                      text.sz = v29;
                      padding = v28;
                      p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)v29;
                    }
                    else
                    {
                      precision = 163;
                    }
                  }
                }
                else
                {
                  precision = v10 == 103;
                }
              }
              else
              {
                precision = 6;
              }
              v30 = *v4;
              v31 = (char *)(v4 + 2);
              LODWORD(tmp.x) = v30;
              HIDWORD(tmp.x) = *((_DWORD *)v31 - 1);
              v56 = capexp;
              v55 = precision;
              v73 = v31;
              v53 = v10;
              v52 = padding;
              v32 = (void (__cdecl *)(_CRT_DOUBLE *, _output_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))DecodePointer(Ptr: Ptr);
              v32(a1: &tmp, a2: p_buffer, a3: v52, a4: v53, a5: v55, a6: v56, a7: &_loc_update);
              v33 = flags & 0x80;
              if ( (flags & 0x80) != 0 && precision == 0 )
              {
                v34 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_100631A4);
                v34(a1: p_buffer, a2: &_loc_update);
              }
              if ( v78 == 103 && v33 == 0 )
              {
                v35 = (void (__cdecl *)(_output_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_100631A0);
                v35(a1: p_buffer, a2: &_loc_update);
              }
              if ( p_buffer->sz[0] == 45 )
              {
                flags |= 0x100u;
                p_buffer = (_output_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
                text.sz = (char *)p_buffer;
              }
              strlen(buf: (unsigned __int8 *)p_buffer);
              goto LABEL_189;
            }
            if ( v10 > 112 )
            {
              if ( v10 != 115 )
              {
                if ( v10 != 117 )
                {
                  if ( v10 != 120 )
                    goto LABEL_190;
                  hexadd = 39;
                  goto COMMON_HEX;
                }
LABEL_119:
                radix = 10;
                goto COMMON_INT;
              }
LABEL_83:
              v18 = precision;
              if ( precision == -1 )
                v18 = 0x7FFFFFFF;
              v73 = (char *)(v4 + 1);
              v19.sz = (char *)*v4;
              text.sz = v19.sz;
              if ( (flags & 0x810) != 0 )
              {
                if ( v19.sz == nullptr )
                  text.sz = (char *)__wnullstring;
                sz = text.sz;
                bufferiswide = 1;
                while ( v18 != 0 )
                {
                  --v18;
                  if ( *(_WORD *)sz == 0 )
                    break;
                  sz += 2;
                }
                v24 = (sz - text.sz) >> 1;
              }
              else
              {
                if ( v19.sz == nullptr )
                  text.sz = __nullstring;
                for ( i = text.sz; v18 != 0; ++i )
                {
                  --v18;
                  if ( *i == 0 )
                    break;
                }
                v24 = i - text.sz;
              }
LABEL_189:
              radix = v24;
              goto LABEL_190;
            }
            if ( v10 == 112 )
            {
              precision = 8;
LABEL_140:
              hexadd = 7;
COMMON_HEX:
              radix = 16;
              if ( (flags & 0x80u) != 0 )
              {
                prefix[0] = 48;
                prefix[1] = hexadd + 81;
                prefixlen = 2;
              }
              goto COMMON_INT;
            }
            if ( v10 < 101 )
              goto LABEL_190;
            if ( v10 <= 103 )
              goto LABEL_77;
            if ( v10 == 105 )
              goto LABEL_118;
            if ( v10 != 110 )
            {
              if ( v10 != 111 )
                goto LABEL_190;
              radix = 8;
              if ( (flags & 0x80u) != 0 )
                flags |= 0x200u;
COMMON_INT:
              if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
              {
                v26 = *(_QWORD *)v4;
                v27 = v4 + 2;
              }
              else
              {
                v27 = v4 + 1;
                if ( (flags & 0x20) != 0 )
                {
                  v73 = (char *)v27;
                  if ( (flags & 0x40) != 0 )
                    LODWORD(v26) = *((__int16 *)v27 - 2);
                  else
                    LODWORD(v26) = *((unsigned __int16 *)v27 - 2);
                  v26 = (int)v26;
LABEL_157:
                  if ( (flags & 0x40) != 0 && v26 < 0 )
                  {
                    v26 = -v26;
                    flags |= 0x100u;
                  }
                  v36 = HIDWORD(v26);
                  v37 = v26;
                  if ( (flags & 0x9000) == 0 )
                    v36 = 0;
                  if ( precision >= 0 )
                  {
                    flags &= ~8u;
                    if ( precision > 512 )
                      precision = 512;
                  }
                  else
                  {
                    precision = 1;
                  }
                  if ( (v36 | (unsigned int)v26) == 0 )
                    prefixlen = 0;
                  for ( j = &buffer.sz[511]; ; --j )
                  {
                    v39 = precision--;
                    if ( v39 <= 0 && (v36 | v37) == 0 )
                      break;
                    v54 = __PAIR64__(v36, v37);
                    v40 = __PAIR64__(v36, v37) % radix;
                    v41 = v40 + 48;
                    padding = HIDWORD(v40);
                    v36 = (v54 / radix) >> 32;
                    v37 = v54 / radix;
                    if ( v41 > 57 )
                      LOBYTE(v41) = hexadd + v41;
                    *j = v41;
                  }
                  v42 = (char *)(&buffer.sz[511] - j);
                  v43 = j + 1;
                  radix = (int)v42;
                  text.sz = v43;
                  if ( (flags & 0x200) != 0 && (v42 == nullptr || *v43 != 48) )
                  {
                    *--text.sz = 48;
                    v24 = (signed int)(v42 + 1);
                    goto LABEL_189;
                  }
LABEL_190:
                  if ( no_output != 0 )
                    goto LABEL_222;
                  if ( (flags & 0x40) != 0 )
                  {
                    if ( (flags & 0x100) != 0 )
                    {
                      prefix[0] = 45;
                      goto LABEL_198;
                    }
                    if ( (flags & 1) != 0 )
                    {
                      prefix[0] = 43;
                      goto LABEL_198;
                    }
                    if ( (flags & 2) != 0 )
                    {
                      prefix[0] = 32;
LABEL_198:
                      prefixlen = 1;
                    }
                  }
                  v45 = fldwidth - radix - prefixlen;
                  padding = v45;
                  if ( (flags & 0xC) == 0 )
                  {
                    v46 = fldwidth - radix - prefixlen;
                    if ( v45 > 0 )
                    {
                      do
                      {
                        --v46;
                        write_char(ch: 32, f, pnumwritten: &charsout);
                      }
                      while ( charsout != -1 && v46 > 0 );
                    }
                  }
                  v47 = f;
                  write_string(string: prefix, len: prefixlen, f, pnumwritten: &charsout);
                  if ( (flags & 8) != 0 && (flags & 4) == 0 )
                  {
                    do
                    {
                      if ( v45 <= 0 )
                        break;
                      --v45;
                      write_char(ch: 48, f: v47, pnumwritten: &charsout);
                    }
                    while ( charsout != -1 );
                  }
                  v48 = radix;
                  if ( bufferiswide != 0 && radix > 0 )
                  {
                    v49 = (wchar_t *)text.sz;
                    while ( 1 )
                    {
                      v57 = *v49;
                      --v48;
                      ++v49;
                      if ( wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v57) != 0 || retval == 0 )
                        break;
                      write_string(string: L_buffer, len: retval, f: v47, pnumwritten: &charsout);
                      if ( v48 == 0 )
                        goto LABEL_217;
                    }
                    charsout = -1;
                  }
                  else
                  {
                    write_string(string: text.sz, len: radix, f: v47, pnumwritten: &charsout);
                  }
LABEL_217:
                  if ( charsout >= 0 && (flags & 4) != 0 )
                  {
                    v50 = padding;
                    do
                    {
                      if ( v50 <= 0 )
                        break;
                      --v50;
                      write_char(ch: 32, f: v47, pnumwritten: &charsout);
                    }
                    while ( charsout != -1 );
                  }
                  goto LABEL_222;
                }
                LODWORD(v26) = *(v27 - 1);
                if ( (flags & 0x40) != 0 )
                  v26 = (int)v26;
                else
                  HIDWORD(v26) = 0;
              }
              v73 = (char *)v27;
              goto LABEL_157;
            }
            v25 = (_WORD *)*v4;
            v73 = (char *)(v4 + 1);
            if ( !_get_printf_count_output() )
              goto LABEL_2;
            if ( (flags & 0x20) != 0 )
              *v25 = charsout;
            else
              *(_DWORD *)v25 = charsout;
            no_output = 1;
LABEL_222:
            if ( heapbuf != nullptr )
            {
              free(pMem: heapbuf);
              heapbuf = nullptr;
            }
LABEL_224:
            v5 = v68;
            v51 = *v68;
            v78 = v51;
            if ( v51 == 0 )
              goto LABEL_226;
            v11 = state;
            v4 = (int *)v73;
            v10 = v51;
            break;
          default:
            goto LABEL_224;
        }
      }
    }
LABEL_226:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003DB34
// Name: __initp_misc_invarg
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_invarg(void *enull)
{
  __pInvalidArgHandler = enull;
}

//------------------------------------------------------------------------------
// Address: 0x1003DB43
// Name: __call_reportfault
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _call_reportfault(
        unsigned int a1@<edi>,
        unsigned int a2@<esi>,
        int nDbgHookCode,
        unsigned int dwExceptionCode,
        unsigned int dwExceptionFlags)
{
  unsigned int v5; // ecx
  unsigned int v6; // edx
  unsigned int v7; // kr00_4
  BOOL v8; // edi
  _EXCEPTION_POINTERS ExceptionPointers; // [esp+8h] [ebp-328h] BYREF
  _EXCEPTION_RECORD ExceptionRecord; // [esp+10h] [ebp-320h] BYREF
  _CONTEXT ContextRecord; // [esp+60h] [ebp-2D0h] BYREF
  unsigned int savedregs; // [esp+330h] [ebp+0h]
  void *retaddr; // [esp+334h] [ebp+4h] BYREF

  if ( nDbgHookCode != -1 )
    _crt_debugger_hook(_Reserved: nDbgHookCode);
  memset(dst: (int)&ExceptionRecord.ExceptionFlags, value: nullptr, count: 0x4Cu);
  ExceptionPointers.ExceptionRecord = &ExceptionRecord;
  ExceptionPointers.ContextRecord = &ContextRecord;
  ContextRecord.Eax = (unsigned int)&ContextRecord;
  ContextRecord.Ecx = v5;
  ContextRecord.Edx = v6;
  ContextRecord.Ebx = nDbgHookCode;
  ContextRecord.Esi = a2;
  ContextRecord.Edi = a1;
  LOWORD(ContextRecord.SegSs) = __SS__;
  LOWORD(ContextRecord.SegCs) = __CS__;
  LOWORD(ContextRecord.SegDs) = __DS__;
  LOWORD(ContextRecord.SegEs) = __ES__;
  LOWORD(ContextRecord.SegFs) = __FS__;
  LOWORD(ContextRecord.SegGs) = __GS__;
  v7 = __readeflags();
  ContextRecord.EFlags = v7;
  ContextRecord.Esp = (unsigned int)&retaddr;
  ContextRecord.ContextFlags = 65537;
  ContextRecord.Eip = (unsigned int)retaddr;
  ContextRecord.Ebp = savedregs;
  ExceptionRecord.ExceptionCode = dwExceptionCode;
  ExceptionRecord.ExceptionFlags = dwExceptionFlags;
  ExceptionRecord.ExceptionAddress = retaddr;
  v8 = IsDebuggerPresent();
  SetUnhandledExceptionFilter(lpTopLevelExceptionFilter: nullptr);
  if ( UnhandledExceptionFilter(ExceptionInfo: &ExceptionPointers) == 0 && !v8 && nDbgHookCode != -1 )
    _crt_debugger_hook(_Reserved: nDbgHookCode);
}

//------------------------------------------------------------------------------
// Address: 0x1003DC6C
// Name: __invoke_watson
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall __noreturn _invoke_watson(unsigned int a1@<edi>)
{
  HANDLE CurrentProcess; // eax

  _call_reportfault(a1, a2: 0xC0000417, nDbgHookCode: 2, dwExceptionCode: 0xC0000417, dwExceptionFlags: 1u);
  CurrentProcess = GetCurrentProcess();
  TerminateProcess(hProcess: CurrentProcess, uExitCode: 0xC0000417);
}

//------------------------------------------------------------------------------
// Address: 0x1003DC91
// Name: __invalid_parameter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall _invalid_parameter(unsigned int a1@<edi>)
{
  void (*v1)(void); // eax

  v1 = (void (*)(void))DecodePointer(Ptr: __pInvalidArgHandler);
  if ( v1 == nullptr )
    _invoke_watson(a1);
  v1();
}

//------------------------------------------------------------------------------
// Address: 0x1003DCBE
// Name: __invalid_parameter_noinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _invalid_parameter_noinfo()
{
  unsigned int v0; // edi

  _invalid_parameter(a1: v0);
}

//------------------------------------------------------------------------------
// Address: 0x1003DD15
// Name: __SEH_epilog4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
void _SEH_epilog4()
{
  __asm { retn }
}

//------------------------------------------------------------------------------
// Address: 0x1003DEBF
// Name: __ioinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _ioinit()
{
  ioinfo *v0; // eax
  char *p_pipech; // eax
  int v3; // ebx
  char **v4; // edi
  char *v5; // eax
  char *v6; // eax
  int i; // edi
  ioinfo *v8; // esi
  int j; // ebx
  ioinfo *v10; // esi
  DWORD v11; // eax
  HANDLE StdHandle; // eax
  int v13; // edi
  DWORD FileType; // eax
  _STARTUPINFOW StartupInfo; // [esp+4h] [ebp-4Ch] BYREF
  int *posfhnd; // [esp+48h] [ebp-8h]
  char *posfile; // [esp+4Ch] [ebp-4h]

  GetStartupInfoW(lpStartupInfo: &StartupInfo);
  v0 = (ioinfo *)calloc(count: 0x20u, size: 0x40u);
  if ( v0 == nullptr )
    return -1;
  __pioinfo[0] = v0;
  _nhandle = 32;
  if ( v0 < &v0[32] )
  {
    p_pipech = &v0->pipech;
    do
    {
      *(_DWORD *)(p_pipech - 5) = -1;
      *(_WORD *)(p_pipech - 1) = 2560;
      *(_DWORD *)(p_pipech + 3) = 0;
      *(_WORD *)(p_pipech + 31) = 2560;
      p_pipech[33] = 10;
      *(_DWORD *)(p_pipech + 51) = 0;
      p_pipech[47] = 0;
      p_pipech += 64;
    }
    while ( (ioinfo *)(p_pipech - 5) < &__pioinfo[0][32] );
  }
  if ( StartupInfo.cbReserved2 != 0 && StartupInfo.lpReserved2 != nullptr )
  {
    v3 = *(_DWORD *)StartupInfo.lpReserved2;
    posfile = (char *)(StartupInfo.lpReserved2 + 4);
    posfhnd = (int *)&StartupInfo.lpReserved2[v3 + 4];
    if ( v3 >= 2048 )
      v3 = 2048;
    if ( (int)_nhandle < v3 )
    {
      v4 = (char **)&unk_10174C04;
      while ( 1 )
      {
        v5 = (char *)calloc(count: 0x20u, size: 0x40u);
        if ( v5 == nullptr )
          break;
        _nhandle += 32;
        *v4 = v5;
        if ( v5 < v5 + 2048 )
        {
          v6 = v5 + 5;
          do
          {
            *(_DWORD *)(v6 - 5) = -1;
            *(_DWORD *)(v6 + 3) = 0;
            v6[31] &= 0x80u;
            *(_DWORD *)(v6 + 51) = 0;
            *(_WORD *)(v6 - 1) = 2560;
            *((_WORD *)v6 + 16) = 2570;
            v6[47] = 0;
            v6 += 64;
          }
          while ( v6 - 5 < *v4 + 2048 );
        }
        ++v4;
        if ( (int)_nhandle >= v3 )
          goto LABEL_19;
      }
      v3 = _nhandle;
    }
LABEL_19:
    for ( i = 0; i < v3; ++posfile )
    {
      if ( *posfhnd != -1
        && *posfhnd != -2
        && (*posfile & 1) != 0
        && ((*posfile & 8) != 0 || GetFileType(hFile: (HANDLE)*posfhnd) != 0) )
      {
        v8 = &__pioinfo[i >> 5][i & 0x1F];
        v8->osfhnd = *posfhnd;
        v8->osfile = *posfile;
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v8->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v8->lockinitflag;
      }
      ++posfhnd;
      ++i;
    }
  }
  for ( j = 0; j < 3; ++j )
  {
    v10 = &__pioinfo[0][j];
    if ( v10->osfhnd == -1 || v10->osfhnd == -2 )
    {
      v10->osfile = -127;
      if ( j != 0 )
        v11 = -(j != 1) - 11;
      else
        v11 = -10;
      StdHandle = GetStdHandle(nStdHandle: v11);
      v13 = (int)StdHandle;
      if ( StdHandle != (HANDLE)-1 && StdHandle != nullptr && (FileType = GetFileType(hFile: StdHandle)) != 0 )
      {
        v10->osfhnd = v13;
        if ( (unsigned __int8)FileType == 2 )
        {
          v10->osfile |= 0x40u;
        }
        else if ( (unsigned __int8)FileType == 3 )
        {
          v10->osfile |= 8u;
        }
        if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: &v10->lock, dwSpinCount: 0xFA0u) )
          return -1;
        ++v10->lockinitflag;
      }
      else
      {
        v10->osfile |= 0x40u;
        v10->osfhnd = -2;
      }
    }
    else
    {
      v10->osfile |= 0x80u;
    }
  }
  SetHandleCount(uNumber: _nhandle);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003E104
// Name: __ioterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _ioterm()
{
  void **v0; // edi
  char *v1; // eax
  _RTL_CRITICAL_SECTION *v2; // esi

  v0 = (void **)__pioinfo;
  do
  {
    v1 = (char *)*v0;
    if ( *v0 != nullptr )
    {
      if ( v1 < v1 + 2048 )
      {
        v2 = (_RTL_CRITICAL_SECTION *)(v1 + 12);
        do
        {
          if ( v2[-1].SpinCount != 0 )
            DeleteCriticalSection(lpCriticalSection: v2);
          v2 = (_RTL_CRITICAL_SECTION *)((char *)v2 + 64);
        }
        while ( &v2[-1].OwningThread < (void **)((char *)*v0 + 2048) );
      }
      free(pMem: *v0);
      *v0 = nullptr;
    }
    ++v0;
  }
  while ( (int)v0 < (int)&_acmdln );
}

//------------------------------------------------------------------------------
// Address: 0x1003E157
// Name: __fileno
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fileno(_iobuf *stream)
{
  if ( stream != nullptr )
    return stream->_file;
  *_errno() = 22;
  _invalid_parameter_noinfo();
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x1003E17D
// Name: write_char
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_char(int ch@<eax>, _iobuf *f@<ecx>, int *pnumwritten@<esi>)
{
  bool v3; // sf

  if ( ((f->_flag & 0x40) == 0 || f->_base != nullptr)
    && ((v3 = f->_cnt - 1 < 0, --f->_cnt, v3)
      ? (ch = _flsbuf((char)ch, str: f))
      : (*f->_ptr = ch, ++f->_ptr, ch = (unsigned __int8)ch),
        ch == -1) )
  {
    *pnumwritten = -1;
  }
  else
  {
    ++*pnumwritten;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E1B0
// Name: write_string
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall write_string(char *string@<ecx>, _iobuf *f@<edi>, int *pnumwritten@<eax>, int len)
{
  int *v4; // esi
  int *v6; // eax

  v4 = pnumwritten;
  if ( (f->_flag & 0x40) == 0 || f->_base != nullptr )
  {
    while ( len > 0 )
    {
      LOBYTE(pnumwritten) = *string;
      --len;
      write_char(ch: (int)pnumwritten, f, pnumwritten: v4);
      ++string;
      if ( *v4 == -1 )
      {
        v6 = _errno();
        if ( *v6 != 42 )
          return;
        LOBYTE(v6) = 63;
        write_char(ch: (int)v6, f, pnumwritten: v4);
      }
    }
  }
  else
  {
    *pnumwritten += len;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003E1FD
// Name: __output_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _output_s_l(_iobuf *stream, const char *format, localeinfo_struct *plocinfo, char *argptr)
{
  int *v4; // ebx
  const char *v5; // edi
  int v7; // eax
  ioinfo *v8; // ecx
  ioinfo *v9; // eax
  char v10; // dl
  char *v11; // edi
  int v12; // eax
  STATE v13; // eax
  char v14; // al
  bool v15; // zf
  int v16; // eax
  _output_s_l::__l2::<unnamed_type_buffer> *p_buffer; // edi
  int v18; // ecx
  _output_s_l::__l2::<unnamed_type_text> v19; // ebx
  char *sz; // eax
  char *v21; // ebx
  __int16 *v22; // eax
  _output_s_l::__l2::<unnamed_type_text> v23; // ecx
  signed int v24; // eax
  _WORD *v25; // esi
  int *v26; // ebx
  __int64 v27; // rax
  int v28; // esi
  char *v29; // eax
  int v30; // eax
  char *v31; // ebx
  void (__cdecl *v32)(_CRT_DOUBLE *, _output_s_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *); // eax
  int v33; // ebx
  void (__cdecl *v34)(_output_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  void (__cdecl *v35)(_output_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *); // eax
  unsigned int v36; // ebx
  unsigned int v37; // edi
  char *j; // esi
  int v39; // eax
  unsigned __int64 v40; // rcx
  int v41; // ecx
  char *v42; // eax
  _BYTE *v43; // esi
  _BYTE *i; // eax
  int v45; // eax
  int v46; // ebx
  int v47; // edi
  _iobuf *v48; // edi
  int v49; // eax
  int v50; // ebx
  wchar_t *v51; // esi
  int v52; // eax
  int v53; // ebx
  char v54; // al
  int v55; // [esp-14h] [ebp-298h]
  int v56; // [esp-10h] [ebp-294h]
  unsigned __int64 v57; // [esp-10h] [ebp-294h]
  int v58; // [esp-Ch] [ebp-290h]
  int v59; // [esp-8h] [ebp-28Ch]
  wchar_t v60; // [esp-4h] [ebp-288h]
  _CRT_DOUBLE tmp; // [esp+Ch] [ebp-278h] BYREF
  int capexp; // [esp+14h] [ebp-270h]
  int retval; // [esp+18h] [ebp-26Ch] BYREF
  int padding; // [esp+20h] [ebp-264h]
  int hexadd; // [esp+24h] [ebp-260h]
  int no_output; // [esp+28h] [ebp-25Ch]
  _iobuf *f; // [esp+2Ch] [ebp-258h]
  char *heapbuf; // [esp+30h] [ebp-254h]
  _LocaleUpdate _loc_update; // [esp+34h] [ebp-250h] BYREF
  STATE state; // [esp+44h] [ebp-240h]
  char *v71; // [esp+48h] [ebp-23Ch]
  int bufferiswide; // [esp+4Ch] [ebp-238h]
  int fldwidth; // [esp+50h] [ebp-234h]
  int prefixlen; // [esp+54h] [ebp-230h]
  char prefix[4]; // [esp+58h] [ebp-22Ch] BYREF
  char *v76; // [esp+5Ch] [ebp-228h]
  int charsout; // [esp+60h] [ebp-224h] BYREF
  int radix; // [esp+64h] [ebp-220h] BYREF
  _output_s_l::__l2::<unnamed_type_text> text; // [esp+68h] [ebp-21Ch]
  int precision; // [esp+6Ch] [ebp-218h]
  char v81; // [esp+73h] [ebp-211h]
  int flags; // [esp+74h] [ebp-210h]
  _output_s_l::__l2::<unnamed_type_buffer> buffer; // [esp+78h] [ebp-20Ch] BYREF
  char L_buffer[8]; // [esp+278h] [ebp-Ch] BYREF

  v4 = (int *)argptr;
  v5 = format;
  f = stream;
  v76 = argptr;
  hexadd = 0;
  flags = 0;
  fldwidth = 0;
  precision = 0;
  prefixlen = 0;
  no_output = 0;
  bufferiswide = 0;
  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( stream == nullptr )
    goto LABEL_2;
  if ( (stream->_flag & 0x40) == 0 )
  {
    v7 = _fileno(stream);
    if ( v7 == -1 || v7 == -2 )
      v8 = &__badioinfo;
    else
      v8 = &__pioinfo[v7 >> 5][v7 & 0x1F];
    if ( (*((_BYTE *)v8 + 36) & 0x7F) != 0 )
      goto LABEL_2;
    v9 = v7 == -1 || v7 == -2 ? &__badioinfo : &__pioinfo[v7 >> 5][v7 & 0x1F];
    if ( *((char *)v9 + 36) < 0 )
      goto LABEL_2;
  }
  if ( format == nullptr )
    goto LABEL_2;
  v10 = *format;
  charsout = 0;
  radix = 0;
  state = ST_NORMAL;
  heapbuf = nullptr;
  v81 = v10;
  if ( v10 == 0 )
    goto LABEL_229;
  while ( 1 )
  {
    v11 = (char *)(v5 + 1);
    v71 = v11;
    if ( charsout < 0 )
      break;
    if ( (unsigned __int8)(v10 - 32) > 0x58u )
      v12 = 0;
    else
      v12 = byte_100590E8[v10] & 0xF;
    v13 = __lookuptable_s[9 * v12 + state] >> 4;
    state = v13;
    if ( v13 == 8 )
      goto LABEL_2;
    switch ( v13 )
    {
      case ST_NORMAL:
        goto NORMAL_STATE_0;
      case ST_PERCENT:
        precision = -1;
        capexp = 0;
        no_output = 0;
        fldwidth = 0;
        prefixlen = 0;
        flags = 0;
        bufferiswide = 0;
        goto LABEL_225;
      case ST_FLAG:
        switch ( v10 )
        {
          case ' ':
            flags |= 2u;
            break;
          case '#':
            flags |= 0x80u;
            break;
          case '+':
            flags |= 1u;
            break;
          case '-':
            flags |= 4u;
            break;
          case '0':
            flags |= 8u;
            break;
          default:
            break;
        }
        goto LABEL_225;
      case ST_WIDTH:
        if ( v10 == 42 )
        {
          v76 = (char *)(v4 + 1);
          fldwidth = *v4;
          if ( fldwidth < 0 )
          {
            flags |= 4u;
            fldwidth = -fldwidth;
          }
        }
        else
        {
          fldwidth = 10 * fldwidth + v10 - 48;
        }
        goto LABEL_225;
      case ST_DOT:
        precision = 0;
        goto LABEL_225;
      case ST_PRECIS:
        if ( v10 == 42 )
        {
          v76 = (char *)(v4 + 1);
          precision = *v4;
          if ( precision < 0 )
            precision = -1;
        }
        else
        {
          precision = 10 * precision + v10 - 48;
        }
        goto LABEL_225;
      case ST_SIZE:
        switch ( v10 )
        {
          case 'I':
            v14 = *v11;
            if ( *v11 == 54 && v11[1] == 52 )
            {
              flags |= 0x8000u;
              v71 = v11 + 2;
            }
            else if ( v14 == 51 && v11[1] == 50 )
            {
              flags &= ~0x8000u;
              v71 = v11 + 2;
            }
            else if ( v14 != 100 && v14 != 105 && v14 != 111 && v14 != 117 && v14 != 120 && v14 != 88 )
            {
              state = ST_NORMAL;
NORMAL_STATE_0:
              bufferiswide = 0;
              v16 = _isleadbyte_l(c: v10, plocinfo: &_loc_update.localeinfo);
              v15 = v16 == 0;
              LOBYTE(v16) = v81;
              if ( !v15 )
              {
                write_char(ch: v16, f, pnumwritten: &charsout);
                LOBYTE(v16) = *v11;
                v71 = v11 + 1;
                if ( (_BYTE)v16 == 0 )
                  goto LABEL_2;
              }
              write_char(ch: v16, f, pnumwritten: &charsout);
            }
            break;
          case 'h':
            flags |= 0x20u;
            break;
          case 'l':
            if ( *v11 == 108 )
            {
              flags |= 0x1000u;
              v71 = v11 + 1;
            }
            else
            {
              flags |= 0x10u;
            }
            break;
          case 'w':
            flags |= 0x800u;
            break;
          default:
            break;
        }
        goto LABEL_225;
      case ST_TYPE:
        if ( v10 <= 100 )
        {
          if ( v10 == 100 )
          {
LABEL_119:
            flags |= 0x40u;
            goto LABEL_120;
          }
          if ( v10 > 83 )
          {
            if ( v10 == 88 )
              goto LABEL_141;
            if ( v10 == 90 )
            {
              v22 = (__int16 *)*v4;
              v76 = (char *)(v4 + 1);
              if ( v22 != nullptr && (v23.sz = *(char **)(v22 + 2), v23.sz != nullptr) )
              {
                v24 = *v22;
                text.sz = v23.sz;
                if ( (flags & 0x800) != 0 )
                {
                  v24 /= 2;
                  bufferiswide = 1;
                }
                else
                {
                  bufferiswide = 0;
                }
              }
              else
              {
                text.sz = __nullstring;
                strlen(buf: (unsigned __int8 *)__nullstring);
              }
              goto LABEL_190;
            }
            if ( v10 != 97 )
            {
              if ( v10 != 99 )
                goto LABEL_191;
              goto LABEL_94;
            }
          }
          else
          {
            if ( v10 == 83 )
            {
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
              goto LABEL_84;
            }
            if ( v10 != 65 )
            {
              if ( v10 != 67 )
              {
                if ( v10 != 69 && v10 != 71 )
                  goto LABEL_191;
                goto LABEL_77;
              }
              if ( (flags & 0x830) == 0 )
                flags |= 0x800u;
LABEL_94:
              v21 = (char *)(v4 + 1);
              v76 = v21;
              if ( (flags & 0x810) != 0 )
              {
                if ( wctomb_s(pRetValue: &radix, dst: buffer.sz, sizeInBytes: 0x200u, wchar: *((_WORD *)v21 - 2)) != 0 )
                  no_output = 1;
              }
              else
              {
                buffer.sz[0] = *(v21 - 4);
                radix = 1;
              }
              text.sz = (char *)&buffer;
              goto LABEL_191;
            }
LABEL_77:
            v10 += 32;
            capexp = 1;
            v81 = v10;
          }
LABEL_78:
          flags |= 0x40u;
          p_buffer = &buffer;
          text.sz = (char *)&buffer;
          padding = 512;
          if ( precision >= 0 )
          {
            if ( precision != 0 )
            {
              if ( precision > 512 )
                precision = 512;
              if ( precision > 163 )
              {
                v28 = precision + 349;
                v29 = (char *)operator new(nSize: precision + 349);
                v10 = v81;
                heapbuf = v29;
                if ( v29 != nullptr )
                {
                  text.sz = v29;
                  padding = v28;
                  p_buffer = (_output_s_l::__l2::<unnamed_type_buffer> *)v29;
                }
                else
                {
                  precision = 163;
                }
              }
            }
            else
            {
              precision = v10 == 103;
            }
          }
          else
          {
            precision = 6;
          }
          v30 = *v4;
          v31 = (char *)(v4 + 2);
          LODWORD(tmp.x) = v30;
          HIDWORD(tmp.x) = *((_DWORD *)v31 - 1);
          v59 = capexp;
          v58 = precision;
          v76 = v31;
          v56 = v10;
          v55 = padding;
          v32 = (void (__cdecl *)(_CRT_DOUBLE *, _output_s_l::__l2::<unnamed_type_buffer> *, int, int, int, int, _LocaleUpdate *))DecodePointer(Ptr: Ptr);
          v32(a1: &tmp, a2: p_buffer, a3: v55, a4: v56, a5: v58, a6: v59, a7: &_loc_update);
          v33 = flags & 0x80;
          if ( (flags & 0x80) != 0 && precision == 0 )
          {
            v34 = (void (__cdecl *)(_output_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_100631A4);
            v34(a1: p_buffer, a2: &_loc_update);
          }
          if ( v81 == 103 && v33 == 0 )
          {
            v35 = (void (__cdecl *)(_output_s_l::__l2::<unnamed_type_buffer> *, _LocaleUpdate *))DecodePointer(Ptr: off_100631A0);
            v35(a1: p_buffer, a2: &_loc_update);
          }
          if ( p_buffer->sz[0] == 45 )
          {
            flags |= 0x100u;
            p_buffer = (_output_s_l::__l2::<unnamed_type_buffer> *)((char *)p_buffer + 1);
            text.sz = (char *)p_buffer;
          }
          strlen(buf: (unsigned __int8 *)p_buffer);
          goto LABEL_190;
        }
        if ( v10 > 112 )
        {
          if ( v10 != 115 )
          {
            if ( v10 != 117 )
            {
              if ( v10 != 120 )
                goto LABEL_191;
              hexadd = 39;
              goto COMMON_HEX_0;
            }
LABEL_120:
            radix = 10;
            goto COMMON_INT_0;
          }
LABEL_84:
          v18 = precision;
          if ( precision == -1 )
            v18 = 0x7FFFFFFF;
          v76 = (char *)(v4 + 1);
          v19.sz = (char *)*v4;
          text.sz = v19.sz;
          if ( (flags & 0x810) != 0 )
          {
            if ( v19.sz == nullptr )
              text.sz = (char *)__wnullstring;
            sz = text.sz;
            bufferiswide = 1;
            while ( v18 != 0 )
            {
              --v18;
              if ( *(_WORD *)sz == 0 )
                break;
              sz += 2;
            }
            v24 = (sz - text.sz) >> 1;
          }
          else
          {
            if ( v19.sz == nullptr )
              text.sz = __nullstring;
            for ( i = text.sz; v18 != 0; ++i )
            {
              --v18;
              if ( *i == 0 )
                break;
            }
            v24 = i - text.sz;
          }
LABEL_190:
          radix = v24;
          goto LABEL_191;
        }
        if ( v10 == 112 )
        {
          precision = 8;
LABEL_141:
          hexadd = 7;
COMMON_HEX_0:
          radix = 16;
          if ( (flags & 0x80u) != 0 )
          {
            prefix[0] = 48;
            prefix[1] = hexadd + 81;
            prefixlen = 2;
          }
          goto COMMON_INT_0;
        }
        if ( v10 < 101 )
          goto LABEL_191;
        if ( v10 <= 103 )
          goto LABEL_78;
        if ( v10 == 105 )
          goto LABEL_119;
        if ( v10 != 110 )
        {
          if ( v10 != 111 )
            goto LABEL_191;
          radix = 8;
          if ( (flags & 0x80u) != 0 )
            flags |= 0x200u;
COMMON_INT_0:
          if ( (flags & 0x8000) != 0 || (flags & 0x1000) != 0 )
          {
            v26 = v4 + 2;
            v27 = *((_QWORD *)v26 - 1);
          }
          else
          {
            v26 = v4 + 1;
            if ( (flags & 0x20) != 0 )
            {
              v76 = (char *)v26;
              if ( (flags & 0x40) != 0 )
                LODWORD(v27) = *((__int16 *)v26 - 2);
              else
                LODWORD(v27) = *((unsigned __int16 *)v26 - 2);
              v27 = (int)v27;
LABEL_158:
              if ( (flags & 0x40) != 0 && v27 < 0 )
              {
                v27 = -v27;
                flags |= 0x100u;
              }
              v36 = HIDWORD(v27);
              v37 = v27;
              if ( (flags & 0x9000) == 0 )
                v36 = 0;
              if ( precision >= 0 )
              {
                flags &= ~8u;
                if ( precision > 512 )
                  precision = 512;
              }
              else
              {
                precision = 1;
              }
              if ( (v36 | (unsigned int)v27) == 0 )
                prefixlen = 0;
              for ( j = &buffer.sz[511]; ; --j )
              {
                v39 = precision--;
                if ( v39 <= 0 && (v36 | v37) == 0 )
                  break;
                v57 = __PAIR64__(v36, v37);
                v40 = __PAIR64__(v36, v37) % radix;
                v41 = v40 + 48;
                padding = HIDWORD(v40);
                v36 = (v57 / radix) >> 32;
                v37 = v57 / radix;
                if ( v41 > 57 )
                  LOBYTE(v41) = hexadd + v41;
                *j = v41;
              }
              v42 = (char *)(&buffer.sz[511] - j);
              v43 = j + 1;
              radix = (int)v42;
              text.sz = v43;
              if ( (flags & 0x200) != 0 && (v42 == nullptr || *v43 != 48) )
              {
                *--text.sz = 48;
                v24 = (signed int)(v42 + 1);
                goto LABEL_190;
              }
LABEL_191:
              if ( no_output != 0 )
                goto LABEL_223;
              v45 = flags;
              if ( (flags & 0x40) != 0 )
              {
                if ( (flags & 0x100) != 0 )
                {
                  prefix[0] = 45;
                  goto LABEL_199;
                }
                if ( (flags & 1) != 0 )
                {
                  prefix[0] = 43;
                  goto LABEL_199;
                }
                if ( (flags & 2) != 0 )
                {
                  prefix[0] = 32;
LABEL_199:
                  prefixlen = 1;
                }
              }
              v46 = fldwidth - radix - prefixlen;
              padding = v46;
              if ( (flags & 0xC) == 0 )
              {
                v47 = fldwidth - radix - prefixlen;
                if ( v46 > 0 )
                {
                  do
                  {
                    LOBYTE(v45) = 32;
                    --v47;
                    write_char(ch: v45, f, pnumwritten: &charsout);
                  }
                  while ( charsout != -1 && v47 > 0 );
                }
              }
              v48 = f;
              write_string(string: prefix, f, pnumwritten: &charsout, len: prefixlen);
              if ( (flags & 8) != 0 && (flags & 4) == 0 )
              {
                do
                {
                  if ( v46 <= 0 )
                    break;
                  LOBYTE(v49) = 48;
                  --v46;
                  write_char(ch: v49, f: v48, pnumwritten: &charsout);
                }
                while ( charsout != -1 );
              }
              v50 = radix;
              if ( bufferiswide != 0 && radix > 0 )
              {
                v51 = (wchar_t *)text.sz;
                while ( 1 )
                {
                  v60 = *v51;
                  --v50;
                  ++v51;
                  v52 = wctomb_s(pRetValue: &retval, dst: L_buffer, sizeInBytes: 6u, wchar: v60);
                  if ( v52 != 0 || retval == 0 )
                    break;
                  write_string(string: L_buffer, f: v48, pnumwritten: &charsout, len: retval);
                  if ( v50 == 0 )
                    goto LABEL_218;
                }
                charsout = -1;
              }
              else
              {
                write_string(string: text.sz, f: v48, pnumwritten: &charsout, len: radix);
              }
LABEL_218:
              if ( charsout >= 0 && (flags & 4) != 0 )
              {
                v53 = padding;
                do
                {
                  if ( v53 <= 0 )
                    break;
                  LOBYTE(v52) = 32;
                  --v53;
                  write_char(ch: v52, f: v48, pnumwritten: &charsout);
                }
                while ( charsout != -1 );
              }
              goto LABEL_223;
            }
            LODWORD(v27) = *(v26 - 1);
            if ( (flags & 0x40) != 0 )
              v27 = (int)v27;
            else
              HIDWORD(v27) = 0;
          }
          v76 = (char *)v26;
          goto LABEL_158;
        }
        v25 = (_WORD *)*v4;
        v76 = (char *)(v4 + 1);
        if ( !_get_printf_count_output() )
          goto LABEL_2;
        if ( (flags & 0x20) != 0 )
          *v25 = charsout;
        else
          *(_DWORD *)v25 = charsout;
        no_output = 1;
LABEL_223:
        if ( heapbuf != nullptr )
        {
          free(pMem: heapbuf);
          heapbuf = nullptr;
        }
LABEL_225:
        v5 = v71;
        v54 = *v71;
        v81 = v54;
        if ( v54 == 0 )
          goto LABEL_227;
        v4 = (int *)v76;
        v10 = v54;
        break;
      default:
        goto LABEL_225;
    }
  }
LABEL_227:
  if ( state == ST_NORMAL || state == ST_TYPE )
  {
LABEL_229:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return charsout;
  }
  else
  {
LABEL_2:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return -1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EDCD
// Name: _strcpy_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl strcpy_s(char *_Dst, unsigned int _SizeInBytes, const char *_Src)
{
  unsigned int v3; // edi
  int v4; // esi
  const char *v6; // eax
  char v7; // cl

  if ( _Dst == nullptr )
    goto LABEL_3;
  v3 = _SizeInBytes;
  if ( _SizeInBytes == 0 )
    goto LABEL_3;
  v6 = _Src;
  if ( _Src == nullptr )
  {
    *_Dst = 0;
LABEL_3:
    v4 = 22;
    *_errno() = 22;
LABEL_4:
    _invalid_parameter_noinfo();
    return v4;
  }
  do
  {
    v7 = *v6;
    v6[_Dst - _Src] = *v6;
    ++v6;
    if ( v7 == 0 )
      break;
    --v3;
  }
  while ( v3 != 0 );
  if ( v3 == 0 )
  {
    *_Dst = 0;
    *_errno() = 34;
    v4 = 34;
    goto LABEL_4;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003EE30
// Name: _strlen
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strlen(char *buf)
{
  char *v1; // ecx
  char v2; // al
  int v3; // eax
  int v4; // eax

  v1 = buf;
  if ( ((unsigned __int8)buf & 3) != 0 )
  {
    while ( 1 )
    {
      v2 = *v1++;
      if ( v2 == 0 )
        break;
      if ( ((unsigned __int8)v1 & 3) == 0 )
        goto main_loop_3;
    }
  }
  else
  {
    do
    {
      do
      {
main_loop_3:
        v3 = (*(_DWORD *)v1 + 2130640639) ^ ~*(_DWORD *)v1;
        v1 += 4;
      }
      while ( (v3 & 0x81010100) == 0 );
      v4 = *((_DWORD *)v1 - 1);
    }
    while ( (_BYTE)v4 != 0 && BYTE1(v4) != 0 && (v4 & 0xFF0000) != 0 && (v4 & 0xFF000000) != 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003EF30
// Name: _strcmp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl strcmp(unsigned __int8 *str1, unsigned __int8 *str2)
{
  unsigned __int8 *v2; // edx
  unsigned __int8 *v3; // ecx
  unsigned int v4; // eax
  unsigned int v5; // eax
  __int16 v6; // ax

  v2 = str1;
  v3 = str2;
  if ( ((unsigned __int8)str1 & 3) != 0 )
  {
    if ( ((unsigned __int8)str1 & 1) == 0 )
      goto doword;
    v2 = str1 + 1;
    if ( *str1 != *str2 )
      return;
    v3 = str2 + 1;
    if ( *str1 == 0 )
      return;
    if ( ((unsigned __int8)v2 & 2) != 0 )
    {
doword:
      v6 = *(_WORD *)v2;
      v2 += 2;
      if ( (_BYTE)v6 != *v3 || (_BYTE)v6 == 0 || HIBYTE(v6) != v3[1] || HIBYTE(v6) == 0 )
        return;
      v3 += 2;
    }
  }
  do
  {
    v4 = *(_DWORD *)v2;
    if ( (unsigned __int8)*(_DWORD *)v2 != *v3 )
      break;
    if ( (_BYTE)v4 == 0 )
      break;
    if ( BYTE1(v4) != v3[1] )
      break;
    if ( BYTE1(v4) == 0 )
      break;
    v5 = HIWORD(v4);
    if ( (_BYTE)v5 != v3[2] )
      break;
    if ( (_BYTE)v5 == 0 )
      break;
    if ( BYTE1(v5) != v3[3] )
      break;
    v3 += 4;
    v2 += 4;
  }
  while ( BYTE1(v5) != 0 );
}

//------------------------------------------------------------------------------
// Address: 0x1003EFB8
// Name: __VEC_memcpy
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// positive sp value has been detected, the output may be wrong!
int __usercall _VEC_memcpy@<eax>(unsigned int a1@<ecx>, __m128i *a2@<edi>, const __m128i *a3@<esi>)
{
  int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // ecx
  unsigned int k; // edx
  __m128i si128; // xmm1
  __m128i v8; // xmm2
  __m128i v9; // xmm3
  __m128i v10; // xmm5
  __m128i v11; // xmm6
  __m128i v12; // xmm7
  unsigned int m; // edx
  unsigned int v14; // ecx
  char v15; // al
  unsigned int n; // ecx
  int ii; // ecx
  unsigned int v19; // eax
  int i; // ecx
  unsigned int j; // eax
  unsigned int v22; // [esp-10h] [ebp-14h]
  int v23; // [esp-Ch] [ebp-10h]

  v3 = (unsigned __int8)a3 & 0xF;
  if ( ((unsigned __int8)a3 & 0xF) != 0 )
  {
    v22 = a1 - (16 - v3);
    v19 = 16 - v3;
    for ( i = v19 & 3; i != 0; --i )
    {
      a2->m128i_i8[0] = a3->m128i_i8[0];
      a3 = (const __m128i *)((char *)a3 + 1);
      a2 = (__m128i *)((char *)a2 + 1);
    }
    for ( j = v19 >> 2; j != 0; --j )
    {
      a2->m128i_i32[0] = a3->m128i_i32[0];
      a3 = (const __m128i *)((char *)a3 + 4);
      a2 = (__m128i *)((char *)a2 + 4);
    }
    a1 = v22;
  }
  v4 = a1;
  v5 = a1 & 0x7F;
  for ( k = v4 >> 7; k != 0; --k )
  {
    si128 = _mm_load_si128(a3 + 1);
    v8 = _mm_load_si128(a3 + 2);
    v9 = _mm_load_si128(a3 + 3);
    *a2 = _mm_load_si128(a3);
    a2[1] = si128;
    a2[2] = v8;
    a2[3] = v9;
    v10 = _mm_load_si128(a3 + 5);
    v11 = _mm_load_si128(a3 + 6);
    v12 = _mm_load_si128(a3 + 7);
    a2[4] = _mm_load_si128(a3 + 4);
    a2[5] = v10;
    a2[6] = v11;
    a2[7] = v12;
    a3 += 8;
    a2 += 8;
  }
  if ( v5 != 0 )
  {
    for ( m = v5 >> 4; m != 0; --m )
      *a2++ = _mm_load_si128(a3++);
    v14 = v5 & 0xF;
    if ( v14 != 0 )
    {
      v15 = v14;
      for ( n = v14 >> 2; n != 0; --n )
      {
        a2->m128i_i32[0] = a3->m128i_i32[0];
        a3 = (const __m128i *)((char *)a3 + 4);
        a2 = (__m128i *)((char *)a2 + 4);
      }
      for ( ii = v15 & 3; ii != 0; --ii )
      {
        a2->m128i_i8[0] = a3->m128i_i8[0];
        a3 = (const __m128i *)((char *)a3 + 1);
        a2 = (__m128i *)((char *)a2 + 1);
      }
    }
  }
  return v23;
}

//------------------------------------------------------------------------------
// Address: 0x1003F0BB
// Name: ___sse2_available_init
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __sse2_available_init()
{
  __sse2_available = IsProcessorFeaturePresent(ProcessorFeature: 0xAu);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F0CB
// Name: _abort
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn abort()
{
  unsigned int v0; // edi
  unsigned int v1; // esi

  if ( __get_sigabrt() != nullptr )
    raise(signum: 22);
  if ( (__abort_behavior & 2) != 0 )
    _call_reportfault(a1: v0, a2: v1, nDbgHookCode: 3, dwExceptionCode: 0x40000015u, dwExceptionFlags: 1u);
  _exit(code: 3);
}

//------------------------------------------------------------------------------
// Address: 0x1003F0FE
// Name: __set_abort_behavior
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _set_abort_behavior(unsigned int flags, unsigned int mask)
{
  unsigned int result; // eax

  result = __abort_behavior;
  __abort_behavior = mask & flags | __abort_behavior & ~mask;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003F11F
// Name: __GET_RTERRMSG
// Source: linker_block_proximity
//------------------------------------------------------------------------------
const wchar_t *__cdecl _GET_RTERRMSG(int rterrnum)
{
  int v1; // eax

  v1 = 0;
  while ( rterrnum != rterrs[v1].rterrno )
  {
    if ( (unsigned int)++v1 >= 0x16 )
      return nullptr;
  }
  return rterrs[v1].rterrtxt;
}

//------------------------------------------------------------------------------
// Address: 0x1003F145
// Name: __NMSG_WRITE
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _NMSG_WRITE(int rterrnum)
{
  const wchar_t *v1; // edi
  unsigned int v2; // eax
  HANDLE StdHandle; // eax
  void *v4; // esi
  unsigned int i; // eax
  DWORD v6; // eax
  unsigned int bytes_written; // [esp+Ch] [ebp-1FCh] BYREF
  char buffer[500]; // [esp+10h] [ebp-1F8h] BYREF

  v1 = _GET_RTERRMSG(rterrnum);
  bytes_written = (unsigned int)v1;
  if ( v1 != nullptr )
  {
    if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
    {
      StdHandle = GetStdHandle(nStdHandle: 0xFFFFFFF4);
      v4 = StdHandle;
      if ( StdHandle != nullptr && StdHandle != (HANDLE)-1 )
      {
        for ( i = 0; i < 0x1F4; ++i )
        {
          buffer[i] = v1[i];
          if ( v1[i] == 0 )
            break;
        }
        buffer[499] = 0;
        strlen(buf: buffer);
        WriteFile(
          hFile: v4,
          lpBuffer: buffer,
          nNumberOfBytesToWrite: v6,
          lpNumberOfBytesWritten: &bytes_written,
          lpOverlapped: nullptr);
      }
    }
    else if ( rterrnum != 252 )
    {
      if ( wcscpy_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"Runtime Error!\n\nProgram: ") != 0
        || (outmsg[285] = 0, GetModuleFileNameW(hModule: nullptr, lpFilename: &outmsg[25], nSize: 0x104u) == 0)
        && wcscpy_s(_Dst: &outmsg[25], _SizeInWords: 0x2FBu, _Src: L"<program name unknown>") != 0
        || wcslen(wcs: &outmsg[25]) + 1 > 0x3C
        && (v2 = wcslen(wcs: &outmsg[25]),
            wcsncpy_s(
              _Dst: &_proc_attached + v2,
              _SizeInWords: 763 - (&_proc_attached + v2 - &outmsg[25]),
              _Src: L"...",
              _Count: 3u) != 0)
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: L"\n\n") != 0
        || wcscat_s(_Dst: outmsg, _SizeInWords: 0x314u, _Src: (const wchar_t *)bytes_written) != 0 )
      {
        _invoke_watson(a1: (unsigned int)outmsg);
      }
      __crtMessageBoxW(lpText: outmsg, lpCaption: L"Microsoft Visual C++ Runtime Library", uType: 0x12010u);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F2F4
// Name: __FF_MSGBANNER
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _FF_MSGBANNER()
{
  if ( _set_error_mode(em: 3) == 1 || _set_error_mode(em: 3) == 0 && __app_type == 1 )
  {
    _NMSG_WRITE(rterrnum: 252);
    _NMSG_WRITE(rterrnum: 255);
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F32D
// Name: __initp_misc_purevirt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_purevirt(void *enull)
{
  __pPurecall = enull;
}

//------------------------------------------------------------------------------
// Address: 0x1003F33C
// Name: __fcloseall
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fcloseall()
{
  int i; // edi
  _iobuf *v1; // eax
  int count; // [esp+14h] [ebp-1Ch]

  count = 0;
  _lock(locknum: 1);
  for ( i = 3; i < (int)_nstream; ++i )
  {
    if ( __piob[i] != nullptr )
    {
      v1 = (_iobuf *)__piob[i];
      if ( (v1->_flag & 0x83) != 0 && fclose(stream: v1) != -1 )
        ++count;
      if ( i >= 20 )
      {
        DeleteCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
        free(pMem: __piob[i]);
        __piob[i] = nullptr;
      }
    }
  }
  _unlock(locknum: 1);
  return count;
}

//------------------------------------------------------------------------------
// Address: 0x1003F3D8
// Name: __mtinitlocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocks()
{
  int v0; // esi
  _RTL_CRITICAL_SECTION *v1; // edi
  LPCRITICAL_SECTION *v2; // eax

  v0 = 0;
  v1 = lclcritsects;
  while ( 1 )
  {
    if ( *(&locktable + 2 * v0 + 1) == (LPCRITICAL_SECTION)1 )
    {
      v2 = &locktable + 2 * v0;
      *v2 = v1++;
      if ( !InitializeCriticalSectionAndSpinCount(lpCriticalSection: *v2, dwSpinCount: 0xFA0u) )
        break;
    }
    if ( ++v0 >= 36 )
      return 1;
  }
  *(&locktable + 2 * v0) = nullptr;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F422
// Name: __mtdeletelocks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void _mtdeletelocks()
{
  LPCRITICAL_SECTION *v0; // esi
  LPCRITICAL_SECTION v1; // edi
  LPCRITICAL_SECTION *v2; // esi

  v0 = &locktable;
  do
  {
    v1 = *v0;
    if ( *v0 != nullptr && v0[1] != (LPCRITICAL_SECTION)1 )
    {
      DeleteCriticalSection(lpCriticalSection: *v0);
      free(pMem: v1);
      *v0 = nullptr;
    }
    v0 += 2;
  }
  while ( (int)v0 < (int)&__initialmbcinfo );
  v2 = &locktable;
  do
  {
    if ( *v2 != nullptr && v2[1] == (LPCRITICAL_SECTION)1 )
      DeleteCriticalSection(lpCriticalSection: *v2);
    v2 += 2;
  }
  while ( (int)v2 < (int)&__initialmbcinfo );
}

//------------------------------------------------------------------------------
// Address: 0x1003F479
// Name: __unlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _unlock(int locknum)
{
  LeaveCriticalSection(lpCriticalSection: *(&locktable + 2 * locknum));
}

//------------------------------------------------------------------------------
// Address: 0x1003F490
// Name: __mtinitlocknum
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinitlocknum(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi
  _RTL_CRITICAL_SECTION *v3; // edi
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 1;
  if ( _crtheap == nullptr )
  {
    _FF_MSGBANNER();
    _NMSG_WRITE(rterrnum: 30);
    __crtExitProcess(status: 255);
  }
  v1 = &locktable + 2 * locknum;
  if ( *v1 != nullptr )
    return 1;
  v3 = (_RTL_CRITICAL_SECTION *)operator new(nSize: 0x18u);
  if ( v3 != nullptr )
  {
    _lock(locknum: 10);
    if ( *v1 != nullptr )
    {
      free(pMem: v3);
    }
    else if ( InitializeCriticalSectionAndSpinCount(lpCriticalSection: v3, dwSpinCount: 0xFA0u) )
    {
      *v1 = v3;
    }
    else
    {
      free(pMem: v3);
      *_errno() = 12;
      retval = 0;
    }
    _unlock(locknum: 10);
    return retval;
  }
  else
  {
    *_errno() = 12;
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F552
// Name: __lock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _lock(int locknum)
{
  LPCRITICAL_SECTION *v1; // esi

  v1 = &locktable + 2 * locknum;
  if ( *v1 == nullptr && _mtinitlocknum(locknum) == 0 )
    _amsg_exit(rterrnum: 17);
  EnterCriticalSection(lpCriticalSection: *v1);
}

//------------------------------------------------------------------------------
// Address: 0x1003F585
// Name: __filbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _filbuf(_iobuf *str)
{
  int flag; // eax
  int v2; // eax
  int v3; // eax
  int v4; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // eax
  char *ptr; // ecx
  int result; // eax
  char *base; // [esp-8h] [ebp-Ch]
  unsigned int bufsiz; // [esp-4h] [ebp-8h]

  if ( str == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  flag = str->_flag;
  if ( (flag & 0x83) == 0 || (flag & 0x40) != 0 )
    return -1;
  if ( (flag & 2) != 0 )
  {
    str->_flag = flag | 0x20;
    return -1;
  }
  v2 = flag | 1;
  str->_flag = v2;
  if ( (v2 & 0x10C) != 0 )
    str->_ptr = str->_base;
  else
    _getbuf(str);
  bufsiz = str->_bufsiz;
  base = str->_base;
  v3 = _fileno(stream: str);
  v4 = _read(fh: v3, buf: base, cnt: bufsiz);
  str->_cnt = v4;
  if ( v4 == 0 || v4 == -1 )
  {
    str->_flag |= v4 != 0 ? 32 : 16;
    str->_cnt = 0;
    return -1;
  }
  if ( (str->_flag & 0x82) == 0 )
  {
    if ( _fileno(stream: str) == -1 || _fileno(stream: str) == -2 )
    {
      v6 = &__badioinfo;
    }
    else
    {
      v5 = &__pioinfo[_fileno(stream: str) >> 5];
      v6 = &(*v5)[_fileno(stream: str) & 0x1F];
    }
    if ( (v6->osfile & 0x82) == 0x82 )
      str->_flag |= 0x2000u;
  }
  if ( str->_bufsiz == 512 )
  {
    v7 = str->_flag;
    if ( (v7 & 8) != 0 && (v7 & 0x400) == 0 )
      str->_bufsiz = 4096;
  }
  ptr = str->_ptr;
  --str->_cnt;
  result = (unsigned __int8)*ptr;
  str->_ptr = ptr + 1;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1003F6A7
// Name: CPtoLCID
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall CPtoLCID@<eax>(int codepage@<eax>)
{
  int v1; // eax
  int v2; // eax
  int v3; // eax

  v1 = codepage - 932;
  if ( v1 == 0 )
    return 1041;
  v2 = v1 - 4;
  if ( v2 == 0 )
    return 2052;
  v3 = v2 - 13;
  if ( v3 == 0 )
    return 1042;
  if ( v3 == 1 )
    return 1028;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003F6D6
// Name: setSBCS
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBCS(threadmbcinfostruct *ptmbci@<eax>)
{
  unsigned __int8 *mbctype; // eax
  int v3; // ecx
  int i; // edi
  unsigned __int8 *mbcasemap; // eax
  int j; // esi

  memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
  ptmbci->mbcodepage = 0;
  ptmbci->ismbcodepage = 0;
  ptmbci->mblcid = 0;
  *(_DWORD *)ptmbci->mbulinfo = 0;
  *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
  *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
  mbctype = ptmbci->mbctype;
  v3 = (char *)&__initialmbcinfo - (char *)ptmbci;
  for ( i = 257; i != 0; --i )
  {
    *mbctype = mbctype[v3];
    ++mbctype;
  }
  mbcasemap = ptmbci->mbcasemap;
  for ( j = 256; j != 0; --j )
  {
    *mbcasemap = mbcasemap[v3];
    ++mbcasemap;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1003F73A
// Name: setSBUpLow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall setSBUpLow(threadmbcinfostruct *ptmbci@<esi>)
{
  unsigned int i; // eax
  unsigned __int8 v2; // al
  unsigned __int8 *v3; // ebx
  unsigned int v4; // ecx
  unsigned int v5; // eax
  int v6; // eax
  unsigned __int16 v7; // cx
  unsigned __int8 v8; // cl
  unsigned int v9; // ecx
  unsigned __int8 *v10; // eax
  unsigned __int8 v11; // dl
  int v12; // [esp+8h] [ebp-51Ch]
  _cpinfo cpinfo; // [esp+Ch] [ebp-518h] BYREF
  unsigned __int16 wVector[256]; // [esp+20h] [ebp-504h] BYREF
  unsigned __int8 upVector[256]; // [esp+220h] [ebp-304h] BYREF
  unsigned __int8 lowVector[256]; // [esp+320h] [ebp-204h] BYREF
  unsigned __int8 sbVector[256]; // [esp+420h] [ebp-104h] BYREF

  if ( GetCPInfo(CodePage: ptmbci->mbcodepage, lpCPInfo: &cpinfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      sbVector[i] = i;
    v2 = cpinfo.LeadByte[0];
    sbVector[0] = 32;
    if ( cpinfo.LeadByte[0] != 0 )
    {
      v3 = &cpinfo.LeadByte[1];
      do
      {
        v4 = v2;
        v5 = *v3;
        if ( v4 <= v5 )
          memset(dst: (int)&sbVector[v4], value: (unsigned __int8 *)0x20, count: v5 - v4 + 1);
        v2 = v3[1];
        v3 += 2;
      }
      while ( v2 != 0 );
    }
    __crtGetStringTypeA(
      plocinfo: nullptr,
      dwInfoType: 1u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpCharType: wVector,
      code_page: ptmbci->mbcodepage,
      lcid: ptmbci->mblcid,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x100u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)lowVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    __crtLCMapStringA(
      plocinfo: nullptr,
      Locale: ptmbci->mblcid,
      dwMapFlags: 0x200u,
      lpSrcStr: (const char *)sbVector,
      cchSrc: 256,
      lpDestStr: (char *)upVector,
      cchDest: 256,
      code_page: ptmbci->mbcodepage,
      bError: 0);
    v6 = 0;
    while ( 1 )
    {
      v7 = wVector[v6];
      if ( (v7 & 1) != 0 )
      {
        ptmbci->mbctype[v6 + 1] |= 0x10u;
        v8 = lowVector[v6];
      }
      else
      {
        if ( (v7 & 2) == 0 )
        {
          ptmbci->mbcasemap[v6] = 0;
          goto LABEL_16;
        }
        ptmbci->mbctype[v6 + 1] |= 0x20u;
        v8 = upVector[v6];
      }
      ptmbci->mbcasemap[v6] = v8;
LABEL_16:
      if ( (unsigned int)++v6 >= 0x100 )
        return;
    }
  }
  v9 = 0;
  v12 = -97 - (_DWORD)ptmbci->mbcasemap;
  do
  {
    v10 = &ptmbci->mbcasemap[v9];
    if ( (unsigned int)&v10[v12 + 32] <= 0x19 )
    {
      ptmbci->mbctype[v9 + 1] |= 0x10u;
      v11 = v9 + 32;
LABEL_23:
      *v10 = v11;
      goto LABEL_25;
    }
    if ( (unsigned int)&v10[v12] <= 0x19 )
    {
      ptmbci->mbctype[v9 + 1] |= 0x20u;
      v11 = v9 - 32;
      goto LABEL_23;
    }
    *v10 = 0;
LABEL_25:
    ++v9;
  }
  while ( v9 < 0x100 );
}

//------------------------------------------------------------------------------
// Address: 0x1003F8CA
// Name: ___updatetmbcinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadmbcinfostruct *__cdecl __updatetmbcinfo()
{
  _tiddata *v0; // edi
  threadmbcinfostruct *ptmbcinfo; // esi

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptmbcinfo = v0->ptmbcinfo;
  }
  else
  {
    _lock(locknum: 13);
    ptmbcinfo = v0->ptmbcinfo;
    if ( ptmbcinfo != __ptmbcinfo )
    {
      if ( ptmbcinfo != nullptr
        && InterlockedDecrement(lpAddend: &ptmbcinfo->refcount) == 0
        && ptmbcinfo != &__initialmbcinfo )
      {
        free(pMem: ptmbcinfo);
      }
      v0->ptmbcinfo = __ptmbcinfo;
      ptmbcinfo = __ptmbcinfo;
      InterlockedIncrement(lpAddend: &__ptmbcinfo->refcount);
    }
    _unlock(locknum: 13);
  }
  if ( ptmbcinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptmbcinfo;
}

//------------------------------------------------------------------------------
// Address: 0x1003F96E
// Name: getSystemCP
// Source: linker_block_proximity
//------------------------------------------------------------------------------
UINT __usercall getSystemCP@<eax>(int codepage@<esi>)
{
  UINT result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo: nullptr);
  fSystemSet = 0;
  switch ( codepage )
  {
    case -2:
      fSystemSet = 1;
      result = GetOEMCP();
      goto LABEL_3;
    case -3:
      fSystemSet = 1;
      result = GetACP();
      goto LABEL_3;
    case -4:
      result = _loc_update.localeinfo.locinfo->lc_codepage;
      fSystemSet = 1;
LABEL_3:
      if ( _loc_update.updated )
        _loc_update.ptd->_ownlocale &= ~2u;
      return result;
    default:
      break;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return codepage;
}

//------------------------------------------------------------------------------
// Address: 0x1003F9EA
// Name: __setmbcp_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp_nolock(int codepage, threadmbcinfostruct *ptmbci)
{
  UINT SystemCP; // edi
  unsigned int i; // eax
  unsigned __int8 *v5; // esi
  unsigned __int8 v6; // cl
  unsigned int k; // eax
  unsigned __int8 *v8; // esi
  unsigned int v9; // eax
  unsigned int v10; // edi
  unsigned __int16 *mbulinfo; // eax
  int v12; // ecx
  unsigned __int16 *v13; // ecx
  int j; // edx
  unsigned __int8 *v15; // eax
  int m; // ecx
  int v17; // edx
  unsigned int irg; // [esp+Ch] [ebp-20h]
  unsigned int icp; // [esp+10h] [ebp-1Ch]
  unsigned int icpa; // [esp+10h] [ebp-1Ch]
  _cpinfo cpinfo; // [esp+14h] [ebp-18h] BYREF
  int codepagea; // [esp+34h] [ebp+8h]

  SystemCP = getSystemCP(codepage);
  codepagea = SystemCP;
  if ( SystemCP != 0 )
  {
    icp = 0;
    for ( i = 0; i < 5; ++i )
    {
      if ( _rgcode_page_info[i].code_page == SystemCP )
      {
        memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
        irg = 0;
        v8 = _rgcode_page_info[icp].rgrange[0];
        icpa = (unsigned int)v8;
        do
        {
          while ( *v8 != 0 )
          {
            LOBYTE(v9) = v8[1];
            if ( (_BYTE)v9 == 0 )
              break;
            v10 = *v8;
            v9 = (unsigned __int8)v9;
            while ( v10 <= v9 )
            {
              ptmbci->mbctype[v10 + 1] |= _rgctypeflag[irg];
              v9 = v8[1];
              ++v10;
            }
            SystemCP = codepagea;
            v8 += 2;
          }
          ++irg;
          v8 = (unsigned __int8 *)(icpa + 8);
          icpa += 8;
        }
        while ( irg < 4 );
        ptmbci->mbcodepage = SystemCP;
        ptmbci->ismbcodepage = 1;
        ptmbci->mblcid = CPtoLCID(codepage: SystemCP);
        mbulinfo = ptmbci->mbulinfo;
        v13 = (unsigned __int16 *)((char *)_rgcode_page_info[0].mbulinfo + v12);
        for ( j = 6; j != 0; --j )
          *mbulinfo++ = *v13++;
LABEL_26:
        setSBUpLow(ptmbci);
        return 0;
      }
      ++icp;
    }
    if ( SystemCP == 65000 || SystemCP == 65001 || !IsValidCodePage(CodePage: (unsigned __int16)SystemCP) )
      return -1;
    if ( GetCPInfo(CodePage: SystemCP, lpCPInfo: &cpinfo) )
    {
      memset(dst: (int)ptmbci->mbctype, value: nullptr, count: sizeof(ptmbci->mbctype));
      ptmbci->mbcodepage = SystemCP;
      ptmbci->mblcid = 0;
      if ( cpinfo.MaxCharSize <= 1 )
      {
        ptmbci->ismbcodepage = 0;
      }
      else
      {
        if ( cpinfo.LeadByte[0] != 0 )
        {
          v5 = &cpinfo.LeadByte[1];
          do
          {
            v6 = *v5;
            if ( *v5 == 0 )
              break;
            for ( k = *(v5 - 1); k <= v6; ++k )
              ptmbci->mbctype[k + 1] |= 4u;
            v5 += 2;
          }
          while ( *(v5 - 1) != 0 );
        }
        v15 = &ptmbci->mbctype[2];
        for ( m = 254; m != 0; --m )
          *v15++ |= 8u;
        ptmbci->mblcid = CPtoLCID(codepage: ptmbci->mbcodepage);
        ptmbci->ismbcodepage = v17;
      }
      *(_DWORD *)ptmbci->mbulinfo = 0;
      *(_DWORD *)&ptmbci->mbulinfo[2] = 0;
      *(_DWORD *)&ptmbci->mbulinfo[4] = 0;
      goto LABEL_26;
    }
    if ( fSystemSet == 0 )
      return -1;
  }
  setSBCS(ptmbci);
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003FBD3
// Name: __setmbcp
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _setmbcp(int codepage)
{
  _tiddata *v1; // edi
  threadmbcinfostruct *ptmbcinfo; // ebx
  threadmbcinfostruct *v3; // eax
  threadmbcinfostruct *v4; // ebx
  int v5; // eax
  int i; // eax
  int j; // eax
  int k; // eax
  int retcode; // [esp+14h] [ebp-20h]
  UINT codepagea; // [esp+3Ch] [ebp+8h]

  retcode = -1;
  v1 = _getptd();
  __updatetmbcinfo();
  ptmbcinfo = v1->ptmbcinfo;
  codepagea = getSystemCP(codepage);
  if ( codepagea == ptmbcinfo->mbcodepage )
    return 0;
  v3 = (threadmbcinfostruct *)operator new(nSize: 0x220u);
  v4 = v3;
  if ( v3 != nullptr )
  {
    qmemcpy(v3, v1->ptmbcinfo, sizeof(threadmbcinfostruct));
    v3->refcount = 0;
    v5 = _setmbcp_nolock(codepage: codepagea, ptmbci: v3);
    retcode = v5;
    if ( v5 != 0 )
    {
      if ( v5 == -1 )
      {
        if ( v4 != &__initialmbcinfo )
          free(pMem: v4);
        *_errno() = 22;
      }
    }
    else
    {
      if ( InterlockedDecrement(lpAddend: &v1->ptmbcinfo->refcount) == 0 && v1->ptmbcinfo != &__initialmbcinfo )
        free(pMem: v1->ptmbcinfo);
      v1->ptmbcinfo = v4;
      InterlockedIncrement(lpAddend: &v4->refcount);
      if ( (v1->_ownlocale & 2) == 0 && (__globallocalestatus & 1) == 0 )
      {
        _lock(locknum: 13);
        __mbcodepage = v4->mbcodepage;
        __ismbcodepage = v4->ismbcodepage;
        __mblcid = v4->mblcid;
        for ( i = 0; i < 5; ++i )
          __mbulinfo[i] = v4->mbulinfo[i];
        for ( j = 0; j < 257; ++j )
          _mbctype[j] = v4->mbctype[j];
        for ( k = 0; k < 256; ++k )
          _mbcasemap[k] = v4->mbcasemap[k];
        if ( InterlockedDecrement(lpAddend: &__ptmbcinfo->refcount) == 0 && __ptmbcinfo != &__initialmbcinfo )
          free(pMem: __ptmbcinfo);
        __ptmbcinfo = v4;
        InterlockedIncrement(lpAddend: &v4->refcount);
        _unlock(locknum: 13);
      }
    }
  }
  return retcode;
}

//------------------------------------------------------------------------------
// Address: 0x1003FD6D
// Name: ___initmbctable
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __initmbctable()
{
  if ( __mbctype_initialized == 0 )
  {
    _setmbcp(codepage: -3);
    __mbctype_initialized = 1;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1003FD8B
// Name: ___addlocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __addlocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+14h] [ebp+8h]

  InterlockedIncrement(lpAddend: &ptloci->refcount);
  if ( ptloci->lconv_intl_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_intl_refcount);
  if ( ptloci->lconv_mon_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_mon_refcount);
  if ( ptloci->lconv_num_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->lconv_num_refcount);
  if ( ptloci->ctype1_refcount != nullptr )
    InterlockedIncrement(lpAddend: ptloci->ctype1_refcount);
  p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
  for ( ptlocia = 6; ptlocia != 0; --ptlocia )
  {
    if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
      InterlockedIncrement(lpAddend: *p_refcount);
    if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
      InterlockedIncrement(lpAddend: p_refcount[1]);
    p_refcount += 4;
  }
  InterlockedIncrement(lpAddend: &ptloci->lc_time_curr->refcount);
}

//------------------------------------------------------------------------------
// Address: 0x1003FE1A
// Name: ___removelocaleref
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __removelocaleref(threadlocaleinfostruct *ptloci)
{
  volatile LONG **p_refcount; // ebx
  int ptlocia; // [esp+Ch] [ebp+8h]

  if ( ptloci != nullptr )
  {
    InterlockedDecrement(lpAddend: &ptloci->refcount);
    if ( ptloci->lconv_intl_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_intl_refcount);
    if ( ptloci->lconv_mon_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_mon_refcount);
    if ( ptloci->lconv_num_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->lconv_num_refcount);
    if ( ptloci->ctype1_refcount != nullptr )
      InterlockedDecrement(lpAddend: ptloci->ctype1_refcount);
    p_refcount = (volatile LONG **)&ptloci->lc_category[0].refcount;
    for ( ptlocia = 6; ptlocia != 0; --ptlocia )
    {
      if ( *(p_refcount - 2) != (volatile LONG *)__clocalestr && *p_refcount != nullptr )
        InterlockedDecrement(lpAddend: *p_refcount);
      if ( *(p_refcount - 1) != nullptr && p_refcount[1] != nullptr )
        InterlockedDecrement(lpAddend: p_refcount[1]);
      p_refcount += 4;
    }
    InterlockedDecrement(lpAddend: &ptloci->lc_time_curr->refcount);
  }
  return ptloci;
}

//------------------------------------------------------------------------------
// Address: 0x1003FEB3
// Name: ___freetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __freetlocinfo(threadlocaleinfostruct *ptloci)
{
  lconv *lconv; // eax
  int *lconv_intl_refcount; // eax
  int *lconv_mon_refcount; // eax
  int *lconv_num_refcount; // eax
  int *ctype1_refcount; // eax
  __lc_time_data *lc_time_curr; // eax
  void **p_refcount; // edi
  _DWORD *v9; // eax
  int ptlocia; // [esp+14h] [ebp+8h]

  lconv = ptloci->lconv;
  if ( lconv != nullptr && lconv != &__lconv_c )
  {
    lconv_intl_refcount = ptloci->lconv_intl_refcount;
    if ( lconv_intl_refcount != nullptr && *lconv_intl_refcount == 0 )
    {
      lconv_mon_refcount = ptloci->lconv_mon_refcount;
      if ( lconv_mon_refcount != nullptr && *lconv_mon_refcount == 0 )
      {
        free(pMem: ptloci->lconv_mon_refcount);
        __free_lconv_mon(l: ptloci->lconv);
      }
      lconv_num_refcount = ptloci->lconv_num_refcount;
      if ( lconv_num_refcount != nullptr && *lconv_num_refcount == 0 )
      {
        free(pMem: ptloci->lconv_num_refcount);
        __free_lconv_num(l: ptloci->lconv);
      }
      free(pMem: ptloci->lconv_intl_refcount);
      free(pMem: ptloci->lconv);
    }
  }
  ctype1_refcount = ptloci->ctype1_refcount;
  if ( ctype1_refcount != nullptr && *ctype1_refcount == 0 )
  {
    free(pMem: ptloci->ctype1 - 127);
    free(pMem: (void *)(ptloci->pclmap - 128));
    free(pMem: (void *)(ptloci->pcumap - 128));
    free(pMem: ptloci->ctype1_refcount);
  }
  lc_time_curr = ptloci->lc_time_curr;
  if ( lc_time_curr != &__lc_time_c && lc_time_curr->refcount == 0 )
  {
    __free_lc_time(lc_time: ptloci->lc_time_curr);
    free(pMem: ptloci->lc_time_curr);
  }
  p_refcount = (void **)&ptloci->lc_category[0].refcount;
  for ( ptlocia = 6; ptlocia != 0; --ptlocia )
  {
    if ( *(p_refcount - 2) != __clocalestr && *p_refcount != nullptr && *(_DWORD *)*p_refcount == 0 )
      free(pMem: *p_refcount);
    if ( *(p_refcount - 1) != nullptr )
    {
      v9 = p_refcount[1];
      if ( v9 != nullptr && *v9 == 0 )
        free(pMem: p_refcount[1]);
    }
    p_refcount += 4;
  }
  free(pMem: ptloci);
}

//------------------------------------------------------------------------------
// Address: 0x1003FFFE
// Name: __updatetlocinfoEx_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl _updatetlocinfoEx_nolock(
        threadlocaleinfostruct **pptlocid,
        threadlocaleinfostruct *ptlocis)
{
  threadlocaleinfostruct *v2; // esi

  if ( ptlocis == nullptr || pptlocid == nullptr )
    return nullptr;
  v2 = *pptlocid;
  if ( *pptlocid != ptlocis )
  {
    *pptlocid = ptlocis;
    __addlocaleref(ptloci: ptlocis);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: v2);
      if ( v2->refcount == 0 && v2 != &__initiallocinfo )
        __freetlocinfo(ptloci: v2);
    }
  }
  return ptlocis;
}

//------------------------------------------------------------------------------
// Address: 0x1004004B
// Name: ___updatetlocinfo
// Source: linker_block_proximity
//------------------------------------------------------------------------------
threadlocaleinfostruct *__cdecl __updatetlocinfo()
{
  _tiddata *v0; // esi
  threadlocaleinfostruct *ptlocinfo; // esi
  threadlocaleinfostruct *ptloci; // [esp+10h] [ebp-1Ch]

  v0 = _getptd();
  if ( (__globallocalestatus & v0->_ownlocale) != 0 && v0->ptlocinfo != nullptr )
  {
    ptlocinfo = _getptd()->ptlocinfo;
  }
  else
  {
    _lock(locknum: 12);
    ptloci = _updatetlocinfoEx_nolock(pptlocid: &v0->ptlocinfo, ptlocis: __ptlocinfo);
    _unlock(locknum: 12);
    ptlocinfo = ptloci;
  }
  if ( ptlocinfo == nullptr )
    _amsg_exit(rterrnum: 32);
  return ptlocinfo;
}

//------------------------------------------------------------------------------
// Address: 0x100400C4
// Name: __encoded_null
// Source: linker_block_proximity
//------------------------------------------------------------------------------
PVOID _encoded_null()
{
  return EncodePointer(Ptr: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100400CD
// Name: __crtTlsAlloc(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
// attributes: thunk
DWORD __stdcall __crtTlsAlloc(void (__stdcall *lpCallBack)(void *))
{
  return TlsAlloc();
}

//------------------------------------------------------------------------------
// Address: 0x100400D6
// Name: ___set_flsgetvalue
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__set_flsgetvalue()
{
  void *Value; // esi

  Value = TlsGetValue(dwTlsIndex: __getvalueindex);
  if ( Value == nullptr )
  {
    Value = DecodePointer(Ptr: gpFlsGetValue);
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: Value);
  }
  return Value;
}

//------------------------------------------------------------------------------
// Address: 0x1004010A
// Name: __mtterm
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mtterm()
{
  void (__stdcall *v0)(unsigned int); // eax
  unsigned int v1; // [esp-4h] [ebp-4h]

  if ( __flsindex != -1 )
  {
    v1 = __flsindex;
    v0 = (void (__stdcall *)(unsigned int))DecodePointer(Ptr: gpFlsFree);
    v0(a1: v1);
    __flsindex = -1;
  }
  if ( __getvalueindex != -1 )
  {
    TlsFree(dwTlsIndex: __getvalueindex);
    __getvalueindex = -1;
  }
  _mtdeletelocks();
}

//------------------------------------------------------------------------------
// Address: 0x10040147
// Name: __initptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initptd(_tiddata *ptd, threadlocaleinfostruct *ptloci)
{
  int savedregs; // [esp+28h] [ebp+0h]

  GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  ptd->_pxcptacttab = (void *)_XcptActTab;
  ptd->_terrno = 0;
  ptd->_holdrand = 1;
  ptd->_ownlocale = 1;
  ptd->_setloc_data._cachein[0] = 67;
  ptd->_setloc_data._cacheout[0] = 67;
  ptd->ptmbcinfo = &__initialmbcinfo;
  _lock(locknum: 13);
  InterlockedIncrement(lpAddend: &ptd->ptmbcinfo->refcount);
  _unlock(locknum: 13);
  _lock(locknum: 12);
  ptd->ptlocinfo = ptloci;
  if ( ptloci == nullptr )
    ptd->ptlocinfo = __ptlocinfo;
  __addlocaleref(ptloci: ptd->ptlocinfo);
  savedregs = 268698077;
  _unlock(locknum: 12);
}

//------------------------------------------------------------------------------
// Address: 0x100401FB
// Name: __getptd_noexit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd_noexit()
{
  DWORD LastError; // eax
  DWORD v1; // edi
  int (__stdcall *v2)(unsigned int); // eax
  _tiddata *v3; // esi
  _tiddata *v4; // eax
  int (__stdcall *v5)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v8; // [esp-8h] [ebp-10h]
  unsigned int v9; // [esp-4h] [ebp-Ch]
  _tiddata *v10; // [esp-4h] [ebp-Ch]

  LastError = GetLastError();
  v9 = __flsindex;
  v1 = LastError;
  v2 = (int (__stdcall *)(unsigned int))__set_flsgetvalue();
  v3 = (_tiddata *)v2(a1: v9);
  if ( v3 == nullptr )
  {
    v4 = (_tiddata *)calloc(count: 1u, size: 0x214u);
    v3 = v4;
    if ( v4 != nullptr )
    {
      v10 = v4;
      v8 = __flsindex;
      v5 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
      if ( v5(a1: v8, a2: v10) != 0 )
      {
        _initptd(ptd: v3, ptloci: nullptr);
        CurrentThreadId = GetCurrentThreadId();
        v3->_thandle = -1;
        v3->_tid = CurrentThreadId;
      }
      else
      {
        free(pMem: v3);
        v3 = nullptr;
      }
    }
  }
  SetLastError(dwErrCode: v1);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10040274
// Name: __getptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_tiddata *__cdecl _getptd()
{
  _tiddata *result; // eax

  result = _getptd_noexit();
  if ( result == nullptr )
    _amsg_exit(rterrnum: 16);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004028E
// Name: _freefls(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _freefls(void *data)
{
  threadmbcinfostruct *v1; // edi
  threadlocaleinfostruct *v2; // edi
  int savedregs; // [esp+28h] [ebp+0h]

  if ( data != nullptr )
  {
    if ( *((_DWORD *)data + 9) != 0 )
      free(pMem: *((void **)data + 9));
    if ( *((_DWORD *)data + 11) != 0 )
      free(pMem: *((void **)data + 11));
    if ( *((_DWORD *)data + 13) != 0 )
      free(pMem: *((void **)data + 13));
    if ( *((_DWORD *)data + 15) != 0 )
      free(pMem: *((void **)data + 15));
    if ( *((_DWORD *)data + 16) != 0 )
      free(pMem: *((void **)data + 16));
    if ( *((_DWORD *)data + 17) != 0 )
      free(pMem: *((void **)data + 17));
    if ( *((_DWORD *)data + 18) != 0 )
      free(pMem: *((void **)data + 18));
    if ( *((const _XCPT_ACTION **)data + 23) != _XcptActTab )
      free(pMem: *((void **)data + 23));
    _lock(locknum: 13);
    v1 = *((threadmbcinfostruct **)data + 26);
    if ( v1 != nullptr && InterlockedDecrement(lpAddend: *((volatile LONG **)data + 26)) == 0 && v1 != &__initialmbcinfo )
      free(pMem: v1);
    _unlock(locknum: 13);
    _lock(locknum: 12);
    v2 = *((threadlocaleinfostruct **)data + 27);
    if ( v2 != nullptr )
    {
      __removelocaleref(ptloci: *((threadlocaleinfostruct **)data + 27));
      if ( v2 != __ptlocinfo && v2 != &__initiallocinfo && v2->refcount == 0 )
        __freetlocinfo(ptloci: v2);
    }
    savedregs = 268698518;
    _unlock(locknum: 12);
    free(pMem: data);
  }
}

//------------------------------------------------------------------------------
// Address: 0x100403BD
// Name: __freeptd
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freeptd(_tiddata *ptd)
{
  int (__stdcall *Value)(unsigned int); // eax
  void (__stdcall *v2)(unsigned int, _DWORD); // eax
  unsigned int v3; // [esp-8h] [ebp-8h]
  unsigned int v4; // [esp-8h] [ebp-8h]

  if ( __flsindex != -1 )
  {
    if ( ptd == nullptr && TlsGetValue(dwTlsIndex: __getvalueindex) != nullptr )
    {
      v3 = __flsindex;
      Value = (int (__stdcall *)(unsigned int))TlsGetValue(dwTlsIndex: __getvalueindex);
      ptd = (_tiddata *)Value(a1: v3);
    }
    v4 = __flsindex;
    v2 = (void (__stdcall *)(unsigned int, _DWORD))DecodePointer(Ptr: gpFlsSetValue);
    v2(a1: v4, a2: 0);
    _freefls(data: ptd);
  }
  if ( __getvalueindex != -1 )
    TlsSetValue(dwTlsIndex: __getvalueindex, lpTlsValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x1004042B
// Name: __mtinit
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mtinit()
{
  HMODULE ModuleHandleW; // eax
  HMODULE v1; // edi
  BOOL (__stdcall *FlsFree)(DWORD); // eax
  DWORD v4; // eax
  int (__stdcall *v5)(_DWORD); // eax
  _tiddata *v6; // eax
  _tiddata *v7; // esi
  int (__stdcall *v8)(unsigned int, _tiddata *); // eax
  DWORD CurrentThreadId; // eax
  unsigned int v10; // [esp-Ch] [ebp-10h]
  _tiddata *v11; // [esp-8h] [ebp-Ch]

  ModuleHandleW = GetModuleHandleW(lpModuleName: L"KERNEL32.DLL");
  v1 = ModuleHandleW;
  if ( ModuleHandleW == nullptr )
  {
    _mtterm();
    return 0;
  }
  gpFlsAlloc = GetProcAddress(hModule: ModuleHandleW, lpProcName: "FlsAlloc");
  gpFlsGetValue = GetProcAddress(hModule: v1, lpProcName: "FlsGetValue");
  gpFlsSetValue = GetProcAddress(hModule: v1, lpProcName: "FlsSetValue");
  FlsFree = (BOOL (__stdcall *)(DWORD))GetProcAddress(hModule: v1, lpProcName: "FlsFree");
  gpFlsFree = FlsFree;
  if ( gpFlsAlloc == nullptr || gpFlsGetValue == nullptr || gpFlsSetValue == nullptr || FlsFree == nullptr )
  {
    gpFlsGetValue = TlsGetValue;
    gpFlsAlloc = __crtTlsAlloc;
    gpFlsSetValue = TlsSetValue;
    gpFlsFree = TlsFree;
  }
  v4 = TlsAlloc();
  __getvalueindex = v4;
  if ( v4 != -1 && TlsSetValue(dwTlsIndex: v4, lpTlsValue: gpFlsGetValue) )
  {
    _init_pointers();
    gpFlsAlloc = EncodePointer(Ptr: gpFlsAlloc);
    gpFlsGetValue = EncodePointer(Ptr: gpFlsGetValue);
    gpFlsSetValue = EncodePointer(Ptr: gpFlsSetValue);
    gpFlsFree = EncodePointer(Ptr: gpFlsFree);
    if ( _mtinitlocks() != 0 )
    {
      v5 = (int (__stdcall *)(_DWORD))DecodePointer(Ptr: gpFlsAlloc);
      __flsindex = v5(a1: _freefls);
      if ( __flsindex != -1 )
      {
        v6 = (_tiddata *)calloc(count: 1u, size: 0x214u);
        v7 = v6;
        if ( v6 != nullptr )
        {
          v11 = v6;
          v10 = __flsindex;
          v8 = (int (__stdcall *)(unsigned int, _tiddata *))DecodePointer(Ptr: gpFlsSetValue);
          if ( v8(a1: v10, a2: v11) != 0 )
          {
            _initptd(ptd: v7, ptloci: nullptr);
            CurrentThreadId = GetCurrentThreadId();
            v7->_thandle = -1;
            v7->_tid = CurrentThreadId;
            return 1;
          }
        }
      }
    }
    _mtterm();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x100405A6
// Name: __isctype_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _isctype_l(int c, int mask, localeinfo_struct *plocinfo)
{
  __int16 v3; // bx
  int v4; // eax
  int v5; // ecx
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  char buffer[4]; // [esp+14h] [ebp-8h] BYREF
  unsigned __int16 chartype; // [esp+18h] [ebp-4h] BYREF
  int ca; // [esp+24h] [ebp+8h]

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  v3 = c;
  if ( (unsigned int)(c + 1) <= 0x100 )
  {
    v4 = _loc_update.localeinfo.locinfo->pctype[c];
    goto LABEL_11;
  }
  ca = c >> 8;
  if ( _isleadbyte_l(c: HIBYTE(v3), plocinfo: &_loc_update.localeinfo) != 0 )
  {
    buffer[0] = ca;
    buffer[1] = v3;
    buffer[2] = 0;
    v5 = 2;
  }
  else
  {
    buffer[0] = v3;
    buffer[1] = 0;
    v5 = 1;
  }
  if ( __crtGetStringTypeA(
         plocinfo: &_loc_update.localeinfo,
         dwInfoType: 1u,
         lpSrcStr: buffer,
         cchSrc: v5,
         lpCharType: &chartype,
         code_page: _loc_update.localeinfo.locinfo->lc_codepage,
         lcid: _loc_update.localeinfo.locinfo->lc_handle[2],
         bError: 1) != 0 )
  {
    v4 = chartype;
LABEL_11:
    result = mask & v4;
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10040690
// Name: ___TypeMatch
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl __TypeMatch(const _s_HandlerType *pCatch, const _s_CatchableType *pCatchable, const _s_ThrowInfo *pThrow)
{
  TypeDescriptor *pType; // eax
  TypeDescriptor *v4; // ecx
  int v5; // eax
  BOOL result; // eax

  pType = pCatch->pType;
  result = true;
  if ( pType != nullptr && pType->name[0] != 0 )
  {
    v4 = pCatchable->pType;
    if ( pType != v4 )
    {
      strcmp(str1: (unsigned __int8 *)pType->name, str2: (unsigned __int8 *)v4->name);
      if ( v5 != 0 )
        return false;
    }
    if ( (pCatchable->properties & 2) != 0 && (pCatch->adjectives & 8) == 0
      || (pThrow->attributes & 1) != 0 && (pCatch->adjectives & 1) == 0
      || (pThrow->attributes & 2) != 0 && (pCatch->adjectives & 2) == 0 )
    {
      return false;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100406EF
// Name: ___FrameUnwindFilter
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __FrameUnwindFilter(_EXCEPTION_POINTERS *pExPtrs)
{
  unsigned int ExceptionCode; // eax
  _tiddata *v2; // eax

  ExceptionCode = pExPtrs->ExceptionRecord->ExceptionCode;
  if ( ExceptionCode == -532462766 || ExceptionCode == -532459699 )
  {
    if ( _getptd()->_ProcessingThrow > 0 )
    {
      v2 = _getptd();
      --v2->_ProcessingThrow;
    }
  }
  else if ( ExceptionCode == -529697949 )
  {
    _getptd()->_ProcessingThrow = 0;
    terminate();
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x1004073E
// Name: ___FrameUnwindToState
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __FrameUnwindToState(EHRegistrationNode *pRN, void *pDC, const _s_FuncInfo *pFuncInfo, int targetState)
{
  int state; // esi
  _tiddata *v5; // eax
  int v6; // eax
  const _s_UnwindMapEntry *pUnwindMap; // ecx
  _tiddata *v8; // eax

  if ( pFuncInfo->maxState > 128 )
    state = pRN->state;
  else
    state = SLOBYTE(pRN->state);
  v5 = _getptd();
  ++v5->_ProcessingThrow;
  while ( state != targetState )
  {
    if ( state <= -1 || state >= pFuncInfo->maxState )
      _inconsistency();
    v6 = state;
    pUnwindMap = pFuncInfo->pUnwindMap;
    state = pUnwindMap[state].toState;
    if ( pUnwindMap[v6].action != nullptr )
    {
      pRN->state = state;
      _CallSettingFrame(funclet: (unsigned int)pFuncInfo->pUnwindMap[v6].action, (unsigned int)pRN, dwInCode: 0x103u);
    }
  }
  if ( _getptd()->_ProcessingThrow > 0 )
  {
    v8 = _getptd();
    --v8->_ProcessingThrow;
  }
  if ( state != targetState )
    _inconsistency();
  pRN->state = state;
}

//------------------------------------------------------------------------------
// Address: 0x1004081A
// Name: ExFilterRethrow
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall ExFilterRethrow@<eax>(_EXCEPTION_POINTERS *pExPtrs@<eax>)
{
  _EXCEPTION_RECORD *ExceptionRecord; // eax
  unsigned int v2; // ecx

  ExceptionRecord = pExPtrs->ExceptionRecord;
  if ( ExceptionRecord->ExceptionCode != -529697949 )
    return 0;
  if ( ExceptionRecord->NumberParameters != 3 )
    return 0;
  v2 = ExceptionRecord->ExceptionInformation[0];
  if ( v2 != 429065504 && v2 != 429065505 && v2 != 429065506 )
    return 0;
  if ( ExceptionRecord->ExceptionInformation[2] != 0 )
    return 0;
  _getptd()->_cxxReThrow = 1;
  return 1;
}

//------------------------------------------------------------------------------
// Address: 0x1004085F
// Name: ___DestructExceptionObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __DestructExceptionObject(EHExceptionRecord *pExcept)
{
  const _s_ThrowInfo *pThrowInfo; // eax
  void (__cdecl *pmfnUnwind)(); // eax
  void *v3; // [esp+0h] [ebp-28h]
  int v4; // [esp+4h] [ebp-24h]

  if ( pExcept != nullptr && pExcept->ExceptionCode == -529697949 )
  {
    pThrowInfo = pExcept->params.pThrowInfo;
    if ( pThrowInfo != nullptr )
    {
      pmfnUnwind = pThrowInfo->pmfnUnwind;
      if ( pmfnUnwind != nullptr )
        _CallMemberFunction1(pthis: pExcept->params.pExceptionObject, pmfn: pmfnUnwind, pthat: v3, val2: v4);
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x100408B4
// Name: ___AdjustPointer
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl __AdjustPointer(char *pThis, const PMD *pmd)
{
  char *result; // eax

  result = &pThis[pmd->mdisp];
  if ( pmd->pdisp >= 0 )
    result += pmd->pdisp + *(_DWORD *)(*(_DWORD *)&pThis[pmd->pdisp] + pmd->vdisp);
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100408DD
// Name: IsInExceptionSpec
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned __int8 __usercall IsInExceptionSpec@<al>(const _s_ESTypeList *pESTypeList@<edi>, EHExceptionRecord *pExcept)
{
  const _s_CatchableTypeArray *pCatchableTypeArray; // eax
  int nCatchableTypes; // ebx
  const _s_CatchableType **arrayOfCatchableTypes; // esi
  int i; // [esp+0h] [ebp-Ch]
  int v7; // [esp+4h] [ebp-8h]
  unsigned __int8 bFoundMatchingTypeInES; // [esp+Bh] [ebp-1h]

  if ( pESTypeList == nullptr )
    _inconsistency();
  bFoundMatchingTypeInES = 0;
  i = 0;
  if ( pESTypeList->nCount > 0 )
  {
    v7 = 0;
    do
    {
      pCatchableTypeArray = pExcept->params.pThrowInfo->pCatchableTypeArray;
      nCatchableTypes = pCatchableTypeArray->nCatchableTypes;
      arrayOfCatchableTypes = pCatchableTypeArray->arrayOfCatchableTypes;
      while ( nCatchableTypes > 0 )
      {
        if ( __TypeMatch(
               pCatch: &pESTypeList->pTypeArray[v7],
               pCatchable: *arrayOfCatchableTypes,
               pThrow: pExcept->params.pThrowInfo) )
        {
          bFoundMatchingTypeInES = 1;
          break;
        }
        --nCatchableTypes;
        ++arrayOfCatchableTypes;
      }
      ++i;
      ++v7;
    }
    while ( i < pESTypeList->nCount );
  }
  return bFoundMatchingTypeInES;
}

//------------------------------------------------------------------------------
// Address: 0x1004099C
// Name: CallCatchBlock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void *__cdecl CallCatchBlock(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        const _s_FuncInfo *pFuncInfo,
        int CatchDepth,
        unsigned int NLGCode)
{
  void *handlerAddress; // ecx
  void *v7; // ebx
  void *v8; // eax
  unsigned int magicNumber; // eax
  FrameInfo FrameInfo; // [esp+10h] [ebp-3Ch] BYREF
  int ExceptionObjectDestroyed; // [esp+18h] [ebp-34h]
  _CONTEXT *pSaveExContext; // [esp+1Ch] [ebp-30h]
  EHExceptionRecord *pSaveException; // [esp+20h] [ebp-2Ch]
  FrameInfo *pFrameInfo; // [esp+24h] [ebp-28h]
  void *saveESP; // [esp+28h] [ebp-24h]
  void *continuationAddress; // [esp+30h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+34h] [ebp-18h]

  v7 = handlerAddress;
  continuationAddress = handlerAddress;
  ExceptionObjectDestroyed = 0;
  saveESP = (void *)pRN[-1].state;
  pFrameInfo = _CreateFrameInfo(pFrameInfo: &FrameInfo, pExceptionObject: pExcept->params.pExceptionObject);
  pSaveException = (EHExceptionRecord *)_getptd()->_curexception;
  pSaveExContext = (_CONTEXT *)_getptd()->_curcontext;
  _getptd()->_curexception = pExcept;
  _getptd()->_curcontext = pContext;
  ms_exc.registration.TryLevel = 1;
  _CallCatchBlock2(pRN, pFuncInfo, handlerAddress: v7, CatchDepth, NLGCode);
  continuationAddress = v8;
  ms_exc.registration.TryLevel = -2;
  pRN[-1].state = (int)saveESP;
  _FindAndUnlinkFrame(pFrameInfo);
  _getptd()->_curexception = pSaveException;
  _getptd()->_curcontext = pSaveExContext;
  if ( pExcept->ExceptionCode == -529697949 && pExcept->NumberParameters == 3 )
  {
    magicNumber = pExcept->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505 || magicNumber == 429065506)
      && ExceptionObjectDestroyed == 0
      && continuationAddress != nullptr
      && _IsExceptionObjectToBeDestroyed(pExceptionObject: pExcept->params.pExceptionObject) != 0 )
    {
      __DestructExceptionObject(pExcept);
    }
  }
  return continuationAddress;
}

//------------------------------------------------------------------------------
// Address: 0x10040B38
// Name: ___BuildCatchObjectHelper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __BuildCatchObjectHelper(
        EHExceptionRecord *pExcept,
        int (__stdcall *pRN)(),
        const _s_HandlerType *pCatch,
        const _s_CatchableType *pConv)
{
  TypeDescriptor *pType; // ecx
  int dispCatchObj; // ecx
  int (__stdcall *v6)(); // esi
  char *pExceptionObject; // eax
  char *v8; // eax
  unsigned __int8 *v9; // eax
  int (__stdcall *v11)(); // [esp-8h] [ebp-34h]
  unsigned int sizeOrOffset; // [esp-4h] [ebp-30h]
  int retval; // [esp+10h] [ebp-1Ch]

  retval = 0;
  pType = pCatch->pType;
  if ( pType != nullptr && pType->name[0] != 0 )
  {
    dispCatchObj = pCatch->dispCatchObj;
    if ( dispCatchObj != 0 || (pCatch->adjectives & 0x80000000) != 0 )
    {
      v6 = pRN;
      if ( (pCatch->adjectives & 0x80000000) == 0 )
        v6 = (int (__stdcall *)())((char *)pRN + dispCatchObj + 12);
      if ( (pCatch->adjectives & 8) != 0 )
      {
        if ( _ValidateRead(code: (int (__stdcall *)())pExcept->params.pExceptionObject) != 0
          && _ValidateRead(code: v6) != 0 )
        {
          pExceptionObject = (char *)pExcept->params.pExceptionObject;
          *(_DWORD *)v6 = pExceptionObject;
          v8 = __AdjustPointer(pThis: pExceptionObject, pmd: &pConv->thisDisplacement);
LABEL_11:
          *(_DWORD *)v6 = v8;
          return retval;
        }
      }
      else
      {
        v11 = (int (__stdcall *)())pExcept->params.pExceptionObject;
        if ( (pConv->properties & 1) != 0 )
        {
          if ( _ValidateRead(code: v11) != 0 && _ValidateRead(code: v6) != 0 )
          {
            memmove(
              dst: (unsigned __int8 *)v6,
              src: (unsigned __int8 *)pExcept->params.pExceptionObject,
              count: pConv->sizeOrOffset);
            if ( pConv->sizeOrOffset != 4 || *(_DWORD *)v6 == 0 )
              return retval;
            v8 = __AdjustPointer(pThis: *(char **)v6, pmd: &pConv->thisDisplacement);
            goto LABEL_11;
          }
        }
        else if ( pConv->copyFunction != nullptr )
        {
          if ( _ValidateRead(code: v11) != 0
            && _ValidateRead(code: v6) != 0
            && _ValidateRead(code: (int (__stdcall *)())pConv->copyFunction) != 0 )
          {
            return ((pConv->properties & 4) != 0) + 1;
          }
        }
        else if ( _ValidateRead(code: v11) != 0 && _ValidateRead(code: v6) != 0 )
        {
          sizeOrOffset = pConv->sizeOrOffset;
          v9 = (unsigned __int8 *)__AdjustPointer(
                                    pThis: (char *)pExcept->params.pExceptionObject,
                                    pmd: &pConv->thisDisplacement);
          memmove(dst: (unsigned __int8 *)v6, src: v9, count: sizeOrOffset);
          return retval;
        }
      }
      _inconsistency();
    }
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10040CB7
// Name: ___BuildCatchObject
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __BuildCatchObject(
        EHExceptionRecord *pExcept,
        int (__stdcall *pRN)(),
        const _s_HandlerType *pCatch,
        const _s_CatchableType *pConv)
{
  int (__stdcall *v4)(); // ebx
  int v5; // eax
  char *v6; // eax
  char *v7; // eax
  int v8; // [esp+0h] [ebp-28h]

  if ( (pCatch->adjectives & 0x80000000) == 0 )
    v4 = (int (__stdcall *)())((char *)pRN + pCatch->dispCatchObj + 12);
  else
    v4 = pRN;
  v5 = __BuildCatchObjectHelper(pExcept, pRN, pCatch, pConv) - 1;
  if ( v5 != 0 )
  {
    if ( v5 == 1 )
    {
      v6 = __AdjustPointer(pThis: (char *)pExcept->params.pExceptionObject, pmd: &pConv->thisDisplacement);
      _CallMemberFunction1(pthis: v4, pmfn: pConv->copyFunction, pthat: v6, val2: 1);
    }
  }
  else
  {
    v7 = __AdjustPointer(pThis: (char *)pExcept->params.pExceptionObject, pmd: &pConv->thisDisplacement);
    _CallMemberFunction1(pthis: v4, pmfn: pConv->copyFunction, pthat: v7, val2: v8);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040D49
// Name: CatchIt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __usercall CatchIt(
        EHRegistrationNode *pRN@<esi>,
        const _s_HandlerType *pCatch@<ebx>,
        const _s_TryBlockMapEntry *pEntry@<edi>,
        EHExceptionRecord *pExcept,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        const _s_CatchableType *pConv,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  void *v10; // eax

  if ( pConv != nullptr )
    __BuildCatchObject(pExcept, (int (__stdcall *)())pRN, pCatch, pConv);
  if ( pMarkerRN != nullptr )
    _UnwindNestedFrames(pRN: pMarkerRN, pExcept);
  else
    _UnwindNestedFrames(pRN, pExcept);
  __FrameUnwindToState(pRN, pDC, pFuncInfo, targetState: pEntry->tryLow);
  pRN->state = pEntry->tryHigh + 1;
  v10 = CallCatchBlock(pExcept, pRN, pContext, pFuncInfo, CatchDepth, NLGCode: 0x100u);
  if ( v10 != nullptr )
    _JumpToContinuation(target: v10, pRN);
}

//------------------------------------------------------------------------------
// Address: 0x10040DB7
// Name: FindHandlerForForeignException
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl FindHandlerForForeignException(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        int curState,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  void **p_translator; // edi
  int v9; // esi
  const _s_TryBlockMapEntry *v10; // eax
  int *p_nCatches; // eax
  int v12; // ecx
  int v13; // edx
  unsigned int end; // [esp+4h] [ebp-Ch] BYREF
  int *v15; // [esp+8h] [ebp-8h]
  unsigned int curTry; // [esp+Ch] [ebp-4h] BYREF

  if ( pExcept->ExceptionCode != -2147483645
    && (_getptd()->_translator == nullptr
     || *(p_translator = &_getptd()->_translator) == _encoded_null()
     || pExcept->ExceptionCode == -532459699
     || pExcept->ExceptionCode == -532462766
     || _CallSETranslator(pExcept, pRN, pContext, pDC, pFuncInfo, CatchDepth, pMarkerRN) == 0) )
  {
    if ( pFuncInfo->nTryBlocks == 0 )
      _inconsistency();
    v9 = curState;
    v10 = _GetRangeOfTrysToCheck(pFuncInfo, CatchDepth, curState, pStart: &curTry, pEnd: &end);
    if ( curTry < end )
    {
      p_nCatches = &v10->nCatches;
      v15 = p_nCatches;
      do
      {
        if ( v9 >= *(p_nCatches - 3) && v9 <= *(p_nCatches - 2) )
        {
          v12 = p_nCatches[1] + 16 * *p_nCatches;
          v13 = *(_DWORD *)(v12 - 12);
          if ( (v13 == 0 || *(_BYTE *)(v13 + 8) == 0) && (*(_BYTE *)(v12 - 16) & 0x40) == 0 )
          {
            CatchIt(
              pRN,
              pCatch: (const _s_HandlerType *)(v12 - 16),
              pEntry: (const _s_TryBlockMapEntry *)(p_nCatches - 3),
              pExcept,
              pContext,
              pDC,
              pFuncInfo,
              pConv: nullptr,
              CatchDepth,
              pMarkerRN);
            v9 = curState;
            p_nCatches = v15;
          }
        }
        ++curTry;
        p_nCatches += 5;
        v15 = p_nCatches;
      }
      while ( curTry < end );
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x10040EBE
// Name: FindHandler
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl FindHandler(
        EHExceptionRecord *pExcept,
        EHRegistrationNode *pRN,
        _CONTEXT *pContext,
        void *pDC,
        const _s_FuncInfo *pFuncInfo,
        unsigned __int8 recursive,
        int CatchDepth,
        EHRegistrationNode *pMarkerRN)
{
  const _s_FuncInfo *v8; // ebx
  int maxState; // eax
  int state; // ecx
  EHExceptionRecord *curexception; // esi
  unsigned int magicNumber; // eax
  unsigned int v13; // eax
  const _s_ESTypeList *curexcspec; // edi
  _tiddata *v15; // eax
  int v16; // esi
  int v17; // ebx
  unsigned int v18; // eax
  const _s_FuncInfo *v19; // edi
  const _s_TryBlockMapEntry *v20; // eax
  const _s_HandlerType **p_pHandlerArray; // edi
  int *p_nCatchableTypes; // eax
  const _s_CatchableType **v23; // ebx
  const _s_ESTypeList *pESTypeList; // edi
  _tiddata *v25; // eax
  bool v26; // zf
  const _s_FuncInfo *v27; // esi
  EHExceptionRecord *v28; // [esp-4h] [ebp-44h]
  const _s_ThrowInfo *pThrowInfo; // [esp-4h] [ebp-44h]
  std::exception pExceptionObject; // [esp+Ch] [ebp-34h] BYREF
  _s_TryBlockMapEntry *pEntry; // [esp+18h] [ebp-28h]
  const _s_CatchableType *pCatchable; // [esp+1Ch] [ebp-24h]
  unsigned int end; // [esp+20h] [ebp-20h] BYREF
  const _s_HandlerType **v34; // [esp+24h] [ebp-1Ch]
  int catches; // [esp+28h] [ebp-18h]
  int catchables; // [esp+2Ch] [ebp-14h]
  unsigned int curTry; // [esp+30h] [ebp-10h] BYREF
  const _s_HandlerType *pCatch; // [esp+34h] [ebp-Ch]
  int curState; // [esp+38h] [ebp-8h]
  unsigned __int8 gotMatch; // [esp+3Fh] [ebp-1h]

  v8 = pFuncInfo;
  maxState = pFuncInfo->maxState;
  gotMatch = 0;
  if ( maxState > 128 )
    state = pRN->state;
  else
    state = SLOBYTE(pRN->state);
  curState = state;
  if ( state < -1 || state >= maxState )
    _inconsistency();
  curexception = pExcept;
  if ( pExcept->ExceptionCode != -529697949 )
  {
LABEL_61:
    if ( v8->nTryBlocks != 0 )
    {
      if ( recursive != 0 )
        goto LABEL_28;
      FindHandlerForForeignException(
        pExcept: curexception,
        pRN,
        pContext,
        pDC,
        pFuncInfo: v8,
        curState,
        CatchDepth,
        pMarkerRN);
    }
    goto LABEL_64;
  }
  if ( pExcept->NumberParameters == 3 )
  {
    magicNumber = pExcept->params.magicNumber;
    if ( (magicNumber == 429065504 || magicNumber == 429065505 || magicNumber == 429065506)
      && pExcept->params.pThrowInfo == nullptr )
    {
      if ( _getptd()->_curexception == nullptr )
        return;
      curexception = (EHExceptionRecord *)_getptd()->_curexception;
      pExcept = curexception;
      pContext = (_CONTEXT *)_getptd()->_curcontext;
      if ( _ValidateRead(code: (int (__stdcall *)())curexception) == 0 )
        _inconsistency();
      if ( curexception->ExceptionCode == -529697949 && curexception->NumberParameters == 3 )
      {
        v13 = curexception->params.magicNumber;
        if ( (v13 == 429065504 || v13 == 429065505 || v13 == 429065506) && curexception->params.pThrowInfo == nullptr )
          _inconsistency();
      }
      if ( _getptd()->_curexcspec != nullptr )
      {
        curexcspec = (const _s_ESTypeList *)_getptd()->_curexcspec;
        v15 = _getptd();
        v28 = pExcept;
        v16 = 0;
        v15->_curexcspec = nullptr;
        if ( IsInExceptionSpec(pESTypeList: curexcspec, pExcept: v28) == 0 )
        {
          v17 = 0;
          if ( curexcspec->nCount > 0 )
          {
            do
            {
              if ( type_info::operator==(
                     this: (type_info *)curexcspec->pTypeArray[v17].pType,
                     rhs: &std::bad_exception `RTTI Type Descriptor') )
              {
                __DestructExceptionObject(pExcept);
                pExcept = (EHExceptionRecord *)"bad exception";
                std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&pExcept);
                pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_exception::`vftable';
                _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_exception_std__);
              }
              ++v16;
              ++v17;
            }
            while ( v16 < curexcspec->nCount );
          }
LABEL_28:
          terminate();
        }
        curexception = pExcept;
      }
    }
  }
  if ( curexception->ExceptionCode != -529697949
    || curexception->NumberParameters != 3
    || (v18 = curexception->params.magicNumber) != 429065504 && v18 != 429065505 && v18 != 429065506 )
  {
    v8 = pFuncInfo;
    goto LABEL_61;
  }
  v19 = pFuncInfo;
  if ( pFuncInfo->nTryBlocks != 0 )
  {
    v20 = _GetRangeOfTrysToCheck(pFuncInfo, CatchDepth, curState, pStart: &curTry, pEnd: &end);
    if ( curTry < end )
    {
      p_pHandlerArray = &v20->pHandlerArray;
      v34 = &v20->pHandlerArray;
      do
      {
        pEntry = (_s_TryBlockMapEntry *)(p_pHandlerArray - 4);
        if ( (int)*(p_pHandlerArray - 4) <= curState && curState <= (int)*(p_pHandlerArray - 3) )
        {
          pCatch = *p_pHandlerArray;
          catches = (int)*(p_pHandlerArray - 1);
          if ( catches > 0 )
          {
            while ( 1 )
            {
              p_nCatchableTypes = &curexception->params.pThrowInfo->pCatchableTypeArray->nCatchableTypes;
              v23 = (const _s_CatchableType **)(p_nCatchableTypes + 1);
              catchables = *p_nCatchableTypes;
              if ( catchables > 0 )
                break;
LABEL_45:
              --catches;
              ++pCatch;
              if ( catches <= 0 )
                goto NextTryBlock;
            }
            while ( 1 )
            {
              pThrowInfo = curexception->params.pThrowInfo;
              pCatchable = *v23;
              if ( __TypeMatch(pCatch, pCatchable, pThrow: pThrowInfo) )
                break;
              --catchables;
              ++v23;
              if ( catchables <= 0 )
                goto LABEL_45;
            }
            gotMatch = 1;
            CatchIt(
              pRN,
              pCatch,
              pEntry,
              pExcept: curexception,
              pContext,
              pDC,
              pFuncInfo,
              pConv: pCatchable,
              CatchDepth,
              pMarkerRN);
            curexception = pExcept;
            p_pHandlerArray = v34;
          }
        }
NextTryBlock:
        ++curTry;
        p_pHandlerArray += 5;
        v34 = p_pHandlerArray;
      }
      while ( curTry < end );
      v19 = pFuncInfo;
    }
  }
  if ( recursive != 0 )
    __DestructExceptionObject(pExcept: curexception);
  if ( gotMatch == 0 && (*(_DWORD *)v19 & 0x1FFFFFFFu) >= 0x19930521 )
  {
    pESTypeList = v19->pESTypeList;
    if ( pESTypeList != nullptr && IsInExceptionSpec(pESTypeList, pExcept: curexception) == 0 )
    {
      _getptd();
      _getptd();
      _getptd()->_curexception = curexception;
      v25 = _getptd();
      v26 = pMarkerRN == nullptr;
      v25->_curcontext = pContext;
      if ( v26 )
        _UnwindNestedFrames(pRN, pExcept: curexception);
      else
        _UnwindNestedFrames(pRN: pMarkerRN, pExcept: curexception);
      v27 = pFuncInfo;
      __FrameUnwindToState(pRN, pDC, pFuncInfo, targetState: -1);
      CallUnexpected(pESTypeList: v27->pESTypeList);
    }
  }
LABEL_64:
  if ( _getptd()->_curexcspec != nullptr )
    _inconsistency();
}

//------------------------------------------------------------------------------
// Address: 0x10041336
// Name: __security_check_cookie(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall __security_check_cookie(unsigned int cookie)
{
  if ( cookie != __security_cookie )
    __report_gsfailure();
}

//------------------------------------------------------------------------------
// Address: 0x10041345
// Name: void terminate(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn terminate()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_terminate;
  if ( v0 != nullptr )
    v0();
  abort();
}

//------------------------------------------------------------------------------
// Address: 0x1004137E
// Name: void unexpected(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn unexpected()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))_getptd()->_unexpected;
  if ( v0 != nullptr )
    v0();
  terminate();
}

//------------------------------------------------------------------------------
// Address: 0x10041391
// Name: void _inconsistency(void)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl __noreturn _inconsistency()
{
  void (*v0)(void); // eax

  v0 = (void (*)(void))DecodePointer(Ptr: __pInconsistency);
  if ( v0 != nullptr )
    v0();
  terminate();
}

//------------------------------------------------------------------------------
// Address: 0x100413C9
// Name: __initp_eh_hooks
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_eh_hooks()
{
  __pInconsistency = EncodePointer(Ptr: terminate);
}

//------------------------------------------------------------------------------
// Address: 0x100413E0
// Name: _CallSettingFrame(x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _CallSettingFrame(unsigned int funclet, unsigned int pRN, unsigned int dwInCode)
{
  void (*v3)(void); // eax
  unsigned int v4; // ecx

  v3 = (void (*)(void))_NLG_Notify1(a1: dwInCode);
  v3();
  v4 = dwInCode;
  if ( dwInCode == 256 )
    v4 = 2;
  _NLG_Notify1(a1: v4);
}

//------------------------------------------------------------------------------
// Address: 0x1004142C
// Name: __flsbuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _flsbuf(unsigned __int8 ch, int str)
{
  _iobuf *v2; // esi
  int flag; // eax
  unsigned int v5; // eax
  char *base; // eax
  char *ptr; // edi
  signed int v8; // edi
  ioinfo *v9; // eax
  __int64 v10; // rax
  int written; // [esp+4h] [ebp-4h]

  v2 = (_iobuf *)str;
  str = _fileno(stream: (_iobuf *)str);
  flag = v2->_flag;
  if ( (flag & 0x82) == 0 )
  {
    *_errno() = 9;
LABEL_3:
    v2->_flag |= 0x20u;
    return -1;
  }
  if ( (flag & 0x40) != 0 )
  {
    *_errno() = 34;
    goto LABEL_3;
  }
  if ( (flag & 1) != 0 )
  {
    v2->_cnt = 0;
    if ( (flag & 0x10) == 0 )
    {
      v2->_flag = flag | 0x20;
      return -1;
    }
    v2->_ptr = v2->_base;
    v2->_flag = flag & 0xFFFFFFFE;
  }
  v5 = v2->_flag & 0xFFFFFFED | 2;
  v2->_flag = v5;
  v2->_cnt = 0;
  written = 0;
  if ( (v5 & 0x10C) == 0 && (v2 != &__iob_func()[1] && v2 != &__iob_func()[2] || _isatty(fh: str) == 0) )
    _getbuf(str: v2);
  if ( (v2->_flag & 0x108) != 0 )
  {
    base = v2->_base;
    ptr = v2->_ptr;
    v2->_ptr = base + 1;
    v8 = ptr - base;
    v2->_cnt = v2->_bufsiz - 1;
    if ( v8 <= 0 )
    {
      if ( str == -1 || str == -2 )
        v9 = &__badioinfo;
      else
        v9 = &__pioinfo[str >> 5][str & 0x1F];
      if ( (v9->osfile & 0x20) != 0 )
      {
        v10 = _lseeki64(fh: str, pos: 0, mthd: 2);
        if ( (HIDWORD(v10) & (unsigned int)v10) == 0xFFFFFFFF )
          goto LABEL_27;
      }
    }
    else
    {
      written = _write(fh: str, buf: base, cnt: v8);
    }
    *v2->_base = ch;
  }
  else
  {
    v8 = 1;
    written = _write(fh: str, buf: &ch, cnt: 1u);
  }
  if ( written != v8 )
  {
LABEL_27:
    v2->_flag |= 0x20u;
    return -1;
  }
  return ch;
}

//------------------------------------------------------------------------------
// Address: 0x10041590
// Name: __vsnprintf_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsnprintf_helper(
        int (__cdecl *outfn)(_iobuf *, const char *, localeinfo_struct *, char *),
        char *string,
        unsigned int count,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax
  bool v7; // sf
  _iobuf str; // [esp+8h] [ebp-20h] BYREF
  int retval; // [esp+3Ch] [ebp+14h]

  memset(&str, 0, sizeof(str));
  if ( format == nullptr || count != 0 && string == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  str._cnt = 0x7FFFFFFF;
  if ( count <= 0x7FFFFFFF )
    str._cnt = count;
  str._flag = 66;
  str._base = string;
  str._ptr = string;
  result = outfn(a1: &str, a2: format, a3: plocinfo, a4: ap);
  retval = result;
  if ( string != nullptr )
  {
    if ( result >= 0 )
    {
      if ( --str._cnt >= 0 )
      {
        *str._ptr = 0;
        return retval;
      }
      if ( _flsbuf(ch: 0, (int)&str) != -1 )
        return retval;
    }
    v7 = str._cnt < 0;
    string[count - 1] = 0;
    return !v7 - 2;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004165A
// Name: __vsprintf_s_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _vsprintf_s_l(
        char *string,
        unsigned int sizeInBytes,
        const char *format,
        localeinfo_struct *plocinfo,
        char *ap)
{
  int result; // eax

  if ( format == nullptr )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( string == nullptr || sizeInBytes == 0 )
  {
    *_errno() = 22;
LABEL_10:
    _invalid_parameter_noinfo();
    return -1;
  }
  result = _vsnprintf_helper(outfn: _output_s_l, string, count: sizeInBytes, format, plocinfo, ap);
  if ( result < 0 )
    *string = 0;
  if ( result == -2 )
  {
    *_errno() = 34;
    goto LABEL_10;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100416D1
// Name: __VEC_memzero
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__fastcall _VEC_memzero(_BYTE *a1, unsigned int a2)
{
  int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  char *result; // eax
  unsigned int v6; // edx
  char v7; // al
  unsigned int k; // edx
  int i; // edx
  unsigned int j; // ebx
  unsigned int v11; // [esp-4h] [ebp-Ch]

  v2 = (unsigned __int8)a1 & 0xF;
  if ( ((unsigned __int8)a1 & 0xF) != 0 )
  {
    v11 = a2 - (16 - v2);
    for ( i = (16 - (_BYTE)v2) & 3; i != 0; --i )
      *a1++ = 0;
    for ( j = (unsigned int)(16 - v2) >> 2; j != 0; --j )
    {
      *(_DWORD *)a1 = 0;
      a1 += 4;
    }
    a2 = v11;
  }
  v3 = a2;
  v4 = a2 & 0x7F;
  for ( result = (char *)(v3 >> 7); result != nullptr; --result )
  {
    *(_OWORD *)a1 = 0;
    *((_OWORD *)a1 + 1) = 0;
    *((_OWORD *)a1 + 2) = 0;
    *((_OWORD *)a1 + 3) = 0;
    *((_OWORD *)a1 + 4) = 0;
    *((_OWORD *)a1 + 5) = 0;
    *((_OWORD *)a1 + 6) = 0;
    *((_OWORD *)a1 + 7) = 0;
    a1 += 128;
  }
  if ( v4 != 0 )
  {
    result = (char *)(v4 >> 4);
    if ( v4 >> 4 != 0 )
    {
      do
      {
        *(_OWORD *)a1 = 0;
        a1 += 16;
        --result;
      }
      while ( result != nullptr );
    }
    v6 = v4 & 0xF;
    if ( v6 != 0 )
    {
      v7 = v6;
      for ( k = v6 >> 2; k != 0; --k )
      {
        *(_DWORD *)a1 = 0;
        a1 += 4;
      }
      for ( result = (char *)(v7 & 3); result != nullptr; --result )
        *a1++ = 0;
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1004178B
// Name: __fullpath
// Source: linker_block_proximity
//------------------------------------------------------------------------------
char *__cdecl _fullpath(char *UserBuf, const char *path, DWORD maxlen)
{
  DWORD FullPathNameA; // eax
  DWORD LastError; // eax
  unsigned int v6; // edi
  char *v7; // eax
  char *v8; // ebx
  DWORD v9; // eax
  char *pfname; // [esp+Ch] [ebp-4h] BYREF

  if ( path == nullptr || *path == 0 )
    return _getcwd(pnbuf: UserBuf, maxlen);
  if ( UserBuf != nullptr )
  {
    v6 = maxlen;
    if ( maxlen == 0 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v8 = UserBuf;
  }
  else
  {
    FullPathNameA = GetFullPathNameA(lpFileName: path, nBufferLength: 0, lpBuffer: nullptr, lpFilePart: nullptr);
    if ( FullPathNameA == 0 )
    {
LABEL_5:
      LastError = GetLastError();
      _dosmaperr(oserrno: LastError);
      return nullptr;
    }
    v6 = maxlen;
    if ( maxlen <= FullPathNameA )
      v6 = FullPathNameA;
    v7 = (char *)calloc(count: v6, size: 1u);
    v8 = v7;
    if ( v7 == nullptr )
    {
      *_errno() = 12;
      return nullptr;
    }
  }
  v9 = GetFullPathNameA(lpFileName: path, nBufferLength: v6, lpBuffer: v8, lpFilePart: &pfname);
  if ( v9 >= v6 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    *_errno() = 34;
    return nullptr;
  }
  if ( v9 == 0 )
  {
    if ( UserBuf == nullptr )
      free(pMem: v8);
    goto LABEL_5;
  }
  return v8;
}

//------------------------------------------------------------------------------
// Address: 0x10041882
// Name: ___dtoxmode
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl __dtoxmode(char attr, const char *name)
{
  const char *v2; // ecx
  char v3; // dl
  int v4; // edi
  unsigned int v5; // edi
  const unsigned __int8 *v6; // eax
  const unsigned __int8 *v7; // esi

  v2 = name;
  if ( name[1] == 58 )
    v2 = name + 2;
  v3 = *v2;
  if ( (*v2 == 92 || v3 == 47) && v2[1] == 0 || (attr & 0x10) != 0 || (v4 = 0x8000, v3 == 0) )
    v4 = 16448;
  v5 = ~(attr << 7) & 0x80 | 0x100 | v4;
  v6 = _mbsrchr(str: (const unsigned __int8 *)name, c: 0x2Eu);
  v7 = v6;
  if ( v6 != nullptr
    && (_mbsicmp(s1: v6, s2: ".exe") == 0
     || _mbsicmp(s1: v7, s2: ".cmd") == 0
     || _mbsicmp(s1: v7, s2: ".bat") == 0
     || _mbsicmp(s1: v7, s2: ".com") == 0) )
  {
    v5 |= 0x40u;
  }
  return (v5 >> 3) & 0x38 | v5 | (((v5 >> 3) & 0x38 | v5) >> 6) & 7;
}

//------------------------------------------------------------------------------
// Address: 0x1004193F
// Name: __close_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close_nolock(int fh)
{
  int osfhandle; // edi
  void *v2; // eax
  DWORD LastError; // edi

  if ( _get_osfhandle(fh) == -1
    || (fh == 1 && (__pioinfo[0][2].osfile & 1) != 0 || fh == 2 && (__pioinfo[0][1].osfile & 1) != 0)
    && (osfhandle = _get_osfhandle(fh: 2), _get_osfhandle(fh: 1) == osfhandle)
    || (v2 = (void *)_get_osfhandle(fh), CloseHandle(hObject: v2)) )
  {
    LastError = 0;
  }
  else
  {
    LastError = GetLastError();
  }
  _free_osfhnd(fh);
  __pioinfo[fh >> 5][fh & 0x1F].osfile = 0;
  if ( LastError == 0 )
    return 0;
  _dosmaperr(oserrno: LastError);
  return -1;
}

//------------------------------------------------------------------------------
// Address: 0x100419DB
// Name: __close
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _close(int fh)
{
  ioinfo **v2; // edi
  int v3; // esi
  int r; // [esp+14h] [ebp-1Ch]

  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle || (v2 = &__pioinfo[fh >> 5], v3 = (fh & 0x1F) << 6, (*(&(*v2)->osfile + v3) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  __lock_fhandle(fh);
  if ( (*(&(*v2)->osfile + v3) & 1) != 0 )
  {
    r = _close_nolock(fh);
  }
  else
  {
    *_errno() = 9;
    r = -1;
  }
  _unlock_fhandle(fh);
  return r;
}

//------------------------------------------------------------------------------
// Address: 0x10041A9F
// Name: __fstat64i32
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _fstat64i32(int fildes, _stat64i32 *buf)
{
  int v3; // edi
  DWORD v4; // eax
  DWORD LastError; // eax
  unsigned __int16 v6; // cx
  unsigned int v7; // ecx
  BOOL v8; // eax
  unsigned __int16 st_mode; // ax
  unsigned __int16 v10; // ax
  _FILETIME LocalFileTime; // [esp+14h] [ebp-74h] BYREF
  int fh; // [esp+1Ch] [ebp-6Ch]
  unsigned int TotalBytesAvail; // [esp+20h] [ebp-68h] BYREF
  int v14; // [esp+24h] [ebp-64h]
  _BY_HANDLE_FILE_INFORMATION FileInformation; // [esp+28h] [ebp-60h] BYREF
  _SYSTEMTIME SystemTime; // [esp+5Ch] [ebp-2Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+70h] [ebp-18h]

  fh = fildes;
  v14 = 0;
  if ( buf == nullptr )
  {
    *__doserrno() = 0;
    *_errno() = 22;
LABEL_3:
    _invalid_parameter_noinfo();
    return -1;
  }
  memset(dst: (int)buf, value: nullptr, count: sizeof(_stat64i32));
  if ( fildes == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fildes < 0
    || fildes >= _nhandle
    || (TotalBytesAvail = (unsigned int)&__pioinfo[fildes >> 5],
        v3 = (fildes & 0x1F) << 6,
        (*(_BYTE *)(*(_DWORD *)TotalBytesAvail + v3 + 4) & 1) == 0) )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    goto LABEL_3;
  }
  __lock_fhandle(fh);
  ms_exc.registration.TryLevel = 0;
  if ( (*(_BYTE *)(*(_DWORD *)TotalBytesAvail + v3 + 4) & 1) == 0 )
    goto LABEL_12;
  v4 = GetFileType(hFile: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6))) & 0xFFFF7FFF;
  switch ( v4 )
  {
    case 1u:
      buf->st_mode = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ino = 0;
      buf->st_nlink = 1;
      if ( GetFileInformationByHandle(
             hFile: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6)),
             lpFileInformation: &FileInformation) )
      {
        st_mode = buf->st_mode;
        if ( (FileInformation.dwFileAttributes & 1) != 0 )
          v10 = st_mode | 0x124;
        else
          v10 = st_mode | 0x1B6;
        buf->st_mode = v10;
        if ( FileInformation.ftLastWriteTime.dwLowDateTime != 0 || FileInformation.ftLastWriteTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftLastWriteTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_mtime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_mtime = 0;
        }
        if ( FileInformation.ftLastAccessTime.dwLowDateTime != 0 || FileInformation.ftLastAccessTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftLastAccessTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_atime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_atime = buf->st_mtime;
        }
        if ( FileInformation.ftCreationTime.dwLowDateTime != 0 || FileInformation.ftCreationTime.dwHighDateTime != 0 )
        {
          if ( !FileTimeToLocalFileTime(lpFileTime: &FileInformation.ftCreationTime, lpLocalFileTime: &LocalFileTime)
            || !FileTimeToSystemTime(lpFileTime: &LocalFileTime, lpSystemTime: &SystemTime) )
          {
            goto LABEL_13;
          }
          buf->st_ctime = __loctotime64_t(
                            yr: SystemTime.wYear,
                            mo: SystemTime.wMonth,
                            dy: SystemTime.wDay,
                            hr: SystemTime.wHour,
                            mn: SystemTime.wMinute,
                            sc: SystemTime.wSecond,
                            dstflag: -1);
        }
        else
        {
          buf->st_ctime = buf->st_mtime;
        }
        buf->st_size = FileInformation.nFileSizeLow;
        buf->st_mode |= 0x8000u;
        buf->st_dev = 0;
        buf->st_rdev = 0;
        goto done_2;
      }
      goto LABEL_19;
    case 2u:
      v6 = 0x2000;
LABEL_22:
      buf->st_mode = v6;
      v7 = fh;
      buf->st_dev = fh;
      buf->st_rdev = v7;
      buf->st_nlink = 1;
      buf->st_ino = 0;
      buf->st_gid = 0;
      buf->st_uid = 0;
      buf->st_ctime = 0;
      buf->st_mtime = 0;
      buf->st_atime = 0;
      if ( v4 == 2 )
      {
        buf->st_size = 0;
      }
      else
      {
        v8 = PeekNamedPipe(
               hNamedPipe: *(HANDLE *)(*(_DWORD *)TotalBytesAvail + ((fildes & 0x1F) << 6)),
               lpBuffer: nullptr,
               nBufferSize: 0,
               lpBytesRead: nullptr,
               lpTotalBytesAvail: &TotalBytesAvail,
               lpBytesLeftThisMessage: nullptr);
        buf->st_size = v8 ? TotalBytesAvail : 0;
      }
      goto done_2;
    case 3u:
      v6 = 4096;
      goto LABEL_22;
    default:
      break;
  }
  if ( v4 != 0 )
  {
LABEL_19:
    LastError = GetLastError();
    _dosmaperr(oserrno: LastError);
    goto LABEL_13;
  }
LABEL_12:
  *_errno() = 9;
LABEL_13:
  v14 = -1;
done_2:
  ms_exc.registration.TryLevel = -2;
  _unlock_fhandle(fh);
  return v14;
}

//------------------------------------------------------------------------------
// Address: 0x10041DF1
// Name: _tsopen_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __usercall tsopen_nolock@<eax>(
        int *pfh@<eax>,
        unsigned int a2@<edi>,
        int *punlock_flag,
        const char *path,
        int oflag,
        int shflag,
        char pmode)
{
  unsigned int v8; // eax
  int v10; // eax
  char *v11; // eax
  DWORD v12; // eax
  DWORD FileType; // eax
  char *p_osfile; // eax
  DWORD LastError; // esi
  char v16; // cl
  _BYTE *v17; // eax
  int v18; // edi
  int v19; // eax
  unsigned int v20; // eax
  unsigned int v21; // eax
  int v22; // edi
  __int64 v23; // rax
  int v24; // eax
  __int64 v25; // rax
  int v26; // eax
  int v27; // ebx
  int v28; // eax
  _BYTE *v29; // eax
  _BYTE *v30; // eax
  bool v31; // zf
  char *v32; // eax
  HANDLE v33; // eax
  DWORD v34; // eax
  char *v35; // eax
  int v36; // [esp-10h] [ebp-48h]
  DWORD v37; // [esp-Ch] [ebp-44h]
  int v38; // [esp-8h] [ebp-40h]
  _SECURITY_ATTRIBUTES SecurityAttributes; // [esp+8h] [ebp-30h] BYREF
  int fmode; // [esp+14h] [ebp-24h] BYREF
  void *osfh; // [esp+18h] [ebp-20h]
  int bom; // [esp+1Ch] [ebp-1Ch] BYREF
  unsigned int filecreate; // [esp+20h] [ebp-18h]
  unsigned int fileshare; // [esp+24h] [ebp-14h]
  unsigned int fileattrib; // [esp+28h] [ebp-10h]
  unsigned int fileaccess; // [esp+2Ch] [ebp-Ch]
  int retvalue; // [esp+30h] [ebp-8h]
  char inputbuf; // [esp+34h] [ebp-4h] BYREF
  char v49; // [esp+35h] [ebp-3h]
  char tmode; // [esp+36h] [ebp-2h]
  char fileflags; // [esp+37h] [ebp-1h]

  fmode = 0;
  tmode = 0;
  retvalue = 0;
  SecurityAttributes.nLength = 12;
  SecurityAttributes.lpSecurityDescriptor = nullptr;
  if ( (oflag & 0x80u) == 0 )
  {
    SecurityAttributes.bInheritHandle = 1;
    fileflags = 0;
  }
  else
  {
    SecurityAttributes.bInheritHandle = 0;
    fileflags = 16;
  }
  if ( _get_fmode(pMode: &fmode) != 0 )
    _invoke_watson(a1: a2);
  if ( (oflag & 0x8000) == 0 && ((oflag & 0x74000) != 0 || fmode != 0x8000) )
    fileflags |= 0x80u;
  if ( (oflag & 3) != 0 )
  {
    if ( (oflag & 3) != 1 )
    {
      if ( (oflag & 3) != 2 )
        goto LABEL_40;
      goto LABEL_13;
    }
    if ( (oflag & 8) != 0 && (oflag & 0x70000) != 0 )
    {
LABEL_13:
      fileaccess = -1073741824;
      goto LABEL_18;
    }
    fileaccess = 0x40000000;
  }
  else
  {
    fileaccess = 0x80000000;
  }
LABEL_18:
  switch ( shflag )
  {
    case 16:
      fileshare = 0;
      break;
    case 32:
      fileshare = 1;
      break;
    case 48:
      fileshare = 2;
      break;
    case 64:
      fileshare = 3;
      break;
    case 128:
      fileshare = fileaccess == 0x80000000;
      break;
    default:
      goto LABEL_40;
  }
  v8 = oflag & 0x700;
  if ( v8 > 0x400 )
  {
    if ( v8 != 1280 )
    {
      if ( v8 == 1536 )
        goto LABEL_41;
      if ( v8 != 1792 )
        goto LABEL_40;
    }
    filecreate = 1;
    goto LABEL_43;
  }
  if ( (oflag & 0x700) == 0x400 || (oflag & 0x700) == 0 )
  {
    filecreate = 3;
    goto LABEL_43;
  }
  if ( v8 == 256 )
  {
    filecreate = 4;
    goto LABEL_43;
  }
  if ( v8 == 512 )
  {
LABEL_41:
    filecreate = 5;
    goto LABEL_43;
  }
  if ( v8 != 768 )
  {
LABEL_40:
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  filecreate = 2;
LABEL_43:
  fileattrib = 128;
  if ( (oflag & 0x100) != 0 && (pmode & ~(_BYTE)_umaskval & 0x80u) == 0 )
    fileattrib = 1;
  if ( (oflag & 0x40) != 0 )
  {
    fileattrib |= 0x4000000u;
    fileaccess |= 0x10000u;
    fileshare |= 4u;
  }
  if ( (oflag & 0x1000) != 0 )
    fileattrib |= 0x100u;
  if ( (oflag & 0x20) != 0 )
  {
    fileattrib |= 0x8000000u;
  }
  else if ( (oflag & 0x10) != 0 )
  {
    fileattrib |= 0x10000000u;
  }
  v10 = _alloc_osfhnd();
  *pfh = v10;
  if ( v10 == -1 )
  {
    *__doserrno() = 0;
    *pfh = -1;
    *_errno() = 24;
    return *_errno();
  }
  v37 = fileattrib;
  *punlock_flag = 1;
  osfh = CreateFileA(
           lpFileName: path,
           dwDesiredAccess: fileaccess,
           dwShareMode: fileshare,
           lpSecurityAttributes: &SecurityAttributes,
           dwCreationDisposition: filecreate,
           dwFlagsAndAttributes: v37,
           hTemplateFile: nullptr);
  if ( osfh != (void *)-1
    || (fileaccess & 0xC0000000) == 0xC0000000
    && (oflag & 1) != 0
    && (fileaccess &= ~0x80000000,
        (osfh = CreateFileA(
                  lpFileName: path,
                  dwDesiredAccess: fileaccess,
                  dwShareMode: fileshare,
                  lpSecurityAttributes: &SecurityAttributes,
                  dwCreationDisposition: filecreate,
                  dwFlagsAndAttributes: fileattrib,
                  hTemplateFile: nullptr)) != (void *)-1) )
  {
    FileType = GetFileType(hFile: osfh);
    switch ( FileType )
    {
      case 0u:
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
        LastError = GetLastError();
        _dosmaperr(oserrno: LastError);
        CloseHandle(hObject: osfh);
        if ( LastError == 0 )
          *_errno() = 13;
        return *_errno();
      case 2u:
        fileflags |= 0x40u;
        break;
      case 3u:
        fileflags |= 8u;
        break;
      default:
        break;
    }
    _set_osfhnd(fh: *pfh, value: (int)osfh);
    v16 = fileflags | 1;
    __pioinfo[*pfh >> 5][*pfh & 0x1F].osfile = fileflags | 1;
    v17 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
    *v17 &= 0x80u;
    v49 = v16 & 0x48;
    fileflags = v16;
    if ( (v16 & 0x48) == 0 )
    {
      if ( v16 >= 0 )
        goto LABEL_131;
      if ( (oflag & 2) != 0 )
      {
        v18 = _lseek_nolock(fh: *pfh, pos: -1, mthd: 2);
        if ( v18 == -1 )
        {
          if ( *__doserrno() != 131 )
          {
LABEL_74:
            _close_nolock(fh: *pfh);
            return *_errno();
          }
        }
        else
        {
          v36 = *pfh;
          inputbuf = 0;
          if ( _read_nolock(fh: v36, &inputbuf, cnt: 1u) == 0
            && inputbuf == 26
            && _chsize_nolock(filedes: *pfh, size: v18) == -1
            || _lseek_nolock(fh: *pfh, pos: 0, mthd: 0) == -1 )
          {
            goto LABEL_74;
          }
        }
      }
    }
    if ( fileflags >= 0 )
    {
LABEL_131:
      v29 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      *v29 ^= (tmode ^ *v29) & 0x7F;
      v30 = (char *)&__pioinfo[*pfh >> 5][*pfh & 0x1F] + 36;
      v31 = v49 == 0;
      *v30 = *v30 & 0x7F | (BYTE2(oflag) << 7);
      if ( v31 && (oflag & 8) != 0 )
      {
        v32 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *v32 |= 0x20u;
      }
      if ( (fileaccess & 0xC0000000) != 0xC0000000 || (oflag & 1) == 0 )
        return retvalue;
      CloseHandle(hObject: osfh);
      v33 = CreateFileA(
              lpFileName: path,
              dwDesiredAccess: fileaccess & 0x7FFFFFFF,
              dwShareMode: fileshare,
              lpSecurityAttributes: &SecurityAttributes,
              dwCreationDisposition: 3u,
              dwFlagsAndAttributes: fileattrib,
              hTemplateFile: nullptr);
      if ( v33 != (HANDLE)-1 )
      {
        __pioinfo[*pfh >> 5][*pfh & 0x1F].osfhnd = (int)v33;
        return retvalue;
      }
      v34 = GetLastError();
      _dosmaperr(oserrno: v34);
      v35 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
      *v35 &= ~1u;
      _free_osfhnd(fh: *pfh);
      return *_errno();
    }
    if ( (oflag & 0x74000) == 0 )
    {
      if ( (fmode & 0x74000) != 0 )
        oflag |= fmode & 0x74000;
      else
        oflag |= 0x4000u;
    }
    v19 = oflag & 0x74000;
    if ( (oflag & 0x74000) == 0x4000 )
    {
      tmode = 0;
      goto LABEL_95;
    }
    if ( v19 == 0x10000 || v19 == 81920 )
    {
      if ( (oflag & 0x301) != 0x301 )
        goto LABEL_95;
    }
    else if ( v19 != 0x20000 && v19 != 147456 )
    {
      if ( v19 == 0x40000 || v19 == 278528 )
        tmode = 1;
LABEL_95:
      if ( (oflag & 0x70000) == 0 )
        goto LABEL_131;
      bom = 0;
      if ( (fileflags & 0x40) != 0 )
        goto LABEL_131;
      v20 = fileaccess & 0xC0000000;
      if ( (fileaccess & 0xC0000000) == 0x40000000 )
      {
        v21 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate <= 2 )
          goto LABEL_104;
        if ( filecreate > 4 )
          goto LABEL_103;
        if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2) != 0 )
        {
          v25 = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0);
          v26 = HIDWORD(v25) & v25;
          goto LABEL_119;
        }
      }
      else
      {
        if ( v20 == 0x80000000 )
          goto LABEL_109;
        if ( v20 != -1073741824 )
          goto LABEL_131;
        v21 = filecreate;
        if ( filecreate == 0 )
          goto LABEL_131;
        if ( filecreate > 2 )
        {
          if ( filecreate > 4 )
          {
LABEL_103:
            if ( v21 != 5 )
              goto LABEL_131;
            goto LABEL_104;
          }
          if ( _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 2) != 0 )
          {
            v23 = _lseeki64_nolock(fh: *pfh, pos: 0, mthd: 0);
            if ( (HIDWORD(v23) & (unsigned int)v23) == 0xFFFFFFFF )
              goto LABEL_74;
LABEL_109:
            v24 = _read_nolock(fh: *pfh, inputbuf: &bom, cnt: 3u);
            if ( v24 == -1 )
              goto LABEL_74;
            if ( v24 != 2 )
            {
              if ( v24 != 3 )
              {
LABEL_126:
                v26 = _lseek_nolock(fh: *pfh, pos: 0, mthd: 0);
LABEL_119:
                if ( v26 == -1 )
                  goto LABEL_74;
                goto LABEL_131;
              }
              if ( bom == 12565487 )
              {
                tmode = 1;
                goto LABEL_131;
              }
            }
            if ( (unsigned __int16)bom == 65534 )
            {
              _close_nolock(fh: *pfh);
              *_errno() = 22;
              return 22;
            }
            if ( (unsigned __int16)bom == 65279 )
            {
              if ( _lseek_nolock(fh: *pfh, pos: 2, mthd: 0) == -1 )
                goto LABEL_74;
              tmode = 2;
              goto LABEL_131;
            }
            goto LABEL_126;
          }
        }
      }
LABEL_104:
      v22 = 0;
      if ( tmode == 1 )
      {
        bom = 12565487;
        v38 = 3;
LABEL_128:
        v27 = v38;
        while ( 1 )
        {
          v28 = _write(fh: *pfh, buf: (char *)&bom + v22, cnt: v27 - v22);
          if ( v28 == -1 )
            goto LABEL_74;
          v22 += v28;
          if ( v27 <= v22 )
            goto LABEL_131;
        }
      }
      if ( tmode == 2 )
      {
        bom = 65279;
        v38 = 2;
        goto LABEL_128;
      }
      goto LABEL_131;
    }
    tmode = 2;
    goto LABEL_95;
  }
  v11 = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
  *v11 &= ~1u;
  v12 = GetLastError();
  _dosmaperr(oserrno: v12);
  return *_errno();
}

//------------------------------------------------------------------------------
// Address: 0x10042525
// Name: __sopen_helper
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_helper(const char *path, int oflag, int shflag, int pmode, int *pfh, int bSecure)
{
  int result; // eax
  char *p_osfile; // eax
  int retval; // [esp+14h] [ebp-20h]
  int unlock_flag; // [esp+18h] [ebp-1Ch] BYREF
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  unlock_flag = 0;
  if ( pfh == nullptr || (*pfh = -1, path == nullptr) || bSecure != 0 && (pmode & 0xFFFFFE7F) != 0 )
  {
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return 22;
  }
  else
  {
    ms_exc.registration.TryLevel = 0;
    retval = tsopen_nolock(pfh, a2: 0, punlock_flag: &unlock_flag, path, oflag, shflag, pmode);
    ms_exc.registration.TryLevel = -2;
    if ( unlock_flag != 0 )
    {
      if ( retval != 0 )
      {
        p_osfile = &__pioinfo[*pfh >> 5][*pfh & 0x1F].osfile;
        *p_osfile &= ~1u;
      }
      _unlock_fhandle(fh: *pfh);
    }
    result = retval;
    if ( retval != 0 )
      *pfh = -1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x100425E9
// Name: __sopen_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _sopen_s(int *pfh, const char *path, int oflag, int shflag, int pmode)
{
  return _sopen_helper(path, oflag, shflag, pmode, pfh, bSecure: 1);
}

//------------------------------------------------------------------------------
// Address: 0x10042609
// Name: ___loctotime64_t
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl __loctotime64_t(int yr, int mo, int dy, unsigned int hr, unsigned int mn, unsigned int sc, int dstflag)
{
  int v7; // ebx
  int v8; // esi
  int *v9; // eax
  int v10; // ecx
  int v11; // ecx
  unsigned int v12; // edi
  int timezone; // [esp+Ch] [ebp-40h] BYREF
  int dstbias; // [esp+10h] [ebp-3Ch] BYREF
  int v16; // [esp+14h] [ebp-38h]
  int daylight; // [esp+18h] [ebp-34h] BYREF
  int v18; // [esp+1Ch] [ebp-30h]
  int tmpdays; // [esp+20h] [ebp-2Ch]
  tm tb; // [esp+24h] [ebp-28h] BYREF

  v7 = mo;
  v8 = yr - 1900;
  v16 = mo;
  daylight = 0;
  dstbias = 0;
  timezone = 0;
  if ( yr - 1900 < 70
    || v8 > 1100
    || (unsigned int)(mo - 1) > 0xB
    || hr > 0x17
    || mn > 0x3B
    || sc > 0x3B
    || dy < 1
    || (v9 = &_days[mo], v10 = *(v9 - 1), *v9 - v10 < dy)
    && ((v8 % 4 != 0 || v8 % 100 == 0) && yr % 400 != 0 || (v7 = v16, v16 != 2) || dy > 29) )
  {
    *_errno() = 22;
    return -1;
  }
  else
  {
    tmpdays = dy + v10;
    if ( v8 % 4 == 0 && (v11 = 100, v8 % 100 != 0) || (v11 = 400, yr % 400 == 0) )
    {
      if ( v7 > 2 )
        ++tmpdays;
    }
    __tzset(a1: v11);
    if ( _get_daylight(_Daylight: &daylight) != 0
      || _get_dstbias(_Daylight_savings_bias: &dstbias) != 0
      || _get_timezone(_Timezone: &timezone) != 0 )
    {
      _invoke_watson(a1: 0x190u);
    }
    v18 = (unsigned __int64)(365 * (v8 - 70LL) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17) >> 32;
    tb.tm_yday = tmpdays;
    v12 = sc
        + timezone
        + 60
        * (mn
         + 60
         * (hr + 24 * (tmpdays + 365 * (yr - 1970) + (yr - 1900 + 299) / 400 - (yr - 1901) / 100 + (yr - 1901) / 4 - 17)));
    tb.tm_year = yr - 1900;
    tb.tm_mon = v16 - 1;
    tb.tm_hour = hr;
    tb.tm_min = mn;
    tb.tm_sec = sc;
    if ( dstflag == 1 || dstflag == -1 && daylight != 0 && _isindst(&tb) != 0 )
      v12 += dstbias;
    return v12;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042870
// Name: __getdrive
// Source: linker_block_proximity
//------------------------------------------------------------------------------
unsigned int __cdecl _getdrive()
{
  wchar_t *v0; // ebx
  signed int CurrentDirectoryW; // esi
  wchar_t *v2; // eax
  unsigned int v3; // edi
  unsigned int v4; // eax
  int memfree; // [esp+10h] [ebp-214h]
  wchar_t curdirstr[262]; // [esp+14h] [ebp-210h] BYREF

  memfree = 0;
  v0 = curdirstr;
  CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: 0x105u, lpBuffer: curdirstr);
  if ( CurrentDirectoryW > 260 )
  {
    v2 = (wchar_t *)calloc(count: CurrentDirectoryW + 1, size: 2u);
    v0 = v2;
    if ( v2 != nullptr )
    {
      memfree = 1;
      CurrentDirectoryW = GetCurrentDirectoryW(nBufferLength: CurrentDirectoryW + 1, lpBuffer: v2);
    }
    else
    {
      *_errno() = 12;
      CurrentDirectoryW = 0;
    }
  }
  v3 = 0;
  if ( CurrentDirectoryW != 0 )
  {
    if ( v0[1] == 58 )
    {
      v4 = *v0;
      if ( v4 >= 0x61 && v4 <= 0x7A )
        v4 -= 32;
      v3 = v4 - 64;
    }
  }
  else
  {
    *_errno() = 12;
  }
  if ( memfree != 0 )
    free(pMem: v0);
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x1004293E
// Name: __mbctolower_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower_l(unsigned int c, localeinfo_struct *plocinfo)
{
  int result; // eax
  _LocaleUpdate _loc_update; // [esp+4h] [ebp-18h] BYREF
  unsigned __int8 ret[4]; // [esp+14h] [ebp-8h] BYREF
  char val[4]; // [esp+18h] [ebp-4h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( c <= 0xFF )
  {
    if ( (_loc_update.localeinfo.mbcinfo->mbctype[c + 1] & 0x10) != 0 )
      result = _loc_update.localeinfo.mbcinfo->mbcasemap[c];
    else
      result = c;
LABEL_11:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return result;
  }
  val[0] = BYTE1(c);
  val[1] = c;
  if ( (_loc_update.localeinfo.mbcinfo->mbctype[BYTE1(c) + 1] & 4) != 0
    && __crtLCMapStringA(
         plocinfo: &_loc_update.localeinfo,
         Locale: _loc_update.localeinfo.mbcinfo->mblcid,
         dwMapFlags: 0x100u,
         lpSrcStr: val,
         cchSrc: 2,
         lpDestStr: (char *)ret,
         cchDest: 2,
         code_page: _loc_update.localeinfo.mbcinfo->mbcodepage,
         bError: 1) != 0 )
  {
    result = ret[1] + (ret[0] << 8);
    goto LABEL_11;
  }
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
  return c;
}

//------------------------------------------------------------------------------
// Address: 0x100429E4
// Name: __mbctolower
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _mbctolower(unsigned int c)
{
  return _mbctolower_l(c, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100429F7
// Name: __mbspbrk_l
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk_l(unsigned __int8 *string, unsigned __int8 *charset, localeinfo_struct *plocinfo)
{
  unsigned __int8 *v3; // ecx
  unsigned __int8 *i; // eax
  unsigned __int8 v5; // dl
  _LocaleUpdate _loc_update; // [esp+8h] [ebp-10h] BYREF

  _LocaleUpdate::_LocaleUpdate(this: &_loc_update, plocinfo);
  if ( _loc_update.localeinfo.mbcinfo->ismbcodepage == 0 )
  {
    strpbrk(string, control: charset);
LABEL_22:
    if ( _loc_update.updated )
      _loc_update.ptd->_ownlocale &= ~2u;
    return;
  }
  v3 = string;
  if ( string != nullptr && charset != nullptr )
  {
    if ( *string != 0 )
    {
      do
      {
        for ( i = charset; *i != 0; ++i )
        {
          v5 = *i;
          if ( (_loc_update.localeinfo.mbcinfo->mbctype[*i + 1] & 4) != 0 )
          {
            if ( v5 == *v3 && i[1] == v3[1] || i[1] == 0 )
              break;
            ++i;
          }
          else if ( v5 == *v3 )
          {
            break;
          }
        }
        if ( *i != 0 )
          break;
        if ( (_loc_update.localeinfo.mbcinfo->mbctype[*v3 + 1] & 4) != 0 && *++v3 == 0 )
          break;
        ++v3;
      }
      while ( *v3 != 0 );
    }
    goto LABEL_22;
  }
  *_errno() = 22;
  _invalid_parameter_noinfo();
  if ( _loc_update.updated )
    _loc_update.ptd->_ownlocale &= ~2u;
}

//------------------------------------------------------------------------------
// Address: 0x10042ABC
// Name: __mbspbrk
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _mbspbrk(unsigned __int8 *string, unsigned __int8 *charset)
{
  _mbspbrk_l(string, charset, plocinfo: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x10042AD3
// Name: __freebuf
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _freebuf(_iobuf *stream)
{
  int flag; // eax

  flag = stream->_flag;
  if ( (flag & 0x83) != 0 && (flag & 8) != 0 )
  {
    free(pMem: stream->_base);
    stream->_flag &= 0xFFFFFBF7;
    stream->_ptr = nullptr;
    stream->_base = nullptr;
    stream->_cnt = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10042B04
// Name: __initp_misc_winsig
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_winsig(void *enull)
{
  ctrlc_action = enull;
  ctrlbreak_action = (void (__cdecl *)(int))enull;
  abort_action = enull;
  term_action = (void (__cdecl *)(int))enull;
}

//------------------------------------------------------------------------------
// Address: 0x10042B22
// Name: siglookup
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_XCPT_ACTION *__usercall siglookup@<eax>(int signum@<edx>, _XCPT_ACTION *pxcptacttab)
{
  _XCPT_ACTION *result; // eax

  result = pxcptacttab;
  do
  {
    if ( result->SigNum == signum )
      break;
    ++result;
  }
  while ( result < &pxcptacttab[12] );
  if ( result >= &pxcptacttab[12] || result->SigNum != signum )
    return nullptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042B59
// Name: ___get_sigabrt
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void (__cdecl *__cdecl __get_sigabrt())(int)
{
  return (void (__cdecl *)(int))DecodePointer(Ptr: abort_action);
}

//------------------------------------------------------------------------------
// Address: 0x10042B66
// Name: _raise
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl raise(int signum)
{
  _tiddata *v1; // edi
  _tiddata *v2; // eax
  int result; // eax
  void (__cdecl **p_XcptAction)(int); // esi
  void (__cdecl *v5)(int); // eax
  void (__cdecl *v6)(int); // eax
  int oldfpecode; // [esp+10h] [ebp-30h]
  _EXCEPTION_POINTERS *oldpxcptinfoptrs; // [esp+14h] [ebp-2Ch]
  int indx; // [esp+1Ch] [ebp-24h]
  void (__cdecl *sigact)(int); // [esp+20h] [ebp-20h]
  int siglock; // [esp+24h] [ebp-1Ch]

  v1 = nullptr;
  siglock = 0;
  if ( signum > 11 )
  {
    if ( signum == 15 )
    {
      p_XcptAction = &term_action;
      v5 = term_action;
      goto LABEL_18;
    }
    if ( signum == 21 )
    {
      p_XcptAction = &ctrlbreak_action;
      v5 = ctrlbreak_action;
      goto LABEL_18;
    }
    if ( signum != 22 )
      goto LABEL_14;
    goto LABEL_15;
  }
  if ( signum != 11 )
  {
    if ( signum == 2 )
    {
      p_XcptAction = (void (__cdecl **)(int))&ctrlc_action;
      v5 = (void (__cdecl *)(int))ctrlc_action;
LABEL_18:
      siglock = 1;
      v6 = (void (__cdecl *)(int))DecodePointer(Ptr: v5);
      goto LABEL_19;
    }
    if ( signum != 4 )
    {
      if ( signum != 6 )
      {
        if ( signum == 8 )
          goto LABEL_7;
LABEL_14:
        *_errno() = 22;
        _invalid_parameter_noinfo();
        return -1;
      }
LABEL_15:
      p_XcptAction = (void (__cdecl **)(int))&abort_action;
      v5 = (void (__cdecl *)(int))abort_action;
      goto LABEL_18;
    }
  }
LABEL_7:
  v2 = _getptd_noexit();
  v1 = v2;
  if ( v2 == nullptr )
    return -1;
  p_XcptAction = &siglookup(signum, pxcptacttab: (_XCPT_ACTION *)v2->_pxcptacttab)->XcptAction;
  v6 = *p_XcptAction;
LABEL_19:
  sigact = v6;
  result = 0;
  if ( sigact == (void (__cdecl *)(int))1 )
    return result;
  if ( sigact == nullptr )
    _exit(code: 3);
  if ( siglock != 0 )
    _lock(locknum: 0);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    oldpxcptinfoptrs = (_EXCEPTION_POINTERS *)v1->_tpxcptinfoptrs;
    v1->_tpxcptinfoptrs = nullptr;
    if ( signum != 8 )
      goto LABEL_33;
    oldfpecode = v1->_tfpecode;
    v1->_tfpecode = 140;
  }
  if ( signum == 8 )
  {
    for ( indx = 3; indx < 12; ++indx )
      *((_DWORD *)v1->_pxcptacttab + 3 * indx + 2) = 0;
    goto $LN37_1;
  }
LABEL_33:
  *p_XcptAction = (void (__cdecl *)(int))_encoded_null();
$LN37_1:
  if ( siglock != 0 )
    _unlock(locknum: 0);
  if ( signum == 8 )
    ((void (__cdecl *)(int, int))sigact)(a1: 8, a2: v1->_tfpecode);
  else
    sigact(a1: signum);
  if ( signum == 8 || signum == 11 || signum == 4 )
  {
    v1->_tpxcptinfoptrs = oldpxcptinfoptrs;
    if ( signum == 8 )
      v1->_tfpecode = oldfpecode;
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10042D09
// Name: __initp_misc_rand_s
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _initp_misc_rand_s(int (__stdcall *enull)(void *, unsigned int))
{
  g_pfnRtlGenRandom = enull;
}

//------------------------------------------------------------------------------
// Address: 0x10042D18
// Name: __RTC_Initialize
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Initialize()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10042D3E
// Name: __RTC_Terminate
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl _RTC_Terminate()
{
  ;
}

//------------------------------------------------------------------------------
// Address: 0x10042D70
// Name: __ValidateImageBase
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _ValidateImageBase(unsigned __int8 *pImageBase)
{
  unsigned __int8 *v2; // eax

  return *(_WORD *)pImageBase == 23117
      && *(_DWORD *)(v2 = &pImageBase[*((_DWORD *)pImageBase + 15)]) == 17744
      && *((_WORD *)v2 + 12) == 267;
}

//------------------------------------------------------------------------------
// Address: 0x10042DB0
// Name: __FindPESection
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_IMAGE_SECTION_HEADER *__cdecl _FindPESection(unsigned __int8 *pImageBase, unsigned int rva)
{
  unsigned __int8 *v2; // ecx
  unsigned int v3; // esi
  unsigned int v4; // edx
  _IMAGE_SECTION_HEADER *result; // eax
  unsigned int VirtualAddress; // ecx

  v2 = &pImageBase[*((_DWORD *)pImageBase + 15)];
  v3 = *((unsigned __int16 *)v2 + 3);
  v4 = 0;
  result = (_IMAGE_SECTION_HEADER *)&v2[*((unsigned __int16 *)v2 + 10) + 24];
  if ( *((_WORD *)v2 + 3) == 0 )
    return nullptr;
  while ( 1 )
  {
    VirtualAddress = result->VirtualAddress;
    if ( rva >= VirtualAddress && rva < VirtualAddress + result->Misc.PhysicalAddress )
      break;
    ++v4;
    ++result;
    if ( v4 >= v3 )
      return nullptr;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10042E00
// Name: __IsNonwritableInCurrentImage
// Source: linker_block_proximity
//------------------------------------------------------------------------------
BOOL __cdecl _IsNonwritableInCurrentImage(unsigned __int8 *pTarget)
{
  _IMAGE_SECTION_HEADER *PESection; // eax

  return _ValidateImageBase(pImageBase: (unsigned __int8 *)0x10000000)
      && (PESection = _FindPESection(
                        pImageBase: (unsigned __int8 *)0x10000000,
                        rva: (unsigned int)(pTarget - 0x10000000))) != nullptr
      && (PESection->Characteristics & 0x80000000) == 0;
}

//------------------------------------------------------------------------------
// Address: 0x10042EBC
// Name: __openfile
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _openfile(const char *filename, const char *mode, int shflag, _iobuf *str)
{
  unsigned int v4; // ebx
  const char *v5; // esi
  char v6; // al
  _iobuf *result; // eax
  int v8; // ecx
  const unsigned __int8 *v9; // esi
  signed __int8 v10; // al
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  const unsigned __int8 *i; // esi
  int encodingFlag; // [esp+8h] [ebp-10h]
  int commodeset; // [esp+Ch] [ebp-Ch]
  int scanset; // [esp+10h] [ebp-8h]
  unsigned int streamflag; // [esp+14h] [ebp-4h]

  v4 = 0;
  v5 = mode;
  commodeset = 0;
  scanset = 0;
  encodingFlag = 0;
  while ( *v5 == 32 )
    ++v5;
  v6 = *v5;
  if ( *v5 == 97 )
  {
    v4 = 265;
  }
  else
  {
    if ( v6 == 114 )
    {
      streamflag = _commode | 1;
      goto LABEL_12;
    }
    if ( v6 != 119 )
    {
      *_errno() = 22;
      _invalid_parameter_noinfo();
      return nullptr;
    }
    v4 = 769;
  }
  streamflag = _commode | 2;
LABEL_12:
  v8 = 1;
  v9 = (const unsigned __int8 *)(v5 + 1);
  v10 = *v9;
  if ( *v9 == 0 )
    goto LABEL_66;
  while ( v8 != 0 )
  {
    if ( v10 > 83 )
    {
      v16 = v10 - 84;
      if ( v16 == 0 )
      {
        if ( (v4 & 0x1000) == 0 )
        {
          v4 |= 0x1000u;
          goto LABEL_48;
        }
        goto LABEL_46;
      }
      v17 = v16 - 14;
      if ( v17 != 0 )
      {
        v18 = v17 - 1;
        if ( v18 != 0 )
        {
          v19 = v18 - 11;
          if ( v19 != 0 )
          {
            if ( v19 != 6 )
              goto LABEL_68;
            if ( (v4 & 0xC000) != 0 )
              goto LABEL_46;
            v4 |= 0x4000u;
          }
          else
          {
            if ( commodeset != 0 )
              goto LABEL_46;
            streamflag &= ~0x4000u;
            commodeset = 1;
          }
        }
        else
        {
          if ( commodeset != 0 )
            goto LABEL_46;
          streamflag |= 0x4000u;
          commodeset = 1;
        }
      }
      else
      {
        if ( (v4 & 0xC000) != 0 )
          goto LABEL_46;
        v4 |= 0x8000u;
      }
    }
    else if ( v10 == 83 )
    {
      if ( scanset != 0 )
        goto LABEL_46;
      scanset = 1;
      v4 |= 0x20u;
    }
    else
    {
      v11 = v10 - 32;
      if ( v11 != 0 )
      {
        v12 = v11 - 11;
        if ( v12 != 0 )
        {
          v13 = v12 - 1;
          if ( v13 == 0 )
          {
            encodingFlag = 1;
LABEL_46:
            v8 = 0;
            goto LABEL_48;
          }
          v14 = v13 - 24;
          if ( v14 != 0 )
          {
            v15 = v14 - 10;
            if ( v15 != 0 )
            {
              if ( v15 != 4 )
                goto LABEL_68;
              if ( scanset != 0 )
                goto LABEL_46;
              scanset = 1;
              v4 |= 0x10u;
            }
            else
            {
              v4 |= 0x80u;
            }
          }
          else
          {
            if ( (v4 & 0x40) != 0 )
              goto LABEL_46;
            v4 |= 0x40u;
          }
        }
        else
        {
          if ( (v4 & 2) != 0 )
            goto LABEL_46;
          v4 = v4 & 0xFFFFFFFC | 2;
          streamflag = streamflag & 0xFFFFFF7C | 0x80;
        }
      }
    }
LABEL_48:
    v10 = *++v9;
    if ( *v9 == 0 )
      break;
  }
  if ( encodingFlag == 0 )
    goto LABEL_66;
  while ( *v9 == 32 )
    ++v9;
  if ( _mbsnbcmp(s1: "ccs", s2: v9, n: 3u) != 0 )
    goto LABEL_68;
  for ( i = v9 + 3; *i == 32; ++i )
    ;
  if ( *i != 61 )
    goto LABEL_68;
  do
    ++i;
  while ( *i == 32 );
  if ( _mbsnbicmp(s1: i, s2: "UTF-8", n: 5u) == 0 )
  {
    v9 = i + 5;
    v4 |= 0x40000u;
    goto LABEL_66;
  }
  if ( _mbsnbicmp(s1: i, s2: "UTF-16LE", n: 8u) == 0 )
  {
    v9 = i + 8;
    v4 |= 0x20000u;
    goto LABEL_66;
  }
  if ( _mbsnbicmp(s1: i, s2: "UNICODE", n: 7u) != 0 )
    goto LABEL_68;
  v9 = i + 7;
  v4 |= 0x10000u;
LABEL_66:
  while ( *v9 == 32 )
    ++v9;
  if ( *v9 != 0 )
  {
LABEL_68:
    *_errno() = 22;
    _invalid_parameter_noinfo();
    return nullptr;
  }
  if ( _sopen_s(pfh: (int *)&mode, path: filename, oflag: v4, shflag, pmode: 384) != 0 )
    return nullptr;
  ++_cflush;
  result = str;
  str->_flag = streamflag;
  result->_cnt = 0;
  result->_ptr = nullptr;
  result->_base = nullptr;
  result->_tmpfname = nullptr;
  result->_file = (int)mode;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043153
// Name: __getstream
// Source: linker_block_proximity
//------------------------------------------------------------------------------
_iobuf *__cdecl _getstream()
{
  _DWORD *v0; // edi
  int i; // esi
  void **v2; // eax
  int v3; // eax
  void *v4; // eax

  v0 = nullptr;
  _lock(locknum: 1);
  for ( i = 0; i < (int)_nstream; ++i )
  {
    v2 = &__piob[i];
    if ( *v2 == nullptr )
    {
      v4 = operator new(nSize: 0x38u);
      __piob[i] = v4;
      if ( v4 != nullptr )
      {
        if ( InitializeCriticalSectionAndSpinCount(
               lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32),
               dwSpinCount: 0xFA0u) )
        {
          EnterCriticalSection(lpCriticalSection: (LPCRITICAL_SECTION)((char *)__piob[i] + 32));
          v0 = __piob[i];
          v0[3] = 0;
        }
        else
        {
          free(pMem: __piob[i]);
          __piob[i] = nullptr;
        }
      }
      break;
    }
    v3 = *((_DWORD *)*v2 + 3);
    if ( (v3 & 0x83) == 0 && (v3 & 0x8000) == 0 )
    {
      if ( (unsigned int)(i - 3) <= 0x10 && _mtinitlocknum(locknum: i + 16) == 0 )
        break;
      _lock_file2(i, s: (char *)__piob[i]);
      if ( (*((_BYTE *)__piob[i] + 12) & 0x83) == 0 )
      {
        v0 = __piob[i];
        break;
      }
      _unlock_file2(i, s: (char *)__piob[i]);
    }
  }
  if ( v0 != nullptr )
  {
    v0[3] &= 0x8000u;
    v0[1] = 0;
    v0[2] = 0;
    *v0 = 0;
    v0[7] = 0;
    v0[4] = -1;
  }
  _unlock(locknum: 1);
  return (_iobuf *)v0;
}

//------------------------------------------------------------------------------
// Address: 0x10043290
// Name: __local_unwind4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _local_unwind4(_DWORD *a1, int a2, unsigned int a3)
{
  int result; // eax
  unsigned int v4; // esi
  int v5; // esi
  int v6; // ebx
  _EXCEPTION_REGISTRATION_RECORD *ExceptionList; // [esp-8h] [ebp-28h]
  int (__cdecl *v8)(int, int, int, int); // [esp-4h] [ebp-24h]

  v8 = unwind_handler4;
  ExceptionList = NtCurrentTeb()->NtTib.ExceptionList;
  while ( 1 )
  {
    result = a2;
    v4 = *(_DWORD *)(a2 + 12);
    if ( v4 == -2 || a3 != -2 && v4 <= a3 )
      break;
    v5 = 3 * v4;
    v6 = (*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 16;
    *(_DWORD *)(a2 + 12) = *(_DWORD *)((*a1 ^ *(_DWORD *)(a2 + 8)) + 4 * v5 + 0x10);
    if ( *(_DWORD *)(v6 + 4) == 0 )
    {
      _NLG_Notify(a1: 257);
      _NLG_Call(a1: 1, a2: ExceptionList, a3: v8);
    }
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043320
// Name: _unwind_handler4
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl unwind_handler4(int a1, int a2, int a3, _DWORD *a4)
{
  int result; // eax

  result = 1;
  if ( (*(_DWORD *)(a1 + 4) & 6) != 0 )
  {
    _local_unwind4(a1: *(_DWORD **)(a2 + 20), a2: *(_DWORD *)(a2 + 16), a3: *(_DWORD *)(a2 + 12));
    *a4 = a2;
    return 3;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10043366
// Name: _seh_longjmp_unwind4(x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __stdcall _seh_longjmp_unwind4(unsigned int Dummy)
{
  _local_unwind4(a1: *(_DWORD **)(Dummy + 40), a2: *(_DWORD *)(Dummy + 24), a3: *(_DWORD *)(Dummy + 28));
}

//------------------------------------------------------------------------------
// Address: 0x10043382
// Name: _EH4_CallFilterFunc(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_CallFilterFunc(int (*this)(void))
{
  return this();
}

//------------------------------------------------------------------------------
// Address: 0x10043399
// Name: _EH4_TransferToHandler(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __thiscall _EH4_TransferToHandler(int (__fastcall *this)(_DWORD, _DWORD))
{
  _NLG_Notify(a1: 1);
  return this(a1: 0, a2: 0);
}

//------------------------------------------------------------------------------
// Address: 0x100433B2
// Name: _EH4_GlobalUnwind2(x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __fastcall _EH4_GlobalUnwind2(PVOID TargetFrame, PEXCEPTION_RECORD ExceptionRecord)
{
  RtlUnwind(TargetFrame, TargetIp: &ReturnPoint_0, ExceptionRecord, ReturnValue: nullptr);
}

//------------------------------------------------------------------------------
// Address: 0x100433CB
// Name: _EH4_LocalUnwind(x,x,x,x)
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __fastcall _EH4_LocalUnwind(int a1, unsigned int a2, int a3, _DWORD *a4)
{
  return _local_unwind4(a1: a4, a2: a1, a3: a2);
}

//------------------------------------------------------------------------------
// Address: 0x100433E2
// Name: __read_nolock
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int __cdecl _read_nolock(int fh, char *inputbuf, unsigned int cnt)
{
  unsigned int v3; // edx
  int result; // eax
  ioinfo **v5; // edi
  ioinfo *v6; // eax
  int v7; // esi
  char v8; // cl
  char *v9; // ebx
  char *v10; // ecx
  char *v11; // eax
  char v12; // cl
  bool v13; // zf
  ioinfo *v14; // ecx
  char v15; // cl
  ioinfo *v16; // ecx
  char v17; // cl
  ioinfo *v18; // ecx
  ioinfo *v19; // eax
  char *v20; // eax
  char *v21; // ebx
  char v22; // al
  char *v23; // eax
  char *v24; // ebx
  int v25; // ecx
  int v26; // eax
  char v27; // dl
  char *v28; // ebx
  int v29; // ebx
  DWORD LastError; // eax
  ioinfo *v31; // edx
  BOOL v32; // ecx
  char *v33; // ebx
  int v34; // ecx
  char *v35; // esi
  __int16 v36; // [esp-Ch] [ebp-2Ch]
  unsigned int inputsize; // [esp+4h] [ebp-1Ch]
  int os_read; // [esp+8h] [ebp-18h] BYREF
  int retval; // [esp+Ch] [ebp-14h]
  void *buf; // [esp+10h] [ebp-10h]
  int bytes_read; // [esp+14h] [ebp-Ch]
  wchar_t wpeekchr; // [esp+18h] [ebp-8h] BYREF
  char tmode; // [esp+1Eh] [ebp-2h]
  char peekchr; // [esp+1Fh] [ebp-1h] BYREF
  char *p; // [esp+30h] [ebp+10h]
  char *pa; // [esp+30h] [ebp+10h]

  v3 = cnt;
  retval = -2;
  inputsize = cnt;
  if ( fh == -2 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    return -1;
  }
  if ( fh < 0 || fh >= _nhandle )
  {
    *__doserrno() = 0;
    *_errno() = 9;
    _invalid_parameter_noinfo();
    return -1;
  }
  v5 = &__pioinfo[fh >> 5];
  v6 = *v5;
  v7 = (fh & 0x1F) << 6;
  v8 = *(&(*v5)->osfile + v7);
  if ( (v8 & 1) == 0 )
  {
    *__doserrno() = 0;
    *_errno() = 9;
LABEL_19:
    _invalid_parameter_noinfo();
    return -1;
  }
  if ( cnt > 0x7FFFFFFF )
    goto LABEL_18;
  bytes_read = 0;
  if ( cnt == 0 || (v8 & 2) != 0 )
    return 0;
  if ( inputbuf == nullptr )
    goto LABEL_18;
  tmode = (char)(2 * *((_BYTE *)v6 + v7 + 36)) >> 1;
  if ( tmode != 1 )
  {
    if ( tmode != 2 )
    {
LABEL_16:
      v9 = inputbuf;
      buf = inputbuf;
      goto LABEL_26;
    }
    if ( (cnt & 1) == 0 )
    {
      cnt &= ~1u;
      goto LABEL_16;
    }
LABEL_18:
    *__doserrno() = 0;
    *_errno() = 22;
    goto LABEL_19;
  }
  if ( (cnt & 1) != 0 )
    goto LABEL_18;
  cnt = 4;
  if ( v3 >> 1 >= 4 )
    cnt = v3 >> 1;
  v9 = (char *)operator new(nSize: cnt);
  buf = v9;
  if ( v9 == nullptr )
  {
    *_errno() = 12;
    *__doserrno() = 8;
    return -1;
  }
  *(_QWORD *)&(*v5)->pipech2[v7 + 3] = _lseeki64_nolock(fh, pos: 0, mthd: 1);
LABEL_26:
  v10 = (char *)*v5 + v7;
  v11 = v9;
  if ( (v10[4] & 0x48) != 0 )
  {
    v12 = v10[5];
    if ( v12 != 10 && cnt != 0 )
    {
      --cnt;
      v13 = tmode == 0;
      *v9 = v12;
      v14 = *v5;
      v11 = v9 + 1;
      bytes_read = 1;
      *(&v14->pipech + v7) = 10;
      if ( !v13 )
      {
        v15 = (*v5)->pipech2[v7];
        if ( v15 != 10 && cnt != 0 )
        {
          *v11 = v15;
          v16 = *v5;
          v11 = v9 + 2;
          --cnt;
          v13 = tmode == 1;
          bytes_read = 2;
          v16->pipech2[v7] = 10;
          if ( v13 )
          {
            v17 = (*v5)->pipech2[v7 + 1];
            if ( v17 != 10 && cnt != 0 )
            {
              *v11 = v17;
              v18 = *v5;
              v11 = v9 + 3;
              --cnt;
              bytes_read = 3;
              v18->pipech2[v7 + 1] = 10;
            }
          }
        }
      }
    }
  }
  if ( !ReadFile(
          hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
          lpBuffer: v11,
          nNumberOfBytesToRead: cnt,
          lpNumberOfBytesRead: (LPDWORD)&os_read,
          lpOverlapped: nullptr)
    || os_read < 0
    || os_read > cnt )
  {
    LastError = GetLastError();
    if ( LastError == 5 )
    {
      *_errno() = 9;
      *__doserrno() = 5;
      goto LABEL_93;
    }
    if ( LastError == 109 )
    {
      retval = 0;
      goto error_return;
    }
    goto LABEL_92;
  }
  v19 = *v5;
  bytes_read += os_read;
  v20 = &v19->osfile + v7;
  if ( *v20 < 0 )
  {
    if ( tmode != 2 )
    {
      if ( os_read != 0 && *v9 == 10 )
        *v20 |= 4u;
      else
        *v20 &= ~4u;
      v21 = (char *)buf;
      p = (char *)buf;
      bytes_read += (int)buf;
      if ( (unsigned int)buf < bytes_read )
      {
        do
        {
          v22 = *p;
          if ( *p == 26 )
          {
            v23 = &(*v5)->osfile + v7;
            if ( (*v23 & 0x40) != 0 )
              *v21++ = *p;
            else
              *v23 |= 2u;
            break;
          }
          if ( v22 == 13 )
          {
            if ( (unsigned int)p < bytes_read - 1 )
            {
              if ( p[1] == 10 )
              {
                p += 2;
                goto LABEL_52;
              }
              ++p;
LABEL_63:
              *v21 = 13;
LABEL_64:
              ++v21;
              continue;
            }
            ++p;
            if ( !ReadFile(
                    hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
                    lpBuffer: &peekchr,
                    nNumberOfBytesToRead: 1u,
                    lpNumberOfBytesRead: (LPDWORD)&os_read,
                    lpOverlapped: nullptr)
              && GetLastError() != 0
              || os_read == 0 )
            {
              goto LABEL_63;
            }
            if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
            {
              if ( peekchr != 10 )
              {
                *v21 = 13;
                *(&(*v5)->pipech + v7) = peekchr;
                goto LABEL_64;
              }
LABEL_52:
              *v21 = 10;
              goto LABEL_64;
            }
            if ( v21 == buf && peekchr == 10 )
              goto LABEL_52;
            _lseeki64_nolock(fh, pos: -1, mthd: 1);
            if ( peekchr != 10 )
              goto LABEL_63;
          }
          else
          {
            *v21++ = v22;
            ++p;
          }
        }
        while ( (unsigned int)p < bytes_read );
      }
      bytes_read = v21 - (_BYTE *)buf;
      if ( tmode != 1 || v21 == buf )
        goto error_return;
      v24 = v21 - 1;
      LOBYTE(v25) = *v24;
      if ( *v24 < 0 )
      {
        v26 = 1;
        v25 = (unsigned __int8)v25;
        while ( _lookuptrailbytes[v25] == 0 && v26 <= 4 && v24 >= buf )
        {
          v25 = (unsigned __int8)*--v24;
          ++v26;
        }
        v27 = *v24;
        if ( _lookuptrailbytes[(unsigned __int8)*v24] == 0 )
        {
          *_errno() = 42;
LABEL_93:
          retval = -1;
          goto error_return;
        }
        if ( _lookuptrailbytes[(unsigned __int8)*v24] + 1 == v26 )
        {
          v24 += v26;
        }
        else if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
        {
          v28 = v24 + 1;
          *(&(*v5)->pipech + v7) = v27;
          if ( v26 >= 2 )
            (*v5)->pipech2[v7] = *v28++;
          if ( v26 == 3 )
            (*v5)->pipech2[v7 + 1] = *v28++;
          v24 = &v28[-v26];
        }
        else
        {
          _lseeki64_nolock(fh, pos: -v26, mthd: 1);
        }
      }
      else
      {
        ++v24;
      }
      v29 = v24 - (_BYTE *)buf;
      bytes_read = MultiByteToWideChar(
                     CodePage: 0xFDE9u,
                     dwFlags: 0,
                     lpMultiByteStr: (LPCCH)buf,
                     cbMultiByte: v29,
                     lpWideCharStr: (LPWSTR)inputbuf,
                     cchWideChar: inputsize >> 1);
      if ( bytes_read != 0 )
      {
        v31 = *v5;
        v32 = bytes_read != v29;
        bytes_read *= 2;
        *(int *)((char *)&v31->utf8translations + v7) = v32;
        goto error_return;
      }
      LastError = GetLastError();
LABEL_92:
      _dosmaperr(oserrno: LastError);
      goto LABEL_93;
    }
    if ( os_read != 0 && *(_WORD *)v9 == 10 )
      *v20 |= 4u;
    else
      *v20 &= ~4u;
    v33 = (char *)buf;
    pa = (char *)buf;
    bytes_read += (int)buf;
    if ( (unsigned int)buf >= bytes_read )
    {
LABEL_129:
      bytes_read = v33 - (_BYTE *)buf;
      goto error_return;
    }
    while ( 1 )
    {
      v34 = *(unsigned __int16 *)pa;
      if ( v34 == 26 )
      {
        v35 = &(*v5)->osfile + v7;
        if ( (*v35 & 0x40) != 0 )
        {
          *(_WORD *)v33 = *(_WORD *)pa;
          v33 += 2;
        }
        else
        {
          *v35 |= 2u;
        }
        goto LABEL_129;
      }
      if ( v34 == 13 )
      {
        if ( (unsigned int)pa < bytes_read - 2 )
        {
          if ( *((_WORD *)pa + 1) == 10 )
          {
            pa += 4;
            goto LABEL_110;
          }
          pa += 2;
LABEL_121:
          v36 = 13;
LABEL_122:
          *(_WORD *)v33 = v36;
          goto LABEL_123;
        }
        pa += 2;
        if ( !ReadFile(
                hFile: *(HANDLE *)((char *)&(*v5)->osfhnd + v7),
                lpBuffer: &wpeekchr,
                nNumberOfBytesToRead: 2u,
                lpNumberOfBytesRead: (LPDWORD)&os_read,
                lpOverlapped: nullptr)
          && GetLastError() != 0
          || os_read == 0 )
        {
          goto LABEL_121;
        }
        if ( (*(&(*v5)->osfile + v7) & 0x48) != 0 )
        {
          if ( wpeekchr != 10 )
          {
            *(_WORD *)v33 = 13;
            *(&(*v5)->pipech + v7) = wpeekchr;
            (*v5)->pipech2[v7] = HIBYTE(wpeekchr);
            (*v5)->pipech2[v7 + 1] = 10;
LABEL_123:
            v33 += 2;
            goto LABEL_124;
          }
LABEL_110:
          v36 = 10;
          goto LABEL_122;
        }
        if ( v33 == buf && wpeekchr == 10 )
          goto LABEL_110;
        _lseeki64_nolock(fh, pos: -2, mthd: 1);
        if ( wpeekchr != 10 )
          goto LABEL_121;
      }
      else
      {
        *(_WORD *)v33 = v34;
        v33 += 2;
        pa += 2;
      }
LABEL_124:
      if ( (unsigned int)pa >= bytes_read )
        goto LABEL_129;
    }
  }
error_return:
  if ( buf != inputbuf )
    free(pMem: buf);
  result = retval;
  if ( retval == -2 )
    return bytes_read;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10050DB0
// Name: _dynamic_initializer_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CleanupFunctions__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_CleanupFunctions__);
}

//------------------------------------------------------------------------------
// Address: 0x10050DC0
// Name: _dynamic_initializer_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ExitStopper__()
{
  return atexit(func: dynamic_atexit_destructor_for__g_ExitStopper__);
}

//------------------------------------------------------------------------------
// Address: 0x10050DD0
// Name: _anonymous_namespace_::_dynamic_initializer_for__g_arrCompileEntries__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int anonymous_namespace_::_dynamic_initializer_for__g_arrCompileEntries__()
{
  return atexit(func: anonymous_namespace_::_dynamic_atexit_destructor_for__g_arrCompileEntries__);
}

//------------------------------------------------------------------------------
// Address: 0x10050DE0
// Name: _dynamic_initializer_for__g_ShaderByteCode__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ShaderByteCode__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_ShaderByteCode.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ShaderByteCode__);
}

//------------------------------------------------------------------------------
// Address: 0x10050E00
// Name: _dynamic_initializer_for__g_ShaderToShaderInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ShaderToShaderInfo__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_ShaderToShaderInfo.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_ShaderToShaderInfo__);
}

//------------------------------------------------------------------------------
// Address: 0x10050E20
// Name: _dynamic_initializer_for__g_Master_ShaderHadError__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Master_ShaderHadError__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_Master_ShaderHadError.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_Master_ShaderHadError__);
}

//------------------------------------------------------------------------------
// Address: 0x10050E40
// Name: _dynamic_initializer_for__g_Master_ShaderWrittenToDisk__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Master_ShaderWrittenToDisk__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_Master_ShaderWrittenToDisk.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_Master_ShaderWrittenToDisk__);
}

//------------------------------------------------------------------------------
// Address: 0x10050E60
// Name: _dynamic_initializer_for__g_Master_CompilerMsgInfo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_Master_CompilerMsgInfo__()
{
  CUtlSymbolTable::CUtlSymbolTable(
    this: &g_Master_CompilerMsgInfo.m_SymbolTable,
    growSize: 0,
    initSize: 32,
    caseInsensitive: true);
  return atexit(func: dynamic_atexit_destructor_for__g_Master_CompilerMsgInfo__);
}

//------------------------------------------------------------------------------
// Address: 0x10051950
// Name: _dynamic_atexit_destructor_for__g_ExitStopper__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_ExitStopper__()
{
  if ( g_bStopOnExit )
  {
    _Warning(a1: "\nPress any key to quit.\n");
    getch();
  }
}

//------------------------------------------------------------------------------
// Address: 0x10051970
// Name: _dynamic_atexit_destructor_for__g_CleanupFunctions__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl dynamic_atexit_destructor_for__g_CleanupFunctions__()
{
  CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int>> *,unsigned short>,unsigned short>>::RemoveAll(this: (CUtlLinkedList<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short,0,unsigned short,CUtlMemory<UtlLinkedListElem_t<CUtlVector<char,CUtlMemory<char,int> > *,unsigned short>,unsigned short> > *)&g_CleanupFunctions);
  if ( g_CleanupFunctions.m_Memory.m_nGrowSize >= 0 )
  {
    if ( g_CleanupFunctions.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: g_CleanupFunctions.m_Memory.m_pMemory);
      g_CleanupFunctions.m_Memory.m_pMemory = nullptr;
    }
    g_CleanupFunctions.m_Memory.m_nAllocationCount = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x100519C0
// Name: _CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
void __cdecl CmdLib_FPrintf_::_2_::_dynamic_atexit_destructor_for__buf__()
{
  CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>::~CUtlVector<CWorkerAccumState<CThreadNullMutex>::SubProcess *,CUtlMemory<CWorkerAccumState<CThreadNullMutex>::SubProcess *,int>>(this: (CUtlVector<CFileResponse,CUtlMemory<CFileResponse,int> > *)&buf);
}
