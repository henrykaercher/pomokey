#include <stdio.h>
#include "raylib.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"
#include "timer.h"
#include "ui.h"

int main(void){
	CurrentPage current_page;

	InitWindow(800, 600, "PomoKey");
	SetExitKey(0);
	SetTargetFPS(60);
	SetWindowMinSize(800, 600);
	SetWindowState(FLAG_WINDOW_RESIZABLE);

	while(!WindowShouldClose()){
		BeginDrawing();
		DrawUI(&current_page);
		EndDrawing();
	}

	return 0;
}
