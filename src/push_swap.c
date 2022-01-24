/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 12:54:04 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/24 04:01:30 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** 
 * TODO:
 *  - Check MAX and MIN int 2147483647, -2147483648
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



int	main(int argc, char **argv)
{
	// t_list	*start = NULL;
	t_stack	*stackA;
	
	int		i;

	if (argc < 2)
		return (0);
	i = 0;
	while (argv[++i])
		if (!(ft_strisdigit(argv[i])) | (ft_strlen(argv[i]) > 11))
			return (ft_putstr_fd("Error\n", 1), 0);
	stackA = check_arg(argc - 1, argv + 1);
	if (stackA != NULL)
	{
		printf("%d\n", ft_stacklenght(stackA));
		// ft_lstadd_front(&start, ft_lstnew((void*)&tab[0]));
		// ft_lstadd_front(&start, ft_lstnew((void*)&tab[1]));
		// for (int i = 0; i < argc - 1; i++)
		// {
		// 	printf("%d\n", (int)head->content);
		// 	head = head->next;
		// }
		for (t_stack *head = stackA; head != NULL; head = head->next) {
			printf("%d ", head->content);
		}
		// printf(":%d\n", stack_pop(&stackA)->content);
		printf("\n");
		swap_a(&stackA);
		for (t_stack *head = stackA; head != NULL; head = head->next) {
			printf("%d ", head->content);
		}
		ft_stackclear(&stackA);
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