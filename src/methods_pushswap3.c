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

void		splitstacks(t_stack **s_a, t_stack **s_b, t_stackops **ops, int medvalue)
{
	t_stack		*current;
	int			i;
	int			size;

	i =  0;
	size = ft_count_list(*s_a);
	current = (*s_a);
	while (i < size + 1)
	{
		if (current->value == medvalue)
		{
			*ops = addop(*ops, "ra", ft_count_list(*s_a), ft_count_list(*s_b));
			rotate_a(s_a, s_b);
		}
		else if (current->value <= medvalue)
		{
			*ops = addop(*ops, "pb", ft_count_list(*s_a), ft_count_list(*s_b));
			push_b(s_a, s_b);
		}
		else
		{
			*ops = addop(*ops, "ra", ft_count_list(*s_a), ft_count_list(*s_b));
			rotate_a(s_a, s_b);
		}
		current = (*s_a);
		i++;
	}
}

void	medsolve_a(t_stack **stack, t_stack **otherstack, t_stackops **ops)
{
	  t_stack * current;
	int	max_val;
	int	max_id;
	int	min_val;
	int min_id;


//	print_list(*stack, *otherstack);
	findmax(*stack, &max_val, &max_id);
	findmin(*stack, &min_val, &min_id);
	while (!issorted(*stack))
	{
		current = *stack;
		while(current->next)
			current = current->next;
		if ((*stack)->value == min_val && (*stack)->next->value > current->value)
		{
			*ops = addop(*ops, "rra", ft_count_list(*stack), ft_count_list(*otherstack));
			reverse_rotate_a(stack, otherstack);
			*ops = addop(*ops, "sa", ft_count_list(*stack), ft_count_list(*otherstack));
			swap_a(stack, otherstack);
		}
		else if ((*stack)->value > (*stack)->next->value && (*stack)->value != max_val)
		{
			*ops = addop(*ops, "sa", ft_count_list(*stack), ft_count_list(*otherstack));
			swap_a(stack, otherstack);
		}
		else
		{
			*ops = addop(*ops, "ra", ft_count_list(*stack), ft_count_list(*otherstack));
			rotate_a(stack, otherstack);
		}
	}
}

 void	medsolve_b(t_stack **otherstack, t_stack **stack, t_stackops **ops)
 {
	 int	maxindex;
	 int	maxvalue;
	 int	i;
	 int	size;

	i = 0;
 	while (*stack)
 	{
		size = ft_count_list(*stack);
		findmax(*stack, &maxvalue, &maxindex);
		if (maxindex == 0)
		{
			*ops = addop(*ops, "pa", ft_count_list(*otherstack), ft_count_list(*stack));
			push_a(otherstack, stack);
		}
		else if (maxindex < size / 2)
		{
			i = maxindex;
			while (i > 0)
			{
				*ops = addop(*ops, "rb", ft_count_list(*otherstack), ft_count_list(*stack));
				rotate_b(otherstack, stack);
				i--;
			}
			*ops = addop(*ops, "pa", ft_count_list(*otherstack), ft_count_list(*stack));
			push_a(otherstack, stack);
		}
		else
		{
			i = maxindex;
			while (i < size)
			{
				*ops = addop(*ops, "rrb", ft_count_list(*otherstack), ft_count_list(*stack));
				reverse_rotate_b(otherstack, stack);
				i++;
			}
			*ops = addop(*ops, "pa", ft_count_list(*otherstack), ft_count_list(*stack));
			push_a(otherstack, stack);
 		}
 	}
 }

void		medsolve(t_stack *s_a, t_stack *s_b, t_stackops **ops)
{
	int	medvalue;
	int	medindex;
	t_stack *medians;
	t_stack *currentmed;
	int f;

	f = 0;
	medians = NULL;
	while (ft_count_list(s_a) > 3)
	{
		findmed(s_a, &medvalue, &medindex);
		splitstacks(&s_a, &s_b, ops, medvalue);
		currentmed = create_node(NULL, medvalue);
		if(medians)
			currentmed->next = medians;
		medians = currentmed;
	}
	medians = medians->next;
	while (medians || !f)
	{
		medsolve_a(&s_a, &s_b, ops);
		medsolve_b(&s_a, &s_b, ops);
		if (medians)
		{
			callback(&s_a, &s_b, ops, medians->value);
			medians = medians->next;
//			medsolve_a(&s_a, &s_b, ops);
		}
		f = 1;
	}
//	print_list(s_a, s_b);
}


void	callback(t_stack **s_a, t_stack **s_b, t_stackops **ops, int med_val)
{
	int i;
	int size;


	size = ft_count_list(*s_b);
	i = 0;
	while (i < size)
	{
		if((*s_b)->value > med_val)
		{
			*ops = addop(*ops, "pa", ft_count_list(*s_a), ft_count_list(*s_b));
			push_a(s_a, s_b);
		}
		else
		{
			*ops = addop(*ops, "rb", ft_count_list(*s_a), ft_count_list(*s_b));
			rotate_b(s_a, s_b);
		}
		i++;
	}
}
