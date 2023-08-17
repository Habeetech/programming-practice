#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main (int ac, char *av, char **env)
{
	while (*env != NULL)
	{
		printf("Address of main Env: %p\n", &env);
		*env++;
	}
	char **en = environ;
	while (*en != NULL)
	{
		printf("Address of global Env: %p\n", &en);
		*en++;
	}
	return 0;
}
