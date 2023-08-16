#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
	pid_t child;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	child = fork();
	if (child == 0)
	{
		printf("I am the first child\n");
		execve(argv[0], argv, NULL);
		sleep(3);
	}
	else
	{
		wait(&status);
	}
	child = fork ();
	if (child == 0)
	{
		printf("I am the second child\n");
		execve(argv[0], argv, NULL);
		sleep(3);
	}
	else
	{
		wait(&status);
	}
	child = fork();
	if (child == 0)
	{
		printf("I am the third child\n");
		execve(argv[0], argv, NULL);
		sleep(3);
	}
	else
	{
		wait(&status);
	}
	child = fork();
	if (child == 0)
	{
		printf("I am the fourth child\n");
		execve(argv[0], argv, NULL);
		sleep(3);
	}
	else
	{
		wait(&status);
	}
	child = fork();
	if (child == 0)
	{
		printf("I am the fifth child\n");
		execve(argv[0], argv, NULL);
		sleep(3);
	}
	else
	{
		wait(&status);
	}
	return 0;
}
