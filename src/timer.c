#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "timer.h"

void timer(int *status){
	printf("%d\n", *status);

	time_t start, current_time;
	int s_counter = 0;
	int m_counter = 0;
	//due the use of raylib, we need to think some things in the game logic way counting the frames.
	//float accumulator = 0.0f;

	//start the counter
	start = time(NULL);

	while (*status == FOCUS){
		//accumulator += GetFrameTime();

		/*
		 * while (accumulator >= 1.0f) {
            s_counter++;
            accumulator -= 1.0f;  // Reduz o acumulador, mantendo o tempo restante
            
            if (s_counter >= 60) {
                s_counter = 0;
                m_counter++;
            }

            printf("Timer: %02d minutes and %02d seconds\n", m_counter, s_counter);
        }
		*/

		//take the current time
		current_time = time(NULL);

		if(difftime(current_time, start) >= 1){
				s_counter++;
				start = current_time;
				if(s_counter >= 60){
					s_counter = 0;
					m_counter++;
				}
				printf("Counter: %02d seconds and %02d minutes\n", s_counter, m_counter);
		}
		sleep(1);
	}
}
