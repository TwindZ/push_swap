/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:36:38 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/12 16:37:39 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pushswap_free(int i)
{
	t_data *data;

	data = ft_init(0, NULL);
	ft_free_stack(data->stack_a);
	ft_free_stack(data->stack_b);
	if(data->free_flag == 1)
		ft_freeall(data->arg);
	free(data);
	if(i == 1)
	{
		ft_putendl_fd("Error from psfree", 2);
		exit(EXIT_FAILURE);
	}
}

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