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
#include <stdlib.h>

typedef struct	s_stack
{
   int	value;
   struct	s_stack*	next;
}				t_stack;

typedef struct	s_stackops
{
   char *op;
   struct	s_stackops *next;
}				t_stackops;

typedef void	(*stack_op)(t_stack**, t_stack**);
/*
** ft_count_list.c
*/
size_t		ft_count_list(t_stack *stack);
size_t		ft_count_ops(t_stackops **stack);
void		ft_del_stack(t_stack **stack);
void		ft_del_stackops(t_stackops **ops);
void		print_list(t_stack *a, t_stack *b);
void		print_stackops(t_stackops *ops);
/*
** methods.c
*/
void		ft_error(int error);
int			checktab(t_stack *stack);
int			handleministack(t_stack *current, t_stack *stack, char* str);
int			makestack(t_stack *stack, int argc, char **argv, int *f);
/*
** methods2.c
*/
int			issorted(t_stack *stack);
int			issorted_reverse(t_stack *stack);
t_stack		*create_node(t_stack *prevelem, int value);
/*
** methods_checker.c
*/
stack_op	define_hashmap(char *op_name);
int			check(t_stack *s_a, t_stack *s_b);
int			read_cmds(t_stack *s_a, t_stack *s_b, int f);
/*
** methods_pushswap.c
*/
t_stackops	*addop(t_stackops *ops, char *op);
int			smallresolve(t_stack **stack, t_stackops **ops);
void		mediumsolve(t_stack *s_a, t_stack *s_b, t_stackops **ops);
void		basicsolve(t_stack **s_a, t_stack **s_b, t_stackops **ops);
void		basicsolve2(t_stack **s_a, t_stack **s_b, t_stackops **ops);
void		findmax(t_stack *stack, int *value_max, int *index_max);
void		findmin(t_stack *stack, int *value, int *index);
/*
** methods_pushswap2.c
*/
void		clean_ops(t_stackops **ops);
void		findmed(t_stack *stack, int *value, int *index);
t_stack		*copystack(t_stack *stack);
int			* stacktotab(t_stack* stack, int* size);
/*
** methods_pushswap3.c
*/
void		splitstacks(t_stack **s_a, t_stack **s_b, t_stackops **ops, int medvalue);
void		medsolve_a(t_stack** stack, t_stack **otherstack, t_stackops **ops);
void		medsolve_b(t_stack **otherstack, t_stack **stack, t_stackops **ops);
void		medsolve(t_stack *s_a, t_stack *s_b, t_stackops **ops);
void ft_merge_pivot(t_stackops **ops, t_stackops **ops1, t_stackops **ops2);
void ft_merge_main(t_stackops **ops, t_stackops **ops_selec);
void ft_merge_ops(t_stackops **ops, t_stackops **ops1, t_stackops **ops2);
void callback(t_stack **s_a, t_stack **s_b, t_stackops **ops, int med_val);
/*
** op_push.c
*/
void		push(t_stack **stackfrom, t_stack **stackto);
void		push_a(t_stack **s_a, t_stack **s_b);
void		push_b(t_stack **s_a, t_stack **s_b);
/*
** op_reverserotate.c
*/
t_stack		*reverse_rotate(t_stack *first);
void		reverse_rotate_a(t_stack **s_a, t_stack **s_b);
void		reverse_rotate_b(t_stack **s_a, t_stack **s_b);
void		reverse_rotate_both(t_stack **s_a, t_stack **s_b);
/*
** op_rotate.c
*/
t_stack		*rotate(t_stack *stack);
void		rotate_a(t_stack **s_a, t_stack **s_b);
void		rotate_b(t_stack **s_a, t_stack **s_b);
void		rotate_both(t_stack **s_a, t_stack **s_b);
/*
** op_swap.c
*/
t_stack *swap(t_stack *stack);
void		swap_a(t_stack **s_a, t_stack **s_b);
void		swap_b(t_stack **s_a, t_stack **s_b);
void		swap_both(t_stack **s_a, t_stack **s_b);

#endif
