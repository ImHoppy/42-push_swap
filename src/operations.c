/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 05:53:13 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/25 14:07:17 by mbraets          ###   ########.fr       */
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


void	reverse_rotate_a(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*temp[2];

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	stack = &stacks->b;
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
 * 2 : first  
 */
void	reverse_rotate_b(t_stacks *stacks)
{
	t_stack	**stack;
	t_stack	*temp[3];

	if (stacks->b == NULL || stacks->b->next == NULL)
		return ;
	stack = &stacks->b;
	temp[0] = ft_stacklast(*stack);
	temp[1] = ft_stackbeforelast(*stack);
	temp[1]->next = NULL;
	temp[0] = stack_pop(&temp[0]);
	temp[2] = stack_pop(stack);
	// temp[2]->next = NULL;
	ft_stackadd_back(stack, temp[2]);
	ft_stackadd_front(stack, temp[0]);
	ft_lstadd_back(&stacks->result, ft_lstnew("rrb"));
}