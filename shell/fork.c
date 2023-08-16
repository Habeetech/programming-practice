#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid, mypid;

	printf("This is the parent\n");
	pid = getpid();
	printf("Pid: %u\n", pid);

	pid = fork();
	printf("This is the child\n");
	mypid = getpid();
	if (mypid == -1)
{
	return -1;
}
else
{
	printf("Pid: %u\n", mypid);
	return 0;
}
}
