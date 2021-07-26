#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
extern int errno;

int main()
{
	int fd = open("foo.txt",O_RDONLY);
	printf("fd = %d\n",fd);
	if (fd == -1)
	{
		printf("Error number %d\n",errno);		
		perror("Program");
	}
	return 0;
}
