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

int guessmvt(t_stack* stackA, t_stack* stackB, int i)
{
	int firstElemA;
	int secondElemA;
	int lastElemA;
	if(i>100)
		return(-1);
	if(issorted(stackA))
	{
		if(stackB->size == 0)
			return (0);
		else
		{
			printf("pa\n");
			push_a(stackA,stackB);
			return guessmvt(stackA,stackB,i+1);
		}
	}
	if(stackA->size> 1)
	{
		firstElemA = stackA->content[0];
		secondElemA = stackA->content[1];
		lastElemA = stackA->content[stackA->size - 1];
		if(firstElemA > secondElemA)
		{
				printf("sa\n");
				swap_a(stackA,stackB);
				return guessmvt(stackA,stackB,i+1);
		}
		else if(firstElemA > lastElemA)
			{
				printf("ra\n");
				rotate_a(stackA,stackB);
				return guessmvt(stackA,stackB,i+1);
			}
		else
		{
			printf("pb\n");
			push_b(stackA,stackB);
			return guessmvt(stackA,stackB,i+1);
		}
	}
	else
	{
		printf("pa\n");
		push_a(stackA,stackB);
		return guessmvt(stackA,stackB,i+1);
	}
	return -1;
}

int main(int argc, char** argv)
{
	t_stack* stackA;
	t_stack* stackB;
	
	stackA = (t_stack*)malloc(sizeof(t_stack));
	stackB = (t_stack*)malloc(sizeof(t_stack));
	stackA->content = (int*)malloc(sizeof(int)* (argc-1));
	stackA->size = argc - 1;
	stackB->content = NULL;
	stackB->size = 0;
	if(!makeStack(stackA, argc, argv))
	{
		printf("Error\n");
		return (-1);
	}
	if(guessmvt(stackA, stackB,0)<0)
	{
		printf("Error\n");
		return (-1);
	}
	return 0;
}

