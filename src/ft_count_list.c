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
	ft_putendl("----------------\t\t----------------");
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
		ft_putendl("----------------\t\t----------------");
		if (a)
			a = a->next;
		if (b)
			b = b->next;
	}
}

int main (int ac, char **av)
{
  t_stack *stack_a;
  t_stack *stack_b;

  if (!(stack_a = (t_stack*)ft_memalloc(sizeof(t_stack))))
  return (0);
  stack_b = NULL;
  if(makestack(stack_a, ac, av))
  {
	  stack_a = stack_a->next;
	  print_list(stack_a, stack_b);
  }
  else
  {
    ft_putendl("error");
  }
  return (0);
}
