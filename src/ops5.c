/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void		findmin(t_stack *stack, int *value, int *index)
{
	int		i;
	int		v;
	int		idx;

	i = 0;
	v = stack->content[0];
	idx = 0;
	while (i < stack->size)
	{
		if (stack->content[i] < v)
		{
			v = stack->content[i];
			idx = i;
		}
		i++;
	}
	*value = v;
	*index = idx;
}

void		findmax(t_stack *stack, int *value, int *index)
{
	int		i;
	int		v;
	int		idx;

	i = 0;
	v = stack->content[0];
	idx = 0;
	while (i < stack->size)
	{
		if (stack->content[i] > v)
		{
			v = stack->content[i];
			idx = i;
		}
		i++;
	}
	*value = v;
	*index = idx;
}

void		findmed(t_stack *stack, int *value, int *index)
{
	t_stack *copy;

	copy = copystack(stack);
	ft_sort_integer_table(copy->content, copy->size - 1);
	*index = stack->size / 2;
	*value = copy->content[*index];
}

void		shift(t_stack *stack, int pivot, t_stackops *ops)
{
	if (pivot > stack->size / 2)
	{
		ops = addop(ops, "rra");
		reverse_rotate(stack);
	}
	else
	{
		ops = addop(ops, "ra");
		rotate(stack);
	}
}

t_stack		*copystack(t_stack *stack)
{
	t_stack	*stack_copy;
	int		i;
	stack_copy = (t_stack*) malloc(sizeof(t_stack));
	stack_copy->content = (int*) malloc(sizeof(int) * stack->size);
	stack_copy->size = stack->size;
	i = 0;
	while (i < stack->size)
	{
		stack_copy->content[i] = stack->content[i];
		i++;
	}
	return (stack_copy);
}
