/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pushswap.h"

void		rotate(t_stack *stack)
{
	t_stack* first;
	t_stack* last;
	
	first = stack->next;
	last = stack->previous;
	if(first && last)
	{
		stack->next = first->next;
		stack->previous = first;
		first->next = stack;
		first->previous = last;
		last->next = first;
	}
}

void		rotate_a(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	(void)s_b;
}

void		rotate_b(t_stack *s_a, t_stack *s_b)
{
	rotate(s_b);
	(void)s_a;
}

void		rotate_both(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	rotate(s_b);
}
