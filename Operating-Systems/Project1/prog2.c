#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct funcs 
{
	int (*openit)(char *name, int prot);
	void (*closeit)(void);
} funcs;

int my_openit(char *name, int prot)
{
	printf("Opening File\n");
	return 0;
}

void my_closeit()
{
	printf("Closing File\n");
}

void f(funcs *a)
{
	char* test = "test";
	int testing;
	testing = 2;
	a -> openit(test, testing);
	a -> closeit();
}

int main(int argc, char** argv)
{
	funcs functions = {.openit = &my_openit, .closeit = &my_closeit};
	f(&functions);
}
