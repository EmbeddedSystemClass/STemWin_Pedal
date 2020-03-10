/*
 * rotatePolygon.c
 *
 *  Created on: Mar 10, 2020
 *      Author: Koson
 */
#include "DIALOG.h"

// Source polygon
// The coords of the polygon set that the origin and pivot point is inside the polygon
GUI_POINT pSource1[] = { {-10, 10}, {-10, -90}, {0, -100}, {10, -90}, {10, 10} };

// The coords of the polygon set that the origin and pivot point is outside the polygon
GUI_POINT pSource2[] = { {-10, -20}, {-10, -90}, {0, -100}, {10, -90}, {10, -20} };

// Rotated polygon
GUI_POINT pDest1[5], pDest2[5];


void MainTask(void) {

    GUI_Init();

    // Origin point is inside the polygon
    GUI_DispStringHCenterAt("Origin point is inside the polygon", 160, 10);

    // Draw the origin point (100, 120)
    GUI_DrawPoint(100, 120);

    // Draw the source polygon with the origin point
    GUI_DrawPolygon(pSource1, GUI_COUNTOF(pSource1), 100, 120);

    // Rotate the source polygon
    GUI_RotatePolygon(pDest1, pSource1, GUI_COUNTOF(pSource1), 45 * 0.01745329);

    GUI_SetColor(GUI_RED);

    // Draw the rotated polygon with the same origin point
    GUI_DrawPolygon(pDest1, GUI_COUNTOF(pDest1), 100, 120);

    GUI_SetColor(GUI_GREEN);

    // Draw the new origin point (300, 120)
    GUI_DrawPoint(300, 120);

    // Draw the rotated polygon with the new origin point
    GUI_DrawPolygon(pDest1, GUI_COUNTOF(pDest1), 300, 120);

    // Origin point is outside the polygon
    GUI_SetColor(GUI_WHITE);
    GUI_DispStringHCenterAt("Origin point is outside the polygon", 160, 170);

    // Draw the origin point (100, 280)
    GUI_DrawPoint(100, 280);

    // Draw the source polygon with the origin point
    GUI_DrawPolygon(pSource2, GUI_COUNTOF(pSource2), 100, 280);

    // Rotate the source polygon
    GUI_RotatePolygon(pDest2, pSource2, GUI_COUNTOF(pSource2), 45 * 0.01745329);

    GUI_SetColor(GUI_RED);

    // Draw the rotated polygon with the same origin point
    GUI_DrawPolygon(pDest2, GUI_COUNTOF(pDest2), 100, 280);

    GUI_SetColor(GUI_GREEN);

    // Draw the new origin point (300, 280)
    GUI_DrawPoint(300, 280);

    // Draw the rotated polygon with the new origin point
    GUI_DrawPolygon(pDest2, GUI_COUNTOF(pDest2), 300, 280);

    while (1);
}

