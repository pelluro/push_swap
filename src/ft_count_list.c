#include "../include/pushswap.h"

size_t		ft_count_list(t_stack *stack)
{
  size_t	i;
  t_stack	*current;

  i = 0;
  current = stack;
  while (current)
  {
    current = current->next;
    i++;
  }
  return (i);
}
size_t		ft_count_ops(t_stackops **stack)
{
  size_t	i;
  t_stackops	*current;

  i = 0;
  current = *stack;
  while (current)
  {
    current = current->next;
    i++;
  }
  return (i);
}

void		ft_del_stack(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current)
	{
		current = current->next;
		free (current);
	}
	*stack = NULL;
}

void		ft_del_stackops(t_stackops **ops)
{
	t_stackops	*current;

	current = *ops;
	while (current)
	{
		free(current->op);
		current = current->next;
		free (current);
	}
	*ops = NULL;
}

void		print_list(t_stack *a, t_stack *b)
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

void		print_stackops(t_stackops *ops)
{
	t_stackops	*current;

	current = ops;
	while (current)
	{
		ft_putstr(current->op);
		ft_putstr("\n");
		current = current->next;
	}
}
