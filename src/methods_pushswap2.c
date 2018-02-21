/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods_pushswap2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

//void	clean_push(t_stackops **ops, t_stackops *current, t_stackops *previous)
//{
//	if ((!ft_strcmp(current->op, "pa") && !ft_strcmp(current->next->op, "pb"))
//		|| (!ft_strcmp(current->op, "pb") && !ft_strcmp(current->next->op, "pa")))
//	{
//		if(!previous)
//		{
//			*ops = current->next->next;
//			current = current->next->next;
//		}
//		else
//		{
//			previous->next = current->next->next;
//			current = current->next->next;
//		}
//	}
//}

void	clean_ops(t_stackops **ops)
{
  t_stackops *current;
  t_stackops *previous;

  previous = NULL;
  current = *ops;
  while (current && current->next)
  {
    if ((!ft_strcmp(current->op, "pa") && !ft_strcmp(current->next->op, "pb"))
      || (!ft_strcmp(current->op, "pb") && !ft_strcmp(current->next->op, "pa")))
      {
        if(!previous)
        {
          *ops = current->next->next;
          current = current->next->next;
           continue;
        }
        else
        {
          previous->next = current->next->next;
          current = current->next->next;
          continue;
        }
      }
      if ((!ft_strcmp(current->op, "ra") && !ft_strcmp(current->next->op, "rb"))
        || (!ft_strcmp(current->op, "rb") && !ft_strcmp(current->next->op, "ra")))
        {
          if(!previous)
          {
            *ops = current->next;
            current->next->op = "rr";
            current = current->next->next;
             continue;
          }
          else
          {
            previous->next = current->next;
            current->next->op = "rr";
            current = current->next->next;
            continue;
          }
        }
      if ((!ft_strcmp(current->op, "rra") && !ft_strcmp(current->next->op, "rrb"))
        || (!ft_strcmp(current->op, "rrb") && !ft_strcmp(current->next->op, "rra")))
          {
            if(!previous)
            {
              *ops = current->next;
              current->next->op = "rrr";
              current = current->next->next;
               continue;
            }
            else
            {
              previous->next = current->next;
              current->next->op = "rrr";
              current = current->next->next;
              continue;
            }
          }
      previous = current;
      current = current->next;
  }
}
