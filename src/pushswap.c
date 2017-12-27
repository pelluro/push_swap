/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:03:05 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:03:20 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int guessmvt(t_stack *stack_a, t_stack *stack_b, int i)
{
	int first_elem_a;
	int second_elem_a;
	int last_elem_a;
	
	if(i > 100)
		return(-1);
	if(issorted(stack_a))
	{
		if(stack_b->size == 0)
			return (0);
		else
		{
			printf("pa\n");
			push_a(stack_a, stack_b);
			return guessmvt(stack_a, stack_b, i + 1);
		}
	}
	if(stack_a->size > 1)
	{
		first_elem_a = stack_a->content[0];
		second_elem_a = stack_a->content[1];
		last_elem_a = stack_a->content[stack_a->size - 1];
		if(first_elem_a > second_elem_a)
		{
				printf("sa\n");
				swap_a(stack_a, stack_b);
				return (guessmvt(stack_a, stack_b, i + 1));
		}
		else if(first_elem_a > last_elem_a)
			{
				printf("ra\n");
				rotate_a(stack_a, stack_b);
				return (guessmvt(stack_a, stack_b, i + 1));
			}
		else
		{
			printf("pb\n");
			push_b(stack_a, stack_b);
			return (guessmvt(stack_a, stack_b, i + 1));
		}
	}
	else
	{
		printf("pa\n");
		push_a(stack_a, stack_b);
		return (guessmvt(stack_a, stack_b, i + 1));
	}
}

int main(int argc, char** argv)
{
	t_stack* stack_a;
	t_stack* stack_b;
	
	stack_a = (t_stack*)malloc(sizeof(t_stack));
	stack_b = (t_stack*)malloc(sizeof(t_stack));
	stack_a->content = (int*)malloc(sizeof(int) * (argc - 1));
	stack_a->size = argc - 1;
	stack_b->content = NULL;
	stack_b->size = 0;
	if(!makestack(stack_a, argc, argv))
	{
		printf("Error\n");
		return (-1);
	}
	if(guessmvt(stack_a, stack_b, 0) < 0)
	{
		printf("Error\n");
		return (-1);
	}
	return (0);
}