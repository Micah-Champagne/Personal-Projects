#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
	unsigned long *p = malloc(sizeof(unsigned long));
	*p = 0xdeadbeefcafeba00;
	int i;
	unsigned long *p1 = malloc(sizeof(unsigned long));
	//*p1 = htons(*p);
	unsigned char *c = (unsigned char *)p+8;
	//output the individual byes of the unsigned long value... or not?
	for (i = 0; i < sizeof(unsigned long); i++)
	{
		printf("%02x ", *c);
		c--;
	}

	printf("\n");
	return 0;
}
