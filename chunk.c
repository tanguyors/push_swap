#include "pushswap.c"

void initialize_chunks(t_stack *stack)
{
    if (stack == NULL || stack->size == 0)
        return;
    stack->chunk_size = (int)sqrt(stack->size);  // racine pour determiner un nombre de chunks
    if (stack->chunk_size == 0)
    {
        stack->chunk_size = 1;
    }
}