#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <assert.h>

#include "main.h"

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

  while ((option = getopt(argc, argv, "nf:")) != -1)
  {
    switch (option)
    {
    case 'f':
      filename = optarg;
      break;
    case 'n':
      newfile = true;
      break;
    case '?':
      printf("unknown option: %c\n", optopt);
      break;
    }
  }

  printf("DEBUG: PASSED ARGS: filename: %s | newfile %d\n", filename, newfile);

  if (filename == NULL)
  {
    printf("No file provided");
    print_usage(argv);
  }

  // TODO:To be closed in this function
  FILE *fd = fopen(filename, "wb");

  if (fd == NULL)
  {
    perror("Error opening file");
    return 1;
  }

  // Todo: initializing this as pointer threw error. read about that
  // To be freed
  struct header_t header = {0};

  if (newfile)
  {
    printf("DEBUG: creating new header\n");
    header.version = 1;
    header.count = 0;
    header.magic = HEADER_MAGIC;
    int write_result = fwrite(&header, sizeof(struct header_t), 1, fd);
    printf("DEBUG: write_result %d \n", write_result);

    if (write_result == 0)
    {
      printf("Error writing new header to file\n");
      return 1;
    }
  }
  else
  {
    printf("DEBUG: Reading header from file\n");
    // TODO handle error. read ferror(3)
    fread(&header, sizeof(struct header_t), 1, fd);
  }

  // calling in both cases just to be sure
  if (!validate_header(&header))
  {
    printf("HEADER MAGIC does not match\n");
    return 1;
  }

  printf("DEBUG: HEADER: MAGIC: %d | Version %d | Count %d\n", header.magic, header.version, header.count);

  initialize_db(&header, fd);

  return 0;
}

int validate_header(struct header_t *header)
{
  if (header->magic != HEADER_MAGIC)
  {
    printf("DEBUG: in-valid header %d\n", header->magic);
    return 0;
  }

  printf("DEBUG: valid header\n");
  return 1;
}

void initialize_db(struct header_t *header, FILE *fd)
{
  assert(!"TODO: INITIALIZE DB\n");
}