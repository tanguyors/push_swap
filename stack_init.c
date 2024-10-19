/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:36:29 by torsini           #+#    #+#             */
/*   Updated: 2024/10/19 18:57:48 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*create_stack(void)
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
}

void initialize_chunks(t_stack *stack)
{
    if (stack == NULL || stack->size == 0)
        return;
    stack->chunk_size = (int)sqrt(stack->size);  // racine pour determiner un nombre de chunks
    if (stack->chunk_size == 0)
    {
        stack->chunk_size = 1;
    }
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