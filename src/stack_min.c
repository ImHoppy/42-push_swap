/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:30:46 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/31 19:55:11 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexof_min(t_stack *stack)
{
	int		i;
	int		min[2];
	t_stack	*head;

	i = 0;
	head = stack;
	min[0] = head->content;
	min[1] = i;
	while (head != NULL)
	{
		if (head->content < min[0])
		{
			min[0] = head->content;
			min[1] = i;
		}
		head = head->next;
		i++;
	}
	return (min[1]);
}

int	min(t_stack *stack)
{
	int		i;
	int		min;
	t_stack	*head;

	i = 0;
	head = stack;
	min = head->content;
	while (head != NULL)
	{
		if (head->content < min)
		{
			min = head->content;
		}
		head = head->next;
		i++;
	}
	return (min);
}

void	push_min_top_a(t_stacks *stacks)
{
	int		len;
	int		middle;
	int		vmin;
	void	(*ptr)(t_stacks*);

	len = ft_stacklenght(stacks->a);
	middle = indexof_min(stacks->a);
	vmin = min(stacks->a);
	if (middle < len / 2)
		ptr = &rotate_a;
	else
		ptr = &reverse_rotate_a;
	while (stacks->a->content != vmin)
		ptr(stacks);
}

void	push_min_top_b(t_stacks *stacks)
{
	int		len;
	int		middle;
	int		vmin;
	void	(*ptr)(t_stacks*);

	len = ft_stacklenght(stacks->b);
	middle = indexof_min(stacks->b);
	vmin = min(stacks->b);
	if (middle < len / 2)
		ptr = &rotate_b;
	else
		ptr = &reverse_rotate_b;
	while (stacks->a->content != vmin)
		ptr(stacks);
}