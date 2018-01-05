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

int		check(t_stack *s_a, t_stack *s_b)
{
	if (issorted(s_a) && s_b && s_b->size == 0)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	free_stack(s_a);
	free_stack(s_b);
	return (0);
}

int		read_cmds(t_stack *s_a, t_stack *s_b)
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
				op(s_a, s_b);
			else if (!(*cmdline)[0])
				return (check(s_a, s_b));
			else
				ft_error(1);
		}
		else
			return (check(s_a, s_b));
	}
}

int		main(int argc, char **argv)
{
	t_stack *s_a;
	t_stack *s_b;
	if(argc == 1)
		ft_error(0);
	if (!(s_a = (t_stack*)malloc(sizeof(t_stack))))
		ft_error(0);
	if (!(s_b = (t_stack*)malloc(sizeof(t_stack))))
		ft_error(0);
	s_b->content = NULL;
	s_b->size = 0;
	if (!makestack(s_a, argc, argv))
		ft_error(1);
	return (read_cmds(s_a, s_b));
}
