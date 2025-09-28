#include "user/user.h"

int
main(int argc, char **argv)
{
  if (argc < 3) {
    
    printf("  lab2e3test get <pid>\n");
    printf("  lab2e3test set <pid> <prio 0..39>\n");
    exit(1);
  }

  if (!strcmp(argv[1], "get")) {
    int pid = atoi(argv[2]);
    int v = get_priority(pid);
    if (v < 0) {
      printf("get_priority(%d) -> -1 (not found)\n", pid);
    } else {
      printf("pid %d nice %d\n", pid, v);
    }
    exit(0);
  }

  if (!strcmp(argv[1], "set")) {
    if (argc < 4) {
      printf("Intended use:\nlab2e3test set <pid> <prio 0..39>\n");
      exit(1);
    }
    int pid = atoi(argv[2]);
    int pr  = atoi(argv[3]);
    int r = set_priority(pid, pr);
    int now = get_priority(pid);
    printf("set_priority(%d,%d) -> %d; now %d\n", pid, pr, r, now);
    exit(0);
  }
  exit(1);
}

