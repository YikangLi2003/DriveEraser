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


typedef struct {
    char drive_letter;
    char erase_sequence[12];
    bool log_to_file;
    bool remove_erase_files;
} Arguments;


void configure_arguments(int argc, char *argv[], Arguments *arguments) {
    for (int i = 0; i < sizeof(arguments->erase_sequence) / sizeof(char); i++) {
        arguments->erase_sequence[i] = '\0';
    }

    arguments->erase_sequence[0] = ARGUMENT_ERASE_MODE_ALL_ZERO;
    arguments->erase_sequence[1] = ARGUMENT_ERASE_MODE_ALL_ONE;
    arguments->erase_sequence[2] = ARGUMENT_ERASE_MODE_RANDOM;
    arguments->log_to_file = true;
    arguments->remove_erase_files = true;

    // -l 
}