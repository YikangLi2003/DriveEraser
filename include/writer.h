#ifndef WRITER_H
#define WRITER_H

#include <stdio.h>

#include "block.h"

bool write_file_randomly(FILE *file);
bool write_file(FILE *file, const Block block);

#endif