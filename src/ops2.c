/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"


void push(t_stack *stackfrom, t_stack *stackto)
{
	t_stack *stackmove;

	if (stackfrom && stackto)
	{
			stackmove = stackfrom;
			stackfrom = stackfrom->next;
			stackmove->next = stackto;
			stackto = stackmove;
	}
}

void push_a(t_stack *s_a, t_stack *s_b)
{
	push(s_b, s_a);
}

void push_b(t_stack *s_a, t_stack *s_b)
{
	push(s_a, s_b);
}
