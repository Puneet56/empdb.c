#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdbool.h>

struct header_t
{
  int version;
  int count;
};

void print_usage(char *argv[])
{
  // TODO
  printf("USAGE: %s -f <db file>\n", argv[0]);
}

int main(int argc, char *argv[])
{
  char *filename = NULL;
  bool newfile = false;

  int option;

  while ((option = getopt(argc, argv, "f:n")) != -1)
  {
    switch (option)
    {
    case 'f':
      filename = optarg;
      break;
    case 'n':
      newfile = optarg;
      break;
    case '?':
      printf("unknown option: %c\n", optopt);
      break;
    }
  }

  if (filename == NULL)
  {
    printf("No db file provided\n");
    print_usage(argv);
    return 1;
  }

  return 0;
}
