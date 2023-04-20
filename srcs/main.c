/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/20 17:05:10 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_choose_algo(t_data *data)
{
	if (ft_stacksize(data->stack_a) == 3)
		ft_sort_3(data);
	else if (ft_stacksize(data->stack_a) == 4)
		ft_sort_4(data);
	else if (ft_stacksize(data->stack_a) == 5)
		ft_sort_5(data);
	else if (ft_stacksize(data->stack_a) > 5
		&& ft_stacksize(data->stack_a) < 10)
		ft_simple_sort(data);
	else
	{
		ft_simulation(data);
		ft_radix(data, data->base);
	}
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 1)
	{
		data = ft_init(argc, argv);
		if (data->stack_a == NULL && data->stacksize < 3)
			ft_pushswap_free(1);
		ft_index(data);
		if (ft_no_double(data) == TRUE && ft_sorted(data->stack_a) == FALSE)
			ft_choose_algo(data);
		else
			ft_pushswap_free(1);
		ft_pushswap_free(0);
	}
	return (0);
}
