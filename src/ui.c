#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#include "ui.h"
#include "timer.h"

static Status ui_status = IDLE;
static int ui_minutes = 25;

Texture2D backgrounds[3];

int dropdownActive = 0;
bool dropdownEdit = false;
const char *options = "Square;Piramid;Square with more faces";

Rectangle dropdownRect = {650, 50, 140, 30};

void DrawUI(){
	if(ui_status == IDLE){
		GuiSpinner(
			(Rectangle){ 40, 40, 160, 30 },
			"Minutes",
			&ui_minutes,
			25,
			80,
			true
		);

		DrawText("Shape:", dropdownRect.x, dropdownRect.y - 20, 10, WHITE);
		if(GuiDropdownBox(dropdownRect, options, &dropdownActive, dropdownEdit)){
            dropdownEdit = !dropdownEdit;
        }

		if(GuiButton((Rectangle){ 40, 80, 160, 30 },"Begin")){
			ui_status = FOCUS;
		}
	}else{
		if(GuiButton((Rectangle){ 40, 80, 160, 30 },"stop")) ui_status = IDLE;
	}

	control_timer(&ui_status, ui_minutes);
}

void load_background(){
	backgrounds[0] = LoadTexture("assets/background.png");
    backgrounds[1] = LoadTexture("assets/background2.png");
    backgrounds[2] = LoadTexture("assets/background3.png");
}

void unload_background(){
	for (int i = 0; i < ARRAY_LEN(backgrounds); i++)
        UnloadTexture(backgrounds[i]);
}

void update_background(){
	Texture2D *bg = &backgrounds[dropdownActive];

    DrawTexturePro(
        *bg,
        (Rectangle){ 0, 0, bg->width, bg->height },
        (Rectangle){ 0, 0, GetScreenWidth(), GetScreenHeight() },
        (Vector2){ 0, 0 },
        0.0f,
        WHITE
    );
}
