/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:54:04 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/25 12:22:02 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * TODO:
 *  - Check MAX and MIN int 2147483647, -2147483648
 *  - Add prev to struct stack maybe? 
 *  - finish operations.c
 */

#include "push_swap.h"
#include <stdio.h>

int	ft_strisdigit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] == '-')
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
			ft_stackadd_front(&start, ft_stacknew(ft_atoi(argv[i])));
			// res[i] = ft_atoi(argv[i]);
		// else
			// return (free(res), NULL);
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


void print_stack(t_stacks *stacks)
{
	// t_stack *head_a = stacks->a;
	// t_stack *head_b = stacks->b;

	// while (head_a != NULL && head_b != NULL)
	// {
	// 	if (head_a->next != NULL)
	// 		head_a = head_a->next;
	// 	if (head_b->next != NULL)
	// 		head_b = head_b->next;
	// 	printf("%5d %d\n", head_a->content, head_b->content);

	// }
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

int	main(int argc, char **argv)
{
	// t_list	*start = NULL;
	// t_stack		*stackA;
	t_stacks	*stacks;

	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
		if (!(ft_strisdigit(argv[i])) | (ft_strlen(argv[i]) > 11))
			return (ft_putstr_fd("Error\n", 1), 0);
	stacks = malloc(sizeof(t_stacks));
	stacks->a = check_arg(argc - 1, argv + 1);
	stacks->b = NULL;
	// stacks->a = &stackA;
	if (stacks->a != NULL)
	{
		printf("lenght:{%d}\n", ft_stacklenght(stacks->a));
		printf("Input:%7s", "");
		for (t_stack *head = stacks->a; head != NULL; head = head->next) {
			printf("%d ", head->content);
		}
		printf("\n");
		swap_a(stacks);
		swap_b(stacks);
		push_b(stacks);
		print_stack(stacks);
		push_b(stacks);

		print_stack(stacks);
		// push_a(stacks);
		// push_a(stacks);
		rotate_a(stacks);
		rotate_b(stacks);

		print_stack(stacks);

		printf("\n");
		ft_stackclear(&stacks->a);
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