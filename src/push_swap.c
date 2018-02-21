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
  int f;
  // t_stackops* ops2;
  f = 0;
  if (!(stack_a = (t_stack*)ft_memalloc(sizeof(t_stack))))
  return (0);
  stack_b = NULL;
  ops = NULL;
  if(makestack(stack_a, ac, av, &f))
    {
	  stack_a = stack_a->next;
      mediumsolve(stack_a, stack_b, &ops);
      clean_ops(&ops);
      print_stackops(ops);
    }
  else
  {
    ft_putendl("error");
  }
	if (stack_a)
		free(stack_a);
	if (stack_b)
		free(stack_b);
	if (ops)
		free(ops);
  return (0);
}
