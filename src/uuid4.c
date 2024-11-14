#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#include "uuid4.h"

#define UUID4_CHARSET "0123456789abcdef"
#define UUID4_LIST_INIT_CAPACITY 64


void get_uuid4(Uuid4 uuid) {
    srand(time(NULL));

    for (int i = 0; i < sizeof(Uuid4) / sizeof(char); i++) {
        switch (i) {
            case 8:
            case 13:
            case 18:
            case 23:
                uuid[i] = '-';
                break;
            case 14:
                uuid[i] = '4';
                break;
            case 19:
                uuid[i] = UUID4_CHARSET[(rand() % 4) + 8];
                break;
            case 36:
                uuid[i] = '\0';
                break;
            default:
                uuid[i] = UUID4_CHARSET[rand() % 16];
        }
    }
}


bool init_uuid4_list(Uuid4List *list) {
    list->elements = (Uuid4 *)malloc(sizeof(Uuid4) * UUID4_LIST_INIT_CAPACITY);
    list->length = 0;
    list->capacity = UUID4_LIST_INIT_CAPACITY;

    if (list->elements == NULL) {
        return false;
    }

    return true;
}


bool append_uuid4_to_list(Uuid4List *list, const Uuid4 uuid4) {
    if (list->length == list->capacity) {
        size_t new_capacity = list->capacity * 2;
        Uuid4 *new_elements = (Uuid4 *)realloc(list->elements, sizeof(Uuid4) * new_capacity);

        if (new_elements == NULL) {
            return false;
        }

        list->elements = new_elements;
        list->capacity = new_capacity;
    }

    strcpy(list->elements[list->length++], uuid4);

    return true;
}


void free_uuid4_list(Uuid4List *list) {
    free(list->elements);

    list->elements = NULL;
    list->length = 0;
    list->capacity = 0;
}
