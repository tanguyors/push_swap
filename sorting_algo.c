#include "pushswap.h"

void perform_sort(t_stack *stack_a, t_stack *stack_b, int num_chunks)
{
    int total_elements = stack_a->size;
    int chunk_size = total_elements / num_chunks;
    int chunk = 0;

    // Parcourir les chunks avec une boucle while
    while (chunk < num_chunks)
    {
        int chunk_min = chunk * chunk_size;
        int chunk_max = (chunk + 1) * chunk_size - 1;

        // Appeler push_chunk_to_stack_b pour déplacer les éléments de ce chunk
        push_chunk_to_stack_b(stack_a, stack_b, chunk_min, chunk_max);

        chunk++;
    }

    // Réinsérer les éléments de STACK_B dans STACK_A avec une boucle while
    reinsert_from_stack_b(stack_a, stack_b);
}

