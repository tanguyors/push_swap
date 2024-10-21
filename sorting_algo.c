#include "pushswap.h"

void	move_element_to_stack_b(t_stack *stack_a, t_stack *stack_b, int element_position)
{
	int	stack_size;
	int	rotations_needed;

	stack_size = stack_a->size;
	// Si l'élément est dans la première moitié de la pile, utiliser ra
	if (element_position <= stack_size / 2)
	{
		// Effectuer des rotations vers le haut avec ra
		while (element_position > 0)
		{
			ra(stack_a); // Rotation vers le haut
			element_position--;
		}
	}
	else
	{
		rotations_needed = stack_size - element_position;
		// Effectuer des rotations inverses avec rra
		while (rotations_needed > 0)
		{
			rra(stack_a); // Rotation vers le bas
			rotations_needed--;
		}
	}
	pb(stack_a, stack_b); // Push dans STACK_B
}
