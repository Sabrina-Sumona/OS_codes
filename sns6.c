#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int id = fork();
	printf("The id of this process: %d.\n",getpid());
	return 0;
}
