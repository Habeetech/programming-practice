#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t mypid, childpid;

	childpid = fork();
	if (childpid == -1)
	{
		perror("unable to create a child process");
		return -1;
	}
	mypid = getpid();
	printf("my pid is %u\n", mypid);
	if (childpid == 0)
	{
		printf("(%u) I am the child\n", mypid);
	}
	else
	{
		printf("(%u) %u I am your father\n", mypid, childpid);
	}
	return 0;
}
