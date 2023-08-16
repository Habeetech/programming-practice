#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	unsigned int i;
	struct stat st;

	if (argc < 2)
	{
		printf("_which filename ...");
		return 1;
	}
	i = 1;
	while (argv[i])
	{
		printf("%s: ", argv[i]);
		if (stat(argv[i], &st) == 0)
		{
			printf("FOUND\n");
		}
		else
		{
			printf("NOT FOUND\n");
		}
		i++;
	}
	return 0;
}
