#include <stdio.h>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "ui.h"
#include "timer.h"

static Status ui_status = IDLE;
static int ui_minutes = 20;

Status* ui_get_status(){
    return &ui_status;
}

int ui_get_minutes(){
    return ui_minutes;
}

void DrawUI(){
	if(GuiButton((Rectangle){ 40, 160, 140, 30 },"Begin")){
		if(ui_status == IDLE){
			ui_status = FOCUS;
			ui_minutes = 10;
		}
	}

	control_timer(ui_get_status(), ui_get_minutes());

	ClearBackground(DARKGRAY);
	printf("%d\n", ui_status);
	//draw_timer();
}
