/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:02:46 by mipham            #+#    #+#             */
/*   Updated: 2017/12/27 16:02:49 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

int main(int argc, char** argv)
{
	char buff[2001];
	int f;
	t_stack* stackA;
	t_stack* stackB;
	
	stackA = (t_stack*)malloc(sizeof(t_stack));
	stackB = (t_stack*)malloc(sizeof(t_stack));
	stackA->content = (int*)malloc(sizeof(int)* (argc-1));
	stackA->size = argc - 1;
	stackB->content = NULL;
	stackB->size = 0;
	f = 0;
	if(read(0, buff, 1999))
	{
		buff[2000]='\0';
		f = 1;
	}
	if(!makeStack(stackA, argc, argv))
	{
		printf("Error\n");
		return (-1);
	}
	if(f>0)
		return(doCmds(stackA, stackB, ft_strsplit(buff,'\n')));
	else
		return(readCmds(stackA, stackB));
}
