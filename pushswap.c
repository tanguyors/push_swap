#include "pushswap.h"

void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    ft_printf("Stack (size: %d): ", stack->size);
    while (current)
    {
        ft_printf("%d ", current->value);
        current = current->next;
    }
    ft_printf("\n");
}

void print_chunks(t_stack *stack)
{
    t_node *current = stack->top;
    ft_printf("Chunks: ");
    while (current)
    {
        ft_printf("%d ", current->chunk);
        current = current->next;
    }
    ft_printf("\n");
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        ft_printf("Usage: %s <list of integers>\n", argv[0]);
        return (1);
    }

    t_stack *stack_a = create_stack();
    t_stack *stack_b = create_stack();

    if (!stack_a || !stack_b)
    {
        ft_printf("Error: Unable to initialize stacks\n");
        return (1);
    }

    // Initialisation des piles avec les valeurs de la ligne de commande
    for (int i = 1; i < argc; i++)
    {
        if (!is_valid_number(argv[i]) || is_duplicate(stack_a, atoi(argv[i])))
        {
            ft_printf("Error: Invalid input or duplicate value\n");
            free_stack(stack_a);
            free_stack(stack_b);
            return (1);
        }
        push(stack_a, atoi(argv[i]));
    }

    // Afficher la pile initiale
    ft_printf("Initial stack:\n");
    print_stack(stack_a);

    // Initialiser et assigner les chunks
    initialize_chunks(stack_a);
    assign_chunks(stack_a);

    // Afficher les chunks
    ft_printf("Chunks after initialization:\n");
    print_chunks(stack_a);

    // Pousser les chunks dans stack_b
    ft_printf("Pushing chunks to stack_b:\n");
    push_chunk_to_stack_b(stack_a, stack_b, 0, stack_a->chunk_size - 1);
    print_stack(stack_a);
    print_stack(stack_b);

    // Réinsérer les éléments de stack_b dans stack_a
    ft_printf("Reinserting chunks from stack_b to stack_a:\n");
    reinsert_from_stack_b(stack_a, stack_b);
    print_stack(stack_a);
    print_stack(stack_b);

    // Libérer la mémoire
    free_stack(stack_a);
    free_stack(stack_b);

    return (0);
}