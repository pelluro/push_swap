/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 15:50:07 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:27 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
#define PUSHSWAP_H

#include "libft/libft.h"

typedef struct	s_stack
{
   int	*content;
   int	size;
}				t_stack;

typedef struct	s_stackops
{
   char	**content;
   int	size;
}				t_stackops;

typedef void	(*stack_op)(t_stack*, t_stack*);

/*
 ** algos.c
 */
t_stackops	*basicsolve2(t_stack *s_a, t_stack *s_b, t_stackops *ops);
t_stackops	*basicsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops);
int			smallresolve(t_stack *stack, t_stackops *ops);
t_stackops	*mediumsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops);
t_stackops	*addop(t_stackops *ops, char *op);
void		printtab(t_stack *stack);
/*
** algos1.c
*/
void		splitstacks(t_stack *s_a, t_stack *s_b, t_stackops *ops, int medvalue);
void		doop(t_stack *s_a, t_stack *s_b, t_stackops *ops, int op);
t_stackops	*medsolve2(t_stack *s_a, t_stack *s_b, t_stackops *ops);
t_stackops	*medsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops);
 /*
 ** checker.c
 */
int			check(t_stack *s_a, t_stack *s_b);
int			read_cmds(t_stack *s_a, t_stack *s_b);

 /*
 ** methods.c
 */
stack_op	define_hashmap(char *op_name);
int			ft_haschar(const char *s, int c);
t_stack		*parsestack(t_stack *stack, char *str);
 /*
 ** methods2.c
 */
t_stack		*copytabintostack(t_stack *stack, int* tab, int s);
int			checktab(int *tab, int s);
int			*handleministack(int* tab, int* s, char* str);
int			*maketab(int *tab, int *s, int argc, char **argv);
int			makestack(t_stack *stack, int argc, char **argv);
 /*
 ** methods3.c
 */
int			issorted(t_stack *stack);
int			issortedreverse(t_stack *stack);
void		printtab(t_stack *stack);
 /*
 ** ops1.c
 */
void		swap(t_stack *stack);
void		swap_a(t_stack *s_a, t_stack *s_b);
void		swap_b(t_stack *s_a, t_stack *s_b);
void		swap_both(t_stack *s_a, t_stack *s_b);
 /*
 ** ops2.c
 */
void		push(t_stack *stackfrom, t_stack *stackto);
void		push_a(t_stack *s_a, t_stack *s_b);
void		push_b(t_stack *s_a, t_stack *s_b);
t_stack		*add_top(t_stack *stack, int c);
t_stack		*remove_elem(t_stack *stack, int index);
 /*
 ** ops3.c
 */
void		rotate(t_stack *stack);
void		rotate_a(t_stack *s_a, t_stack *s_b);
void		rotate_b(t_stack *s_a, t_stack *s_b);
void		rotate_both(t_stack *s_a, t_stack *s_b);
 /*
 ** ops4.c
 */
void		reverse_rotate(t_stack *stack);
void		reverse_rotate_a(t_stack *s_a, t_stack *s_b);
void		reverse_rotate_b(t_stack *s_a, t_stack *s_b);
void		reverse_rotate_both(t_stack *s_a, t_stack *s_b);
 /*
 ** ops5.c
 */
void		findmin(t_stack *stack, int *value, int *index);
void		findmax(t_stack *stack, int *value, int *index);
void		findmed(t_stack *stack, int *value, int *index);
void		shift(t_stack *stack, int pivot, t_stackops *ops);
t_stack		*copystack(t_stack *stack);
 /*
 ** pushswap.c
 */
 void		printstackops(t_stackops *ops);
t_stackops	*init_so(t_stackops *ops);
t_stack		*init_stack(t_stack *s);
void		compare(t_stackops *ops1, t_stackops *ops2, t_stackops *ops3);
#endif
