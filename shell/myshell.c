#include "main.h"

int main (void)
{
	pid_t child;
	int status;
	char *cmd = NULL;
	size_t len = 0;

	while(1)
	{
		printf("OlaShell $: ");
		getline(&cmd, &len, stdin);
		switch(cmd)
		{
			case 'ls':
				child = fork();
				if (child == 0)
				{
				run_ls(cmd);
				}
				else
				{
			wait(&status);
				}
				break;
			default:
			break;
		}
	}
return 0;
}
