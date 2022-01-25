/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:53:13 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/25 15:01:47 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * 0 : first
 * 1 : second
 */
void	swap_a(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*temp[2];

	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	stack = &stacks->a;
	temp[0] = stack_pop(stack);
	temp[1] = stack_pop(stack);
	stack_push(stack, temp[0]);
	stack_push(stack, temp[1]);
	ft_lstadd_back(&stacks->result, ft_lstnew("sa"));
}

/**
 * 0 : first
 * 1 : second
 */
void	swap_b(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*temp[2];

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	stack = &stacks->b;
	temp[0] = stack_pop(stack);
	temp[1] = stack_pop(stack);
	stack_push(stack, temp[0]);
	stack_push(stack, temp[1]);
	ft_lstadd_back(&stacks->result, ft_lstnew("sb"));
}

void	push_a(t_stacks *stacks)
{
	t_stack	*temp;

	if (stacks->b == NULL)
		return ;
	temp = stack_pop(&stacks->b);
	stack_push(&stacks->a, temp);
	ft_lstadd_back(&stacks->result, ft_lstnew("pa"));
}

void	push_b(t_stacks *stacks)
{
	t_stack	*temp;

	if (stacks->a == NULL)
		return ;
	temp = stack_pop(&stacks->a);
	stack_push(&stacks->b, temp);
	ft_lstadd_back(&stacks->result, ft_lstnew("pb"));
}
