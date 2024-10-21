#include "pushswap.h"

void initialize_chunks(t_stack *stack)
{
    if (stack->size > 0)
    {
        stack->chunk_size = (int)sqrt(stack->size);
    }
}

void assign_chunks(t_stack *stack)
{
    t_node *current = stack->top;
    int chunk_index = 0;
    int count = 0;

    while (current)
    {
        current->chunk = chunk_index;
        count++;
        if (count >= stack->chunk_size)
        {
            chunk_index++;
            count = 0;
        }
        current = current->next;
    }
}

void push_chunk_to_stack_b(t_stack *stack_a, t_stack *stack_b, int chunk_min, int chunk_max)
{
    int size = stack_a->size;

    for (int i = 0; i < size; i++)
    {
        if (stack_a->top->chunk >= chunk_min && stack_a->top->chunk <= chunk_max)
        {
            pb(stack_b, stack_a);
        }
        else
        {
            ra(stack_a);
        }
    }
}