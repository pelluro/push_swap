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
  t_stackops* ops;
  t_stackops* ops2;

  if (!(stack_a = (t_stack*)ft_memalloc(sizeof(t_stack))))
  return (0);
  stack_b = NULL;
  ops = NULL;
  ops2 = NULL;
if(makestack(stack_a, ac, av))
  {
	  stack_a = stack_a->next;
	  print_list(stack_a, stack_b);
	  if(ft_count_list(stack_a) < 10)
     {
		     mediumsolve(stack_a, stack_b, &ops);
	     print_stackops(ops);
	 }
	  else
	  {
		  basicsolve(&stack_a, &stack_b, &ops2);
	
		  print_stackops(ops2);
	  }
  }
  else
  {
    ft_putendl("error");
  }
  return (0);
}
