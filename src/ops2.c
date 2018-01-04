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


void		push(t_stack *stackfrom, t_stack *stackto)
{
	if (stackfrom && stackfrom->size >= 1)
	{
		stackto = add_top(stackto, stackfrom->content[0]);
		stackfrom = remove_elem(stackfrom, 0);
	}
}

void		push_a(t_stack *s_a, t_stack *s_b)
{
	push(s_b, s_a);
}

void		push_b(t_stack *s_a, t_stack *s_b)
{
	push(s_a, s_b);
}

t_stack		*add_top(t_stack *stack, int c)
{
	int	i;
	int	*s;

  	i = 0;
	s = (int*)malloc(sizeof(int) * (stack->size));
	while (i < stack->size)
	{
		s[i] = stack->content[i];
		i++;
	}
	stack->content = (int*)malloc(sizeof(int) * ((stack->size) + 1));
	stack->content[0] = c;
	if (stack->size > 0)
	{
		i = 0;
		while (i < stack->size)
		{
			stack->content[1 + i] = s[i];
			i++;
		}
	}
	stack->size = (stack->size) + 1;
	free(s);
	return (stack);
}

t_stack		*remove_elem(t_stack *stack, int index)
{
	int		i;
	int		j;
	int		*s;
	
	i = -1;
	j = 0;
	if (!(s = (int*)malloc(sizeof(int)*(stack->size))))
		return (0);
	while (i++ < stack->size)
		s[i] = stack->content[i];
	if (!(stack->content = (int*)malloc(sizeof(int)*((stack->size) - 1))))
		return (0);
	i = 0;
	while (i < stack->size)
	{
		if (i != index)
			stack->content[j++] = s[i];
		i++;
	}
	stack->size = (stack->size) - 1;
	free(s);
	return (stack);
}
