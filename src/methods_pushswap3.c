/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos1.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void		splitstacks(t_stack **s_a, t_stack **s_b, t_stackops **ops, int medval)
{
	t_stack		*current;
	int			i;
	int			size;

	i =  -1;
	size = count_list(*s_a);
	current = (*s_a);
	while (++i < size + 1)
	{
		if (current->val == medval)
		{
			*ops = addop(*ops, "ra", count_list(*s_a), count_list(*s_b));
			rotate_a(s_a, s_b);
		}
		else if (current->val <= medval)
		{
			*ops = addop(*ops, "pb", count_list(*s_a), count_list(*s_b));
			push_b(s_a, s_b);
		}
		else
		{
			*ops = addop(*ops, "ra", count_list(*s_a), count_list(*s_b));
			rotate_a(s_a, s_b);
		}
		current = (*s_a);
	}
}

void	medsolve_a(t_stack **stack, t_stack **o_stack, t_stackops **ops)
{
	  t_stack * current;
	int	maxval;
	int	max_id;
	int	min_val;
	int min_id;


//	print_list(*stack, *o_stack);
	findmax(*stack, &maxval, &max_id);
	findmin(*stack, &min_val, &min_id);
	while (!issorted(*stack))
	{
		current = *stack;
		while(current->next)
			current = current->next;
		if ((*stack)->val == min_val && (*stack)->next->val > current->val)
		{
			*ops = addop(*ops, "rra", count_list(*stack), count_list(*o_stack));
			reverse_rotate_a(stack, o_stack);
			*ops = addop(*ops, "sa", count_list(*stack), count_list(*o_stack));
			swap_a(stack, o_stack);
		}
		else if ((*stack)->val > (*stack)->next->val && (*stack)->val != maxval)
		{
			*ops = addop(*ops, "sa", count_list(*stack), count_list(*o_stack));
			swap_a(stack, o_stack);
		}
		else
		{
			*ops = addop(*ops, "ra", count_list(*stack), count_list(*o_stack));
			rotate_a(stack, o_stack);
		}
	}
}

 void	medsolve_b(t_stack **o_stack, t_stack **stack, t_stackops **ops)
 {
	 int	maxindex;
	 int	maxval;
	 int	i;
	 int	size;

	i = 0;
 	while (*stack)
 	{
		size = count_list(*stack);
		findmax(*stack, &maxval, &maxindex);
		if (maxindex == 0)
		{
			*ops = addop(*ops, "pa", count_list(*o_stack), count_list(*stack));
			push_a(o_stack, stack);
		}
		else if (maxindex < size / 2)
		{
			i = maxindex;
			while (i > 0)
			{
				*ops = addop(*ops, "rb", count_list(*o_stack), count_list(*stack));
				rotate_b(o_stack, stack);
				i--;
			}
			*ops = addop(*ops, "pa", count_list(*o_stack), count_list(*stack));
			push_a(o_stack, stack);
		}
		else
		{
			i = maxindex;
			while (i < size)
			{
				*ops = addop(*ops, "rrb", count_list(*o_stack), count_list(*stack));
				reverse_rotate_b(o_stack, stack);
				i++;
			}
			*ops = addop(*ops, "pa", count_list(*o_stack), count_list(*stack));
			push_a(o_stack, stack);
 		}
 	}
 }

void		medsolve(t_stack *s_a, t_stack *s_b, t_stackops **ops)
{
	int	medval;
	int	medindex;
	t_stack *medians;
	t_stack *currentmed;
	int f;

	f = 0;
	medians = NULL;

//	 print_list(s_a, s_b);
	while (count_list(s_a) > 3)
	{
		findmed(s_a, &medval, &medindex);
		splitstacks(&s_a, &s_b, ops, medval);
		currentmed = create_node(NULL, medval);
		if (medians)
			currentmed->next = medians;
		medians = currentmed;
//		 print_list(s_a, s_b);
	}
	medians = medians->next;
	while (medians || !f)
	{
		medsolve_a(&s_a, &s_b, ops);
		medsolve_b(&s_a, &s_b, ops);
		if (medians)
		{
			callback(&s_a, &s_b, ops, medians->val);
			medians = medians->next;
//			medsolve_a(&s_a, &s_b, ops);
		}
		f = 1;
	}
//	 print_list(s_a, s_b);
}


void	callback(t_stack **s_a, t_stack **s_b, t_stackops **ops, int med_val)
{
	int i;
	int size;


	size = count_list(*s_b);
	i = 0;
	while (i < size)
	{
		if((*s_b)->val > med_val)
		{
			*ops = addop(*ops, "pa", count_list(*s_a), count_list(*s_b));
			push_a(s_a, s_b);
		}
		else
		{
			*ops = addop(*ops, "rb", count_list(*s_a), count_list(*s_b));
			rotate_b(s_a, s_b);
		}
		i++;
	}
}
