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

void printstackops(t_stackops *ops)
{
	int i;

	i = 0;
	while (i < ops->size)
	{
		ft_putendl(ops->content[i]);
		i++;
	}
}
void init_op(t_stackops *ops)
{
	ops = NULL;
	if (!(ops = (t_stackops*)malloc(sizeof(t_stackops))))
		return ;
	if (!(ops->content = (char**)malloc(sizeof(char*) * 10000000)))
		return ;
	ops->size = 0;
}

int		main(int argc, char** argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stackops	*ops1;
	t_stackops	*ops2;
	t_stackops	*ops3;

	if (!(stack_a = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	if (!(stack_b = (t_stack*)malloc(sizeof(t_stack))))
		return (0);
	stack_b->content = NULL;
	stack_b->size = 0;
	if (!makestack(stack_a, argc, argv))
	{
		ft_putendl("Error makestack");
		return (-1);
	}
	if (stack_a->size <= 2)
			return (smallresolve(stack_a, NULL));
	else
	{
		if (!(ops1 = (t_stackops*)malloc(sizeof(t_stackops))))
			return 0;
		if (!(ops2 = (t_stackops*)malloc(sizeof(t_stackops))))
			return 0;
		if (!(ops3 = (t_stackops*)malloc(sizeof(t_stackops))))
			return 0;
		if (!(ops1->content = (char**)malloc(sizeof(char*) * 10000000)))
			return 0;
		if (!(ops2->content = (char**)malloc(sizeof(char*) * 10000000)))
			return 0;
		if (!(ops3->content = (char**)malloc(sizeof(char*) * 10000000)))
			return 0;
		ops1->size = 0;
		ops2->size = 0;
		ops3->size = 0;
		ops1 = basicresolve(copystack(stack_a), copystack(stack_b), ops1);
		ops2 = mediumresolve(copystack(stack_a), copystack(stack_b), ops2);
		ops3 = medresolve(copystack(stack_a), copystack(stack_b), ops3);
		if (ops1->size > ops2->size && ops3->size > ops2->size)
			printstackops(ops2);
		else if (ops3->size > ops1->size)
			printstackops(ops1);
		else
			printstackops(ops3);
	}
	return (0);
}
