/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:46 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:49 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"


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
