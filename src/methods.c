/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:56 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int issorted(t_stack* stack)
{
	int i = 1;
	if(stack->size == 0)
		return(0);
	if(stack->size == 1)
		return(1);
	while(i < stack->size)
	{
		if(stack->content[i-1] >= stack->content[i])
			return(0);
		i++;
	}
	return(1);
}

t_stack* add_top(t_stack* stack, int c)
{
	int i = 0;
	int*  s;
	s = (int*)malloc(sizeof(int)*(stack->size));
	while(i < stack->size)
	{
		s[i] = stack->content[i];
		i++;
	}
	stack->content = (int*)malloc(sizeof(int)*((stack->size) + 1));
	stack->content[0] = c;
	if(stack->size > 0)
	{
		i = 0;
		while(i < stack->size)
		{
			stack->content[1 + i] = s[i];
			i++;
		}
	}
	stack->size = (stack->size) + 1;
	free(s);
	return (stack);
}

t_stack* remove_elem(t_stack* stack, int index)
{
	int i = 0;
	int j = 0;
	int*  s;
	s = (int*)malloc(sizeof(int)*(stack->size));
	while(i < stack->size)
	{
		s[i] = stack->content[i];
		i++;
	}
	stack->content = (int*)malloc(sizeof(int)*((stack->size) - 1));
	i = 0;
	while(i < stack->size)
	{
		if(i != index)
		{
			stack->content[j] = s[i];
			j++;
		}
		i++;
	}
	stack->size = (stack->size) - 1;
	free(s);
	return (stack);
}

void swap(t_stack* stack)
{
	int c;
	if(stack && stack->content && (stack->size) >= 2)
	{
		c = stack->content[0];
		stack->content[0] = stack->content[1];
		stack->content[1] = c;
	}
}
void swap_a(t_stack* stack_a, t_stack* stack_b)
{
	swap(stack_a);
	(void)stack_b;
}

void swap_b(t_stack* stack_a, t_stack* stack_b)
{
	swap(stack_b);
	(void)stack_a;
}

