#include "../include/pushswap.h"

size_t  ft_count_list(t_stack *stack)
{
  size_t i;
  t_stack *current;

  i = 0;
  current = stack;
  while (current)
  {
    current = current->next;
    i++;
  }
  return (i);
}

void	print_list(t_stack *a, t_stack *b)
{
	ft_putendl("     PILE A\t\t\t      PILE B");
	ft_putendl("------------------\t\t------------------");
	while (a || b)
	{
		ft_putstr("|\t");
		if (a)
			ft_putnbr(a->value);
		ft_putstr("\t|");
		ft_putstr("\t\t|\t ");
		if (b)
			ft_putnbr(b->value);
		ft_putstr("\t|");
		ft_putendl(" ");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
  ft_putendl("------------------\t\t------------------");
}
