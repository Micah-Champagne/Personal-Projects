#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	if(argv[1] == NULL || argv[2] != NULL)
	{
		printf("Error: Invalid input arguments. Must pass one file as argument to program.\n");
		exit(1);
	}
	FILE * fp;
	fp = fopen(argv[1], "r+");
	
	if(fp == NULL)
	{
		printf("Error: File cannot be opened.\n");
		exit(1);
	}
	else
	{
		fseek(fp, 0L, SEEK_END);
		long int fileSize = ftell(fp);
		printf("File size is %ld\n", fileSize);
		fseek(fp, 0L, SEEK_SET);
		char* pointer = (char*)malloc(fileSize);
		fread(pointer, fileSize+1, 1, fp);
		pointer[fileSize+1] = '\0';
		fclose(fp);
		const char* delim = " \t , \n";
		char* tokenize = strtok(pointer, delim);
		while (tokenize != NULL)
		{
			printf("%s\n", tokenize);
			tokenize = strtok(NULL, delim);
		}
		free(pointer);
	}
	return(0);
}

