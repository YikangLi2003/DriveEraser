#ifndef DISK_WIPE_H
#define DISK_WIPE_H

#include <stdio.h>
#include <stdint.h>

bool write_random(FILE *file);
bool write_bytes(FILE *file, uint8_t byte);

#endif