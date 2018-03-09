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

t_stackops		*addop(t_stackops *ops, char *op, int size_sa, int size_sb)
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
		new->sizestack_a = size_sa;
		new->sizestack_b = size_sb;
	}
	else
		ops->op = op;
	return (ops);
}

void		findmax(t_stack *stack, int *val_max, int *index_max)
{
	t_stack		*current;
	int 	i;
	int		v;
	int		idx;

	i = 0;
	current = stack;
	v = -2147483648;
	idx = 0;
	while (current)
	{
		if (current->val > v)
		{
			v = current->val;
			idx = i;
		}
		i++;
		current = current->next;
	}
	*val_max = v;
	*index_max = idx;
}

void		findmin(t_stack *stack, int *val, int *index)
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
		if (current->val < v)
		{
			v = current->val;
			idx = i;
		}
		i++;
		current = current->next;
	}
	*val = v;
	*index = idx;
}


static void		shift(t_stack **stack, int pivot, t_stackops **ops)
{
	int size;

	size = count_list(*stack);
	if (pivot > size / 2)
	{
		*ops = addop(*ops, "rra", size, -1);
		*stack = reverse_rotate(*stack);
	}
	else
	{
		*ops = addop(*ops, "ra", size, -1);
		*stack = rotate(*stack);
	}
}

void basicsolve2(t_stack **s_a, t_stack **s_b, t_stackops **ops)
{
	int first_elem_a;
	int second_elem_a;
	int last_elem_a;
	t_stack *current;

	current = *s_a;
	first_elem_a = (*s_a)->val;
	second_elem_a = (*s_a)->next->val;

	while (current->next)
		current = current->next;
	last_elem_a = current->val;
	if (first_elem_a > second_elem_a)
	{
		*ops = addop(*ops, "sa", count_list(*s_a), count_list(*s_b));
		swap_a(s_a, s_b);
		basicsolve(s_a, s_b, ops);
	}
	else if (first_elem_a > last_elem_a)
	{
		*ops = addop(*ops, "ra", count_list(*s_a), count_list(*s_b));
		rotate_a(s_a, s_b);
		basicsolve(s_a, s_b, ops);
	}
	else
	{
		*ops = addop(*ops, "pb", count_list(*s_a), count_list(*s_b));
		push_b(s_a, s_b);
		basicsolve(s_a, s_b, ops);
	}
}

void basicsolve(t_stack **s_a, t_stack **s_b, t_stackops **ops)
{
	if (issorted(*s_a))
	{
		if ((*s_b))
		{
			*ops = addop(*ops, "pa", count_list(*s_a), count_list(*s_b));
			push_a(s_a, s_b);
			basicsolve(s_a, s_b, ops);
		}
	}
	else
		basicsolve2(s_a, s_b, ops);
}


int			smallresolve(t_stack **stack, t_stackops **ops)
{
	if (!(*stack) || !(*stack)->next)
		return (0);
	if ((*stack)->val > (*stack)->next->val)
	{
		if (*ops)
			*ops = addop(*ops, "sa", count_list(*stack), -1);
		else
		  ft_putendl("sa");
		*stack = swap(*stack);
	}
	return (0);
}


void	mediumsolve(t_stack *s_a, t_stack *s_b, t_stackops **ops)
{
	int	minval;
	int	minindex;

	while (!issorted(s_a) || s_b)
	{
		while (s_a && s_a->next && s_a->next->next)
		{
			findmin(s_a, &minval, &minindex);
			while (s_a->val > minval)
				shift(&s_a, minindex, ops);
			*ops = addop(*ops, "pb", count_list(s_a), count_list(s_b));
			push_b(&s_a, &s_b);
		}
		smallresolve(&s_a, ops);
		while (s_b)
		{
			*ops = addop(*ops, "pa", count_list(s_a), count_list(s_b));
			push_a(&s_a, &s_b);
		}
	}
	// free (minval);
	// free (minindex);
}
