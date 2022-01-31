/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:54:04 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/31 20:17:33 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * TODO:
 *  - Check MAX and MIN int 2147483647, -2147483648
 * 	- Remove gitignore
 *  - 6 instrucion max for 4 number
 *  - Rewrite instrucion for 5 number
 */

#include "push_swap.h"
#include <stdio.h>

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

t_stack	*check_arg(int argc, char **argv)
{
	int		i;
	t_stack	*start;

	start = NULL;
	i = 0;
	while (i < argc)
	{
		if (ft_strisdigit(argv[i]))
			ft_stackadd_back(&start, ft_stacknew(ft_atoi(argv[i])));
		else
			return (NULL);
		i++;
	}
	return (start);
}

void	ft_putendl(void *s)
{
	if (s)
	{
		ft_putstr_fd((char *)s, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	print_stack(t_stacks *stacks)
{
	printf("\n----------\n");
	printf("StackA:%6s", "");
	for (t_stack *head = stacks->a; head != NULL; head = head->next) {
		printf("%d ", head->content);
	}
	printf("\nStackB:%6s", "");
	for (t_stack *head = stacks->b; head != NULL; head = head->next) {
		printf("%d ", head->content);
	}
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
		insertion_sort(stacks, 5);
	else if (len > 100 && len <= 500)
		insertion_sort(stacks, 11);
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
			return (ft_putstr_fd("Error\n", 2), 0);
	stacks = malloc(sizeof(t_stacks));
	stacks->a = check_arg(argc - 1, argv + 1);
	if (find_duplicate_stack(stacks->a))
		return (ft_putstr_fd("Error\n", 2), 0);
	stacks->b = NULL;
	stacks->result = NULL;
	if (stacks->a != NULL)
	{
		// printf("lenght:{%d}\n", ft_stacklenght(stacks->a));
		// printf("Input:%7s", "");
		// for (t_stack *head = stacks->a; head != NULL; head = head->next) {
			// printf("%d ", head->content);
		// }
		// printf("\n");
		which_algo(stacks);
		// print_stack(stacks);
		/*
		push_b(stacks);
		push_b(stacks);
		// swap_a(stacks);
		swap_a(stacks);
		// swap_b(stacks);
		print_stack(stacks);
		// push_a(stacks);
		// push_a(stacks);
		rotate_a(stacks);
		rotate_b(stacks);
		print_stack(stacks);
		// swap_a(stacks);
		reverse_rotate_a(stacks);
		reverse_rotate_b(stacks);
		print_stack(stacks);
		printf("\n");
		ss_rr_rrr(stacks->result);
		*/
		ft_stackclear(&stacks->a);
		ft_stackclear(&stacks->b);
		ft_lstclear(&stacks->result, &ft_putendl);
		free(stacks);
	}
	// while (1)
		// ;;
	return (0);
}

// #include <stdlib.h>
// #include <stdio.h>

// typedef struct nodeStruct
// {
//     int val;
//     struct nodeStruct *next;
// } node;

// static void push(node **head, int v)
// {
//     node *temp = malloc(sizeof(node));
//     temp->val = v;
//     temp->next = *head;
//     *head = temp;
// }

// int main(int argc, char **argv)
// {
//     (void) argv;
//     (void) argc;
//     node *list = NULL;

//     for (int i=0; i<10; ++i) {
//         push(&list, i);
//     }
//     for(node *l = list; l != NULL; l = l->next) {
//         printf("%d ", l->val);
//     }
//     printf("\n");
//     return 0;
// }