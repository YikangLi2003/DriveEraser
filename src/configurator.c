#include <stdbool.h>

#define OPTION_LOG_TO_FILE "-l"
#define OPTION_REMOVE_ERASE_FILE "-r"

#define ERASE_MODE_ALL_ZERO '0'
#define ERASE_MODE_ALL_ONE '1'
#define ERASE_MODE_RANDOM 'R'


typedef struct {
    char erase_sequence[12];
    bool log_to_file;
    bool remove_erase_file;
} Arguments;


void configure_arguments(int argc, char *argv[], Arguments *arguments) {
    for (int i = 0; i < sizeof(arguments->erase_sequence) / sizeof(char); i++) {
        arguments->erase_sequence[i] = '\0';
    }

    arguments->erase_sequence[0] = ERASE_MODE_ALL_ZERO;
    arguments->erase_sequence[1] = ERASE_MODE_ALL_ONE;
    arguments->erase_sequence[2] = ERASE_MODE_RANDOM;
    arguments->log_to_file = true;
    arguments->remove_erase_file = true;
}