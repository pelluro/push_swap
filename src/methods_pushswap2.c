/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_pushswap2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

static void	clean_push(t_stackops **ops)
{
	t_stackops *current;
	t_stackops *previous;

	previous = NULL;
	current = *ops;
	while (current && current->next)
	{
		if (
		 (!ft_strcmp(current->op, "pa") && !ft_strcmp(current->next->op, "pb"))
		 ||
		 (!ft_strcmp(current->op, "pb") && !ft_strcmp(current->next->op, "pa")))
		{
			if (!previous)
			{
				*ops = current->next->next;
				current = current->next->next;
				continue;
			}
			else
			{
				previous->next = current->next->next;
				current = current->next->next;
				continue;
			}
		}
		previous = current;
		current = current->next;
	}
}

static void clean_rotate(t_stackops **ops)
{
		t_stackops *current;
		t_stackops *previous;

		previous = NULL;
		current = *ops;
		while (current && current->next)
		{
			if ((!ft_strcmp(current->op, "ra") &&
				 !ft_strcmp(current->next->op, "rb"))
				|| (!ft_strcmp(current->op, "rb") &&
					!ft_strcmp(current->next->op, "ra")))
			{
				if (!previous)
				{
					*ops = current->next;
					current->next->op = "rr";
					current = current->next->next;
					continue;
				}
				else
				{
					previous->next = current->next;
					current->next->op = "rr";
					current = current->next->next;
					continue;
				}
			}
			previous = current;
			current = current->next;
		}
}

static void clean_reverserotate(t_stackops **ops)
{
	t_stackops *current;
	t_stackops *previous;

	previous = NULL;
	current = *ops;
	while (current && current->next)
	{
		if ((!ft_strcmp(current->op, "rra") && !ft_strcmp(current->next->op, "rrb"))
			|| (!ft_strcmp(current->op, "rrb") && !ft_strcmp(current->next->op, "rra")))
		{
			if (!previous)
			{
				*ops = current->next;
				current->next->op = "rrr";
				current = current->next->next;
				continue;
			}
			else
			{
				previous->next = current->next;
				current->next->op = "rrr";
				current = current->next->next;
				continue;
			}
		}
		previous = current;
		current = current->next;
	}
}

void clean_ops(t_stackops **ops)
{
	clean_push(ops);
	clean_rotate(ops);
	clean_reverserotate(ops);
}

void		findmed(t_stack *stack, int *value, int *index)
{
	t_stack *copy;
	int size;
	int* tab;

	//size = (int*)ft_memalloc(sizeof(int));
	copy = copystack(stack);
	tab = stacktotab(copy,&size);
	ft_sort_integer_table(tab, (size));
	*index = size / 2;
	*value = tab[(*index)];
	printf("med: %d\n", *value);
	//free(size);
}

t_stack		*copystack(t_stack *stack)
{
	t_stack	*stack_copy;
	t_stack	*current;
	t_stack	*current_copy;

	current = stack;
	current_copy = NULL;
	if(!(stack_copy = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return(NULL);
	while (current)
	{
		current_copy = create_node(current_copy ? current_copy : stack_copy, current->value);
		current = current->next;
	}
	return (stack_copy->next);
}

int* stacktotab(t_stack* stack, int* size)
{
	t_stack *current;
	int* tab;
	int i;

	current = stack;
	*size = 0;
	while (current)
	{
		current = current->next;
		(*size)++;
	}
	tab = (int*)ft_memalloc(sizeof(int) * (*size));
	current = stack;
	i = 0;
	while (current)
	{
		tab[i] = current->value;
		current = current->next;
		i++;
	}
	return(tab);
}
