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

//typedef struct	s_flags
//{
//    int	flag_v;
//    int	flag_c;
//}				t_flags;
//
typedef void	(*stack_op)(t_stack**, t_stack**);
// /*
//  ** algos.c
//  */
// t_stackops	*basicsolve2(t_stack *s_a, t_stack *s_b, t_stackops *ops);
// t_stackops	*basicsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops);
// int			smallresolve(t_stack *stack, t_stackops *ops);
// t_stackops	*mediumsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops);
// t_stackops	*addop(t_stackops *ops, char *op);
// void		printtab(t_stack *stack);
// /*
// ** algos1.c
// */
// void		splitstacks(t_stack *s_a, t_stack *s_b, t_stackops *ops, int medvalue);
// void		doop(t_stack *s_a, t_stack *s_b, t_stackops *ops, int op);
// t_stackops	*medsolve2(t_stack *s_a, t_stack *s_b, t_stackops *ops);
// t_stackops	*medsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops);
//  /*
//  ** checker.c
//  */
// int			check(t_stack *s_a, t_stack *s_b);
// int			read_cmds(t_stack *s_a, t_stack *s_b);

void	ft_error(int error);

// stack_op	define_hashmap(char *op_name);
// int			issorted(t_stack *stack);
// int			issortedreverse(t_stack *stack);
// void		free_stack(t_stack *m);
// void		free_stackops(t_stackops *n);
// void		ft_error(int error);
// t_stack		*copytabintostack(t_stack *stack, int* tab, int s);
 /*
 ** methods2.c
 */
t_stack		*parsestack(t_stack *stack, char *str);
t_stack* create_node(t_stack *previous, int value);

int		checktab(t_stack *stack);
int		handleministack(t_stack *current, t_stack *stack, char* str);
int		makestack(t_stack *stack, int argc, char **argv);

 /*
 ** ops1.c
 */
t_stack *swap(t_stack *stack);
void		swap_a(t_stack **s_a, t_stack **s_b);
void		swap_b(t_stack **s_a, t_stack **s_b);
void		swap_both(t_stack **s_a, t_stack **s_b);
 /*
 ** ops2.c
 */
void		push(t_stack **stackfrom, t_stack **stackto);
void		push_a(t_stack **s_a, t_stack **s_b);
void		push_b(t_stack **s_a, t_stack **s_b);
// t_stack		*add_top(t_stack *stack, int c);
// t_stack		*remove_elem(t_stack *stack);
 /*
 ** ops3.c
 */
t_stack	*rotate(t_stack *stack);
void		rotate_a(t_stack **s_a, t_stack **s_b);
void		rotate_b(t_stack **s_a, t_stack **s_b);
void		rotate_both(t_stack **s_a, t_stack **s_b);
 /*
 ** ops4.c
 */
t_stack *reverse_rotate(t_stack *stack);
void		reverse_rotate_a(t_stack **s_a, t_stack **s_b);
void		reverse_rotate_b(t_stack **s_a, t_stack **s_b);
void		reverse_rotate_both(t_stack **s_a, t_stack **s_b);

// void		findmin(t_stack *stack, int *value, int *index);
// void		findmax(t_stack *stack, int *value, int *index);
// void		findmed(t_stack *stack, int *value, int *index);
// void		shift(t_stack *stack, int pivot, t_stackops *ops);
// t_stack		*copystack(t_stack *stack);
// int* stacktotab(t_stack* stack, int* size);
//
// void		printstackops(t_stackops *ops);
// t_stackops	*init_so(t_stackops *ops);
// t_stack		*init_stack(t_stack *s);
// void		compare(t_stackops *ops1, t_stackops *ops2, t_stackops *ops3);
//
// void erase_elem_list(t_list *list);
// void erase_list(t_list **list);
// void erase_elem (t_list *elem);
// ** listops2.c
//
// void ft_show_list(t_list *elem);
// t_list create_list_double(void);
// void add_after_elem(t_list *elem, int val);
// void add_before_elem(t_list *elem, int val);
//
void	print_list(t_stack *a, t_stack *b);
size_t  ft_count_list(t_stack *stack);

int		read_cmds(t_stack *s_a, t_stack *s_b);
int	  check(t_stack *s_a, t_stack *s_b);
stack_op	define_hashmap(char *op_name);
int			issorted(t_stack *stack);


#endif
