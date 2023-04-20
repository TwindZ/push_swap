/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:13:16 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/20 17:20:27 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_rad_a(t_data *data, int base)
{
	int	i;
	int	mod;

	mod = 0;
	while (data->stack_a != NULL && ft_sorted(data->stack_a) == FALSE)
	{
		i = ft_stacksize(data->stack_a);
		while (i)
		{
			if ((data->stack_a->index / data->div) % base == mod)
				ft_push_b(data);
			else
				ft_rot(data, 'a');
			i--;
		}
		if (mod < base - 1)
			mod++;
	}
	data->div *= base;
}

void	ft_rad_b(t_data *data, int base)
{
	int	i;
	int	mod;

	mod = base - 1;
	while (data->stack_b != NULL)
	{
		i = ft_stacksize(data->stack_b);
		while (i)
		{
			if ((data->stack_b->index / data->div) % base == mod)
				ft_push_a(data);
			else if (data->stack_b != NULL)
				ft_rot(data, 'b');
			i--;
		}
		if (mod > 0)
			mod--;
	}
	data->div *= base;
}

void	ft_radix(t_data *data, int base)
{
	while (ft_sorted(data->stack_a) == FALSE)
	{
		ft_rad_a(data, base);
		if (data->div > (INT_MAX / 2))
			return ;
		if (ft_inverted_sorted(data->stack_b) == TRUE)
		{
			while (data->stack_b != NULL)
				ft_push_a(data);
		}
		ft_rad_b(data, base);
		if (data->div > (INT_MAX / 2))
			return ;
	}
}
