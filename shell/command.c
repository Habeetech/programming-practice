#include "main.h"

void run_command(char *cmd)
{
	char *argv[] = {cmd, NULL};
	char *envp[] = {"TERM=xterm", NULL};
	execve(argv[0], argv, envp);
perror("execve");
exit(EXIT_FAILURE);
}
