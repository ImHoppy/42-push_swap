/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:30:46 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/09 12:02:33 by mbraets          ###   ########.fr       */
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

int	sorted(t_stack *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (0);
	while (lst->next != NULL)
	{
		if (lst->content < lst->next->content)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}
