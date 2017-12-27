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

typedef struct stack
{
   int *content;
   int size;
} t_stack;

typedef void (*stack_op)(t_stack*, t_stack*);
int issorted(t_stack* stack);
t_stack* add_top(t_stack* stack, int c);
t_stack* remove_elem(t_stack* stack, int index);
void swap(t_stack* stack);
void swap_a(t_stack* stack_a, t_stack* stack_b);
void swap_b(t_stack* stack_a, t_stack* stack_b);
void swap_both(t_stack* stack_a, t_stack* stack_b);
void push(t_stack* stackfrom, t_stack* stackto);
void push_a(t_stack* stack_a, t_stack* stack_b);
void push_b(t_stack* stack_a, t_stack* stack_b);
void rotate(t_stack* stack);
void rotate_a(t_stack* stack_a, t_stack* stack_b);
void rotate_b(t_stack* stack_a, t_stack* stack_b);
void rotate_both(t_stack* stack_a, t_stack* stack_b);
void reverse_rotate(t_stack* stack);
void reverse_rotate_a(t_stack* stack_a, t_stack* stack_b);
void reverse_rotate_b(t_stack* stack_a, t_stack* stack_b);
void reverse_rotate_both(t_stack* stack_a, t_stack* stack_b);
stackOp define_hashmap(char * opName);

void printtab(t_stack *stack);
int makestack(t_stack *stack, int argc, char **argv);
void read_cmd(char *cmd);
int read_cmds(t_stack *stack_a, t_stack *stack_b);
int do_cmds(t_stack *stack_a, t_stack *stack_b, char **cmds);
#endif
