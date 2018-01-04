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

stack_op	define_hashmap(char *op_name)
{
	if (ft_strlen(op_name) < 1 || ft_strlen(op_name) > 3)
		return (NULL);
	if (!ft_strcmp(op_name, "sa"))
		return (&swap_a);
	if (!ft_strcmp(op_name, "sb"))
		return (&swap_b);
	if (!ft_strcmp(op_name, "ss"))
		return (&swap_both);
	if (!ft_strcmp(op_name, "pa"))
		return (&push_a);
	if (!ft_strcmp(op_name, "pb"))
		return (&push_b);
	if (!ft_strcmp(op_name, "ra"))
		return (&rotate_a);
	if (!ft_strcmp(op_name, "rb"))
		return (&rotate_b);
	if (!ft_strcmp(op_name, "rr"))
		return (&rotate_both);
	if (!ft_strcmp(op_name, "rra"))
		return (&reverse_rotate_a);
	if (!ft_strcmp(op_name, "rrb"))
		return (&reverse_rotate_b);
	if (!ft_strcmp(op_name, "rrr"))
		return (&reverse_rotate_both);
	return (NULL);
}

int			ft_haschar(const char *s, int c)
{
	char	*src;
	int		i;

	src = (char *)s;
	i = 0;
	while (src[i] && src[i] != (char)c)
		i++;
	if (src[i] == (char)c)
		return (1);
	return (0);
}

t_stack		*parsestack(t_stack *stack, char *str)
{
	int		i;
	int		j;
	char	**tabnb;

	if (!(stack = (t_stack *) malloc(sizeof(t_stack))) ||
			!(stack->content = (int *) malloc(sizeof(int) * 1000)) ||
			!(tabnb = ft_split_whitespaces(str)))
		return (0);
	i = 0;
	while (tabnb[i])
	{
		if (ft_strlen(tabnb[i]) == 1 && tabnb[i][0] == '0')
			stack->content[i] = 0;
		else
		{
			j = ft_atoi(tabnb[i]);
			if (j != 0)
				stack->content[i] = j;
			else
				return (0);
		}
		i++;
	}
	j = 0;
	stack->size = i;
	return (stack);
}
