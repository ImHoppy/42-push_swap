/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:06:43 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/09 12:10:28 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacknew(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	*new = (t_stack){.content = content};
	return (new);
}

void	ft_stackadd_back(t_stack **alst, t_stack *new)
{
	t_stack	*last;

	if (alst == NULL || new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	new->next = NULL;
	last = ft_stacklast(*alst);
	if (last != NULL)
	{
		last->next = new;
	}
	new->prev = last;
}

t_stack	*stack_pop(t_stack **stack)
{
	t_stack	*popped;

	popped = *stack;
	(*stack) = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	if (popped->prev != NULL)
		popped->prev->next = NULL;
	popped->next = NULL;
	popped->prev = NULL;
	return (popped);
}

void	stack_push(t_stack **stack, t_stack *new)
{
	if (new == NULL)
		return ;
	if (stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		if (new->next != NULL)
			new->next->prev = new;
		*stack = new;
	}
}
