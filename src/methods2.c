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
	t_stack* current;

	current = stack;
	while (current && current->next)
	{
		if (current->next->value <= current->value)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack		*parsestack(t_stack *stack, char *str)
{
	int		i;
	int		j;
	char	**tabnb;
	t_stack *current;

	current = NULL;
	if (!(tabnb = ft_split_whitespaces(str)))
		return (0);
	i = 0;
	while (tabnb[i])
	{
		if (ft_strlen(tabnb[i]) == 1 && tabnb[i][0] == '0')
			current = create_node(current ? current : stack, 0);
		else
		{
			j = ft_atoi(tabnb[i]);
			if (j != 0)
			current = create_node(current ? current : stack, j);
			else
				return (0);
		}
		i++;
	}
	return (stack);
}

t_stack		*create_node(t_stack *prevelem, int value)
{
	t_stack* newnode;

	newnode = (t_stack*)ft_memalloc(sizeof(t_stack));
	if (newnode)
	{
		newnode->value = value;
		prevelem->next = newnode;
		newnode->next = NULL;
	}
	return (newnode);
}
