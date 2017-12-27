/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:46 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:49 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"git

int main(int argc, char **argv)
{
	char buff[2001];
	int f;
	t_stack* stack_a;
	t_stack* stack_b;
	
	stack_a = (t_stack*)malloc(sizeof(t_stack));
	stack_b = (t_stack*)malloc(sizeof(t_stack));
	stack_a->content = (int*)malloc(sizeof(int) * (argc - 1));
	stack_a->size = argc - 1;
	stack_b->content = NULL;
	stack_b->size = 0;
	f = 0;
	if(read(0, buff, 1999))
	{
		buff[2000] = '\0';
		f = 1;
	}
	if(!makestack(stack_a, argc, argv))
	{
		printf("Error\n");
		return (-1);
	}
	if(f>0)
		return(do_cmds(stack_a, stack_b, ft_strsplit(buff, '\n')));
	else
		return(read_cmds(stack_a, stack_b));
}
