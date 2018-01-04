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

	f = 0;
	while (s_a->content[0] != medvalue || !f)
	{
		if (!f && s_a->content[0] == medvalue)
		{
			f = 1;
			ops = addop(ops, "ra");
			rotate_a(s_a, s_b);
		}
		else if (s_a->content[0]<=medvalue)
		{
			ops = addop(ops, "pb");
			push_b(s_a, s_b);
		}
		else
		{
			ops = addop(ops, "ra");
			rotate_a(s_a, s_b);
		}
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
		if (ops->size > 10000)
			return (NULL);
		op = 0;
		if (!issorted(s_a))
			op += (s_a->content[0] > s_a->content[1] &&
					s_a->content[0] < s_a->content[s_a->size - 1]) ? 1 : 2;
		if (!issortedreverse(s_b))
			op += (s_b->content[0] < s_b->content[1] &&
					s_b->content[0] > s_b->content[s_b->size - 1]) ? 10 : 20;
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

	if (!(medvalue = (int*)malloc(sizeof(int))))
		return (0);
	if (!(medindex = (int*)malloc(sizeof(int))))
		return (0);
	findmed(s_a, medvalue, medindex);
	printf("findmed ok\n");
	splitstacks(s_a, s_b, ops, *medvalue);
	printf("splitmed ok \n");
	if (!(ops = medsolve2(s_a, s_b, ops)))
	{
		printf("medsolve2 return null\n");
		return (NULL);
	}
	
	while (s_b->size > 0)
	{
		ops = addop(ops, "pa");
		push_a(s_a, s_b);
	}
	return(ops);
}
