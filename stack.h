#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include <stdint.h>

typedef struct stack_u8_node {
    uint8_t value;
    struct stack_u8_node *next;
} stack_u8_node_t;

typedef struct stack_u8 {
    stack_u8_node_t *top;
    size_t size;
} stack_u8_t;

void    stack_u8_push(stack_u8_t *stack, uint8_t value);
uint8_t stack_u8_pop(stack_u8_t *stack);
uint8_t stack_u8_peek(stack_u8_t *stack);

#endif