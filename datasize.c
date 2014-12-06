#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
	printf("The value of INT_MAX is %i\n", INT_MAX);
	printf("The value of INT_MIN is %i\n", INT_MIN);
	printf("An int takes %zu bytes\n", sizeof(int));

	printf("The value of FLT_MAX is %f\n", FLT_MAX);
	printf("The value of FLT_MIN is %f\n", FLT_MIN);
	printf("A float takes %zu bytes\n", sizeof(float));

	printf("A char takes %zu bytes\n", sizeof(char *));
	printf("A double takes %zu bytes\n", sizeof(double));

	printf("A short int takes %zu bytes\n", sizeof(short));
	printf("A long int takes %zu bytes\n", sizeof(long));
}

