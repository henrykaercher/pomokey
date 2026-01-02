#include "raylib.h"
#include "timer.h"

static Sound snd_focus;
static Sound snd_break;
static Sound snd_long_break;

void load_sounds(){
	//TODO: diferent sounds for each one
	snd_focus = LoadSound("assets/pomo_break_bell.wav");
    snd_break = LoadSound("assets/pomo_break_bell.wav");
    snd_long_break = LoadSound("sounds/pomo_break_bell.wav");

	//TODO: themes, volume control and options in general
	SetSoundVolume(snd_focus, 6.0f);
	SetSoundVolume(snd_break, 6.0f);
	SetSoundVolume(snd_long_break, 6.0f);
}

void unload_sounds(){
	UnloadSound(snd_focus);
    UnloadSound(snd_break);
    UnloadSound(snd_long_break);
}

void play_sound(Status *status){
	switch(*status){
		case FOCUS:	PlaySound(snd_focus); break;
		case BREAK:	PlaySound(snd_break); break;
		case LONG_BREAK: PlaySound(snd_long_break); break;
		default: break;
	}
}
