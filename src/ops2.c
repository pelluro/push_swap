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


void push(t_stack *stackfrom, t_stack *stackto)
{
	if (stackfrom && stackfrom->size >= 1)
	{
		stackto = add_top(stackto, stackfrom->content[0]);
		stackfrom = remove_elem(stackfrom);
	}
}

void push_a(t_stack *s_a, t_stack *s_b)
{
	push(s_b, s_a);
}

void push_b(t_stack *s_a, t_stack *s_b)
{
	push(s_a, s_b);
}

t_stack *add_top(t_stack *stack, int c)
{
	t_stack *current;
	
	current = stack->next;
	create_node(stack, current ? current->next : stack, c);
	return (stack);
}

t_stack *remove_elem(t_stack *stack)
{
	t_stack *current;
		
	current = stack->next;
	if(current)
	{
			stack->next = current->next;
			if(current->next)
				current->next->previous = stack;
			free(current);
	}	return (stack);
}
