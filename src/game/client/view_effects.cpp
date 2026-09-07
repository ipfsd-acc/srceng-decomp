// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: game/client/view_effects.cpp
// Functions: 67
// ============================================================

#include "game\client\view_effects.h"

//------------------------------------------------------------------------------
// Address: 0x10190E50
// Name: class IViewEffects __near * GetViewEffects(void)
// Source: json
//------------------------------------------------------------------------------
CViewEffects *__cdecl GetViewEffects()
{
  return g_ViewEffects;
}

//------------------------------------------------------------------------------
// Address: 0x10190E60
// Name: void CC_Shake_Stop(void)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Shake_Stop()
{
  g_ViewEffects[0].ClearAllShakes(this: g_ViewEffects);
}

//------------------------------------------------------------------------------
// Address: 0x10190E70
// Name: public: virtual void CViewEffects::GetFadeParams(unsigned char __near *,unsigned char __near *,unsigned char __near *,unsigned char __near *,bool __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::GetFadeParams(
        CViewEffects *this,
        unsigned __int8 *r,
        unsigned __int8 *g,
        unsigned __int8 *b,
        unsigned __int8 *a,
        bool *blend)
{
  if ( g_pIntroData == nullptr || g_pIntroData->m_flCurrentFadeColor[3] == 0.0 )
  {
    this->FadeCalculate(this);
    *r = this->m_FadeColorRGBA[0];
    *g = this->m_FadeColorRGBA[1];
    *b = this->m_FadeColorRGBA[2];
    *a = this->m_FadeColorRGBA[3];
    *blend = this->m_bModulate;
  }
  else
  {
    *r = (int)g_pIntroData->m_flCurrentFadeColor[0];
    *g = (int)g_pIntroData->m_flCurrentFadeColor[1];
    *b = (int)g_pIntroData->m_flCurrentFadeColor[2];
    *a = (int)g_pIntroData->m_flCurrentFadeColor[3];
    *blend = false;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10190F20
// Name: class ISaveRestoreBlockHandler __near * GetViewEffectsRestoreBlockHandler(void)
// Source: json
//------------------------------------------------------------------------------
CViewEffectsSaveRestoreBlockHandler *__cdecl GetViewEffectsRestoreBlockHandler()
{
  return &g_ViewEffectsSaveRestoreBlockHandler;
}

//------------------------------------------------------------------------------
// Address: 0x10190F30
// Name: void __MsgFunc_Shake(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_Shake(bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v3; // edx
  ShakeCommand_t v4; // esi
  int v5; // ecx
  ShakeCommand_t v6; // edi
  const unsigned int *v7; // ecx
  const unsigned int *v8; // edx
  unsigned int v9; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v12; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v14; // esi
  unsigned int v15; // ebx
  int v16; // esi
  unsigned int v17; // ecx
  const unsigned int *v18; // edx
  const unsigned int *v19; // esi
  const unsigned int *v20; // ecx
  unsigned int v21; // edi
  int v22; // edx
  const unsigned int *v23; // esi
  unsigned int v24; // esi
  unsigned int v25; // ebx
  int v26; // esi
  unsigned int v27; // ecx
  const unsigned int *v28; // edx
  const unsigned int *v29; // esi
  const unsigned int *v30; // ecx
  unsigned int v31; // edi
  int v32; // edx
  const unsigned int *v33; // esi
  unsigned int v34; // esi
  unsigned int v35; // ebx
  int v36; // esi
  unsigned int v37; // ecx
  const unsigned int *v38; // edx
  const unsigned int *v39; // esi
  const unsigned int *v40; // ecx
  unsigned int v41; // edi
  int v42; // edx
  const unsigned int *v43; // esi
  unsigned int v44; // esi
  unsigned int v45; // ebx
  void (__thiscall *v46)(struct CViewEffects *, const ScreenShake_t *); // edx
  ScreenShake_t shake; // [esp+0h] [ebp-1Ch] BYREF
  bf_read *msga; // [esp+24h] [ebp+8h]
  bf_read *msgb; // [esp+24h] [ebp+8h]
  bf_read *msgc; // [esp+24h] [ebp+8h]

  m_nBitsAvail = msg->m_nBitsAvail;
  memset((void *)&shake.direction, 0, sizeof(shake.direction));
  if ( m_nBitsAvail < 8 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v12 = 8 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      v6 = SHAKE_START;
    }
    else
    {
      v14 = msg->m_nInBufWord;
      v15 = (v14 & CBitBuffer::s_nMaskTable[v12]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v12;
      v6 = v15 | m_nInBufWord;
      msg->m_nInBufWord = v14 >> v12;
    }
    goto LABEL_19;
  }
  v3 = msg->m_nInBufWord;
  v4 = (unsigned __int8)v3;
  v5 = m_nBitsAvail - 8;
  msg->m_nBitsAvail = v5;
  if ( v5 != 0 )
  {
    msg->m_nInBufWord = v3 >> 8;
    v6 = (unsigned __int8)v3;
  }
  else
  {
    v7 = msg->m_pDataIn;
    v8 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v7 == v8 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v7 + 1;
      v6 = v4;
    }
    else
    {
      if ( v7 <= v8 )
      {
        v9 = *v7;
        msg->m_pDataIn = v7 + 1;
        msg->m_nInBufWord = v9;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v6 = v4;
    }
  }
LABEL_19:
  v16 = msg->m_nBitsAvail;
  shake.command = v6;
  if ( v16 < 32 )
  {
    v20 = msg->m_pDataIn;
    v21 = msg->m_nInBufWord;
    v22 = 32 - v16;
    v23 = msg->m_pBufferEnd;
    if ( v20 == v23 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v20 > v23 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v20;
    }
    msg->m_pDataIn = v20 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      msga = nullptr;
    }
    else
    {
      v24 = msg->m_nInBufWord;
      v25 = (v24 & CBitBuffer::s_nMaskTable[v22]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v22;
      msga = (bf_read *)(v25 | v21);
      msg->m_nInBufWord = v24 >> v22;
    }
    goto LABEL_37;
  }
  v17 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v16 - 32;
  if ( v16 == 32 )
  {
    v18 = msg->m_pDataIn;
    v19 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v18 == v19 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v18 + 1;
      msga = (bf_read *)v17;
    }
    else
    {
      if ( v18 <= v19 )
      {
        msg->m_nInBufWord = *v18;
        msg->m_pDataIn = v18 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msga = (bf_read *)v17;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    msga = (bf_read *)v17;
  }
LABEL_37:
  v26 = msg->m_nBitsAvail;
  LODWORD(shake.amplitude) = msga;
  if ( v26 < 32 )
  {
    v30 = msg->m_pDataIn;
    v31 = msg->m_nInBufWord;
    v32 = 32 - v26;
    v33 = msg->m_pBufferEnd;
    if ( v30 == v33 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v30 > v33 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_52;
      }
      msg->m_nInBufWord = *v30;
    }
    msg->m_pDataIn = v30 + 1;
LABEL_52:
    if ( msg->m_bOverflow )
    {
      msgb = nullptr;
    }
    else
    {
      v34 = msg->m_nInBufWord;
      v35 = (v34 & CBitBuffer::s_nMaskTable[v32]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v32;
      msgb = (bf_read *)(v35 | v31);
      msg->m_nInBufWord = v34 >> v32;
    }
    goto LABEL_55;
  }
  v27 = msg->m_nInBufWord;
  msg->m_nBitsAvail = v26 - 32;
  if ( v26 == 32 )
  {
    v28 = msg->m_pDataIn;
    v29 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v28 == v29 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v28 + 1;
      msgb = (bf_read *)v27;
    }
    else
    {
      if ( v28 <= v29 )
      {
        msg->m_nInBufWord = *v28;
        msg->m_pDataIn = v28 + 1;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      msgb = (bf_read *)v27;
    }
  }
  else
  {
    msg->m_nInBufWord = 0;
    msgb = (bf_read *)v27;
  }
LABEL_55:
  v36 = msg->m_nBitsAvail;
  LODWORD(shake.frequency) = msgb;
  if ( v36 >= 32 )
  {
    v37 = msg->m_nInBufWord;
    msg->m_nBitsAvail = v36 - 32;
    if ( v36 == 32 )
    {
      v38 = msg->m_pDataIn;
      v39 = msg->m_pBufferEnd;
      msg->m_nBitsAvail = 32;
      if ( v38 == v39 )
      {
        msg->m_nBitsAvail = 1;
        msg->m_nInBufWord = 0;
        msg->m_pDataIn = v38 + 1;
        msgc = (bf_read *)v37;
        goto LABEL_72;
      }
      if ( v38 <= v39 )
      {
        msg->m_nInBufWord = *v38;
        msg->m_pDataIn = v38 + 1;
        msgc = (bf_read *)v37;
        goto LABEL_72;
      }
      msg->m_bOverflow = true;
    }
    msg->m_nInBufWord = 0;
    msgc = (bf_read *)v37;
    goto LABEL_72;
  }
  v40 = msg->m_pDataIn;
  v41 = msg->m_nInBufWord;
  v42 = 32 - v36;
  v43 = msg->m_pBufferEnd;
  if ( v40 == v43 )
  {
    msg->m_nBitsAvail = 1;
    msg->m_nInBufWord = 0;
    msg->m_bOverflow = true;
  }
  else
  {
    if ( v40 > v43 )
    {
      msg->m_bOverflow = true;
      msg->m_nInBufWord = 0;
      goto LABEL_69;
    }
    msg->m_nInBufWord = *v40;
  }
  msg->m_pDataIn = v40 + 1;
LABEL_69:
  if ( msg->m_bOverflow )
  {
    msgc = nullptr;
  }
  else
  {
    v44 = msg->m_nInBufWord;
    v45 = (v44 & CBitBuffer::s_nMaskTable[v42]) << msg->m_nBitsAvail;
    msg->m_nBitsAvail = 32 - v42;
    msgc = (bf_read *)(v45 | v41);
    msg->m_nInBufWord = v44 >> v42;
  }
LABEL_72:
  v46 = g_ViewEffects[0].Shake;
  LODWORD(shake.duration) = msgc;
  v46(this: g_ViewEffects, a2: &shake);
}

//------------------------------------------------------------------------------
// Address: 0x101912F0
// Name: void __MsgFunc_Fade(class bf_read __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl __MsgFunc_Fade(bf_read *msg)
{
  int m_nBitsAvail; // ecx
  unsigned int v2; // edx
  unsigned __int16 v3; // si
  int v4; // ecx
  unsigned __int16 v5; // di
  const unsigned int *v6; // ecx
  const unsigned int *v7; // edx
  unsigned int v8; // edx
  const unsigned int *m_pBufferEnd; // esi
  unsigned int m_nInBufWord; // edi
  int v11; // edx
  const unsigned int *m_pDataIn; // ecx
  unsigned int v13; // esi
  unsigned int v14; // ebx
  int v15; // ecx
  unsigned int v16; // edx
  unsigned __int16 v17; // si
  int v18; // ecx
  unsigned __int16 v19; // cx
  const unsigned int *v20; // ecx
  const unsigned int *v21; // edx
  unsigned int v22; // edx
  const unsigned int *v23; // esi
  unsigned int v24; // edi
  int v25; // edx
  const unsigned int *v26; // ecx
  unsigned int v27; // esi
  unsigned int v28; // ebx
  int v29; // ecx
  unsigned int v30; // edx
  __int16 v31; // si
  int v32; // ecx
  __int16 v33; // cx
  const unsigned int *v34; // ecx
  const unsigned int *v35; // edx
  unsigned int v36; // edx
  const unsigned int *v37; // esi
  unsigned int v38; // edi
  int v39; // edx
  const unsigned int *v40; // ecx
  unsigned int v41; // esi
  unsigned int v42; // ebx
  int v43; // ecx
  unsigned int v44; // edx
  unsigned __int8 v45; // si
  int v46; // ecx
  unsigned __int8 v47; // cl
  const unsigned int *v48; // ecx
  const unsigned int *v49; // edx
  unsigned int v50; // edx
  const unsigned int *v51; // esi
  unsigned int v52; // edi
  int v53; // edx
  const unsigned int *v54; // ecx
  unsigned int v55; // esi
  unsigned int v56; // ebx
  int v57; // ecx
  unsigned int v58; // edx
  unsigned __int8 v59; // si
  int v60; // ecx
  unsigned __int8 v61; // cl
  const unsigned int *v62; // ecx
  const unsigned int *v63; // edx
  unsigned int v64; // edx
  const unsigned int *v65; // esi
  unsigned int v66; // edi
  int v67; // edx
  const unsigned int *v68; // ecx
  unsigned int v69; // esi
  unsigned int v70; // ebx
  int v71; // ecx
  unsigned int v72; // edx
  unsigned __int8 v73; // si
  int v74; // ecx
  unsigned __int8 v75; // cl
  const unsigned int *v76; // ecx
  const unsigned int *v77; // edx
  unsigned int v78; // edx
  const unsigned int *v79; // esi
  unsigned int v80; // edi
  int v81; // edx
  const unsigned int *v82; // ecx
  unsigned int v83; // esi
  unsigned int v84; // ebx
  int v85; // ecx
  unsigned int v86; // edx
  unsigned __int8 v87; // si
  int v88; // ecx
  unsigned __int8 v89; // al
  const unsigned int *v90; // ecx
  const unsigned int *v91; // edx
  unsigned int v92; // edx
  const unsigned int *v93; // esi
  unsigned int v94; // edi
  int v95; // edx
  const unsigned int *v96; // ecx
  unsigned int v97; // esi
  unsigned int v98; // ebx
  ScreenFade_t fade; // [esp+Ch] [ebp-Ch] BYREF

  m_nBitsAvail = msg->m_nBitsAvail;
  if ( m_nBitsAvail < 16 )
  {
    m_pBufferEnd = msg->m_pBufferEnd;
    m_nInBufWord = msg->m_nInBufWord;
    v11 = 16 - m_nBitsAvail;
    m_pDataIn = msg->m_pDataIn;
    if ( m_pDataIn == m_pBufferEnd )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( m_pDataIn > m_pBufferEnd )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_16;
      }
      msg->m_nInBufWord = *m_pDataIn;
    }
    msg->m_pDataIn = m_pDataIn + 1;
LABEL_16:
    if ( msg->m_bOverflow )
    {
      v5 = 0;
    }
    else
    {
      v13 = msg->m_nInBufWord;
      v14 = (v13 & CBitBuffer::s_nMaskTable[v11]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v11;
      v5 = v14 | m_nInBufWord;
      msg->m_nInBufWord = v13 >> v11;
    }
    goto LABEL_19;
  }
  v2 = msg->m_nInBufWord;
  v3 = v2;
  v4 = m_nBitsAvail - 16;
  msg->m_nBitsAvail = v4;
  if ( v4 != 0 )
  {
    msg->m_nInBufWord = HIWORD(v2);
    v5 = v2;
  }
  else
  {
    v6 = msg->m_pDataIn;
    v7 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v6 == v7 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v6 + 1;
      v5 = v3;
    }
    else
    {
      if ( v6 <= v7 )
      {
        v8 = *v6;
        msg->m_pDataIn = v6 + 1;
        msg->m_nInBufWord = v8;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v5 = v3;
    }
  }
LABEL_19:
  v15 = msg->m_nBitsAvail;
  fade.duration = v5;
  if ( v15 < 16 )
  {
    v23 = msg->m_pBufferEnd;
    v24 = msg->m_nInBufWord;
    v25 = 16 - v15;
    v26 = msg->m_pDataIn;
    if ( v26 == v23 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v26 > v23 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_34;
      }
      msg->m_nInBufWord = *v26;
    }
    msg->m_pDataIn = v26 + 1;
LABEL_34:
    if ( msg->m_bOverflow )
    {
      v19 = 0;
    }
    else
    {
      v27 = msg->m_nInBufWord;
      v28 = (v27 & CBitBuffer::s_nMaskTable[v25]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v25;
      v19 = v28 | v24;
      msg->m_nInBufWord = v27 >> v25;
    }
    goto LABEL_37;
  }
  v16 = msg->m_nInBufWord;
  v17 = v16;
  v18 = v15 - 16;
  msg->m_nBitsAvail = v18;
  if ( v18 != 0 )
  {
    msg->m_nInBufWord = HIWORD(v16);
    v19 = v16;
  }
  else
  {
    v20 = msg->m_pDataIn;
    v21 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v20 == v21 )
    {
      msg->m_pDataIn = v20 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v19 = v17;
    }
    else
    {
      if ( v20 <= v21 )
      {
        v22 = *v20;
        msg->m_pDataIn = v20 + 1;
        msg->m_nInBufWord = v22;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v19 = v17;
    }
  }
LABEL_37:
  fade.holdTime = v19;
  v29 = msg->m_nBitsAvail;
  if ( v29 < 16 )
  {
    v37 = msg->m_pBufferEnd;
    v38 = msg->m_nInBufWord;
    v39 = 16 - v29;
    v40 = msg->m_pDataIn;
    if ( v40 == v37 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v40 > v37 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_52;
      }
      msg->m_nInBufWord = *v40;
    }
    msg->m_pDataIn = v40 + 1;
LABEL_52:
    if ( msg->m_bOverflow )
    {
      v33 = 0;
    }
    else
    {
      v41 = msg->m_nInBufWord;
      v42 = (v41 & CBitBuffer::s_nMaskTable[v39]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v39;
      v33 = v42 | v38;
      msg->m_nInBufWord = v41 >> v39;
    }
    goto LABEL_55;
  }
  v30 = msg->m_nInBufWord;
  v31 = v30;
  v32 = v29 - 16;
  msg->m_nBitsAvail = v32;
  if ( v32 != 0 )
  {
    msg->m_nInBufWord = HIWORD(v30);
    v33 = v30;
  }
  else
  {
    v34 = msg->m_pDataIn;
    v35 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v34 == v35 )
    {
      msg->m_pDataIn = v34 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v33 = v31;
    }
    else
    {
      if ( v34 <= v35 )
      {
        v36 = *v34;
        msg->m_pDataIn = v34 + 1;
        msg->m_nInBufWord = v36;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v33 = v31;
    }
  }
LABEL_55:
  fade.fadeFlags = v33;
  v43 = msg->m_nBitsAvail;
  if ( v43 < 8 )
  {
    v51 = msg->m_pBufferEnd;
    v52 = msg->m_nInBufWord;
    v53 = 8 - v43;
    v54 = msg->m_pDataIn;
    if ( v54 == v51 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v54 > v51 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_70;
      }
      msg->m_nInBufWord = *v54;
    }
    msg->m_pDataIn = v54 + 1;
LABEL_70:
    if ( msg->m_bOverflow )
    {
      v47 = 0;
    }
    else
    {
      v55 = msg->m_nInBufWord;
      v56 = (v55 & CBitBuffer::s_nMaskTable[v53]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v53;
      v47 = v56 | v52;
      msg->m_nInBufWord = v55 >> v53;
    }
    goto LABEL_73;
  }
  v44 = msg->m_nInBufWord;
  v45 = v44;
  v46 = v43 - 8;
  msg->m_nBitsAvail = v46;
  if ( v46 != 0 )
  {
    msg->m_nInBufWord = v44 >> 8;
    v47 = v44;
  }
  else
  {
    v48 = msg->m_pDataIn;
    v49 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v48 == v49 )
    {
      msg->m_pDataIn = v48 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v47 = v45;
    }
    else
    {
      if ( v48 <= v49 )
      {
        v50 = *v48;
        msg->m_pDataIn = v48 + 1;
        msg->m_nInBufWord = v50;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v47 = v45;
    }
  }
LABEL_73:
  fade.r = v47;
  v57 = msg->m_nBitsAvail;
  if ( v57 < 8 )
  {
    v65 = msg->m_pBufferEnd;
    v66 = msg->m_nInBufWord;
    v67 = 8 - v57;
    v68 = msg->m_pDataIn;
    if ( v68 == v65 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v68 > v65 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_88;
      }
      msg->m_nInBufWord = *v68;
    }
    msg->m_pDataIn = v68 + 1;
LABEL_88:
    if ( msg->m_bOverflow )
    {
      v61 = 0;
    }
    else
    {
      v69 = msg->m_nInBufWord;
      v70 = (v69 & CBitBuffer::s_nMaskTable[v67]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v67;
      v61 = v70 | v66;
      msg->m_nInBufWord = v69 >> v67;
    }
    goto LABEL_91;
  }
  v58 = msg->m_nInBufWord;
  v59 = v58;
  v60 = v57 - 8;
  msg->m_nBitsAvail = v60;
  if ( v60 != 0 )
  {
    msg->m_nInBufWord = v58 >> 8;
    v61 = v58;
  }
  else
  {
    v62 = msg->m_pDataIn;
    v63 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v62 == v63 )
    {
      msg->m_pDataIn = v62 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v61 = v59;
    }
    else
    {
      if ( v62 <= v63 )
      {
        v64 = *v62;
        msg->m_pDataIn = v62 + 1;
        msg->m_nInBufWord = v64;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v61 = v59;
    }
  }
LABEL_91:
  fade.g = v61;
  v71 = msg->m_nBitsAvail;
  if ( v71 < 8 )
  {
    v79 = msg->m_pBufferEnd;
    v80 = msg->m_nInBufWord;
    v81 = 8 - v71;
    v82 = msg->m_pDataIn;
    if ( v82 == v79 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v82 > v79 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_106;
      }
      msg->m_nInBufWord = *v82;
    }
    msg->m_pDataIn = v82 + 1;
LABEL_106:
    if ( msg->m_bOverflow )
    {
      v75 = 0;
    }
    else
    {
      v83 = msg->m_nInBufWord;
      v84 = (v83 & CBitBuffer::s_nMaskTable[v81]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v81;
      v75 = v84 | v80;
      msg->m_nInBufWord = v83 >> v81;
    }
    goto LABEL_109;
  }
  v72 = msg->m_nInBufWord;
  v73 = v72;
  v74 = v71 - 8;
  msg->m_nBitsAvail = v74;
  if ( v74 != 0 )
  {
    msg->m_nInBufWord = v72 >> 8;
    v75 = v72;
  }
  else
  {
    v76 = msg->m_pDataIn;
    v77 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v76 == v77 )
    {
      msg->m_pDataIn = v76 + 1;
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      v75 = v73;
    }
    else
    {
      if ( v76 <= v77 )
      {
        v78 = *v76;
        msg->m_pDataIn = v76 + 1;
        msg->m_nInBufWord = v78;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v75 = v73;
    }
  }
LABEL_109:
  fade.b = v75;
  v85 = msg->m_nBitsAvail;
  if ( v85 < 8 )
  {
    v93 = msg->m_pBufferEnd;
    v94 = msg->m_nInBufWord;
    v95 = 8 - v85;
    v96 = msg->m_pDataIn;
    if ( v96 == v93 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_bOverflow = true;
    }
    else
    {
      if ( v96 > v93 )
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
        goto LABEL_124;
      }
      msg->m_nInBufWord = *v96;
    }
    msg->m_pDataIn = v96 + 1;
LABEL_124:
    if ( msg->m_bOverflow )
    {
      v89 = 0;
    }
    else
    {
      v97 = msg->m_nInBufWord;
      v98 = (v97 & CBitBuffer::s_nMaskTable[v95]) << msg->m_nBitsAvail;
      msg->m_nBitsAvail = 32 - v95;
      msg->m_nInBufWord = v97 >> v95;
      v89 = v98 | v94;
    }
    goto LABEL_127;
  }
  v86 = msg->m_nInBufWord;
  v87 = v86;
  v88 = v85 - 8;
  msg->m_nBitsAvail = v88;
  if ( v88 != 0 )
  {
    msg->m_nInBufWord = v86 >> 8;
    v89 = v86;
  }
  else
  {
    v90 = msg->m_pDataIn;
    v91 = msg->m_pBufferEnd;
    msg->m_nBitsAvail = 32;
    if ( v90 == v91 )
    {
      msg->m_nBitsAvail = 1;
      msg->m_nInBufWord = 0;
      msg->m_pDataIn = v90 + 1;
      v89 = v87;
    }
    else
    {
      if ( v90 <= v91 )
      {
        v92 = *v90;
        msg->m_pDataIn = v90 + 1;
        msg->m_nInBufWord = v92;
      }
      else
      {
        msg->m_bOverflow = true;
        msg->m_nInBufWord = 0;
      }
      v89 = v87;
    }
  }
LABEL_127:
  fade.a = v89;
  g_ViewEffects[0].Fade(this: g_ViewEffects, a2: &fade);
}

