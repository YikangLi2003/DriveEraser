#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <string.h>

#include "log.h"
#include "utils.h"

#define FILENAME "disk_eraser.log"

bool log_message(const char *type, const char *format, ...) {
    va_list args;
    va_start(args, format);

    Timestamp timestamp;
    get_timestamp(timestamp);

    printf("[%s %s] ", timestamp, type);
    vprintf(format, args);
    printf("\n");

    FILE *file = fopen(FILENAME, "a");
    
    if (file == NULL) {
        va_end(args);
        
        return false;  
    }

    fprintf(file, "[%s %s] ", timestamp, type);
    vfprintf(file, format, args);
    fprintf(file, "\n");
    fclose(file);

    va_end(args);

    return true;
}