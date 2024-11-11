#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "block.h"

#define BYTE_SIZE 1
#define BYTES_PER_FILE_2GB (2LL * 1024 * 1024 * 1024)
#define BLOCKS_PER_FILE_2GB (BYTES_PER_FILE_2GB / sizeof(Block))

#define ERASE_MODE_ALL_ZEROS 0
#define ERASE_MODE_ALL_ONES 1
#define ERASE_MODE_RANDOM 2

/*
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
*/

bool fill_file_randomly(FILE *file) {
    Block block;
    uint32_t random_state = time(NULL);

    for (int i = 0; i < BLOCKS_PER_FILE_2GB; i++) {
        fill_block_randomly(block, &random_state);
        if (fwrite(block, BYTE_SIZE, sizeof(Block), file) != sizeof(Block)) {
            return false;
        }
    }

    return true;
}


bool fill_file_all_ones(FILE *file) {
    Block block;
    fill_block_all_ones(block);

    for (int i = 0; i < BLOCKS_PER_FILE_2GB; i++) {
        if (fwrite(block, BYTE_SIZE, sizeof(Block), file) != sizeof(Block)) {
            return false;
        }
    }

    return true;
}