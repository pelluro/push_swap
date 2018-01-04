/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_stack *copytabintostack(t_stack *stack, int* tab, int s)
{
	int i;

	i = 0;
	stack->content = (int*)malloc(sizeof(int)*s);
	while (i < s)
	{
		stack->content[i] = tab[i];
		i++;
	}
	stack->size = s;
	return (stack);
}

int		checktab(int *tab, int s)
{
	int i;
	int *tab2;

	i = 0;
	if (!(tab2 = (int*)malloc(sizeof(int) * s)))
		return (0);
	while (i < s)
	{
		tab2[i] = tab[i];
		i++;
	}
	if (!ft_is_sorted(tab2, s))
		ft_sort_integer_table(tab2, s);
	i = -1;
	while (i++ < s)
	{
		if (tab2[i] == tab2[i + 1])
			return (0);
	}
	return (1);
}

int		*handleministack(int* tab, int* s, char* str)
{
	int j;
	t_stack *ministack;

	ministack = NULL;
	ministack = parsestack(ministack, str);
	if (ministack)
	{
		j = -1;
		while (++j < ministack->size)
		{
			tab[*s] = ministack->content[j];
			*s = *s + 1;
		}
		return (tab);
	}
	else
		return (NULL);
}

int		*maketab(int *tab, int *s, int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	*s = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 1 && argv[i][0] == '0')
			tab[(*s)++] = 0;
		else if (ft_haschar(argv[i], ' '))
		{
			if (!(tab = handleministack(tab, s, argv[i])))
				return (0);
		}
		else
		{
			j = ft_atoi(argv[i]);
			if (j != 0)
				tab[(*s)++] = j;
			else
				return (0);
		}
		i++;
	}
	return (tab);
}

int		makestack(t_stack *stack, int argc, char **argv)
{
	int* s;
	int* tab;

	if (!(tab = (int*)malloc(sizeof(int) * 1000)))
		return (0);
  	if (!(s = (int*)malloc(sizeof(int))))
		return (0);
	tab = maketab(tab, s, argc, argv);
	if (!checktab(tab, *s))
		return (0);
	stack = copytabintostack(stack, tab,* s);
	free(tab);
	return (1);
}
