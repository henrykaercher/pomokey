#include <stdio.h>
#include "timer.h"
#include "raylib.h"
#include "ui.h"

void control_timer(Status *status, int *s_counter, int *m_counter, int *b_counter){
	static float accumulator = 0.0f;

	accumulator += GetFrameTime();

	while(accumulator >= 1.0f){
		if(*status == FOCUS) (*s_counter)--;
		accumulator -= 1.0f;
		
		if(*s_counter <= 0){
			*s_counter = 59;
			(*m_counter)--;
		}
		if(*m_counter <= 0){
			*status = BREAK;
			(*b_counter)++;
			if(*b_counter >= 2){
				*b_counter = 0;
				//TODO: bigger break here
			}
		}
	}
}
