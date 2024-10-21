#include "pushswap.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (stack == NULL)
	{
		ft_printf("stack vide");
		//return(0);
	}
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		ft_printf("echec allocation push");
	}
	new_node->value = value;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
	if (stack->size == 1 || value < stack->min)
		stack->min = value;
	if (stack->size == 1 || value > stack->max)
		stack->max = value;
	if (stack->size % 10 == 0)
		initialize_chunks(stack);
}

int	pop(t_stack *stack)
{
	t_node	*tmp;
	int		value;

	if (stack == NULL)
		return(0);
	value = stack->top->value;
	tmp = stack->top;
	stack->top = stack->top->next;
	stack->size--;
	free(tmp);
	if (stack->size == 0)
	{
		stack->min = INT_MAX;
		stack->max = INT_MIN;
	}
	else if (value == stack->min || value == stack->max)
	{
		udapte_stack_minmax(stack);
	}
	if (stack->size % 10 == 0)
		initialize_chunks(stack);
	return (value);
}
void	sa(t_stack *stack_a)
{
	int tmp;
	if (stack_a->size >= 2)
	{
		tmp = stack_a->top->value;
		// Stocke la valeur du premier élément
		stack_a->top->value = stack_a->top->next->value;
		// Échange avec la valeur du second élément
		stack_a->top->next->value = tmp;
		// Met à jour la valeur du second élément
	}
}

void	sb(t_stack *stack_b)
{
	int	tmp;

	if (stack_b->size >= 2)
	{
		tmp = stack_b->top->value;
		stack_b->top->value = stack_b->top->next->value;
		stack_b->top->next->value = tmp;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a);  // Swap sur la pile A
    sb(stack_b);  // Swap sur la pile B
}
