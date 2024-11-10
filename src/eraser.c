#define ERASE_MODE_ALL_ZEROS 0
#define ERASE_MODE_ALL_ONES 1
#define ERASE_MODE_RANDOM 2

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