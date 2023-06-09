/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:29:05 by emlamoth          #+#    #+#             */
/*   Updated: 2023/05/03 20:13:22 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This function initializes the main struct once and can be used to obtain a 
pointer to the struct.*/
t_data	*ft_init(int argc, char **argv)
{
	static t_data	*data;	

	if (!data)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return(NULL);
		data->stack_a = NULL;
		data->stack_b = NULL;
		data->arg = NULL;
		data->free_flag = 0;
		data->write_flag = 1;
		data->cost = 0;
		data->base = 2;
		data->div = 1;
		data->argc = argc;
		data->argv = argv;
		ft_arg(data);
		if(!data->arg)
			ft_pushswap_free(1);
		data->stacksize = ft_stacksize(data->stack_a);
	}
	return (data);
}

/*This function brings the argument to the same base to initialize the stack.
If the list of numbers is in quotes, it needs to be split, unlike a normal 
argv list.*/
void	ft_arg(t_data *data)
{
	if (data->argc == 2)
	{
		data->arg = ft_split(data->argv[1], ' ');
		if (!data->arg)
			ft_pushswap_free(1);
		data->free_flag = 1;
		ft_stack(data, 0);
	}
	else
	{
		data->arg = data->argv;
		ft_stack(data, 1);
	}
}

/*This function converts the normalized arguments to a linked list while also
parsing for empty strings, non-numeric characters and integers outside the 
range of an int type.*/
void	ft_stack(t_data *data, int i)
{
	long int	nb;
	t_stack		*temp;

	if (!(ft_strlen(data->arg[i]) > 0 && ft_strlen(data->arg[i]) < 12))
		ft_pushswap_free(1);
	temp = NULL;
	ft_only_number(data->arg, i);
	while (data->arg[i])
	{
		nb = ft_atoi(data->arg[i]);
		if (!(ft_strlen(data->arg[i]) > 0 && ft_strlen(data->arg[i]) < 12
				&& nb <= INT_MAX && nb >= INT_MIN))
			ft_pushswap_free(1);
		if (data->stack_a == NULL)
		{
			data->stack_a = ft_lstnew_int(nb);
			if (!data->stack_a)
				ft_pushswap_free(1);
		}
		else
		{
			temp = data->stack_a;
			temp = ft_stacklast(temp);
			temp->next = ft_lstnew_int(nb);
			if (!temp->next)
				ft_pushswap_free(1);
		}
		i++;
	}
}

/*This function indexes the stack from the smallest integer to the largest. 
The sorting will be done by sorting the indexes rather than the contents 
of the stack.*/
void	ft_index(t_data *data)
{
	int		i;
	int		nb;
	t_stack	*temp;

	temp = data->stack_a;
	nb = INT_MAX;
	i = 0;
	while (i <= data->stacksize)
	{
		while (temp != NULL)
		{
			if (nb > temp->content && temp->index == 0)
				nb = temp->content;
			temp = temp->next;
		}
		temp = data->stack_a;
		while (temp->content != nb)
			temp = temp->next;
		temp->index = i;
		temp = data->stack_a;
		nb = INT_MAX;
		i++;
	}	
}
