#include <stdio.h>

#include "uuid4.h"
#include "log.h"
#include "block.h"
#include "path.h"
#include "writer.h"
#include "configurator.h"


int main(int argc, char *argv[]) {
    Arguments arguments;

    init_args(&arguments);

    // args to string
}

/*
int main(int argc, char *argv[]) {
    Uuid4 uuid;
    Path path;
    Path dir = "C:\\Users\\ethan\\desktop";

    get_uuid4(uuid);
    build_full_file_path(path, dir, uuid);

    printf("%s", path);

    return 0;
}
*/


/*
int main(void) {
    Block all_ones;
    Block all_zeros;

    fill_block_all_ones(all_ones);
    fill_block_all_zeros(all_zeros);

    FILE *file_ones = fopen("file_ones.tmp", "wb");
    FILE *file_zeros = fopen("file_zeros.tmp", "wb");
    FILE *file_random = fopen("file_random.tmp", "wb");

    if (write_file(file_ones, all_ones)) {
        printf("all ones successful\n");
    }

    if (write_file(file_zeros, all_zeros)) {
        printf("all zeros successful\n");
    }

    if (write_file_randomly(file_random)) {
        printf("random successful\n");
    }

    fclose(file_ones);
    fclose(file_zeros);
    fclose(file_random);

    return 0;
}
*/

/*
int main(void) {
    Path input;
    Path full;
    Uuid4 uuid4;

    get_uuid4(uuid4);

    input_path(input);

    printf("Input path: %s\n", input);

    build_full_file_path(full, input, uuid4);

    printf("Full path: %s\n", full);

    return 0;
}
*/


/*
int main(void) {
    Block block;
    uint32_t state = 0xabcdef12;

    fill_block_randomly(block, &state);

    for (int i = 0; i < sizeof(Block); i++) {
        printf("%#02x ", block[i]);
    }
    printf("\n\n\n");

    fill_block_all_ones(block);

    for (int i = 0; i < sizeof(Block); i++) {
        printf("%#02x ", block[i]);
    }
    printf("\n\n\n");

    fill_block_all_zeros(block);

    for (int i = 0; i < sizeof(Block); i++) {
        printf("%#02x ", block[i]);
    }
    printf("\n\n\n");

    return 0;
}
*/

/*
int main(void) {
    log_message(LOG_TYPE_INFO, "Information %d.", 12);
    log_message(LOG_TYPE_ERROR, "Error %s.", "a piece string");
    log_message(LOG_TYPE_INPUT, "Please input: %s", "hello");

    return 0;
}
*/


/*
int main(void) {
    Uuid4List list;
    Uuid4 buffer;

    init_uuid4_list(&list);

    for (int i = 0; i < 132; i++) {
        get_uuid4(buffer);
        append_uuid4_to_list(&list, buffer);
        printf("New uuid4: %s\n", buffer);
        printf("List capacity: %d\n", list.capacity);
        printf("List length: %d\n", list.length);
        for (int j = 0; j < list.length; j++) {
            printf("%d: %s\n", j, list.elements[j]);
        }
        printf("\n");
    }

    free_uuid4_list(&list);

    printf("Program end.");
}
*/

/*
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
*/

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