
#include "libft/libft.h"

void ft_show_list(t_list *elem)
{
	t_list *it;
	t_list *rit;

	it = elem->next;
	rit = elem->prec;
	while (it != elem)
	{
		printf("val a l'endroit=%d\n", it->val);
		it = it->next;
	}
	while (rit != elem)
	{
		printf("val a l'envers%s\n", rit->val);
		rit = rit->prec;
	}
}

t_list create_list_double(void)
{
	t_list *racine;

	if (!(racine = ft_memalloc(sizeof(t_list))))
		return (NULL);
	racine->prec = racine;
	racine->next = racine;
	return (racine);
}

void add_after_elem(t_list *elem, int val)
{
  t_list *newelem;

  newelem =(t_list*)ft_memalloc(sizeof(t_list));
  if (newelem)
  {
    newelem->val = val;
    newelem->prec = elem->prec;
    newelem->next = elem;
    elem->prec->next = newelem;
    elem->prec = newelem;
  }
}

void add_before_elem(t_list *elem, int val)
{
  t_list *newelem;

  newelem = (t_list*)ft_memalloc(sizeof(t_list));
  if (newelem)
  {
    newelem->val = val;
    newelem->prec = elem;
    newelem->next = elem->next;
    elem->next->prec = newelem;
    elem->next = newelem;
  }
}