//------------------------------------------------------------------------------
// Address: 0x10191920
// Name: public: virtual void CViewEffects::Init(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::Init(CViewEffects *this)
{
  CUserMessages::HookMessage(this: usermessages, name: "Shake", hook: __MsgFunc_Shake);
  CUserMessages::HookMessage(this: usermessages, name: "Fade", hook: __MsgFunc_Fade);
}

//------------------------------------------------------------------------------
// Address: 0x10191950
// Name: void CC_Shake_TestPunch(class CCommand const __near &)
// Source: json
//------------------------------------------------------------------------------
void __cdecl CC_Shake_TestPunch(const CCommand *args)
{
  const char *v2; // eax
  const char *v3; // eax
  const char *v4; // eax
  const char *v5; // eax
  const char *v6; // eax
  const char *v7; // eax
  const char *v8; // esi
  void (__thiscall *v9)(struct CViewEffects *, const ScreenShake_t *); // eax
  ScreenShake_t shake; // [esp+4h] [ebp-2Ch] BYREF
  float z; // [esp+20h] [ebp-10h]
  float y; // [esp+24h] [ebp-Ch]
  float x; // [esp+28h] [ebp-8h]
  float f; // [esp+2Ch] [ebp-4h]
  float a; // [esp+38h] [ebp+8h]

  if ( args->m_nArgc < 7 )
  {
    v2 = prType;
    if ( args->m_nArgc > 0 )
      v2 = args->m_ppArgv[0];
    _Msg(
      a1: "Usage: %s x y z f a d\n"
      "where x,y,z are direction of screen punch\n"
      "      f     is  frequency (1 means three bounces before settling)\n"
      "      a     is  amplitude\n"
      "      d     is  duration\n",
      v2);
  }
  v3 = prType;
  if ( args->m_nArgc > 1 )
    v3 = args->m_ppArgv[1];
  x = atof(nptr: v3);
  v4 = prType;
  if ( args->m_nArgc > 2 )
    v4 = args->m_ppArgv[2];
  y = atof(nptr: v4);
  v5 = prType;
  if ( args->m_nArgc > 3 )
    v5 = args->m_ppArgv[3];
  z = atof(nptr: v5);
  v6 = prType;
  if ( args->m_nArgc > 4 )
    v6 = args->m_ppArgv[4];
  f = atof(nptr: v6);
  v7 = prType;
  if ( args->m_nArgc > 5 )
    v7 = args->m_ppArgv[5];
  a = atof(nptr: v7);
  if ( args->m_nArgc > 6 )
    v8 = args->m_ppArgv[6];
  else
    v8 = prType;
  shake.duration = atof(nptr: v8);
  shake.amplitude = a;
  shake.frequency = f;
  shake.direction.x = x;
  shake.direction.y = y;
  v9 = g_ViewEffects[0].Shake;
  shake.command = SHAKE_START;
  shake.direction.z = z;
  v9(this: g_ViewEffects, a2: &shake);
}

