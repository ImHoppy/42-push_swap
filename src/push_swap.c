/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:54:04 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/17 16:35:42 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_strisdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(ft_isdigit(s[i])))
			return (0);
		i++;
	}
	return (1);
}

int	*check_arg(int argc, char **argv)
{
	int	i;
	int	*res;

	i = 0;
	res = malloc(sizeof(int) * (argc));
	if (!res)
		return (NULL);
	while (i < argc)
	{
		if (ft_strisdigit(argv[i]))
			res[i] = ft_atoi(argv[i]);
		else
			return (free(res), NULL);
		i++;
	}
	return (res);
}



int	main(int argc, char **argv)
{
	t_list	*start = ft_lstnew(0);
	int	*tab = check_arg(argc - 1, argv + 1);
	ft_lstadd_front(&start, ft_lstnew(&tab[0]));
	if (tab != NULL)
	{
		for (int i = 0; i < argc - 1; i++)
			printf("%d\n", tab[i]);
		free(tab);
	}
	return (0);
}