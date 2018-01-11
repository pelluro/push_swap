
#include "list_double.h"

void erase_elem (t_list *elem)
{
  elem->prec->next = elem->next;
  elem->next->prec = elem->prec;
  free(elem);
}
