#include "push_swap.h"

void	reverse_or_rotate_a(t_stacks *stacks, t_stack *topush)
{
	int		len;
	int		middle;
	void	(*ptr)(t_stacks*);

	len = ft_stacklenght(stacks->a);
	middle = indexof(stacks->a, topush);
	if (middle < len / 2)
		ptr = &rotate_a;
	else
		ptr = &reverse_rotate_a;
	while (stacks->a != topush)
		ptr(stacks);
}

void	reverse_or_rotate_b(t_stacks *stacks, t_stack *topush)
{
	int		len;
	int		middle;
	void	(*ptr)(t_stacks*);

	len = ft_stacklenght(stacks->b);
	middle = indexof(stacks->b, topush);
	if (middle < len / 2)
		ptr = &rotate_b;
	else
		ptr = &reverse_rotate_b;
 	ptr(stacks);
}