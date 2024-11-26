#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define OPTION_SHORT_DRIVE_LETTER "-d"
#define OPTION_LONG_DRIVE_LETTER "--drive"

#define OPTION_SHORT_ERASE_SEQUENCE "-s"
#define OPTION_LONG_ERASE_SEQUENCE "--sequence"

#define ARGUMENT_ERASE_MODE_ALL_ZERO '0'
#define ARGUMENT_ERASE_MODE_ALL_ONE '1'
#define ARGUMENT_ERASE_MODE_RANDOM 'r'

#define OPTION_SHORT_NO_LOG_FILE "-n"
#define OPTION_LONG_NO_LOG_FILE "--no-log-file"

#define OPTION_SHORT_KEEP_ERASE_FILES "-k"
#define OPTION_LONG_KEEP_ERASE_FILES "--keep-erase-files"

#define OPTION_SHORT_HELP "-h"
#define OPTION_LONG_HELP "--help"

#define ERASE_SEQUENCE_LENGTH 12


typedef struct {
    char drive_letter;
    char erase_sequence[ERASE_SEQUENCE_LENGTH + 1];
    bool no_log_file;
    bool keep_erase_files;
    bool show_help;
    bool are_args_valid;
} Arguments;


void config_args(Arguments *arguments, int argc, const char *argv[]) {

}


void argv_to_lower(int argc, const char *argv[]) {
    for (int i = 0; i < argc; i++) {
        char *arg = argv[i];

        for (int j = 0; arg[j] != '\0'; j++) {
            if (isalpha(arg[j])) {
                arg[j] = tolower(arg[j]);
            }
        }
    }
}


void init_args(Arguments *arguments) {
    arguments->drive_letter = '\0';
    memset(arguments->erase_sequence, '\0', sizeof(arguments->erase_sequence) / sizeof(char));
    arguments->no_log_file = false;
    arguments->keep_erase_files = false;
    arguments->show_help = false;
    arguments->are_args_valid = true;
}


void set_drive_letter(Arguments *arguments, int argc, const char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (
            (strcmp(OPTION_SHORT_DRIVE_LETTER, argv[i]) ||
            strcmp(OPTION_LONG_DRIVE_LETTER, argv[i]))
            && i < argc - 1
        ) {
            if (strlen(argv[i + 1]) == 1 && isalpha(argv[i + 1][0])) {
                arguments->drive_letter = toupper(argv[i + 1][0]);
            }

            return;
        }
    }
}


void set_erase_sequence(Arguments *arguments, int argc, const char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (
            (strcmp(OPTION_SHORT_ERASE_SEQUENCE, argv[i]) ||
            strcmp(OPTION_LONG_ERASE_SEQUENCE, argv[i]))
            && i < argc - 1
        ) {
            strncpy(
                arguments->erase_sequence,
                argv[i + 1],
                ERASE_SEQUENCE_LENGTH
            );
            
            return;
        }
    }
}


void set_boolean_flags(Arguments *arguments, int argc, const char *argv[]) {
    for (int i = 0; i < argc; i++) {
        if (
            strcmp(OPTION_SHORT_NO_LOG_FILE, argv[i]) ||
            strcmp(OPTION_LONG_NO_LOG_FILE, argv[i])
        ) {
            arguments->no_log_file = true;
        } else if (
            strcmp(OPTION_SHORT_KEEP_ERASE_FILES, argv[i]) ||
            strcmp(OPTION_LONG_KEEP_ERASE_FILES, argv[i])
        ) {
            arguments->keep_erase_files = true;
        } else if (
            strcmp(OPTION_SHORT_HELP, argv[i]) ||
            strcmp(OPTION_LONG_HELP, argv[i])
        ) {
            arguments->show_help = true;
        }
    }
}


void verify_args(Arguments *arguments) {
    if (arguments->drive_letter == '\0') {
        arguments->are_args_valid = false;
        return;
    }

    if (arguments->erase_sequence[0] == '\0') {
        arguments->are_args_valid = false;
        return;
    }

    for (int i = 0; arguments->erase_sequence[i] != '\0'; i++) {
        if (
            arguments->erase_sequence[i] != ARGUMENT_ERASE_MODE_ALL_ZERO &&
            arguments->erase_sequence[i] != ARGUMENT_ERASE_MODE_ALL_ONE &&
            arguments->erase_sequence[i] != ARGUMENT_ERASE_MODE_RANDOM
        ) {
            arguments->are_args_valid = false;
            return;
        }
    }
}
