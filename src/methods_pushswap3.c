/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos1.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void		splitstacks(t_stack *s_a, t_stack *s_b, t_stackops *ops, int medvalue)
{
	int f;
	t_stack *current;

	current = s_a->next;
	f = 0;
	while (current && !current->isroot && (current->content != medvalue || !f))
	{
		if (!f && current->content == medvalue)
		{
			f = 1;
			ops = addop(ops, "ra");
			rotate_a(s_a, s_b);
		}
		else if (current->content<=medvalue)
		{
			ops = addop(ops, "pb");
			push_b(s_a, s_b);
		}
		else
		{
			ops = addop(ops, "ra");
			rotate_a(s_a, s_b);
		}
		current = current->next;
	}
}

void		doop(t_stack *s_a, t_stack *s_b, t_stackops *ops, int op)
{
	if (op == 1 || op == 21)
	{
		ops = addop(ops, "sa");
		swap_a(s_a, s_b);
	}
	else if (op == 2 || op == 12)
	{
		ops = addop(ops, "ra");
		rotate_a(s_a, s_b);
	}
	else if (op == 10)
	{
		ops = addop(ops, "sb");
		swap_b(s_a, s_b);
	}
	else if (op == 20)
	{
		ops = addop(ops, "rb");
		rotate_b(s_a, s_b);
	}
}

t_stackops	*medsolve2(t_stack *s_a, t_stack *s_b, t_stackops *ops)
{
	int op;

	while (!issorted(s_a) || !issortedreverse(s_b))
	{
		op = 0;
		if (!issorted(s_a))
			op += (s_a->content > s_a->next->content &&
					s_a->content < s_a->previous->content) ? 1 : 2;
		if (!issortedreverse(s_b))
			op += (s_b->content < s_b->next->content &&
					s_b->content > s_b->previous->content) ? 10 : 20;
		if (op == 11)
		{
			ops = addop(ops, "ss");
			swap_both(s_a, s_b);
		}
		else if (op == 22)
		{
			ops = addop(ops, "rr");
			rotate_both(s_a, s_b);
		}
		else
			doop(s_a, s_b, ops, op);
	}
	return (ops);
}

t_stackops	*medsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops)
{
	int	*medvalue;
	int	*medindex;

	if (!(medvalue = (int*)ft_memalloc(sizeof(int))))
		return (0);
	if (!(medindex = (int*)ft_memalloc(sizeof(int))))
		return (0);
	findmed(s_a, medvalue, medindex);
	splitstacks(s_a, s_b, ops, *medvalue);
	if (!(ops = medsolve2(s_a, s_b, ops)))
		return (0);
	while (s_b->next)
	{
		ops = addop(ops, "pa");
		push_a(s_a, s_b);
	}
	return(ops);
}
