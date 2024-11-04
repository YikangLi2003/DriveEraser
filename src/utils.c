#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <sys/stat.h>

#include "utils.h"

#define TIMESTAMP_FORMAT "%Y-%m-%d %H:%M:%S"
#define TIMESTAMP_DEFAULT "1970-01-01 00:00:00"
#define UUID4_CHARSET "0123456789abcdef"


bool get_timestamp(Timestamp buffer) {
    time_t current_time = time(NULL); 
    struct tm *local_time = localtime(&current_time);

    if (local_time == NULL) {
        strcpy(buffer, TIMESTAMP_DEFAULT);
        return false;
    } else {
        strftime(buffer, sizeof(Timestamp), TIMESTAMP_FORMAT, local_time);
        return true;
    }
}


bool input_path(Path path) {
    if (fgets(path, sizeof(Path) / sizeof(char), stdin) != NULL) {
        size_t length = strlen(path);
        
        if (length > 0 && path[length - 1] == '\n') {
            path[length - 1] = '\0';
        }

        struct stat stat_buffer;
        if (stat(path, &stat_buffer) == 0) {
            return true;
        }

        return false;
    }

    return false;
}


void get_uuid4(Uuid4 uuid) {
    for (int i = 0; i < sizeof(Uuid4) / sizeof(char); i++) {
        switch (i) {
            case 8:
            case 13:
            case 18:
            case 23:
                uuid[i] = '-';
                break;
            case 14:
                uuid[i] = '4';
                break;
            case 19:
                uuid[i] = UUID4_CHARSET[(rand() % 4) + 8];
                break;
            case 36:
                uuid[i] = '\0';
                break;
            default:
                uuid[i] = UUID4_CHARSET[rand() % 16];
        }
    }
}