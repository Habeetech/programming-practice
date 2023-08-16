#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int main (void)
{
pid_t child;
int status;
char *buf = NULL;
size_t len = 0;

while(1)
	{
		printf("OlaShell $: ");
		getline(&buf, &len, stdin);
		if (strcmp(buf, "exit") == 0)
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