void swap_both(t_stack* stack_a, t_stack* stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

void push(t_stack* stackfrom, t_stack* stackto)
{
	if(stackfrom && stackfrom->size >= 1)
	{
		stackto = add_top(stackto, stackfrom->content[0]);
		stackfrom = remove_elem(stackfrom, 0);
	}
}

void push_a(t_stack* stack_a, t_stack* stack_b)
{
	push(stack_b, stack_a);
}

void push_b(t_stack* stack_a, t_stack* stack_b)
{
	push(stack_a, stack_b);
}

void rotate(t_stack* stack)
{
	int i;
	int c;

	if(stack && stack->size > 1)
	{
		i = 1;
		c = stack->content[0];
		while(i <= stack->size - 1)
		{
			stack->content[i-1] = stack->content[i];
			i++;
		}
		stack->content[stack->size - 1] = c;
	}
}

void rotate_a(t_stack* stack_a, t_stack* stack_b)
{
	rotate(stack_a);
	(void)stack_b;
}

void rotate_b(t_stack* stack_a, t_stack* stack_b)
{
	rotate(stack_b);
	(void)stack_a;
}

void rotate_both(t_stack* stack_a, t_stack* stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void reverse_rotate(t_stack* stack)
{
	int i;
	char c;

	if(stack && stack->size > 1)
	{
		i = stack->size - 2;
		c = stack->content[stack->size - 1];
		while(i >= 0)
		{
			stack->content[i+1] = stack->content[i];
			i--;
		}
		stack->content[0] = c;
	}
}

void reverse_rotate_a(t_stack* stack_a, t_stack* stack_b)
{
	reverse_rotate(stack_a);
	(void)stack_b;
}

void reverse_rotate_b(t_stack* stack_a, t_stack* stack_b)
{
	reverse_rotate(stack_b);
	(void)stack_a;
}

void reverse_rotate_both(t_stack* stack_a, t_stack* stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}

stack_op define_hashmap(char * op_name)
{
	if(ft_strlen(op_name) < 1 || ft_strlen(op_name)> 3)
		return(NULL);
	if(!ft_strcmp(op_name,"sa"))
		return (&swap_a);
	if(!ft_strcmp(op_name,"sb"))
		return (&swap_b);
	if(!ft_strcmp(op_name,"ss"))
		return (&swap_both);
	if(!ft_strcmp(op_name,"pa"))
		return (&push_a);
	if(!ft_strcmp(op_name,"pb"))
		return (&push_b);
	if(!ft_strcmp(op_name,"ra"))
		return (&rotate_a);
	if(!ft_strcmp(op_name,"rb"))
		return (&rotate_b);
	if(!ft_strcmp(op_name,"rr"))
		return (&rotate_both);
	if(!ft_strcmp(op_name,"rra"))
		return (&reverse_rotate_a);
	if(!ft_strcmp(op_name,"rrb"))
		return (&reverse_rotate_b);
	if(!ft_strcmp(op_name,"rrr"))
		return (&reverse_rotate_both);
	return (NULL);
}

int		ft_haschar(const char *s, int c)
{
	char	*src;
	int		i;

	src = (char *)s;
	i = 0;
	while (src[i] && src[i] != (char)c)
		i++;
	if (src[i] == (char)c)
		return (1);
	return (0);

}

t_stack* parsestack(t_stack* stack, char * str)
{
	int i;
	int j;
	char** tabNb;

	stack = (t_stack*)malloc(sizeof(t_stack));
	stack->content = (int*)malloc(sizeof(int)*1000);
	tabNb = ft_split_whitespaces(str);

	i = 0;
	while (tabNb[i])
	{
		if (ft_strlen(tabNb[i]) == 1 && tabNb[i][0] == '0')
			stack->content[i] = 0;
		else
		{
			j = ft_atoi(tabNb[i]);
			if (j != 0)
				stack->content[i] = j;
			else
				return(0);
		}
		i++;
	}
	j = 0;
	stack->size = i;
	return stack;
}

t_stack* copytabintostack(t_stack* stack, int* tab, int s)
{
	int i;

	i = 0;
	stack->content = (int*)malloc(sizeof(int)*s);
	while(i < s)
	{
		stack->content[i] = tab[i];
		i++;
	}
	stack->size = s;
	return(stack);
}

int checktab(int* tab, int s)
{
	int i;
	int *tab2;

	i = 0;
	if(!(tab2 = (int*)malloc(sizeof(int) *s)))
		return (0);
	while (i < s)
	{
		tab2[i] = tab[i];
		i++;
	}
	if (!ft_is_sorted(tab2, s))
		ft_sort_integer_table(tab2, s);
	i = 0;
	while (i < s)
	{
		if (tab2[i] == tab2[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int makestack(t_stack *stack, int argc, char **argv)
{
	int i;
	int j;
	int s;
	int* tab;
	t_stack* ministack;

	ministack = NULL;
	tab = (int*)malloc(sizeof(int)*1000);
	i = 1;
	s = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 1 && argv[i][0] == '0')
		{
			tab[s] = 0;
			s++;
		}
		else if(ft_haschar(argv[i],' '))
		{
			ministack = parsestack(ministack, argv[i]);
			if(ministack)
			{
				j = 0;
				while(j < ministack->size)
				{
					tab[s] = ministack->content[j];
					s++;
					j++;
				}
			}
			else
				return(0);
		}
		else
		{
			j = ft_atoi(argv[i]);
			if (j != 0)
			{
				tab[s] = j;
				s++;
			}
			else
				return(0);
		}
		i++;
	}
	if(!checktab(tab,s))
		return(0);
	stack = copytabintostack(stack,tab,s);
	free(tab);
	return (1);
}

void printtab(t_stack* stack)
{
	int i;

	i = 0;
	while (i < stack->size)
	{
		printf("content=%d\n",stack->content[i]);
		i++;
	}
}
