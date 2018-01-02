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

void rotate(t_stack* stack)
{
	int i;
	int c;

	if(stack && stack->size > 1)
	{
		i = 1;
		c = stack->content[0];
		while(i <= stack->size - 1)
		{
			stack->content[i-1] = stack->content[i];
			i++;
		}
		stack->content[stack->size - 1] = c;
	}
}

void rotate_a(t_stack* stack_a, t_stack* stack_b)
{
	rotate(stack_a);
	(void)stack_b;
}

void rotate_b(t_stack* stack_a, t_stack* stack_b)
{
	rotate(stack_b);
	(void)stack_a;
}

void rotate_both(t_stack* stack_a, t_stack* stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
