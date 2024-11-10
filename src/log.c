#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>
#include <time.h>

#include "log.h"

#define LOG_FILENAME "driver_eraser.log"
#define LOG_TIMESTAMP_FORMAT "%Y-%m-%d %H:%M:%S"
#define LOG_TIMESTAMP_DEFAULT "1970-01-01 00:00:00"


typedef char LogTimestamp[20];


static bool get_log_timestamp(LogTimestamp buffer);
static void print_log(LogType type, LogTimestamp timestamp, const char *format, va_list args);
static bool save_log(LogType type, LogTimestamp timestamp, const char *format, va_list args);


bool log_message(LogType type, const char *format, ...) {
    va_list args;
    va_start(args, format);

    LogTimestamp timestamp;
    get_log_timestamp(timestamp);

    print_log(type, timestamp, format, args);
    save_log(type, timestamp, format, args);

    va_end(args);

    return true;
}


static bool get_log_timestamp(LogTimestamp buffer) {
    time_t current_time = time(NULL); 
    struct tm *local_time = localtime(&current_time);

    if (local_time == NULL) {
        strcpy(buffer, LOG_TIMESTAMP_DEFAULT);
        return false;
    } else {
        strftime(buffer, sizeof(LogTimestamp), LOG_TIMESTAMP_FORMAT, local_time);
        return true;
    }
}


static void print_log(LogType type, LogTimestamp timestamp, const char *format, va_list args) {
    printf("[%s %s] ", type, timestamp);
    vprintf(format, args);
    printf("\n");
}


static bool save_log(LogType type, LogTimestamp timestamp, const char *format, va_list args) {
    FILE *file = fopen(LOG_FILENAME, "a");
    
    if (file == NULL) {        
        return false;  
    }

    fprintf(file, "[%s %s] ", type, timestamp);
    vfprintf(file, format, args);
    fprintf(file, "\n");

    fclose(file);
}
