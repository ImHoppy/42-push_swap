/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbraets <mbraets@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:07:32 by mbraets           #+#    #+#             */
/*   Updated: 2022/01/28 17:29:06 by mbraets          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	t_list			*result;
}					t_stacks;

t_stack	*ft_stacknew(int content);
void	ft_stackadd_front(t_stack **alst, t_stack *new);
void	ft_stackadd_back(t_stack **alst, t_stack *new);
void	ft_stackclear(t_stack **lst);
int		ft_stacklenght(t_stack *lst);
t_stack	*stack_pop(t_stack **stack);
void	stack_push(t_stack **stack, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stackbeforelast(t_stack *lst);
int		indexof_min(t_stack *stack);
int		min(t_stack *stack);

// Instruction

void	swap_a(t_stacks *stacks);
void	swap_b(t_stacks *stacks);
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);
void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);
void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);

// Algo

void	number_3(t_stacks *stacks);
void	number_4(t_stacks *stacks);

#endif