#include <stdint.h>
#include <string.h>

#include "block.h"

#define BYTE_ALL_ZERO 0x00
#define BYTE_ALL_ONE 0xff


void fill_block_randomly(Block block, uint32_t *state) {
    uint32_t x = *state;
    int i = 0;

    while (i < sizeof(Block)) {
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


void fill_block_all_zeros(Block block) {
    memset(block, BYTE_ALL_ZERO, sizeof(Block));
}


void fill_block_all_ones(Block block) {
    memset(block, BYTE_ALL_ONE, sizeof(Block));
}
