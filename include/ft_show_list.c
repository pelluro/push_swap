
#include "list_double.h"

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
