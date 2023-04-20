/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 11:07:32 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/19 20:35:22 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_fake_stack(t_data *fake, int i)
{
	t_stack *temp;

	while(i)
	{
		if(fake->stack_a == NULL)
		{
			fake->stack_a = ft_lstnew_int(i);
			i--;
		}
		else
		{			
			temp = fake->stack_a;
			temp = ft_stacklast(temp);
			temp->next = ft_lstnew_int(i);
			i--;
		}
	}
	
}

t_data	*ft_fake_data(t_data *data)
{
	t_data *fake;
	(void) data;
	fake = malloc(sizeof(t_data));
	fake->stack_a = NULL;
	fake->stack_b = NULL;
	fake->cost = 0;
	fake->write_flag = 0;
	fake->free_flag = 0;
	fake->a_len = 0;
	fake->b_len = 0;
	fake->cost = 0;
	fake->base = 2;
	fake->stacksize = ft_stacksize(data->stack_a);
	ft_fake_stack(fake, fake->stacksize);
	ft_index(fake);

	return(fake);	
}

void	ft_simulation(t_data *data)
{
	t_data *fake;
	int i;
	int bestcost;
	int bestbase;
		
	i = 2;
	bestcost = INT_MAX;
	while(i != 10 /*ft_stacksize(data->stack_a) / 2*/)
	{
		fake = ft_fake_data(data);
		fake->cost = 0;
		ft_radix(fake, i);
		if(bestcost > fake->cost)
		{
			bestcost = fake->cost;
			bestbase = i;
		}
		i++;
		data->base = bestbase;
		ft_printf("%d\n", bestbase);
		ft_printf("%d\n", bestcost);
		ft_free_stack(fake->stack_a);
		ft_free_stack(fake->stack_b);
		free(fake);
		ft_printf("%d\n", data->base);
	}	
}