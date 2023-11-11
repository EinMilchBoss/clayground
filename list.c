#include "list.h"

const LIST_SPACE_INCREMENT = 10;

static void
list_u8_space_inc(list_u8_t *const list) {
    list->space += LIST_SPACE_INCREMENT;
    list->values = realloc(list->values, list->space);
}

static void
list_u8_space_inc_if_full(list_u8_t *const list) {
    if (list->size == list->space) {
        list_u8_space_inc(list);
    }
}

static void
list_u8_space_dec(list_u8_t *const list) {
    list->space -= LIST_SPACE_INCREMENT;
    list->values = realloc(list->values, list->space);
}

static void
list_u8_space_dec_if_enough(list_u8_t *const list) {
    size_t max_space_unused = 2 * LIST_SPACE_INCREMENT;
    size_t min_space_used = 0;

    if (max_space_unused <= list->space) {
        min_space_used = list->space - max_space_unused;
    }

    if (list->size < min_space_used) {
        list_u8_space_dec(list);
    }
}

uint8_t*    
list_u8_push(list_u8_t *const list, uint8_t value) {
    uint8_t *pushed;

    list_u8_space_inc_if_full(list);

    pushed = list->values + list->size;
    *pushed = value;
    list->size += 1;

    return pushed;
}

uint8_t*
list_u8_insert(list_u8_t *const list, uint8_t value, size_t index) {
    size_t pushed_amount = list->size - index;
    uint8_t *inserted = list->values + index;
    
    if (index < 0 || list->size <= index) {
        return NULL;
    }

    list_u8_space_inc_if_full(list);

    /* make room for inserted value */
    memmove(inserted + 1, inserted, pushed_amount);

    *inserted = value;
    list->size += 1;
    return inserted;
}

uint8_t 
list_u8_pop(list_u8_t *const list) {
    uint8_t popped = list->values[list->size - 1];

    list->size -= 1;
    list_u8_space_dec_if_enough(list);

    return popped;
}

list_error_t     
list_u8_remove(list_u8_t *const list, size_t index) {
    size_t pulled_amount = list->size - (index + 1);
    uint8_t *removed = list->values + index;
    
    if (index < 0 || list->size <= index) {
        return ERR_INVALID_INDEX;
    }

    /* fill gap of removed value */
    memmove(removed, removed + 1, pulled_amount);

    list->size -= 1;
    list_u8_space_dec_if_enough(list);

    return OK;
}