/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_pushswap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

t_stackops	*addop(t_stackops *ops, char *op)
{
	t_stackops * current;
	t_stackops * new;

	if(ops->op)
	{
		current = ops;
		while(current->next)
			current = current->next;
		if (!(new = (t_stackops*)malloc(sizeof(t_stackops))))
			return(NULL);
		new->op = op;
		new->next = NULL;
		current->next = new;
	}
	else
		ops->op = op;
	return (ops);
}
