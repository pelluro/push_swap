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

void		reverse_rotate(t_stack *stack)
{
	int	i;
	int	c;

	if (stack && stack->size > 1)
	{
		i = stack->size - 2;
		c = stack->content[i + 1];
		while (i >= 0)
		{
			stack->content[i + 1] = stack->content[i];
			i--;
		}
		stack->content[0] = c;

	}
}

void		reverse_rotate_a(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_a);
	(void)s_b;
}

void		reverse_rotate_b(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_b);
	(void)s_a;
}

void		reverse_rotate_both(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
}
