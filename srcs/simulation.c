/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:07:32 by emlamoth          #+#    #+#             */
/*   Updated: 2023/05/03 20:54:57 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This function creates a simulated stack for the radix algorithm simulation.*/
void	ft_fake_stack(t_data *fake, int i)
{
	t_stack	*temp;

	while (i)
	{
		if (fake->stack_a == NULL)
		{
			fake->stack_a = ft_lstnew_int(i);
			if (!fake->stack_a)
				ft_simulation_free(fake, 1);
		}
		else
		{			
			temp = fake->stack_a;
			temp = ft_stacklast(temp);
			temp->next = ft_lstnew_int(i);
			if (!temp->next)
				ft_simulation_free(fake, 1);
		}
		i--;
	}
}

/*Initialize the simulated stack*/
t_data	*ft_fake_data(t_data *data)
{
	t_data	*fake;

	fake = malloc(sizeof(t_data));
	if (!fake)
		ft_pushswap_free(1);
	fake->stack_a = NULL;
	fake->stack_b = NULL;
	fake->write_flag = 0;
	fake->div = 1;
	fake->cost = 0;
	fake->base = 2;
	fake->stacksize = ft_stacksize(data->stack_a);
	ft_fake_stack(fake, fake->stacksize);
	if (!fake)
		ft_pushswap_free(1);
	ft_index(fake);
	return (fake);
}

/*This function simulates the action count for each base from 2 to 10 and keeps
the best one.*/
void	ft_simulation(t_data *data)
{
	t_data	*fake;
	int		i;
	int		bestcost;

	i = 2;
	bestcost = INT_MAX;
	while (i != 10)
	{
		fake = ft_fake_data(data);
		ft_radix(fake, i);
		if (bestcost > fake->cost)
		{
			bestcost = fake->cost;
			data->base = i;
		}
		i++;
		ft_simulation_free(fake, 0);
	}	
}
