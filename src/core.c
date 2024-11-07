#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

#include "utils.h"
#include "core.h"

#define ONE_BYTE_SIZE 1
#define BLOCK_BYTES 4096
#define BLOCKS_PER_2GB (int)(2LL * 1024 * 1024 * 1024 / BLOCK_BYTES)


typedef uint8_t Block[BLOCK_BYTES];


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


bool write_2gb(FILE *file, uint8_t byte) {
    Block block;
    
    memset(block, byte, BLOCK_BYTES);

    for (int i = 0; i < BLOCKS_PER_2GB; i++) {
        if (fwrite(block, ONE_BYTE_SIZE, BLOCK_BYTES, file) != BLOCK_BYTES) {
            return false;
        }
    }

    return true;
}


bool fill_driver(Path driver_dir, EraseMode mode) {
    
}