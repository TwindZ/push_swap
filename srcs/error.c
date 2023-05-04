/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:36:38 by emlamoth          #+#    #+#             */
/*   Updated: 2023/05/03 21:05:58 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This function is used to free a linked list.*/
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

/*This function is used to free all elements of the simulation and also calls
ft_pushswap_free in case of an error.*/
void	ft_simulation_free(t_data *fake, int i)
{
	ft_free_stack(fake->stack_a);
	ft_free_stack(fake->stack_b);
	free(fake);
	if (i)
		ft_pushswap_free(1);
}

/*This function is used to free all elements of the program and can also 
be used to display an error message when needed.*/
void	ft_pushswap_free(int i)
{
	t_data	*data;

	data = ft_init(0, NULL);
	ft_free_stack(data->stack_a);
	ft_free_stack(data->stack_b);
	if (data->free_flag == 1)
		ft_freeall(data->arg);
	free(data);
	if (i == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(EXIT_FAILURE);
	}
}
