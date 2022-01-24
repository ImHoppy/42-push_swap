#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_list			*result;
}					t_stacks;

t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **alst, t_stack *new);
void	ft_stackclear(t_stack **lst);
int		ft_stacklenght(t_stack *lst);
t_stack	*stack_pop(t_stack **stack);
void	stack_push(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);

void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
#endif