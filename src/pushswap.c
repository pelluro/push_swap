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

void printstackops(t_stackops* ops)
{
	int i;
	i = 0;

	while(i < ops->size)
	{
		ft_putendl(ops->content[i]);
		i++;
	}
}

int main(int argc, char** argv)
{
	t_stack* stack_a;
	t_stack* stack_b;
	t_stackops* ops1;
	t_stackops* ops2;

	stack_a = (t_stack*)malloc(sizeof(t_stack));
	stack_b = (t_stack*)malloc(sizeof(t_stack));
	stack_b->content = NULL;
	stack_b->size = 0;
	if(!makestack(stack_a, argc, argv))
	{
		ft_putendl("Error");
		return (-1);
	}
	if(stack_a->size <= 2)
			return (smallresolve(stack_a, NULL));
		else
		{
				ops1 = (t_stackops*)malloc(sizeof(t_stackops));
				ops2 = (t_stackops*)malloc(sizeof(t_stackops));
				ops1->content = (char**)malloc(sizeof(char*)*1000);
				ops2->content = (char**)malloc(sizeof(char*)*1000);
				ops1->size = 0;
				ops2->size = 0;
				ops1 = basicresolve(copystack(stack_a),copystack(stack_b),ops1);
				ops2 = mediumresolve(copystack(stack_a),copystack(stack_b),ops2);
				if(ops1->size > ops2->size)
					printstackops(ops2);
				else
				  printstackops(ops1);
		}
	return (0);
}
