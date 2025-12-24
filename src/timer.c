#include <stdio.h>
#include "timer.h"
#include "raylib.h"
#include "ui.h"

static int s_counter = 0;
static int m_counter = 20;
static int total_m = 20;

static Status current_status = IDLE;
static int break_counter = 0;

void running_timer(void){
    static float accumulator = 0.0f;

    accumulator += GetFrameTime();
	//printf("%d\n", break_counter);

    while(accumulator >= 1.0f){
        accumulator -= 1.0f;

        if(m_counter == 0 && s_counter == 0){
            //return;
			current_status = BREAK;
			break_counter ++;
        }

		if(break_counter > 2){
			current_status = LONG_BREAK;
		}

        if(s_counter == 0){
            s_counter = 59;
            m_counter--;
        }else{
            s_counter--;
        }
    }
}

void control_timer(Status *status, int minutes){
    if (!status) return;

    if (*status != current_status) {
        current_status = *status;

        switch (current_status) {
            case IDLE:
                s_counter = 0;
                m_counter = 20;
                break;

            case FOCUS:
                m_counter = minutes;
				s_counter = 0;
                break;

            case BREAK:
                m_counter = (int)(total_m * 0.2f) + total_m;
                s_counter = 0;
                break;

            case LONG_BREAK:
                m_counter = (int)(total_m * 1.2f);
                s_counter = 0;
                break;

            default:
                break;
        }
    }

    if (current_status == FOCUS ||
        current_status == BREAK ||
        current_status == LONG_BREAK) {
        running_timer();
    }
}

void draw_timer(void){
    char str[16];
    sprintf(str, "%02d:%02d", m_counter, s_counter);
    DrawText(
        str,
        GetScreenWidth() / 2,
        GetScreenHeight() / 2,
        60,
        BLACK
    );
}

