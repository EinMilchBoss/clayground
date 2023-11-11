#include "stack.h"

void 
stack_u8_push(stack_u8_t *stack, uint8_t value) {
    stack_u8_node_t *old_top = stack->top;

    stack->top = malloc(sizeof *stack->top);
    *stack->top = (stack_u8_node_t){ 
        .value = value, 
        .next = old_top
    };

    stack->size += 1;
}

uint8_t 
stack_u8_pop(stack_u8_t *stack) {
    stack_u8_node_t *popped = stack->top;
    uint8_t popped_value = popped->value;

    stack->top = popped->next;
    free(popped);

    stack->size -= 1;

    return popped_value;
}

uint8_t 
stack_u8_peek(stack_u8_t *stack) {
    return stack->top->value;
}