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

t_stackops	*basicsolve2(t_stack *s_a, t_stack *s_b, t_stackops *ops)
{
	int	first_elem_a;
	int	second_elem_a;
	int	last_elem_a;

	first_elem_a = s_a->content[0];
	second_elem_a = s_a->content[1];
	last_elem_a = s_a->content[s_a->size - 1];
	if (ops->size > 10000)
		return (0);
	if (first_elem_a > second_elem_a)
	{
		ops = addop(ops, "sa");
		swap_a(s_a, s_b);
		return (basicsolve(s_a, s_b, ops));
	}
	else if (first_elem_a > last_elem_a)
		{
			ops = addop(ops, "ra");
			rotate_a(s_a, s_b);
			return (basicsolve(s_a, s_b, ops));
		}
	else
	{
		ops = addop(ops, "pb");
		push_b(s_a, s_b);
		return (basicsolve(s_a, s_b, ops));
	}
}

t_stackops	*basicsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops)
{
	if (ops->size > 10000)
		return (0);
	if (issorted(s_a))
	{
		if (s_b->size == 0)
			return (ops);
		else
		{
			ops = addop(ops, "pa");
			push_a(s_a, s_b);
			return (basicsolve(s_a, s_b, ops));
		}
	}
	if (s_a->size > 1)
			return (basicsolve2(s_a, s_b, ops));
	else
	{
		ops = addop(ops, "pa");
		push_a(s_a, s_b);
		return (basicsolve(s_a, s_b, ops));
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


t_stackops	*mediumsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops)
{
	int	*minvalue;
	int	*minindex;

	if (!(minvalue = (int*)malloc(sizeof(int))))
		return (0);
	if (!(minindex = (int*)malloc(sizeof(int))))
		return (0);
	while (!issorted(s_a) || s_b->size > 0)
	{
		while (s_a->size > 2)
		{
			findmin(s_a, minvalue, minindex);
			while (s_a->content[0] > *minvalue)
				shift(s_a, *minindex, ops);
			ops = addop(ops, "pb");
			push_b(s_a, s_b);
		}
		smallresolve(s_a, ops);
		while (s_b->size > 0)
		{
			if (ops->size > 10000)
				return (NULL);
			ops = addop(ops, "pa");
			push_a(s_a, s_b);
		}
	}
	return (ops);
}

t_stackops	*addop(t_stackops *ops, char *op)
{
	ops->content[ops->size] = op;
	ops->size = ops->size + 1;
//	printf("opssize=%d\n",ops->size);
	return (ops);
}

void		printtab(t_stack *stack)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		printf("%d\n",stack->content[i]);
		i++;
	}
}