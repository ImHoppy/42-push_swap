/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:14:40 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/28 17:53:19 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void number_3(t_stacks *stacks)
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
	else if (a->content < a->next->content && a->next->content > last->content
		&& a->content > last->content)
		reverse_rotate_a(stacks);
	else if (a->content > a->next->content && a->next->content < last->content
		&& a->content > last->content)
		rotate_a(stacks);
}

void number_4(t_stacks *stacks)
{
	t_stack	*head;
	int		len;
	int		middle;
	int		vmin;
	void	(*ptr)(t_stacks*);

	head = stacks->a;
	len = ft_stacklenght(stacks->a);
	middle = indexof_min(stacks->a);
	vmin = min(stacks->a);
	if (middle < len / 2)
		ptr = &rotate_a;
	else
		ptr = &reverse_rotate_a;
	while (stacks->a->content != vmin)
	{
		ptr(stacks);
	}
	push_b(stacks);
	number_3(stacks);
	push_a(stacks);
}

void number_5(t_stacks *stacks)
{
	push_b(stacks);
	number_4(stacks);
	push_a(stacks);
	swap_a(stacks);
	push_b(stacks);
	number_4(stacks);
	push_a(stacks);
}
