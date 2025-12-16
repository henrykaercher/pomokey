#include <stdio.h>
#include "timer.h"
#include "raylib.h"

void timer(int *status, int *s_counter, int *m_counter){
	static float accumulator = 0.0f;

	accumulator += GetFrameTime();

	while (accumulator >= 1.0f){
		(*s_counter)--;
		accumulator -= 1.0f;
		
		if (*s_counter <= 0){
			*s_counter = 59;
			(*m_counter)--;
		}
		if (*m_counter >= 25){
			*status = BREAK;
		}
	}
}
