//
// Created by pelluro on 14/01/18.
//
#include "../include/pushswap.h"

void	print_list(t_list *a, t_list *b)
{
	ft_putendl("     PILE A\t\t\t      PILE B");
	ft_putendl("----------------\t\t----------------");
	while (a || b)
	{
		ft_putstr("|\t");
		if (a)
			ft_putnbr(a->content);
		ft_putstr("\t|");
		ft_putstr("\t\t|\t ");
		if (b)
			ft_putnbr(b->content);
		ft_putstr("\t|");
		ft_putn();
		ft_putendl("----------------\t\t----------------");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}
