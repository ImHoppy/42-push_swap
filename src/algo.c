/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:14:40 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/31 20:48:56 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



void	insertion_sort(t_stacks *stacks, int chunk)
{
	(void) chunk;
	while (stacks->a != NULL)
	{
		push_stack_top_a(stacks, getmin(stacks->a));
		push_b(stacks);
	}
	while (stacks->b != NULL)
		push_a(stacks);
}

void	quarter_sort(t_stacks *stacks)
{
	
}

// First attempt of creating my own sort

// void	insertion_sort(t_stacks *stacks, int chunk)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	t_stack	*last[2];

// 	// if (chunk == 0)
// 	if (sorted(stacks->a))
// 		return;
// 	a = stacks->a;
// 	b = stacks->b;
// 	last[0] =	ft_stacklast(a);
// 	last[1] =	ft_stacklast(b);
// 	while (a->next != NULL && !sorted(stacks->a))
// 	// while (chunk != 0)
// 	{
// 		if (a->content > last[0]->content)
// 		{
// 			rotate_a(stacks);
// 			last[0] = last[0]->next;
// 		}
// 		else if (a->content > a->next->content)
// 		{
// 			swap_a(stacks);
// 			// push_b(stacks);
// 		}
// 		else
// 		{
// 			push_b(stacks);
// 			if (stacks->b->next != NULL && stacks->b->content < stacks->b->next->content)
// 			{
// 				swap_b(stacks);
// 			}
// 			// if ()
// 		}
// 		if (last[1] != NULL && stacks->b->content < last[1]->content)
// 		{
// 			rotate_b(stacks);
// 			last[1] = ft_stacklast(b);
// 		}
// 		a = stacks->a;
// 	}

	
// 	b = stacks->b;
// 	last[1] = ft_stacklast(b);
// 	while (b != NULL && b->next != NULL )
// 	{
// 		if (last[1] != NULL && b->content > last[1]->content)
// 		{
// 			rotate_b(stacks);
// 			last[1] = last[1]->next;
// 		}
// 		else if (b->content > b->next->content)
// 		{
// 			swap_b(stacks);
// 			// push_b(stacks);
// 		}
// 		else if (stacks->a->content < stacks->b->content)
// 			push_a(stacks);
// 		else
// 		{
// 			push_a(stacks);
// 			if (stacks->a->next != NULL && stacks->a->content > stacks->a->next->content)
// 				swap_a(stacks);
// 		}
// 		b = stacks->b;
// 	}
// 	chunk--;
// 	if (stacks->b != NULL)
// 		push_a(stacks);
// 	insertion_sort(stacks, chunk);
// }