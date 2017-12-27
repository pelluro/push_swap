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
			stack->content[1+i] = s[i];
			i++;
		}
	}
	stack->size = (stack->size)+1;
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
	stack->size = (stack->size)-1;
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
void swap_a(t_stack* stackA, t_stack* stackB)
{
	swap(stackA);
	(void)stackB;
}

void swap_b(t_stack* stackA, t_stack* stackB)
{
	swap(stackB);
	(void)stackA;
}

void swap_both(t_stack* stackA, t_stack* stackB)
{
	swap(stackA);
	swap(stackB);
}

void push(t_stack* stackFrom, t_stack* stackTo)
{
	if(stackFrom && stackFrom->size >= 1)
	{
		stackTo = add_top(stackTo, stackFrom->content[0]);
		stackFrom = remove_elem(stackFrom, 0);
	}
}

void push_a(t_stack* stackA, t_stack* stackB)
{
	push(stackB, stackA);
}

void push_b(t_stack* stackA, t_stack* stackB)
{
	push(stackA, stackB);
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

void rotate_a(t_stack* stackA, t_stack* stackB)
{
	rotate(stackA);
	(void)stackB;
}

void rotate_b(t_stack* stackA, t_stack* stackB)
{
	rotate(stackB);
	(void)stackA;
}

void rotate_both(t_stack* stackA, t_stack* stackB)
{
	rotate(stackA);
	rotate(stackB);
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

void reverse_rotate_a(t_stack* stackA, t_stack* stackB)
{
	reverse_rotate(stackA);
	(void)stackB;
}

void reverse_rotate_b(t_stack* stackA, t_stack* stackB)
{
	reverse_rotate(stackB);
	(void)stackA;
}

void reverse_rotate_both(t_stack* stackA, t_stack* stackB)
{
	reverse_rotate(stackA);
	reverse_rotate(stackB);
}

stackOp define_hashmap(char * opName)
{
	if(ft_strlen(opName) < 1 || ft_strlen(opName)> 3)
		return(NULL);
	if(!ft_strcmp(opName,"sa"))
		return &swap_a;
	if(!ft_strcmp(opName,"sb"))
		return &swap_b;
	if(!ft_strcmp(opName,"ss"))
		return &swap_both;
	if(!ft_strcmp(opName,"pa"))
		return &push_a;
	if(!ft_strcmp(opName,"pb"))
		return &push_b;
	if(!ft_strcmp(opName,"ra"))
		return &rotate_a;
	if(!ft_strcmp(opName,"rb"))
		return &rotate_b;
	if(!ft_strcmp(opName,"rr"))
		return &rotate_both;
	if(!ft_strcmp(opName,"rra"))
		return &reverse_rotate_a;
	if(!ft_strcmp(opName,"rrb"))
		return &reverse_rotate_b;
	if(!ft_strcmp(opName,"rrr"))
		return &reverse_rotate_both;
	return (NULL);
}

int makeStack(t_stack* stack, int argc, char** argv)
{
	int i;
	int j;
	
	i = 1;
	while(i < argc)
	{
		if(ft_strlen(argv[i]) == 1 && argv[i][0] == '0')
			stack->content[i] = 0;
		else
		{
			j = ft_atoi(argv[i]);
			if(j != 0)
				stack->content[i-1] = j;
			else 
				return(0);
		}
		i++;
	}
	return (1);
}


void readCmd(char* cmd)
{
	int i;
	char buff[1];
	
	i = 0;
	while(1)
	{
		buff[0] = 0;
		if(read(1, buff, 1))
		{
			if(i<=2)
				cmd[i] = buff[0];
			i++;
			if(buff[0] == 27 || buff[0] == '\n')
				break;
		}
	}
	i = 0;
	while(i <= 2)
	{
		if(cmd[i] == '\n')
			cmd[i] = 0;
		i++;
	}
	cmd[3] = 0;
}

void printtab(t_stack* stack)
{
	int i;
	
	i = 0;
	while(i < stack->size)
	{
		printf("%d\n",stack->content[i]);
		i++;
	}
}

int readCmds(t_stack* stackA, t_stack* stackB)
{
	char* cmd;
	stackOp op;
	
	while(1)
	{
		printtab(stackA);
		printtab(stackB);
		cmd = (char*)malloc(sizeof(char)*4);
		readCmd(cmd);
		op = define_hashmap(cmd);
		if(op)
		{
			op(stackA,stackB);
		}
		else if(!cmd[0])
		{
			if(issorted(stackA) && stackB && stackB->size == 0)
				printf("OK\n");
			else 
				printf("KO\n");
			return(0);
		}
		else
		{
			printf("Error\n");
			return (-1);
		}
		free(cmd);
	}
	return(0);
}

int doCmds(t_stack* stackA, t_stack* stackB, char** cmds)
{
	int i;
	stackOp op;
	
	i = 0;
	while(cmds[i])
	{
		op = define_hashmap(cmds[i]);
		if(op)
		{
			op(stackA,stackB);
		}
		else if(!cmds[i][0])
			break;
		else
		{
			printf("Error\n");
			return (-1);
		}
		i++;
	}
	if(issorted(stackA) && stackB && stackB->size == 0)
		printf("OK\n");
	else 
		printf("KO\n");
	return(0);
}
