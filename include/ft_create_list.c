/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 15:09:54 by mipham            #+#    #+#             */
/*   Updated: 2018/01/10 16:04:46 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list_double.h"
/*
** la liste est vide pour le moment, donc racine pointe sur elle meme
*/
t_list create_list_double(void)
{
	t_list *racine;

	if (!(racine = ft_memalloc(sizeof(t_list))))
		return (NULL);
	racine->prec = racine;
	racine->next = racine;
	return (racine);
}
