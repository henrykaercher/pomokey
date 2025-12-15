#include <stdio.h>
#include "timer.h"

int status = IDLE;

void timer(){
	printf("%d\n", status);
}
