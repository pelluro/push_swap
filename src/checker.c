/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:46 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:49 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int		main(int argc, char **argv)
{
	t_stack	*s_a;
	t_stack	*s_b;
	int		f;

	f = 0;
	if (argc == 1)
		ft_error(0);
	if (!(s_a = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return (0);
	s_b = NULL;
	if (!makestack(s_a, argc, argv, &f))
		ft_error (1);
	s_a = s_a->next;
	return (read_cmds(s_a, s_b, f));
}