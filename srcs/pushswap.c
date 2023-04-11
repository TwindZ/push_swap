/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/11 17:31:21 by emlamoth         ###   ########.fr       */
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
	node->index = 0;
	return (node);
}

void	ft_printlist(t_stack *list)
{
	while(list != NULL)
	{
		ft_printf("list :		%p \n", list);
		ft_printf("\nlist->index : %d \n\n", list->index);
		ft_printf("\nlist->content : %d \n\n", list->content);
		ft_printf("list->next :	%p \n		|\n", list->next);
		list = list->next;
		usleep(500000);
	}
}

int	ft_only_number(char **arg, int i)
{
	int j;

	j = 0;
	while(arg[i])
	{
		while(arg[i][j])
		{
			if(!(ft_isdigit(arg[i][j]) == 1 || (arg[i][0] == '-' 
					&& ft_isdigit(arg[i][j + 1]) == 1)))
			{
				ft_printf(ERRARG);
				return (FALSE);
			}
			j++;
		}
		i++;
		j = 0;	
	}
	return(TRUE);
}

int	ft_empty(char **arg)
{
	int i;

	i = 0;
	if(!arg[i])
	{
		ft_printf(ERRARG);
		return (FALSE);
	}
	return (TRUE);
}

int	ft_no_double(char **arg, int i)//peut etre verifier pour le -0 ici
{
	int j;
	int len;
	int len2;
	
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
			{
				ft_printf(ERRDUP);
				return(FALSE);
			}
			j++;
		}
		i++;
		j = i + 1;
	}
	return(TRUE);
}

int	ft_sorted(t_stack *stack)
{
	while(stack->next != NULL)
	{
		if(stack->content < stack->next->content)
			return (FALSE);
		stack = stack->next;
	}
	ft_printf("Sorted !");
	return (TRUE);
}

void	ft_stack(t_data *data, int i)
{
	long int nb;
	t_stack *temp;

	temp = NULL;
	// ft_printf("no double %d\n", ft_no_double(data->arg, i));
	// ft_printf("only number %d\n", ft_only_number(data->arg, i));
	if(ft_only_number(data->arg, i) == TRUE && ft_no_double(data->arg, i) == TRUE && ft_empty(data->arg + i) == TRUE)
	{
		while (data->arg[i])
		{
			nb = ft_atoi(data->arg[i]);
			if(nb <= INT_MAX && nb >= INT_MIN)
			{			
				temp = data->stack_a;
				data->stack_a = ft_lstnew_int(nb);
				data->stack_a->next = temp;
				i++;
			}
			else
			{
				ft_printf(ERRINT);
				ft_free_stack(data->stack_a);
				exit(EXIT_FAILURE);
			}
		}
	}
}

void	ft_arg(int argc, char **argv, t_data *data)
{
		if(argc == 2)
		{
			data->arg = ft_split(argv[1], ' ');
			ft_stack(data, 0);
			ft_freeall(data->arg);
			data->arg = NULL;
			
		}
		else if (argc > 2)
		{
			data->arg = argv;
			ft_stack(data, 1);
		}
		else
			return ;
}

t_data	*ft_init(int argc, char **argv)
{
	static t_data *data;	
	
	if(!data)
	{
		data = malloc(sizeof(t_data));
		data->stack_a = NULL;
		data->stack_b = NULL;
		data->arg = NULL;
		ft_arg(argc, argv, data);
		data->free_flag = 0;
		data->stacksize = ft_stacksize(data->stack_a);
	}
	return(data);
}

void	ft_index(t_data *data)
{
	int i;
	int nb;
	t_stack *temp;

	temp = data->stack_a;
	nb = INT_MIN;
	i = 0;
	while(i < data->stacksize)
	{
		while(temp->next != NULL)
		{
			if(nb < temp->content && temp->index == 0)
			{
				nb = temp->content;
			}
			temp = temp->next;
		}
		temp->index = i;
		temp = data->stack_a;
		nb = INT_MIN;
		i++;
	}	
}

int main(int argc, char **argv)
{
	t_data *data;
	
	data = ft_init(argc, argv);
	if(ft_sorted(data->stack_a) == FALSE)
	{
		
	
	}
		ft_index(data);
		
		ft_printf("LIST A\n");
		ft_printlist(data->stack_a);
		ft_printf("\n");
		ft_printf("LIST B\n");
		ft_printlist(data->stack_b);
		ft_printf("\n");
		
	ft_free_stack(data->stack_a);
	ft_free_stack(data->stack_b);
	free(data);
	return (0);
}