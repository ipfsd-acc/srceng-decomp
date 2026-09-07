// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vscript/languages/squirrel/sqstdlib/sqstdrex.cpp
// Functions: 15
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100328B0
// Name: sqstd_rex_newnode
// Source: json
//------------------------------------------------------------------------------
int __usercall sqstd_rex_newnode@<eax>(SQRex *exp@<ecx>, unsigned int type@<eax>)
{
  int nallocated; // eax
  int v4; // eax
  tagSQRexNode *v5; // eax
  unsigned __int64 n; // [esp+4h] [ebp-10h]
  __int64 n_8; // [esp+Ch] [ebp-8h]

  n = type | 0xFFFFFFFF00000000uLL;
  n_8 = -1;
  if ( type == 258 )
  {
    LODWORD(n_8) = exp->_nsubexpr;
    exp->_nsubexpr = n_8 + 1;
  }
  nallocated = exp->_nallocated;
  if ( nallocated < exp->_nsize + 1 )
  {
    v4 = 2 * nallocated;
    exp->_nallocated = v4;
    exp->_nodes = (tagSQRexNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp->_nodes, a3: 16 * v4);
  }
  v5 = &exp->_nodes[exp->_nsize];
  *(_QWORD *)&v5->type = n;
  *(_QWORD *)&v5->right = n_8;
  return exp->_nsize++;
}

//------------------------------------------------------------------------------
// Address: 0x10032930
// Name: sqstd_rex_expect
// Source: json
//------------------------------------------------------------------------------
void __thiscall __noreturn sqstd_rex_expect(SQRex *exp)
{
  const char **error; // eax

  error = exp->_error;
  if ( error != nullptr )
    *error = "expected paren";
  longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
}

