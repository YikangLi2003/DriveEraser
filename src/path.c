#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "path.h"
#include "uuid4.h"

#define TEMP_FILE_EXTENSION ".tmp"


void build_full_file_path(Path result, const char drive_letter, const Uuid4 filename) {
    char letter[3];

    letter[0] = toupper(drive_letter);
    letter[1] = ':';
    letter[2] = '\0';

    strcpy(result, letter);
    strcat(result, "\\");
    strcat(result, filename);
    strcat(result, TEMP_FILE_EXTENSION);
}
