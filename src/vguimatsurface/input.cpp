// ============================================================
// Auto-decompiled by IDA Pro 9.4
// Original: vguimatsurface/input.cpp
// Functions: 1
// ============================================================

#include <cstdint>
#include <cstddef>

//------------------------------------------------------------------------------
// Address: 0x100039F0
// Name: bool InputHandleInputEvent(struct InputContextHandle_t__ __near *,struct InputEvent_t const __near &)
// Source: json
//------------------------------------------------------------------------------
bool __cdecl InputHandleInputEvent(InputContextHandle_t__ *hContext, const InputEvent_t *event)
{
  ButtonCode_t m_nData2; // eax
  bool result; // al
  ButtonCode_t v4; // eax
  ButtonCode_t v5; // eax
  int m_nData; // ecx

  switch ( event->m_nType )
  {
    case 0:
      m_nData2 = event->m_nData2;
      if ( (unsigned int)m_nData2 <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(m_nData2 - 114) <= 0xBF )
      {
        result = g_pIInput->InternalKeyCodePressed(this: g_pIInput, a2: m_nData2);
      }
      else
      {
        if ( (unsigned int)(m_nData2 - 107) > 6 )
          goto LABEL_40;
        result = g_pIInput->InternalMousePressed(this: g_pIInput, a2: m_nData2);
      }
      break;
    case 1:
      v4 = event->m_nData2;
      if ( (unsigned int)v4 <= KEY_SCROLLLOCKTOGGLE || (unsigned int)(v4 - 114) <= 0xBF )
      {
        result = g_pIInput->InternalKeyCodeReleased(this: g_pIInput, a2: v4);
      }
      else
      {
        if ( (unsigned int)(v4 - 107) > 6 )
          goto LABEL_40;
        result = g_pIInput->InternalMouseReleased(this: g_pIInput, a2: v4);
      }
      break;
    case 2:
      v5 = event->m_nData2;
      if ( (unsigned int)(v5 - 107) > 6 )
        goto LABEL_40;
      result = g_pIInput->InternalMouseDoublePressed(this: g_pIInput, a2: v5);
      break;
    case 3:
      m_nData = event->m_nData;
      switch ( m_nData )
      {
        case 3:
          result = g_pIInput->InternalMouseWheeled(this: g_pIInput, a2: event->m_nData3);
          break;
        case 2:
          result = g_pIInput->InternalCursorMoved(this: g_pIInput, a2: event->m_nData2, a3: event->m_nData3);
          break;
        case 4:
          result = g_pIInput->InternalJoystickMoved(this: g_pIInput, a2: 0, a3: event->m_nData2);
          break;
        case 5:
          result = g_pIInput->InternalJoystickMoved(this: g_pIInput, a2: 1, a3: event->m_nData2);
          break;
        case 8:
          result = g_pIInput->InternalJoystickMoved(this: g_pIInput, a2: 2, a3: event->m_nData2);
          break;
        case 7:
          result = g_pIInput->InternalJoystickMoved(this: g_pIInput, a2: 3, a3: event->m_nData2);
          break;
        default:
          goto LABEL_40;
      }
      break;
    case 0x64:
    case 0x67:
      g_pVGui->Stop(this: g_pVGui);
      result = true;
      break;
    case 0xC8:
      g_pIInput->InternalCursorMoved(this: g_pIInput, a2: event->m_nData, a3: event->m_nData2);
      result = true;
      break;
    case 0xC9:
      ActivateCurrentCursor(hContext);
      result = true;
      break;
    case 0xCA:
      ((void (__stdcall *)(_DWORD))g_pIInput->InternalKeyTyped)(a1: LOWORD(event->m_nData));
      result = true;
      break;
    case 0xCB:
      g_pIInput->InternalKeyCodeTyped(this: g_pIInput, a2: (ButtonCode_t)event->m_nData);
      result = true;
      break;
    case 0xCC:
      g_pIInput->OnInputLanguageChanged(this: g_pIInput);
      result = true;
      break;
    case 0xCD:
      g_pIInput->SetIMEWindow(this: g_pIInput, a2: (void *)event->m_nData);
      result = true;
      break;
    case 0xCE:
      g_pIInput->OnIMEStartComposition(this: g_pIInput);
      result = true;
      break;
    case 0xCF:
      g_pIInput->OnIMEComposition(this: g_pIInput, a2: event->m_nData);
      result = true;
      break;
    case 0xD0:
      g_pIInput->OnIMEEndComposition(this: g_pIInput);
      result = true;
      break;
    case 0xD1:
      g_pIInput->OnIMEShowCandidates(this: g_pIInput);
      result = true;
      break;
    case 0xD2:
      g_pIInput->OnIMEChangeCandidates(this: g_pIInput);
      result = true;
      break;
    case 0xD3:
      g_pIInput->OnIMECloseCandidates(this: g_pIInput);
      result = true;
      break;
    case 0xD4:
      g_pIInput->OnIMERecomputeModes(this: g_pIInput);
      result = true;
      break;
    default:
LABEL_40:
      result = false;
      break;
  }
  return result;
}
