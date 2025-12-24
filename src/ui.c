#include <stdio.h>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "ui.h"
#include "timer.h"

static Status ui_status = IDLE;
static int ui_minutes = 20;

Status* ui_get_status(void) {
    return &ui_status;
}

int ui_get_minutes(void) {
    return ui_minutes;
}

void DrawUI(){
	ClearBackground(DARKGRAY);
	draw_timer();

	if(GuiButton((Rectangle){ 40, 160, 140, 30 },"Begin")){
		ui_status = FOCUS;
		ui_minutes = 1;
	}

	control_timer(ui_get_status(), ui_get_minutes());
}
