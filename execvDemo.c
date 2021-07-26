#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	char *args[]={"./EXECV",NULL};
	execv(args[0],args);
	//printf("The id of this process: %d.\n",getpid());
	printf("Ending......");
	return 0;
}
