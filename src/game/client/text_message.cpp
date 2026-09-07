// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/text_message.cpp
// Functions: 3
// ============================================================

#include "game\client\text_message.h"

//------------------------------------------------------------------------------
// Address: 0x10179F90
// Name: public: virtual char __near * CHudTextMessage::LocaliseTextString(char const __near *,char __near *,int)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHudTextMessage::LocaliseTextString(
        CHudTextMessage *this,
        char *msg,
        char *dst_buffer,
        int buffer_size)
{
  char *result; // eax
  char *v5; // esi
  char *v6; // edi
  int v7; // ecx
  char v8; // al
  char *v9; // ecx
  client_textmessage_t *v10; // eax
  client_textmessage_t *v11; // ebx
  const char *v12; // eax
  const wchar_t *v13; // eax
  char *pMessage; // ecx
  char i; // al
  char *v16; // [esp+8h] [ebp-4h]
  char *word_start; // [esp+14h] [ebp+8h]

  result = dst_buffer;
  v5 = msg;
  v6 = dst_buffer;
  if ( *msg != 0 )
  {
    while ( 1 )
    {
      v7 = buffer_size;
      if ( buffer_size <= 0 )
      {
LABEL_20:
        result[v7 - 1] = 0;
        return result;
      }
      if ( *v5 != 35 )
        break;
      v8 = v5[1];
      word_start = v5++;
      v9 = word_buf;
      v16 = v5;
      if ( v8 >= 65 )
      {
        do
        {
          if ( v8 > 122 )
            break;
          ++v5;
          *v9 = v8;
          v8 = *v5;
          ++v9;
        }
        while ( *v5 >= 65 );
      }
      *v9 = 0;
      v10 = TextMessageGet(pName: word_buf);
      v11 = v10;
      if ( v10 != nullptr && (v12 = v10->pMessage) != nullptr )
      {
        if ( *v12 != 35 || (v13 = g_pVGuiLocalize->Find(this: g_pVGuiLocalize, a2: v11->pMessage)) == nullptr )
        {
          pMessage = (char *)v11->pMessage;
          for ( i = *pMessage; *pMessage != 0; ++v6 )
          {
            ++pMessage;
            *v6 = i;
            i = *pMessage;
          }
          result = dst_buffer;
          goto LABEL_17;
        }
        g_pVGuiLocalize->ConvertUnicodeToANSI(this: g_pVGuiLocalize, a2: v13, a3: v6, a4: buffer_size);
        result = dst_buffer;
      }
      else
      {
        v5 = v16;
        result = dst_buffer;
        *v6++ = *word_start;
      }
LABEL_18:
      --buffer_size;
      if ( *v5 == 0 )
      {
        v7 = buffer_size;
        goto LABEL_20;
      }
    }
    *v6++ = *v5++;
LABEL_17:
    *v6 = 0;
    goto LABEL_18;
  }
  dst_buffer[buffer_size - 1] = 0;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1017A0A0
// Name: public: virtual char __near * CHudTextMessage::BufferedLocaliseTextString(char const __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHudTextMessage::BufferedLocaliseTextString(CHudTextMessage *this, const char *msg)
{
  return this->LocaliseTextString(this, a2: msg, a3: dst_buffer, a4: 1024);
}

//------------------------------------------------------------------------------
// Address: 0x1017A0C0
// Name: public: virtual char __near * CHudTextMessage::LookupString(char const __near *,int __near *)
// Source: json
//------------------------------------------------------------------------------
char *__thiscall CHudTextMessage::LookupString(CHudTextMessage *this, const char *msg, int *msg_dest)
{
  client_textmessage_t *v4; // eax

  if ( msg == nullptr )
    return (char *)prType;
  if ( *msg != 35 )
    return (char *)msg;
  v4 = TextMessageGet(pName: msg + 1);
  if ( v4 == nullptr || v4->pMessage == nullptr )
    return (char *)msg;
  if ( msg_dest != nullptr && v4->effect < 0 )
    *msg_dest = -v4->effect;
  return (char *)v4->pMessage;
}
