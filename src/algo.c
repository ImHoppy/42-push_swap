/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:14:40 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/31 19:55:31 by mbraets          ###   ########.fr       */
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
	push_min_top_a(stacks);
	push_b(stacks);
	number_3(stacks);
	push_a(stacks);
}

void	number_5(t_stacks *stacks)
{
	push_min_top_a(stacks);
	push_b(stacks);
	push_min_top_a(stacks);
	push_b(stacks);
	number_3(stacks);
	push_a(stacks);
	push_a(stacks);
}

void	insertion_sort(t_stacks *stacks, int chunk)
{
	(void) chunk;
	while (stacks->a != NULL)
	{
		push_min_top_a(stacks);
		push_b(stacks);
	}
	while (stacks->b != NULL)
		push_a(stacks);
}

// void	insertion_sort(t_stacks *stacks, int chunk)
// {
// 	t_stack	*a;
// 	t_stack	*b;
// 	t_stack	*last[2];

// 	// if (chunk == 0)
// 	if (isSorted(stacks->a))
// 		return;
// 	a = stacks->a;
// 	b = stacks->b;
// 	last[0] =	ft_stacklast(a);
// 	last[1] =	ft_stacklast(b);
// 	while (a->next != NULL && !isSorted(stacks->a))
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