//------------------------------------------------------------------------------
// Address: 0x10191A80
// Name: private: void CViewEffects::CalcShake_Basic(struct screenshake_t __near *,float restrict __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::CalcShake_Basic(CViewEffects *this, screenshake_t *pShake, float *pflRumbleAngle)
{
  float v3; // xmm0_4
  Vector *p_offset; // edi
  __m128 v6; // xmm1
  float v7; // xmm0_4
  float v8; // xmm2_4
  int command; // eax
  double v10; // xmm0_8
  float v11; // xmm0_4
  float z; // xmm3_4
  float v13; // xmm4_4
  float angle; // xmm1_4
  float duration; // [esp+18h] [ebp-8h]
  int fraction; // [esp+28h] [ebp+8h]
  float fractiona; // [esp+28h] [ebp+8h]

  v3 = *(float *)(gpGlobals.m_Index + 12);
  if ( v3 > pShake->nextShake )
  {
    pShake->nextShake = (float)(1.0 / pShake->frequency) + v3;
    p_offset = &pShake->offset;
    for ( fraction = 3; fraction != 0; --fraction )
    {
      p_offset->x = ((double (__thiscall *)(IUniformRandomStream *, unsigned int, _DWORD))random->RandomFloat)(
                      a1: random,
                      a2: LODWORD(pShake->amplitude) ^ (unsigned int)_mask__NegFloat_,
                      a3: LODWORD(pShake->amplitude));
      p_offset = (Vector *)((char *)p_offset + 4);
    }
    pShake->angle = ((double (__stdcall *)(_DWORD, _DWORD))random->RandomFloat)(
                      a1: pShake->amplitude * -0.25,
                      a2: pShake->amplitude * 0.25);
  }
  v6 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
  v7 = (float)(pShake->endtime - v6.m128_f32[0]) / pShake->duration;
  duration = pShake->duration;
  v8 = 0.0;
  if ( v7 != 0.0 )
    v8 = pShake->frequency / v7;
  fractiona = v7 * v7;
  v6.m128_f32[0] = v6.m128_f32[0] * v8;
  if ( v6.m128_f32[0] > 100000000.0 )
    v6 = (__m128)0x4CBEBC20u;
  __libm_sse2_sin(X: (__m128i)_mm_cvtps_pd(v6));
  command = pShake->command;
  *(float *)&v10 = v10;
  v11 = *(float *)&v10 * fractiona;
  if ( command != 5 )
    *pflRumbleAngle = (float)(pShake->angle * v11) + *pflRumbleAngle;
  if ( command != 4 )
  {
    z = pShake->offset.z;
    v13 = this->m_vecShakeAppliedOffset.x + (float)(pShake->offset.x * v11);
    this->m_vecShakeAppliedOffset.y = this->m_vecShakeAppliedOffset.y + (float)(pShake->offset.y * v11);
    this->m_vecShakeAppliedOffset.z = this->m_vecShakeAppliedOffset.z + (float)(z * v11);
    angle = pShake->angle;
    this->m_vecShakeAppliedOffset.x = v13;
    this->m_flShakeAppliedAngle = (float)(angle * v11) + this->m_flShakeAppliedAngle;
  }
  pShake->amplitude = pShake->amplitude
                    - (float)((float)(*(float *)(gpGlobals.m_Index + 16) / (float)(pShake->frequency * duration))
                            * pShake->amplitude);
}

//------------------------------------------------------------------------------
// Address: 0x10191C40
// Name: public: virtual void CViewEffects::ApplyShake(class Vector __near &,class QAngle __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::ApplyShake(CViewEffects *this, Vector *origin, QAngle *angles, float factor)
{
  origin->x = (float)(this->m_vecShakeAppliedOffset.x * factor) + origin->x;
  origin->y = (float)(this->m_vecShakeAppliedOffset.y * factor) + origin->y;
  origin->z = (float)(this->m_vecShakeAppliedOffset.z * factor) + origin->z;
  angles->z = (float)(this->m_flShakeAppliedAngle * factor) + angles->z;
}

