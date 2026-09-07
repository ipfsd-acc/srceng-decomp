// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: mysql-connector-c-6.0.2/mysys/charset-def.c
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x0041DF40
// Name: _init_compiled_charsets
// Source: json
//------------------------------------------------------------------------------
char init_compiled_charsets()
{
  LIST_ENTRY32 *v0; // esi

  add_compiled_collation(a1: &my_charset_bin);
  add_compiled_collation(a1: &my_charset_filename);
  add_compiled_collation(a1: &my_charset_latin1);
  add_compiled_collation(a1: &my_charset_latin1_bin);
  add_compiled_collation(a1: &my_charset_latin1_german2_ci);
  add_compiled_collation(a1: &my_charset_big5_chinese_ci);
  add_compiled_collation(a1: &my_charset_big5_bin);
  add_compiled_collation(a1: &my_charset_cp1250_czech_ci);
  add_compiled_collation(a1: &my_charset_cp932_japanese_ci);
  add_compiled_collation(a1: &my_charset_cp932_bin);
  add_compiled_collation(a1: &my_charset_latin2_czech_ci);
  add_compiled_collation(a1: &my_charset_eucjpms_japanese_ci);
  add_compiled_collation(a1: &my_charset_eucjpms_bin);
  add_compiled_collation(a1: &my_charset_euckr_korean_ci);
  add_compiled_collation(a1: &my_charset_euckr_bin);
  add_compiled_collation(a1: &my_charset_gb2312_chinese_ci);
  add_compiled_collation(a1: &my_charset_gb2312_bin);
  add_compiled_collation(a1: &my_charset_gbk_chinese_ci);
  add_compiled_collation(a1: &my_charset_gbk_bin);
  add_compiled_collation(a1: &my_charset_sjis_japanese_ci);
  add_compiled_collation(a1: &my_charset_sjis_bin);
  add_compiled_collation(a1: &my_charset_tis620_thai_ci);
  add_compiled_collation(a1: &my_charset_tis620_bin);
  add_compiled_collation(a1: &my_charset_ucs2_general_ci);
  add_compiled_collation(a1: &my_charset_ucs2_bin);
  add_compiled_collation(a1: &my_charset_ucs2_unicode_ci);
  add_compiled_collation(a1: &my_charset_ucs2_icelandic_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_latvian_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_romanian_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_slovenian_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_polish_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_estonian_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_spanish_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_swedish_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_turkish_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_czech_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_danish_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_lithuanian_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_slovak_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_spanish2_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_roman_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_persian_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_esperanto_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_hungarian_uca_ci);
  add_compiled_collation(a1: &my_charset_ucs2_sinhala_uca_ci);
  add_compiled_collation(a1: &my_charset_ujis_japanese_ci);
  add_compiled_collation(a1: &my_charset_ujis_bin);
  add_compiled_collation(a1: &my_charset_utf8mb3_general_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_bin);
  add_compiled_collation(a1: &my_charset_utf8mb3_unicode_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_icelandic_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_latvian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_romanian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_slovenian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_polish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_estonian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_spanish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_swedish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_turkish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_czech_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_danish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_lithuanian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_slovak_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_spanish2_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_roman_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_persian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_esperanto_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_hungarian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb3_sinhala_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_general_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_bin);
  add_compiled_collation(a1: &my_charset_utf8mb4_unicode_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_icelandic_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_latvian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_romanian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_slovenian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_polish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_estonian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_spanish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_swedish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_turkish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_czech_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_danish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_lithuanian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_slovak_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_spanish2_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_roman_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_persian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_esperanto_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_hungarian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf8mb4_sinhala_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_general_ci);
  add_compiled_collation(a1: &my_charset_utf16_bin);
  add_compiled_collation(a1: &my_charset_utf16_unicode_ci);
  add_compiled_collation(a1: &my_charset_utf16_icelandic_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_latvian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_romanian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_slovenian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_polish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_estonian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_spanish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_swedish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_turkish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_czech_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_danish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_lithuanian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_slovak_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_spanish2_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_roman_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_persian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_esperanto_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_hungarian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf16_sinhala_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_general_ci);
  add_compiled_collation(a1: &my_charset_utf32_bin);
  add_compiled_collation(a1: &my_charset_utf32_unicode_ci);
  add_compiled_collation(a1: &my_charset_utf32_icelandic_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_latvian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_romanian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_slovenian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_polish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_estonian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_spanish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_swedish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_turkish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_czech_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_danish_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_lithuanian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_slovak_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_spanish2_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_roman_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_persian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_esperanto_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_hungarian_uca_ci);
  add_compiled_collation(a1: &my_charset_utf32_sinhala_uca_ci);
  v0 = (LIST_ENTRY32 *)&compiled_charsets;
  if ( compiled_charsets.sizeOrOffset != 0 )
  {
    do
    {
      add_compiled_collation(a1: v0);
      v0 = (LIST_ENTRY32 *)((char *)v0 + 108);
    }
    while ( v0[2].Blink != 0 );
  }
  return 0;
}
