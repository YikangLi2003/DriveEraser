#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "disk_wipe.h"

typedef uint8_t Block[4096];

#define BLOCKS_PER_FILE (int)(2LL * 1024 * 1024 * 1024 / sizeof(Block))


void fill_block_randomly(Block block) {
    for (int i = 0; i < sizeof(Block); i++) {
        block[i] = (uint8_t)(rand() % 256);
    }
}


bool write_random(FILE *file) {
    Block block;

    for (int i = 0; i < BLOCKS_PER_FILE; i++) {
        fill_block_randomly(block);
        if (fwrite(block, sizeof(uint8_t), sizeof(Block), file) != sizeof(Block)) {
            return false;            
        }
    }

    return true;
}


bool write_bytes(FILE *file, uint8_t byte) {
    Block block;
    
    memset(block, byte, sizeof(Block));

    for (int i = 0; i < BLOCKS_PER_FILE; i++) {
        if (fwrite(block, sizeof(uint8_t), sizeof(Block), file) != sizeof(Block)) {
            return false;
        }
    }

    return true;
}
