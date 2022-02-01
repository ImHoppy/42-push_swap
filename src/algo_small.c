/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 20:27:44 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/01 14:11:19 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	number_3_next(t_stacks *stacks, t_stack *last)
{
	t_stack	*a;

	a = stacks->a;
	if (a->content < a->next->content && a->next->content > last->content
		&& a->content > last->content)
		reverse_rotate_a(stacks);
	else if (a->content > a->next->content && a->next->content < last->content
		&& a->content > last->content)
		rotate_a(stacks);
}

void	number_3(t_stacks *stacks)
{
	t_stack	*a;
	t_stack	*last;

	a = stacks->a;
	last = ft_stacklast(a);
	if (a->content > a->next->content && a->next->content < last->content
		&& a->content < last->content)
		swap_a(stacks);
	else if (a->content > a->next->content && a->next->content > last->content
		&& a->content > last->content)
	{
		swap_a(stacks);
		reverse_rotate_a(stacks);
	}
	else if (a->content < a->next->content && a->next->content > last->content
		&& a->content < last->content)
	{
		reverse_rotate_a(stacks);
		swap_a(stacks);
	}
	else
		number_3_next(stacks, last);
}

void	number_4(t_stacks *stacks)
{
	push_stack_top_a(stacks, getmin(stacks->a));
	push_b(stacks);
	number_3(stacks);
	push_a(stacks);
}

void	number_5(t_stacks *stacks)
{
	push_stack_top_a(stacks, getmin(stacks->a));
	push_b(stacks);
	push_stack_top_a(stacks, getmin(stacks->a));
	push_b(stacks);
	number_3(stacks);
	push_a(stacks);
	push_a(stacks);
}