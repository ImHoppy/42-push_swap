/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 16:23:11 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/09 12:10:09 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strisdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && (s[i] == '-' || s[i] == '+'))
			i++;
		else if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

void	error(t_stacks *stacks)
{
	ft_putstr_fd("Error\n", 2);
	if (stacks == NULL)
		exit(EXIT_FAILURE);
	if (stacks->a != NULL)
		ft_stackclear(&stacks->a);
	if (stacks->b != NULL)
		ft_stackclear(&stacks->b);
	if (stacks->result != NULL)
		ft_lstclear(&stacks->result, NULL);
	free(stacks);
	exit(EXIT_FAILURE);
}

int	find_duplicate_stack(t_stack *stack)
{
	t_stack	*head;
	t_stack	*current;

	head = stack;
	while (head != NULL)
	{
		current = stack;
		while (current != NULL)
		{
			if (head->content == current->content && head != current)
				return (1);
			current = current->next;
		}
		head = head->next;
	}
	return (0);
}

void	ft_putendl(void *s)
{
	if (s)
	{
		ft_putstr_fd((char *)s, 1);
		ft_putchar_fd('\n', 1);
	}
}
