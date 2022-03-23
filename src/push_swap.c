/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:54:04 by mbraets           #+#    #+#             */
/*   Updated: 2022/03/23 16:16:18 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*check_arg(int argc, char **argv)
{
	int		i;
	t_stack	*start;
	t_stack	*new;

	start = NULL;
	i = 0;
	while (i < argc)
	{
		if (ft_strisdigit(argv[i]))
		{
			new = ft_stacknew(ft_atoi(argv[i]));
			if (new->content == -1 && (argv[i][1] != '1' && argv[i][1] != '0'))
				return (ft_stackclear(&start), ft_stackclear(&new), NULL);
			if (new != NULL)
				ft_stackadd_back(&start, new);
			else
				return (ft_stackclear(&start), ft_stackclear(&new), NULL);
		}
		else
			return (NULL);
		i++;
	}
	return (start);
}

t_list	*create_ss_rr_rrr(t_list *head, char *a, char *b, char *ab)
{
	t_list	*temp;

	temp = NULL;
	if (ft_strcmp(head->content, a) == 0
		&& ft_strcmp(head->next->content, b) == 0)
	{
		head->content = ab;
		temp = head->next->next;
		free(head->next);
		head->next = temp;
	}
	return (head);
}

void	ss_rr_rrr(t_list *lst)
{
	t_list	*head;

	head = lst;
	while (head != NULL && head->next != NULL)
	{
		head = create_ss_rr_rrr(head, "sa", "sb", "ss");
		head = create_ss_rr_rrr(head, "ra", "rb", "rr");
		head = create_ss_rr_rrr(head, "rra", "rrb", "rrr");
		head = head->next;
	}
}

void	which_algo(t_stacks *stacks)
{
	int	len;

	len = ft_stacklenght(stacks->a);
	if (sorted(stacks->a))
		return ;
	if (len == 2)
	{
		if (stacks->a->content > stacks->a->next->content)
			swap_a(stacks);
	}
	else if (len == 3)
		number_3(stacks);
	else if (len == 4)
		number_4(stacks);
	else if (len == 5)
		number_5(stacks);
	else if (len > 5 && len <= 100)
		index_sort(stacks, 17);
	else if (len > 100 && len <= 500)
		index_sort(stacks, 44);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;
	int			i;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
		if (!(ft_strisdigit(argv[i])) | (ft_strlen(argv[i]) > 11))
			error(NULL);
	stacks = malloc(sizeof(t_stacks));
	*stacks = (t_stacks){};
	if (stacks == NULL)
		error(stacks);
	stacks->a = check_arg(argc - 1, argv + 1);
	if (stacks->a == NULL || find_duplicate_stack(stacks->a))
		error(stacks);
	if (stacks->a != NULL)
	{
		which_algo(stacks);
		ss_rr_rrr(stacks->result);
		ft_stackclear(&stacks->a);
		ft_stackclear(&stacks->b);
		ft_lstclear(&stacks->result, &ft_putendl);
	}
	free(stacks);
}
