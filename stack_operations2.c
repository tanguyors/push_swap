#include "pushswap.h"

void	ra(t_stack *stack_a)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->size >= 2)
	{
		first = stack_a->top;              // Détache le premier élément (top)
		stack_a->top = stack_a->top->next; // Le deuxième élément devient le nouveau top
		last = stack_a->top;               // Trouver le dernier
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = first; // Ajouter l'ancien top a la fin
		first->next = NULL; // le nouveau dernier élément pointe sur nul
	}
}

void	rb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->size >= 2)
	{
		first = stack_b->top;
		stack_b->top = stack_b->top->next;
		last = stack_b->top;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = first;
		first->next = NULL;
	}
}
void	rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a);
    rb(stack_b);
}