#include "pushswap.h"

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size == 0)
		return ; // Rien à pousser si STACK_A est vide
	t_node *first_element = stack_a->top;
		// Prendre l'élément en tête de STACK_A
	// Mettre à jour le top de STACK_A
	stack_a->top = stack_a->top->next;
	// Ajouter l'élément en haut de STACK_B
	first_element->next = stack_b->top;
	stack_b->top = first_element;
	// Mettre à jour les tailles des piles
	stack_a->size--;
	stack_b->size++;
}

