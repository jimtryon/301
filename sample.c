#include <stdio.h>

 
void f1(void)
{
	printf("hello\n");
}

int f2(int a, int b)
{
	int c = a + b;
	return c;
}

int main() 
{
	int result = 0;
	printf("I'm alive");
	f1();

	return 0;
}
