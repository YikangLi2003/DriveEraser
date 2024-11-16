#include <stdbool.h>

#define OPTION_SHORT_DRIVE_LETTER "-d"
#define OPTION_LONG_DRIVE_LETTER "--drive"

#define OPTION_SHORT_ERASE_SEQUENCE "-s"
#define OPTION_LONG_ERASE_SEQUENCE "--sequence"

#define ARGUMENT_ERASE_MODE_ALL_ZERO '0'
#define ARGUMENT_ERASE_MODE_ALL_ONE '1'
#define ARGUMENT_ERASE_MODE_RANDOM 'R'

#define OPTION_SHORT_NO_LOG_FILE "-n"
#define OPTION_LONG_NO_LOG_FILE "--no-log-file"

#define OPTION_SHORT_KEEP_ERASE_FILES "-k"
#define OPTION_LONG_KEEP_ERASE_FILES "--keep-erase-files"

#define OPTION_SHORT_HELP "-h"
#define OPTION_LONG_HELP "--help"


typedef struct {
    char drive_letter;
    char erase_sequence[12];
    bool no_log_file;
    bool keep_erase_files;
    bool show_help;
    bool are_args_valid;
} Arguments;


void config_args(Arguments *arguments, int argc, char *argv[]) {

}


void init_args(Arguments *arguments) {
    arguments->drive_letter = '\0';

    for (int i = 0; i < sizeof(arguments->erase_sequence) / sizeof(char); i++) {
        arguments->erase_sequence[i] = '\0';
    }

    arguments->no_log_file = false;
    arguments->keep_erase_files = false;
    arguments->show_help = false;
    arguments->are_args_valid = false;
}


void set_drive_letter(Arguments *arguments, int argc, char *argv[]) {
    
}

void verify_args(Arguments *arguments) {

}