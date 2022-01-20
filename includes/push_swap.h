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
}					t_stacks;

t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **alst, t_stack *new);

#endif