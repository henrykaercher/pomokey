#include <stdio.h>
#include "raylib.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
#include "timer.h"

int main(void){
	int status = FOCUS;
	int s_counter = 59;
	int m_counter = 25;

	InitWindow(800, 600, "PomoKey");
	SetExitKey(0);
	SetTargetFPS(60);
	SetWindowMinSize(800, 600);
	SetWindowState(FLAG_WINDOW_RESIZABLE);

	while(!WindowShouldClose()){
		timer(&status, &s_counter, &m_counter);

		BeginDrawing();
		ClearBackground(DARKGRAY);
		char str[16];
		sprintf(str, "%02d:%02d", m_counter, s_counter);
		DrawText(str, 500, 400, 60, BLACK);
		EndDrawing();
	}

	return 0;
}
