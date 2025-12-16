#ifndef TIMER_H
#define TIMER_H

//IDLE, FOCUS, BREAK, LONG_BREAK
#define IDLE 0
#define FOCUS 1
#define BREAK 2
#define LONG_BREAK 3

void timer(int *status, int *s_counter, int *m_counter);

#endif
