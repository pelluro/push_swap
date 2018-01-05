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

void	free_stack(t_stack *m)
{
	free(m->content);
	m->content = NULL;
	free(m);
}

void	free_stackops(t_stackops *n)
{
	int i;

	i = 0;
	while (n->content[i])
	{
		free(n->content[i]);
		i++;
	}
	free(n->content);
	n->content = NULL;
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
