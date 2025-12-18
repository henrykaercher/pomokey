#ifndef TIMER_H
#define TIMER_H

//IDLE, FOCUS, BREAK, LONG_BREAK
typedef enum{
	IDLE,
	FOCUS,
	BREAK,
	LONG_BREAK
}Status;

void control_timer(Status *status, int *s_counter, int *m_counter, int *b_counter);

#endif
