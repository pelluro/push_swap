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
		if (current->next->val <= current->val)
			return (0);
		current = current->next;
	}
	return (1);
}

int			issorted_reverse(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current && current->next)
	{
		if (current->next->val >= current->val)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack		*create_node(t_stack *prevelem, int val)
{
	t_stack	*newnode;

	newnode = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (newnode)
	{
		newnode->val = val;
		newnode->next = NULL;
		if(prevelem)
			prevelem->next = newnode;
	}
	return (newnode);
}
