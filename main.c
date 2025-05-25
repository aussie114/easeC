#include "header/easeC.h"

int main(void)
{
    printf("Result: %g\n", eval("1+1*5"));
    printf("Result: %g\n", eval("(1+1)*5"));
    printf("Result: %g\n", eval("1/99"));
    printf("Result: %g\n", eval("10*10"));
	char output[65];
	sha256("test", output);
	puts(output);
    return 0;
}
