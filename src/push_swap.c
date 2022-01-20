/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:54:04 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/20 06:20:09 by mbraets          ###   ########.fr       */
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

t_stack	*check_arg(int argc, char **argv)
{
	int		i;
	int		*res;
	t_stack	*start;

	start = NULL;
	i = 0;
	res = malloc(sizeof(int) * (argc));
	if (!res)
		return (NULL);
	while (i < argc)
	{
		if (ft_strisdigit(argv[i]))
			ft_stackadd_front(&start, ft_stacknew(ft_atoi(argv[i])));
			// res[i] = ft_atoi(argv[i]);
		// else
			// return (free(res), NULL);
		i++;
	}
	return (start);
}



int	main(int argc, char **argv)
{
	// t_list	*start = NULL;
	t_stack	*stackA;
	t_stack	*head;
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
		if (!(ft_strisdigit(argv[i])))
			return (ft_putstr_fd("Error\n", 1), 0);
	stackA = check_arg(argc - 1, argv + 1);
	head = stackA;
	if (stackA != NULL)
	{
		printf("%d\n", ft_stacklenght(stackA));
		// ft_lstadd_front(&start, ft_lstnew((void*)&tab[0]));
		// ft_lstadd_front(&start, ft_lstnew((void*)&tab[1]));
		for (int i = 0; i < argc - 1; i++)
		{
			printf("%d\n", (int)head->content);
			head = head->next;
		}
		ft_stackclear(&stackA);
	}
	// while (1)
		// ;;
	return (0);
}
