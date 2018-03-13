/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:46 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:49 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"


int main (int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*tmp;
	t_stackops	*ops;
	int f;

	f = 0;
	if (!(tmp = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (0);
	stack_a = tmp;
	stack_b = NULL;
	ops = NULL;
	if (makestack(stack_a, ac, av, &f))
	{
		stack_a = stack_a->next;
		medsolve(copystack(stack_a), stack_b, &ops);
//		print_stackops(ops);
//		printf("\n\n\n\n\n");
		clean_ops(&ops);
		print_stackops(ops);
	}
	else
	{
		ft_putendl("error");
	}
	// ft_del_stack(&stack_a);
	// ft_del_stack(&stack_b);
	// ft_del_stackops(&ops);
	free(tmp);
	return (0);
}
