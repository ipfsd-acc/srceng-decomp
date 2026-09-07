// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: tracker/adminserver/tokenline.cpp
// Functions: 5
// ============================================================

#include "tracker\adminserver\tokenline.h"

//------------------------------------------------------------------------------
// Address: 0x1000DE70
// Name: public: virtual TokenLine::~TokenLine(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall TokenLine::~TokenLine(TokenLine *this)
{
  this->__vftable = (TokenLine_vtbl *)&TokenLine::`vftable';
}

//------------------------------------------------------------------------------
// Address: 0x1000DEB0
// Name: public: bool TokenLine::SetLine(char const __near *)
// Source: json
//------------------------------------------------------------------------------
bool __thiscall TokenLine::SetLine(TokenLine *this, char *newLine)
{
  char *m_tokenBuffer; // eax
  char v4; // cl
  int m_tokenNumber; // edx
  char i; // cl
  char j; // cl

  this->m_tokenNumber = 0;
  if ( newLine != nullptr && strlen(newLine) < 0x7FF )
  {
    strncpy(dest: (unsigned __int8 *)this->m_fullLine, source: (unsigned __int8 *)newLine, count: 0x7FFu);
    this->m_fullLine[2047] = 0;
    strncpy(dest: (unsigned __int8 *)this->m_tokenBuffer, source: (unsigned __int8 *)newLine, count: 0x7FFu);
    m_tokenBuffer = this->m_tokenBuffer;
    this->m_tokenBuffer[2047] = 0;
    v4 = this->m_tokenBuffer[0];
    if ( v4 != 0 )
    {
      do
      {
        m_tokenNumber = this->m_tokenNumber;
        if ( m_tokenNumber >= 128 )
          break;
        while ( v4 <= 32 || v4 == 127 )
        {
          v4 = *++m_tokenBuffer;
          if ( v4 == 0 )
            return this->m_tokenNumber != 128;
        }
        if ( *m_tokenBuffer == 0 )
          break;
        this->m_token[m_tokenNumber] = m_tokenBuffer;
        if ( *m_tokenBuffer == 34 )
        {
          this->m_token[this->m_tokenNumber] = ++m_tokenBuffer;
          for ( i = *m_tokenBuffer; i != 0; i = *++m_tokenBuffer )
          {
            if ( i == 34 )
              break;
          }
        }
        else
        {
          this->m_token[this->m_tokenNumber] = m_tokenBuffer;
          for ( j = *m_tokenBuffer; j != 0; j = *++m_tokenBuffer )
          {
            if ( (unsigned __int8)(j - 33) > 0x5Du )
              break;
          }
        }
        ++this->m_tokenNumber;
        if ( *m_tokenBuffer != 0 )
          *m_tokenBuffer++ = 0;
        v4 = *m_tokenBuffer;
      }
      while ( *m_tokenBuffer != 0 );
    }
    return this->m_tokenNumber != 128;
  }
  else
  {
    memset(dst: (int)this->m_fullLine, value: nullptr, count: sizeof(this->m_fullLine));
    memset(dst: (int)this->m_tokenBuffer, value: nullptr, count: sizeof(this->m_tokenBuffer));
    return false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x1000E020
// Name: public: char __near * TokenLine::GetToken(int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall TokenLine::GetToken(TokenLine *this, int i)
{
  if ( i < this->m_tokenNumber )
    return this->m_token[i];
  else
    return nullptr;
}

//------------------------------------------------------------------------------
// Address: 0x1000E040
// Name: public: int TokenLine::CountToken(void)
// Source: json
//------------------------------------------------------------------------------
int __thiscall TokenLine::CountToken(TokenLine *this)
{
  int m_tokenNumber; // edx
  int result; // eax
  char **m_token; // ecx

  m_tokenNumber = this->m_tokenNumber;
  result = 0;
  if ( m_tokenNumber > 0 )
  {
    m_token = this->m_token;
    do
    {
      if ( *m_token != nullptr )
        ++result;
      ++m_token;
      --m_tokenNumber;
    }
    while ( m_tokenNumber != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1000E060
// Name: public: TokenLine::TokenLine(void)
// Source: json
//------------------------------------------------------------------------------
TokenLine *__thiscall TokenLine::TokenLine(TokenLine *this)
{
  this->__vftable = (TokenLine_vtbl *)&TokenLine::`vftable';
  return this;
}
