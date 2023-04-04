/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/04 17:45:28 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_stack_a(char **data)
{
	void 	*head;
	t_list 	*list;
	int i;
	
	i = 0;
	head = NULL;
	while (data[i])
	{
		list = ft_lstnew((void *)(ft_atoi(data[i])));
		list->next = head;
		head = list;
		i++;
	}
	while(list != NULL)
	{
		list = head;
		ft_putnbr(list->content);
		head = list->next;
	}
	
}

int main(int argc, char **argv)
{
	int i;
	char **arg;
	int free_flag;
	
	free_flag = 0;
	arg = NULL;
	i = 0;
	if(argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		free_flag = 1;
	}
	else if (argc > 2)
	{
		i++;
		arg = argv;
	}
	else
		ft_putstr("\n\e[1;31mNothing to sort !\e[0m\n\n");
	// while(arg[i])
	// {	
	// 	ft_putstr(arg[i]);
	// 	write(1, "\n", 1);
	// 	i++;
	// }
	ft_stack_a(arg);
	if(free_flag == 1)
		ft_freeall(arg);
}