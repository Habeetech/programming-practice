#include "main.h"

void run_command(char *cmd)
{
	char *argv[] = {"cmd, "NULL"};
	execve(argv[0], argv, NULL);
perror("execve");
exit(EXIT_FAILURE);
}
