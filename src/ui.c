#include <stdio.h>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "ui.h"
#include "timer.h"

void DrawUI(CurrentPage *current_page){
	static Status status = FOCUS;
	static int s_counter = 59;
	static int m_counter = 25;
	static int b_counter = 0;

	ClearBackground(DARKGRAY);

	control_timer(&status, &s_counter, &m_counter, &b_counter);
	char str[16];
	sprintf(str, "%02d:%02d", m_counter, s_counter);
	DrawText(str, 500, 400, 60, BLACK);
}
