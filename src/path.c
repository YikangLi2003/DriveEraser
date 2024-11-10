#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "path.h"
#include "uuid4.h"

#define TEMP_FILE_EXTENSION ".tmp"


bool input_path(Path path) {
    if (fgets(path, sizeof(Path) / sizeof(char), stdin) != NULL) {
        size_t length = strlen(path);
        
        if (length > 0 && path[length - 1] == '\n') {
            path[length - 1] = '\0';
        }

        return true;
    }

    return false;
}


bool build_full_file_path(Path result, const Path dir_path, const Uuid4 filename) {
    if ((strlen(result) + strlen(dir_path) + strlen(filename)) >= sizeof(Path)) {
        return false;
    }

    strcat(result, dir_path);
    strcat(result, "/");
    strcat(result, filename);
    strcat(result, "/");
    strcat(result, TEMP_FILE_EXTENSION);

    return true;
}
