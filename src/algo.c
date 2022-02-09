/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:14:40 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/09 11:53:50 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *stack)
{
	t_stack	*head;
	t_stack	*head1;

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

int	getnmax(t_stack *stack, int n)
{
	t_stack	*head;
	int		pos;
	int		i;

	head = stack;
	pos = 0;
	i = 0;
	while (head)
	{
		if (head->index == n)
		{
			pos = i;
			break ;
		}
		head = head->next;
		i++;
	}
	return (pos);
}

void	rb_rrb(t_stacks *stacks, int pos)
{
	int	stacksize;

	stacksize = ft_stacklenght(stacks->b);
	if (pos > stacksize / 2)
	{
		pos = stacksize - pos;
		while (pos != 0)
		{
			reverse_rotate_b(stacks);
			pos--;
		}
	}
	else if (pos <= stacksize / 2)
	{
		while (pos != 0)
		{
			rotate_b(stacks);
			pos--;
		}
	}
}

void	pushback_b(t_stacks *stacks, int i, int range_max)
{
	int	pos;

	while (stacks->b)
	{
		while (i > 0 && i >= range_max - 5)
		{
			pos = getnmax(stacks->b, i);
			rb_rrb(stacks, pos);
			push_a(stacks);
			i--;
		}
		range_max -= 5;
	}
}

void	index_sort(t_stacks *stacks, int chunk)
{
	int	range_max;
	int	i;

	set_index(stacks->a);
	range_max = 0;
	i = 1;
	while (stacks->a != NULL)
	{
		range_max += chunk;
		while (i <= range_max)
		{
			if (!(stacks->a))
				break ;
			if (stacks->a->index <= range_max)
			{
				push_b(stacks);
				i++;
			}
			else
				rotate_a(stacks);
		}
	}
	i--;
	pushback_b(stacks, i, range_max);
}
