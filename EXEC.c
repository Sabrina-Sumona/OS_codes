#include<stdio.h>
#include<unistd.h>

int main()
{
	int i;
	printf("I am EXEC.c called by execvp()");
	printf("\n");
	//printf("The id of this process: %d.\n",getpid());
	return 0;
}
