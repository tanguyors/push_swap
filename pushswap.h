/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:00:00 by torsini           #+#    #+#             */
/*   Updated: 2024/10/21 15:14:37 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	int				chunk_size;
	int				min;
	int				max;
}					t_stack;

t_stack				*create_stack(void);
int					pop(t_stack *stack);
int 				is_valid_number(const char *str);
int 				is_duplicate(t_stack *stack, int value);
int 				init_stack_with_args(t_stack *stack_a, int argc, char **argv);
int					calculate_cost_stack_a(t_stack *stack_a, int element_position);
int					calculate_cost_in_stack_b(t_stack *stack_b, int value);
int					find_best_move(t_stack *stack_a, t_stack *stack_b);
int     			stack_is_empty(t_stack *stack);

void				push(t_stack *stack, int value);
void				sa(t_stack *stack_a);
void				sb(t_stack *stack_b);
void				ss(t_stack *stack_a, t_stack *stack_b);
void				pa(t_stack *stack_a, t_stack *stack_b);
void				pb(t_stack *stack_b, t_stack *stack_a);
void				ra(t_stack *stack_a);
void				rb(t_stack *stack_b);
void				rr(t_stack *stack_a, t_stack *stack_b);
void				rra(t_stack *stack_a);
void				rrb(t_stack *stack_b);
void				rrr(t_stack *stack_a, t_stack *stack_b);
void 				initialize_chunks(t_stack *stack);
void 				push_chunk_to_stack_b(t_stack *stack_a, t_stack *stack_b, int chunk_min, int chunk_max);
void 				perform_sort(t_stack *stack_a, t_stack *stack_b, int num_chunks);
void    			udapte_stack_minmax(t_stack *stack);
void 				free_stack(t_stack *stack_to_free);
void 				move_element_to_stack_a(t_stack *stack_a, t_stack *stack_b, int element_position);
void 				reinsert_from_stack_b(t_stack *stack_a, t_stack *stack_b);
void 				move_element_to_stack_b(t_stack *stack_a, t_stack *stack_b, int element_position);

#endif