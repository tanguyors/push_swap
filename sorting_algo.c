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
		utiliser ra (rotation vers le haut)
	if (element_position <= stack_size / 2)
	{
		return (element_position); // Le coût est la position dans la pile (ra)
	}
	else
	{
		// Si l'élément est dans la deuxième moitié,
			utiliser rra (rotation vers le bas)
		return (stack_size - element_position);
			// Le coût est la distance depuis le bas (rra)
	}
}
