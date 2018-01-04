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

void		printstackops(t_stackops *ops)
{
	int i;

	i = 0;
	while (i < ops->size)
	{
		ft_putendl(ops->content[i]);
		i++;
	}
}

t_stackops	*init_so(t_stackops *ops)
{
	if (!(ops = (t_stackops*)malloc(sizeof(t_stackops))))
		return (NULL);
	if (!(ops->content = (char**)malloc(sizeof(char*) * 10000000)))
		return (NULL);
	ops->size = 0;
	return (ops);
}

t_stack		*init_stack(t_stack *s)
{
	if (!(s = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	return (s);
}

void		compare(t_stackops *ops1, t_stackops *ops2, t_stackops *ops3)
{
	if (!ops1 && !ops2 && !ops3)
	{
		printf("3 ops existe pas\n");
		return ;
	}

	else if (ops1 && ops2 && ops3)
	{
		printf("Acompare\n");
		if (ops1->size > ops2->size && ops3->size > ops2->size)
			printstackops(ops2);
		else if (ops3->size > ops1->size)
			printstackops(ops1);
		else
			printstackops(ops3);
	}
	if (!ops1)
		ops3->size > ops2->size ? printstackops(ops2) :printstackops(ops3);
	if (!ops2)
		ops3->size > ops1->size ? printstackops(ops1) : printstackops(ops3);
	if (!ops3)
		ops1->size > ops2->size ? printstackops(ops2) : printstackops(ops1);
}

int			main(int argc, char** argv)
{
	t_stack		*s_a;
	t_stack		*s_b;
	t_stackops	*ops1;
	t_stackops	*ops2;
	t_stackops	*ops3;
	
	s_a = NULL;
	s_b = NULL;
	ops1 = NULL;
	ops2 = NULL;
	ops3 = NULL;
	s_a = init_stack(s_a);
	s_b = init_stack(s_b);
	s_b->content = NULL;
	s_b->size = 0;
	if (!makestack(s_a, argc, argv))
	{
		ft_putendl("Error");
		return (-1);
	}
	if (s_a->size <= 2)
			return (smallresolve(s_a, NULL));
	else
	{
		ops1 = basicsolve(copystack(s_a), copystack(s_b), init_so(ops1));
		printf("A\n");
		ops2 = mediumsolve(copystack(s_a), copystack(s_b), init_so(ops2));
		printf("B\n");
		ops3 = medsolve(copystack(s_a), copystack(s_b), init_so(ops3));
		printf("C\n");
		compare(ops1, ops2, ops3);
	}
	return (0);
}
