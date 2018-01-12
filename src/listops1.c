/*
** vider la list_double
*/
#include "libft/libft.h"

void erase_elem_list(t_list *list)
{
	t_list *elem;
	t_list *nextelem;

	elem = list->next;
	while (elem != list)
	{
		nextelem = elem->next; /*enregistre le pointeur sur l.elem suiv avant de supprimer */
		free(elem);
		elem = nextelem;
	}
}

void erase_list(t_list **list)
{
	erase_elem_list(*list);
	free(*list);
	*list = NULL;
}

void erase_elem (t_list *elem)
{
  elem->prec->next = elem->next;
  elem->next->prec = elem->prec;
  free(elem);
}
