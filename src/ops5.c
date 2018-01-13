/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void		findmin(t_stack *stack, int *value, int *index)
{
	t_stack		*current;
	int 	i;
	int		v;
	int		idx;

	i = 0;
	current = stack->next;
	v = current ? current->content : 2147483647;
	idx = 0;
	while (!current->isroot)
	{
		if (current->content < v)
		{
			v = current->content;
			idx = i;
		}
		i++;
		current = current->next;
	}
	*value = v;
	*index = idx;
}

void		findmed(t_stack *stack, int *value, int *index)
{
	t_stack *copy;
	int* size;
	int* tab;
	
	size = (int*)malloc(sizeof(int));
	copy = copystack(stack);
	tab = stacktotab(copy,size);
	ft_sort_integer_table(tab, (*size - 1));
	*index = *size / 2;
	*value = tab[(*index)];
	free(size);
}

void		shift(t_stack *stack, int pivot, t_stackops *ops)
{
	t_stack *current;
	current = stack->next;
	int size;
	
	size = 0;
	while (current && !current->isroot)
	{
		current = current->next;
		size++;
	}
	if (pivot > size / 2)
	{
		ops = addop(ops, "rra");
		reverse_rotate(stack);
	}
	else
	{
		ops = addop(ops, "ra");
		rotate(stack);
	}
}

t_stack		*copystack(t_stack *stack)
{
	t_stack	*stack_copy;
	t_stack	*current;
	t_stack	*current_copy;
	
	if (!(stack_copy = (t_stack*) malloc(sizeof(t_stack))))
		return (0);
	stack_copy->isroot = 1;
	current = stack->next;
	current_copy = NULL;
	while (current && !current->isroot)
	{
		current_copy = create_node(current_copy ? current_copy : stack_copy, stack_copy, current->content);
		current = current->next;
	}
	return (stack_copy);
}

int* stacktotab(t_stack* stack, int* size)
{
	t_stack *current;
	int* tab;
	
	current = stack->next;
	*size = 0;
	while (current && !current->isroot)
	{
		current = current->next;
		(*size)++;
	}
	tab = (int*)malloc(sizeof(int)*(*size));
	current = stack->next;
	*size = 0;
	while (current && !current->isroot)
		tab[(*size)++] = current->content;
	return(tab);
}
