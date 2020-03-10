/*
 * timerinc.c
 *
 *  Created on: Mar 10, 2020
 *      Author: Koson
 */

#include "DIALOG.h"

/*********************************************************************
*
*       Static code
*
**********************************************************************
*/
/*********************************************************************
*
*       _cbBk
*/
static void _cbBk(WM_MESSAGE * pMsg) {
  int              Id;
  int              NCode;
  WM_HWIN          hItem;
  static int       Value;
  static int       TimerInc;
  static WM_HTIMER hTimer;

  switch (pMsg->MsgId) {
  case WM_CREATE:
    hTimer = WM_CreateTimer(pMsg->hWin, 0, 0, 0);
    BUTTON_CreateEx(10, 10, 80, 20, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_BUTTON0);
    hItem = TEXT_CreateEx(100, 10, 80, 20, pMsg->hWin, WM_CF_SHOW, 0, GUI_ID_TEXT0, "0");
    TEXT_SetTextColor(hItem, GUI_WHITE);
    TEXT_SetTextAlign(hItem, GUI_TA_HCENTER | GUI_TA_VCENTER);
    TEXT_SetDec(hItem, 0, 5, 0, 0, 1);
    break;
  case WM_PAINT:
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
    break;
  case WM_TIMER:
    hItem = WM_GetDialogItem(pMsg->hWin, GUI_ID_BUTTON0);
    if (BUTTON_IsPressed(hItem)) {
      hItem = WM_GetDialogItem(pMsg->hWin, GUI_ID_TEXT0);
      Value++;
      TEXT_SetDec(hItem, Value, 5, 0, 0, 1);
      WM_RestartTimer(hTimer, 25);
      TimerInc = 1;
    } else {
      TimerInc = 0;
    }
    break;
  case WM_NOTIFY_PARENT:
    Id    = WM_GetId(pMsg->hWinSrc);
    NCode = pMsg->Data.v;
    switch (Id) {
    case GUI_ID_BUTTON0:
      switch (NCode) {
      case WM_NOTIFICATION_CLICKED:
        WM_RestartTimer(hTimer, 200);
        break;
      case WM_NOTIFICATION_RELEASED:
        if (TimerInc == 0) {
          hItem = WM_GetDialogItem(pMsg->hWin, GUI_ID_TEXT0);
          Value++;
          TEXT_SetDec(hItem, Value, 5, 0, 0, 1);
        }
        break;
      }
      break;
    }
    break;
  default:
    WM_DefaultProc(pMsg);
    break;
  }
}

/*********************************************************************
*
*       Public code
*
**********************************************************************
*/
/*********************************************************************
*
*       MainTask
*/
void MainTask(void) {
  GUI_Init();
  WM_MULTIBUF_Enable(1);
  WM_CreateWindowAsChild(0, 0, LCD_GetXSize(), LCD_GetYSize(), WM_HBKWIN, WM_CF_SHOW, _cbBk, 0);
  while (1) {
    GUI_Delay(100);
  }
}

/*************************** End of file ****************************/
