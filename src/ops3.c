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

t_stack		*rotate(t_stack *first)
{
	t_stack *current;
	t_stack *second;

	current = first;
	second = first->next;
	if (!second)
		return (first);
	while (current->next)
		current = current->next;
	first->next = NULL;
	current->next = first;
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
