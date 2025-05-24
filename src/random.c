#include <stdio.h>
#include <stdlib.h>

int randint(int start, int stop)
{
	return (rand() % (start - stop + 1)) + start;
}

