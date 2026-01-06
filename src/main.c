#include "raylib.h"
#include "timer.h"
#include "ui.h"
#include "sounds.h"

int main(void){
	InitWindow(800, 600, "PomoKey");
	SetExitKey(0);
	SetTargetFPS(60);
	SetWindowMinSize(800, 600);
	/*
	 * NOTE:
	 * Enabling FLAG_WINDOW_RESIZABLE causes incorrect mouse coordinates
	 * when running under XWayland + Hyprland, especially when the window
	 * is tiled or grouped.
	 *
	 * Mouse position appears offset (e.g. Y + ~30px).
	 */
	// SetWindowState(FLAG_WINDOW_RESIZABLE);

	InitAudioDevice();
	//TraceLog(LOG_INFO, "Audio device ready: %d", IsAudioDeviceReady());
	load_sounds();
	load_background();

	while(!WindowShouldClose()){
		BeginDrawing();
		update_background();
		DrawUI();
		draw_timer();
		EndDrawing();
	}
	unload_sounds();
	unload_background();
	CloseAudioDevice();
	CloseWindow();

	return 0;
}
