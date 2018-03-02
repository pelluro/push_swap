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
//void ft_merge_pivot(t_stackops **ops, t_stackops **ops1, t_stackops **ops2)
//{
//	t_stackops	*c_a;
//	t_stackops	*c_b;
//	t_stackops	*c_final;
//
//	c_a = *ops1;
//	c_b = *ops2;
//	c_final = *ops;
//	while (c_a && c_a->op)
//	{
//		if (c_b && c_b->op && !ft_strcmp(c_a->op, "sa") && !ft_strcmp(c_b->op, "sb"))
//		{
//			c_final = addop(c_final, "ss");
//			c_b = c_b->next;
//		}
//		else if (c_b && c_b->op && !ft_strcmp(c_a->op, "ra") && !ft_strcmp(c_b->op, "rb"))
//			{
//				c_final = addop(c_final, "rr");
//				c_b = c_b->next;
//			}
//		else if (c_b && c_b->op && !ft_strcmp(c_a->op, "rra") && !ft_strcmp(c_b->op, "rrb"))
//		{
//			c_final = addop(c_final, "rrr");
//			c_b = c_b->next;
//		}
//		else
//			c_final = addop(c_final, c_a->op);
//		c_a = c_a->next;
//	}
//	while (c_b &&  c_b->op)
//	{
//		c_final = addop(c_final, c_b->op);
//		c_b = c_b->next;
//	}
//}

//void ft_merge_main(t_stackops **ops, t_stackops **ops_selec)
//{
//	t_stackops *cur_ops;
//	t_stackops *cur_ops_selec;
//
//	cur_ops = *ops;
//	cur_ops_selec = *ops_selec;
//	while (cur_ops->next)
//		cur_ops = cur_ops->next;
//	while (cur_ops_selec)
//	{
//		cur_ops = addop(cur_ops,cur_ops_selec->op);
//		cur_ops_selec = cur_ops_selec->next;
//	}
//}
//
//void ft_merge_ops(t_stackops **ops, t_stackops **ops1, t_stackops **ops2)
//{
//	t_stackops *ops_f1;
//	t_stackops *ops_f2;
//
//	if (!(ops_f1 = (t_stackops*)ft_memalloc(sizeof(t_stackops))))
//		return;
//	if (!(ops_f2 = (t_stackops*)ft_memalloc(sizeof(t_stackops))))
//		return;
//	ft_merge_pivot(&ops_f1, ops1, ops2);
//	ft_merge_pivot(&ops_f2, ops2, ops1);
//	if (ft_count_ops(&ops_f1) > ft_count_ops(&ops_f2))
//		ft_merge_main(ops, &ops_f2);
//	else
//		ft_merge_main (ops, &ops_f1);
//}

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
		if (medians)
		{
			callback(&s_a, &s_b, ops, medians->value);
			medians = medians->next;
			medsolve_a(&s_a, &s_b, ops);
		}
		f = 1;
	}
	medsolve_b(&s_a, &s_b, ops);
	print_list(s_a, s_b);
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
