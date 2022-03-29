/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 14:08:37 by hoppy             #+#    #+#             */
/*   Updated: 2022/03/29 12:41:53 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	empty_stack_b(t_stacks *stacks)
{
	while (stacks->b != NULL)
		push_a(stacks);
}

void	radix_sort(t_stacks *stacks)
{
	int	stacksize;
	int	max_num;
	int	i;
	int	j;

	set_index(stacks->a);
	stacksize = ft_stacklenght(stacks->a);
	max_num = stacksize - 1;
	i = 0;
	while (!sorted(stacks->a))
	{
		j = 0;
		while (j < stacksize)
		{
			if (((stacks->a->index >> i) & 1) == 1)
				rotate_a(stacks);
			else
				push_b(stacks);
			j++;
		}
		empty_stack_b(stacks);
		i++;
	}
}
