#include "pushswap.h"

void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	if (stack == NULL)
	{
		ft_printf("stack vide");
		return (0);
	}
	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
	{
		ft_printf("echec allocation push");
		return (NULL);
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
    t_node *tmp;
    int value;

    if(stack == NULL)
        return(NULL);
    value = stack->top->value;
    tmp = stack->top;
    stack->top = stack->top->next;
    stack->SIZE--;
    free(tmp);
    if(stack->size == 0)
    {
        stack->min = INT_MAX;
        stack->max = INT_MIN;
    }
    else if(value == stack->min || value == stack->max)
    {
        udapte_stack_minmax(stack);
    }
    if (stack->size % 10 == 0)
		initialize_chunks(stack);
    return(value);
}
