/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_checker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:46 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:49 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/pushswap.h"

stack_op	define_hashmap(char *op_name)
{
	if (ft_strlen(op_name) < 1 || ft_strlen(op_name) > 3)
		return (NULL);
	if (!ft_strcmp(op_name, "sa"))
		return (&swap_a);
	if (!ft_strcmp(op_name, "sb"))
		return (&swap_b);
	if (!ft_strcmp(op_name, "ss"))
		return (&swap_both);
	if (!ft_strcmp(op_name, "pa"))
		return (&push_a);
	if (!ft_strcmp(op_name, "pb"))
		return (&push_b);
	if (!ft_strcmp(op_name, "ra"))
		return (&rotate_a);
	if (!ft_strcmp(op_name, "rb"))
		return (&rotate_b);
	if (!ft_strcmp(op_name, "rr"))
		return (&rotate_both);
	if (!ft_strcmp(op_name, "rra"))
		return (&reverse_rotate_a);
	if (!ft_strcmp(op_name, "rrb"))
		return (&reverse_rotate_b);
	if (!ft_strcmp(op_name, "rrr"))
		return (&reverse_rotate_both);
	return (NULL);
}

int		check(t_stack *s_a, t_stack *s_b)
{
	// print_list(s_a, s_b);
	if (issorted(s_a) && !s_b)
		ft_putendl("OK");
	else
		ft_putendl("KO");
	return (0);
}

int		read_cmds(t_stack *s_a, t_stack *s_b, int f)
{
	stack_op	op;
	char		**cmdline;

	if (!(cmdline = (char**)ft_memalloc(sizeof(char*))))
		return (0);
	if (f)
		print_list(s_a, s_b);
	while (1)
	{

		if (get_next_line(0, cmdline))
		{
			op = define_hashmap(*cmdline);
			if (op)
			{
				op(&s_a, &s_b);
				if (f)
					print_list(s_a, s_b);
			}
			else if (!(*cmdline)[0])
				return (check(s_a, s_b));
			else
				ft_error(1);
		}
		else
			return (check(s_a, s_b));
	}
}
