#include "pushswap.h"

void pa(t_stack *stack_b, t_stack *stack_a)
{
    if (stack_b->size == 0)
        return;  // Si STACK_B est vide, il n'y a rien à pousser

    t_node *first_element = stack_b->top;  // Prendre l'élément en tête de STACK_B

    // Mettre à jour le top de STACK_B
    stack_b->top = stack_b->top->next;

    // Ajouter l'élément en haut de STACK_A
    first_element->next = stack_a->top;
    stack_a->top = first_element;

    // Mettre à jour les tailles des piles
    stack_b->size--;
    stack_a->size++;
}
