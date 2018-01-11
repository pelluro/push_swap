
#include "list_double.h"

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
