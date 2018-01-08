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

t_stackops *init_so(t_stackops *ops)
{
	if (!(ops = (t_stackops*)malloc(sizeof(t_stackops))))
		return(NULL);
	if (!(ops->content = (char**)malloc(sizeof(char*) * 100000)))
		return(NULL);
	ops->size = 0;
	return (ops);
}

t_stack	*init_stack(t_stack *s)
{
	if (!(s = (t_stack*)malloc(sizeof(t_stack))))
		return(NULL);
	return (s);
}

void compare(t_stackops *ops1, t_stackops *ops2, t_stackops *ops3)
{
	if (!ops1 && !ops2 && !ops3)
		ft_error(0);
	else if (ops1 && ops2 && ops3)
	{
		if (ops1->size > ops2->size && ops3->size > ops2->size)
			printstackops(ops2);
		else if (ops3->size > ops1->size)
			printstackops(ops1);
		else
			printstackops(ops3);
	}
	if (ops1 && !ops2 && !ops3)
		printstackops(ops1);
	else if (ops2 && !ops1 && !ops3)
		printstackops(ops2);
	else if (ops3 && !ops2 && !ops3)
		printstackops(ops3);
	else if (!ops1)
	{
		ops3->size > ops2->size ? printstackops(ops2) : printstackops(ops3);
//		free_stackops(ops2);
//		free_stackops(ops3);
	}
	else if (!ops2)
	{
		ops3->size > ops1->size ? printstackops(ops1) : printstackops(ops3);
//		free_stackops(ops1);
//		free_stackops(ops3);
	}
	else if (!ops3)
	{
		ops1->size > ops2->size ? printstackops(ops2) : printstackops(ops1);
//		free_stackops(ops1);
//		free_stackops(ops2);
	}
}

int		main(int argc, char **argv)
{
	t_stack		**stacks;
	t_stackops	**ops;
//	t_flags		*flags;

	stacks = (t_stack**)malloc(sizeof(t_stack*)*2);
	ops = (t_stackops**)malloc(sizeof(t_stackops*)*3);
	stacks[0] = init_stack(stacks[0]);
	stacks[1] = init_stack(stacks[1]);
	stacks[1]->content = NULL;
	stacks[1]->size = 0;
//	flags = analyze_flags(argc, argv);

	if (!makestack(stacks[0], argc, argv))
		ft_error(1);
	if (stacks[0]->size == 1)
		ft_error(0);
	if (stacks[0]->size <= 2)
		return (smallresolve(stacks[0], NULL));
	else
	{
		ops[0] = basicsolve(copystack(stacks[0]), copystack(stacks[1]), init_so(ops[0]));
		ops[1] = mediumsolve(copystack(stacks[0]), copystack(stacks[1]), init_so(ops[1]));
		ops[2] = medsolve(copystack(stacks[0]), copystack(stacks[1]), init_so(ops[2]));
		compare(ops[0], ops[1], ops[2]);
	}
//	free_stack(stacks[0]);
//	free_stack(stacks[1]);
//	free_stackops(ops[0]);
//	free_stackops(ops[1]);
//	free_stackops(ops[2]);
	return (0);
}
