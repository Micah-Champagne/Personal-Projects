#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUFFSIZE 1024

//a more "laid back" approach for the qsort() comparison function:
int cmp(const void *p1, const void *p2)
{
	char *s1 = *(char **)p1;
	char *s2 = *(char **)p2;
	return(strcmp(s1, s2));
}

/*
//the version that most experienced C programmers would write
int cmp2(const void *p1, const void *p2)
{
	return *((int *)p1) - *((int *)p2);
}
*/

int main(int argc, char *argv[])
{
	char **strings = NULL;
	//int something[5];
	int i, n, len;
	//char a = 64;
	//char b = 'A';	// == 64
	char buf[BUFFSIZE +1];

	printf("Enter # of Strings:");
	fflush(stdout);
	fgets(buf, BUFFSIZE, stdin); 	//or could use scanf()
	n = atoi(buf);
	strings = malloc(n*sizeof(char *));
	for (i = 0; i < n; i++)
	{
		printf("Enter string #%d: ", i+1);
		fgets(buf, BUFFSIZE-1, stdin);
		len = strlen(buf);
		if (buf[len-1] == '\n')
		{
			buf[len-1] = 0;
		}
		strings[i] = malloc((strlen(buf)+1) *sizeof(char));
		strcpy(strings[i], buf);
	}
	qsort(strings, n, sizeof(char*), cmp);

	printf("Sorted strings:\n");
	for (i = 0; i < n; i++)
	{
		printf("%s\n", strings[i]);
	}

	free(strings);

	return 0;
}
