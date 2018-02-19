/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/pushswap.h"

t_stack		*reverse_rotate(t_stack *first)
{
	t_stack* current;
	t_stack* last;

	current = first;
	if (!first || !first->next)
		return (first);
	if (!first->next->next)
		return (swap(first));
	while (current->next->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = first;
	return (last);
}

void		reverse_rotate_a(t_stack **s_a, t_stack **s_b)
{
	*s_a = reverse_rotate(*s_a);
	(void)s_b;
}

void		reverse_rotate_b(t_stack **s_a, t_stack **s_b)
{
	*s_b = reverse_rotate(*s_b);
	(void)s_a;
}

void		reverse_rotate_both(t_stack **s_a, t_stack **s_b)
{
	*s_a = reverse_rotate(*s_a);
	*s_b = reverse_rotate(*s_b);
}
