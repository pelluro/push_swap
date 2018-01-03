/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_stackops	*basicresolve2(t_stack *stack_a, t_stack *stack_b, t_stackops *ops)
{
	int first_elem_a;
	int second_elem_a;
	int last_elem_a;

	first_elem_a = stack_a->content[0];
	second_elem_a = stack_a->content[1];
	last_elem_a = stack_a->content[stack_a->size - 1];
	if (first_elem_a > second_elem_a)
	{
		ops = addop(ops, "sa");
		swap_a(stack_a, stack_b);
		return (basicresolve(stack_a, stack_b, ops));
	}
	else if (first_elem_a > last_elem_a)
		{
			ops = addop(ops, "ra");
			rotate_a(stack_a, stack_b);
			return (basicresolve(stack_a, stack_b, ops));
		}
	else
	{
		ops = addop(ops, "pb");
		push_b(stack_a, stack_b);
		return (basicresolve(stack_a, stack_b, ops));
	}
}

t_stackops	*basicresolve(t_stack *stack_a, t_stack *stack_b, t_stackops *ops)
{
	if (issorted(stack_a))
	{
		if (stack_b->size == 0)
			return ops;
		else
		{
			ops = addop(ops, "pa");
			push_a(stack_a, stack_b);
			return basicresolve(stack_a, stack_b, ops);
		}
	}
	if (stack_a->size > 1)
			return basicresolve2(stack_a, stack_b, ops);
	else
	{
		ops = addop(ops, "pa");
		push_a(stack_a, stack_b);
		return (basicresolve(stack_a, stack_b, ops));
	}
}

int			smallresolve(t_stack *stack, t_stackops *ops)
{
		if (!stack || !stack->content || stack->size > 2)
		return (-1);
		if (stack->content[0] > stack->content[1])
		{
			if (ops)
				ops = addop(ops, "sa");
			else
			  ft_putendl("sa");
			swap(stack);
		}
		return (0);
}

t_stackops	*mediumresolve(t_stack *stack_a, t_stack *stack_b, t_stackops *ops)
{
	int	*minvalue;
	int	*minindex;

	if (!(minvalue = (int*)malloc(sizeof(int))))
		return (0);
	if (!(minindex = (int*)malloc(sizeof(int))))
		return (0);
	while (!issorted(stack_a) || stack_b->size > 0)
	{
		while (stack_a->size > 2)
		{
			findmin(stack_a, minvalue, minindex);
			while (stack_a->content[0] > *minvalue)
				shift(stack_a, *minindex, ops);
			ops = addop(ops, "pb");
			push_b(stack_a, stack_b);
		}
		smallresolve(stack_a, ops);
		while (stack_b->size > 0)
		{
			ops = addop(ops, "pa");
			push_a(stack_a, stack_b);
		}
	}
	return (ops);
}

t_stackops	*addop(t_stackops *ops, char *op)
{
	ops->content[ops->size] = op;
	ops->size = ops->size + 1;
	return (ops);
}
