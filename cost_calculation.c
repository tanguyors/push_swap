#include "pushswap.h"

// calculate_cost_stack_a
// calculate_cost_stack_b
// find_best_move
// perform_sort

int	calculate_cost_stack_a(t_stack *stack_a, int element_position)
{
	int	stack_size;

	// Obtenir la taille de la pile
	stack_size = stack_a->size;
	// Si l'élément est dans la première moitié,
	// ra (rotation vers le haut)
	if (element_position <= stack_size / 2)
	{
		return (element_position); // Le coût est la position dans la pile (ra)
	}
	else
	{
		// rra (rotation vers le bas)
		return (stack_size - element_position);
		// Le coût est la distance depuis le bas (rra)
	}
}

int	calculate_cost_in_stack_b(t_stack *stack_b, int value)
{
	t_node	*current;
	int		position;
	int		size;

	position = 0;
	size = stack_b->size;
	current = stack_b->top;
	while (current != NULL)
	{
		if ((current->value < value && (current->next == NULL
					|| current->next->value > value)))
		{
			if (postion <= size / 2)
				return (position);
			else
				return (size - position);
		}
		current = current->next;
		position++;
	}
	return (0);
}

int	find_best_move(t_stack *stack_a, t_stack *stack_b)
{
	int		best_move_index;
	int		best_cost;
	int		current_cost;
	int		i;
	int		cost_a;
	int		cost_b;
	t_node	*current;

	best_move_index = -1;
	best_cost = INT_MAX;
	i = 0;
	current = stack_a->top; // demarré par le sommet de a
	while (current != NULL)
	{
		cost_a = calculate_cost_in_stack_a(stack_a, i);
		cost_b = calculate_cost_in_stack_b(stack_b, current->value);
		current_cost = cost_a + cost_b;
		if (current_cost < best_cost)
		{
			best_cost = current_cost;
			best_move_index = i;
		}
		current = current->next;
		i++;
	}
	return (best_move_index);
} 