#ifndef BLOCK_H
#define BLOCK_H

#include <stdint.h>

typedef uint8_t Block[4096];

void fill_block_randomly(Block block, uint32_t *state);
void fill_block_all_zeros(Block block);
void fill_block_all_ones(Block block);

#endif