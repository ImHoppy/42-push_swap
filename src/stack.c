/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:07:01 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/08 14:08:20 by mbraets          ###   ########.fr       */
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

// USELESS
void	ft_stackadd_front(t_stack **alst, t_stack *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = *alst;
	new->next->prev = new;
	*alst = new;
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

int	ft_stacklenght(t_stack *lst)
{
	int	len;

	len = 1;
	if (lst == NULL)
		return (0);
	lst = lst->next;
	if (lst != NULL)
		len += ft_stacklenght(lst);
	return (len);
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*list;
	t_stack	*old;

	if (lst == NULL)
		return ;
	list = *lst;
	while (list != NULL)
	{
		old = list->next;
		if (list != NULL)
		{
			free(list);
		}
		list = old;
	}
	*lst = 0;
}

t_stack	*ft_stacklast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// USELESS
t_stack	*ft_stackbeforelast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL && lst->next->next != NULL)
		lst = lst->next;
	return (lst);
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

int	reverse_sorted(t_stack *lst)
{
	if (lst == NULL || lst->next == NULL)
		return (0);
	while (lst->next != NULL)
	{
		if (lst->content > lst->next->content)
			lst = lst->next;
		else
			return (0);
	}
	return (1);
}
