#ifndef CONFIGURATOR_H
#define CONFIGURATOR_H

#include <stdbool.h>

#define ERASE_SEQUENCE_LENGTH 12

typedef struct {
    char drive_letter;
    char erase_sequence[ERASE_SEQUENCE_LENGTH + 1];
    bool no_log_file;
    bool keep_erase_files;
    bool show_help;
    bool are_args_valid;
} Arguments;

void init_args(Arguments *arguments);
void set_drive_letter(Arguments *arguments, int argc, char *argv[]);
void set_erase_sequence(Arguments *arguments, int argc, char *argv[]);
void set_boolean_flags(Arguments *arguments, int argc, char *argv[]);
void verify_args(Arguments *arguments);

#endif