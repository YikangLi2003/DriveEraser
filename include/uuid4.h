#ifndef UUID4_H
#define UUID4_H

#include <stddef.h>
#include <stdbool.h>

typedef char Uuid4[37];

typedef struct {
    Uuid4 *elements;
    size_t length;
    size_t capacity;
} Uuid4List;

void get_uuid4(Uuid4 uuid);
bool init_uuid4_list(Uuid4List *list);
bool append_uuid4_to_list(Uuid4List *list, const Uuid4 uuid4);
void free_uuid4_list(Uuid4List *list);

#endif