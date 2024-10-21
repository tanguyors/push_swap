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

void push_chunk_to_stack_b(t_stack *stack_a, t_stack *stack_b, int chunk_min, int chunk_max)
{
    t_node *current = stack_a->top;
    int position = 0;

    // Parcourir STACK_A et pousser les éléments appartenant au chunk dans STACK_B
    while (current != NULL)
    {
        // Si la valeur de l'élément est dans les limites du chunk, on le pousse dans STACK_B
        if (current->value >= chunk_min && current->value <= chunk_max)
        {
            // Déplacer l'élément vers STACK_B
            move_element_to_stack_b(stack_a, stack_b, position);

            // Réinitialiser la recherche car STACK_A est modifiée après le push
            current = stack_a->top;
            position = 0;
        }
        else
        {
            current = current->next;
            position++;
        }
    }
}