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
void 	move_element_to_stack_b(t_stack *stack_a, t_stack *stack_b, int element_position)
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
void reinsert_from_stack_b(t_stack *stack_a, t_stack *stack_b)
{
    // Tant que STACK_B n'est pas vide
    while (stack_b->size > 0)
    {
        // Chercher l'élément le plus approprié à réinsérer (ici on pourrait optimiser l'ordre)
        int best_move_index = find_best_move(stack_b, stack_a);

        // Amener cet élément au sommet et le déplacer dans STACK_A
        move_element_to_stack_a(stack_a, stack_b, best_move_index); // Fonction à implémenter
    }
}
void move_element_to_stack_a(t_stack *stack_a, t_stack *stack_b, int element_position)
{
    int stack_size = stack_b->size;

    // Si l'élément est dans la première moitié de la pile, utiliser rb
    if (element_position <= stack_size / 2)
    {
        // Effectuer des rotations vers le haut avec rb
        while (element_position > 0)
        {
            rb(stack_b);  // Rotation vers le haut de STACK_B
            element_position--;
        }
    }
    else
    {
        // Si l'élément est dans la deuxième moitié, utiliser rrb (rotation inverse)
        int rotations_needed = stack_size - element_position;

        // Effectuer des rotations inverses avec rrb
        while (rotations_needed > 0)
        {
            rrb(stack_b);  // Rotation inverse de STACK_B
            rotations_needed--;
        }
    }

    // Une fois l'élément au sommet, le pousser dans STACK_A
    pa(stack_b, stack_a);  // Push dans STACK_A
}
