#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main (int argc, char *argv[])
{
pid_t child;
int status;
while(1)
	{
		if (strcmp(argv[1], "exit") == 0)
			{
				break;
			}
		child = fork();
		if (child == 0)
		{
		}
		else
		{
			wait(&status);
		}
	}
return 0;
}
