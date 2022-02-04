/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_top.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:30:46 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/04 11:14:02 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	indexof(t_stack *stack, t_stack *tofind)
{
	int		i;
	t_stack	*head;

	i = 0;
	head = stack;
	while (head != NULL)
	{
		if (head->content == tofind->content)
			return (i);
		head = head->next;
		i++;
	}
	return (i);
}

t_stack	*getmin(t_stack *stack)
{
	int		i;
	t_stack	*min;
	t_stack	*head;

	i = 0;
	head = stack;
	min = head;
	while (head != NULL)
	{
		if (head->content < min->content)
			min = head;
		head = head->next;
		i++;
	}
	return (min);
}

t_stack	*getmax(t_stack *stack)
{
	int		i;
	t_stack	*max;
	t_stack	*head;

	i = 0;
	head = stack;
	max = head;
	while (head != NULL)
	{
		if (head->content > max->content)
			max = head;
		head = head->next;
		i++;
	}
	return (max);
}

void	push_stack_top_a(t_stacks *stacks, t_stack *topush)
{
	int		len;
	int		middle;
	void	(*ptr)(t_stacks*);

	len = ft_stacklenght(stacks->a);
	middle = indexof(stacks->a, topush);
	if (middle <= len / 2)
		ptr = &rotate_a;
	else
		ptr = &reverse_rotate_a;
	while (stacks->a != topush)
		ptr(stacks);
}

void	push_stack_top_b(t_stacks *stacks, t_stack *topush)
{
	int		len;
	int		middle;
	// int		value;
	void	(*ptr)(t_stacks*);

	len = ft_stacklenght(stacks->b);
	middle = indexof(stacks->b, topush);
	// value = topush->content;
	if (middle <= len / 2)
		ptr = &rotate_b;
	else
		ptr = &reverse_rotate_b;
	while (stacks->b != topush)
		ptr(stacks);
}
