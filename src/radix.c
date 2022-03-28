/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:08:37 by hoppy             #+#    #+#             */
/*   Updated: 2022/03/28 17:35:05 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	empty_stack_b(t_stacks *stacks)
{
	while (stacks->b != NULL)
		push_a(stacks);
}

char *decimal_to_binary(int n)
{
  int c, d, t;
  char *p;

  t = 0;
  p = (char*)malloc(32+1);

  if (p == NULL)
    exit(EXIT_FAILURE);

  for (c = 31 ; c >= 0 ; c--)
  {
    d = n >> c;

    if (d & 1)
      *(p+t) = 1 + '0';
    else
      *(p+t) = 0 + '0';

    t++;
  }
  *(p+t) = '\0';

  return  p;
}

#include <stdio.h>
void	print_stack(t_stacks *stacks)
{
	printf("\n----------\n");
	printf("StackA:%6s", "");
	for (t_stack *head = stacks->a; head != NULL; head = head->next) {
		printf("%d:%d:%s ", head->content, head->index, decimal_to_binary(head->index));
	}
	printf("\nStackB:%6s", "");
	for (t_stack *head = stacks->b; head != NULL; head = head->next) {
		printf("%d:%d:%s ", head->content, head->index, decimal_to_binary(head->index));
	}
	printf("\n");
}

void	radix_sort(t_stacks *stacks)
{
	// int	mask;
	int	i;
	int	j;
	// t_stack	*last;
	int	stacksize;
	int	maxbits;
	// t_stack	*topush;

	// last = ft_stacklast(stacks->a);
	set_index(stacks->a);
	// mask = 0;
	i = 0;
	maxbits = 0;
	stacksize = ft_stacklenght(stacks->a);
	// printf("%d",stacksize);
	// print_stack(stacks);
	while (((stacksize - 1) >> maxbits) != 0)
		++maxbits;
	// printf("%d", maxbits);
	while (!sorted(stacks->a))
	{
		i++;
		j = 0;
		while (j++ < stacksize)
		{
			// stacks->a;
			if (((stacks->a->index >> i) & 1) == 1)
				rotate_a(stacks);
			else
				push_b(stacks);
		}
		empty_stack_b(stacks);
		// mask++;
	}
	// print_stack(stacks);
	empty_stack_b(stacks);
	// print_stack(stacks);
}
