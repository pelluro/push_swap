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

void swap(t_stack *stack)
{
	int c;
	if (stack && stack->content && (stack->size) >= 2)
	{
		c = stack->content[0];
		stack->content[0] = stack->content[1];
		stack->content[1] = c;
	}
}
void swap_a(t_stack *s_a, t_stack *s_b)
{
	swap(s_a);
	(void)s_b;
}

void swap_b(t_stack *s_a, t_stack *s_b)
{
	swap(s_b);
	(void)s_a;
}

void swap_both(t_stack *s_a, t_stack *s_b)
{
	swap(s_a);
	swap(s_b);
}
