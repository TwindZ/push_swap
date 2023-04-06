/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/06 18:13:56 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack != NULL)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
	stack = NULL;
}

t_stack	*ft_lstnew_int(int content)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

void	ft_printlist(t_stack *list)
{
	while(list != NULL)
	{
		ft_printf("list : %p \n", list);
		ft_printf("list->content : %d \n", list->content);
		ft_printf("list->next : %p \n", list->next);
		list = list->next;
	}
}

int	ft_only_number(char **arg)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while(arg[i])
	{
		while(arg[i][j])
		{
			if(ft_isdigit(arg[i][j]) == 0)
			{
				ft_printf("Wrong input. Only number can be an argument.\n");
				return (FALSE);
			}
			j++;
		}
		i++;
		j = 0;	
	}
	return(TRUE);
}

int	ft_no_double(char **arg)
{
	int i;
	int j;
	int len;
	int len2;
	
	i = 0;
	j = i + 1;
	while(arg[i])
	{
		while(arg[j])
		{
			len = ft_strlen(arg[i]);
			len2 = ft_strlen(arg[j]);
			if(len < len2)
				len = len2;
			if(ft_strncmp(arg[i], arg[j], len) == 0)
				return(FALSE);
			j++;
		}
		i++;
		j = i + 1;
	}
	return(TRUE);
}

void	ft_stack(char **arg, int argc)
{
	t_stack	*stack;
	t_stack *head;
	int i;
	
	i = 1;
	head = NULL;
	stack = NULL ;
	ft_printf("%d", ft_no_double(arg));
	ft_printf("%d", ft_only_number(arg));
	if(ft_only_number(arg) == TRUE && ft_no_double(arg) == TRUE)
	{
		while (argc > 1)
		{
			stack = ft_lstnew_int(ft_atoi(arg[i]));
			stack->next = head;
			head = stack;
			i++;
			argc--;
		}
	}	
	ft_printlist(head);
	ft_free_stack(stack);
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
		return (-1);
	ft_stack(arg, argc);
	if(free_flag == 1)
		ft_freeall(arg);
}