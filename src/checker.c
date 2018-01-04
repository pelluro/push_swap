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

#include "../include/pushswap.h"

int		check(t_stack *stack_a, t_stack *stack_b)
{
	if (issorted(stack_a) && stack_b && stack_b->size == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}

int		read_cmds(t_stack *stack_a, t_stack *stack_b)
{
	stack_op	op;
	char		**cmdline;

	cmdline = (char**)malloc(sizeof(char*));
	while (1)
	{
		if (get_next_line(0, cmdline))
		{
			op = define_hashmap(*cmdline);
			if (op)
				op(stack_a, stack_b);
			else if (!(*cmdline)[0])
				return (check(stack_a, stack_b));
			else
			{
				ft_putendl("Error");
				return (-1);
			}
		}
		else
			return (check(stack_a, stack_b));
	}
}

int		main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	if (!(stack_b = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	stack_b->content = NULL;
	stack_b->size = 0;
	if (!makestack(stack_a, argc, argv))
	{
		ft_putendl("Error");
		return (-1);
	}
	return (read_cmds(stack_a, stack_b));
}
