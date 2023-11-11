#include <stdio.h>
#include <stdint.h>

#include "stack.h"
#include "list.h"

int main() {
    stack_u8_t stack = { 0 };
    list_u8_t list = { 0 };

    size_t i;
    uint8_t popped;
    uint8_t *inserted;

    for (i = 0; i < 5; i += 1) {
        stack_u8_push(&stack, i);
        printf("Peek: %d\n", stack_u8_peek(&stack));
    }
    printf("Size: %lu\n", stack.size);

    for (i = 0; i < 2; i += 1) {
        popped = stack_u8_pop(&stack);
        printf("Popped: %d\n", popped);
    }
    printf("Size: %lu\n", stack.size);

    for (i = 0; i < 10; i += 1) {
        list_u8_push(&list, i);
    }
    printf("Size: %lu\n", list.size);
    printf("Space: %lu\n", list.space);

    for (i = 0; i < 5; i += 1) {
        popped = list_u8_pop(&list);
        printf("Popped: %d\n", popped);
    }
    printf("Size: %lu\n", list.size);
    printf("Space: %lu\n", list.space);

    inserted = list_u8_insert(&list, 21, 3);
    if (inserted != NULL) {
        printf("Inserted: %d\n", *inserted);
        printf("Last: %d\n", list.values[list.size - 1]);
    }

    if (!list_u8_remove(&list, 3)) {
        printf("Removed entry at index 3.\n");
    }
    printf("Space: %lu\n", list.space);

    return 0;
}