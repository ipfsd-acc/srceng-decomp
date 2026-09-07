// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: utils/ps3/ps3shaderoptimizer/ps3shaderoptimizer.cpp
// Functions: 131
// ============================================================

#include "utils\ps3\ps3shaderoptimizer\ps3shaderoptimizer.h"

//------------------------------------------------------------------------------
// Address: 0x00401040
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
// Address: 0x004010C0
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Min(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Min(
        std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004010E0
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Min(struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Min(
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401100
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Min(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Min(
        std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401120
// Name: protected: void std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Rrotate(
        std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Parent; // ecx

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
// Address: 0x00401180
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Max(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Max(
        std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004011A0
// Name: protected: void std::_Tree<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Rrotate(
        std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Parent; // ecx

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
// Address: 0x00401200
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Max(struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Max(
        std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401220
// Name: public: static struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Min(struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *__cdecl std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Min(
        std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Left; i->_Isnil == 0; i = i->_Left )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401240
// Name: protected: void std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Rrotate(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Parent; // ecx

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
// Address: 0x004012A0
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Max(struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Max(
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004012C0
// Name: protected: void std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Lrotate(
        std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Parent; // ecx

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
// Address: 0x00401320
// Name: protected: void std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Rrotate(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Rrotate(
        std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Left; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Parent; // ecx

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
// Address: 0x00401380
// Name: public: static struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Max(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *__cdecl std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Max(
        std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Pnode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *i; // ecx

  result = _Pnode;
  for ( i = _Pnode->_Right; i->_Isnil == 0; i = i->_Right )
    result = i;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004013B0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *i; // edx

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
// Address: 0x00401420
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v5; // edx

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
// Address: 0x00401480
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v5; // edx

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
// Address: 0x004014E0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v5; // edx

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
// Address: 0x00401540
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>,struct std::_Iterator_base0>::operator--(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>,std::_Iterator_base0>::operator--(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v5; // edx

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
// Address: 0x004015C0
// Name: void std::_Push_heap<struct OptimalComboScheduleFileRecord_t __near *,int,struct OptimalComboScheduleFileRecord_t>(struct OptimalComboScheduleFileRecord_t __near *,int,int,struct OptimalComboScheduleFileRecord_t __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Push_heap<OptimalComboScheduleFileRecord_t *,int,OptimalComboScheduleFileRecord_t>(
        OptimalComboScheduleFileRecord_t *_First,
        int _Hole,
        int _Top,
        OptimalComboScheduleFileRecord_t *_Val)
{
  int v4; // ecx
  int i; // eax
  OptimalComboScheduleFileRecord_t *v6; // edx

  v4 = _Hole;
  for ( i = (_Hole - 1) / 2; _Top < v4; i = (i - 1) / 2 )
  {
    v6 = &_First[i];
    if ( v6->m_nComboHash >= _Val->m_nComboHash )
      break;
    _First[v4] = *v6;
    v4 = i;
  }
  _First[v4] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x00401640
// Name: PrintGlobalStatistics
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintGlobalStatistics(const std::vector<CompileStats_t> *compileStats)
{
  double v1; // xmm0_8
  const std::vector<CompileStats_t> *v2; // edi
  CompileStats_t *Myfirst; // esi
  int v4; // ecx
  char v5; // bl
  unsigned int v6; // edx
  double v7; // xmm2_8
  double v8; // xmm3_8
  double v9; // xmm1_8
  __int16 *p_m_nOrigRegs; // eax
  unsigned int v11; // esi
  double v12; // xmm5_8
  double v13; // xmm1_8
  double v14; // xmm2_8
  double v15; // xmm0_8
  double v16; // xmm3_8
  double v17; // xmm5_8
  double v18; // xmm2_8
  double v19; // xmm3_8
  __int16 *v20; // eax
  unsigned int v21; // ecx
  double v22; // st7
  double flTotalOptRegs; // [esp+24h] [ebp-18h]
  double flTotalOptRegsa; // [esp+24h] [ebp-18h]
  double flTotalOptCycles; // [esp+2Ch] [ebp-10h]
  double flTotalOptCyclesa; // [esp+2Ch] [ebp-10h]

  v1 = 0.0;
  v2 = compileStats;
  Myfirst = compileStats->_Myfirst;
  v4 = compileStats->_Mylast - compileStats->_Myfirst;
  v5 = 0;
  v6 = 0;
  v7 = 0.0;
  v8 = 0.0;
  v9 = 0.0;
  flTotalOptCycles = 0.0;
  flTotalOptRegs = 0.0;
  if ( v4 >= 4 )
  {
    p_m_nOrigRegs = &Myfirst->m_nOrigRegs;
    v11 = ((unsigned int)(v4 - 4) >> 2) + 1;
    v6 = 4 * v11;
    do
    {
      v12 = (double)*p_m_nOrigRegs + v9;
      v13 = (double)p_m_nOrigRegs[1] + v7;
      v14 = (double)p_m_nOrigRegs[2] + v8;
      if ( *(_DWORD *)(p_m_nOrigRegs + 7) == 2 )
        v5 = 1;
      v15 = (double)p_m_nOrigRegs[31] + (double)*(p_m_nOrigRegs - 1) + v1;
      v16 = (double)p_m_nOrigRegs[32] + v12;
      v17 = (double)p_m_nOrigRegs[34] + v14;
      if ( *(_DWORD *)(p_m_nOrigRegs + 39) == 2 )
        v5 = 1;
      v18 = (double)p_m_nOrigRegs[64] + v16;
      v19 = (double)p_m_nOrigRegs[65] + (double)p_m_nOrigRegs[33] + v13;
      if ( *(_DWORD *)(p_m_nOrigRegs + 71) == 2 )
        v5 = 1;
      v1 = (double)p_m_nOrigRegs[95] + (double)p_m_nOrigRegs[63] + v15;
      v9 = (double)p_m_nOrigRegs[96] + v18;
      v7 = (double)p_m_nOrigRegs[97] + v19;
      v8 = (double)p_m_nOrigRegs[98] + (double)p_m_nOrigRegs[66] + v17;
      if ( *(_DWORD *)(p_m_nOrigRegs + 103) == 2 )
        v5 = 1;
      p_m_nOrigRegs += 128;
      --v11;
    }
    while ( v11 != 0 );
    Myfirst = compileStats->_Myfirst;
    v2 = compileStats;
    flTotalOptRegs = v8;
    flTotalOptCycles = v7;
  }
  if ( v6 < v4 )
  {
    v20 = &Myfirst[v6].m_nOrigRegs;
    v21 = v4 - v6;
    do
    {
      v1 = v1 + (double)*(v20 - 1);
      v9 = v9 + (double)*v20;
      v7 = v7 + (double)v20[1];
      v8 = v8 + (double)v20[2];
      if ( *(_DWORD *)(v20 + 7) == 2 )
        v5 = 1;
      v20 += 32;
      --v21;
    }
    while ( v21 != 0 );
    flTotalOptRegs = v8;
    flTotalOptCycles = v7;
  }
  v22 = 1.0 / (double)(unsigned int)(v2->_Mylast - Myfirst);
  flTotalOptCyclesa = flTotalOptCycles * v22;
  flTotalOptRegsa = v22 * flTotalOptRegs;
  printf(format: "Global statistics:\n");
  printf(format: " Original ave. cycles: %3.3f, Ave. regs: %3.3f\n", v22 * v1, v22 * v9);
  if ( v5 != 0 )
  {
    printf(format: " Optimized ave. cycles: %3.3f, Ave. regs: %3.3f\n", flTotalOptCyclesa, flTotalOptRegsa);
    printf(format: " Average improvement: %3.2f%%\n", (1.0 - flTotalOptCyclesa / (v22 * v1)) * 100.0);
  }
  printf(format: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00401920
// Name: PrintCategorizedStatistics
// Source: json
//------------------------------------------------------------------------------
void __usercall PrintCategorizedStatistics(const std::vector<CompileStats_t> *compileStats@<eax>)
{
  long double *p_m_flMaxOrigCycles; // eax
  int j; // ecx
  CompileStats_t *Myfirst; // ecx
  int v5; // eax
  __int16 *p_m_nOrigCycles; // ecx
  int k; // ebx
  int v8; // esi
  unsigned int *p_i; // eax
  int v10; // edx
  unsigned int v11; // eax
  PrintCategorizedStatistics::__l2::CategoryStats_t *v12; // eax
  double v13; // xmm0_8
  int v14; // edx
  double m_flMinOrigCycles; // xmm1_8
  double *p_m_flMinOrigCycles; // edi
  bool v17; // cc
  double *v18; // esi
  int v19; // edx
  double v20; // xmm0_8
  int v21; // edx
  double m_flMinOptCycles; // xmm1_8
  double *p_m_flMinOptCycles; // esi
  int v24; // edx
  double *p_m_flMaxOptCycles; // edx
  int v26; // edi
  unsigned int *p_m_nTotalCombos; // esi
  unsigned int v28; // ebx
  int *v29; // eax
  double v30; // xmm1_8
  double v31; // st7
  double v32; // xmm1_8
  double v33; // [esp+10h] [ebp-8FCh]
  PrintCategorizedStatistics::__l2::CategoryStats_t categoryStats[31]; // [esp+2Ch] [ebp-8E0h] BYREF
  double v35; // [esp+8E4h] [ebp-28h] BYREF
  double v36; // [esp+8ECh] [ebp-20h] BYREF
  double v37; // [esp+8F4h] [ebp-18h] BYREF
  int v38; // [esp+8FCh] [ebp-10h] BYREF
  double v39; // [esp+900h] [ebp-Ch] BYREF
  unsigned int i; // [esp+908h] [ebp-4h] BYREF

  memset(dst: (unsigned __int8 *)categoryStats, value: 0, count: sizeof(categoryStats));
  p_m_flMaxOrigCycles = &categoryStats[0].m_flMaxOrigCycles;
  for ( j = 31; j != 0; --j )
  {
    *(p_m_flMaxOrigCycles - 1) = 1000000000.0;
    *p_m_flMaxOrigCycles = -1000000000.0;
    p_m_flMaxOrigCycles[3] = 1000000000.0;
    p_m_flMaxOrigCycles[4] = -1000000000.0;
    p_m_flMaxOrigCycles += 9;
  }
  Myfirst = compileStats->_Myfirst;
  v5 = compileStats->_Mylast - compileStats->_Myfirst;
  if ( v5 != 0 )
  {
    v38 = 30;
    p_m_nOrigCycles = &Myfirst->m_nOrigCycles;
    for ( k = v5; k != 0; --k )
    {
      v8 = *p_m_nOrigCycles;
      i = v8 / 10;
      p_i = &i;
      if ( v8 / 10 >= 30 )
        p_i = (unsigned int *)&v38;
      v10 = *p_m_nOrigCycles;
      v11 = *p_i;
      ++categoryStats[v11].m_nTotalCombos;
      v12 = &categoryStats[v11];
      v13 = (double)v10;
      v14 = p_m_nOrigCycles[1];
      v12->m_flTotalOrigCycles = v13 + v12->m_flTotalOrigCycles;
      v12->m_flTotalOrigRegs = (double)v14 + v12->m_flTotalOrigRegs;
      m_flMinOrigCycles = v12->m_flMinOrigCycles;
      v39 = v13;
      p_m_flMinOrigCycles = &v39;
      if ( m_flMinOrigCycles <= v13 )
        p_m_flMinOrigCycles = &v12->m_flMinOrigCycles;
      v12->m_flMinOrigCycles = *p_m_flMinOrigCycles;
      v17 = (double)v8 <= v12->m_flMaxOrigCycles;
      v35 = (double)v8;
      v18 = &v35;
      if ( v17 )
        v18 = &v12->m_flMaxOrigCycles;
      v19 = p_m_nOrigCycles[2];
      v12->m_flMaxOrigCycles = *v18;
      v20 = (double)v19;
      v21 = p_m_nOrigCycles[3];
      v12->m_flTotalOptCycles = v20 + v12->m_flTotalOptCycles;
      v12->m_flTotalOptRegs = (double)v21 + v12->m_flTotalOptRegs;
      m_flMinOptCycles = v12->m_flMinOptCycles;
      v36 = v20;
      p_m_flMinOptCycles = &v36;
      if ( m_flMinOptCycles <= v20 )
        p_m_flMinOptCycles = &v12->m_flMinOptCycles;
      v24 = p_m_nOrigCycles[2];
      v12->m_flMinOptCycles = *p_m_flMinOptCycles;
      v17 = (double)v24 <= v12->m_flMaxOptCycles;
      v37 = (double)v24;
      p_m_flMaxOptCycles = &v37;
      if ( v17 )
        p_m_flMaxOptCycles = &v12->m_flMaxOptCycles;
      p_m_nOrigCycles += 32;
      v12->m_flMaxOptCycles = *p_m_flMaxOptCycles;
    }
  }
  printf(format: "Categorized statistics:\n");
  v26 = 0;
  i = 0;
  p_m_nTotalCombos = &categoryStats[0].m_nTotalCombos;
  do
  {
    v28 = *p_m_nTotalCombos;
    if ( *p_m_nTotalCombos != 0 )
    {
      v38 = v26;
      HIDWORD(v39) = 1;
      v29 = &v38;
      if ( v26 <= 1 )
        v29 = (int *)&v39 + 1;
      printf(format: " Category %u, %u-%u original cycles, total combos: %u:\n", i, *v29, v26 + 9, v28);
      HIDWORD(v39) = v28;
      v30 = *((double *)p_m_nTotalCombos - 6);
      v36 = *((double *)p_m_nTotalCombos - 8);
      v39 = 1.0 / (double)v28;
      printf(
        format: "  Original  ave. cycles: %3.3f (Range %3.3f-%3.3f), Ave. regs: %3.3f\n",
        v36 * v39,
        *((double *)p_m_nTotalCombos - 7),
        v30,
        v39 * *((double *)p_m_nTotalCombos - 5));
      v31 = *((double *)p_m_nTotalCombos - 1) * v39;
      v33 = *((double *)p_m_nTotalCombos - 2);
      v32 = *((double *)p_m_nTotalCombos - 3);
      v37 = *((double *)p_m_nTotalCombos - 4);
      printf(format: "  Optimized ave. cycles: %3.3f (Range %3.3f-%3.3f), Ave. regs: %3.3f\n", v37 * v39, v32, v33, v31);
      printf(format: "  Average improvement: %3.2f%%\n", (1.0 - v37 / v36) * 100.0);
    }
    ++i;
    v26 += 10;
    p_m_nTotalCombos += 18;
  }
  while ( (unsigned int)v26 < 0x136 );
  printf(format: "\n");
}

//------------------------------------------------------------------------------
// Address: 0x00401BF0
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
// Address: 0x00401C60
// Name: public: struct CompileStats_t __near * std::allocator<struct CompileStats_t>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
CompileStats_t *__thiscall std::allocator<CompileStats_t>::allocate(
        std::allocator<CompileStats_t> *this,
        unsigned int _Count)
{
  CompileStats_t *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x3FFFFFF || (result = (CompileStats_t *)operator new(size: _Count << 6)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401CC0
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *i; // edx

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
// Address: 0x00401D10
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // edx

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
// Address: 0x00401D60
// Name: public: class std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>,struct std::_Iterator_base0> __near & std::_Tree_unchecked_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>,struct std::_Iterator_base0>::operator++(void)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >,std::_Iterator_base0> *__thiscall std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>,std::_Iterator_base0>::operator++(
        std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >,std::_Iterator_base0> *this)
{
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >,std::_Iterator_base0> *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Ptr; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *j; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *i; // edx

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
// Address: 0x00401DC0
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near * std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::allocator<std::string>::allocate(std::allocator<std::string > *this, unsigned int _Count)
{
  std::string *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x9249249 || (result = (std::string *)operator new(size: 28 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401E20
// Name: public: struct SchedulerUsage_t __near * std::allocator<struct SchedulerUsage_t>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
SchedulerUsage_t *__thiscall std::allocator<SchedulerUsage_t>::allocate(
        std::allocator<SchedulerUsage_t> *this,
        unsigned int _Count)
{
  SchedulerUsage_t *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0 && (_Count > 0x1FFFFFFF || (result = (SchedulerUsage_t *)operator new(size: 8 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401E80
// Name: public: struct OptimalComboScheduleFileRecord_t __near * std::allocator<struct OptimalComboScheduleFileRecord_t>::allocate(unsigned int)
// Source: json
//------------------------------------------------------------------------------
OptimalComboScheduleFileRecord_t *__thiscall std::allocator<OptimalComboScheduleFileRecord_t>::allocate(
        std::allocator<OptimalComboScheduleFileRecord_t> *this,
        unsigned int _Count)
{
  OptimalComboScheduleFileRecord_t *result; // eax
  std::exception pExceptionObject; // [esp+0h] [ebp-Ch] BYREF

  result = nullptr;
  if ( _Count != 0
    && (_Count > 0xFFFFFFF || (result = (OptimalComboScheduleFileRecord_t *)operator new(size: 16 * _Count)) == nullptr) )
  {
    _Count = 0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Count);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00401EE0
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
// Address: 0x00401F70
// Name: protected: void std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Lrotate(
        std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Parent; // ecx

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
// Address: 0x00401FD0
// Name: protected: void std::_Tree<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Lrotate(
        std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Parent; // ecx

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
// Address: 0x00402030
// Name: protected: void std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Lrotate(struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Lrotate(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Parent; // ecx

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
// Address: 0x00402090
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
    result = (char *)operator new(size: _Count);
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
// Address: 0x004020E0
// Name: void std::_Adjust_heap<struct SchedulerUsage_t __near *,int,struct SchedulerUsage_t>(struct SchedulerUsage_t __near *,int,int,struct SchedulerUsage_t __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<SchedulerUsage_t *,int,SchedulerUsage_t>(
        SchedulerUsage_t *_First,
        int _Hole,
        int _Bottom,
        SchedulerUsage_t *_Val)
{
  int v4; // esi
  int v5; // eax
  bool i; // zf
  int j; // eax

  v4 = _Hole;
  v5 = 2 * _Hole + 2;
  for ( i = v5 == _Bottom; v5 < _Bottom; i = v5 == _Bottom )
  {
    if ( _First[v5].m_nTotalUses > _First[v5 - 1].m_nTotalUses )
      --v5;
    _First[v4] = _First[v5];
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    _First[v4] = _First[_Bottom - 1];
    v4 = _Bottom - 1;
  }
  for ( j = (v4 - 1) / 2; _Hole < v4; j = (j - 1) / 2 )
  {
    if ( _First[j].m_nTotalUses <= _Val->m_nTotalUses )
      break;
    _First[v4] = _First[j];
    v4 = j;
  }
  _First[v4] = *_Val;
}

//------------------------------------------------------------------------------
// Address: 0x00402180
// Name: void std::_Adjust_heap<struct OptimalComboScheduleFileRecord_t __near *,int,struct OptimalComboScheduleFileRecord_t>(struct OptimalComboScheduleFileRecord_t __near *,int,int,struct OptimalComboScheduleFileRecord_t __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Adjust_heap<OptimalComboScheduleFileRecord_t *,int,OptimalComboScheduleFileRecord_t>(
        OptimalComboScheduleFileRecord_t *_First,
        int _Hole,
        int _Bottom,
        OptimalComboScheduleFileRecord_t *_Val)
{
  int v4; // edx
  int v5; // eax
  bool i; // zf

  v4 = _Hole;
  v5 = 2 * _Hole + 2;
  for ( i = v5 == _Bottom; v5 < _Bottom; i = v5 == _Bottom )
  {
    if ( _First[v5].m_nComboHash < _First[v5 - 1].m_nComboHash )
      --v5;
    _First[v4] = _First[v5];
    v4 = v5;
    v5 = 2 * v5 + 2;
  }
  if ( i )
  {
    _First[v4] = _First[_Bottom - 1];
    v4 = _Bottom - 1;
  }
  std::_Push_heap<OptimalComboScheduleFileRecord_t *,int,OptimalComboScheduleFileRecord_t>(
    _First,
    _Hole: v4,
    _Top: _Hole,
    _Val);
}

//------------------------------------------------------------------------------
// Address: 0x00402220
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
    operator delete(p: v3->_Bx._Ptr);
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
// Address: 0x00402360
// Name: protected: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>> std::_Tree<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > *__thiscall std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Insert(
        std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x1FFFFFFE )
  {
    operator delete(p: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  this->_Mysize = Mysize + 1;
  v6 = _Newnode;
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
LABEL_50:
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
        goto LABEL_50;
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
// Address: 0x00402590
// Name: protected: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>> std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Insert(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x1FFFFFFE )
  {
    operator delete(p: _Newnode);
    std::_Xlength_error(_Message: "map/set<T> too long");
  }
  this->_Mysize = Mysize + 1;
  v6 = _Newnode;
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
LABEL_50:
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
        goto LABEL_50;
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
// Address: 0x004027C0
// Name: public: struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near * std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Buynode<unsigned __int64 __near &>(unsigned __int64 __near &)
// Source: json
//------------------------------------------------------------------------------
std::pair<int const ,int> *__thiscall std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Buynode<unsigned __int64 &>(
        std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this,
        unsigned __int64 *_Val)
{
  std::pair<int const ,int> *v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *p; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::pair<int const ,int> *)operator new(size: 0x20u);
  p = v3;
  if ( v3 == nullptr )
  {
    _Val = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Val);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  v3->first = (const int)this->_Myhead;
  v3->second = (int)this->_Myhead;
  v3[1].first = (const int)this->_Myhead;
  LOWORD(v3[3].first) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<std::pair<int const,int>>,std::pair<int const,int>,std::pair<int const,int> &>(
    _Alval: (std::allocator<std::pair<int const ,int> > *)&this->_Alval,
    _Pdest: v3 + 2,
    _Src: (std::pair<int const ,int> *)_Val);
  v9 = -1;
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x00402880
// Name: void std::_Cons_val<class std::allocator<struct OptimalComboScheduleFileRecord_t>,struct OptimalComboScheduleFileRecord_t,struct OptimalComboScheduleFileRecord_t>(class std::allocator<struct OptimalComboScheduleFileRecord_t> __near &,struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<OptimalComboScheduleFileRecord_t>,OptimalComboScheduleFileRecord_t,OptimalComboScheduleFileRecord_t>(
        std::allocator<OptimalComboScheduleFileRecord_t> *_Alval,
        OptimalComboScheduleFileRecord_t *_Pdest,
        OptimalComboScheduleFileRecord_t *_Src)
{
  if ( _Pdest != nullptr )
    *_Pdest = *_Src;
}

//------------------------------------------------------------------------------
// Address: 0x004028B0
// Name: struct OptimalComboScheduleFileRecord_t __near * std::_Uninit_move<struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,class std::allocator<struct OptimalComboScheduleFileRecord_t>,struct OptimalComboScheduleFileRecord_t>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,class std::allocator<struct OptimalComboScheduleFileRecord_t> __near &,struct OptimalComboScheduleFileRecord_t __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
OptimalComboScheduleFileRecord_t *__cdecl std::_Uninit_move<OptimalComboScheduleFileRecord_t *,OptimalComboScheduleFileRecord_t *,std::allocator<OptimalComboScheduleFileRecord_t>,OptimalComboScheduleFileRecord_t>(
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Last,
        OptimalComboScheduleFileRecord_t *_Dest,
        std::allocator<OptimalComboScheduleFileRecord_t> *_Al)
{
  _DWORD v7[7]; // [esp+0h] [ebp-1Ch] BYREF

  v7[3] = v7;
  v7[6] = 0;
  while ( _First != _Last )
    std::_Cons_val<std::allocator<OptimalComboScheduleFileRecord_t>,OptimalComboScheduleFileRecord_t,OptimalComboScheduleFileRecord_t>(
      _Alval: _Al,
      _Pdest: _Dest++,
      _Src: _First++);
  return _Dest;
}

//------------------------------------------------------------------------------
// Address: 0x00402930
// Name: void std::_Make_heap<struct SchedulerUsage_t __near *,int,struct SchedulerUsage_t>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,int __near *,struct SchedulerUsage_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<SchedulerUsage_t *,int,SchedulerUsage_t>(
        SchedulerUsage_t *_First,
        SchedulerUsage_t *_Last)
{
  int v3; // edi
  int v4; // eax
  SchedulerUsage_t *v5; // ebx
  int m_nScheduleIndex; // edx
  int v7; // eax
  int i; // esi
  int j; // eax
  int _Val_4; // [esp+8h] [ebp-8h]
  SchedulerUsage_t *_Firsta; // [esp+18h] [ebp+8h]
  int _Bottom; // [esp+1Ch] [ebp+Ch]

  _Bottom = _Last - _First;
  v3 = _Bottom / 2;
  if ( _Bottom / 2 > 0 )
  {
    v4 = 2 * v3 + 2;
    v5 = &_First[v3];
    while ( 1 )
    {
      m_nScheduleIndex = v5[-1].m_nScheduleIndex;
      --v5;
      v7 = v4 - 2;
      _Val_4 = v5->m_nTotalUses;
      --v3;
      _Firsta = (SchedulerUsage_t *)v7;
      for ( i = v3; v7 < _Bottom; v7 = 2 * v7 + 2 )
      {
        if ( _First[v7].m_nTotalUses > _First[v7 - 1].m_nTotalUses )
          --v7;
        _First[i].m_nScheduleIndex = _First[v7].m_nScheduleIndex;
        _First[i].m_nTotalUses = _First[v7].m_nTotalUses;
        i = v7;
      }
      if ( v7 == _Bottom )
      {
        _First[i].m_nScheduleIndex = _First[_Bottom - 1].m_nScheduleIndex;
        _First[i].m_nTotalUses = _First[_Bottom - 1].m_nTotalUses;
        i = _Bottom - 1;
      }
      for ( j = (i - 1) / 2; v3 < i; j = (j - 1) / 2 )
      {
        if ( _First[j].m_nTotalUses <= _Val_4 )
          break;
        _First[i].m_nScheduleIndex = _First[j].m_nScheduleIndex;
        _First[i].m_nTotalUses = _First[j].m_nTotalUses;
        i = j;
      }
      _First[i].m_nScheduleIndex = m_nScheduleIndex;
      _First[i].m_nTotalUses = _Val_4;
      if ( v3 <= 0 )
        break;
      v4 = (int)_Firsta;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402A10
// Name: void std::_Make_heap<struct OptimalComboScheduleFileRecord_t __near *,int,struct OptimalComboScheduleFileRecord_t>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,int __near *,struct OptimalComboScheduleFileRecord_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Make_heap<OptimalComboScheduleFileRecord_t *,int,OptimalComboScheduleFileRecord_t>(
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Last)
{
  int v3; // edi
  int v4; // ebx
  int v5; // eax
  OptimalComboScheduleFileRecord_t *v6; // ecx
  unsigned __int64 m_nComboHash; // xmm0_8
  OptimalComboScheduleFileRecord_t *v8; // ecx
  int v9; // eax
  __int64 v10; // xmm0_8
  int v11; // edx
  bool v12; // zf
  int v13; // edx
  int v14; // edx
  OptimalComboScheduleFileRecord_t _Val; // [esp+Ch] [ebp-14h] BYREF
  int _Hole; // [esp+1Ch] [ebp-4h]
  OptimalComboScheduleFileRecord_t *_Firsta; // [esp+28h] [ebp+8h]
  OptimalComboScheduleFileRecord_t *_Lasta; // [esp+2Ch] [ebp+Ch]

  v3 = _Last - _First;
  v4 = v3 / 2;
  if ( v3 / 2 > 0 )
  {
    v5 = 2 * v4 + 2;
    v6 = &_First[v4];
    while ( 1 )
    {
      m_nComboHash = v6[-1].m_nComboHash;
      v8 = v6 - 1;
      --v4;
      v9 = v5 - 2;
      _Val.m_nComboHash = m_nComboHash;
      v10 = *((_QWORD *)v8 + 1);
      _Hole = v4;
      _Lasta = v8;
      _Firsta = (OptimalComboScheduleFileRecord_t *)v9;
      *((_QWORD *)&_Val + 1) = v10;
      v11 = v4;
      v12 = v9 == v3;
      if ( v9 < v3 )
      {
        do
        {
          if ( _First[v9].m_nComboHash < _First[v9 - 1].m_nComboHash )
            --v9;
          v13 = v11;
          _First[v13].m_nComboHash = _First[v9].m_nComboHash;
          *((_QWORD *)&_First[v13] + 1) = *((_QWORD *)&_First[v9] + 1);
          v11 = v9;
          v9 = 2 * v9 + 2;
          v12 = v9 == v3;
        }
        while ( v9 < v3 );
        v4 = _Hole;
      }
      if ( v12 )
      {
        v14 = v11;
        _First[v14].m_nComboHash = _First[v3 - 1].m_nComboHash;
        *((_QWORD *)&_First[v14] + 1) = *((_QWORD *)&_First[v3 - 1] + 1);
        v11 = v3 - 1;
      }
      std::_Push_heap<OptimalComboScheduleFileRecord_t *,int,OptimalComboScheduleFileRecord_t>(
        _First,
        _Hole: v11,
        _Top: v4,
        &_Val);
      if ( v4 <= 0 )
        break;
      v6 = _Lasta;
      v5 = (int)_Firsta;
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402B00
// Name: void std::_Insertion_sort1<struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Insertion_sort1<OptimalComboScheduleFileRecord_t *,OptimalComboScheduleFileRecord_t>(
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Last)
{
  OptimalComboScheduleFileRecord_t *i; // ecx
  unsigned __int64 m_nComboHash; // xmm0_8
  __int64 v4; // xmm1_8
  OptimalComboScheduleFileRecord_t *v5; // edx
  OptimalComboScheduleFileRecord_t *k; // eax
  unsigned __int64 v7; // xmm2_8
  OptimalComboScheduleFileRecord_t *j; // eax

  if ( _First != _Last )
  {
    for ( i = _First + 1; i != _Last; ++i )
    {
      m_nComboHash = i->m_nComboHash;
      v4 = *((_QWORD *)i + 1);
      v5 = i;
      if ( i->m_nComboHash >= _First->m_nComboHash )
      {
        for ( j = i; ; v5 = j )
        {
          --j;
          if ( m_nComboHash >= j->m_nComboHash )
            break;
          v5->m_nComboHash = j->m_nComboHash;
          *((_QWORD *)v5 + 1) = *((_QWORD *)j + 1);
        }
        v5->m_nComboHash = m_nComboHash;
        *((_QWORD *)v5 + 1) = v4;
      }
      else
      {
        for ( k = i; k != _First; *((_QWORD *)&k[1] + 1) = *((_QWORD *)k + 1) )
        {
          v7 = k[-1].m_nComboHash;
          --k;
          k[1].m_nComboHash = v7;
        }
        _First->m_nComboHash = m_nComboHash;
        *((_QWORD *)_First + 1) = v4;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402BC0
// Name: void std::_Med3<struct SchedulerUsage_t __near *>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Med3<SchedulerUsage_t *>(SchedulerUsage_t *_First, SchedulerUsage_t *_Mid, SchedulerUsage_t *_Last)
{
  int m_nScheduleIndex; // edx
  int m_nTotalUses; // esi
  int v5; // esi
  int v6; // edi
  int v7; // edx
  int v8; // esi

  if ( _Mid->m_nTotalUses > _First->m_nTotalUses )
  {
    m_nScheduleIndex = _Mid->m_nScheduleIndex;
    m_nTotalUses = _Mid->m_nTotalUses;
    *_Mid = *_First;
    _First->m_nScheduleIndex = m_nScheduleIndex;
    _First->m_nTotalUses = m_nTotalUses;
  }
  if ( _Last->m_nTotalUses > _Mid->m_nTotalUses )
  {
    v5 = _Last->m_nScheduleIndex;
    v6 = _Last->m_nTotalUses;
    *_Last = *_Mid;
    _Mid->m_nScheduleIndex = v5;
    _Mid->m_nTotalUses = v6;
  }
  if ( _Mid->m_nTotalUses > _First->m_nTotalUses )
  {
    v7 = _Mid->m_nScheduleIndex;
    v8 = _Mid->m_nTotalUses;
    *_Mid = *_First;
    _First->m_nScheduleIndex = v7;
    _First->m_nTotalUses = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402C30
// Name: void std::_Med3<struct OptimalComboScheduleFileRecord_t __near *>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Med3<OptimalComboScheduleFileRecord_t *>(
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Mid,
        OptimalComboScheduleFileRecord_t *_Last)
{
  unsigned __int64 m_nComboHash; // xmm0_8
  __int64 v4; // xmm1_8
  unsigned __int64 v5; // xmm0_8
  __int64 v6; // xmm1_8
  unsigned __int64 v7; // xmm0_8
  __int64 v8; // xmm1_8

  if ( _Mid->m_nComboHash < _First->m_nComboHash )
  {
    m_nComboHash = _Mid->m_nComboHash;
    v4 = *((_QWORD *)_Mid + 1);
    *_Mid = *_First;
    _First->m_nComboHash = m_nComboHash;
    *((_QWORD *)_First + 1) = v4;
  }
  if ( _Last->m_nComboHash < _Mid->m_nComboHash )
  {
    v5 = _Last->m_nComboHash;
    v6 = *((_QWORD *)_Last + 1);
    *_Last = *_Mid;
    _Mid->m_nComboHash = v5;
    *((_QWORD *)_Mid + 1) = v6;
  }
  if ( _Mid->m_nComboHash < _First->m_nComboHash )
  {
    v7 = _Mid->m_nComboHash;
    v8 = *((_QWORD *)_Mid + 1);
    *_Mid = *_First;
    _First->m_nComboHash = v7;
    *((_QWORD *)_First + 1) = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00402CE0
// Name: void std::_Cons_val<class std::allocator<struct std::pair<int const,int>>,struct std::pair<int const,int>,struct std::pair<int const,int> __near &>(class std::allocator<struct std::pair<int const,int>> __near &,struct std::pair<int const,int> __near *,struct std::pair<int const,int> __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::pair<int const,int>>,std::pair<int const,int>,std::pair<int const,int> &>(
        std::allocator<std::pair<int const ,int> > *_Alval,
        std::pair<int const ,int> *_Pdest,
        std::pair<int const ,int> *_Src)
{
  if ( _Pdest != nullptr )
    *_Pdest = *_Src;
}

//------------------------------------------------------------------------------
// Address: 0x00402D00
// Name: protected: struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near * std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Lbound(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &)const
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *__thiscall std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Lbound(
        std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        const std::string *_Keyval)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *result; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Parent; // edi
  const std::string *Ptr; // edx
  unsigned int Mysize; // ebx
  const char *Buf; // eax
  unsigned int v7; // esi
  unsigned int v8; // ecx
  int v9; // eax
  bool v10; // sf
  unsigned int Myres; // [esp+4h] [ebp-8h]
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Wherenode; // [esp+8h] [ebp-4h]

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
      Buf = Parent->_Myval.first._Bx._Buf;
      if ( Myres >= 0x10 )
        Ptr = (const std::string *)Ptr->_Bx._Ptr;
      v7 = Parent->_Myval.first._Mysize;
      v8 = v7;
      if ( v7 >= Mysize )
        v8 = Mysize;
      if ( Parent->_Myval.first._Myres >= 0x10 )
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
// Address: 0x00402DA0
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>> std::_Tree<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > *__thiscall std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::erase(
        std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > _Where)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *v7; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *i; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
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
        v9 = std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Min(_Pnode: Right);
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
        v10->_Right = std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Max(_Pnode: Right);
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
          std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Lrotate(
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
            std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Lrotate(
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
          std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Rrotate(
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
            std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Rrotate(
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
  operator delete(p: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00402FF0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>> std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > _Where)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *v7; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *i; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
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
        v9 = std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Min(_Pnode: Right);
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
        v10->_Right = std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Max(_Pnode: Right);
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
          std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Lrotate(
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
            std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Lrotate(
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
          std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Rrotate(
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
            std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Rrotate(
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
  operator delete(p: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403240
// Name: protected: void std::_Tree<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Erase(struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Erase(
        std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this,
        std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v2; // edi
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *i; // esi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    operator delete(p: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403280
// Name: protected: void std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Erase(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v2; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // esi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    operator delete(p: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x004032C0
// Name: public: struct std::pair<class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>>,bool> std::_Tree<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >,bool> *__thiscall std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Linsert(
        std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this,
        std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >,bool> *result,
        std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *_Node,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > _Leftish)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v4; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v8; // edi
  bool v9; // cl
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Ptr; // esi
  bool _Addleft; // [esp+Ch] [ebp-4h]

  v4 = _Node;
  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v8 = Myhead;
  v9 = true;
  _Addleft = true;
  while ( Parent->_Isnil == 0 )
  {
    v8 = Parent;
    if ( LOBYTE(_Leftish._Ptr) != 0 )
    {
      v9 = Parent->_Myval >= _Node->_Myval;
      _Addleft = v9;
      if ( Parent->_Myval < _Node->_Myval )
        goto LABEL_8;
      Parent = Parent->_Left;
    }
    else
    {
      if ( _Node->_Myval >= Parent->_Myval )
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
  Ptr = v8;
  _Leftish._Ptr = v8;
  if ( v9 )
  {
    if ( v8 == this->_Myhead->_Left )
    {
      result->first = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >)std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Insert(this, result: &_Leftish, _Addleft: true, _Wherenode: v8, _Newnode: _Node)->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    Ptr = _Leftish._Ptr;
    v4 = _Node;
  }
  if ( Ptr->_Myval >= v4->_Myval )
  {
    operator delete(p: v4);
    result->first._Ptr = Ptr;
    result->second = false;
  }
  else
  {
    result->first = (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >)std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Insert(this, result: &_Leftish, _Addleft, _Wherenode: v8, _Newnode: v4)->_Ptr;
    result->second = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004033D0
// Name: public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>>,bool> std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >,bool> *__thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Linsert(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >,bool> *result,
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Node,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > _Leftish)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v4; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v8; // esi
  bool v9; // cl
  int first; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Ptr; // edi
  bool _Addleft; // [esp+Ch] [ebp-4h]

  v4 = _Node;
  Myhead = this->_Myhead;
  Parent = Myhead->_Parent;
  v8 = Myhead;
  v9 = true;
  _Addleft = true;
  if ( Parent->_Isnil == 0 )
  {
    first = _Node->_Myval.first;
    do
    {
      v8 = Parent;
      if ( LOBYTE(_Leftish._Ptr) != 0 )
        v9 = Parent->_Myval.first >= first;
      else
        v9 = first < Parent->_Myval.first;
      _Addleft = v9;
      if ( v9 )
        Parent = Parent->_Left;
      else
        Parent = Parent->_Right;
    }
    while ( Parent->_Isnil == 0 );
  }
  Ptr = v8;
  _Leftish._Ptr = v8;
  if ( v9 )
  {
    if ( v8 == this->_Myhead->_Left )
    {
      result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Insert(this, result: &_Leftish, _Addleft: true, _Wherenode: v8, _Newnode: _Node)->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    Ptr = _Leftish._Ptr;
    v4 = _Node;
  }
  if ( Ptr->_Myval.first >= v4->_Myval.first )
  {
    operator delete(p: v4);
    result->first._Ptr = Ptr;
    result->second = false;
  }
  else
  {
    result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Insert(this, result: &_Leftish, _Addleft, _Wherenode: v8, _Newnode: v4)->_Ptr;
    result->second = true;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004034B0
// Name: void std::_Uninit_def_fill_n<struct OptimalComboScheduleFileRecord_t __near *,unsigned int,struct OptimalComboScheduleFileRecord_t,class std::allocator<struct OptimalComboScheduleFileRecord_t>,struct OptimalComboScheduleFileRecord_t>(struct OptimalComboScheduleFileRecord_t __near *,unsigned int,struct OptimalComboScheduleFileRecord_t const __near *,class std::allocator<struct OptimalComboScheduleFileRecord_t> __near &,struct OptimalComboScheduleFileRecord_t __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Uninit_def_fill_n<OptimalComboScheduleFileRecord_t *,unsigned int,OptimalComboScheduleFileRecord_t,std::allocator<OptimalComboScheduleFileRecord_t>,OptimalComboScheduleFileRecord_t>(
        OptimalComboScheduleFileRecord_t *_First,
        unsigned int _Count,
        const OptimalComboScheduleFileRecord_t *__formal,
        std::allocator<OptimalComboScheduleFileRecord_t> *_Al)
{
  int v6; // [esp+0h] [ebp-2Ch] BYREF
  OptimalComboScheduleFileRecord_t _Src; // [esp+Ch] [ebp-20h] BYREF
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v6;
  v9 = 0;
  while ( _Count != 0 )
  {
    memset(&_Src, 0, sizeof(_Src));
    std::_Cons_val<std::allocator<OptimalComboScheduleFileRecord_t>,OptimalComboScheduleFileRecord_t,OptimalComboScheduleFileRecord_t>(
      _Alval: _Al,
      _Pdest: _First,
      &_Src);
    --_Count;
    ++_First;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403530
// Name: struct SchedulerUsage_t __near * std::_Uninit_move<struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,class std::allocator<struct SchedulerUsage_t>,struct SchedulerUsage_t>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,class std::allocator<struct SchedulerUsage_t> __near &,struct SchedulerUsage_t __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
SchedulerUsage_t *__cdecl std::_Uninit_move<SchedulerUsage_t *,SchedulerUsage_t *,std::allocator<SchedulerUsage_t>,SchedulerUsage_t>(
        SchedulerUsage_t *_First,
        SchedulerUsage_t *_Last,
        SchedulerUsage_t *_Dest,
        std::allocator<std::pair<int const ,int> > *_Al)
{
  _DWORD v7[7]; // [esp+0h] [ebp-1Ch] BYREF

  v7[3] = v7;
  v7[6] = 0;
  while ( _First != _Last )
    std::_Cons_val<std::allocator<std::pair<int const,int>>,std::pair<int const,int>,std::pair<int const,int> &>(
      _Alval: _Al,
      _Pdest: (std::pair<int const ,int> *)_Dest++,
      _Src: (std::pair<int const ,int> *)_First++);
  return _Dest;
}

//------------------------------------------------------------------------------
// Address: 0x004035B0
// Name: void std::_Median<struct SchedulerUsage_t __near *>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Median<SchedulerUsage_t *>(
        SchedulerUsage_t *_First,
        SchedulerUsage_t *_Mid,
        SchedulerUsage_t *_Last)
{
  int v3; // eax
  int v4; // eax
  unsigned int v5; // edi
  unsigned int v6; // ebx
  SchedulerUsage_t *v7; // edx
  SchedulerUsage_t *_Firsta; // [esp+Ch] [ebp+8h]

  v3 = _Last - _First;
  if ( v3 <= 40 )
  {
    std::_Med3<SchedulerUsage_t *>(_First, _Mid, _Last);
  }
  else
  {
    v4 = (v3 + 1) / 8;
    v5 = 16 * v4;
    v6 = 8 * v4;
    v7 = &_First[2 * v4];
    _Firsta = &_First[v4];
    std::_Med3<SchedulerUsage_t *>(_First, _Mid: _Firsta, _Last: v7);
    std::_Med3<SchedulerUsage_t *>(_First: &_Mid[v6 / 0xFFFFFFF8], _Mid, _Last: &_Mid[v6 / 8]);
    std::_Med3<SchedulerUsage_t *>(_First: &_Last[v5 / 0xFFFFFFF8], _Mid: &_Last[v6 / 0xFFFFFFF8], _Last);
    std::_Med3<SchedulerUsage_t *>(_First: _Firsta, _Mid, _Last: &_Last[v6 / 0xFFFFFFF8]);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403640
// Name: void std::_Insertion_sort1<struct SchedulerUsage_t __near *,struct SchedulerUsage_t>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Insertion_sort1<SchedulerUsage_t *,SchedulerUsage_t>(
        SchedulerUsage_t *_First,
        SchedulerUsage_t *_Last)
{
  SchedulerUsage_t *i; // edx
  int m_nTotalUses; // esi
  int m_nScheduleIndex; // ebx
  SchedulerUsage_t *v5; // ecx
  SchedulerUsage_t *j; // eax
  int v7; // ecx
  SchedulerUsage_t *v8; // eax
  int _Val; // [esp+4h] [ebp-8h]

  if ( _First != _Last )
  {
    for ( i = _First + 1; i != _Last; ++i )
    {
      m_nTotalUses = i->m_nTotalUses;
      m_nScheduleIndex = i->m_nScheduleIndex;
      v5 = i;
      _Val = i->m_nScheduleIndex;
      if ( m_nTotalUses <= _First->m_nTotalUses )
      {
        v8 = i - 1;
        if ( m_nTotalUses > i[-1].m_nTotalUses )
        {
          do
          {
            v5->m_nScheduleIndex = v8->m_nScheduleIndex;
            v5->m_nTotalUses = v8->m_nTotalUses;
            v5 = v8--;
          }
          while ( m_nTotalUses > v8->m_nTotalUses );
          m_nScheduleIndex = _Val;
        }
        v5->m_nScheduleIndex = m_nScheduleIndex;
        v5->m_nTotalUses = m_nTotalUses;
      }
      else
      {
        for ( j = i; j != _First; j[1].m_nTotalUses = j->m_nTotalUses )
        {
          v7 = j[-1].m_nScheduleIndex;
          --j;
          j[1].m_nScheduleIndex = v7;
        }
        _First->m_nScheduleIndex = m_nScheduleIndex;
        _First->m_nTotalUses = m_nTotalUses;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x004036D0
// Name: void std::_Median<struct OptimalComboScheduleFileRecord_t __near *>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Median<OptimalComboScheduleFileRecord_t *>(
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Mid,
        OptimalComboScheduleFileRecord_t *_Last)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // ebx
  OptimalComboScheduleFileRecord_t *v8; // [esp-Ch] [ebp-10h]
  OptimalComboScheduleFileRecord_t *_Firsta; // [esp+Ch] [ebp+8h]

  v3 = _Last - _First;
  if ( v3 <= 40 )
  {
    std::_Med3<OptimalComboScheduleFileRecord_t *>(_First, _Mid, _Last);
  }
  else
  {
    v4 = (v3 + 1) / 8;
    v5 = v4;
    v4 *= 32;
    v6 = v5 * 16;
    v8 = (OptimalComboScheduleFileRecord_t *)((char *)_First + v4);
    _Firsta = &_First[v5];
    std::_Med3<OptimalComboScheduleFileRecord_t *>(_First, _Mid: _Firsta, _Last: v8);
    std::_Med3<OptimalComboScheduleFileRecord_t *>(
      _First: (OptimalComboScheduleFileRecord_t *)((char *)_Mid - v6),
      _Mid,
      _Last: (OptimalComboScheduleFileRecord_t *)((char *)_Mid + v6));
    std::_Med3<OptimalComboScheduleFileRecord_t *>(
      _First: (OptimalComboScheduleFileRecord_t *)((char *)_Last - v4),
      _Mid: (OptimalComboScheduleFileRecord_t *)((char *)_Last - v6),
      _Last);
    std::_Med3<OptimalComboScheduleFileRecord_t *>(
      _First: _Firsta,
      _Mid,
      _Last: (OptimalComboScheduleFileRecord_t *)((char *)_Last - v6));
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403760
// Name: struct SchedulerUsage_t __near * std::_Uninit_copy<class std::_Vector_const_iterator<class std::_Vector_val<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>>,struct SchedulerUsage_t __near *,class std::allocator<struct SchedulerUsage_t>>(class std::_Vector_const_iterator<class std::_Vector_val<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>>,class std::_Vector_const_iterator<class std::_Vector_val<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>>,struct SchedulerUsage_t __near *,class std::allocator<struct SchedulerUsage_t> __near &,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
SchedulerUsage_t *__cdecl std::_Uninit_copy<std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t>>,SchedulerUsage_t *,std::allocator<SchedulerUsage_t>>(
        std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t> > _First,
        std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t> > _Last,
        SchedulerUsage_t *_Dest,
        std::allocator<std::pair<int const ,int> > *_Al)
{
  SchedulerUsage_t *i; // eax
  _DWORD v7[7]; // [esp+0h] [ebp-1Ch] BYREF

  v7[3] = v7;
  v7[6] = 0;
  for ( i = _First._Ptr; i != _Last._Ptr; i = ++_First._Ptr )
    std::_Cons_val<std::allocator<std::pair<int const,int>>,std::pair<int const,int>,std::pair<int const,int> &>(
      _Alval: _Al,
      _Pdest: (std::pair<int const ,int> *)_Dest++,
      _Src: (std::pair<int const ,int> *)i);
  return _Dest;
}

//------------------------------------------------------------------------------
// Address: 0x004037E0
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
// Address: 0x004038D0
// Name: public: void std::_Tree<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::clear(
        std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Parent; // ebx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *i; // esi

  Parent = this->_Myhead->_Parent;
  for ( i = Parent; i->_Isnil == 0; Parent = i )
  {
    std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    operator delete(p: Parent);
  }
  this->_Myhead->_Parent = this->_Myhead;
  this->_Myhead->_Left = this->_Myhead;
  this->_Myhead->_Right = this->_Myhead;
  this->_Mysize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403920
// Name: public: void std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::clear(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::clear(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Parent; // ebx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // esi

  Parent = this->_Myhead->_Parent;
  for ( i = Parent; i->_Isnil == 0; Parent = i )
  {
    std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    operator delete(p: Parent);
  }
  this->_Myhead->_Parent = this->_Myhead;
  this->_Myhead->_Left = this->_Myhead;
  this->_Myhead->_Right = this->_Myhead;
  this->_Mysize = 0;
}

//------------------------------------------------------------------------------
// Address: 0x00403970
// Name: protected: struct OptimalComboScheduleFileRecord_t __near * std::vector<struct OptimalComboScheduleFileRecord_t,class std::allocator<struct OptimalComboScheduleFileRecord_t>>::_Umove<struct OptimalComboScheduleFileRecord_t __near *>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *)
// Source: json
//------------------------------------------------------------------------------
OptimalComboScheduleFileRecord_t *__thiscall std::vector<OptimalComboScheduleFileRecord_t>::_Umove<OptimalComboScheduleFileRecord_t *>(
        std::vector<OptimalComboScheduleFileRecord_t> *this,
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Last,
        OptimalComboScheduleFileRecord_t *_Ptr)
{
  return std::_Uninit_move<OptimalComboScheduleFileRecord_t *,OptimalComboScheduleFileRecord_t *,std::allocator<OptimalComboScheduleFileRecord_t>,OptimalComboScheduleFileRecord_t>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: &this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x004039A0
// Name: public: struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Buynode<struct std::pair<int const,int> __near &>(struct std::pair<int const,int> __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *__thiscall std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Buynode<std::pair<int const,int> &>(
        std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::pair<int const ,int> *_Val)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *p; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node **)operator new(size: 0x18u);
  p = v3;
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
  *((_WORD *)v3 + 10) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<std::pair<int const,int>>,std::pair<int const,int>,std::pair<int const,int> &>(
    _Alval: &this->_Alval,
    _Pdest: (std::pair<int const ,int> *)(v3 + 3),
    _Src: _Val);
  v9 = -1;
  return (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00403A60
// Name: public: CompileStats_t::CompileStats_t(struct CompileStats_t const __near &)
// Source: json
//------------------------------------------------------------------------------
CompileStats_t *__thiscall CompileStats_t::CompileStats_t(CompileStats_t *this, const CompileStats_t *__that)
{
  std::string *p_m_Filename; // ecx

  this->m_nCompileGUID = __that->m_nCompileGUID;
  this->m_nComboHash = __that->m_nComboHash;
  p_m_Filename = &this->m_Filename;
  p_m_Filename->_Myres = 15;
  p_m_Filename->_Mysize = 0;
  p_m_Filename->_Bx._Buf[0] = 0;
  std::string::assign(this: p_m_Filename, _Right: &__that->m_Filename, _Roff: 0, _Count: 0xFFFFFFFF);
  this->m_nOrigCycles = __that->m_nOrigCycles;
  this->m_nOrigRegs = __that->m_nOrigRegs;
  this->m_nOptCycles = __that->m_nOptCycles;
  this->m_nOptRegs = __that->m_nOptRegs;
  this->m_nOptSchedule = __that->m_nOptSchedule;
  this->m_nOptSeed = __that->m_nOptSeed;
  this->m_nSchedulerParamSource = __that->m_nSchedulerParamSource;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00403AE0
// Name: struct std::pair<struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *> std::_Unguarded_partition<struct SchedulerUsage_t __near *>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *)
// Source: json
//------------------------------------------------------------------------------
std::pair<SchedulerUsage_t *,SchedulerUsage_t *> *__cdecl std::_Unguarded_partition<SchedulerUsage_t *>(
        std::pair<SchedulerUsage_t *,SchedulerUsage_t *> *result,
        SchedulerUsage_t *_First,
        SchedulerUsage_t *_Last)
{
  SchedulerUsage_t *v3; // ecx
  SchedulerUsage_t *i; // esi
  int m_nTotalUses; // eax
  int v6; // edx
  int v7; // edx
  int v8; // eax
  SchedulerUsage_t *v9; // edi
  SchedulerUsage_t *v10; // eax
  int v11; // edx
  int v12; // ebx
  bool v13; // zf
  SchedulerUsage_t *v14; // edx
  int v15; // edi
  int v16; // ebx
  int v17; // ebx
  int v18; // edi
  int v19; // edx
  SchedulerUsage_t *v20; // edx
  int v21; // edx
  int v22; // edx
  int v23; // edx
  int v25; // [esp+10h] [ebp-3Ch]
  int v26; // [esp+18h] [ebp-34h]
  int v27; // [esp+20h] [ebp-2Ch]
  int v28; // [esp+28h] [ebp-24h]
  int v29; // [esp+34h] [ebp-18h]
  int v30; // [esp+38h] [ebp-14h]
  int m_nScheduleIndex; // [esp+3Ch] [ebp-10h]
  int v32; // [esp+40h] [ebp-Ch]
  SchedulerUsage_t *_Glast; // [esp+48h] [ebp-4h]

  std::_Median<SchedulerUsage_t *>(_First, _Mid: &_First[(_Last - _First) / 2], _Last: _Last - 1);
  v3 = &_First[(_Last - _First) / 2];
  for ( i = v3 + 1; _First < v3; --v3 )
  {
    m_nTotalUses = v3[-1].m_nTotalUses;
    v6 = v3->m_nTotalUses;
    if ( v6 < m_nTotalUses )
      break;
    if ( v6 > m_nTotalUses )
      break;
  }
  if ( i < _Last )
  {
    v7 = v3->m_nTotalUses;
    do
    {
      v8 = i->m_nTotalUses;
      if ( v7 < v8 )
        break;
      if ( v7 > v8 )
        break;
      ++i;
    }
    while ( i < _Last );
  }
  v9 = v3;
  v10 = i;
  _Glast = v3;
  while ( 2 )
  {
    while ( 2 )
    {
      while ( v10 < _Last )
      {
        v11 = v10->m_nTotalUses;
        v12 = v3->m_nTotalUses;
        if ( v11 >= v12 )
        {
          if ( v11 > v12 )
            break;
          m_nScheduleIndex = i->m_nScheduleIndex;
          v32 = i->m_nTotalUses;
          i->m_nScheduleIndex = v10->m_nScheduleIndex;
          i->m_nTotalUses = v10->m_nTotalUses;
          v10->m_nScheduleIndex = m_nScheduleIndex;
          ++i;
          v10->m_nTotalUses = v32;
        }
        ++v10;
      }
      v13 = v9 == _First;
      if ( v9 <= _First )
        goto LABEL_25;
      v14 = v9 - 1;
      while ( 1 )
      {
        v15 = v14->m_nTotalUses;
        v16 = v3->m_nTotalUses;
        if ( v16 >= v15 )
          break;
LABEL_21:
        v9 = _Glast - 1;
        --v14;
        _Glast = v9;
        if ( _First >= v9 )
          goto LABEL_24;
      }
      if ( v16 <= v15 )
      {
        v17 = v3[-1].m_nTotalUses;
        v18 = v3[-1].m_nScheduleIndex;
        --v3;
        v3->m_nScheduleIndex = v14->m_nScheduleIndex;
        v3->m_nTotalUses = v14->m_nTotalUses;
        v14->m_nScheduleIndex = v18;
        v14->m_nTotalUses = v17;
        goto LABEL_21;
      }
      v9 = _Glast;
LABEL_24:
      v13 = v9 == _First;
LABEL_25:
      if ( !v13 )
      {
        _Glast = --v9;
        if ( v10 == _Last )
        {
          if ( v9 != --v3 )
          {
            v21 = v9->m_nScheduleIndex;
            v27 = v9->m_nTotalUses;
            v9->m_nScheduleIndex = v3->m_nScheduleIndex;
            v9->m_nTotalUses = v3->m_nTotalUses;
            v3->m_nScheduleIndex = v21;
            v3->m_nTotalUses = v27;
          }
          v22 = v3->m_nScheduleIndex;
          --i;
          v26 = v3->m_nTotalUses;
          v3->m_nScheduleIndex = i->m_nScheduleIndex;
          v3->m_nTotalUses = i->m_nTotalUses;
          i->m_nScheduleIndex = v22;
          i->m_nTotalUses = v26;
        }
        else
        {
          v23 = v10->m_nScheduleIndex;
          v25 = v10->m_nTotalUses;
          v10->m_nScheduleIndex = v9->m_nScheduleIndex;
          v10->m_nTotalUses = v9->m_nTotalUses;
          v9->m_nScheduleIndex = v23;
          v9->m_nTotalUses = v25;
          ++v10;
        }
        continue;
      }
      break;
    }
    if ( v10 != _Last )
    {
      if ( i != v10 )
      {
        v19 = v3->m_nScheduleIndex;
        v28 = v3->m_nTotalUses;
        v3->m_nScheduleIndex = i->m_nScheduleIndex;
        v3->m_nTotalUses = i->m_nTotalUses;
        i->m_nScheduleIndex = v19;
        i->m_nTotalUses = v28;
      }
      v29 = v3->m_nScheduleIndex;
      v30 = v3->m_nTotalUses;
      v3->m_nScheduleIndex = v10->m_nScheduleIndex;
      v3->m_nTotalUses = v10->m_nTotalUses;
      v20 = v10;
      v10->m_nScheduleIndex = v29;
      ++i;
      ++v3;
      ++v10;
      v20->m_nTotalUses = v30;
      continue;
    }
    break;
  }
  result->second = i;
  result->first = v3;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403CC0
// Name: struct std::pair<struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *> std::_Unguarded_partition<struct OptimalComboScheduleFileRecord_t __near *>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *)
// Source: json
//------------------------------------------------------------------------------
std::pair<OptimalComboScheduleFileRecord_t *,OptimalComboScheduleFileRecord_t *> *__cdecl std::_Unguarded_partition<OptimalComboScheduleFileRecord_t *>(
        std::pair<OptimalComboScheduleFileRecord_t *,OptimalComboScheduleFileRecord_t *> *result,
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Last)
{
  OptimalComboScheduleFileRecord_t *v3; // esi
  unsigned int v4; // edi
  unsigned int v5; // ecx
  unsigned int v6; // eax
  unsigned int v7; // esi
  unsigned int v8; // ebx
  unsigned int v9; // esi
  OptimalComboScheduleFileRecord_t *v10; // ebx
  unsigned int v11; // eax
  unsigned int v12; // edx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  __int64 v15; // xmm0_8
  __int64 v16; // xmm1_8
  bool v17; // zf
  OptimalComboScheduleFileRecord_t *v18; // edx
  unsigned int m_nComboHash_high; // esi
  unsigned int v20; // ebx
  unsigned __int64 v21; // xmm0_8
  __int64 v22; // xmm1_8
  unsigned __int64 v23; // xmm0_8
  __int64 v24; // xmm1_8
  unsigned int v25; // edx
  unsigned __int64 v26; // xmm0_8
  __int64 v27; // xmm1_8
  unsigned __int64 m_nComboHash; // xmm0_8
  __int64 v29; // xmm1_8
  __int64 v30; // xmm2_8
  unsigned __int64 v31; // xmm0_8
  __int64 v32; // xmm1_8
  unsigned __int64 v33; // xmm0_8
  __int64 v34; // xmm1_8
  OptimalComboScheduleFileRecord_t *_Glast; // [esp+Ch] [ebp-8h]
  OptimalComboScheduleFileRecord_t *_Plast; // [esp+10h] [ebp-4h]

  v3 = &_First[(_Last - _First) / 2];
  std::_Median<OptimalComboScheduleFileRecord_t *>(_First, _Mid: v3, _Last: _Last - 1);
  v4 = (unsigned int)&v3[1];
  v5 = (unsigned int)v3;
  _Plast = v3 + 1;
  if ( _First < v3 )
  {
    do
    {
      v6 = *(_DWORD *)(v5 - 12);
      v7 = *(_DWORD *)(v5 - 16);
      if ( __PAIR64__(v6, v7) < *(_QWORD *)v5 )
        break;
      if ( *(_QWORD *)v5 < __PAIR64__(v6, v7) )
        break;
      v5 -= 16;
    }
    while ( (unsigned int)_First < v5 );
  }
  if ( v4 < (unsigned int)_Last )
  {
    v8 = *(_DWORD *)v5;
    v9 = *(_DWORD *)(v5 + 4);
    do
    {
      if ( *(_QWORD *)v4 < __PAIR64__(v9, v8) )
        break;
      if ( __PAIR64__(v9, v8) < *(_QWORD *)v4 )
        break;
      v4 += 16;
    }
    while ( v4 < (unsigned int)_Last );
    _Plast = (OptimalComboScheduleFileRecord_t *)v4;
  }
  v10 = (OptimalComboScheduleFileRecord_t *)v5;
  v11 = v4;
  _Glast = (OptimalComboScheduleFileRecord_t *)v5;
  while ( 2 )
  {
    while ( 2 )
    {
      if ( v11 < (unsigned int)_Last )
      {
        while ( 1 )
        {
          v12 = *(_DWORD *)(v11 + 4);
          v13 = *(_DWORD *)(v5 + 4);
          v14 = *(_DWORD *)v11;
          if ( v13 >= v12 )
          {
            if ( v13 > v12 || (v4 = (unsigned int)_Plast, *(_DWORD *)v5 >= v14) )
            {
              if ( v12 < v13 || v12 <= v13 && v14 < *(_DWORD *)v5 )
              {
LABEL_21:
                v10 = _Glast;
                break;
              }
              v15 = *(_QWORD *)v4;
              v16 = *(_QWORD *)(v4 + 8);
              *(_QWORD *)v4 = *(_QWORD *)v11;
              *(_QWORD *)(v4 + 8) = *(_QWORD *)(v11 + 8);
              v4 += 16;
              *(_QWORD *)v11 = v15;
              _Plast = (OptimalComboScheduleFileRecord_t *)v4;
              *(_QWORD *)(v11 + 8) = v16;
            }
          }
          v11 += 16;
          if ( v11 >= (unsigned int)_Last )
            goto LABEL_21;
        }
      }
      v17 = v10 == _First;
      if ( v10 <= _First )
        goto LABEL_33;
      v18 = v10 - 1;
      do
      {
        m_nComboHash_high = HIDWORD(v18->m_nComboHash);
        v20 = *(_DWORD *)v5;
        if ( m_nComboHash_high >= *(_DWORD *)(v5 + 4) )
        {
          if ( m_nComboHash_high <= *(_DWORD *)(v5 + 4) )
          {
            v4 = (unsigned int)_Plast;
            if ( LODWORD(v18->m_nComboHash) < v20 )
              goto LABEL_31;
          }
          if ( *(_DWORD *)(v5 + 4) < m_nComboHash_high
            || *(_DWORD *)(v5 + 4) <= m_nComboHash_high && v20 < LODWORD(v18->m_nComboHash) )
          {
            break;
          }
          v21 = *(_QWORD *)(v5 - 16);
          v22 = *(_QWORD *)(v5 - 8);
          v5 -= 16;
          *(_QWORD *)v5 = v18->m_nComboHash;
          *(_QWORD *)(v5 + 8) = *((_QWORD *)v18 + 1);
          v18->m_nComboHash = v21;
          *((_QWORD *)v18 + 1) = v22;
        }
LABEL_31:
        --v18;
        --_Glast;
      }
      while ( _First < _Glast );
      v10 = _Glast;
      v17 = _Glast == _First;
LABEL_33:
      if ( !v17 )
      {
        _Glast = --v10;
        if ( (OptimalComboScheduleFileRecord_t *)v11 == _Last )
        {
          v5 -= 16;
          if ( v10 != (OptimalComboScheduleFileRecord_t *)v5 )
          {
            m_nComboHash = v10->m_nComboHash;
            v29 = *((_QWORD *)v10 + 1);
            v10->m_nComboHash = *(_QWORD *)v5;
            *((_QWORD *)v10 + 1) = *(_QWORD *)(v5 + 8);
            *(_QWORD *)v5 = m_nComboHash;
            *(_QWORD *)(v5 + 8) = v29;
          }
          v30 = *(_QWORD *)(v4 - 16);
          v31 = *(_QWORD *)v5;
          v32 = *(_QWORD *)(v5 + 8);
          v4 -= 16;
          *(_QWORD *)v5 = v30;
          *(_QWORD *)(v5 + 8) = *(_QWORD *)(v4 + 8);
          *(_QWORD *)v4 = v31;
          _Plast = (OptimalComboScheduleFileRecord_t *)v4;
          *(_QWORD *)(v4 + 8) = v32;
        }
        else
        {
          v33 = *(_QWORD *)v11;
          v34 = *(_QWORD *)(v11 + 8);
          *(_QWORD *)v11 = v10->m_nComboHash;
          *(_QWORD *)(v11 + 8) = *((_QWORD *)v10 + 1);
          v10->m_nComboHash = v33;
          *((_QWORD *)v10 + 1) = v34;
          v11 += 16;
        }
        continue;
      }
      break;
    }
    if ( (OptimalComboScheduleFileRecord_t *)v11 != _Last )
    {
      if ( v4 != v11 )
      {
        v23 = *(_QWORD *)v5;
        v24 = *(_QWORD *)(v5 + 8);
        *(_QWORD *)v5 = *(_QWORD *)v4;
        *(_QWORD *)(v5 + 8) = *(_QWORD *)(v4 + 8);
        *(_QWORD *)v4 = v23;
        *(_QWORD *)(v4 + 8) = v24;
      }
      v25 = v11;
      v26 = *(_QWORD *)v5;
      v27 = *(_QWORD *)(v5 + 8);
      *(_QWORD *)v5 = *(_QWORD *)v11;
      v4 += 16;
      *(_QWORD *)(v5 + 8) = *(_QWORD *)(v11 + 8);
      v5 += 16;
      *(_QWORD *)v11 = v26;
      _Plast = (OptimalComboScheduleFileRecord_t *)v4;
      v11 += 16;
      *(_QWORD *)(v25 + 8) = v27;
      continue;
    }
    break;
  }
  result->second = (OptimalComboScheduleFileRecord_t *)v4;
  result->first = (OptimalComboScheduleFileRecord_t *)v5;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00403F30
// Name: void std::_Sort_heap<struct SchedulerUsage_t __near *>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<SchedulerUsage_t *>(SchedulerUsage_t *_First, SchedulerUsage_t *_Last)
{
  int v2; // eax
  SchedulerUsage_t *v3; // esi
  int m_nTotalUses; // edx
  SchedulerUsage_t _Val; // [esp+4h] [ebp-8h] BYREF

  v2 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF8) > 8 )
  {
    v3 = _Last - 1;
    do
    {
      m_nTotalUses = v3->m_nTotalUses;
      _Val.m_nScheduleIndex = v3->m_nScheduleIndex;
      v3->m_nScheduleIndex = _First->m_nScheduleIndex;
      _Val.m_nTotalUses = m_nTotalUses;
      v3->m_nTotalUses = _First->m_nTotalUses;
      std::_Adjust_heap<SchedulerUsage_t *,int,SchedulerUsage_t>(_First, _Hole: 0, _Bottom: (v2 - 8) >> 3, &_Val);
      v2 = (char *)--v3 - (char *)_First + 8;
    }
    while ( (int)(v2 & 0xFFFFFFF8) > 8 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00403FA0
// Name: void std::_Sort_heap<struct OptimalComboScheduleFileRecord_t __near *>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort_heap<OptimalComboScheduleFileRecord_t *>(
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Last)
{
  int v2; // eax
  OptimalComboScheduleFileRecord_t *v3; // esi
  OptimalComboScheduleFileRecord_t _Val; // [esp+4h] [ebp-10h] BYREF

  v2 = (char *)_Last - (char *)_First;
  if ( (int)(((char *)_Last - (char *)_First) & 0xFFFFFFF0) > 16 )
  {
    v3 = _Last - 1;
    do
    {
      _Val = *v3;
      *v3 = *_First;
      std::_Adjust_heap<OptimalComboScheduleFileRecord_t *,int,OptimalComboScheduleFileRecord_t>(
        _First,
        _Hole: 0,
        _Bottom: (v2 - 16) >> 4,
        &_Val);
      v2 = (char *)--v3 - (char *)_First + 16;
    }
    while ( (int)(v2 & 0xFFFFFFF0) > 16 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404020
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
// Address: 0x00404120
// Name: public: class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>> std::_Tree<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tset_traits<unsigned __int64,struct std::less<unsigned __int64>,class std::allocator<unsigned __int64>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > *__thiscall std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::erase(
        std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > *this,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > _Last)
{
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Ptr; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > v8; // edx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *i; // eax
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > v13; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::clear(this);
    result->_Ptr = this->_Myhead->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v8._Ptr = Ptr;
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
          v10 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v10 = j;
          _First._Ptr = v10;
        }
      }
      std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::erase(
        this,
        result: &v13,
        _Where: v8);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004041C0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>> std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > _Last)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Ptr; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > v8; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > v13; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::clear(this);
    result->_Ptr = this->_Myhead->_Left;
    return result;
  }
  else
  {
    for ( ; _First._Ptr != _Last._Ptr; Ptr = _First._Ptr )
    {
      v8._Ptr = Ptr;
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
          v10 = Ptr->_Right;
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            v10 = j;
          _First._Ptr = v10;
        }
      }
      std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
        this,
        result: &v13,
        _Where: v8);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404260
// Name: protected: struct SchedulerUsage_t __near * std::vector<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>::_Umove<struct SchedulerUsage_t __near *>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *)
// Source: json
//------------------------------------------------------------------------------
SchedulerUsage_t *__thiscall std::vector<SchedulerUsage_t>::_Umove<SchedulerUsage_t *>(
        std::vector<SchedulerUsage_t> *this,
        SchedulerUsage_t *_First,
        SchedulerUsage_t *_Last,
        SchedulerUsage_t *_Ptr)
{
  return std::_Uninit_move<SchedulerUsage_t *,SchedulerUsage_t *,std::allocator<SchedulerUsage_t>,SchedulerUsage_t>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: (std::allocator<std::pair<int const ,int> > *)&this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x00404290
// Name: void std::_Dest_val<class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>(class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>> __near &,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Dest_val<std::allocator<std::string>,std::string>(
        std::allocator<std::string > *_Alval,
        std::string *_Pdest)
{
  if ( _Pdest->_Myres >= 0x10 )
    operator delete(p: _Pdest->_Bx._Ptr);
  _Pdest->_Myres = 15;
  _Pdest->_Mysize = 0;
  _Pdest->_Bx._Buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004042C0
// Name: void std::_Cons_val<class std::allocator<struct CompileStats_t>,struct CompileStats_t,struct CompileStats_t>(class std::allocator<struct CompileStats_t> __near &,struct CompileStats_t __near *,struct CompileStats_t __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<CompileStats_t>,CompileStats_t,CompileStats_t>(
        std::allocator<CompileStats_t> *_Alval,
        CompileStats_t *_Pdest,
        CompileStats_t *_Src)
{
  if ( _Pdest != nullptr )
    CompileStats_t::CompileStats_t(this: _Pdest, __that: _Src);
}

//------------------------------------------------------------------------------
// Address: 0x004042E0
// Name: protected: struct SchedulerUsage_t __near * std::vector<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>::_Ucopy<class std::_Vector_const_iterator<class std::_Vector_val<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>>>(class std::_Vector_const_iterator<class std::_Vector_val<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>>,class std::_Vector_const_iterator<class std::_Vector_val<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>>,struct SchedulerUsage_t __near *)
// Source: json
//------------------------------------------------------------------------------
SchedulerUsage_t *__thiscall std::vector<SchedulerUsage_t>::_Ucopy<std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t>>>(
        std::vector<SchedulerUsage_t> *this,
        std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t> > _First,
        std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t> > _Last,
        SchedulerUsage_t *_Ptr)
{
  return std::_Uninit_copy<std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t>>,SchedulerUsage_t *,std::allocator<SchedulerUsage_t>>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: (std::allocator<std::pair<int const ,int> > *)&this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x00404310
// Name: protected: void std::vector<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>::_Tidy(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<SchedulerUsage_t>::_Tidy(std::vector<SchedulerUsage_t> *this)
{
  if ( this->_Myfirst != nullptr )
    operator delete(p: this->_Myfirst);
  this->_Myfirst = nullptr;
  this->_Mylast = nullptr;
  this->_Myend = nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x00404340
// Name: public: void std::vector<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<SchedulerUsage_t>::reserve(std::vector<SchedulerUsage_t> *this, unsigned int _Count)
{
  SchedulerUsage_t *v3; // ebx
  int v4; // edi
  int v5; // [esp+0h] [ebp-20h] BYREF
  SchedulerUsage_t *_Ptr; // [esp+Ch] [ebp-14h]
  int *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( _Count > 0x1FFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    v3 = std::allocator<SchedulerUsage_t>::allocate(this: &this->_Alval, _Count);
    _Ptr = v3;
    v8 = 0;
    std::vector<SchedulerUsage_t>::_Umove<SchedulerUsage_t *>(
      this,
      _First: this->_Myfirst,
      _Last: this->_Mylast,
      _Ptr: v3);
    v8 = -1;
    v4 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      operator delete(p: this->_Myfirst);
    this->_Myend = &v3[_Count];
    this->_Mylast = &v3[v4];
    this->_Myfirst = v3;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404400
// Name: public: void std::vector<struct OptimalComboScheduleFileRecord_t,class std::allocator<struct OptimalComboScheduleFileRecord_t>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<OptimalComboScheduleFileRecord_t>::reserve(
        std::vector<OptimalComboScheduleFileRecord_t> *this,
        unsigned int _Count)
{
  int v4; // edi
  _DWORD v5[4]; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+18h] [ebp-4h]
  OptimalComboScheduleFileRecord_t *_Ptr; // [esp+24h] [ebp+8h]

  v5[3] = v5;
  if ( _Count > 0xFFFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    _Ptr = std::allocator<OptimalComboScheduleFileRecord_t>::allocate(this: &this->_Alval, _Count);
    v6 = 0;
    std::vector<OptimalComboScheduleFileRecord_t>::_Umove<OptimalComboScheduleFileRecord_t *>(
      this,
      _First: this->_Myfirst,
      _Last: this->_Mylast,
      _Ptr);
    v6 = -1;
    v4 = (char *)this->_Mylast - (char *)this->_Myfirst;
    if ( this->_Myfirst != nullptr )
      operator delete(p: this->_Myfirst);
    this->_Myend = &_Ptr[_Count];
    this->_Mylast = (OptimalComboScheduleFileRecord_t *)((char *)_Ptr + (v4 & 0xFFFFFFF0));
    this->_Myfirst = _Ptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004044C0
// Name: void std::_Sort<struct SchedulerUsage_t __near *,int>(struct SchedulerUsage_t __near *,struct SchedulerUsage_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort<SchedulerUsage_t *,int>(SchedulerUsage_t *_First, SchedulerUsage_t *_Last, int _Ideal)
{
  SchedulerUsage_t *second; // ebx
  SchedulerUsage_t *first; // edi
  int v5; // eax
  std::pair<SchedulerUsage_t *,SchedulerUsage_t *> _Mid; // [esp+Ch] [ebp-8h] BYREF

  second = _First;
  first = _Last;
  v5 = _Last - _First;
  if ( v5 <= 32 )
  {
LABEL_7:
    if ( v5 > 1 )
      std::_Insertion_sort1<SchedulerUsage_t *,SchedulerUsage_t>(_First: second, _Last: first);
  }
  else
  {
    while ( _Ideal > 0 )
    {
      std::_Unguarded_partition<SchedulerUsage_t *>(result: &_Mid, _First: second, _Last: first);
      _Ideal = _Ideal / 2 / 2 + _Ideal / 2;
      if ( (int)(((char *)_Mid.first - (char *)second) & 0xFFFFFFF8) >= (int)(((char *)first - (char *)_Mid.second)
                                                                            & 0xFFFFFFF8) )
      {
        std::_Sort<SchedulerUsage_t *,int>(_First: _Mid.second, _Last: first, _Ideal);
        first = _Mid.first;
      }
      else
      {
        std::_Sort<SchedulerUsage_t *,int>(_First: second, _Last: _Mid.first, _Ideal);
        second = _Mid.second;
      }
      v5 = first - second;
      if ( v5 <= 32 )
        goto LABEL_7;
    }
    if ( (int)(((char *)first - (char *)second) & 0xFFFFFFF8) > 8 )
      std::_Make_heap<SchedulerUsage_t *,int,SchedulerUsage_t>(_First: second, _Last: first);
    std::_Sort_heap<SchedulerUsage_t *>(_First: second, _Last: first);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404590
// Name: void std::_Sort<struct OptimalComboScheduleFileRecord_t __near *,int>(struct OptimalComboScheduleFileRecord_t __near *,struct OptimalComboScheduleFileRecord_t __near *,int)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Sort<OptimalComboScheduleFileRecord_t *,int>(
        OptimalComboScheduleFileRecord_t *_First,
        OptimalComboScheduleFileRecord_t *_Last,
        int _Ideal)
{
  OptimalComboScheduleFileRecord_t *second; // ebx
  OptimalComboScheduleFileRecord_t *first; // edi
  int v5; // eax
  std::pair<OptimalComboScheduleFileRecord_t *,OptimalComboScheduleFileRecord_t *> _Mid; // [esp+Ch] [ebp-8h] BYREF

  second = _First;
  first = _Last;
  v5 = _Last - _First;
  if ( v5 <= 32 )
  {
LABEL_7:
    if ( v5 > 1 )
      std::_Insertion_sort1<OptimalComboScheduleFileRecord_t *,OptimalComboScheduleFileRecord_t>(
        _First: second,
        _Last: first);
  }
  else
  {
    while ( _Ideal > 0 )
    {
      std::_Unguarded_partition<OptimalComboScheduleFileRecord_t *>(result: &_Mid, _First: second, _Last: first);
      _Ideal = _Ideal / 2 / 2 + _Ideal / 2;
      if ( (int)(((char *)_Mid.first - (char *)second) & 0xFFFFFFF0) >= (int)(((char *)first - (char *)_Mid.second)
                                                                            & 0xFFFFFFF0) )
      {
        std::_Sort<OptimalComboScheduleFileRecord_t *,int>(_First: _Mid.second, _Last: first, _Ideal);
        first = _Mid.first;
      }
      else
      {
        std::_Sort<OptimalComboScheduleFileRecord_t *,int>(_First: second, _Last: _Mid.first, _Ideal);
        second = _Mid.second;
      }
      v5 = first - second;
      if ( v5 <= 32 )
        goto LABEL_7;
    }
    if ( (int)(((char *)first - (char *)second) & 0xFFFFFFF0) > 16 )
      std::_Make_heap<OptimalComboScheduleFileRecord_t *,int,OptimalComboScheduleFileRecord_t>(
        _First: second,
        _Last: first);
    std::_Sort_heap<OptimalComboScheduleFileRecord_t *>(_First: second, _Last: first);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404660
// Name: void std::_Destroy_range<class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>> __near &,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Destroy_range<std::allocator<std::string>>(std::string *_First, std::string *_Last)
{
  std::string *i; // esi

  for ( i = _First; i != _Last; ++i )
  {
    if ( i->_Myres >= 0x10 )
      operator delete(p: i->_Bx._Ptr);
    i->_Myres = 15;
    i->_Mysize = 0;
    i->_Bx._Buf[0] = 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x004046A0
// Name: void std::_Dest_val<class std::allocator<struct CompileStats_t>,struct CompileStats_t>(class std::allocator<struct CompileStats_t> __near &,struct CompileStats_t __near *)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Dest_val<std::allocator<CompileStats_t>,CompileStats_t>(
        std::allocator<CompileStats_t> *_Alval,
        CompileStats_t *_Pdest)
{
  if ( _Pdest->m_Filename._Myres >= 0x10 )
    operator delete(p: _Pdest->m_Filename._Bx._Ptr);
  _Pdest->m_Filename._Myres = 15;
  _Pdest->m_Filename._Mysize = 0;
  _Pdest->m_Filename._Bx._Buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004046D0
// Name: public: std::vector<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>::vector<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>>(class std::vector<struct SchedulerUsage_t,class std::allocator<struct SchedulerUsage_t>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::vector<SchedulerUsage_t> *__thiscall std::vector<SchedulerUsage_t>::vector<SchedulerUsage_t>(
        std::vector<SchedulerUsage_t> *this,
        const std::vector<SchedulerUsage_t> *_Right)
{
  unsigned int v3; // edi
  SchedulerUsage_t *v4; // eax
  int v6; // [esp+0h] [ebp-20h] BYREF
  std::vector<SchedulerUsage_t> *v7; // [esp+Ch] [ebp-14h]
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
    if ( v3 > 0x1FFFFFFF )
      std::_Xlength_error(_Message: "vector<T> too long");
    v4 = std::allocator<SchedulerUsage_t>::allocate(this: &this->_Alval, _Count: v3);
    this->_Myfirst = v4;
    this->_Mylast = v4;
    this->_Myend = &v4[v3];
    v9 = 0;
    this->_Mylast = std::vector<SchedulerUsage_t>::_Ucopy<std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t>>>(
                      this,
                      _First: (std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t> >)_Right->_Myfirst,
                      _Last: (std::_Vector_const_iterator<std::_Vector_val<SchedulerUsage_t> >)_Right->_Mylast,
                      _Ptr: this->_Myfirst);
    v9 = -1;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00404790
// Name: protected: struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near * std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Copy(struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *__thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Copy(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Rootnode,
        std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Wherenode)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v4; // esi
  int v6; // [esp+0h] [ebp-24h] BYREF
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *v7; // [esp+Ch] [ebp-18h]
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *_Newroot; // [esp+10h] [ebp-14h]
  int *v9; // [esp+14h] [ebp-10h]
  int v10; // [esp+20h] [ebp-4h]

  v9 = &v6;
  v7 = this;
  _Newroot = this->_Myhead;
  if ( _Rootnode->_Isnil == 0 )
  {
    v4 = std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Buynode<std::pair<int const,int> &>(
           this,
           _Val: &_Rootnode->_Myval);
    v4->_Parent = _Wherenode;
    v4->_Color = _Rootnode->_Color;
    if ( _Newroot->_Isnil != 0 )
      _Newroot = v4;
    v10 = 0;
    v4->_Left = std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Copy(
                  this,
                  _Rootnode: _Rootnode->_Left,
                  _Wherenode: v4);
    v4->_Right = std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Copy(
                   this,
                   _Rootnode: _Rootnode->_Right,
                   _Wherenode: v4);
    v10 = -1;
  }
  return _Newroot;
}

//------------------------------------------------------------------------------
// Address: 0x00404840
// Name: public: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near & std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>::assign(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near &&)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::string::assign(std::string *this, std::string *_Right)
{
  if ( this != _Right )
  {
    if ( this->_Myres >= 0x10 )
      operator delete(p: this->_Bx._Ptr);
    this->_Myres = 15;
    this->_Mysize = 0;
    this->_Bx._Buf[0] = 0;
    if ( _Right->_Myres >= 0x10 )
    {
      this->_Bx._Ptr = _Right->_Bx._Ptr;
      _Right->_Bx._Ptr = nullptr;
    }
    else
    {
      memmove(dst: (unsigned __int8 *)this, src: (unsigned __int8 *)_Right, count: _Right->_Mysize + 1);
    }
    this->_Mysize = _Right->_Mysize;
    this->_Myres = _Right->_Myres;
    _Right->_Myres = 15;
    _Right->_Mysize = 0;
    _Right->_Bx._Buf[0] = 0;
  }
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x004048C0
// Name: protected: void std::vector<struct OptimalComboScheduleFileRecord_t,class std::allocator<struct OptimalComboScheduleFileRecord_t>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<OptimalComboScheduleFileRecord_t>::_Reserve(
        std::vector<OptimalComboScheduleFileRecord_t> *this,
        unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0xFFFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0xFFFFFFF - (v4 >> 1) >= v4 )
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
    std::vector<OptimalComboScheduleFileRecord_t>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404930
// Name: protected: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>> std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Insert(
        std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v6; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Myhead; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v8; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v9; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Parent; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v12; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Right; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v14; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v15; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v16; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v17; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v19; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v20; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v21; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v22; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v24; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v25; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v26; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v27; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v28; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v29; // ecx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x71C71C6 )
  {
    if ( _Newnode->_Myval.first._Myres >= 0x10 )
      operator delete(p: _Newnode->_Myval.first._Bx._Ptr);
    _Newnode->_Myval.first._Myres = 15;
    _Newnode->_Myval.first._Mysize = 0;
    _Newnode->_Myval.first._Bx._Buf[0] = 0;
    operator delete(p: _Newnode);
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
// Address: 0x00404B80
// Name: void std::_Destroy_range<class std::allocator<struct CompileStats_t>>(struct CompileStats_t __near *,struct CompileStats_t __near *,class std::allocator<struct CompileStats_t> __near &,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Destroy_range<std::allocator<CompileStats_t>>(CompileStats_t *_First, CompileStats_t *_Last)
{
  unsigned int *p_Myres; // esi

  if ( _First != _Last )
  {
    p_Myres = &_First->m_Filename._Myres;
    do
    {
      if ( *p_Myres >= 0x10 )
        operator delete(p: (void *)*(p_Myres - 5));
      *p_Myres = 15;
      *(p_Myres - 1) = 0;
      *((_BYTE *)p_Myres - 20) = 0;
      p_Myres += 16;
    }
    while ( p_Myres - 9 != (unsigned int *)_Last );
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404BD0
// Name: struct CompileStats_t __near * std::_Uninit_move<struct CompileStats_t __near *,struct CompileStats_t __near *,class std::allocator<struct CompileStats_t>,struct CompileStats_t>(struct CompileStats_t __near *,struct CompileStats_t __near *,struct CompileStats_t __near *,class std::allocator<struct CompileStats_t> __near &,struct CompileStats_t __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
CompileStats_t *__cdecl std::_Uninit_move<CompileStats_t *,CompileStats_t *,std::allocator<CompileStats_t>,CompileStats_t>(
        CompileStats_t *_First,
        CompileStats_t *_Last,
        CompileStats_t *_Dest,
        std::allocator<CompileStats_t> *_Al)
{
  CompileStats_t *v4; // edi
  int v7; // [esp+0h] [ebp-20h] BYREF
  CompileStats_t *_Next; // [esp+Ch] [ebp-14h]
  int *v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-4h]

  v9 = &v7;
  v4 = _Dest;
  _Next = _Dest;
  v10 = 0;
  while ( _First != _Last )
    std::_Cons_val<std::allocator<CompileStats_t>,CompileStats_t,CompileStats_t>(
      _Alval: _Al,
      _Pdest: v4++,
      _Src: _First++);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00404C70
// Name: protected: void std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Copy(class std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Copy(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        const std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *_Right)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Myhead; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v4; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v7; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v8; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *j; // eax

  Myhead = this->_Myhead;
  Myhead->_Parent = std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Copy(
                      this,
                      _Rootnode: _Right->_Myhead->_Parent,
                      _Wherenode: Myhead);
  v4 = this->_Myhead;
  this->_Mysize = _Right->_Mysize;
  Parent = v4->_Parent;
  if ( Parent->_Isnil != 0 )
  {
    v4->_Left = v4;
    this->_Myhead->_Right = this->_Myhead;
  }
  else
  {
    for ( i = Parent->_Left; i->_Isnil == 0; i = i->_Left )
      Parent = i;
    v4->_Left = Parent;
    v7 = this->_Myhead;
    v8 = v7->_Parent;
    for ( j = v8->_Right; j->_Isnil == 0; j = j->_Right )
      v8 = j;
    v7->_Right = v8;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404CF0
// Name: public: void std::vector<struct OptimalComboScheduleFileRecord_t,class std::allocator<struct OptimalComboScheduleFileRecord_t>>::resize(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<OptimalComboScheduleFileRecord_t>::resize(
        std::vector<OptimalComboScheduleFileRecord_t> *this,
        unsigned int _Newsize)
{
  OptimalComboScheduleFileRecord_t *Mylast; // ecx
  unsigned int v4; // eax
  OptimalComboScheduleFileRecord_t *v5; // edx

  Mylast = this->_Mylast;
  v4 = Mylast - this->_Myfirst;
  if ( v4 <= _Newsize )
  {
    if ( v4 < _Newsize )
    {
      std::vector<OptimalComboScheduleFileRecord_t>::_Reserve(this, _Count: _Newsize - v4);
      std::_Uninit_def_fill_n<OptimalComboScheduleFileRecord_t *,unsigned int,OptimalComboScheduleFileRecord_t,std::allocator<OptimalComboScheduleFileRecord_t>,OptimalComboScheduleFileRecord_t>(
        _First: this->_Mylast,
        _Count: _Newsize - (this->_Mylast - this->_Myfirst),
        __formal: nullptr,
        _Al: &this->_Alval);
      this->_Mylast += _Newsize - (this->_Mylast - this->_Myfirst);
    }
  }
  else
  {
    v5 = &this->_Myfirst[_Newsize];
    if ( v5 != Mylast )
      this->_Mylast = v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00404DA0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>> std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > _Where)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Ptr; // ebx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *v7; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v9; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v12; // ecx
  char Color; // cl
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v14; // eax
  std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *i; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Erasednode; // [esp+10h] [ebp-8h]

  Ptr = _Where._Ptr;
  if ( _Where._Ptr->_Isnil != 0 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  _Erasednode = _Where._Ptr;
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
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
        v9 = std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Min(_Pnode: Right);
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
        v10->_Right = std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Max(_Pnode: Right);
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
          std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Lrotate(
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
            std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Rrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Right;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Lrotate(
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
          std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Rrotate(
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
            std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Lrotate(
              this: i,
              _Wherenode: Left);
            Left = Parent->_Left;
            i = this;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Rrotate(
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
  if ( v14->_Myval.first._Myres >= 0x10 )
    operator delete(p: v14->_Myval.first._Bx._Ptr);
  _Erasednode->_Myval.first._Myres = 15;
  _Erasednode->_Myval.first._Mysize = 0;
  _Erasednode->_Myval.first._Bx._Buf[0] = 0;
  operator delete(p: _Erasednode);
  Mysize = this->_Mysize;
  if ( Mysize != 0 )
    this->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405020
// Name: protected: void std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Erase(
        std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v2; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *i; // edi

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    if ( v2->_Myval.first._Myres >= 0x10 )
      operator delete(p: v2->_Myval.first._Bx._Ptr);
    v2->_Myval.first._Myres = 15;
    v2->_Myval.first._Mysize = 0;
    v2->_Myval.first._Bx._Buf[0] = 0;
    operator delete(p: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405080
// Name: public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>>,bool> std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > >,bool> *__thiscall std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Linsert(
        std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *this,
        std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > >,bool> *result,
        std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Node,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > _Leftish)
{
  std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *v4; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Parent; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v7; // edi
  std::pair<std::string const ,CMachineStats> *p_Myval; // ebx
  bool v9; // al
  std::pair<std::string const ,CMachineStats> *v10; // eax
  std::pair<std::string const ,CMachineStats> *Ptr; // edx
  unsigned int Mysize; // esi
  unsigned int v13; // edi
  unsigned int v14; // ecx
  int v15; // eax
  bool v16; // sf
  unsigned int v17; // edi
  unsigned int v18; // esi
  unsigned int v19; // edx
  std::pair<std::string const ,CMachineStats> *v20; // ecx
  int v21; // eax
  bool v22; // sf
  int v23; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Left; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v25; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *v26; // eax
  std::pair<std::string const ,CMachineStats> *v28; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Wherenode; // [esp+Ch] [ebp-10h]
  std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *v30; // [esp+10h] [ebp-Ch]
  bool _Addleft; // [esp+14h] [ebp-8h]
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *_Trynode; // [esp+18h] [ebp-4h]

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
        if ( _Node->_Myval.first._Myres < 0x10 )
          Ptr = &_Node->_Myval;
        else
          Ptr = (std::pair<std::string const ,CMachineStats> *)p_Myval->first._Bx._Ptr;
        Mysize = Parent->_Myval.first._Mysize;
        v13 = _Node->_Myval.first._Mysize;
        v14 = Mysize;
        if ( Mysize >= v13 )
          v14 = _Node->_Myval.first._Mysize;
        if ( v10->first._Myres >= 0x10 )
          v10 = (std::pair<std::string const ,CMachineStats> *)v10->first._Bx._Ptr;
        v15 = std::char_traits<char>::compare(_First1: v10->first._Bx._Buf, _First2: Ptr->first._Bx._Buf, _Count: v14);
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
        v17 = Parent->_Myval.first._Mysize;
        if ( Parent->_Myval.first._Myres >= 0x10 )
          v10 = (std::pair<std::string const ,CMachineStats> *)v10->first._Bx._Ptr;
        v18 = _Node->_Myval.first._Mysize;
        v19 = v18;
        if ( v18 >= v17 )
          v19 = Parent->_Myval.first._Mysize;
        if ( _Node->_Myval.first._Myres < 0x10 )
          v20 = &_Node->_Myval;
        else
          v20 = (std::pair<std::string const ,CMachineStats> *)p_Myval->first._Bx._Ptr;
        v21 = std::char_traits<char>::compare(_First1: v20->first._Bx._Buf, _First2: v10->first._Bx._Buf, _Count: v19);
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
      v26 = std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Insert(
              this: v4,
              result: &_Leftish,
              _Addleft: true,
              _Wherenode: v7,
              _Newnode: _Node);
LABEL_38:
      result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > >)v26->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    v25 = _Leftish._Ptr;
  }
  if ( _Node->_Myval.first._Myres < 0x10 )
    v28 = &_Node->_Myval;
  else
    v28 = (std::pair<std::string const ,CMachineStats> *)p_Myval->first._Bx._Ptr;
  if ( std::string::compare(
         this: &v25->_Myval.first,
         _Off: 0,
         _N0: v25->_Myval.first._Mysize,
         _Ptr: v28->first._Bx._Buf,
         _Count: _Node->_Myval.first._Mysize) < 0 )
  {
    v26 = std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Insert(
            this: v30,
            result: &_Leftish,
            _Addleft,
            _Wherenode: v7,
            _Newnode: _Node);
    goto LABEL_38;
  }
  if ( _Node->_Myval.first._Myres >= 0x10 )
    operator delete(p: p_Myval->first._Bx._Ptr);
  _Node->_Myval.first._Myres = 15;
  _Node->_Myval.first._Mysize = 0;
  p_Myval->first._Bx._Buf[0] = 0;
  operator delete(p: _Node);
  result->first._Ptr = v25;
  result->second = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00405240
// Name: public: std::_Pair_base<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>::~_Pair_base<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Pair_base<std::string const,PerShaderStats_t>::~_Pair_base<std::string const,PerShaderStats_t>(
        std::_Pair_base<std::string const ,PerShaderStats_t> *this)
{
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > result; // [esp+Ch] [ebp-4h] BYREF

  if ( this->second.m_SortedSchedulerUsage._Myfirst != nullptr )
    operator delete(p: this->second.m_SortedSchedulerUsage._Myfirst);
  this->second.m_SortedSchedulerUsage._Myfirst = nullptr;
  this->second.m_SortedSchedulerUsage._Mylast = nullptr;
  this->second.m_SortedSchedulerUsage._Myend = nullptr;
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
    this: &this->second.m_SchedulerHist,
    &result,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)this->second.m_SchedulerHist._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)this->second.m_SchedulerHist._Myhead);
  operator delete(p: this->second.m_SchedulerHist._Myhead);
  if ( this->first._Myres >= 0x10 )
    operator delete(p: this->first._Bx._Ptr);
  this->first._Mysize = 0;
  this->first._Myres = 15;
  this->first._Bx._Buf[0] = 0;
}

//------------------------------------------------------------------------------
// Address: 0x004052B0
// Name: public: std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>>(class std::_Tree<class std::_Tmap_traits<int,int,struct std::less<int>,class std::allocator<struct std::pair<int const,int>>,0>> const __near &)
// Source: json
//------------------------------------------------------------------------------
std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *__thiscall std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>(
        std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *this,
        const std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *_Right)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v3; // eax
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > *v7; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v7 = this;
  this->_Mysize = 0;
  v3 = (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)operator new(size: 0x18u);
  if ( v3 == nullptr )
  {
    _Right = nullptr;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&_Right);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  this->_Myhead = v3;
  v3->_Left = v3;
  this->_Myhead->_Parent = this->_Myhead;
  this->_Myhead->_Right = this->_Myhead;
  this->_Myhead->_Color = 1;
  this->_Myhead->_Isnil = 1;
  v9 = 0;
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Copy(this, _Right);
  v9 = -1;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405380
// Name: PrintGlobalSchedulerStatistics
// Source: json
//------------------------------------------------------------------------------
void __cdecl PrintGlobalSchedulerStatistics(const std::vector<CompileStats_t> *compileStats)
{
  unsigned int v1; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v2; // eax
  CompileStats_t *Myfirst; // eax
  int v4; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v5; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Left; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Ptr; // ebx
  SchedulerUsage_t *v8; // edx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v9; // ecx
  int v10; // edi
  int *p_Parent; // esi
  int v12; // eax
  int v13; // edx
  double v14; // st7
  int first; // esi
  int v16; // esi
  unsigned int v17; // eax
  unsigned int v18; // eax
  unsigned int v19; // ecx
  unsigned int v20; // ecx
  unsigned int v21; // eax
  unsigned int v22; // eax
  unsigned int v23; // ecx
  unsigned int v24; // ecx
  int second; // ecx
  bool v26; // zf
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // eax
  std::map<int,int> schedulerHist; // [esp+14h] [ebp-28h] BYREF
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >,bool> insRes; // [esp+24h] [ebp-18h] BYREF
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >,bool> result; // [esp+2Ch] [ebp-10h] BYREF
  std::pair<int const ,int> _Val; // [esp+34h] [ebp-8h] BYREF

  v1 = 0;
  schedulerHist._Mysize = 0;
  v2 = (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)operator new(size: 0x18u);
  if ( v2 == nullptr )
  {
    _Val.second = 0;
    std::exception::exception(this: (std::exception *)&insRes.second, _What: (const char *const *)&_Val.second);
    *(_DWORD *)&insRes.second = &std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject: &insRes.second, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  schedulerHist._Myhead = v2;
  v2->_Left = v2;
  schedulerHist._Myhead->_Parent = schedulerHist._Myhead;
  schedulerHist._Myhead->_Right = schedulerHist._Myhead;
  schedulerHist._Myhead->_Color = 1;
  schedulerHist._Myhead->_Isnil = 1;
  Myfirst = compileStats->_Myfirst;
  if ( compileStats->_Mylast - compileStats->_Myfirst != 0 )
  {
    _Val.second = 0;
    v4 = 0;
    do
    {
      _Val.first = Myfirst[v4].m_nOptSchedule;
      v5 = std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Buynode<std::pair<int const,int> &>(
             this: &schedulerHist,
             &_Val);
      std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Linsert(
        this: &schedulerHist,
        &result,
        _Node: v5,
        _Leftish: 0);
      ++result.first._Ptr->_Myval.second;
      Myfirst = compileStats->_Myfirst;
      ++v1;
      ++v4;
    }
    while ( v1 < compileStats->_Mylast - compileStats->_Myfirst );
  }
  printf(format: "Global scheduler statistics:\n");
  Left = schedulerHist._Myhead->_Left;
  Ptr = nullptr;
  v8 = nullptr;
  v9 = nullptr;
  insRes.first._Ptr = nullptr;
  *(_DWORD *)&insRes.second = 0;
  result.first._Ptr = nullptr;
  if ( Left != schedulerHist._Myhead )
  {
    while ( 1 )
    {
      first = Left->_Myval.first;
      _Val.second = Left->_Myval.second;
      _Val.first = first;
      if ( &_Val >= (std::pair<int const ,int> *)v8
        || Ptr > (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)&_Val )
      {
        if ( v8 == (SchedulerUsage_t *)v9 )
        {
          v21 = ((char *)v8 - (char *)Ptr) >> 3;
          if ( v21 > 0x1FFFFFFE )
LABEL_48:
            std::_Xlength_error(_Message: "vector<T> too long");
          v22 = v21 + 1;
          v23 = ((char *)v9 - (char *)Ptr) >> 3;
          if ( v22 > v23 )
          {
            if ( 0x1FFFFFFF - (v23 >> 1) >= v23 )
              v24 = (v23 >> 1) + v23;
            else
              v24 = 0;
            if ( v24 < v22 )
              v24 = v22;
            std::vector<SchedulerUsage_t>::reserve(this: (std::vector<SchedulerUsage_t> *)&insRes, _Count: v24);
            v8 = *(SchedulerUsage_t **)&insRes.second;
            Ptr = insRes.first._Ptr;
          }
        }
        if ( v8 != nullptr )
        {
          second = _Val.second;
          v8->m_nScheduleIndex = first;
          v8->m_nTotalUses = second;
        }
      }
      else
      {
        v16 = ((char *)&_Val - (char *)Ptr) >> 3;
        if ( v8 == (SchedulerUsage_t *)v9 )
        {
          v17 = ((char *)v8 - (char *)Ptr) >> 3;
          if ( v17 > 0x1FFFFFFE )
            goto LABEL_48;
          v18 = v17 + 1;
          v19 = ((char *)v9 - (char *)Ptr) >> 3;
          if ( v18 > v19 )
          {
            if ( 0x1FFFFFFF - (v19 >> 1) >= v19 )
              v20 = (v19 >> 1) + v19;
            else
              v20 = 0;
            if ( v20 < v18 )
              v20 = v18;
            std::vector<SchedulerUsage_t>::reserve(this: (std::vector<SchedulerUsage_t> *)&insRes, _Count: v20);
            v8 = *(SchedulerUsage_t **)&insRes.second;
            Ptr = insRes.first._Ptr;
          }
        }
        if ( v8 != nullptr )
        {
          v8->m_nScheduleIndex = *((_DWORD *)&Ptr->_Left + 2 * v16);
          v8->m_nTotalUses = *((_DWORD *)&Ptr->_Parent + 2 * v16);
        }
      }
      ++v8;
      v26 = Left->_Isnil == 0;
      *(_DWORD *)&insRes.second = v8;
      if ( v26 )
      {
        Right = Left->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = Left->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( Left != i->_Right )
              break;
            Left = i;
          }
          Left = i;
        }
        else
        {
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            Right = j;
          Left = Right;
        }
      }
      if ( Left == schedulerHist._Myhead )
        break;
      v9 = result.first._Ptr;
    }
  }
  v10 = ((char *)v8 - (char *)Ptr) >> 3;
  std::_Sort<SchedulerUsage_t *,int>(_First: (SchedulerUsage_t *)Ptr, _Last: v8, _Ideal: v10);
  if ( v10 != 0 )
  {
    p_Parent = (int *)&Ptr->_Parent;
    do
    {
      v13 = (char *)compileStats->_Mylast - (char *)compileStats->_Myfirst;
      _Val.second = *p_Parent;
      v12 = _Val.second;
      v14 = (double)_Val.second;
      _Val.second = v13 >> 6;
      printf(
        format: "   Schedule: %i, Uses: %i (%3.1f%%)\n",
        *(p_Parent - 1),
        v12,
        v14 * 100.0 / (double)(unsigned int)(v13 >> 6));
      p_Parent += 2;
      --v10;
    }
    while ( v10 != 0 );
  }
  printf(format: "\n");
  if ( Ptr != nullptr )
    operator delete(p: Ptr);
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
    this: &schedulerHist,
    result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *)&_Val.second,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)schedulerHist._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)schedulerHist._Myhead);
  operator delete(p: schedulerHist._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x00405640
// Name: WriteOutputFile
// Source: json
//------------------------------------------------------------------------------
char __cdecl WriteOutputFile(
        const std::vector<CompileStats_t> *compileStats,
        const std::map<std::string,PerShaderStats_t> *shaderStats,
        const char *pFilename)
{
  OptimalComboScheduleFileRecord_t *Myfirst; // esi
  int v4; // edi
  unsigned int v5; // ebx
  int *v6; // esi
  CompileStats_t *v7; // ecx
  char **p_First2; // eax
  __int64 v9; // rax
  unsigned int v10; // edi
  char **p_m_nOptSchedule; // edx
  int m_nOptSchedule; // eax
  int v13; // eax
  unsigned int v14; // eax
  int v15; // edx
  int *p_m_nOptSeed; // eax
  unsigned int v17; // eax
  std::string *p_m_Filename; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v19; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Myhead; // ebx
  unsigned int Mysize; // edx
  std::pair<std::string const ,PerShaderStats_t> *p_Myval; // eax
  bool v23; // cf
  unsigned int v24; // ecx
  int v25; // eax
  bool v26; // sf
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *p_findRes; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Ptr; // eax
  int v29; // edx
  unsigned int v30; // ecx
  _DWORD *v31; // edi
  SchedulerUsage_t *v32; // eax
  int m_nScheduleIndex; // ebx
  int *p_m_nScheduleIndex; // eax
  int v35; // ebx
  unsigned int v36; // eax
  int v37; // ecx
  int v38; // edi
  int v39; // edx
  __int16 v40; // ax
  int v41; // edi
  int v42; // eax
  std::vector<OptimalComboScheduleFileRecord_t> records; // [esp+Ch] [ebp-58h] BYREF
  int altSchedules[3]; // [esp+1Ch] [ebp-48h]
  OptimalComboScheduleFileHeader_t hdr; // [esp+28h] [ebp-3Ch] BYREF
  int v47; // [esp+30h] [ebp-34h]
  int v48; // [esp+34h] [ebp-30h]
  int v49; // [esp+38h] [ebp-2Ch] BYREF
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v50; // [esp+3Ch] [ebp-28h] BYREF
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > findRes; // [esp+40h] [ebp-24h] BYREF
  unsigned int v52; // [esp+44h] [ebp-20h]
  int v53; // [esp+48h] [ebp-1Ch] BYREF
  int v54; // [esp+4Ch] [ebp-18h] BYREF
  int v55; // [esp+50h] [ebp-14h]
  char *_First2; // [esp+54h] [ebp-10h] BYREF
  unsigned int v57; // [esp+58h] [ebp-Ch]
  unsigned int d; // [esp+5Ch] [ebp-8h]
  _iobuf *pFile; // [esp+60h] [ebp-4h] BYREF

  memset(&records, 0, 12);
  std::vector<OptimalComboScheduleFileRecord_t>::resize(
    this: &records,
    _Newsize: compileStats->_Mylast - compileStats->_Myfirst);
  Myfirst = records._Myfirst;
  v4 = records._Mylast - records._Myfirst;
  v5 = 16 * v4;
  v48 = v4;
  v47 = 16 * v4;
  memset(dst: (unsigned __int8 *)records._Myfirst, value: 0, count: 16 * v4);
  if ( v4 != 0 )
  {
    v54 = 511;
    v53 = 1023;
    v57 = 0;
    v6 = (int *)Myfirst + 2;
    v55 = v4;
    while ( 1 )
    {
      v7 = &compileStats->_Myfirst[v57 / 0x40];
      *(v6 - 2) = v7->m_nComboHash;
      *(v6 - 1) = HIDWORD(v7->m_nComboHash);
      _First2 = (char *)v7->m_nOptCycles;
      p_First2 = &_First2;
      if ( (int)_First2 >= 511 )
        p_First2 = (char **)&v54;
      v9 = (unsigned int)*p_First2 & 0x1FF;
      v10 = *v6 & 0xFFFFFE00;
      v6[1] |= HIDWORD(v9);
      p_m_nOptSchedule = (char **)&v7->m_nOptSchedule;
      *v6 = v10 | v9;
      m_nOptSchedule = v7->m_nOptSchedule;
      v49 = (int)&v7->m_nOptSchedule;
      if ( m_nOptSchedule >= 0 )
      {
        _First2 = (char *)1022;
        if ( m_nOptSchedule >= 1022 )
          p_m_nOptSchedule = &_First2;
        v14 = *v6 & 0xFFF801FF | (((unsigned int)*p_m_nOptSchedule & 0x3FF) << 9);
        v15 = v6[1];
        *v6 = v14;
        v6[1] = v15;
      }
      else
      {
        v13 = v6[1];
        *v6 |= 0x7FE00u;
        v6[1] = v13;
      }
      p_m_nOptSeed = &v7->m_nOptSeed;
      if ( v7->m_nOptSeed >= 1023 )
        p_m_nOptSeed = &v53;
      v17 = *v6 & 0xE007FFFF | ((*p_m_nOptSeed & 0x3FF) << 19);
      v6[1] = v6[1];
      p_m_Filename = &v7->m_Filename;
      v6[1] = v6[1] & 0x7FFFFFF | 0x88000000;
      *v6 = v17;
      altSchedules[0] = 1023;
      altSchedules[1] = 1023;
      altSchedules[2] = 1023;
      v19 = std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Lbound(
              this: &shaderStats->std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >,
              _Keyval: &v7->m_Filename);
      Myhead = shaderStats->_Myhead;
      findRes._Ptr = v19;
      if ( v19 == Myhead )
        goto LABEL_25;
      Mysize = v19->_Myval.first._Mysize;
      p_Myval = &v19->_Myval;
      v23 = p_Myval->first._Myres < 0x10;
      v52 = Mysize;
      if ( v23 )
        _First2 = (char *)p_Myval;
      else
        _First2 = p_Myval->first._Bx._Ptr;
      d = p_m_Filename->_Mysize;
      v24 = d;
      if ( d >= Mysize )
        v24 = Mysize;
      if ( p_m_Filename->_Myres >= 0x10 )
        p_m_Filename = (std::string *)p_m_Filename->_Bx._Ptr;
      v25 = std::char_traits<char>::compare(_First1: p_m_Filename->_Bx._Buf, _First2, _Count: v24);
      v26 = v25 < 0;
      if ( v25 == 0 )
      {
        if ( d < v52 )
          goto LABEL_25;
        v26 = false;
      }
      if ( !v26 )
      {
        p_findRes = &findRes;
        goto LABEL_26;
      }
LABEL_25:
      v50 = Myhead;
      p_findRes = (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *)&v50;
LABEL_26:
      Ptr = p_findRes->_Ptr;
      findRes._Ptr = Ptr;
      if ( Ptr != Myhead )
      {
        v29 = 0;
        v30 = Ptr->_Myval.second.m_SortedSchedulerUsage._Mylast - Ptr->_Myval.second.m_SortedSchedulerUsage._Myfirst;
        d = 0;
        if ( v30 != 0 )
        {
          v31 = (_DWORD *)v49;
          while ( d < 3 )
          {
            v32 = Ptr->_Myval.second.m_SortedSchedulerUsage._Myfirst;
            m_nScheduleIndex = v32[v29].m_nScheduleIndex;
            p_m_nScheduleIndex = &v32[v29].m_nScheduleIndex;
            if ( m_nScheduleIndex != *v31 )
            {
              v49 = 1022;
              if ( m_nScheduleIndex >= 1022 )
                p_m_nScheduleIndex = &v49;
              v35 = *p_m_nScheduleIndex;
              v36 = d;
              altSchedules[d] = v35;
              d = v36 + 1;
            }
            if ( ++v29 >= v30 )
              break;
            Ptr = findRes._Ptr;
          }
        }
      }
      v37 = *v6;
      v38 = v6[1];
      v39 = (unsigned __int64)(altSchedules[0] & 0x3FF) >> 3;
      v57 += 64;
      *v6 = v37 & 0x1FFFFFFF | ((altSchedules[0] & 0x3FF) << 29);
      v40 = altSchedules[1];
      v6[1] = v38 & 0xFFFFFF80 | v39;
      v6[1] = v6[1] & 0xFFFE007F | ((v40 & 0x3FF) << 7);
      v41 = v6[1];
      v42 = altSchedules[2] & 0x3FF;
      *v6 = *v6;
      *v6 = *v6;
      v6[1] = v41 & 0xF801FFFF | (v42 << 17);
      v6 += 4;
      if ( --v55 == 0 )
      {
        v4 = v48;
        Myfirst = records._Myfirst;
        v5 = v47;
        break;
      }
    }
  }
  printf(format: "Sorting combo schedule records\n");
  std::_Sort<OptimalComboScheduleFileRecord_t *,int>(_First: Myfirst, _Last: records._Mylast, _Ideal: v4);
  printf(format: "Writing output file: %s\n", pFilename);
  pFile = nullptr;
  fopen_s(pfile: &pFile, file: pFilename, mode: "wb");
  if ( pFile == nullptr )
  {
    printf(format: "Failed opening output file: %s\n", pFilename);
    goto LABEL_40;
  }
  hdr.m_nID = -245450332;
  hdr.m_nNumCombos = v4;
  if ( fwrite(buffer: &hdr, size: 8u, count: 1u, stream: pFile) == 1
    && fwrite(buffer: Myfirst, size: v5, count: 1u, stream: pFile) == 1 )
  {
    if ( fclose(stream: pFile) != 0 )
    {
      printf(format: "Failed writing to output file!\n");
LABEL_40:
      if ( Myfirst != nullptr )
        operator delete(p: Myfirst);
      return 0;
    }
    if ( Myfirst != nullptr )
      operator delete(p: Myfirst);
    return 1;
  }
  else
  {
    printf(format: "Failed writing to output file!\n");
    fclose(stream: pFile);
    if ( Myfirst == nullptr )
      return 0;
    operator delete(p: Myfirst);
    return 0;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A00
// Name: protected: struct CompileStats_t __near * std::vector<struct CompileStats_t,class std::allocator<struct CompileStats_t>>::_Umove<struct CompileStats_t __near *>(struct CompileStats_t __near *,struct CompileStats_t __near *,struct CompileStats_t __near *)
// Source: json
//------------------------------------------------------------------------------
CompileStats_t *__thiscall std::vector<CompileStats_t>::_Umove<CompileStats_t *>(
        std::vector<CompileStats_t> *this,
        CompileStats_t *_First,
        CompileStats_t *_Last,
        CompileStats_t *_Ptr)
{
  return std::_Uninit_move<CompileStats_t *,CompileStats_t *,std::allocator<CompileStats_t>,CompileStats_t>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: &this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x00405A30
// Name: void std::_Cons_val<class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>(class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>> __near &,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::string>,std::string,std::string>(
        std::allocator<std::string > *_Alval,
        std::string *_Pdest,
        std::string *_Src)
{
  if ( _Pdest != nullptr )
  {
    _Pdest->_Myres = 15;
    _Pdest->_Mysize = 0;
    _Pdest->_Bx._Buf[0] = 0;
    std::string::assign(this: _Pdest, _Right: _Src);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405A60
// Name: public: void std::vector<struct CompileStats_t,class std::allocator<struct CompileStats_t>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<CompileStats_t>::reserve(std::vector<CompileStats_t> *this, unsigned int _Count)
{
  int v4; // edi
  _DWORD v5[4]; // [esp+0h] [ebp-1Ch] BYREF
  int v6; // [esp+18h] [ebp-4h]
  CompileStats_t *_Ptr; // [esp+24h] [ebp+8h]

  v5[3] = v5;
  if ( _Count > 0x3FFFFFF )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    _Ptr = std::allocator<CompileStats_t>::allocate(this: &this->_Alval, _Count);
    v6 = 0;
    std::vector<CompileStats_t>::_Umove<CompileStats_t *>(this, _First: this->_Myfirst, _Last: this->_Mylast, _Ptr);
    v6 = -1;
    v4 = (char *)this->_Mylast - (char *)this->_Myfirst;
    if ( this->_Myfirst != nullptr )
    {
      std::_Destroy_range<std::allocator<CompileStats_t>>(_First: this->_Myfirst, _Last: this->_Mylast);
      operator delete(p: this->_Myfirst);
    }
    this->_Myend = &_Ptr[_Count];
    this->_Mylast = (CompileStats_t *)((char *)_Ptr + (v4 & 0xFFFFFFC0));
    this->_Myfirst = _Ptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405B30
// Name: protected: void std::vector<struct CompileStats_t,class std::allocator<struct CompileStats_t>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<CompileStats_t>::_Reserve(std::vector<CompileStats_t> *this, unsigned int _Count)
{
  unsigned int v2; // eax
  unsigned int v3; // eax
  unsigned int v4; // edx
  unsigned int v5; // edx

  v2 = this->_Mylast - this->_Myfirst;
  if ( 0x3FFFFFF - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 0x3FFFFFF - (v4 >> 1) >= v4 )
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
    std::vector<CompileStats_t>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405BA0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>> std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > _Last)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v7; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > v9; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *i; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > v14; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Erase(
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
      std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::erase(
        this,
        result: &v14,
        _Where: v9);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405C60
// Name: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near * std::_Uninit_move<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>> __near &,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,struct std::_Nonscalar_ptr_iterator_tag)
// Source: json
//------------------------------------------------------------------------------
std::string *__cdecl std::_Uninit_move<std::string *,std::string *,std::allocator<std::string>,std::string>(
        std::string *_First,
        std::string *_Last,
        std::string *_Dest,
        std::allocator<std::string > *_Al)
{
  std::string *v4; // edi
  int v7; // [esp+0h] [ebp-20h] BYREF
  std::string *_Next; // [esp+Ch] [ebp-14h]
  int *v9; // [esp+10h] [ebp-10h]
  int v10; // [esp+1Ch] [ebp-4h]

  v9 = &v7;
  v4 = _Dest;
  _Next = _Dest;
  v10 = 0;
  while ( _First != _Last )
    std::_Cons_val<std::allocator<std::string>,std::string,std::string>(_Alval: _Al, _Pdest: v4++, _Src: _First++);
  return v4;
}

//------------------------------------------------------------------------------
// Address: 0x00405D00
// Name: public: std::_Pair_base<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>::_Pair_base<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near &&,struct PerShaderStats_t __near &&)
// Source: json
//------------------------------------------------------------------------------
std::_Pair_base<std::string const ,PerShaderStats_t> *__thiscall std::_Pair_base<std::string const,PerShaderStats_t>::_Pair_base<std::string const,PerShaderStats_t>(
        std::_Pair_base<std::string const ,PerShaderStats_t> *this,
        std::string *_Val1,
        PerShaderStats_t *_Val2)
{
  this->first._Myres = 15;
  this->first._Mysize = 0;
  this->first._Bx._Buf[0] = 0;
  std::string::assign(this: &this->first, _Right: _Val1);
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>(
    this: &this->second.m_SchedulerHist,
    _Right: &_Val2->m_SchedulerHist);
  std::vector<SchedulerUsage_t>::vector<SchedulerUsage_t>(
    this: &this->second.m_SortedSchedulerUsage,
    _Right: &_Val2->m_SortedSchedulerUsage);
  this->second.m_flTotalOrigCycles = _Val2->m_flTotalOrigCycles;
  this->second.m_flMinOrigCycles = _Val2->m_flMinOrigCycles;
  this->second.m_flMaxOrigCycles = _Val2->m_flMaxOrigCycles;
  this->second.m_flTotalOrigRegs = _Val2->m_flTotalOrigRegs;
  this->second.m_flTotalOptCycles = _Val2->m_flTotalOptCycles;
  this->second.m_flMinOptCycles = _Val2->m_flMinOptCycles;
  this->second.m_flMaxOptCycles = _Val2->m_flMaxOptCycles;
  this->second.m_flTotalOptRegs = _Val2->m_flTotalOptRegs;
  this->second.m_nTotalCombos = _Val2->m_nTotalCombos;
  return this;
}

//------------------------------------------------------------------------------
// Address: 0x00405D80
// Name: public: void std::vector<struct CompileStats_t,class std::allocator<struct CompileStats_t>>::push_back(struct CompileStats_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<CompileStats_t>::push_back(std::vector<CompileStats_t> *this, const CompileStats_t *_Val)
{
  CompileStats_t *Mylast; // eax
  int v4; // edi
  CompileStats_t *v5; // ecx
  CompileStats_t *v6; // ecx

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<CompileStats_t>::_Reserve(this, _Count: 1u);
    v6 = this->_Mylast;
    if ( v6 != nullptr )
      CompileStats_t::CompileStats_t(this: v6, __that: _Val);
  }
  else
  {
    v4 = (char *)_Val - (char *)this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<CompileStats_t>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      CompileStats_t::CompileStats_t(
        this: v5,
        __that: (const CompileStats_t *)((char *)this->_Myfirst + (v4 & 0xFFFFFFC0)));
      ++this->_Mylast;
      return;
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x00405DF0
// Name: void std::_Cons_val<class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats>>(class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>> __near &,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats> __near *,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats> __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::pair<std::string const,CMachineStats>>,std::pair<std::string const,CMachineStats>,std::pair<std::string,CMachineStats>>(
        std::allocator<std::pair<std::string const ,CMachineStats> > *_Alval,
        std::pair<std::string const ,CMachineStats> *_Pdest,
        std::pair<std::string,CMachineStats> *_Src)
{
  if ( _Pdest != nullptr )
  {
    _Pdest->first._Myres = 15;
    _Pdest->first._Mysize = 0;
    _Pdest->first._Bx._Buf[0] = 0;
    std::string::assign(this: &_Pdest->first, _Right: &_Src->first);
    _Pdest->second = _Src->second;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00405E30
// Name: protected: class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near * std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>::_Umove<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *>(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *,class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> __near *)
// Source: json
//------------------------------------------------------------------------------
std::string *__thiscall std::vector<std::string>::_Umove<std::string *>(
        std::vector<std::string> *this,
        std::string *_First,
        std::string *_Last,
        std::string *_Ptr)
{
  return std::_Uninit_move<std::string *,std::string *,std::allocator<std::string>,std::string>(
           _First,
           _Last,
           _Dest: _Ptr,
           _Al: &this->_Alval);
}

//------------------------------------------------------------------------------
// Address: 0x00405E60
// Name: public: struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,class CMachineStats>>,0>>::_Buynode<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats>>(struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class CMachineStats> __near &&)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *__thiscall std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Buynode<std::pair<std::string,CMachineStats>>(
        std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > *this,
        std::pair<std::string,CMachineStats> *_Val)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *p; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node **)operator new(size: 0x34u);
  p = v3;
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
  *((_WORD *)v3 + 24) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<std::pair<std::string const,CMachineStats>>,std::pair<std::string const,CMachineStats>,std::pair<std::string,CMachineStats>>(
    _Alval: &this->_Alval,
    _Pdest: (std::pair<std::string const ,CMachineStats> *)(v3 + 3),
    _Src: _Val);
  v9 = -1;
  return (std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x00405F20
// Name: public: void std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>::reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<std::string>::reserve(std::vector<std::string> *this, unsigned int _Count)
{
  int v3; // edi
  std::string *v4; // eax
  int v5; // [esp+0h] [ebp-20h] BYREF
  std::string *_Ptr; // [esp+Ch] [ebp-14h]
  int *v7; // [esp+10h] [ebp-10h]
  int v8; // [esp+1Ch] [ebp-4h]

  v7 = &v5;
  if ( _Count > 0x9249249 )
    std::_Xlength_error(_Message: "vector<T> too long");
  if ( this->_Myend - this->_Myfirst < _Count )
  {
    _Ptr = std::allocator<std::string>::allocate(this: &this->_Alval, _Count);
    v8 = 0;
    std::vector<std::string>::_Umove<std::string *>(this, _First: this->_Myfirst, _Last: this->_Mylast, _Ptr);
    v8 = -1;
    v3 = this->_Mylast - this->_Myfirst;
    if ( this->_Myfirst != nullptr )
    {
      std::_Destroy_range<std::allocator<std::string>>(_First: this->_Myfirst, _Last: this->_Mylast);
      operator delete(p: (void *)this->_Myfirst);
    }
    v4 = _Ptr;
    this->_Myend = &_Ptr[_Count];
    this->_Mylast = &v4[v3];
    this->_Myfirst = v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406030
// Name: protected: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>> std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Insert(bool,struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near *,struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Insert(
        std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *result,
        bool _Addleft,
        std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Wherenode,
        std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Newnode)
{
  unsigned int Mysize; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v7; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v9; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v10; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v11; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Parent; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v13; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v15; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v16; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v17; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v18; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Left; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v20; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v21; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v22; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v23; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v24; // edx

  Mysize = this->_Mysize;
  if ( Mysize >= 0x1E1E1E0 )
  {
    std::_Pair_base<std::string const,PerShaderStats_t>::~_Pair_base<std::string const,PerShaderStats_t>(this: &_Newnode->_Myval);
    operator delete(p: _Newnode);
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
LABEL_9:
    v9->_Right = _Newnode;
    goto LABEL_10;
  }
  if ( !_Addleft )
  {
    _Wherenode->_Right = _Newnode;
    v9 = this->_Myhead;
    if ( _Wherenode != v9->_Right )
      goto LABEL_10;
    goto LABEL_9;
  }
  _Wherenode->_Left = _Newnode;
  v10 = this->_Myhead;
  if ( _Wherenode == v10->_Left )
    v10->_Left = _Newnode;
LABEL_10:
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
LABEL_42:
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
          std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Rrotate(
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
        goto LABEL_42;
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
// Address: 0x00406240
// Name: void std::_Cons_val<class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t>>(class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>> __near &,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t> __near *,struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t> __near &&)
// Source: json
//------------------------------------------------------------------------------
void __cdecl std::_Cons_val<std::allocator<std::pair<std::string const,PerShaderStats_t>>,std::pair<std::string const,PerShaderStats_t>,std::pair<std::string,PerShaderStats_t>>(
        std::allocator<std::pair<std::string const ,PerShaderStats_t> > *_Alval,
        std::pair<std::string const ,PerShaderStats_t> *_Pdest,
        std::pair<std::string,PerShaderStats_t> *_Src)
{
  if ( _Pdest != nullptr )
    std::_Pair_base<std::string const,PerShaderStats_t>::_Pair_base<std::string const,PerShaderStats_t>(
      this: _Pdest,
      _Val1: &_Src->first,
      _Val2: &_Src->second);
}

//------------------------------------------------------------------------------
// Address: 0x00406260
// Name: LoadLogFiles
// Source: json
//------------------------------------------------------------------------------
char __cdecl LoadLogFiles(
        const std::vector<std::string> *inputFiles,
        std::vector<CompileStats_t> *compileStats,
        bool bPrintDetailedStats)
{
  const std::vector<std::string> *v3; // esi
  std::vector<CompileStats_t> *v4; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v5; // eax
  int v6; // eax
  std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *v7; // eax
  char *v8; // eax
  const char *v9; // edi
  _BYTE *v10; // eax
  _BYTE *v11; // eax
  signed int v12; // kr00_4
  bool v13; // dl
  signed int i; // ecx
  char v15; // al
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v16; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Ptr; // esi
  std::pair<int const ,int> *v18; // eax
  bool v19; // cf
  int v20; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Myhead; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Left; // esi
  unsigned int m_nGoodResults; // eax
  const char *Buf; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *k; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v29; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v30; // esi
  const char *v31; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *v32; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *ii; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *m; // eax
  char szBuf[2048]; // [esp+14h] [ebp-AF4h] BYREF
  char szName[260]; // [esp+814h] [ebp-2F4h] BYREF
  char szMachineName[256]; // [esp+918h] [ebp-1F0h] BYREF
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > >,bool> insertResult; // [esp+A18h] [ebp-F0h] BYREF
  std::pair<std::string,CMachineStats> dst; // [esp+A20h] [ebp-E8h] BYREF
  unsigned int shaderSchedulerSourcesHist[4]; // [esp+A44h] [ebp-C4h] BYREF
  CompileStats_t stats; // [esp+A54h] [ebp-B4h] BYREF
  std::string v42; // [esp+A94h] [ebp-74h] BYREF
  std::exception pExceptionObject; // [esp+AB0h] [ebp-58h] BYREF
  int nDbgStatusIndex; // [esp+ABCh] [ebp-4Ch]
  unsigned int nInputFileIndex; // [esp+AC0h] [ebp-48h]
  std::set<unsigned __int64> encounteredCombos; // [esp+AC4h] [ebp-44h] BYREF
  unsigned int nNumDuplicates; // [esp+AD4h] [ebp-34h]
  int nShaderSourceIndex; // [esp+AD8h] [ebp-30h]
  unsigned int nNumInvalid; // [esp+ADCh] [ebp-2Ch]
  unsigned int nNumNonDuplicates; // [esp+AE0h] [ebp-28h]
  std::map<std::string,CMachineStats> machineStats; // [esp+AE4h] [ebp-24h] BYREF
  std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > > v52; // [esp+AF4h] [ebp-14h] BYREF
  _iobuf *pInputFile; // [esp+AF8h] [ebp-10h] BYREF
  unsigned int nTotalGoodResults; // [esp+AFCh] [ebp-Ch]
  int n; // [esp+B00h] [ebp-8h] BYREF
  bool bPrintedWarningHeader; // [esp+B07h] [ebp-1h]

  v3 = inputFiles;
  v4 = compileStats;
  std::vector<CompileStats_t>::reserve(this: compileStats, _Count: 0x7A120u);
  memset(shaderSchedulerSourcesHist, 0, sizeof(shaderSchedulerSourcesHist));
  machineStats._Mysize = 0;
  v5 = (std::_Tree_nod<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> >::_Node *)operator new(size: 0x34u);
  if ( v5 == nullptr )
  {
    *(float *)&n = 0.0;
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&n);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  machineStats._Myhead = v5;
  v5->_Left = v5;
  machineStats._Myhead->_Parent = machineStats._Myhead;
  machineStats._Myhead->_Right = machineStats._Myhead;
  machineStats._Myhead->_Color = 1;
  machineStats._Myhead->_Isnil = 1;
  v6 = inputFiles->_Mylast - inputFiles->_Myfirst;
  nInputFileIndex = 0;
  if ( v6 != 0 )
  {
    nTotalGoodResults = 0;
    while ( 1 )
    {
      encounteredCombos._Mysize = 0;
      v7 = (std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *)operator new(size: 0x20u);
      if ( v7 == nullptr )
      {
        *(float *)&n = 0.0;
        std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&n);
        pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
        _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
      }
      encounteredCombos._Myhead = v7;
      v7->_Left = v7;
      encounteredCombos._Myhead->_Parent = encounteredCombos._Myhead;
      encounteredCombos._Myhead->_Right = encounteredCombos._Myhead;
      encounteredCombos._Myhead->_Color = 1;
      encounteredCombos._Myhead->_Isnil = 1;
      v8 = &v3->_Myfirst->_Bx._Buf[nTotalGoodResults];
      v9 = *((_DWORD *)v8 + 5) < 0x10u ? (char *)v3->_Myfirst + nTotalGoodResults : *(const char **)v8;
      pInputFile = nullptr;
      fopen_s(pfile: &pInputFile, file: v9, mode: "r");
      if ( pInputFile == nullptr )
        break;
      printf(format: "Processing log file: %s\n", v9);
      nNumNonDuplicates = 0;
      nNumDuplicates = 0;
      nNumInvalid = 0;
      while ( feof(stream: pInputFile) == 0 )
      {
        if ( fgets(string: szBuf, count: 2048, str: pInputFile) == nullptr )
          break;
        strchr(string: (unsigned __int8 *)szBuf, chr: 0xAu);
        if ( v10 != nullptr )
          *v10 = 0;
        strchr(string: (unsigned __int8 *)szBuf, chr: 0xDu);
        if ( v11 != nullptr )
          *v11 = 0;
        if ( szBuf[0] == 59 || szBuf[0] == 42 || szBuf[0] == 0 )
          goto LABEL_47;
        v12 = strlen(szBuf);
        v13 = false;
        for ( i = 0; i < v12; ++i )
        {
          v15 = szBuf[i];
          if ( v15 == 34 )
          {
            v13 = !v13;
          }
          else if ( !v13 && v15 == 44 )
          {
            szBuf[i] = 32;
          }
        }
        memset(&stats, 0, 17);
        stats.m_Filename._Myres = 15;
        stats.m_Filename._Mysize = 0;
        *(_DWORD *)&stats.m_nOrigCycles = 0;
        *(_DWORD *)&stats.m_nOptCycles = 0;
        stats.m_nOptSchedule = -1;
        stats.m_nOptSeed = 0;
        memset(szName, 0, 258);
        strcpy(szMachineName, "?");
        memset(dst: (unsigned __int8 *)&szMachineName[2], value: 0, count: 0xFEu);
        nShaderSourceIndex = 0;
        nDbgStatusIndex = 0;
        *(float *)&n = COERCE_FLOAT(
                         sscanf_s(
                           string: szBuf,
                           format: "%s %I64x %258s %I64x %hi %hi %hi %hi %i %i %i %i",
                           szMachineName,
                           256,
                           &stats,
                           szName,
                           258,
                           &stats.m_nComboHash,
                           &stats.m_nOrigCycles,
                           &stats.m_nOrigRegs,
                           &stats.m_nOptCycles,
                           &stats.m_nOptRegs,
                           &stats.m_nOptSchedule,
                           &stats.m_nOptSeed));
        v42._Myres = 15;
        v42._Mysize = 0;
        v42._Bx._Buf[0] = 0;
        std::string::assign(this: &v42, _Ptr: szMachineName, _Count: strlen(szMachineName));
        dst.first._Myres = 15;
        dst.first._Mysize = 0;
        dst.first._Bx._Buf[0] = 0;
        if ( v42._Myres >= 0x10 )
        {
          dst.first._Bx._Ptr = v42._Bx._Ptr;
          v42._Bx._Ptr = nullptr;
        }
        else
        {
          memmove((unsigned __int8 *)&dst, src: (unsigned __int8 *)&v42, count: v42._Mysize + 1);
        }
        dst.first._Myres = v42._Myres;
        dst.first._Mysize = v42._Mysize;
        v42._Myres = 15;
        v42._Mysize = 0;
        v42._Bx._Buf[0] = 0;
        dst.second.m_nGoodResults = 0;
        dst.second.m_nInvalidResults = 0;
        v16 = std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Buynode<std::pair<std::string,CMachineStats>>(
                this: &machineStats,
                _Val: &dst);
        std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::_Linsert(
          this: &machineStats,
          result: &insertResult,
          _Node: v16,
          _Leftish: 0);
        if ( dst.first._Myres >= 0x10 )
          operator delete(p: dst.first._Bx._Ptr);
        dst.first._Myres = 15;
        dst.first._Mysize = 0;
        dst.first._Bx._Buf[0] = 0;
        if ( v42._Myres >= 0x10 )
          operator delete(p: v42._Bx._Ptr);
        Ptr = insertResult.first._Ptr;
        if ( n == 12 )
        {
          if ( stats.m_nOrigCycles != 0 && stats.m_nOptCycles != 0 && nDbgStatusIndex >= 0 )
          {
            ++insertResult.first._Ptr->_Myval.second.m_nGoodResults;
            v18 = std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Buynode<unsigned __int64 &>(
                    this: &encounteredCombos,
                    _Val: &stats.m_nComboHash);
            std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::_Linsert(
              this: &encounteredCombos,
              result: (std::pair<std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >,bool> *)&pExceptionObject._Mywhat,
              _Node: (std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *)v18,
              _Leftish: 0);
            if ( pExceptionObject._Mydofree )
            {
              if ( (unsigned int)nShaderSourceIndex <= 3 )
                ++shaderSchedulerSourcesHist[nShaderSourceIndex];
              std::string::assign(this: &stats.m_Filename, _Ptr: szName, _Count: strlen(szName));
              stats.m_nSchedulerParamSource = nShaderSourceIndex;
              std::vector<CompileStats_t>::push_back(this: compileStats, _Val: &stats);
              ++nNumNonDuplicates;
              if ( stats.m_Filename._Myres < 0x10 )
                goto LABEL_47;
LABEL_46:
              operator delete(p: stats.m_Filename._Bx._Ptr);
              goto LABEL_47;
            }
            ++nNumDuplicates;
            v19 = stats.m_Filename._Myres < 0x10;
            goto LABEL_45;
          }
          printf(
            format: "Note: Bad statistics for shader %s combo ID 0x%016I64X from machine \"%s\" (DbgStatus: %i)\n",
            szName,
            stats.m_nComboHash,
            szMachineName,
            nDbgStatusIndex);
          ++Ptr->_Myval.second.m_nInvalidResults;
          ++nNumInvalid;
        }
        else
        {
          ++insertResult.first._Ptr->_Myval.second.m_nInvalidResults;
          printf(format: "Failed parsing line: %s (machine: %s)\n", szBuf, szMachineName);
        }
        v19 = stats.m_Filename._Myres < 0x10;
LABEL_45:
        if ( !v19 )
          goto LABEL_46;
LABEL_47:
        v3 = inputFiles;
      }
      fclose(stream: pInputFile);
      printf(
        format: "Unique shader combos: %u, Duplicates: %u, Invalid: %u\n",
        nNumNonDuplicates,
        nNumDuplicates,
        nNumInvalid);
      std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::erase(
        this: &encounteredCombos,
        result: &v52,
        _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >)encounteredCombos._Myhead->_Left,
        _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >)encounteredCombos._Myhead);
      operator delete(p: encounteredCombos._Myhead);
      v20 = (char *)v3->_Mylast - (char *)v3->_Myfirst;
      nTotalGoodResults += 28;
      if ( ++nInputFileIndex >= v20 / 28 )
      {
        v4 = compileStats;
        goto LABEL_50;
      }
    }
    printf(format: "Failed opening input file: %s\n", v9);
    std::_Tree<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0>>::erase(
      this: &encounteredCombos,
      result: &v52,
      _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >)encounteredCombos._Myhead->_Left,
      _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> > >)encounteredCombos._Myhead);
    operator delete(p: encounteredCombos._Myhead);
    std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::erase(
      this: &machineStats,
      result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *)&v52,
      _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > >)machineStats._Myhead->_Left,
      _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > >)machineStats._Myhead);
    operator delete(p: machineStats._Myhead);
    return 0;
  }
  else
  {
LABEL_50:
    printf(format: "Loaded statistics for %u shader combos\n", v4->_Mylast - v4->_Myfirst);
    printf(format: "Shader scheduler parameter source histogram:\n");
    printf(
      format: "  Total shaders using the compiler's default/unoptimized scheduler settings: %u\n",
      shaderSchedulerSourcesHist[0]);
    printf(
      format: "  Total shaders that didn't use the optimized settings in the ps3optimalschedules.bin file, and instead fell back "
      "to default settings: %u\n",
      shaderSchedulerSourcesHist[1]);
    printf(
      format: "  Total shaders using optimized settings from the ps3optimalschedules.bin file: %u\n",
      shaderSchedulerSourcesHist[3]);
    printf(
      format: "  Total shaders using optimized settings determined through brute force searching: %u\n",
      shaderSchedulerSourcesHist[2]);
    Myhead = machineStats._Myhead;
    Left = machineStats._Myhead->_Left;
    bPrintedWarningHeader = false;
    nTotalGoodResults = 0;
    if ( Left != machineStats._Myhead )
    {
      do
      {
        m_nGoodResults = Left->_Myval.second.m_nGoodResults;
        nTotalGoodResults += m_nGoodResults;
        Buf = Left->_Myval.first._Bx._Buf;
        if ( m_nGoodResults == 0 )
        {
          if ( !bPrintedWarningHeader )
          {
            bPrintedWarningHeader = true;
            printf(format: "------------------------------------------------------------\n");
          }
          if ( Left->_Myval.first._Myres >= 0x10 )
            Buf = *(const char **)Buf;
          printf(
            format: "WARNING: VMPI Machine \"%s\" returned %u all-invalid/bad results!\n",
            Buf,
            Left->_Myval.second.m_nInvalidResults);
          Myhead = machineStats._Myhead;
        }
        if ( Left->_Isnil == 0 )
        {
          Right = Left->_Right;
          if ( Right->_Isnil != 0 )
          {
            for ( j = Left->_Parent; j->_Isnil == 0; j = j->_Parent )
            {
              if ( Left != j->_Right )
                break;
              Left = j;
            }
            Left = j;
          }
          else
          {
            Left = Left->_Right;
            for ( k = Right->_Left; k->_Isnil == 0; k = k->_Left )
              Left = k;
          }
        }
      }
      while ( Left != Myhead );
      if ( bPrintedWarningHeader )
        printf(format: "------------------------------------------------------------\n");
    }
    printf(format: "Total Unique VMPI Machines returning statistics: %u\n", machineStats._Mysize);
    v29 = machineStats._Myhead;
    if ( bPrintDetailedStats )
    {
      v30 = machineStats._Myhead->_Left;
      if ( machineStats._Myhead->_Left != machineStats._Myhead )
      {
        *(float *)&n = (float)nTotalGoodResults;
        do
        {
          if ( v30->_Myval.first._Myres < 0x10 )
            v31 = v30->_Myval.first._Bx._Buf;
          else
            v31 = v30->_Myval.first._Bx._Ptr;
          v52._Ptr = (std::_Tree_nod<std::_Tset_traits<unsigned __int64,std::less<unsigned __int64>,std::allocator<unsigned __int64>,0> >::_Node *)v30->_Myval.second.m_nGoodResults;
          printf(
            format: "VMPI Machine: %s, Combos: %u (%3.1f%%)\n",
            v31,
            v52._Ptr,
            (double)(unsigned int)v52._Ptr * 100.0 / *(float *)&n);
          if ( v30->_Isnil == 0 )
          {
            v32 = v30->_Right;
            if ( v32->_Isnil != 0 )
            {
              for ( m = v30->_Parent; m->_Isnil == 0; m = m->_Parent )
              {
                if ( v30 != m->_Right )
                  break;
                v30 = m;
              }
              v30 = m;
            }
            else
            {
              v30 = v30->_Right;
              for ( ii = v32->_Left; ii->_Isnil == 0; ii = ii->_Left )
                v30 = ii;
            }
          }
          v29 = machineStats._Myhead;
        }
        while ( v30 != machineStats._Myhead );
      }
    }
    std::_Tree<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string>,std::allocator<std::pair<std::string const,CMachineStats>>,0>>::erase(
      this: &machineStats,
      result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > > *)&v52,
      _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > >)v29->_Left,
      _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,CMachineStats,std::less<std::string >,std::allocator<std::pair<std::string const ,CMachineStats> >,0> > >)v29);
    operator delete(p: machineStats._Myhead);
    return 1;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406AA0
// Name: protected: void std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>::_Reserve(unsigned int)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<std::string>::_Reserve(std::vector<std::string> *this, unsigned int _Count)
{
  unsigned int v2; // esi
  unsigned int v3; // esi
  unsigned int v4; // eax
  unsigned int v5; // eax

  v2 = this->_Mylast - this->_Myfirst;
  if ( 153391689 - _Count < v2 )
    std::_Xlength_error(_Message: "vector<T> too long");
  v3 = _Count + v2;
  v4 = this->_Myend - this->_Myfirst;
  if ( v3 > v4 )
  {
    if ( 153391689 - (v4 >> 1) >= v4 )
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
    std::vector<std::string>::reserve(this, _Count: v5);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406B30
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>> std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > _Where)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Ptr; // ebx
  bool v4; // zf
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Right; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v6; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Parent; // esi
  std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *v8; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v10; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v11; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v12; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v13; // ecx
  char Color; // cl
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Left; // eax
  unsigned int Mysize; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > v18; // [esp+8h] [ebp-8h] BYREF
  std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *v19; // [esp+Ch] [ebp-4h]

  Ptr = _Where._Ptr;
  v4 = _Where._Ptr->_Isnil == 0;
  v19 = this;
  if ( !v4 )
    std::_Xout_of_range(_Message: "invalid map/set<T> iterator");
  std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>,std::_Iterator_base0>::operator++(this: &_Where);
  if ( Ptr->_Left->_Isnil != 0 )
  {
    Right = Ptr->_Right;
LABEL_8:
    Parent = Ptr->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    v8 = v19;
    Myhead = v19->_Myhead;
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
    if ( v8->_Myhead->_Left == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v10 = Parent;
      }
      else
      {
        v10 = std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Min(_Pnode: Right);
        v8 = v19;
      }
      v8->_Myhead->_Left = v10;
    }
    if ( v8->_Myhead->_Right == Ptr )
    {
      if ( Right->_Isnil != 0 )
      {
        v8->_Myhead->_Right = Parent;
      }
      else
      {
        v11 = std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Max(_Pnode: Right);
        v8 = v19;
        v19->_Myhead->_Right = v11;
      }
    }
    goto LABEL_35;
  }
  if ( Ptr->_Right->_Isnil != 0 )
  {
    Right = Ptr->_Left;
    goto LABEL_8;
  }
  v6 = _Where._Ptr;
  Right = _Where._Ptr->_Right;
  if ( _Where._Ptr == Ptr )
    goto LABEL_8;
  Ptr->_Left->_Parent = _Where._Ptr;
  v6->_Left = Ptr->_Left;
  if ( v6 == Ptr->_Right )
  {
    Parent = v6;
  }
  else
  {
    Parent = v6->_Parent;
    if ( Right->_Isnil == 0 )
      Right->_Parent = Parent;
    Parent->_Left = Right;
    v6->_Right = Ptr->_Right;
    Ptr->_Right->_Parent = v6;
  }
  v12 = v19->_Myhead;
  if ( v12->_Parent == Ptr )
  {
    v12->_Parent = v6;
  }
  else
  {
    v13 = Ptr->_Parent;
    if ( v13->_Left == Ptr )
      v13->_Left = v6;
    else
      v13->_Right = v6;
  }
  v6->_Parent = Ptr->_Parent;
  Color = v6->_Color;
  v6->_Color = Ptr->_Color;
  Ptr->_Color = Color;
  v8 = v19;
LABEL_35:
  if ( Ptr->_Color == 1 )
  {
    for ( ; Right != v8->_Myhead->_Parent; Parent = Parent->_Parent )
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
          std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Lrotate(
            this: v8,
            _Wherenode: Parent);
          Left = Parent->_Right;
          v8 = v19;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Left->_Color != 1 || Left->_Right->_Color != 1 )
        {
          if ( Left->_Right->_Color == 1 )
          {
            Left->_Left->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Rrotate(
              this: v8,
              _Wherenode: Left);
            Left = Parent->_Right;
            v8 = v19;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Right->_Color = 1;
          std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Lrotate(
            this: v8,
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
          std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Rrotate(
            this: v8,
            _Wherenode: Parent);
          Left = Parent->_Left;
          v8 = v19;
        }
        if ( Left->_Isnil != 0 )
          goto LABEL_53;
        if ( Left->_Right->_Color != 1 || Left->_Left->_Color != 1 )
        {
          if ( Left->_Left->_Color == 1 )
          {
            Left->_Right->_Color = 1;
            Left->_Color = 0;
            std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Lrotate(
              this: v8,
              _Wherenode: Left);
            Left = Parent->_Left;
            v8 = v19;
          }
          Left->_Color = Parent->_Color;
          Parent->_Color = 1;
          Left->_Left->_Color = 1;
          std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Rrotate(
            this: v8,
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
  if ( Ptr->_Myval.second.m_SortedSchedulerUsage._Myfirst != nullptr )
    operator delete(p: Ptr->_Myval.second.m_SortedSchedulerUsage._Myfirst);
  Ptr->_Myval.second.m_SortedSchedulerUsage._Myfirst = nullptr;
  Ptr->_Myval.second.m_SortedSchedulerUsage._Mylast = nullptr;
  Ptr->_Myval.second.m_SortedSchedulerUsage._Myend = nullptr;
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
    this: &Ptr->_Myval.second.m_SchedulerHist,
    result: &v18,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)Ptr->_Myval.second.m_SchedulerHist._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)Ptr->_Myval.second.m_SchedulerHist._Myhead);
  operator delete(p: Ptr->_Myval.second.m_SchedulerHist._Myhead);
  if ( Ptr->_Myval.first._Myres >= 0x10 )
    operator delete(p: Ptr->_Myval.first._Bx._Ptr);
  Ptr->_Myval.first._Myres = 15;
  Ptr->_Myval.first._Mysize = 0;
  Ptr->_Myval.first._Bx._Buf[0] = 0;
  operator delete(p: Ptr);
  Mysize = v19->_Mysize;
  if ( Mysize != 0 )
    v19->_Mysize = Mysize - 1;
  result->_Ptr = _Where._Ptr;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x00406E80
// Name: protected: void std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Erase(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Erase(
        std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Rootnode)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v2; // edi
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *i; // ebx

  v2 = _Rootnode;
  for ( i = _Rootnode; i->_Isnil == 0; v2 = i )
  {
    std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Erase(
      this,
      _Rootnode: i->_Right);
    i = i->_Left;
    if ( v2->_Myval.second.m_SortedSchedulerUsage._Myfirst != nullptr )
      operator delete(p: v2->_Myval.second.m_SortedSchedulerUsage._Myfirst);
    v2->_Myval.second.m_SortedSchedulerUsage._Myfirst = nullptr;
    v2->_Myval.second.m_SortedSchedulerUsage._Mylast = nullptr;
    v2->_Myval.second.m_SortedSchedulerUsage._Myend = nullptr;
    std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
      this: &v2->_Myval.second.m_SchedulerHist,
      result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *)&_Rootnode,
      _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)v2->_Myval.second.m_SchedulerHist._Myhead->_Left,
      _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)v2->_Myval.second.m_SchedulerHist._Myhead);
    operator delete(p: v2->_Myval.second.m_SchedulerHist._Myhead);
    if ( v2->_Myval.first._Myres >= 0x10 )
      operator delete(p: v2->_Myval.first._Bx._Ptr);
    v2->_Myval.first._Myres = 15;
    v2->_Myval.first._Mysize = 0;
    v2->_Myval.first._Bx._Buf[0] = 0;
    operator delete(p: v2);
  }
}

//------------------------------------------------------------------------------
// Address: 0x00406F30
// Name: public: struct std::pair<class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>>,bool> std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Linsert(struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near *,bool)
// Source: json
//------------------------------------------------------------------------------
std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > >,bool> *__thiscall std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Linsert(
        std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > >,bool> *result,
        std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Node,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > _Leftish)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v4; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Parent; // ebx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Myhead; // edi
  bool v7; // al
  unsigned int Mysize; // ecx
  const char *Buf; // eax
  const char *Ptr; // edx
  unsigned int v11; // esi
  unsigned int v12; // ecx
  int v13; // eax
  bool v14; // sf
  unsigned int v15; // edi
  unsigned int v16; // esi
  unsigned int v17; // edx
  std::pair<std::string const ,PerShaderStats_t> *p_Myval; // ecx
  int v19; // eax
  bool v20; // sf
  int v21; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v22; // esi
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *v23; // eax
  bool v25; // cf
  std::_Pair_base<std::string const ,PerShaderStats_t> *v26; // ebx
  unsigned int v27; // edx
  const char *v28; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *_Wherenode; // [esp+Ch] [ebp-14h]
  std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *v30; // [esp+10h] [ebp-10h]
  unsigned int Myres; // [esp+14h] [ebp-Ch]
  unsigned int v32; // [esp+18h] [ebp-8h]
  bool _Addleft; // [esp+1Ch] [ebp-4h]

  v4 = _Node;
  Parent = this->_Myhead->_Parent;
  Myhead = this->_Myhead;
  v7 = true;
  v30 = this;
  _Addleft = true;
  if ( Parent->_Isnil == 0 )
  {
    Mysize = _Node->_Myval.first._Mysize;
    v32 = Mysize;
    Myres = _Node->_Myval.first._Myres;
    while ( 1 )
    {
      _Wherenode = Parent;
      Buf = Parent->_Myval.first._Bx._Buf;
      if ( LOBYTE(_Leftish._Ptr) != 0 )
      {
        if ( Myres < 0x10 )
          Ptr = v4->_Myval.first._Bx._Buf;
        else
          Ptr = v4->_Myval.first._Bx._Ptr;
        v11 = Parent->_Myval.first._Mysize;
        v12 = v11;
        if ( v11 >= v32 )
          v12 = v32;
        if ( Parent->_Myval.first._Myres >= 0x10 )
          Buf = *(const char **)Buf;
        v13 = std::char_traits<char>::compare(_First1: Buf, _First2: Ptr, _Count: v12);
        v14 = v13 < 0;
        if ( v13 == 0 )
        {
          if ( v11 < v32 )
          {
            v7 = false;
            goto LABEL_32;
          }
          v14 = false;
        }
        v7 = !v14;
      }
      else
      {
        v15 = Parent->_Myval.first._Mysize;
        if ( Parent->_Myval.first._Myres >= 0x10 )
          Buf = *(const char **)Buf;
        v16 = _Node->_Myval.first._Mysize;
        if ( Mysize < v16 )
          v16 = Mysize;
        v17 = v16;
        if ( v16 >= v15 )
          v17 = Parent->_Myval.first._Mysize;
        if ( Myres < 0x10 )
          p_Myval = &_Node->_Myval;
        else
          p_Myval = (std::pair<std::string const ,PerShaderStats_t> *)_Node->_Myval.first._Bx._Ptr;
        v19 = std::char_traits<char>::compare(_First1: p_Myval->first._Bx._Buf, _First2: Buf, _Count: v17);
        v20 = v19 < 0;
        if ( v19 == 0 )
        {
          if ( v16 >= v15 )
            v21 = v16 != v15;
          else
            v21 = -1;
          v20 = v21 < 0;
        }
        v7 = v20;
      }
LABEL_32:
      _Addleft = v7;
      if ( v7 )
        Parent = Parent->_Left;
      else
        Parent = Parent->_Right;
      v4 = _Node;
      if ( Parent->_Isnil != 0 )
      {
        Myhead = _Wherenode;
        this = v30;
        break;
      }
      Mysize = v32;
    }
  }
  v22 = Myhead;
  _Leftish._Ptr = Myhead;
  if ( v7 )
  {
    if ( Myhead == this->_Myhead->_Left )
    {
      v23 = std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Insert(
              this,
              result: &_Leftish,
              _Addleft: true,
              _Wherenode: Myhead,
              _Newnode: v4);
LABEL_40:
      result->first = (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > >)v23->_Ptr;
      result->second = true;
      return result;
    }
    std::_Tree_unchecked_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>,std::_Iterator_base0>::operator--(this: &_Leftish);
    v22 = _Leftish._Ptr;
    v4 = _Node;
  }
  v25 = v4->_Myval.first._Myres < 0x10;
  v26 = &v4->_Myval;
  v27 = v4->_Myval.first._Mysize;
  if ( v25 )
    v28 = (const char *)v26;
  else
    v28 = v26->first._Bx._Ptr;
  if ( std::string::compare(this: &v22->_Myval.first, _Off: 0, _N0: v22->_Myval.first._Mysize, _Ptr: v28, _Count: v27) < 0 )
  {
    v23 = std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Insert(
            this: v30,
            result: &_Leftish,
            _Addleft,
            _Wherenode: Myhead,
            _Newnode: _Node);
    goto LABEL_40;
  }
  std::_Pair_base<std::string const,PerShaderStats_t>::~_Pair_base<std::string const,PerShaderStats_t>(this: v26);
  operator delete(p: _Node);
  result->first._Ptr = v22;
  result->second = false;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x004070F0
// Name: public: struct std::_Tree_nod<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Node __near * std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::_Buynode<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t>>(struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t> __near &&)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *__thiscall std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Buynode<std::pair<std::string,PerShaderStats_t>>(
        std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        std::pair<std::string,PerShaderStats_t> *_Val)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node **v3; // esi
  int v5; // [esp+0h] [ebp-2Ch] BYREF
  std::exception pExceptionObject; // [esp+Ch] [ebp-20h] BYREF
  void *p; // [esp+18h] [ebp-14h]
  int *v8; // [esp+1Ch] [ebp-10h]
  int v9; // [esp+28h] [ebp-4h]

  v8 = &v5;
  v3 = (std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node **)operator new(size: 0xA0u);
  p = v3;
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
  *((_WORD *)v3 + 76) = 0;
  v9 = 0;
  std::_Cons_val<std::allocator<std::pair<std::string const,PerShaderStats_t>>,std::pair<std::string const,PerShaderStats_t>,std::pair<std::string,PerShaderStats_t>>(
    _Alval: &this->_Alval,
    _Pdest: (std::pair<std::string const ,PerShaderStats_t> *)(v3 + 4),
    _Src: _Val);
  v9 = -1;
  return (std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *)v3;
}

//------------------------------------------------------------------------------
// Address: 0x004071B0
// Name: public: void std::vector<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,class std::allocator<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>>::push_back(class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall std::vector<std::string>::push_back(std::vector<std::string> *this, const std::string *_Val)
{
  std::string *Mylast; // ecx
  int v4; // esi
  std::string *v5; // ecx
  const std::string *v6; // [esp-Ch] [ebp-14h]

  Mylast = this->_Mylast;
  if ( _Val >= Mylast || this->_Myfirst > _Val )
  {
    if ( Mylast == this->_Myend )
      std::vector<std::string>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      v6 = _Val;
      goto LABEL_11;
    }
  }
  else
  {
    v4 = _Val - this->_Myfirst;
    if ( Mylast == this->_Myend )
      std::vector<std::string>::_Reserve(this, _Count: 1u);
    v5 = this->_Mylast;
    if ( v5 != nullptr )
    {
      v6 = &this->_Myfirst[v4];
LABEL_11:
      v5->_Myres = 15;
      v5->_Mysize = 0;
      v5->_Bx._Buf[0] = 0;
      std::string::assign(this: v5, _Right: v6, _Roff: 0, _Count: 0xFFFFFFFF);
    }
  }
  ++this->_Mylast;
}

//------------------------------------------------------------------------------
// Address: 0x00407240
// Name: ComputeAndPrintPerShaderStatistics
// Source: json
//------------------------------------------------------------------------------
void __cdecl ComputeAndPrintPerShaderStatistics(
        const std::vector<CompileStats_t> *compileStats,
        std::map<std::string,PerShaderStats_t> *perShaderStatsMap,
        bool bPrintStats)
{
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v3; // eax
  CompileStats_t *Myfirst; // edi
  int v5; // edx
  int v6; // ebx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v7; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Ptr; // esi
  double m_flMinOrigCycles; // xmm1_8
  double m_nOrigCycles; // xmm0_8
  double *p_m_flMinOrigCycles; // ecx
  bool v12; // cc
  double *p_m_flMaxOrigCycles; // ecx
  double m_flMinOptCycles; // xmm1_8
  double m_nOptCycles; // xmm0_8
  double *p_m_flMinOptCycles; // ecx
  double *p_m_flMaxOptCycles; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v18; // eax
  unsigned int v19; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Left; // esi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node **p_Left; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v23; // ebx
  std::vector<SchedulerUsage_t> *p_m_SortedSchedulerUsage; // edi
  int second; // ecx
  SchedulerUsage_t *Mylast; // eax
  SchedulerUsage_t *v27; // edx
  SchedulerUsage_t *v28; // ecx
  int v29; // esi
  unsigned int v30; // eax
  unsigned int v31; // eax
  unsigned int v32; // ecx
  unsigned int v33; // ecx
  SchedulerUsage_t *v34; // eax
  SchedulerUsage_t *v35; // ecx
  int m_nTotalUses; // ecx
  SchedulerUsage_t *Myend; // ecx
  unsigned int v38; // eax
  unsigned int v39; // eax
  unsigned int v40; // ecx
  unsigned int v41; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *Right; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *i; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v45; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *m; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *k; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v48; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v49; // esi
  const char *Buf; // ecx
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v51; // eax
  double v52; // st7
  SchedulerUsage_t *v53; // eax
  unsigned int n; // edi
  std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *v55; // ecx
  int m_nTotalCombos; // edx
  double v57; // st6
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v58; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *jj; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *ii; // eax
  std::pair<std::string,PerShaderStats_t> dst; // [esp+2Ch] [ebp-150h] BYREF
  double v62; // [esp+B4h] [ebp-C8h] BYREF
  double v63; // [esp+BCh] [ebp-C0h] BYREF
  double v64; // [esp+C4h] [ebp-B8h] BYREF
  std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > >,bool> result; // [esp+CCh] [ebp-B0h] BYREF
  double v66; // [esp+D4h] [ebp-A8h] BYREF
  PerShaderStats_t defaultPerShaderStats; // [esp+DCh] [ebp-A0h] BYREF
  std::exception pExceptionObject; // [esp+144h] [ebp-38h] BYREF
  std::string v69; // [esp+150h] [ebp-2Ch] BYREF
  std::pair<int const ,int> _Val; // [esp+16Ch] [ebp-10h] BYREF
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > histIt; // [esp+174h] [ebp-8h] BYREF
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > it; // [esp+178h] [ebp-4h] BYREF

  defaultPerShaderStats.m_SchedulerHist._Mysize = 0;
  v3 = (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)operator new(size: 0x18u);
  it._Ptr = nullptr;
  if ( v3 == nullptr )
  {
    std::exception::exception(this: &pExceptionObject, _What: (const char *const *)&it);
    pExceptionObject.__vftable = (std::exception_vtbl *)&std::bad_alloc::`vftable';
    _CxxThrowException(&pExceptionObject, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  defaultPerShaderStats.m_SchedulerHist._Myhead = v3;
  v3->_Left = v3;
  defaultPerShaderStats.m_SchedulerHist._Myhead->_Parent = defaultPerShaderStats.m_SchedulerHist._Myhead;
  defaultPerShaderStats.m_SchedulerHist._Myhead->_Right = defaultPerShaderStats.m_SchedulerHist._Myhead;
  defaultPerShaderStats.m_SchedulerHist._Myhead->_Color = 1;
  defaultPerShaderStats.m_SchedulerHist._Myhead->_Isnil = 1;
  Myfirst = compileStats->_Myfirst;
  v5 = compileStats->_Mylast - compileStats->_Myfirst;
  memset(&defaultPerShaderStats.m_SortedSchedulerUsage, 0, 12);
  defaultPerShaderStats.m_flTotalOrigCycles = 0.0;
  defaultPerShaderStats.m_flMinOrigCycles = 8999999488.0;
  defaultPerShaderStats.m_flMaxOrigCycles = -8999999488.0;
  memset(&defaultPerShaderStats.m_flTotalOrigRegs, 0, 16);
  defaultPerShaderStats.m_flMinOptCycles = 8999999488.0;
  defaultPerShaderStats.m_flMaxOptCycles = -8999999488.0;
  memset(&defaultPerShaderStats.m_flTotalOptRegs, 0, 12);
  if ( v5 != 0 )
  {
    _Val.second = 0;
    v6 = 0;
    do
    {
      v69._Myres = 15;
      v69._Mysize = 0;
      v69._Bx._Buf[0] = 0;
      std::string::assign(this: &v69, _Right: &Myfirst[v6].m_Filename, _Roff: 0, _Count: 0xFFFFFFFF);
      dst.first._Myres = 15;
      dst.first._Mysize = 0;
      dst.first._Bx._Buf[0] = 0;
      if ( v69._Myres >= 0x10 )
      {
        dst.first._Bx._Ptr = v69._Bx._Ptr;
        v69._Bx._Ptr = nullptr;
      }
      else
      {
        memmove((unsigned __int8 *)&dst, src: (unsigned __int8 *)&v69, count: v69._Mysize + 1);
      }
      dst.first._Mysize = v69._Mysize;
      dst.first._Myres = v69._Myres;
      v69._Myres = 15;
      v69._Mysize = 0;
      v69._Bx._Buf[0] = 0;
      std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>(
        this: &dst.second.m_SchedulerHist,
        _Right: &defaultPerShaderStats.m_SchedulerHist);
      std::vector<SchedulerUsage_t>::vector<SchedulerUsage_t>(
        this: &dst.second.m_SortedSchedulerUsage,
        _Right: &defaultPerShaderStats.m_SortedSchedulerUsage);
      dst.second.m_flTotalOrigCycles = defaultPerShaderStats.m_flTotalOrigCycles;
      dst.second.m_flMinOrigCycles = defaultPerShaderStats.m_flMinOrigCycles;
      dst.second.m_flMaxOrigCycles = defaultPerShaderStats.m_flMaxOrigCycles;
      dst.second.m_flTotalOrigRegs = defaultPerShaderStats.m_flTotalOrigRegs;
      dst.second.m_flTotalOptCycles = defaultPerShaderStats.m_flTotalOptCycles;
      dst.second.m_flMinOptCycles = defaultPerShaderStats.m_flMinOptCycles;
      dst.second.m_flMaxOptCycles = defaultPerShaderStats.m_flMaxOptCycles;
      dst.second.m_flTotalOptRegs = defaultPerShaderStats.m_flTotalOptRegs;
      dst.second.m_nTotalCombos = defaultPerShaderStats.m_nTotalCombos;
      if ( v69._Myres >= 0x10 )
        operator delete(p: v69._Bx._Ptr);
      v69._Myres = 15;
      v69._Mysize = 0;
      v69._Bx._Buf[0] = 0;
      v7 = std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Buynode<std::pair<std::string,PerShaderStats_t>>(
             this: perShaderStatsMap,
             _Val: &dst);
      std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Linsert(
        this: perShaderStatsMap,
        &result,
        _Node: v7,
        _Leftish: 0);
      Ptr = result.first._Ptr;
      if ( dst.second.m_SortedSchedulerUsage._Myfirst != nullptr )
        operator delete(p: dst.second.m_SortedSchedulerUsage._Myfirst);
      memset(&dst.second.m_SortedSchedulerUsage, 0, 12);
      std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
        this: &dst.second.m_SchedulerHist,
        result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *)&histIt,
        _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)dst.second.m_SchedulerHist._Myhead->_Left,
        _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)dst.second.m_SchedulerHist._Myhead);
      operator delete(p: dst.second.m_SchedulerHist._Myhead);
      if ( dst.first._Myres >= 0x10 )
        operator delete(p: dst.first._Bx._Ptr);
      dst.first._Myres = 15;
      dst.first._Mysize = 0;
      dst.first._Bx._Buf[0] = 0;
      ++Ptr->_Myval.second.m_nTotalCombos;
      Ptr->_Myval.second.m_flTotalOrigCycles = (double)Myfirst[v6].m_nOrigCycles
                                             + Ptr->_Myval.second.m_flTotalOrigCycles;
      Ptr->_Myval.second.m_flTotalOrigRegs = (double)Myfirst[v6].m_nOrigRegs + Ptr->_Myval.second.m_flTotalOrigRegs;
      m_flMinOrigCycles = Ptr->_Myval.second.m_flMinOrigCycles;
      m_nOrigCycles = (double)Myfirst[v6].m_nOrigCycles;
      v62 = m_nOrigCycles;
      p_m_flMinOrigCycles = &v62;
      if ( m_flMinOrigCycles <= m_nOrigCycles )
        p_m_flMinOrigCycles = &Ptr->_Myval.second.m_flMinOrigCycles;
      Ptr->_Myval.second.m_flMinOrigCycles = *p_m_flMinOrigCycles;
      v12 = (double)Myfirst[v6].m_nOrigCycles <= Ptr->_Myval.second.m_flMaxOrigCycles;
      v66 = (double)Myfirst[v6].m_nOrigCycles;
      p_m_flMaxOrigCycles = &v66;
      if ( v12 )
        p_m_flMaxOrigCycles = &Ptr->_Myval.second.m_flMaxOrigCycles;
      Ptr->_Myval.second.m_flMaxOrigCycles = *p_m_flMaxOrigCycles;
      Ptr->_Myval.second.m_flTotalOptCycles = (double)Myfirst[v6].m_nOptCycles + Ptr->_Myval.second.m_flTotalOptCycles;
      Ptr->_Myval.second.m_flTotalOptRegs = (double)Myfirst[v6].m_nOptRegs + Ptr->_Myval.second.m_flTotalOptRegs;
      m_flMinOptCycles = Ptr->_Myval.second.m_flMinOptCycles;
      m_nOptCycles = (double)Myfirst[v6].m_nOptCycles;
      v63 = m_nOptCycles;
      p_m_flMinOptCycles = &v63;
      if ( m_flMinOptCycles <= m_nOptCycles )
        p_m_flMinOptCycles = &Ptr->_Myval.second.m_flMinOptCycles;
      Ptr->_Myval.second.m_flMinOptCycles = *p_m_flMinOptCycles;
      v12 = (double)Myfirst[v6].m_nOptCycles <= Ptr->_Myval.second.m_flMaxOptCycles;
      v64 = (double)Myfirst[v6].m_nOptCycles;
      p_m_flMaxOptCycles = &v64;
      if ( v12 )
        p_m_flMaxOptCycles = &Ptr->_Myval.second.m_flMaxOptCycles;
      Ptr->_Myval.second.m_flMaxOptCycles = *p_m_flMaxOptCycles;
      _Val.first = Myfirst[v6].m_nOptSchedule;
      v18 = std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Buynode<std::pair<int const,int> &>(
              this: &Ptr->_Myval.second.m_SchedulerHist,
              &_Val);
      std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::_Linsert(
        this: &Ptr->_Myval.second.m_SchedulerHist,
        result: (std::pair<std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >,bool> *)&pExceptionObject._Mywhat,
        _Node: v18,
        _Leftish: 0);
      ++*((_DWORD *)pExceptionObject._Mywhat + 4);
      Myfirst = compileStats->_Myfirst;
      v19 = compileStats->_Mylast - compileStats->_Myfirst;
      ++v6;
      ++it._Ptr;
    }
    while ( (unsigned int)it._Ptr < v19 );
  }
  Myhead = perShaderStatsMap->_Myhead;
  Left = Myhead->_Left;
  histIt._Ptr = Left;
  if ( Left == Myhead )
    goto LABEL_72;
  do
  {
    p_Left = &Left->_Myval.second.m_SchedulerHist._Myhead->_Left;
    v23 = *p_Left;
    p_m_SortedSchedulerUsage = &Left->_Myval.second.m_SortedSchedulerUsage;
    it._Ptr = v23;
    if ( v23 == (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)p_Left )
      goto LABEL_61;
    do
    {
      second = v23->_Myval.second;
      _Val.first = v23->_Myval.first;
      Mylast = p_m_SortedSchedulerUsage->_Mylast;
      _Val.second = second;
      if ( &_Val >= (std::pair<int const ,int> *)Mylast
        || (v27 = p_m_SortedSchedulerUsage->_Myfirst, p_m_SortedSchedulerUsage->_Myfirst > (SchedulerUsage_t *)&_Val) )
      {
        Myend = p_m_SortedSchedulerUsage->_Myend;
        if ( Mylast == Myend )
        {
          v38 = Mylast - p_m_SortedSchedulerUsage->_Myfirst;
          if ( v38 > 0x1FFFFFFE )
LABEL_85:
            std::_Xlength_error(_Message: "vector<T> too long");
          v39 = v38 + 1;
          v40 = Myend - p_m_SortedSchedulerUsage->_Myfirst;
          if ( v39 > v40 )
          {
            if ( 0x1FFFFFFF - (v40 >> 1) >= v40 )
              v41 = (v40 >> 1) + v40;
            else
              v41 = 0;
            if ( v41 < v39 )
              v41 = v39;
            std::vector<SchedulerUsage_t>::reserve(this: p_m_SortedSchedulerUsage, _Count: v41);
          }
        }
        v34 = p_m_SortedSchedulerUsage->_Mylast;
        if ( v34 != nullptr )
        {
          m_nTotalUses = _Val.second;
          v34->m_nScheduleIndex = _Val.first;
          goto LABEL_48;
        }
      }
      else
      {
        v28 = p_m_SortedSchedulerUsage->_Myend;
        v29 = ((char *)&_Val - (char *)v27) >> 3;
        if ( Mylast == v28 )
        {
          v30 = Mylast - v27;
          if ( v30 > 0x1FFFFFFE )
            goto LABEL_85;
          v31 = v30 + 1;
          v32 = v28 - v27;
          if ( v31 > v32 )
          {
            if ( 0x1FFFFFFF - (v32 >> 1) >= v32 )
              v33 = (v32 >> 1) + v32;
            else
              v33 = 0;
            if ( v33 < v31 )
              v33 = v31;
            std::vector<SchedulerUsage_t>::reserve(this: p_m_SortedSchedulerUsage, _Count: v33);
            v23 = it._Ptr;
          }
        }
        v34 = p_m_SortedSchedulerUsage->_Mylast;
        if ( v34 != nullptr )
        {
          v35 = p_m_SortedSchedulerUsage->_Myfirst;
          v34->m_nScheduleIndex = p_m_SortedSchedulerUsage->_Myfirst[v29].m_nScheduleIndex;
          m_nTotalUses = v35[v29].m_nTotalUses;
LABEL_48:
          v34->m_nTotalUses = m_nTotalUses;
        }
      }
      ++p_m_SortedSchedulerUsage->_Mylast;
      if ( v23->_Isnil == 0 )
      {
        Right = v23->_Right;
        if ( Right->_Isnil != 0 )
        {
          for ( i = v23->_Parent; i->_Isnil == 0; i = i->_Parent )
          {
            if ( v23 != i->_Right )
              break;
            v23 = i;
          }
          v23 = i;
        }
        else
        {
          for ( j = Right->_Left; j->_Isnil == 0; j = j->_Left )
            Right = j;
          v23 = Right;
        }
        it._Ptr = v23;
      }
    }
    while ( v23 != histIt._Ptr->_Myval.second.m_SchedulerHist._Myhead );
    Left = histIt._Ptr;
LABEL_61:
    std::_Sort<SchedulerUsage_t *,int>(
      _First: p_m_SortedSchedulerUsage->_Myfirst,
      _Last: p_m_SortedSchedulerUsage->_Mylast,
      _Ideal: p_m_SortedSchedulerUsage->_Mylast - p_m_SortedSchedulerUsage->_Myfirst);
    if ( Left->_Isnil == 0 )
    {
      v45 = Left->_Right;
      if ( v45->_Isnil != 0 )
      {
        for ( k = Left->_Parent; k->_Isnil == 0; k = k->_Parent )
        {
          if ( Left != k->_Right )
            break;
          Left = k;
        }
        Left = k;
      }
      else
      {
        for ( m = v45->_Left; m->_Isnil == 0; m = m->_Left )
          v45 = m;
        Left = v45;
      }
      histIt._Ptr = Left;
    }
  }
  while ( Left != perShaderStatsMap->_Myhead );
LABEL_72:
  if ( bPrintStats )
  {
    printf(format: "Per shader filename scheduler statistics:\n");
    v48 = perShaderStatsMap->_Myhead;
    v49 = v48->_Left;
    if ( v48->_Left != v48 )
    {
      do
      {
        Buf = v49->_Myval.first._Bx._Buf;
        if ( v49->_Myval.first._Myres >= 0x10 )
          Buf = *(const char **)Buf;
        it._Ptr = (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)v49->_Myval.second.m_nTotalCombos;
        v51 = it._Ptr;
        v52 = (double)(unsigned int)it._Ptr * 100.0;
        it._Ptr = (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)(compileStats->_Mylast - compileStats->_Myfirst);
        printf(
          format: " Shader Filename: %s, Total combos: %u (%3.1f%%)\n",
          Buf,
          v51,
          v52 / (double)(unsigned int)it._Ptr);
        printf(
          format: "  Original  ave. cycles: %3.3f (Range %3.3f-%3.3f), Ave. regs: %3.3f\n",
          1.0 / (double)v49->_Myval.second.m_nTotalCombos * (double)v49->_Myval.second.m_flTotalOrigCycles,
          (double)v49->_Myval.second.m_flMinOrigCycles,
          (double)v49->_Myval.second.m_flMaxOrigCycles,
          (double)v49->_Myval.second.m_flTotalOrigRegs * (1.0 / (double)v49->_Myval.second.m_nTotalCombos));
        printf(
          format: "  Optimized ave. cycles: %3.3f (Range %3.3f-%3.3f), Ave. regs: %3.3f\n",
          1.0 / (double)v49->_Myval.second.m_nTotalCombos * (double)v49->_Myval.second.m_flTotalOptCycles,
          (double)v49->_Myval.second.m_flMinOptCycles,
          (double)v49->_Myval.second.m_flMaxOptCycles,
          (double)v49->_Myval.second.m_flTotalOptRegs * (1.0 / (double)v49->_Myval.second.m_nTotalCombos));
        printf(
          format: "  Average improvement: %3.2f%%\n",
          (1.0 - (double)v49->_Myval.second.m_flTotalOptCycles / (double)v49->_Myval.second.m_flTotalOrigCycles) * 100.0);
        printf(format: "  Scheduler usage:\n");
        v53 = v49->_Myval.second.m_SortedSchedulerUsage._Myfirst;
        for ( n = 0; n < v49->_Myval.second.m_SortedSchedulerUsage._Mylast - v53; ++n )
        {
          v55 = (std::_Tree_nod<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> >::_Node *)v53[n].m_nTotalUses;
          m_nTotalCombos = v49->_Myval.second.m_nTotalCombos;
          it._Ptr = v55;
          v57 = (double)(int)v49->_Myval.second.m_nTotalCombos;
          if ( m_nTotalCombos < 0 )
            v57 = v57 + 4294967300.0;
          printf(
            format: "   Schedule: %i, Uses: %i (%3.1f%%)\n",
            v53[n].m_nScheduleIndex,
            v55,
            (double)(int)it._Ptr * 100.0 / v57);
          v53 = v49->_Myval.second.m_SortedSchedulerUsage._Myfirst;
        }
        if ( v49->_Isnil == 0 )
        {
          v58 = v49->_Right;
          if ( v58->_Isnil != 0 )
          {
            for ( ii = v49->_Parent; ii->_Isnil == 0; ii = ii->_Parent )
            {
              if ( v49 != ii->_Right )
                break;
              v49 = ii;
            }
            v49 = ii;
          }
          else
          {
            v49 = v49->_Right;
            for ( jj = v58->_Left; jj->_Isnil == 0; jj = jj->_Left )
              v49 = jj;
          }
        }
      }
      while ( v49 != perShaderStatsMap->_Myhead );
    }
    printf(format: "\n");
  }
  if ( defaultPerShaderStats.m_SortedSchedulerUsage._Myfirst != nullptr )
    operator delete(p: defaultPerShaderStats.m_SortedSchedulerUsage._Myfirst);
  memset(&defaultPerShaderStats.m_SortedSchedulerUsage, 0, 12);
  std::_Tree<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const,int>>,0>>::erase(
    this: &defaultPerShaderStats.m_SchedulerHist,
    result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > > *)&it,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)defaultPerShaderStats.m_SchedulerHist._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<int,int,std::less<int>,std::allocator<std::pair<int const ,int> >,0> > >)defaultPerShaderStats.m_SchedulerHist._Myhead);
  operator delete(p: defaultPerShaderStats.m_SchedulerHist._Myhead);
}

//------------------------------------------------------------------------------
// Address: 0x00407AD0
// Name: public: class std::_Tree_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>> std::_Tree<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>::erase(class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>>,class std::_Tree_const_iterator<class std::_Tree_val<class std::_Tmap_traits<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>,struct PerShaderStats_t,struct std::less<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>>>,class std::allocator<struct std::pair<class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char>> const,struct PerShaderStats_t>>,0>>>)
// Source: json
//------------------------------------------------------------------------------
std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *__thiscall std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::erase(
        std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > *this,
        std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *result,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > _First,
        std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > _Last)
{
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Myhead; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Ptr; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v7; // ecx
  std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > v9; // edx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *Right; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v11; // ecx
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *j; // eax
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *i; // eax
  std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > v14; // [esp+4h] [ebp-4h] BYREF

  Myhead = this->_Myhead;
  Ptr = _First._Ptr;
  if ( _First._Ptr == Myhead->_Left && _Last._Ptr == Myhead )
  {
    std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::_Erase(
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
      std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::erase(
        this,
        result: &v14,
        _Where: v9);
    }
    result->_Ptr = Ptr;
    return result;
  }
}

//------------------------------------------------------------------------------
// Address: 0x00407BA0
// Name: _main
// Source: json
//------------------------------------------------------------------------------
int __cdecl main(int argc, const char **argv, const char **envp)
{
  int j; // esi
  int v5; // ecx
  void *v6; // eax
  unsigned int Mysize; // edi
  _DWORD *v8; // esi
  std::string *v9; // edi
  std::string *k; // esi
  char *v11; // eax
  char v12; // cl
  std::string *Myfirst; // esi
  CompileStats_t *v14; // esi
  std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *v15; // eax
  bool v16; // cl
  std::string *Ptr; // eax
  std::string outputFilename; // [esp+8h] [ebp-60h] BYREF
  std::map<std::string,PerShaderStats_t> perShaderStatsMap; // [esp+24h] [ebp-44h] BYREF
  std::vector<std::string> inputFiles; // [esp+34h] [ebp-34h] BYREF
  std::string _Val; // [esp+44h] [ebp-24h] BYREF
  int i; // [esp+60h] [ebp-8h] BYREF
  BOOL bPrintDetailedStats; // [esp+64h] [ebp-4h]

  if ( argc > 1 )
  {
    printf(format: "ps3shaderoptimizer ");
    for ( j = 1; j < argc; ++j )
      printf(format: "%s ", argv[j]);
    printf(format: "\n\n");
  }
  InitCommandLineProgram(&argc, (char ***)&argv);
  if ( argc < 2 )
  {
    printf(format: "Usage: ps3shaderoptimizer InputFilename.txt [InputFilename.txt] [-s] [-oOutputFilename.bin]\n");
    printf(format: "-s               - Print statistics\n");
    printf(format: "-oOutputfile.bin - Write binary output file, for use in future PS3 shader builds\n");
    return 1;
  }
  v5 = 1;
  memset(&inputFiles, 0, 12);
  LOBYTE(bPrintDetailedStats) = 0;
  outputFilename._Myres = 15;
  outputFilename._Mysize = 0;
  outputFilename._Bx._Buf[0] = 0;
  i = 1;
  do
  {
    v11 = (char *)argv[v5];
    if ( *v11 == 45 )
    {
      v12 = v11[1];
      if ( v12 == 115 )
      {
        LOBYTE(bPrintDetailedStats) = 1;
      }
      else
      {
        if ( v12 != 111 )
        {
          printf(format: "Invalid option: %s\n", v11);
          if ( outputFilename._Myres >= 0x10 )
            operator delete(p: outputFilename._Bx._Ptr);
          outputFilename._Myres = 15;
          Myfirst = inputFiles._Myfirst;
          outputFilename._Mysize = 0;
          outputFilename._Bx._Buf[0] = 0;
          if ( inputFiles._Myfirst != nullptr )
          {
            std::_Destroy_range<std::allocator<std::string>>(_First: inputFiles._Myfirst, _Last: inputFiles._Mylast);
            operator delete(p: (void *)Myfirst);
            return 1;
          }
          return 1;
        }
        std::string::assign(this: &outputFilename, _Ptr: v11 + 2, _Count: strlen(v11 + 2));
      }
    }
    else
    {
      _Val._Myres = 15;
      _Val._Mysize = 0;
      _Val._Bx._Buf[0] = 0;
      std::string::assign(this: &_Val, _Ptr: v11, _Count: strlen(v11));
      std::vector<std::string>::push_back(this: &inputFiles, &_Val);
      if ( _Val._Myres >= 0x10 )
        operator delete(p: _Val._Bx._Ptr);
    }
    v5 = i + 1;
    i = v5;
  }
  while ( v5 < argc );
  v9 = inputFiles._Myfirst;
  memset(&_Val._Bx._Alias[12], 0, 12);
  if ( LoadLogFiles(&inputFiles, compileStats: (std::vector<CompileStats_t> *)&_Val._Bx._Alias[12], bPrintDetailedStats) == 0 )
  {
    v6 = *(void **)&_Val._Bx._Alias[12];
    if ( *(_DWORD *)&_Val._Bx._Alias[12] != 0 )
    {
      Mysize = _Val._Mysize;
      if ( *(_DWORD *)&_Val._Bx._Alias[12] != _Val._Mysize )
      {
        v8 = (_DWORD *)(*(_DWORD *)&_Val._Bx._Alias[12] + 36);
        do
        {
          if ( *v8 >= 0x10u )
          {
            operator delete(p: (void *)*(v8 - 5));
            v6 = *(void **)&_Val._Bx._Alias[12];
          }
          *v8 = 15;
          *(v8 - 1) = 0;
          *((_BYTE *)v8 - 20) = 0;
          v8 += 16;
        }
        while ( v8 - 9 != (_DWORD *)Mysize );
      }
      operator delete(p: v6);
      v9 = inputFiles._Myfirst;
    }
    if ( outputFilename._Myres >= 0x10 )
      operator delete(p: outputFilename._Bx._Ptr);
    outputFilename._Myres = 15;
    outputFilename._Mysize = 0;
    outputFilename._Bx._Buf[0] = 0;
    if ( v9 != nullptr )
    {
      for ( k = v9; k != inputFiles._Mylast; ++k )
      {
        if ( k->_Myres >= 0x10 )
          operator delete(p: k->_Bx._Ptr);
        k->_Myres = 15;
        k->_Mysize = 0;
        k->_Bx._Buf[0] = 0;
      }
      operator delete(p: (void *)v9);
      return 1;
    }
    return 1;
  }
  v14 = *(CompileStats_t **)&_Val._Bx._Alias[12];
  if ( *(_DWORD *)&_Val._Bx._Alias[12] == _Val._Mysize )
  {
    printf(format: "Error: No statistics!\n");
LABEL_47:
    if ( v14 != nullptr )
    {
      std::_Destroy_range<std::allocator<CompileStats_t>>(_First: v14, _Last: (CompileStats_t *)_Val._Mysize);
      operator delete(p: v14);
    }
    if ( outputFilename._Myres >= 0x10 )
      operator delete(p: outputFilename._Bx._Ptr);
    outputFilename._Myres = 15;
    outputFilename._Mysize = 0;
    outputFilename._Bx._Buf[0] = 0;
    if ( v9 != nullptr )
    {
      std::_Destroy_range<std::allocator<std::string>>(_First: v9, _Last: inputFiles._Mylast);
      operator delete(p: (void *)v9);
    }
    return 1;
  }
  PrintGlobalStatistics(compileStats: (const std::vector<CompileStats_t> *)&_Val._Bx._Alias[12]);
  if ( bPrintDetailedStats )
  {
    PrintCategorizedStatistics(compileStats: (const std::vector<CompileStats_t> *)&_Val._Bx._Alias[12]);
    PrintGlobalSchedulerStatistics(compileStats: (const std::vector<CompileStats_t> *)&_Val._Bx._Alias[12]);
  }
  perShaderStatsMap._Mysize = 0;
  v15 = (std::_Tree_nod<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> >::_Node *)operator new(size: 0xA0u);
  if ( v15 == nullptr )
  {
    i = 0;
    std::exception::exception(this: (std::exception *)&_Val._Mysize, _What: (const char *const *)&i);
    _Val._Mysize = (unsigned int)&std::bad_alloc::`vftable';
    _CxxThrowException(pExceptionObject: &_Val._Mysize, pThrowInfo: &_TI2_AVbad_alloc_std__);
  }
  v16 = bPrintDetailedStats;
  perShaderStatsMap._Myhead = v15;
  v15->_Left = v15;
  perShaderStatsMap._Myhead->_Parent = perShaderStatsMap._Myhead;
  perShaderStatsMap._Myhead->_Right = perShaderStatsMap._Myhead;
  perShaderStatsMap._Myhead->_Color = 1;
  perShaderStatsMap._Myhead->_Isnil = 1;
  ComputeAndPrintPerShaderStatistics(
    compileStats: (const std::vector<CompileStats_t> *)&_Val._Bx._Alias[12],
    &perShaderStatsMap,
    bPrintStats: v16);
  if ( outputFilename._Mysize != 0 )
  {
    Ptr = (std::string *)outputFilename._Bx._Ptr;
    if ( outputFilename._Myres < 0x10 )
      Ptr = &outputFilename;
    if ( WriteOutputFile(
           compileStats: (const std::vector<CompileStats_t> *)&_Val._Bx._Alias[12],
           shaderStats: &perShaderStatsMap,
           pFilename: Ptr->_Bx._Buf) == 0 )
    {
      std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::erase(
        this: &perShaderStatsMap,
        result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *)&i,
        _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > >)perShaderStatsMap._Myhead->_Left,
        _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > >)perShaderStatsMap._Myhead);
      operator delete(p: perShaderStatsMap._Myhead);
      goto LABEL_47;
    }
  }
  printf(format: "Success.\n");
  std::_Tree<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string>,std::allocator<std::pair<std::string const,PerShaderStats_t>>,0>>::erase(
    this: &perShaderStatsMap,
    result: (std::_Tree_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > > *)&i,
    _First: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > >)perShaderStatsMap._Myhead->_Left,
    _Last: (std::_Tree_const_iterator<std::_Tree_val<std::_Tmap_traits<std::string,PerShaderStats_t,std::less<std::string >,std::allocator<std::pair<std::string const ,PerShaderStats_t> >,0> > >)perShaderStatsMap._Myhead);
  operator delete(p: perShaderStatsMap._Myhead);
  if ( v14 != nullptr )
  {
    std::_Destroy_range<std::allocator<CompileStats_t>>(_First: v14, _Last: (CompileStats_t *)_Val._Mysize);
    operator delete(p: v14);
  }
  if ( outputFilename._Myres >= 0x10 )
    operator delete(p: outputFilename._Bx._Ptr);
  outputFilename._Myres = 15;
  outputFilename._Mysize = 0;
  outputFilename._Bx._Buf[0] = 0;
  if ( v9 != nullptr )
  {
    std::_Destroy_range<std::allocator<std::string>>(_First: v9, _Last: inputFiles._Mylast);
    operator delete(p: (void *)v9);
  }
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x0040827E
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
// Address: 0x004082CB
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
// Address: 0x004082AE
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
// Address: 0x004082FB
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
// Address: 0x00408350
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
