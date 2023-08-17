#include <stdio.h>
#include <stdlib.h>
char *_getenv(const char *name);

char *_getenv(const char *name)
{
	unsigned int i;
	while (name != NULL)
	{
		name[i];
		i++;
	}
	name[i] = found;
	return name;
}
int main ()
{
	char *value = _getenv("PATH");
	if (value != NULL)
	{
		printf("PATH value is: %s\n", value);
	}
	else
	{
		printf("PATH value not found");
	}
	return 0;
}
