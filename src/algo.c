/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:14:40 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/28 17:31:19 by mbraets          ###   ########.fr       */
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
	int		index;
	int		middle;
	int		vmin;

	head = stacks->a;
	middle = indexof_min(stacks->a);
	vmin = min(stacks->a);
	while (index <= middle)
	{

	}

}
