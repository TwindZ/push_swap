/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:13:16 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/19 20:29:25 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_radix(t_data *data, int base)
{
	int div;
	int mod;
	int i;
	
	div = 1;
	mod = 0;
	i = ft_stacksize(data->stack_a);
	while(ft_sorted(data->stack_a) == FALSE)
	{
		while(data->stack_a != NULL && ft_sorted(data->stack_a) == FALSE)
		{
			i = ft_stacksize(data->stack_a);
			while(i)
			{
				if(div > (INT_MAX / 4))
					return ;
				ft_printf("index = %d / div = %d %% base = %d == mod = %d\n", data->stack_a->index, div, base, mod);
				if((data->stack_a->index / div) % base == mod)
				{
					ft_push_b(data);
				}
				else
					ft_rot_kind(data, 'a');
				i--;
			}
			if (mod < base - 1)
				mod++;
		}
		div *= base;
		if(ft_inverted_sorted(data->stack_b) == TRUE)
		{
			while(data->stack_b != NULL)
				ft_push_a(data);
		}
		while(data->stack_b != NULL)
		{

			i = ft_stacksize(data->stack_b);
			while(i)
			{
				if(div > (INT_MAX / 100))
					return ;
				if((data->stack_b->index / div) % base == mod)
					ft_push_a(data);
				else if(data->stack_b != NULL)
					ft_rot_kind(data, 'b');
				i--;
			}
			if(mod > 0)
				mod--;
		}
		div *= base;
	}
}