/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/05/03 20:35:08 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This function chooses the sorting algorithm based on the number of 
integers to sort.*/
void	ft_choose_algo(t_data *data)
{
	if (ft_stacksize(data->stack_a) == 2)
		ft_sort_2(data);
	else if (ft_stacksize(data->stack_a) == 3)
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

/*The program initializes the main struct, parses the data, assigns an index 
to each number, chooses an algorithm based on the quantity of numbers, 
sorts the numbers using the chosen algorithm, and frees all memory allocated 
during execution.*/
int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc > 1)
	{
		data = ft_init(argc, argv);
		if (!data)
			exit(EXIT_FAILURE);
		ft_index(data);
		ft_no_double(data);
		if (ft_sorted(data->stack_a) == FALSE)
			ft_choose_algo(data);
		ft_pushswap_free(0);
	}
	return (0);
}
