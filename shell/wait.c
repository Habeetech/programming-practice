#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main ()
{
	pid_t childpid;
	int status;

	childpid = fork();
	if (childpid == -1)
	{
		perror("unable to create a child process\n");
		return -1;
	}
	if (childpid == 0)
	{
		printf("I want to sleep wait for me\n");
		sleep(3);
	}
	else
	{
		wait(&status);
		printf("I am waiting, my child\n");
	}
	return 0;
}