//------------------------------------------------------------------------------
// Address: 0x10032950
// Name: sqstd_rex_escapechar
// Source: json
//------------------------------------------------------------------------------
char __usercall sqstd_rex_escapechar@<al>(SQRex *exp@<esi>)
{
  const char *p; // eax
  const char *v2; // ecx
  char result; // al
  const char **error; // eax

  p = exp->_p;
  if ( *p == 92 )
  {
    v2 = p + 1;
    exp->_p = p + 1;
    result = p[1];
    switch ( result )
    {
      case 'f':
        exp->_p = v2 + 1;
        result = 12;
        break;
      case 'n':
        exp->_p = v2 + 1;
        result = 10;
        break;
      case 'r':
        exp->_p = v2 + 1;
        result = 13;
        break;
      case 't':
        exp->_p = v2 + 1;
        result = 9;
        break;
      case 'v':
        exp->_p = v2 + 1;
        result = 11;
        break;
      default:
        goto LABEL_13;
    }
  }
  else
  {
    if ( isprint(c: *p) == 0 )
    {
      error = exp->_error;
      if ( error != nullptr )
        *error = "letter expected";
      longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
    }
    v2 = exp->_p;
    result = *v2;
LABEL_13:
    exp->_p = v2 + 1;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032A00
// Name: sqstd_rex_charclass
// Source: json
//------------------------------------------------------------------------------
int __usercall sqstd_rex_charclass@<eax>(SQRex *exp@<eax>, int classid)
{
  int nsize; // ecx
  int nallocated; // eax
  int v5; // eax
  tagSQRexNode *v6; // eax
  int result; // eax

  nsize = exp->_nsize;
  nallocated = exp->_nallocated;
  if ( nallocated < nsize + 1 )
  {
    v5 = 2 * nallocated;
    exp->_nallocated = v5;
    exp->_nodes = (tagSQRexNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp->_nodes, a3: 16 * v5);
  }
  v6 = &exp->_nodes[exp->_nsize];
  *(_QWORD *)&v6->type = -4294967034LL;
  *(_QWORD *)&v6->right = -1;
  result = exp->_nsize++;
  exp->_nodes[result].left = classid;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032A80
// Name: sqstd_rex_charnode
// Source: json
//------------------------------------------------------------------------------
int __usercall sqstd_rex_charnode@<eax>(SQRex *exp@<esi>, unsigned int isclass)
{
  const char *p; // eax
  const char *v3; // eax
  char v4; // cl
  int result; // eax
  const char **error; // eax

  p = exp->_p;
  if ( *p == 92 )
  {
    v3 = p + 1;
    exp->_p = v3;
    v4 = *v3;
    switch ( *v3 )
    {
      case 'A':
      case 'C':
      case 'D':
      case 'P':
      case 'S':
      case 'W':
      case 'X':
      case 'a':
      case 'c':
      case 'd':
      case 'l':
      case 'p':
      case 's':
      case 'u':
      case 'w':
      case 'x':
        exp->_p = v3 + 1;
        result = sqstd_rex_charclass(exp, classid: v4);
        break;
      case 'B':
      case 'b':
        if ( isclass != 0 )
          goto LABEL_16;
        result = sqstd_rex_newnode(exp, type: 0x10Cu);
        exp->_nodes[result].left = *exp->_p++;
        break;
      case 'f':
        exp->_p = v3 + 1;
        result = sqstd_rex_newnode(exp, type: 0xCu);
        break;
      case 'n':
        exp->_p = v3 + 1;
        result = sqstd_rex_newnode(exp, type: 0xAu);
        break;
      case 'r':
        exp->_p = v3 + 1;
        result = sqstd_rex_newnode(exp, type: 0xDu);
        break;
      case 't':
        exp->_p = v3 + 1;
        result = sqstd_rex_newnode(exp, type: 9u);
        break;
      case 'v':
        exp->_p = v3 + 1;
        result = sqstd_rex_newnode(exp, type: 0xBu);
        break;
      default:
        goto LABEL_16;
    }
  }
  else
  {
    if ( isprint(c: *p) == 0 )
    {
      error = exp->_error;
      if ( error != nullptr )
        *error = "letter expected";
      longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
    }
    v3 = exp->_p;
    v4 = *v3;
LABEL_16:
    exp->_p = v3 + 1;
    return sqstd_rex_newnode(exp, type: v4);
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10032BE0
// Name: sqstd_rex_class
// Source: json
//------------------------------------------------------------------------------
int __usercall sqstd_rex_class@<eax>(SQRex *exp@<eax>)
{
  int nsize; // edx
  bool v3; // zf
  int nallocated; // eax
  int v5; // edi
  int v6; // eax
  tagSQRexNode *v7; // eax
  int v8; // eax
  int v9; // eax
  tagSQRexNode *v10; // eax
  const char **error; // eax
  int v12; // ebx
  const char *p; // eax
  int v14; // edx
  int v15; // eax
  int v16; // eax
  tagSQRexNode *v17; // eax
  tagSQRexNode *nodes; // eax
  int type; // ecx
  int v20; // eax
  int v21; // eax
  const char **v23; // eax
  const char **v24; // eax
  __int64 v25; // [esp+Ch] [ebp-18h]
  int ret; // [esp+1Ch] [ebp-8h]
  int chain; // [esp+20h] [ebp-4h]

  nsize = exp->_nsize;
  v3 = *exp->_p == 94;
  nallocated = exp->_nallocated;
  v5 = -1;
  HIDWORD(v25) = -1;
  if ( v3 )
  {
    LODWORD(v25) = 263;
    if ( nallocated < nsize + 1 )
    {
      v6 = 2 * nallocated;
      exp->_nallocated = v6;
      exp->_nodes = (tagSQRexNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp->_nodes, a3: 16 * v6);
    }
    v7 = &exp->_nodes[exp->_nsize];
    *(_QWORD *)&v7->type = v25;
    *(_QWORD *)&v7->right = -1;
    v8 = exp->_nsize++;
    ++exp->_p;
  }
  else
  {
    LODWORD(v25) = 261;
    if ( nallocated < nsize + 1 )
    {
      v9 = 2 * nallocated;
      exp->_nallocated = v9;
      exp->_nodes = (tagSQRexNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp->_nodes, a3: 16 * v9);
    }
    v10 = &exp->_nodes[exp->_nsize];
    *(_QWORD *)&v10->type = v25;
    *(_QWORD *)&v10->right = -1;
    v8 = exp->_nsize++;
  }
  ret = v8;
  if ( *exp->_p == 93 )
  {
    error = exp->_error;
    if ( error != nullptr )
      *error = "empty class";
    longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
  }
  v12 = v8;
  chain = v8;
  do
  {
    p = exp->_p;
    if ( p == exp->_eol )
      break;
    if ( *p == 45 )
    {
      if ( v5 != -1 )
      {
        v14 = exp->_nsize;
        exp->_p = p + 1;
        v15 = exp->_nallocated;
        if ( v15 < v14 + 1 )
        {
          v16 = 2 * v15;
          exp->_nallocated = v16;
          exp->_nodes = (tagSQRexNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp->_nodes, a3: 16 * v16);
        }
        v17 = &exp->_nodes[exp->_nsize];
        *(_QWORD *)&v17->type = -4294967032LL;
        *(_QWORD *)&v17->right = -1;
        v12 = exp->_nsize++;
        if ( v5 > *exp->_p )
        {
          v23 = exp->_error;
          if ( v23 != nullptr )
            *v23 = "invalid range";
          longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
        }
        nodes = exp->_nodes;
        type = nodes[v5].type;
        if ( type == 262 )
        {
          v24 = exp->_error;
          if ( v24 != nullptr )
            *v24 = "cannot use character classes in ranges";
          longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
        }
        nodes[v12].left = type;
        exp->_nodes[v12].right = sqstd_rex_escapechar(exp);
        exp->_nodes[chain].next = v12;
        chain = v12;
        v5 = -1;
        continue;
      }
LABEL_23:
      v20 = sqstd_rex_charnode(exp, isclass: 1u);
      goto LABEL_24;
    }
    if ( v5 == -1 )
      goto LABEL_23;
    exp->_nodes[v12].next = v5;
    chain = v5;
    v20 = sqstd_rex_charnode(exp, isclass: 1u);
    v12 = v5;
LABEL_24:
    v5 = v20;
  }
  while ( *exp->_p != 93 );
  if ( v5 != -1 )
    exp->_nodes[v12].next = v5;
  v21 = ret;
  exp->_nodes[v21].left = exp->_nodes[ret].next;
  exp->_nodes[v21].next = -1;
  return ret;
}

//------------------------------------------------------------------------------
// Address: 0x10032E50
// Name: sqstd_rex_parsenumber
// Source: json
//------------------------------------------------------------------------------
int __usercall sqstd_rex_parsenumber@<eax>(SQRex *exp@<edi>)
{
  const char *p; // eax
  int v2; // esi
  int v3; // esi
  int v4; // ebx
  const char *v5; // eax
  int v6; // edx
  const char *v7; // eax
  const char **error; // eax

  p = exp->_p;
  v2 = *p++;
  exp->_p = p;
  v3 = v2 - 48;
  v4 = 10;
  if ( isdigit(c: *p) != 0 )
  {
    do
    {
      v5 = exp->_p;
      v6 = *v5;
      v7 = v5 + 1;
      v3 = v6 + 10 * v3 - 48;
      exp->_p = v7;
      if ( v4 == 1000000000 )
      {
        error = exp->_error;
        if ( error != nullptr )
          *error = "overflow in numeric constant";
        longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
      }
      v4 *= 10;
    }
    while ( isdigit(c: *v7) != 0 );
  }
  return v3;
}

//------------------------------------------------------------------------------
// Address: 0x10032EC0
// Name: sqstd_rex_element
// Source: json
//------------------------------------------------------------------------------
int __cdecl sqstd_rex_element(SQRex *exp)
{
  const char *p; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char **error; // eax
  unsigned int v6; // eax
  int v7; // esi
  const char *v8; // eax
  int v9; // ebx
  const char **v10; // eax
  const char **v11; // eax
  int v12; // eax
  const char *v13; // eax
  unsigned __int16 v14; // si
  int nallocated; // eax
  int v16; // eax
  tagSQRexNode *v17; // eax
  int v18; // ecx
  int v19; // eax
  char v20; // al
  const char *v22; // eax
  const char **v23; // eax
  unsigned __int16 v24; // dx
  const char **v25; // eax
  const char *v26; // eax
  unsigned __int16 p0; // [esp+24h] [ebp+8h]

  p = exp->_p;
  switch ( *p )
  {
    case '$':
      exp->_p = p + 1;
      v12 = sqstd_rex_newnode(exp, type: 0x10Au);
      goto LABEL_21;
    case '(':
      v3 = p + 1;
      exp->_p = v3;
      if ( *v3 == 63 )
      {
        v4 = v3 + 1;
        exp->_p = v4;
        if ( *v4 != 58 )
        {
          error = exp->_error;
          if ( error != nullptr )
            *error = "expected paren";
          longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
        }
        exp->_p = v4 + 1;
        v6 = 259;
      }
      else
      {
        v6 = 258;
      }
      v7 = sqstd_rex_newnode(exp, type: v6);
      exp->_nodes[v7].left = sqstd_rex_list(exp);
      v8 = exp->_p;
      v9 = v7;
      if ( *v8 != 41 )
      {
        v10 = exp->_error;
        if ( v10 != nullptr )
          *v10 = "expected paren";
        longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
      }
      goto $LN89_2;
    case '.':
      exp->_p = p + 1;
      v12 = sqstd_rex_newnode(exp, type: 0x104u);
      goto LABEL_21;
    case '[':
      exp->_p = p + 1;
      v9 = sqstd_rex_class(exp);
      v8 = exp->_p;
      if ( *v8 != 93 )
      {
        v11 = exp->_error;
        if ( v11 != nullptr )
          *v11 = "expected paren";
        longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
      }
$LN89_2:
      exp->_p = v8 + 1;
      break;
    default:
      v12 = sqstd_rex_charnode(exp, isclass: 0);
LABEL_21:
      v9 = v12;
      break;
  }
  v13 = exp->_p;
  switch ( *v13 )
  {
    case '*':
      p0 = 0;
      goto LABEL_24;
    case '+':
      p0 = 1;
LABEL_24:
      v14 = -1;
      goto LABEL_25;
    case '?':
      p0 = 0;
      v14 = 1;
      goto LABEL_25;
    case '{':
      v22 = v13 + 1;
      exp->_p = v22;
      if ( isdigit(c: *v22) == 0 )
      {
        v23 = exp->_error;
        if ( v23 != nullptr )
          *v23 = "number expected";
        longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
      }
      v24 = sqstd_rex_parsenumber(exp);
      v13 = exp->_p;
      p0 = v24;
      if ( *v13 == 44 )
      {
        v26 = v13 + 1;
        exp->_p = v26;
        v14 = -1;
        if ( isdigit(c: *v26) != 0 )
          v14 = sqstd_rex_parsenumber(exp);
        v13 = exp->_p;
        if ( *v13 != 125 )
          sqstd_rex_expect(exp);
      }
      else
      {
        if ( *v13 != 125 )
        {
          v25 = exp->_error;
          if ( v25 != nullptr )
            *v25 = ", or } expected";
          longjmp(Buf: (int *)exp->_jmpbuf, Value: -1);
        }
        v14 = v24;
      }
LABEL_25:
      exp->_p = v13 + 1;
      nallocated = exp->_nallocated;
      if ( nallocated < exp->_nsize + 1 )
      {
        v16 = 2 * nallocated;
        exp->_nallocated = v16;
        exp->_nodes = (tagSQRexNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp->_nodes, a3: 16 * v16);
      }
      v17 = &exp->_nodes[exp->_nsize];
      *(_QWORD *)&v17->type = 0xFFFFFFFF00000100uLL;
      *(_QWORD *)&v17->right = -1;
      v18 = ++exp->_nsize;
      v19 = v18 - 1;
      exp->_nodes[v19].left = v9;
      exp->_nodes[v19].right = v14 | (p0 << 16);
      v9 = v18 - 1;
      break;
    default:
      break;
  }
  v20 = *exp->_p;
  if ( v20 != 124 && v20 != 41 && v20 != 42 && v20 != 43 && v20 != 0 )
    exp->_nodes[v9].next = sqstd_rex_element(exp);
  return v9;
}

//------------------------------------------------------------------------------
// Address: 0x10033230
// Name: sqstd_rex_list
// Source: json
//------------------------------------------------------------------------------
int __cdecl sqstd_rex_list(SQRex *exp)
{
  const char *p; // eax
  int v2; // edi
  int nsize; // ecx
  int nallocated; // eax
  int v5; // eax
  tagSQRexNode *v6; // eax
  int v7; // eax
  const char *v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // eax
  tagSQRexNode *v12; // eax
  int v13; // ebx
  int ret; // [esp+1Ch] [ebp-4h]

  p = exp->_p;
  v2 = -1;
  ret = -1;
  if ( *p == 94 )
  {
    nsize = exp->_nsize;
    exp->_p = p + 1;
    nallocated = exp->_nallocated;
    if ( nallocated < nsize + 1 )
    {
      v5 = 2 * nallocated;
      exp->_nallocated = v5;
      exp->_nodes = (tagSQRexNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp->_nodes, a3: 16 * v5);
    }
    v6 = &exp->_nodes[exp->_nsize];
    *(_QWORD *)&v6->type = -4294967029LL;
    *(_QWORD *)&v6->right = -1;
    ret = exp->_nsize++;
    v2 = ret;
  }
  v7 = sqstd_rex_element(exp);
  if ( v2 == -1 )
  {
    ret = v7;
    v2 = v7;
  }
  else
  {
    exp->_nodes[v2].next = v7;
  }
  v8 = exp->_p;
  if ( *v8 != 124 )
    return v2;
  v9 = exp->_nsize;
  exp->_p = v8 + 1;
  v10 = exp->_nallocated;
  if ( v10 < v9 + 1 )
  {
    v11 = 2 * v10;
    exp->_nallocated = v11;
    exp->_nodes = (tagSQRexNode *)_g_pMemAlloc->Realloc_2(this: _g_pMemAlloc, a2: exp->_nodes, a3: 16 * v11);
  }
  v12 = &exp->_nodes[exp->_nsize];
  *(_QWORD *)&v12->type = -4294967039LL;
  *(_QWORD *)&v12->right = -1;
  v13 = ++exp->_nsize;
  exp->_nodes[v13 - 1].left = ret;
  exp->_nodes[v13 - 1].right = sqstd_rex_list(exp);
  return v13 - 1;
}

//------------------------------------------------------------------------------
// Address: 0x10033370
// Name: sqstd_rex_matchcclass
// Source: json
//------------------------------------------------------------------------------
BOOL __usercall sqstd_rex_matchcclass@<eax>(int cclass@<eax>, char c)
{
  BOOL result; // eax

  switch ( cclass )
  {
    case 'A':
      return isalpha(c) == 0;
    case 'C':
      return iscntrl(c) == 0;
    case 'D':
      return isdigit(c) == 0;
    case 'P':
      return ispunct(c) == 0;
    case 'S':
      return isspace(c) == 0;
    case 'W':
      if ( isalnum(c) != 0 || c == 95 )
        goto LABEL_6;
      goto LABEL_9;
    case 'X':
      return isxdigit(c) == 0;
    case 'a':
      return isalpha(c) != 0;
    case 'c':
      return iscntrl(c) != 0;
    case 'd':
      return isdigit(c) != 0;
    case 'l':
      return islower(c) != 0;
    case 'p':
      return ispunct(c) != 0;
    case 's':
      return isspace(c) != 0;
    case 'u':
      return isupper(c) != 0;
    case 'w':
      if ( isalnum(c) == 0 && c != 95 )
        goto LABEL_6;
LABEL_9:
      result = 1;
      break;
    case 'x':
      return isxdigit(c) != 0;
    default:
LABEL_6:
      result = 0;
      break;
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x10033560
// Name: sqstd_rex_matchclass
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall sqstd_rex_matchclass@<eax>(SQRex *exp@<edi>, tagSQRexNode *node@<eax>, char c)
{
  int v5; // eax
  BOOL v6; // eax
  bool v7; // zf
  int next; // eax

  do
  {
    if ( node->type == 262 )
    {
      switch ( node->left )
      {
        case 'A':
          v6 = isalpha(c) == 0;
          goto LABEL_29;
        case 'C':
          v6 = iscntrl(c) == 0;
          goto LABEL_29;
        case 'D':
          v6 = isdigit(c) == 0;
          goto LABEL_29;
        case 'P':
          v6 = ispunct(c) == 0;
          goto LABEL_29;
        case 'S':
          v6 = isspace(c) == 0;
          goto LABEL_29;
        case 'W':
          if ( isalnum(c) != 0 )
            goto LABEL_31;
          v7 = c == 95;
          goto LABEL_30;
        case 'X':
          v6 = isxdigit(c) == 0;
          goto LABEL_29;
        case 'a':
          v5 = isalpha(c);
          goto LABEL_28;
        case 'c':
          v5 = iscntrl(c);
          goto LABEL_28;
        case 'd':
          v5 = isdigit(c);
          goto LABEL_28;
        case 'l':
          v5 = islower(c);
          goto LABEL_28;
        case 'p':
          v5 = ispunct(c);
          goto LABEL_28;
        case 's':
          v5 = isspace(c);
          goto LABEL_28;
        case 'u':
          v5 = isupper(c);
          goto LABEL_28;
        case 'w':
          if ( isalnum(c) == 0 && c != 95 )
            goto LABEL_31;
          return 1;
        case 'x':
          v5 = isxdigit(c);
LABEL_28:
          v6 = v5 != 0;
LABEL_29:
          v7 = !v6;
LABEL_30:
          if ( v7 )
            goto LABEL_31;
          return 1;
        default:
          goto LABEL_31;
      }
    }
    if ( node->type == 264 )
    {
      if ( c >= node->left && c <= node->right )
        return 1;
    }
    else if ( c == node->type )
    {
      return 1;
    }
LABEL_31:
    next = node->next;
    if ( next == -1 )
      break;
    node = &exp->_nodes[next];
  }
  while ( node != nullptr );
  return 0;
}

//------------------------------------------------------------------------------
// Address: 0x10033780
// Name: sqstd_rex_matchnode
// Source: json
//------------------------------------------------------------------------------
const char *__cdecl sqstd_rex_matchnode(SQRex *exp, int node, const char *str, tagSQRexNode *next)
{
  int v5; // ecx
  const char *v6; // esi
  SQRex *v7; // edx
  int v8; // eax
  int v9; // ecx
  signed int v10; // edi
  tagSQRexNode *v11; // ebx
  int v12; // eax
  const char *v13; // eax
  int v14; // eax
  tagSQRexNode *v15; // ecx
  tagSQRexNode *v16; // eax
  int v17; // eax
  bool v18; // cc
  const char *result; // eax
  tagSQRexNode *v20; // esi
  int v21; // ecx
  tagSQRexNode *v22; // esi
  int v23; // ecx
  tagSQRexNode *v24; // esi
  int currsubexp; // ecx
  int v26; // ecx
  tagSQRexNode *v27; // ecx
  int v28; // esi
  int v29; // eax
  bool v30; // zf
  const char *good; // [esp+Ch] [ebp-Ch]
  const char *gooda; // [esp+Ch] [ebp-Ch]
  int p1; // [esp+10h] [ebp-8h]
  int nmaches; // [esp+14h] [ebp-4h]
  int capture; // [esp+24h] [ebp+Ch]

  v5 = *(_DWORD *)node;
  good = *(const char **)node;
  switch ( *(_DWORD *)node )
  {
    case 0x100:
      v6 = str;
      v7 = exp;
      p1 = (unsigned __int16)*(_DWORD *)(node + 8);
      v8 = *(_DWORD *)(node + 12);
      v9 = 0;
      v10 = (unsigned __int16)HIWORD(*(_DWORD *)(node + 8));
      nmaches = 0;
      gooda = str;
      if ( v8 == -1 )
        v11 = next;
      else
        v11 = &exp->_nodes[v8];
      while ( 2 )
      {
        if ( v9 == 0xFFFF || (v12 = p1, v9 < p1) )
        {
          v13 = sqstd_rex_matchnode(exp: v7, node: &v7->_nodes[*(_DWORD *)(node + 4)], str: v6, next: v11);
          v6 = v13;
          if ( v13 == nullptr )
            goto LABEL_25;
          ++nmaches;
          gooda = v13;
          if ( v11 == nullptr || v11->type == 256 && HIWORD(v11->right) == 0 )
          {
LABEL_24:
            if ( v6 < exp->_eol )
            {
              v7 = exp;
              v9 = nmaches;
              continue;
            }
LABEL_25:
            v9 = nmaches;
            v12 = p1;
            break;
          }
          v14 = v11->next;
          v15 = nullptr;
          if ( v14 == -1 )
          {
            if ( next == nullptr )
              goto LABEL_18;
            v17 = next->next;
            if ( v17 == -1 )
              goto LABEL_18;
            v16 = &exp->_nodes[v17];
          }
          else
          {
            v16 = &exp->_nodes[v14];
          }
          v15 = v16;
LABEL_18:
          if ( sqstd_rex_matchnode(exp, node: v11, str: v6, next: v15) != nullptr
            && (v10 == p1 && v10 == nmaches || nmaches >= v10 && (p1 == 0xFFFF || nmaches <= p1)) )
          {
            goto LABEL_25;
          }
          goto LABEL_24;
        }
        break;
      }
      if ( v10 == v12 )
      {
        v18 = v9 < v10;
        if ( v9 == v10 )
          return gooda;
      }
      else
      {
        v18 = v9 < v10;
      }
      if ( v18 )
        return nullptr;
      if ( v12 == 0xFFFF )
        return gooda;
      if ( v9 > v12 )
        return nullptr;
      return gooda;
    case 0x101:
      v20 = &exp->_nodes[*(_DWORD *)(node + 4)];
      result = sqstd_rex_matchnode(exp, node: v20, str, next: nullptr);
      if ( result == nullptr )
        goto LABEL_37;
      while ( 1 )
      {
        v21 = v20->next;
        if ( v21 == -1 )
          break;
        v20 = &exp->_nodes[v21];
        result = sqstd_rex_matchnode(exp, node: v20, str: result, next: nullptr);
        if ( result == nullptr )
        {
LABEL_37:
          v22 = &exp->_nodes[*(_DWORD *)(node + 8)];
          result = sqstd_rex_matchnode(exp, node: v22, str, next: nullptr);
          if ( result == nullptr )
            return nullptr;
          while ( 1 )
          {
            v23 = v22->next;
            if ( v23 == -1 )
              break;
            v22 = &exp->_nodes[v23];
            result = sqstd_rex_matchnode(exp, node: v22, str: result, next: nullptr);
            if ( result == nullptr )
              return nullptr;
          }
          return result;
        }
      }
      return result;
    case 0x102:
    case 0x103:
      result = str;
      v24 = &exp->_nodes[*(_DWORD *)(node + 4)];
      capture = -1;
      if ( v5 != 259 )
      {
        currsubexp = exp->_currsubexp;
        if ( *(_DWORD *)(node + 8) == currsubexp )
        {
          exp->_matches[currsubexp].begin = str;
          ++exp->_currsubexp;
          capture = currsubexp;
        }
      }
      while ( 1 )
      {
        v26 = v24->next;
        v27 = v26 == -1 ? next : &exp->_nodes[v26];
        result = sqstd_rex_matchnode(exp, node: v24, str: result, next: v27);
        if ( result == nullptr )
          break;
        v28 = v24->next;
        if ( v28 != -1 )
        {
          v24 = &exp->_nodes[v28];
          if ( v24 != nullptr )
            continue;
        }
        if ( capture != -1 )
          exp->_matches[capture].len = result - exp->_matches[capture].begin;
        return result;
      }
      if ( capture != -1 )
      {
        exp->_matches[capture].begin = nullptr;
        exp->_matches[capture].len = 0;
      }
      return nullptr;
    case 0x104:
      return str + 1;
    case 0x105:
    case 0x107:
      if ( sqstd_rex_matchclass(exp, node: &exp->_nodes[*(_DWORD *)(node + 4)], c: *str) != 0 )
      {
        v29 = 0;
        v30 = good == (const char *)261;
      }
      else
      {
        v29 = 0;
        v30 = good == (const char *)263;
      }
      LOBYTE(v29) = v30;
      if ( v29 == 0 )
        return nullptr;
      return str + 1;
    case 0x106:
      if ( !sqstd_rex_matchcclass(cclass: *(_DWORD *)(node + 4), c: *str) )
        return nullptr;
      return str + 1;
    case 0x10A:
      return str != exp->_eol ? nullptr : str;
    case 0x10B:
      return str != exp->_bol ? nullptr : str;
    case 0x10C:
      if ( (str != exp->_bol || isspace(c: *str) != 0)
        && (str != exp->_eol || isspace(c: *(str - 1)) != 0)
        && (isspace(c: *str) != 0 || isspace(c: str[1]) == 0)
        && (isspace(c: *str) == 0 || isspace(c: str[1]) != 0) )
      {
        return *(_DWORD *)(node + 4) != 98 ? str : nullptr;
      }
      else
      {
        return *(_DWORD *)(node + 4) != 98 ? nullptr : str;
      }
    default:
      if ( *str == v5 )
        return str + 1;
      else
        return nullptr;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033BB0
// Name: _sqstd_rex_compile
// Source: json
//------------------------------------------------------------------------------
SQRex *__cdecl sqstd_rex_compile(const char *pattern, const char **error)
{
  void *v2; // esi
  unsigned int v3; // eax
  _QWORD *v4; // eax
  _DWORD *v5; // eax
  void *v6; // eax
  _EXCEPTION_REGISTRATION_RECORD *v8; // [esp+0h] [ebp-20h]
  int v9; // [esp+4h] [ebp-1Ch]
  int savedregs; // [esp+20h] [ebp+0h] BYREF

  v2 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 52);
  *((_DWORD *)v2 + 1) = 0;
  *(_DWORD *)v2 = 0;
  *((_DWORD *)v2 + 2) = pattern;
  v3 = strlen(pattern);
  *((_DWORD *)v2 + 6) = v3;
  *((_DWORD *)v2 + 5) = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 16 * v3);
  *((_DWORD *)v2 + 7) = 0;
  *((_DWORD *)v2 + 9) = 0;
  *((_DWORD *)v2 + 8) = 1;
  if ( *((_DWORD *)v2 + 6) < *((_DWORD *)v2 + 7) + 1 )
  {
    *((_DWORD *)v2 + 6) *= 2;
    *((_DWORD *)v2 + 5) = _g_pMemAlloc->Realloc_2(
                            this: _g_pMemAlloc,
                            a2: *((_DWORD *)v2 + 5),
                            a3: 16 * *((_DWORD *)v2 + 6));
  }
  v4 = (_QWORD *)(*((_DWORD *)v2 + 5) + 16 * *((_DWORD *)v2 + 7));
  *v4 = -4294967038LL;
  v4[1] = 0xFFFFFFFF00000000uLL;
  *((_DWORD *)v2 + 3) = (*((_DWORD *)v2 + 7))++;
  *((_DWORD *)v2 + 12) = error;
  v5 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 64);
  *((_DWORD *)v2 + 11) = v5;
  if ( _setjmp3(a1: 0, a2: (int)&savedregs, a3: 1, a4: (int)v2, a5: v5, a6: 0, a7: v8, a8: v9) != 0 )
  {
    sqstd_rex_free(exp: (SQRex *)v2);
    return nullptr;
  }
  else
  {
    *(_DWORD *)(*((_DWORD *)v2 + 5) + 16 * *((_DWORD *)v2 + 3) + 4) = sqstd_rex_list(exp: (SQRex *)v2);
    if ( **((_BYTE **)v2 + 2) != 0 )
    {
      if ( *((_DWORD *)v2 + 12) != 0 )
        **((_DWORD **)v2 + 12) = "unexpected character";
      longjmp(Buf: *((int **)v2 + 11), Value: -1);
    }
    v6 = _g_pMemAlloc->Alloc_2(this: _g_pMemAlloc, a2: 8 * *((_DWORD *)v2 + 8));
    *((_DWORD *)v2 + 9) = v6;
    memset(dst: (int)v6, value: nullptr, count: 8 * *((_DWORD *)v2 + 8));
    return (SQRex *)v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033D20
// Name: _sqstd_rex_free
// Source: json
//------------------------------------------------------------------------------
void __usercall sqstd_rex_free(SQRex *exp@<esi>)
{
  if ( exp != nullptr )
  {
    if ( exp->_nodes != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: exp->_nodes);
    if ( exp->_jmpbuf != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: exp->_jmpbuf);
    if ( exp->_matches != nullptr )
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: exp->_matches);
    _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: exp);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10033D80
// Name: _sqstd_rex_searchrange
// Source: json
//------------------------------------------------------------------------------
unsigned int __usercall sqstd_rex_searchrange@<eax>(
        SQRex *exp@<edi>,
        const char *text_begin,
        const char *text_end,
        const char **out_begin,
        const char **out_end)
{
  const char *v5; // ecx
  int first; // ebx
  unsigned int result; // eax
  tagSQRexNode *v8; // [esp-10h] [ebp-14h]

  v5 = text_begin;
  first = exp->_first;
  if ( text_begin >= text_end )
    return 0;
  exp->_bol = text_begin;
  exp->_eol = text_end;
  while ( 1 )
  {
    result = (unsigned int)v5;
    if ( first != -1 )
    {
      do
      {
        v8 = &exp->_nodes[first];
        exp->_currsubexp = 0;
        result = (unsigned int)sqstd_rex_matchnode(exp, node: (int)v8, str: (const char *)result, next: nullptr);
        if ( result == 0 )
          break;
        first = exp->_nodes[first].next;
      }
      while ( first != -1 );
      v5 = text_begin;
    }
    text_begin = ++v5;
    if ( result != 0 )
      break;
    if ( v5 == text_end )
      return result;
  }
  if ( out_begin != nullptr )
    *out_begin = v5 - 1;
  if ( out_end != nullptr )
    *out_end = (const char *)result;
  return 1;
}
