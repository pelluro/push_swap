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
	int first_elem_a;
	int second_elem_a;
	int last_elem_a;

	first_elem_a = s_a->next->content;
	second_elem_a = s_a->next->next->content;
	last_elem_a = s_a->previous->content;
	if (first_elem_a > second_elem_a)
	{
		ft_putendl("sa");
		ops = addop(ops, "sa");
		swap_a(s_a, s_b);
		return (basicsolve(s_a, s_b, ops));
	}
	else if (first_elem_a > last_elem_a)
	{
		ft_putendl("ra");
		ops = addop(ops, "ra");
		rotate_a(s_a, s_b);
		return (basicsolve(s_a, s_b, ops));
	}
	else
	{
		ft_putendl("pb");
		ops = addop(ops, "pb");
		push_b(s_a, s_b);
		return (basicsolve(s_a, s_b, ops));
	}
}

t_stackops	*basicsolve(t_stack *s_a, t_stack *s_b, t_stackops *ops)
{
	if (issorted(s_a))
	{
		if (!s_b->next || s_b->isroot)
			return (ops);
		else
		{
			ops = addop(ops, "pa");
			push_a(s_a, s_b);
			return (basicsolve(s_a, s_b, ops));
		}
	}
	return (basicsolve2(s_a, s_b, ops));
}

int			smallresolve(t_stack *stack, t_stackops *ops)
{
	if (!stack)
		ft_error(0);
	if (stack->next->content > stack->previous->content)
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
		ft_error(0);
	if (!(minindex = (int*)malloc(sizeof(int))))
		ft_error(0);
	while (!issorted(s_a) || (s_b->next && !s_b->next->isroot))
	{
		while (s_a->next && !s_a->next->isroot 
		&& s_a->next->next && !s_a->next->isroot 
		&& !s_a->next->next->isroot)
		{
			findmin(s_a, minvalue, minindex);
			while (s_a->next->content > *minvalue)
				shift(s_a, *minindex, ops);
			ops = addop(ops, "pb");
			push_b(s_a, s_b);
		}
		smallresolve(s_a, ops);
		while (s_b->next && !s_b->next->isroot)
		{
			ops = addop(ops, "pa");
			push_a(s_a, s_b);
		}
		printf("end mediumsolve\n");
	}
	return (ops);
}

t_stackops	*addop(t_stackops *ops, char *op)
{
	t_stackops * current;
	t_stackops * new;
	
	if(ops->content)
	{
		current = ops;
		while(current->next)
			current = current->next;
		if (!(new = (t_stackops*)malloc(sizeof(t_stackops))))
			return(NULL);
		new->content = op;
		new->next = NULL;
		current->next = new;
	}
	else
		ops->content = op;
	return (ops);
}

void		printtab(t_stack *stack)
{
	t_stack * current;
	
	current = stack->next;
	while (current && !current->isroot)
	{
		printf("%d\n",current->content);
		current = current->next;
	}
}