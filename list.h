#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <string.h>

typedef enum list_error {
    OK,
    ERR_INVALID_INDEX,
} list_error_t;

typedef struct list_u8 {
    uint8_t *values;
    size_t size;
    size_t space;
} list_u8_t;

uint8_t*        list_u8_push(list_u8_t *const list, uint8_t value);
uint8_t*        list_u8_insert(list_u8_t *const list, uint8_t value, size_t index);
uint8_t         list_u8_pop(list_u8_t *const list);
list_error_t    list_u8_remove(list_u8_t *const list, size_t index);

#endif