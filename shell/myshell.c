#include "main.h"
int main(void)
{
	pid_t child;
	int status;
	char *cmd = NULL;
	size_t len = 0;
	while (1)
	{
		printf("OlaShell $: ");
		getline(&cmd, &len, stdin);
		cmd[strcspn(cmd, "\n")] = '\0';
		if (strcmp(cmd, "exit") == 0)
		{
			break;
		}
		if (strcmp(cmd, "ls") == 0)
		{
			child = fork();
			if (child == 0)
			{
				run_command("/usr/bin/ls");
				exit(EXIT_SUCCESS);
			}
			else
			{
				wait(&status);
			}
		}
		if(strcmp(cmd, "clear") == 0)
		{
			child = fork();
			if (child == 0)
			{
				run_command("/usr/bin/clear");
				exit(EXIT_SUCCESS);
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			printf("Command not found.\n");
		}
	}
	free(cmd);
	return 0;
}
