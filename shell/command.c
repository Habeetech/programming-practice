#include "main.h"

void run_ls(char *cmd)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	execve(argv[0], argv, NULL);
}
