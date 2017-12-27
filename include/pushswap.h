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
   int* content;
   int size;
} t_stack;

typedef void (*stackOp)(t_stack*, t_stack*);
int issorted(t_stack* stack);
t_stack* add_top(t_stack* stack, int c);
t_stack* remove_elem(t_stack* stack, int index);
void swap(t_stack* stack);
void swap_a(t_stack* stackA, t_stack* stackB);
void swap_b(t_stack* stackA, t_stack* stackB);
void swap_both(t_stack* stackA, t_stack* stackB);
void push(t_stack* stackFrom, t_stack* stackTo);
void push_a(t_stack* stackA, t_stack* stackB);
void push_b(t_stack* stackA, t_stack* stackB);
void rotate(t_stack* stack);
void rotate_a(t_stack* stackA, t_stack* stackB);
void rotate_b(t_stack* stackA, t_stack* stackB);
void rotate_both(t_stack* stackA, t_stack* stackB);
void reverse_rotate(t_stack* stack);
void reverse_rotate_a(t_stack* stackA, t_stack* stackB);
void reverse_rotate_b(t_stack* stackA, t_stack* stackB);
void reverse_rotate_both(t_stack* stackA, t_stack* stackB);
stackOp define_hashmap(char * opName);

void printtab(t_stack* stack);
int makeStack(t_stack* stack, int argc, char** argv);
void readCmd(char* cmd);
int readCmds(t_stack* stackA, t_stack* stackB);
int doCmds(t_stack* stackA, t_stack* stackB, char** cmds);
#endif
