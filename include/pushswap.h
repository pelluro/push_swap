/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 18:22:18 by mipham            #+#    #+#             */
/*   Updated: 2018/01/02 19:05:35 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"

typedef struct	s_stack
{
	int			*content;
	int			size;
}				t_stack;

typedef struct	s_stackops
{
	char		**content;
	int			size;
}				t_stackops;

int				issorted(t_stack *stack);
t_stack			*add_top(t_stack *stack, int c);
t_stack			*remove_elem(t_stack *stack, int index);
void			swap(t_stack *stack);
void			swap_a(t_stack *stack_a, t_stack *stack_b);
void			swap_b(t_stack *stack_a, t_stack *stack_b);
void			swap_both(t_stack *stack_a, t_stack *stack_b);
void			push(t_stack *stackfrom, t_stack *stackto);
void			push_a(t_stack *stack_a, t_stack *stack_b);
void			push_b(t_stack *stack_a, t_stack *stack_b);
void			rotate(t_stack *stack);
void			rotate_a(t_stack *stack_a, t_stack *stack_b);
void			rotate_b(t_stack *stack_a, t_stack *stack_b);
void			rotate_both(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate(t_stack *stack);
void			reverse_rotate_a(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate_b(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);

typedef	void	(*stack_op)(t_stack*, t_stack*);
stack_op		define_hashmap(char *op_name);

void			findmin(t_stack *stack, int *value, int *index);
void			findmax(t_stack *stack, int *value, int *index);
void			shift(t_stack *stack, int pivot, t_stackops *ops);
t_stack			*copystack(t_stack *stack);

void			printtab(t_stack *stack);
int				makestack(t_stack *stack, int argc, char **argv);
int				*maketab(int *tab, int *s, int argc, char **argv);
int				*handleministack(int *tab, int *s, char *str);
t_stackops		*basicresolve(t_stack *stack_a, t_stack *stack_b,
		t_stackops *ops);
t_stackops		*basicresolve2(t_stack *stack_a, t_stack *stack_b,
		t_stackops *ops);
int				smallresolve(t_stack *stack, t_stackops *ops);
t_stackops		*mediumresolve(t_stack *stack_a, t_stack *stack_b,
		t_stackops *ops);
int				ft_haschar(const char *s, int c);
t_stack			*parsestack(t_stack *stack, char *str);
t_stackops		*addop(t_stackops *ops, char *op);
#endif
