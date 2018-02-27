/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_stack *swap(t_stack *first)
{
	t_stack *second;

	if(first)
	{
		second = first->next;
		if(second)
		{
			first->next = second->next;
			second->next = first;
			return (second);
		}
	}
	return (first);
}

void swap_a(t_stack **s_a, t_stack **s_b)
{
	*s_a = swap(*s_a);
	(void)s_b;
}

void swap_b(t_stack **s_a, t_stack **s_b)
{
	*s_b = swap(*s_b);
	(void)s_a;
}

void swap_both(t_stack **s_a, t_stack **s_b)
{
	*s_a = swap(*s_a);
	*s_b = swap(*s_b);
}
