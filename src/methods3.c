/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int			issorted(t_stack *stack)
{
	int i = 1;
	if (stack->size == 0)
		return (0);
	if (stack->size == 1)
		return (1);
	while (i < stack->size)
	{
		if (stack->content[i - 1] >= stack->content[i])
			return (0);
		i++;
	}
	return (1);
}


int			issortedreverse(t_stack *stack)
{
	int i = 1;
	if (stack->size == 0)
		return (0);
	if (stack->size == 1)
		return (1);
	while (i < stack->size)
	{
		if (stack->content[i - 1] <= stack->content[i])
			return (0);
		i++;
	}
	return (1);
}