//------------------------------------------------------------------------------
// Address: 0x10191CA0
// Name: public: virtual void CViewEffects::ApplyTilt(class QAngle __near &,float)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::ApplyTilt(CViewEffects *this, QAngle *angles, float factor)
{
  QAngle *p_m_vecTiltAppliedAngle; // ecx
  matrix3x4_t matTilt; // [esp+0h] [ebp-C0h] BYREF
  matrix3x4_t matToWorld; // [esp+30h] [ebp-90h] BYREF
  matrix3x4_t matTiltToWorld; // [esp+60h] [ebp-60h] BYREF
  Vector vecUpTilted; // [esp+90h] [ebp-30h] BYREF
  Vector vecForwardTilted; // [esp+9Ch] [ebp-24h] BYREF
  QAngle anglesTilted; // [esp+A8h] [ebp-18h] BYREF
  float in1; // [esp+B4h] [ebp-Ch] BYREF
  int v11; // [esp+B8h] [ebp-8h]
  int v12; // [esp+BCh] [ebp-4h]

  p_m_vecTiltAppliedAngle = &this->m_vecTiltAppliedAngle;
  if ( p_m_vecTiltAppliedAngle->x != 0.0 || p_m_vecTiltAppliedAngle->y != 0.0 || p_m_vecTiltAppliedAngle->z != 0.0 )
  {
    AngleIMatrix(angles: p_m_vecTiltAppliedAngle, matrix: &matTilt);
    AngleMatrix(angles, matrix: &matToWorld);
    ConcatTransforms(in1: &matTilt, in2: &matToWorld, out: &matTiltToWorld);
    in1 = 1.0;
    v11 = 0;
    v12 = 0;
    VectorTransform(&in1, in2: &matTiltToWorld, out: &vecForwardTilted.x);
    in1 = 0.0;
    v11 = 0;
    v12 = 1065353216;
    VectorTransform(&in1, in2: &matTiltToWorld, out: &vecUpTilted.x);
    VectorAngles(forward: &vecForwardTilted, pseudoup: &vecUpTilted, angles: &anglesTilted);
    *angles = anglesTilted;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10191DA0
// Name: public: virtual void CViewEffects::CalcShake(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::CalcShake(CViewEffects *this)
{
  CViewEffects *v1; // edi
  int m_nValue; // eax
  int m_Size; // ebx
  int i; // ebx
  float *p_endtime; // esi
  float v6; // xmm1_4
  bool v7; // zf
  float v8; // xmm3_4
  float v9; // xmm2_4
  float v10; // xmm0_4
  float v11; // xmm1_4
  double v12; // xmm4_8
  __m128 v13; // xmm0
  float v14; // xmm1_4
  __m128d v15; // xmm0
  __m128i v16; // xmm0
  double v17; // xmm0_8
  float v18; // xmm0_4
  float v19; // xmm3_4
  int v20; // eax
  int v21; // eax
  vgui::PropertyPage *v22; // ecx
  con_nprint_s np; // [esp+24h] [ebp-34h] BYREF
  float v24; // [esp+3Ch] [ebp-1Ch]
  float v25; // [esp+40h] [ebp-18h]
  float v26; // [esp+44h] [ebp-14h]
  float v27; // [esp+48h] [ebp-10h]
  float v28; // [esp+4Ch] [ebp-Ch]
  float flRumbleAngle; // [esp+50h] [ebp-8h] BYREF
  bool bShow; // [esp+57h] [ebp-1h]

  v1 = this;
  this->m_vecShakeAppliedOffset.x = 0.0;
  this->m_vecShakeAppliedOffset.y = 0.0;
  this->m_vecShakeAppliedOffset.z = 0.0;
  this->m_flShakeAppliedAngle = 0.0;
  flRumbleAngle = 0.0;
  if ( shake_show.m_pParent != nullptr )
    m_nValue = shake_show.m_pParent->m_Value.m_nValue;
  else
    m_nValue = 0;
  m_Size = this->m_ShakeList.m_Size;
  bShow = m_nValue != 0;
  for ( i = m_Size - 1; i >= 0; --i )
  {
    p_endtime = &v1->m_ShakeList.m_Memory.m_pMemory[i]->endtime;
    v6 = *p_endtime;
    v7 = *p_endtime == 0.0;
    v26 = *p_endtime;
    if ( !v7 )
    {
      this = (CViewEffects *)gpGlobals.m_Index;
      if ( *(float *)(gpGlobals.m_Index + 12) > v6
        || (v28 = p_endtime[1], v8 = v28, v28 <= 0.0)
        || (v24 = p_endtime[2]) <= 0.0
        || (v27 = p_endtime[3], v9 = v27, v27 <= 0.0) )
      {
        C_BaseEntity::operator delete(pMem: p_endtime);
        v21 = v1->m_ShakeList.m_Size;
        if ( v21 > 0 )
        {
          this = (CViewEffects *)(v21 - 1);
          if ( i != v21 - 1 )
          {
            this = (CViewEffects *)v1->m_ShakeList.m_Memory.m_pMemory;
            *((_DWORD *)&this->__vftable + i) = *((_DWORD *)this + v21 - 1);
          }
          --v1->m_ShakeList.m_Size;
        }
      }
      else
      {
        if ( bShow )
        {
          np.time_to_live = 2.0;
          np.color[0] = 1.0;
          np.color[1] = 0.80000001;
          np.color[2] = 0.1;
          np.index = i + 2;
          np.fixed_width_font = true;
          engine->Con_NXPrintf(
            this: engine,
            a2: &np,
            a3: "%02d: dur(%8.2f) amp(%8.2f) freq(%8.2f)",
            i + 1,
            v28,
            v24,
            v27);
          v8 = v28;
          v9 = v27;
          v6 = v26;
        }
        if ( *((_BYTE *)p_endtime + 52) != 0 )
        {
          if ( *((_BYTE *)p_endtime + 52) == 1 )
          {
            v10 = *(float *)(gpGlobals.m_Index + 12);
            v11 = v6 - v10;
            v12 = v10;
            v13 = (__m128)0x3F800000u;
            v13.m128_f32[0] = 1.0 - (float)(v11 / v8);
            v14 = 1.0 - v13.m128_f32[0];
            v15 = _mm_cvtps_pd(v13);
            v15.m128d_f64[0] = v15.m128d_f64[0] * 9.424777960769379;
            v16 = (__m128i)_mm_cvtpd_ps(v15);
            p_endtime[4] = v12 + 0.001;
            v25 = v14;
            *(double *)v16.m128i_i64 = (float)(*(float *)v16.m128i_i32 * v9);
            __libm_sse2_sin(X: v16);
            *(float *)&v17 = v17;
            v18 = *(float *)&v17 * v25;
            v19 = p_endtime[11] * (float)(v24 * v18);
            *(float *)&v12 = p_endtime[12] * (float)(v24 * v18);
            p_endtime[5] = p_endtime[10] * (float)(v24 * v18);
            p_endtime[6] = v19;
            p_endtime[7] = *(float *)&v12;
            v20 = *((_DWORD *)p_endtime + 9);
            if ( v20 != 5 )
              flRumbleAngle = v18 + flRumbleAngle;
            if ( v20 != 4 )
            {
              v1->m_vecShakeAppliedOffset.x = p_endtime[5] + v1->m_vecShakeAppliedOffset.x;
              v1->m_vecShakeAppliedOffset.y = p_endtime[6] + v1->m_vecShakeAppliedOffset.y;
              v1->m_vecShakeAppliedOffset.z = p_endtime[7] + v1->m_vecShakeAppliedOffset.z;
            }
          }
        }
        else
        {
          CViewEffects::CalcShake_Basic(this: v1, pShake: (screenshake_t *)p_endtime, pflRumbleAngle: &flRumbleAngle);
        }
      }
    }
  }
  C_TEBSPDecal::YouForgotToImplementOrDeclareClientClass((vgui::CTreeViewListControl *)this);
  C_BaseAnimating::ShutdownBoneSetupThreadPool(this: v22);
}

//------------------------------------------------------------------------------
// Address: 0x10192050
// Name: public: virtual void CViewEffects::CalcTilt(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::CalcTilt(CViewEffects *this)
{
  __m128 v1; // xmm6
  int v3; // ebx
  __m128 v4; // xmm4
  screentilt_t *v5; // esi
  __m128 endtime_low; // xmm2
  float x; // xmm5_4
  float v8; // xmm1_4
  __m128 v9; // xmm0
  __m128d v10; // xmm0
  __m128i v11; // xmm0
  float v12; // xmm5_4
  float v13; // xmm3_4
  float v14; // xmm0_4
  int m_Size; // eax

  v1 = 0;
  this->m_vecTiltAppliedAngle.x = 0.0;
  this->m_vecTiltAppliedAngle.y = 0.0;
  this->m_vecTiltAppliedAngle.z = 0.0;
  v3 = this->m_TiltList.m_Size - 1;
  if ( v3 >= 0 )
  {
    v4 = (__m128)0x3F800000u;
    do
    {
      v5 = this->m_TiltList.m_Memory.m_pMemory[v3];
      endtime_low = (__m128)LODWORD(v5->endtime);
      if ( endtime_low.m128_f32[0] != v1.m128_f32[0] )
      {
        if ( *(float *)(gpGlobals.m_Index + 12) > endtime_low.m128_f32[0]
          || v1.m128_f32[0] >= v5->duration
          || (x = v5->angle.x, v1.m128_f32[0] == x) && v1.m128_f32[0] == v5->angle.y && v1.m128_f32[0] == v5->angle.z )
        {
          C_BaseEntity::operator delete(pMem: v5);
          m_Size = this->m_TiltList.m_Size;
          if ( m_Size > 0 )
          {
            if ( v3 != m_Size - 1 )
              this->m_TiltList.m_Memory.m_pMemory[v3] = this->m_TiltList.m_Memory.m_pMemory[m_Size - 1];
            --this->m_TiltList.m_Size;
          }
          v1 = 0;
          v4 = (__m128)0x3F800000u;
        }
        else
        {
          v9 = (__m128)*(unsigned int *)(gpGlobals.m_Index + 12);
          v8 = v4.m128_f32[0] / v5->tiltTime;
          v9.m128_f32[0] = (float)(v9.m128_f32[0] - v5->starttime) * v8;
          endtime_low.m128_f32[0] = (float)(endtime_low.m128_f32[0] - *(float *)(gpGlobals.m_Index + 12)) * v8;
          if ( v9.m128_f32[0] > endtime_low.m128_f32[0] )
            v9 = endtime_low;
          if ( v1.m128_f32[0] <= v9.m128_f32[0] )
          {
            if ( v9.m128_f32[0] > v4.m128_f32[0] )
              v9 = v4;
          }
          else
          {
            v9 = v1;
          }
          if ( v5->easeInOut )
          {
            v10 = _mm_cvtps_pd(v9);
            v10.m128d_f64[0] = v10.m128d_f64[0] * 3.141592653589793;
            v11 = (__m128i)_mm_cvtpd_ps(v10);
            *(double *)v11.m128i_i64 = *(float *)v11.m128i_i32;
            __libm_sse2_cos(X: v11);
            v4 = (__m128)0x3F800000u;
            v1 = 0;
            v9.m128_f32[0] = *(double *)v9.m128_u64;
            v9.m128_f32[0] = 1.0 - (float)((float)(v9.m128_f32[0] + 1.0) * 0.5);
          }
          v12 = x * v9.m128_f32[0];
          v13 = v5->angle.z * v9.m128_f32[0];
          this->m_vecTiltAppliedAngle.y = this->m_vecTiltAppliedAngle.y + (float)(v5->angle.y * v9.m128_f32[0]);
          v14 = this->m_vecTiltAppliedAngle.z + v13;
          this->m_vecTiltAppliedAngle.x = v12 + this->m_vecTiltAppliedAngle.x;
          this->m_vecTiltAppliedAngle.z = v14;
        }
      }
      --v3;
    }
    while ( v3 >= 0 );
  }
}

//------------------------------------------------------------------------------
// Address: 0x101921E0
// Name: private: struct screenshake_t __near * CViewEffects::FindLongestShake(void)
// Source: json
//------------------------------------------------------------------------------
screenshake_t *__thiscall CViewEffects::FindLongestShake(CViewEffects *this)
{
  CViewEffects *v1; // edx
  int m_Size; // ebx
  screenshake_t *result; // eax
  int v4; // ecx
  _DWORD *v5; // edx
  unsigned int v6; // edi
  int v7; // esi
  int v8; // esi
  int v9; // esi
  int v10; // edx
  int v11; // esi
  CViewEffects *v12; // [esp+8h] [ebp-4h]

  v1 = this;
  m_Size = this->m_ShakeList.m_Size;
  result = nullptr;
  v4 = 0;
  v12 = v1;
  if ( m_Size >= 4 )
  {
    v5 = v1->m_ShakeList.m_Memory.m_pMemory + 2;
    v6 = ((unsigned int)(m_Size - 4) >> 2) + 1;
    v4 = 4 * v6;
    do
    {
      v7 = *(v5 - 2);
      if ( v7 != 0 && (result == nullptr || *(float *)(v7 + 4) > result->duration) )
        result = (screenshake_t *)*(v5 - 2);
      v8 = *(v5 - 1);
      if ( v8 != 0 && (result == nullptr || *(float *)(v8 + 4) > result->duration) )
        result = (screenshake_t *)*(v5 - 1);
      if ( *v5 != 0 && (result == nullptr || *(float *)(*v5 + 4) > result->duration) )
        result = (screenshake_t *)*v5;
      v9 = v5[1];
      if ( v9 != 0 && (result == nullptr || *(float *)(v9 + 4) > result->duration) )
        result = (screenshake_t *)v5[1];
      v5 += 4;
      --v6;
    }
    while ( v6 != 0 );
    v1 = v12;
  }
  if ( v4 < m_Size )
  {
    v10 = (int)&v1->m_ShakeList.m_Memory.m_pMemory[v4];
    v11 = m_Size - v4;
    do
    {
      if ( *(_DWORD *)v10 != 0 && (result == nullptr || *(float *)(*(_DWORD *)v10 + 4) > result->duration) )
        result = *(screenshake_t **)v10;
      v10 += 4;
      --v11;
    }
    while ( v11 != 0 );
  }
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x101922B0
// Name: public: virtual void CViewEffects::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::Save(CViewEffects *this, ISave *pSave)
{
  void (__thiscall *WriteInt_2)(ISave *, const int *, int); // edx
  int i; // edi
  void (__thiscall *v5)(ISave *, const int *, int); // edx
  int j; // edi
  int iCount; // [esp+Ch] [ebp-4h] BYREF

  WriteInt_2 = pSave->WriteInt_2;
  iCount = this->m_FadeList.m_Size;
  WriteInt_2(this: pSave, a2: &iCount, a3: 1);
  for ( i = 0; i < iCount; ++i )
  {
    pSave->StartBlock(this: pSave);
    pSave->WriteAll(this: pSave, a2: this->m_FadeList.m_Memory.m_pMemory[i], a3: &screenfade_t::m_DataMap);
    pSave->EndBlock(this: pSave);
  }
  v5 = pSave->WriteInt_2;
  iCount = this->m_ShakeList.m_Size;
  v5(this: pSave, a2: &iCount, a3: 1);
  for ( j = 0; j < iCount; ++j )
  {
    pSave->StartBlock(this: pSave);
    pSave->WriteAll(this: pSave, a2: this->m_ShakeList.m_Memory.m_pMemory[j], a3: &screenshake_t::m_DataMap);
    pSave->EndBlock(this: pSave);
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192360
// Name: public: virtual char const __near * CViewEffectsSaveRestoreBlockHandler::GetBlockName(void)
// Source: json
//------------------------------------------------------------------------------
const char *__thiscall CViewEffectsSaveRestoreBlockHandler::GetBlockName(CViewEffectsSaveRestoreBlockHandler *this)
{
  return "ViewEffects";
}

//------------------------------------------------------------------------------
// Address: 0x10192370
// Name: public: virtual void CViewEffectsSaveRestoreBlockHandler::Save(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffectsSaveRestoreBlockHandler::Save(CViewEffectsSaveRestoreBlockHandler *this, ISave *pSave)
{
  g_ViewEffects[0].Save(this: g_ViewEffects, a2: pSave);
}

//------------------------------------------------------------------------------
// Address: 0x10192390
// Name: public: virtual void CViewEffectsSaveRestoreBlockHandler::WriteSaveHeaders(class ISave __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffectsSaveRestoreBlockHandler::WriteSaveHeaders(
        CViewEffectsSaveRestoreBlockHandler *this,
        ISave *pSave)
{
  pSave->WriteShort_2(this: pSave, a2: &VIEWEFFECTS_SAVE_RESTORE_VERSION, a3: 1);
}

//------------------------------------------------------------------------------
// Address: 0x101923B0
// Name: public: virtual void CViewEffectsSaveRestoreBlockHandler::ReadRestoreHeaders(class IRestore __near *)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffectsSaveRestoreBlockHandler::ReadRestoreHeaders(
        CViewEffectsSaveRestoreBlockHandler *this,
        IRestore *pRestore)
{
  this->m_bDoLoad = pRestore->ReadShort_2(this: pRestore) == VIEWEFFECTS_SAVE_RESTORE_VERSION;
}

//------------------------------------------------------------------------------
// Address: 0x101923E0
// Name: public: virtual void CViewEffectsSaveRestoreBlockHandler::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffectsSaveRestoreBlockHandler::Restore(
        CViewEffectsSaveRestoreBlockHandler *this,
        IRestore *pRestore,
        BOOL fCreatePlayers)
{
  if ( this->m_bDoLoad )
    g_ViewEffects[0].Restore(this: g_ViewEffects, a2: pRestore, a3: fCreatePlayers);
}

//------------------------------------------------------------------------------
// Address: 0x10192400
// Name: private: virtual void CViewEffects::ClearAllShakes(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::ClearAllShakes(CViewEffects *this)
{
  int m_Size; // ebx
  int i; // edi
  bool v4; // sf
  screenshake_t **m_pMemory; // ecx

  m_Size = this->m_ShakeList.m_Size;
  for ( i = 0; i < m_Size; ++i )
    C_BaseEntity::operator delete(pMem: this->m_ShakeList.m_Memory.m_pMemory[i]);
  v4 = this->m_ShakeList.m_Memory.m_nGrowSize < 0;
  this->m_ShakeList.m_Size = 0;
  if ( v4 )
  {
    this->m_ShakeList.m_pElements = this->m_ShakeList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_ShakeList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_ShakeList.m_Memory.m_pMemory);
      this->m_ShakeList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_ShakeList.m_Memory.m_pMemory;
    this->m_ShakeList.m_Memory.m_nAllocationCount = 0;
    this->m_ShakeList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192470
// Name: private: void CViewEffects::ClearAllTilts(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::ClearAllTilts(CViewEffects *this)
{
  int m_Size; // ebx
  int i; // edi
  bool v4; // sf
  screentilt_t **m_pMemory; // ecx

  m_Size = this->m_TiltList.m_Size;
  for ( i = 0; i < m_Size; ++i )
    C_BaseEntity::operator delete(pMem: this->m_TiltList.m_Memory.m_pMemory[i]);
  v4 = this->m_TiltList.m_Memory.m_nGrowSize < 0;
  this->m_TiltList.m_Size = 0;
  if ( v4 )
  {
    this->m_TiltList.m_pElements = this->m_TiltList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_TiltList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_TiltList.m_Memory.m_pMemory);
      this->m_TiltList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_TiltList.m_Memory.m_pMemory;
    this->m_TiltList.m_Memory.m_nAllocationCount = 0;
    this->m_TiltList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101924E0
// Name: public: virtual void CViewEffects::FadeCalculate(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::FadeCalculate(CViewEffects *this)
{
  int i; // ebx
  screenfade_t *v3; // edi
  bool v4; // zf
  float v5; // xmm0_4
  int v6; // edi
  screenfade_t **m_pMemory; // eax
  int v8; // ecx
  int v9; // ebx
  screenfade_t *v10; // eax
  int Flags; // ecx
  int alpha; // edx
  int v13; // ecx
  int m_Size; // ecx
  int v15; // [esp+Ch] [ebp-10h]
  screenfade_t *pFade; // [esp+10h] [ebp-Ch] BYREF
  int v17; // [esp+14h] [ebp-8h]
  screenfade_t **v18; // [esp+18h] [ebp-4h]

  for ( i = this->m_FadeList.m_Size - 1; i >= 0; --i )
  {
    v3 = this->m_FadeList.m_Memory.m_pMemory[i];
    v4 = (v3->Flags & 8) == 0;
    pFade = v3;
    if ( !v4 )
      v3->Reset = *(float *)(gpGlobals.m_Index + 12) + 0.1;
    v5 = *(float *)(gpGlobals.m_Index + 12);
    if ( v5 > v3->Reset && v5 > v3->End )
    {
      if ( s_pfnFadeDoneCallback != nullptr )
      {
        s_pfnFadeDoneCallback(a1: s_nCallbackParameter);
        s_pfnFadeDoneCallback = nullptr;
        s_nCallbackParameter = 0;
      }
      CUtlVector<C_BaseParticleEntity *,CUtlMemory<C_BaseParticleEntity *,int>>::FindAndRemove(
        this: (CUtlVector<vgui::TreeNode *,CUtlMemory<vgui::TreeNode *,int> > *)&this->m_FadeList,
        src: (vgui::TreeNode **)&pFade);
      C_BaseEntity::operator delete(pMem: v3);
    }
  }
  v6 = 0;
  this->m_bModulate = false;
  this->m_FadeColorRGBA[3] = 0;
  this->m_FadeColorRGBA[2] = 0;
  this->m_FadeColorRGBA[1] = 0;
  this->m_FadeColorRGBA[0] = 0;
  pFade = nullptr;
  if ( this->m_FadeList.m_Size > 0 )
  {
    m_pMemory = this->m_FadeList.m_Memory.m_pMemory;
    v8 = 0;
    v17 = 0;
    v9 = 0;
    v18 = m_pMemory;
    while ( 1 )
    {
      v10 = *v18;
      v6 += (*v18)->r;
      this->m_FadeColorRGBA[0] = v6;
      v9 += v10->g;
      this->m_FadeColorRGBA[1] = v9;
      v15 = v10->b + v8;
      this->m_FadeColorRGBA[2] = v15;
      Flags = v10->Flags;
      if ( (Flags & 3) != 0 )
      {
        alpha = (int)(float)((float)(v10->End - *(float *)(gpGlobals.m_Index + 12)) * v10->Speed);
        if ( (Flags & 2) != 0 )
          alpha += v10->alpha;
        if ( alpha >= v10->alpha )
          alpha = v10->alpha;
        v13 = alpha < 0 ? 0 : alpha;
      }
      else
      {
        v13 = v10->alpha;
      }
      if ( v13 > v17 )
      {
        v17 = v13;
        this->m_FadeColorRGBA[3] = v13;
      }
      if ( (v10->Flags & 4) != 0 )
        this->m_bModulate = true;
      ++v18;
      pFade = (screenfade_t *)((char *)pFade + 1);
      if ( (int)pFade >= this->m_FadeList.m_Size )
        break;
      v8 = v15;
    }
  }
  m_Size = this->m_FadeList.m_Size;
  if ( m_Size != 0 )
  {
    this->m_FadeColorRGBA[0] /= m_Size;
    this->m_FadeColorRGBA[1] /= m_Size;
    this->m_FadeColorRGBA[2] /= m_Size;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192660
// Name: public: virtual void CViewEffects::ClearPermanentFades(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::ClearPermanentFades(CViewEffects *this)
{
  int v2; // eax
  screenfade_t *v3; // ebx
  int m_Size; // ecx
  int v5; // eax
  screenfade_t **m_pMemory; // edx
  int v7; // ecx
  int i; // [esp+4h] [ebp-4h]

  v2 = this->m_FadeList.m_Size - 1;
  for ( i = v2; v2 >= 0; i = v2 )
  {
    v3 = this->m_FadeList.m_Memory.m_pMemory[v2];
    if ( (v3->Flags & 8) != 0 )
    {
      m_Size = this->m_FadeList.m_Size;
      v5 = 0;
      if ( m_Size > 0 )
      {
        m_pMemory = this->m_FadeList.m_Memory.m_pMemory;
        while ( *m_pMemory != v3 )
        {
          ++v5;
          ++m_pMemory;
          if ( v5 >= m_Size )
            goto LABEL_12;
        }
        if ( v5 != -1 )
        {
          v7 = m_Size - v5 - 1;
          if ( v7 > 0 )
            _V_memmove(
              dest: (unsigned __int8 *)&this->m_FadeList.m_Memory.m_pMemory[v5],
              src: (unsigned __int8 *)&this->m_FadeList.m_Memory.m_pMemory[v5 + 1],
              count: 4 * v7);
          --this->m_FadeList.m_Size;
        }
      }
LABEL_12:
      C_BaseEntity::operator delete(pMem: v3);
      v2 = i;
    }
    --v2;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101926E0
// Name: public: virtual void CViewEffects::ClearAllFades(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::ClearAllFades(CViewEffects *this)
{
  int i; // edi
  screenfade_t **m_pMemory; // ecx

  for ( i = this->m_FadeList.m_Size - 1; i >= 0; --i )
    C_BaseEntity::operator delete(pMem: this->m_FadeList.m_Memory.m_pMemory[i]);
  this->m_FadeList.m_Size = 0;
  if ( this->m_FadeList.m_Memory.m_nGrowSize < 0 )
  {
    this->m_FadeList.m_pElements = this->m_FadeList.m_Memory.m_pMemory;
  }
  else
  {
    if ( this->m_FadeList.m_Memory.m_pMemory != nullptr )
    {
      _g_pMemAlloc->Free_2(this: _g_pMemAlloc, a2: this->m_FadeList.m_Memory.m_pMemory);
      this->m_FadeList.m_Memory.m_pMemory = nullptr;
    }
    m_pMemory = this->m_FadeList.m_Memory.m_pMemory;
    this->m_FadeList.m_Memory.m_nAllocationCount = 0;
    this->m_FadeList.m_pElements = m_pMemory;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192740
// Name: public: virtual void CViewEffects::LevelInit(void)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::LevelInit(CViewEffects *this)
{
  this->ClearAllShakes(this);
  CViewEffects::ClearAllTilts(this);
  this->ClearAllFades(this);
}

//------------------------------------------------------------------------------
// Address: 0x10192760
// Name: public: virtual void CViewEffects::Shake(struct ScreenShake_t const __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::Shake(CViewEffects *this, const ScreenShake_t *data)
{
  ShakeCommand_t command; // eax
  float *v4; // eax
  float *v5; // edi
  bool v6; // zf
  unsigned int m_Index; // eax
  float duration; // xmm0_4
  ShakeCommand_t v9; // ecx
  double x; // st7
  float v11; // xmm1_4
  bool v12; // al
  CUtlMemory<vgui::TreeNode *,int> *p_m_ShakeList; // esi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v17; // eax
  vgui::TreeNode **v18; // ebx
  screenshake_t *LongestShake; // eax
  screenshake_t *v20; // eax

  command = data->command;
  if ( data->command != SHAKE_START && command != SHAKE_START_RUMBLEONLY || this->m_ShakeList.m_Size >= 32 )
  {
    switch ( command )
    {
      case SHAKE_STOP:
        this->ClearAllShakes(this);
        break;
      case SHAKE_AMPLITUDE:
        LongestShake = CViewEffects::FindLongestShake(this);
        if ( LongestShake != nullptr )
          LongestShake->amplitude = data->amplitude;
        break;
      case SHAKE_FREQUENCY:
        v20 = CViewEffects::FindLongestShake(this);
        if ( v20 != nullptr )
          v20->frequency = data->frequency;
        break;
      default:
        break;
    }
  }
  else
  {
    v4 = (float *)MemAlloc_Alloc(nSize: 0x38u);
    if ( v4 != nullptr )
    {
      *((_BYTE *)v4 + 52) = 0;
      v5 = v4;
    }
    else
    {
      v5 = nullptr;
    }
    v6 = LODWORD(data->direction.x) == 0;
    v5[2] = data->amplitude;
    m_Index = gpGlobals.m_Index;
    duration = data->duration;
    v5[3] = data->frequency;
    v9 = data->command;
    x = data->direction.x;
    v5[4] = 0.0;
    v11 = *(float *)(m_Index + 12);
    v5[1] = duration;
    *((_DWORD *)v5 + 9) = v9;
    *v5 = v11 + duration;
    v5[10] = x;
    v5[11] = data->direction.y;
    v5[12] = data->direction.z;
    v12 = v6 && LODWORD(data->direction.y) == 0 && LODWORD(data->direction.z) == 0;
    p_m_ShakeList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ShakeList;
    m_Size = this->m_ShakeList.m_Size;
    v6 = !v12;
    m_nAllocationCount = p_m_ShakeList->m_nAllocationCount;
    *((_BYTE *)v5 + 52) = v6;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_ShakeList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_ShakeList[1].m_pMemory;
    m_pMemory = p_m_ShakeList->m_pMemory;
    v17 = (int)p_m_ShakeList[1].m_pMemory - m_Size - 1;
    p_m_ShakeList[1].m_nAllocationCount = (int)p_m_ShakeList->m_pMemory;
    if ( v17 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v17);
    v18 = &p_m_ShakeList->m_pMemory[m_Size];
    if ( v18 != nullptr )
      *v18 = (vgui::TreeNode *)v5;
  }
}

//------------------------------------------------------------------------------
// Address: 0x101928B0
// Name: public: virtual void CViewEffects::Tilt(struct ScreenTilt_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::Tilt(CViewEffects *this, ScreenTilt_t *data)
{
  int command; // eax
  bool *v4; // esi
  float v5; // xmm0_4
  CUtlMemory<vgui::TreeNode *,int> *p_m_TiltList; // edi
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  vgui::TreeNode **m_pMemory; // ecx
  int v10; // eax
  vgui::TreeNode **v11; // ebx

  command = data->command;
  if ( data->command != 0 && command != 4 || this->m_ShakeList.m_Size >= 32 )
  {
    if ( command == 1 )
      CViewEffects::ClearAllTilts(this);
  }
  else
  {
    v4 = (bool *)MemAlloc_Alloc(nSize: 0x30u);
    *v4 = data->easeInOut;
    *(QAngle *)(v4 + 4) = data->angle;
    *((float *)v4 + 6) = data->duration;
    *((float *)v4 + 7) = data->time;
    v5 = *(float *)(gpGlobals.m_Index + 12);
    *((float *)v4 + 4) = v5;
    *((float *)v4 + 5) = v5 + data->duration;
    p_m_TiltList = (CUtlMemory<vgui::TreeNode *,int> *)&this->m_TiltList;
    *((_DWORD *)v4 + 11) = data->command;
    m_Size = this->m_TiltList.m_Size;
    m_nAllocationCount = p_m_TiltList->m_nAllocationCount;
    if ( m_Size + 1 > m_nAllocationCount )
      CUtlMemory<CChoreoActor *,int>::Grow(this: p_m_TiltList, num: m_Size - m_nAllocationCount + 1);
    ++p_m_TiltList[1].m_pMemory;
    m_pMemory = p_m_TiltList->m_pMemory;
    v10 = (int)p_m_TiltList[1].m_pMemory - m_Size - 1;
    p_m_TiltList[1].m_nAllocationCount = (int)p_m_TiltList->m_pMemory;
    if ( v10 > 0 )
      _V_memmove(
        dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
        src: (unsigned __int8 *)&m_pMemory[m_Size],
        count: 4 * v10);
    v11 = &p_m_TiltList->m_pMemory[m_Size];
    if ( v11 != nullptr )
      *v11 = (vgui::TreeNode *)v4;
  }
}

//------------------------------------------------------------------------------
// Address: 0x10192990
// Name: public: virtual void CViewEffects::Fade(struct ScreenFade_t __near &)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::Fade(CViewEffects *this, ScreenFade_t *data)
{
  float *v3; // eax
  screenfade_t *v4; // edi
  unsigned __int8 a; // dl
  float v6; // xmm1_4
  float v7; // xmm0_4
  float v8; // xmm0_4
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  screenfade_t **m_pMemory; // ecx
  int v12; // eax
  screenfade_t **v13; // ebx

  v3 = (float *)MemAlloc_Alloc(nSize: 0x14u);
  v4 = (screenfade_t *)v3;
  v3[1] = (float)data->duration * 0.001953125;
  v3[2] = (float)data->holdTime * 0.001953125;
  *((_BYTE *)v3 + 12) = data->r;
  *((_BYTE *)v3 + 13) = data->g;
  *((_BYTE *)v3 + 14) = data->b;
  a = data->a;
  *((_BYTE *)v3 + 15) = a;
  *((_DWORD *)v3 + 4) = data->fadeFlags;
  *v3 = 0.0;
  if ( data->duration != 0 )
  {
    v6 = v3[1];
    if ( (data->fadeFlags & 2) != 0 )
    {
      if ( v6 != 0.0 )
        *(_DWORD *)v3 = COERCE_UNSIGNED_INT((float)a / v6) ^ _mask__NegFloat_;
      v7 = *(float *)(gpGlobals.m_Index + 12) + v3[1];
      v3[1] = v7;
      v3[2] = v7 + v3[2];
    }
    else
    {
      if ( v6 != 0.0 )
        *v3 = (float)*((unsigned __int8 *)v3 + 15) / v6;
      v8 = *(float *)(gpGlobals.m_Index + 12) + v3[2];
      v3[2] = v8;
      v3[1] = v8 + v3[1];
    }
  }
  if ( (data->fadeFlags & 0x10) != 0 )
    this->ClearAllFades(this);
  m_Size = this->m_FadeList.m_Size;
  m_nAllocationCount = this->m_FadeList.m_Memory.m_nAllocationCount;
  if ( m_Size + 1 > m_nAllocationCount )
    CUtlMemory<CChoreoActor *,int>::Grow(
      this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FadeList,
      num: m_Size - m_nAllocationCount + 1);
  ++this->m_FadeList.m_Size;
  m_pMemory = this->m_FadeList.m_Memory.m_pMemory;
  v12 = this->m_FadeList.m_Size - m_Size - 1;
  this->m_FadeList.m_pElements = m_pMemory;
  if ( v12 > 0 )
    _V_memmove(
      dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
      src: (unsigned __int8 *)&m_pMemory[m_Size],
      count: 4 * v12);
  v13 = &this->m_FadeList.m_Memory.m_pMemory[m_Size];
  if ( v13 != nullptr )
    *v13 = v4;
}

//------------------------------------------------------------------------------
// Address: 0x10192B00
// Name: public: virtual void CViewEffects::Restore(class IRestore __near *,bool)
// Source: json
//------------------------------------------------------------------------------
void __thiscall CViewEffects::Restore(CViewEffects *this, IRestore *pRestore, bool fCreatePlayers)
{
  int v5; // eax
  int m_Size; // ebx
  int m_nAllocationCount; // eax
  screenfade_t **m_pMemory; // ecx
  int v9; // eax
  screenfade_t **v10; // ebx
  int v11; // eax
  screenshake_t *v12; // eax
  int v13; // ebx
  int v14; // eax
  screenshake_t **v15; // ecx
  int v16; // eax
  screenshake_t **v17; // ebx
  screenfade_t *pNewFade; // [esp+Ch] [ebp-4h]
  screenfade_t *pNewFadea; // [esp+Ch] [ebp-4h]
  screenshake_t *pNewShake; // [esp+18h] [ebp+8h]
  screenshake_t *pNewShakea; // [esp+18h] [ebp+8h]

  if ( pRestore->GetGameSaveRestoreInfo(this: pRestore)->levelInfo.fUseLandmark == 0 )
  {
    this->ClearAllFades(this);
    this->ClearAllShakes(this);
    v5 = pRestore->ReadInt(this: pRestore);
    if ( v5 > 0 )
    {
      for ( pNewShake = (screenshake_t *)v5; pNewShake != nullptr; pNewShake = (screenshake_t *)((char *)pNewShake - 1) )
      {
        pNewFade = (screenfade_t *)MemAlloc_Alloc(nSize: 0x14u);
        pRestore->StartBlock(this: pRestore);
        pRestore->ReadAll(this: pRestore, a2: pNewFade, a3: &screenfade_t::m_DataMap);
        pRestore->EndBlock(this: pRestore);
        m_Size = this->m_FadeList.m_Size;
        m_nAllocationCount = this->m_FadeList.m_Memory.m_nAllocationCount;
        if ( m_Size + 1 > m_nAllocationCount )
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_FadeList,
            num: m_Size - m_nAllocationCount + 1);
        ++this->m_FadeList.m_Size;
        m_pMemory = this->m_FadeList.m_Memory.m_pMemory;
        v9 = this->m_FadeList.m_Size - m_Size - 1;
        this->m_FadeList.m_pElements = m_pMemory;
        if ( v9 > 0 )
          _V_memmove(
            dest: (unsigned __int8 *)&m_pMemory[m_Size + 1],
            src: (unsigned __int8 *)&m_pMemory[m_Size],
            count: 4 * v9);
        v10 = &this->m_FadeList.m_Memory.m_pMemory[m_Size];
        if ( v10 != nullptr )
          *v10 = pNewFade;
      }
    }
    v11 = pRestore->ReadInt(this: pRestore);
    if ( v11 > 0 )
    {
      for ( pNewFadea = (screenfade_t *)v11; pNewFadea != nullptr; pNewFadea = (screenfade_t *)((char *)pNewFadea - 1) )
      {
        v12 = (screenshake_t *)MemAlloc_Alloc(nSize: 0x38u);
        if ( v12 != nullptr )
        {
          v12->nShakeType = 0;
          pNewShakea = v12;
        }
        else
        {
          pNewShakea = nullptr;
        }
        pRestore->StartBlock(this: pRestore);
        pRestore->ReadAll(this: pRestore, a2: pNewShakea, a3: &screenshake_t::m_DataMap);
        pRestore->EndBlock(this: pRestore);
        v13 = this->m_ShakeList.m_Size;
        v14 = this->m_ShakeList.m_Memory.m_nAllocationCount;
        if ( v13 + 1 > v14 )
          CUtlMemory<CChoreoActor *,int>::Grow(
            this: (CUtlMemory<vgui::TreeNode *,int> *)&this->m_ShakeList,
            num: v13 - v14 + 1);
        ++this->m_ShakeList.m_Size;
        v15 = this->m_ShakeList.m_Memory.m_pMemory;
        v16 = this->m_ShakeList.m_Size - v13 - 1;
        this->m_ShakeList.m_pElements = v15;
        if ( v16 > 0 )
          _V_memmove(dest: (unsigned __int8 *)&v15[v13 + 1], src: (unsigned __int8 *)&v15[v13], count: 4 * v16);
        v17 = &this->m_ShakeList.m_Memory.m_pMemory[v13];
        if ( v17 != nullptr )
          *v17 = pNewShakea;
      }
    }
  }
}

//------------------------------------------------------------------------------
// Address: 0x1041DF50
// Name: screenfade_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *screenfade_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<screenfade_t>();
  screenfade_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DF60
// Name: screenshake_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *screenshake_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<screenshake_t>();
  screenshake_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DF70
// Name: screentilt_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__
// Source: json
//------------------------------------------------------------------------------
datamap_t *screentilt_t_DataDescInit::_dynamic_initializer_for__g_DataMapHolder__()
{
  datamap_t *result; // eax

  result = DataMapInit<screentilt_t>();
  screentilt_t_DataDescInit::g_DataMapHolder = result;
  return result;
}

//------------------------------------------------------------------------------
// Address: 0x1041DF80
// Name: _dynamic_initializer_for__g_ViewEffects__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_ViewEffects__()
{
  g_ViewEffects[0].__vftable = (CViewEffects_vtbl *)&CViewEffects::`vftable';
  dword_10653D6C = 0;
  dword_10653D70 = 0;
  dword_10653D74 = 0;
  dword_10653D78 = 0;
  dword_10653D7C = 0;
  dword_10653D80 = 0;
  dword_10653D84 = 0;
  dword_10653D88 = 0;
  dword_10653D8C = 0;
  dword_10653D90 = 0;
  dword_10653DA4 = 0;
  dword_10653DA8 = 0;
  dword_10653DAC = 0;
  dword_10653DB0 = 0;
  dword_10653DB4 = 0;
  return atexit(func: dynamic_atexit_destructor_for__g_ViewEffects__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E000
// Name: _dynamic_initializer_for__shake_show__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__shake_show__()
{
  ConVar::ConVar(
    this: &shake_show,
    pName: "shake_show",
    pDefaultValue: "0",
    flags: 0,
    pHelpString: "Displays a list of the active screen shakes.");
  return atexit(func: dynamic_atexit_destructor_for__shake_show__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E030
// Name: _dynamic_initializer_for__shake_stop__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__shake_stop__()
{
  ConCommand::ConCommand(
    this: &shake_stop,
    pName: "shake_stop",
    callback: CC_Shake_Stop,
    pHelpString: "Stops all active screen shakes.\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__shake_stop__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E060
// Name: _dynamic_initializer_for__shake_testpunch__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__shake_testpunch__()
{
  ConCommand::ConCommand(
    this: &shake_testpunch,
    pName: "shake_testpunch",
    callback: (void (__cdecl *)())CC_Shake_TestPunch,
    pHelpString: "Test a punch-style screen shake.\n",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__shake_testpunch__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E090
// Name: _dynamic_initializer_for__r_updaterefracttexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_updaterefracttexture__()
{
  ConVar::ConVar(this: &r_updaterefracttexture, pName: "r_updaterefracttexture", pDefaultValue: "1", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__r_updaterefracttexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E0C0
// Name: _dynamic_initializer_for__r_depthoverlay__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_depthoverlay__()
{
  ConVar::ConVar(
    this: &r_depthoverlay,
    pName: "r_depthoverlay",
    pDefaultValue: "0",
    flags: 0x4000,
    pHelpString: "Replaces opaque objects with their grayscaled depth values. r_showz_power scales the output.");
  return atexit(func: dynamic_atexit_destructor_for__r_depthoverlay__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E0F0
// Name: _dynamic_initializer_for__viewanim_create_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewanim_create_command__()
{
  ConCommand::ConCommand(
    this: &viewanim_create_command,
    pName: "viewanim_create",
    callback: (void (__cdecl *)())viewanim_create,
    pHelpString: "viewanim_create",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__viewanim_create_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E120
// Name: _dynamic_initializer_for__viewanim_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewanim_test__()
{
  ConCommand::ConCommand(
    this: &viewanim_test,
    pName: "viewanim_test",
    callback: TestViewAnim,
    pHelpString: "test view animation",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__viewanim_test__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E150
// Name: _dynamic_initializer_for__viewanim_reset__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewanim_reset__()
{
  ConCommand::ConCommand(
    this: &viewanim_reset,
    pName: "viewanim_reset",
    callback: ResetViewAngles,
    pHelpString: "reset view angles!",
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__viewanim_reset__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E180
// Name: _dynamic_initializer_for__viewanim_addkeyframe_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewanim_addkeyframe_command__()
{
  ConCommand::ConCommand(
    this: &viewanim_addkeyframe_command,
    pName: "viewanim_addkeyframe",
    callback: (void (__cdecl *)())viewanim_addkeyframe,
    pHelpString: prType,
    flags: 0x4000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__viewanim_addkeyframe_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E1B0
// Name: _dynamic_initializer_for__viewanim_save_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewanim_save_command__()
{
  ConCommand::ConCommand(
    this: &viewanim_save_command,
    pName: "viewanim_save",
    callback: (void (__cdecl *)())viewanim_save,
    pHelpString: "Save current animation to file",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__viewanim_save_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E1E0
// Name: _dynamic_initializer_for__viewanim_load_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__viewanim_load_command__()
{
  ConCommand::ConCommand(
    this: &viewanim_load_command,
    pName: "viewanim_load",
    callback: (void (__cdecl *)())viewanim_load,
    pHelpString: "load animation from file",
    flags: 0,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__viewanim_load_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E210
// Name: _dynamic_initializer_for__g_CviewangleanimFoo__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__g_CviewangleanimFoo__()
{
  CClassMap *ClassMap; // eax

  ClassMap = GetClassMap();
  return ((int (__thiscall *)(CClassMap *, const char *, const char *, int, CViewAngleAnimation *(__cdecl *)()))ClassMap->Add)(
           a1: ClassMap,
           a2: "viewangleanim",
           a3: "CViewAngleAnimation",
           a4: 2480,
           a5: CCViewAngleAnimationFactory);
}

//------------------------------------------------------------------------------
// Address: 0x1041E240
// Name: _dynamic_initializer_for__cl_drawmaterial__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_drawmaterial__()
{
  ConVar::ConVar(
    this: &cl_drawmaterial,
    pName: "cl_drawmaterial",
    pDefaultValue: prType,
    flags: 0x4000,
    pHelpString: "Draw a particular material over the frame");
  return atexit(func: dynamic_atexit_destructor_for__cl_drawmaterial__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E270
// Name: _dynamic_initializer_for__mat_showwatertextures__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_showwatertextures__()
{
  ConVar::ConVar(this: &mat_showwatertextures, pName: "mat_showwatertextures", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_showwatertextures__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E2A0
// Name: _dynamic_initializer_for__mat_wateroverlaysize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_wateroverlaysize__()
{
  ConVar::ConVar(this: &mat_wateroverlaysize, pName: "mat_wateroverlaysize", pDefaultValue: "128", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_wateroverlaysize__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E2D0
// Name: _dynamic_initializer_for__mat_showframebuffertexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_showframebuffertexture__()
{
  ConVar::ConVar(
    this: &mat_showframebuffertexture,
    pName: "mat_showframebuffertexture",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_showframebuffertexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E300
// Name: _dynamic_initializer_for__mat_framebuffercopyoverlaysize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_framebuffercopyoverlaysize__()
{
  ConVar::ConVar(
    this: &mat_framebuffercopyoverlaysize,
    pName: "mat_framebuffercopyoverlaysize",
    pDefaultValue: "128",
    flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_framebuffercopyoverlaysize__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E330
// Name: _dynamic_initializer_for__mat_showcamerarendertarget__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_showcamerarendertarget__()
{
  ConVar::ConVar(
    this: &mat_showcamerarendertarget,
    pName: "mat_showcamerarendertarget",
    pDefaultValue: "0",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_showcamerarendertarget__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E360
// Name: _dynamic_initializer_for__mat_camerarendertargetoverlaysize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_camerarendertargetoverlaysize__()
{
  ConVar::ConVar(
    this: &mat_camerarendertargetoverlaysize,
    pName: "mat_camerarendertargetoverlaysize",
    pDefaultValue: "128",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_camerarendertargetoverlaysize__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E390
// Name: _dynamic_initializer_for__mat_hsv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_hsv__()
{
  ConVar::ConVar(this: &mat_hsv, pName: "mat_hsv", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_hsv__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3C0
// Name: _dynamic_initializer_for__mat_yuv__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_yuv__()
{
  ConVar::ConVar(this: &mat_yuv, pName: "mat_yuv", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_yuv__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E3F0
// Name: _dynamic_initializer_for__cl_overdraw_test__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_overdraw_test__()
{
  ConVar::ConVar(this: &cl_overdraw_test, pName: "cl_overdraw_test", pDefaultValue: "0", flags: 20480);
  return atexit(func: dynamic_atexit_destructor_for__cl_overdraw_test__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E420
// Name: _dynamic_initializer_for__mat_drawTexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_drawTexture__()
{
  ConVar::ConVar(
    this: &mat_drawTexture,
    pName: "mat_drawTexture",
    pDefaultValue: prType,
    flags: 0,
    pHelpString: "Enable debug view texture");
  return atexit(func: dynamic_atexit_destructor_for__mat_drawTexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E450
// Name: _dynamic_initializer_for__mat_drawTextureScale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_drawTextureScale__()
{
  ConVar::ConVar(
    this: &mat_drawTextureScale,
    pName: "mat_drawTextureScale",
    pDefaultValue: "1.0",
    flags: 0,
    pHelpString: "Debug view texture scale");
  return atexit(func: dynamic_atexit_destructor_for__mat_drawTextureScale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E480
// Name: _dynamic_initializer_for__mat_wireframe__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_wireframe__()
{
  ConVar::ConVar(this: &mat_wireframe, pName: "mat_wireframe", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_wireframe__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E4B0
// Name: _dynamic_initializer_for__mat_showlightmappage__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_showlightmappage__()
{
  ConVar::ConVar(this: &mat_showlightmappage, pName: "mat_showlightmappage", pDefaultValue: "-1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_showlightmappage__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E4E0
// Name: _dynamic_initializer_for__cl_drawshadowtexture__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_drawshadowtexture__()
{
  ConVar::ConVar(this: &cl_drawshadowtexture, pName: "cl_drawshadowtexture", pDefaultValue: "0", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_drawshadowtexture__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E510
// Name: _dynamic_initializer_for__cl_shadowtextureoverlaysize__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__cl_shadowtextureoverlaysize__()
{
  ConVar::ConVar(
    this: &cl_shadowtextureoverlaysize,
    pName: "cl_shadowtextureoverlaysize",
    pDefaultValue: "256",
    flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__cl_shadowtextureoverlaysize__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E540
// Name: _dynamic_initializer_for__r_flashlightdrawdepth__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_flashlightdrawdepth__()
{
  ConVar::ConVar(this: &r_flashlightdrawdepth, pName: "r_flashlightdrawdepth", pDefaultValue: "0", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__r_flashlightdrawdepth__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E570
// Name: _dynamic_initializer_for__r_screenoverlay_command__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__r_screenoverlay_command__()
{
  ConCommand::ConCommand(
    this: &r_screenoverlay_command,
    pName: "r_screenoverlay",
    callback: (void (__cdecl *)())r_screenoverlay,
    pHelpString: "Draw specified material as an overlay",
    flags: (int)&loc_10004000,
    completionFunc: nullptr);
  return atexit(func: dynamic_atexit_destructor_for__r_screenoverlay_command__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E5A0
// Name: _dynamic_initializer_for__mat_bloomscale__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_bloomscale__()
{
  ConVar::ConVar(this: &mat_bloomscale, pName: "mat_bloomscale", pDefaultValue: "1", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_bloomscale__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E5D0
// Name: _dynamic_initializer_for__mat_hdr_level__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_hdr_level__()
{
  ConVar::ConVar(this: &mat_hdr_level, pName: "mat_hdr_level", pDefaultValue: "2", flags: 0);
  return atexit(func: dynamic_atexit_destructor_for__mat_hdr_level__);
}

//------------------------------------------------------------------------------
// Address: 0x1041E600
// Name: _dynamic_initializer_for__mat_bloomamount_rate__
// Source: linker_block_proximity
//------------------------------------------------------------------------------
int dynamic_initializer_for__mat_bloomamount_rate__()
{
  ConVar::ConVar(this: &mat_bloomamount_rate, pName: "mat_bloomamount_rate", pDefaultValue: "0.05f", flags: 0x4000);
  return atexit(func: dynamic_atexit_destructor_for__mat_bloomamount_rate__);
}
