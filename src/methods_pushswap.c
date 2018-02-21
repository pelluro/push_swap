/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_stackops		*addop(t_stackops *ops, char *op)
{
	t_stackops	*current;
	t_stackops	*new;

	if(!ops)
		ops = (t_stackops*)ft_memalloc(sizeof(t_stackops));
	if(ops->op)
	{
		current = ops;
		while (current->next)
			current = current->next;
		if (!(new = (t_stackops*)ft_memalloc(sizeof(t_stackops))))
			return(NULL);
		new->op = op;
		new->next = NULL;
		current->next = new;
	}
	else
		ops->op = op;
	return (ops);
}

static void		findmin(t_stack *stack, int *value, int *index)
{
	t_stack		*current;
	int 	i;
	int		v;
	int		idx;

	i = 0;
	current = stack;
	v = 2147483647;
	idx = 0;
	while (current)
	{
		if (current->value < v)
		{
			v = current->value;
			idx = i;
		}
		i++;
		current = current->next;
	}
	*value = v;
	*index = idx;
}


static void		shift(t_stack **stack, int pivot, t_stackops **ops)
{
	int size;

	size = ft_count_list(*stack);
	if (pivot > size / 2)
	{
		*ops = addop(*ops, "rra");
		*stack = reverse_rotate(*stack);
	}
	else
	{
		*ops = addop(*ops, "ra");
		*stack = rotate(*stack);
	}
}

//void basicsolve2(t_stack **s_a, t_stack **s_b, t_stackops **ops)
//{
//	int first_elem_a;
//	int second_elem_a;
//	int last_elem_a;
//	t_stack *current;
//
//	current = *s_a;
//	first_elem_a = (*s_a)->value;
//	second_elem_a = (*s_a)->next->value;
//
//	while (current->next)
//		current = current->next;
//	last_elem_a = current->value;
//	if (first_elem_a > second_elem_a)
//	{
//		*ops = addop(*ops, "sa");
//		swap_a(s_a, s_b);
//		basicsolve(s_a, s_b, ops);
//	}
//	else if (first_elem_a > last_elem_a)
//	{
//		*ops = addop(*ops, "ra");
//		rotate_a(s_a, s_b);
//		basicsolve(s_a, s_b, ops);
//	}
//	else
//	{
//		*ops = addop(*ops, "pb");
//		push_b(s_a, s_b);
//		basicsolve(s_a, s_b, ops);
//	}
//}
//
//void basicsolve(t_stack **s_a, t_stack **s_b, t_stackops **ops)
//{
//	if (issorted(*s_a))
//	{
//		if ((*s_b))
//		{
//			*ops = addop(*ops, "pa");
//			push_a(s_a, s_b);
//			basicsolve(s_a, s_b, ops);
//		}
//	}
//	else
//		basicsolve2(s_a, s_b, ops);
//}


int			smallresolve(t_stack **stack, t_stackops **ops)
{
	if (!(*stack) || !(*stack)->next)
		return (0);
	if ((*stack)->value > (*stack)->next->value)
	{
		if (*ops)
			*ops = addop(*ops, "sa");
		else
		  ft_putendl("sa");
		*stack = swap(*stack);
	}
	return (0);
}


void	mediumsolve(t_stack *s_a, t_stack *s_b, t_stackops **ops)
{
	int	*minvalue;
	int	*minindex;

	if (!(minvalue = (int*)ft_memalloc(sizeof(int))))
		ft_error(0);
	if (!(minindex = (int*)ft_memalloc(sizeof(int))))
		ft_error(0);
	while (!issorted(s_a) || s_b)
	{
		while (s_a && s_a->next && s_a->next->next)
		{
			findmin(s_a, minvalue, minindex);
			while (s_a->value > *minvalue)
				shift(&s_a, *minindex, ops);
			*ops = addop(*ops, "pb");
			push_b(&s_a, &s_b);
		}
		smallresolve(&s_a, ops);
		while (s_b)
		{
			*ops = addop(*ops, "pa");
			push_a(&s_a, &s_b);
		}
	}
	free (minvalue);
	free (minindex);
}
