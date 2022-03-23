/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:07:01 by mbraets           #+#    #+#             */
/*   Updated: 2022/02/09 12:10:01 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
