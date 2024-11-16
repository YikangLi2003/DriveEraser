#ifndef LOG_H
#define LOG_H

#include <stdbool.h>
#include <stdarg.h>

#define LOG_TYPE_INFO "INFO"
#define LOG_TYPE_ERROR "ERROR"
#define LOG_TYPE_INPUT "INPUT"

typedef char *LogType;

bool log_message(const LogType type, bool log_to_file, const char *format, ...);

#endif