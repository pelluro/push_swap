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
void	exit_func(t_stack *m, t_stackops *n, int error)
{
	int i;

	free(m->content);
	free(m->size);
	free_array(n->content, m, 0);
		i = -1;
		while (++i < n->size)
			free(m->content[i]);
		free(m->tab);
	}
	free(m);
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

void	free_array(char **array, t_stac *m, int error)
{
	int i;

	i = 0;
	while (array[i])
		(array[i]) ? free(array[i++]) : 0;
	free(array);
	if (error)
		exit_func(m, 1);
	array = NULL;
}
