/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
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
	t_stack	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->next->value <= current->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack		*create_node(t_stack *prevelem, int value)
{
	t_stack	*newnode;

	newnode = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (newnode)
	{
		newnode->value = value;
		prevelem->next = newnode;
		newnode->next = NULL;
	}
	return (newnode);
}
