#ifndef PATH_H
#define PATH_H

#include "uuid4.h"

typedef char Path[4096];

bool input_path(Path path);
bool build_full_file_path(Path result, const Path dir_path, const Uuid4 filename);

#endif