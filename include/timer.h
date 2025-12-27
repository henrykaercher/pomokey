#ifndef TIMER_H
#define TIMER_H

typedef enum{
	IDLE,
	FOCUS,
	BREAK,
	LONG_BREAK
}Status;

bool running_timer();
void control_timer(Status *status, int minutes);
void draw_timer();

#endif
