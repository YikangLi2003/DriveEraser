#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#include <string.h>

#include "log.h"
#include "core.h"
#include "utils.h"


int main(void) {
    Uuid4 filename;
    Path path = "C:\\Users\\admin\\Desktop";

    get_uuid4(filename);

    strcat(path, "\\");
    strcat(path, filename);
    strcat(path, ".tmp");

    printf("%s", path);

    return 0;
}

/*
int main(void) {
    Uuid4 *uuid_array = malloc(sizeof(Uuid4) * 64);
    
    for (int i = 0; i < 64; i++) {
        get_uuid4(uuid_array[i]);
    }

    for (int i = 0; i < 64; i++) {
        printf("%s\n", uuid_array[i]);
    }

    return 0;
}
*/

/*
int main(void) {
    FILE *file_random = fopen("file_random", "wb");

    if (write_bytes_randomly(file_random)) {
        printf("Random file: Success\n");
    } else {
        printf("Random file: Fail\n");
    }

    fclose(file_random);

    return 0;
}
*/

/*
int main(void) {
    FILE *file = fopen("file_ones", "wb");

    if (write_bytes(file, 0b11111111)) {
        printf("Ones file: Success\n");
    } else {
        printf("Ones file: Fail\n");
    }

    fclose(file);

    return 0;
}
*/

/*
int main(void) {
    FILE *file_random = fopen64("file_random", "w");
    FILE *file_ones = fopen64("file_ones", "w");
    FILE *file_zeros = fopen64("file_zeros", "w");

    if (write_random(file_random)) {
        printf("Random file: Success\n");
    } else {
        printf("Random file: Fail\n");
    }

    if (write_bytes(file_ones, (uint8_t)0b11111111)) {
        printf("Ones file: Success\n");
    } else {
        printf("Ones file: Fail\n");
    }

    if (write_bytes(file_zeros, (uint8_t)0b00000000)) {
        printf("Zeros file: Success\n");
    } else {
        printf("Zeros file: Fail\n");
    }

    fclose(file_random);
    fclose(file_ones);
    fclose(file_zeros);

    return 0;
}
*/

/*
int main(void) {
    Path path;

    if (input_path(path)) {
        printf("Path exist: %s", path);
    } else {
        printf("Path does not exist: %s", path);
    }


}
*/

/*
int main(void) {
    Uuid4 uuid;

    get_uuid4(uuid);

    printf(uuid);

    return 0;
}
*/

/*
int main(void) {
    log_message(LOG_TYPE_INFO, "A piece of information.");
    log_message(LOG_TYPE_ERROR, "An error occured.");
    log_message(LOG_TYPE_INPUT, "User input.");
    log_message(LOG_TYPE_INFO, "An information with formatted integer %d, %d and %d.", 1, 2, 3);

    return 0;
}
*/