#ifndef LOG_H
#define LOG_H

#include <stdbool.h>

#define LOG_TYPE_INFO "INFO"
#define LOG_TYPE_ERROR "ERROR"
#define LOG_TYPE_INPUT "INPUT"

bool log_message(const char *type, const char *format, ...);

#endif