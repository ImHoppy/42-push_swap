/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:53:13 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/24 04:02:40 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stacks)
{
	// t_stack *stack;
	t_stack *temp[2];

	// stack = stacks->a;
	temp[0] = stack_pop(stacks);
	temp[1] = stack_pop(stacks);
	stack_push(stacks, temp[0]);
	stack_push(stacks, temp[1]);
}
void	swap_b(t_stacks *stacks);
void	swap_both(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	rotate_both(t_stacks *stacks);
void	rev_rotate_a(t_stacks *stacks);
void	rev_rotate_b(t_stacks *stacks);
void	rev_rotate_both(t_stacks *stacks);