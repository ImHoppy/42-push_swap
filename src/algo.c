/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:14:40 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/07 18:08:55 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



// USELESS
void	forward_index(t_stack *stack)
{
	t_stack *head;

	head = stack;
	while (head != NULL)
	{
		if (stack->content < head->content)
			head->index++;
		else
			stack->index++;
		head = head->next;
	}
}

int	which_chunk(t_stack *stack, int chunk)
{
	// int	max;

	// max = getmax(stack)
	while (chunk)
	{
		if (stack->index > 20*chunk)
		{
			break;
		}
		chunk--;
	}
	return (chunk + 1);
}

#include <stdio.h>
void	set_index(t_stack *stack)
{
	t_stack *head;
	t_stack *head1;

	head = stack;
	while (head != NULL)
	{
		head1 = head;
		while (head1 != NULL)
		{
			if (head->content < head1->content)
				head1->index++;
			else
				head->index++;
			head1 = head1->next;
		}
		head = head->next;
	}
}

int	push_b_chunk(t_stacks *stacks, int chunk, int currentchunk)
{
	t_stack	*head;
	int		i;
	int		j;

	t_stack	*topush;
	t_stack	*topush2;

	head = stacks->a;
	topush = NULL;
	i = 0;
	while (head != NULL)
	{
		if (which_chunk(head, chunk) == currentchunk)
		{
			topush = head;
			break;
		}
		i++;
		head = head->next;
	}
	if (topush == NULL)
		return (0);
	j = 0;
	head = ft_stacklast(stacks->a);
	while (head != NULL)
	{
		if (which_chunk(head, chunk) == currentchunk)
		{
			topush2 = head;
			break;
		}
		j++;
		head = head->prev;
	}
	// printf("%d:%d {%d:%d}\n", );
	if (i < j)
	{
		push_stack_top_a(stacks, topush);
	}
	else
	{
		push_stack_top_a(stacks, topush2);
	}
	return (1);
}
void	chunk_sort(t_stacks *stacks, int chunk)
{
	int	len;
	set_index(stacks->a);
	len = ft_stacklenght(stacks->a);
	if (chunk != 5 | chunk != 11)
		chunk = len / 20;
	for (t_stack *head = stacks->a; head != NULL; head = head->next) {
		// dprintf(1, "{%d} ", which_chunk(head, 5));
	}
	// dprintf(1, "\n");
	int	currentchunk = 0;
	t_stack *min;
	t_stack *max;
	while (currentchunk++ < chunk)
	{
		while (push_b_chunk(stacks, chunk, currentchunk))
		{
			min = getmin(stacks->b);
			max = getmax(stacks->b);
			// if (stacks->b != NULL && stacks->b->next != NULL)
			// {
				// if (min != NULL)
				// 	push_stack_top_b(stacks, getmax(stacks->b));
			// }
			push_b(stacks);
			// if (stacks->b->next != NULL && stacks->b->next->next != NULL && stacks->b->next->content > stacks->b->content && stacks->b->next->next->content > stacks->b->content)
				// swap_b(stacks);
		}
	}
	while (stacks->b != NULL)
	{
		push_stack_top_b(stacks, getmax(stacks->b));
		push_a(stacks);
	}
	// while (push_b_chunk(stacks, 5, 2))
	// 	push_b(stacks);
	// while (push_b_chunk(stacks, 5, 3))
	// 	push_b(stacks);
	// while (push_b_chunk(stacks, 5, 4))
	// 	push_b(stacks);
	// while (push_b_chunk(stacks, 5, 5))
	// 	push_b(stacks);
	// for (int i = 0; i != 100; i++)
	// push_b_chunk(stacks, chunk, 1);
	// t_stack *i = stacks->a;
	// printf("%d %d\n", stacks->a->index, i->index == 100);
	// while (i->index != 100){
	// 	// printf(":%d\n", i->index);
	// 	if (i->index == 1)
	// 		push_stack_top_a(stacks, i);
	// 	i = i->next;
	// }
	// printf("%d", stacks->a->index);
	
	// for (t_stack *head = stacks->a; head != NULL; head = head->next) {
	// 	printf("{%d} ", which_chunk(head, 5));
	// }
}


void	insertion_sort(t_stacks *stacks)
{
	while (stacks->a != NULL)
	{
		push_stack_top_a(stacks, getmin(stacks->a));
		push_b(stacks);
	}
	while (stacks->b != NULL)
		push_a(stacks);
}

int	sumStack(t_stack *stack)
{
	t_stack	*head;
	int		sum;

	head = stack;
	sum = 0;
	while (head != NULL)
	{
		sum += head->content;
		head = head->next;
	}
	return (sum);
}




void	push_average_a(t_stacks *stacks, t_stack *topush, int average)
{
	while (stacks->a != topush)
	{
		if (stacks->a->content <= average)
			push_b(stacks);
		else
			rotate_a(stacks);
	}
}

void	split_stack_a(t_stacks *stacks)
{
	int		size;
	int		average;
	t_stack	*min;
	
	size = ft_stacklenght(stacks->a);
	average = sumStack(stacks->a) / size;
	min = getmin(stacks->a);
	while (min->content <= average)
	{
		if (stacks->a->content <= average)
			push_b(stacks);
		else
			push_average_a(stacks, min, average);
		min = getmin(stacks->a);
	}
}
#include <stdio.h>
int	calc_distance(t_stack *stack, t_stack *min, t_stack *max)
{
	// int	min_index;
	// int	max_index;
	// int min_res;
	// int max_res;
	int	size;
	// int ret;
	int	i = 0;
	t_stack *head = stack;
	size = ft_stacklenght(stack);
	while (i <= size / 2 && head != NULL && head->next != NULL)
	{
		if (head == min)
			return (0);
		if (head == max)
			return (1);
		head = head->next;
		i++;
	}

	i = size / 2;
	while (i < size && head != NULL && head->next != NULL)
	{
		if (head == min)
			return (1);
		if (head == max)
			return (0);
		head = head->next;
		i++;
	}
	// min_index = indexof(stack, min);
	// max_index = indexof(stack, max);
	// min_res = 	min_index  ;
	// max_res = 	max_index  ;
	
	// ret = min_res < max_res;
	return (0);
}

int	push_max_min(t_stacks *stacks)
{
	t_stack	*min;
	t_stack	*max;
	int		maxaction;

	maxaction = 0;
	while (stacks->b != NULL)
	{

		min = getmin(stacks->b);
		max = getmax(stacks->b);
		if (stacks->b == max)
		{
			push_a(stacks);
			maxaction++;
		}
		if (stacks->b == min)
		{
			push_a(stacks);
			rotate_a(stacks);
		}
		// printf("%d\n",calc_distance(stacks->b, min, max));
		if (calc_distance(stacks->b, min, max) == 0)
			reverse_or_rotate_b(stacks, min);
		else
			reverse_or_rotate_b(stacks, max);
		// rotate_b(stacks);
	}
	return (maxaction);
}

void	quarter_sort(t_stacks *stacks)
{

	split_stack_a(stacks);
	int remaning = ft_stacklenght(stacks->a);
	int max = push_max_min(stacks);
	while (max-- != 0)
	{
		rotate_a(stacks);
	}
	while (remaning-- != 0)
	{
		push_b(stacks);
	}

	max = push_max_min(stacks);

	while (max-- != 0)
	{
		rotate_a(stacks);
	}
	// split_stack_a(stacks);
	// split_stack_b(stacks);
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