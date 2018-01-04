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

void		splitstacks(t_stack *stack_a, t_stack *stack_b, t_stackops *ops, int medvalue)
{
	int f;

	f = 0;
	while (stack_a->content[0] != medvalue || !f)
	{
		if (!f && stack_a->content[0] == medvalue)
		{
			f = 1;
			ops = addop(ops, "ra");
			rotate_a(stack_a, stack_b);
		}
		else if (stack_a->content[0]<=medvalue)
		{
			ops = addop(ops, "pb");
			push_b(stack_a, stack_b);
		}
		else
		{
			ops = addop(ops, "ra");
			rotate_a(stack_a, stack_b);
		}
	}
}

void		doop(t_stack *stack_a, t_stack *stack_b, t_stackops *ops, int op)
{
	if (op == 1 || op == 21)
	{
		ops = addop(ops, "sa");
		swap_a(stack_a, stack_b);
	}
	else if (op == 2 || op == 12)
	{
		ops = addop(ops, "ra");
		rotate_a(stack_a, stack_b);
	}
	else if (op == 10)
	{
		ops = addop(ops, "sb");
		swap_b(stack_a, stack_b);
	}
	else if (op == 20)
	{
		ops = addop(ops, "rb");
		rotate_b(stack_a, stack_b);
	}
}

t_stackops	*medresolve2(t_stack *stack_a, t_stack *stack_b, t_stackops *ops)
{
	int op;
	
	while (!issorted(stack_a) || !issortedreverse(stack_b))
	{
		op = 0;
		if (!issorted(stack_a))
			op += (stack_a->content[0] > stack_a->content[1] &&
					stack_a->content[0] < stack_a->content[stack_a->size - 1]) ? 1 : 2;
		if (!issortedreverse(stack_b))
			op += (stack_b->content[0] < stack_b->content[1] &&
					stack_b->content[0] > stack_b->content[stack_b->size - 1]) ? 10 : 20;
		if (op == 11)
		{
			ops = addop(ops, "ss");
			swap_both(stack_a, stack_b);
		}
		else if (op == 22)
		{
			ops = addop(ops, "rr");
			rotate_both(stack_a, stack_b);
		}
		else
			doop(stack_a, stack_b, ops, op);
	}
	return (ops);
}

t_stackops	*medresolve(t_stack *stack_a, t_stack *stack_b, t_stackops *ops)
{
	int	*medvalue;
	int	*medindex;

	if (!(medvalue = (int*)malloc(sizeof(int))))
		return (0);
	if (!(medindex = (int*)malloc(sizeof(int))))
		return (0);
	findmed(stack_a, medvalue, medindex);
	splitstacks(stack_a, stack_b, ops, *medvalue);
	ops = medresolve2(stack_a, stack_b, ops);
	while (stack_b->size > 0)
	{
		ops = addop(ops, "pa");
		push_a(stack_a, stack_b);
	}
	return(ops);
}
