/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:36:29 by torsini           #+#    #+#             */
/*   Updated: 2024/10/21 17:30:44 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*t_stack	*create_stack(void)
{
	t_stack *new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (new_stack == NULL)
	{
		ft_printf("Memoire alloc error");
		return (NULL);
	}
	new_stack->top = NULL;
	new_stack->size = 0;
    new_stack->chunk_size = 0;
    new_stack->max = INT_MIN; // la valeurs minimale ne pourra jamais etre en dessous de int min
    new_stack->min = INT_MAX; // la veleurs maximum ne pourra jamais etre au dessus de int max 
	return (new_stack);
}*/

t_stack *init_stack(t_stack *stack, int value)
{
    // Allouer la mémoire pour la nouvelle pile si elle n'existe pas encore
    stack = malloc(sizeof(t_stack));
    if (!stack)
    {
        ft_printf("Memory allocation error\n");
        return (NULL);
    }

    // Initialiser la pile avec les valeurs par défaut
    stack->top = NULL;
    stack->size = 0;
    stack->chunk_size = 0;
    stack->max = INT_MIN;
    stack->min = INT_MAX;

    // Ajouter l'élément initial (premier élément) dans la pile
    t_node *new_node = malloc(sizeof(t_node));
    if (!new_node)
    {
        ft_printf("Memory allocation error\n");
        free(stack);  // Libérer la pile si le nœud échoue
        return (NULL);
    }

    // Initialiser le nœud avec la première valeur
    new_node->value = value;
    new_node->next = NULL;  // Premier nœud, donc aucun suivant

    // Mettre à jour le sommet de la pile
    stack->top = new_node;
    stack->size = 1;  // Il y a maintenant un élément dans la pile

    // Mettre à jour les valeurs min et max avec cette première valeur
    stack->min = value;
    stack->max = value;

    return stack;
}


void free_stack(t_stack *stack_to_free)
{
    t_node *current_node;
    t_node *next_node;

    if (stack_to_free == NULL)
        return;

    current_node = stack_to_free->top;
    while (current_node)
    {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }

    free(stack_to_free);
}

int     stack_is_empty(t_stack *stack)
{
    return(stack == NULL || stack->top == NULL);
}

void    udapte_stack_minmax(t_stack *stack)
{
    t_node *current;
    
    stack->min = stack->top->value;
    stack->max = stack->top->value;
    current = stack->top;
    
    while(current)
    {
        if(current->value < stack->min)
            stack->min = current->value;
        if(current->value > stack->max)
            stack->max = current->value;
        current = current->next;
    }
}