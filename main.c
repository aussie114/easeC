#include "header/easeC.h"

int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", randint(50, 100));
	}
	return 0;
}
