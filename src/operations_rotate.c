/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:00:36 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/04 12:26:38 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*temp;

	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	stack = &stacks->a;
	temp = stack_pop(stack);
	ft_stackadd_back(stack, temp);
	ft_lstadd_back(&stacks->result, ft_lstnew("ra"));
}

void	rotate_b(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*temp;

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	stack = &stacks->b;
	temp = stack_pop(stack);
	ft_stackadd_back(stack, temp);
	ft_lstadd_back(&stacks->result, ft_lstnew("rb"));
}

/**
 * 0 : last
 * 1 : beforelast
 */
void	reverse_rotate_a(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*temp[2];

	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	stack = &stacks->a;
	temp[0] = ft_stacklast(*stack);
	temp[1] = ft_stackbeforelast(*stack);
	temp[1]->next = NULL;
	temp[0] = stack_pop(&temp[0]);
	ft_stackadd_front(stack, temp[0]);
	ft_lstadd_back(&stacks->result, ft_lstnew("rra"));
}

/**
 * 0 : last
 * 1 : beforelast
 */
void	reverse_rotate_b(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*temp;

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	stack = &stacks->b;
	temp = ft_stacklast(*stack);
	temp = stack_pop(&temp);
	ft_stackadd_front(stack, temp);
	ft_lstadd_back(&stacks->result, ft_lstnew("rrb"));
}
