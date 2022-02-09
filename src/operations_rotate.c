/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:00:36 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/08 14:09:30 by mbraets          ###   ########.fr       */
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
// add_front to stack_push
void	reverse_rotate_a(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*last;

	if (stacks->a == NULL || stacks->a->next == NULL)
		return ;
	stack = &stacks->a;
	last = ft_stacklast(*stack);
	last->prev->next = NULL;
	last = stack_pop(&last);
	stack_push(stack, last);
	ft_lstadd_back(&stacks->result, ft_lstnew("rra"));
}

/**
 * 0 : last
 * 1 : beforelast
 */
// add_front to stack_push
void	reverse_rotate_b(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*last;

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	stack = &stacks->b;
	last = ft_stacklast(*stack);
	if (last->prev != NULL)
		last->prev->next = NULL;
	last = stack_pop(&last);
	stack_push(stack, last);
	ft_lstadd_back(&stacks->result, ft_lstnew("rrb"));
}
