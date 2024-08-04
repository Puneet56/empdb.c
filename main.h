#ifndef MAIN_H
#define MAIN_H

// TODO: read where to include headers, here or in .c file
#include <stdio.h>
#include <stdlib.h>

#define HEADER_MAGIC 69

struct header_t
{
  int version;
  int count;
  int magic;
};

int validate_header(struct header_t *header);

void initialize_db(struct header_t *header, FILE *fd);

#endif  // MAIN_H