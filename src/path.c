#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "path.h"
#include "uuid4.h"

#define TEMP_FILE_EXTENSION ".tmp"


bool build_full_file_path(Path result, const Path erase_dir, const Uuid4 filename) {
    if (strlen(erase_dir) + strlen("/") + strlen(filename) + strlen(TEMP_FILE_EXTENSION) >= sizeof(Path) / sizeof(char)) {
        return false;
    }

    strcpy(result, "");
    strcat(result, erase_dir);
    strcat(result, "/");
    strcat(result, filename);
    strcat(result, TEMP_FILE_EXTENSION);

    return true;
}