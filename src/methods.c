/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void			ft_error(int error)
{
	if (error)
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
	exit(0);
}

static int		ft_check_doublon(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == tab[i + 1])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int				checktab(t_stack *stack)
{
	size_t	i;
	size_t	size;
	t_stack	*current;
	int		*tab2;

	i = 0;
	current = stack;
	size = ft_count_list(stack);
	if (!(tab2 = (int*)ft_memalloc(sizeof(int) * size)))
		return (0);
	while (i < size)
	{
		tab2[i++] = current->value;
		current = current->next;
	}
	if (!ft_is_sorted(tab2, size))
		ft_sort_integer_table(tab2, size);
	if (!ft_check_doublon(tab2, size))
		return (0);
	free(tab2);
	return (1);
}


int				handleministack(t_stack *current, t_stack *stack, char* str)
{
		int		i;
		int		j;
		char	**tabnb;

		if (!(tabnb = ft_split_whitespaces(str)))
			return (0);
		i = 0;
		while (tabnb[i])
		{
			if (ft_strlen(tabnb[i]) == 1 && tabnb[i][0] == '0')
				current = create_node(current ? current : stack, 0);
			else
			{
				j = ft_atoi(tabnb[i]);
				if (j != 0)
				current = create_node(current ? current : stack, j);
				else
					return (0);
			}
			i++;
		}
		return (1);
}

int				makestack(t_stack *stack, int argc, char **argv, int *f)
{
	int		i;
	int		j;
	t_stack *current;

	i = 1;
	current = NULL;
  while (i < argc)
	{
		if (ft_strlen(argv[i]) == 1 && argv[i][0] == '0')
			current = create_node(current ? current : stack, 0);
		else if (ft_haschar(argv[i], ' '))
		{
			if (!(handleministack(current, stack, argv[i])))
				return (0);
		}
		else
		{
			j = ft_atoi(argv[i]);
			if (j != 0)
				current = create_node(current ? current : stack, j);
			else
			{
				if (!ft_strcmp(argv[i], "-v"))
					*f = 1;
				else
					return (0);
			}
		}
		i++;
	}
	stack = stack->next;
	if (!checktab(stack))
		return (0);
	return (1);
}
