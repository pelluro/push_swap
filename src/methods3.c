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
	t_stack* current;

	if (!stack->next)
		return (0);
	current = stack->next;
	if (!current->next || current->next->isroot)
		return (1);
	current = current->next;
	while (current && !current->isroot)
	{
		if (current->previous->content >= current->content)
			return (0);
		current = current->next;
	}
	return (1);
}


int			issortedreverse(t_stack *stack)
{
	t_stack* current;

	if (!stack->next)
		return (0);
	current = stack->next;
	if (!current->next || current->next->isroot)
		return (1);
	current = current->next;
	while (current && !current->isroot)
	{
		if (current->previous->content <= current->content)
			return (0);
		current = current->next;
	}
	return (1);
}

void	free_stack(t_stack *m)
{
	free(m);
}

void	free_stackops(t_stackops *n)
{
	free(n->content);
	free(n);
}

void	ft_error(int error)
{
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}
