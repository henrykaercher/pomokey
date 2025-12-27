#include <stdio.h>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "ui.h"
#include "timer.h"

static Status ui_status = IDLE;
static int ui_minutes = 25;

void DrawUI(){
		if(ui_status == IDLE){
			GuiSpinner(
				(Rectangle){ 40, 120, 140, 30 },
				"Minutes",
				&ui_minutes,
				25,
				80,
				true
			);

		if(GuiButton((Rectangle){ 40, 160, 140, 30 },"Begin")){
			ui_status = FOCUS;
		}
	}else{
		if(GuiButton((Rectangle){ 40, 160, 140, 30 },"stop")) ui_status = IDLE;
	}

	control_timer(&ui_status, ui_minutes);

	ClearBackground(DARKGRAY);
}
