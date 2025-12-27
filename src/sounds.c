#include <stdio.h>
#include "raylib.h"
#include "timer.h"

static Sound snd_focus;
static Sound snd_break;
static Sound snd_long_break;

void load_sounds(){
	snd_focus = LoadSound("focus.wav");
    snd_break = LoadSound("break.wav");
    snd_long_break = LoadSound("long_break.wav");
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
