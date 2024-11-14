#ifndef PATH_H
#define PATH_H

#include "uuid4.h"

typedef char Path[260];

void build_full_file_path(Path result, const char drive_letter, const Uuid4 filename);

#endif