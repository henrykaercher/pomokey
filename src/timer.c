#include <stdio.h>
#include "timer.h"
#include "raylib.h"
#include "ui.h"

static int s_counter = 0;
static int m_counter = 20;

static Status current_status = IDLE;
static int break_counter = 0;

bool running_timer(void){
    static float accumulator = 0.0f;
    accumulator += GetFrameTime();

    while(accumulator >= 1.0f){
        accumulator -= 1.0f;

        if(s_counter <= 0){
            if(m_counter <= 0){
                return true;
            }else{
                s_counter = 59;
                m_counter--;
            }
        }else{
            //s_counter--;
			s_counter -= 35;
        }
    }
    return false;
}

void control_timer(Status *status, int minutes){
    if(!status) return;

    if(*status != current_status){
        current_status = *status;

        switch(current_status){
            case IDLE:
                m_counter = 20;
                s_counter = 0;
                break;

            case FOCUS:
                m_counter = minutes;
                s_counter = 0;
                break;

            case BREAK:
                m_counter = (int)(minutes * 0.2f);
                s_counter = 0;
                break;

            case LONG_BREAK:
                m_counter = (int)(minutes * 1.2f);
                s_counter = 0;
                break;
        }
    }

    if(current_status == FOCUS ||
       current_status == BREAK ||
       current_status == LONG_BREAK){

        if(running_timer()){
            if(current_status == FOCUS){
                break_counter++;
				if(break_counter > 3){
					*status = LONG_BREAK;
					break_counter = 0;
				}else{
					*status = BREAK;
				}
            } else {
                *status = FOCUS;
            }
        }
    }
}

void draw_timer(){
    char str[16];
    sprintf(str, "%02d:%02d", m_counter, s_counter);
    DrawText(str, GetScreenWidth() / 2, GetScreenHeight() / 2, 60, BLACK);
}

