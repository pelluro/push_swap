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
	t_stackops* current;

	current = ops;
	while (current)
	{
		ft_putendl(current->content);
		current = current->next;
	}
}

t_stackops *init_so(t_stackops *ops)
{
	if (!(ops = (t_stackops*)malloc(sizeof(t_stackops))))
		return(NULL);
	ops->content = NULL;
	ops->next = NULL;
	return (ops);
}

t_stack	*init_stack(t_stack *s)
{
	if (!(s = (t_stack*)malloc(sizeof(t_stack))))
		return(NULL);
	s->content = 0;
	s->isroot = 1;
	return (s);
}


int ft_nb_list(t_stackops *elem)
{
	int i;
	t_stackops *it;

	i = 0;
	if(!elem)
		return(-1);
	it = elem->next;
	while (it != elem)
	{
		it = it->next;
		i++;
	}
	return (i);
}

void compare(t_stackops *ops1, t_stackops *ops2, t_stackops *ops3)
{
	int ops1size;
	int ops2size;
	int ops3size;
	int minValue;
	int opsselected;

	ops1size = ft_nb_list(ops1);
	ops2size = ft_nb_list(ops2);
	ops3size = ft_nb_list(ops3);
	minValue = -1;

	if (!ops1 && !ops2 && !ops3)
		ft_error(0);
	else
	{
		if(ops1size >= 0 && ops1size < minValue)
		{
				minValue = ops1size;
				opsselected = 1;
		}
		if(ops2size >= 0 && ops2size < minValue)
		{
				minValue = ops2size;
				opsselected = 2;
		}
		if(ops3size >= 0 && ops3size < minValue)
		{
					minValue = ops3size;
					opsselected = 3;
		}
		if(opsselected == 1)
			printstackops(ops1);
		if(opsselected == 2)
			printstackops(ops2);
		if(opsselected == 3)
			printstackops(ops3);
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

	if (!makestack(stacks[0], argc, argv))
		ft_error(1);
	if (stacks[0]->next && stacks[0]->next->next->isroot)
		ft_error(0);
	if ((stacks[0]->next && stacks[0]->next->next
		&& !stacks[0]->next->next->isroot
		&& stacks[0]->next->next->next->isroot))
		return (smallresolve(stacks[0], NULL));
	else
	{
		ops[0] = basicsolve(copystack(stacks[0]), copystack(stacks[1]), init_so(ops[0]));
		printf("basic OK\n");
		ops[1] = mediumsolve(copystack(stacks[0]), copystack(stacks[1]), init_so(ops[1]));
		printf("medium OK\n");
		ops[2] = medsolve(copystack(stacks[0]), copystack(stacks[1]), init_so(ops[2]));
		printf("med OK\n");
		compare(ops[0], ops[1], ops[2]);
	}
//	free_stack(stacks[0]);
//	free_stack(stacks[1]);
//	free_stackops(ops[0]);
//	free_stackops(ops[1]);
//	free_stackops(ops[2]);
	return (0);
}
