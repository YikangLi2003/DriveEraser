#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#include "core.h"
#include "uuid4.h"

#define ONE_BYTE_SIZE 1
#define BLOCK_BYTES 4096
#define BLOCKS_PER_2GB (int)(2LL * 1024 * 1024 * 1024 / BLOCK_BYTES)

#define FILENAMES_ARRAY_INITIAL_SIZE 64
#define TEMP_FILE_EXTENSION ".tmp"
#define CHECK_PATH_WRITEABLE_FILENAME "check_path_writeable.tmp"

typedef uint8_t Block[BLOCK_BYTES];
typedef char Path[4096];


void fill_block_randomly(Block block, uint32_t *state) {
    uint32_t x = *state;
    int i = 0;

    while (i < BLOCK_BYTES) {
        x ^= x << 13;
        x ^= x >> 17;
        x ^= x << 5;

        block[i++] = (uint8_t)(x & 0xff);
        block[i++] = (uint8_t)((x >> 8) & 0xff);
        block[i++] = (uint8_t)((x >> 16) & 0xff);
        block[i++] = (uint8_t)((x >> 24) & 0xff);
    }

    *state = x;
}


bool write_2gb_randomly(FILE *file) {
    Block block;
    uint32_t random_state = time(NULL);

    for (int i = 0; i < BLOCKS_PER_2GB; i++) {
        fill_block_randomly(block, &random_state);
        if (fwrite(block, ONE_BYTE_SIZE, BLOCK_BYTES, file) != BLOCK_BYTES) {
            return false;            
        }
    }

    return true;
}


bool write_2gb(FILE *file, Block block) {
    for (int i = 0; i < BLOCKS_PER_2GB; i++) {
        if (fwrite(block, ONE_BYTE_SIZE, BLOCK_BYTES, file) != BLOCK_BYTES) {
            return false;
        }
    }

    return true;
}



/*
bool fill_driver(Path driver_dir_path, EraseMode mode) {
    int filenames_array_size = FILENAMES_ARRAY_INITIAL_SIZE;
    int file_num = 0;
    Uuid4 *filenames = malloc(sizeof(Uuid4) * filenames_array_size);

    if (filenames == NULL) {
        return false;
    }

    while (true) {
        Path file_path = "";
        Uuid4 filename;

        get_uuid4(filename);
        get_file_path(file_path, driver_dir_path, filename);

        FILE *file = fopen64(file_path, "wb");

        if (file == NULL) {
            return false;
        }

        // extend filenames when necessary!

        if (file_num == filenames_array_size) {
            Uuid4 *temp_filenames = realloc(filenames, filenames_array_size * 2);

            if (temp_filenames == NULL) {
                return false;
            }
        }

        strcpy(filenames[file_num++], filename);
        
        // write content!

        fclose(file_path);
    }

}
*/