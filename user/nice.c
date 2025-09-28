#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
	int pid = atoi(argv[1]);
	int prio = atoi(argv[2]);
	int r = nice(pid, prio);

	if(r <0){
		printf("failed to set pid to desginated priority");
		exit(1);
	}
	printf("Set pid %d to priority %d \n", pid, prio);
	exit(0);
}

