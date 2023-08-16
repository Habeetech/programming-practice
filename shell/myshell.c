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
		cmd[strcspn(cmd, "\n")] = '\0';
		if(strcmp(cmd, "ls") == 0)
				{
				child = fork();
				{
				if (child == 0)
				{
				run_command("/bin/ls");
				exit(EXIT_SUCCESS);
				}
				else
				{
				wait(&status);
				}
				else
				{
				printf("command not found");
				}
				}
	}
	}
return 0;
}
