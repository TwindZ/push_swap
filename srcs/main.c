/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emman <emman@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/16 19:23:26 by emman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_3(t_data *data)
{
	if(data->stack_a->index > data->stack_a->next->index 
			&& data->stack_a->next->index > data->stack_a->next->next->index)
		{
			ft_rot_kind(data, 'a');
			ft_swap_kind(data, 'a');
		}
	else if(data->stack_a->index > data->stack_a->next->index 
			&& data->stack_a->index > data->stack_a->next->next->index)
		ft_rot_kind(data, 'a');
	else if(data->stack_a->index > data->stack_a->next->index)
		ft_swap_kind(data, 'a');
	else if (data->stack_a->index < data->stack_a->next->index 
			&& data->stack_a->index > data->stack_a->next->next->index)
		ft_rrot_kind(data, 'a');
	else if (data->stack_a->index < data->stack_a->next->index 
			&& data->stack_a->index < data->stack_a->next->next->index)
	{
		ft_swap_kind(data, 'a');
		ft_rot_kind(data, 'a');
	}
}

void	ft_sort_5(t_data *data)
{
	while(ft_stacksize(data->stack_a) > 3)
		ft_push_b(data);
	ft_sort_3(data);
	if(data->stack_b->index < data->stack_b->next->index)
		ft_swap_kind(data, 'b');
	

}
int main(int argc, char **argv)
{
	t_data *data;
	
	if(argc > 1)
	{
		data = ft_init(argc, argv);
		if(ft_no_double(data) == TRUE && data->stack_a != NULL 
				&& ft_sorted(data->stack_a) == FALSE)
		{
			ft_index(data);
			ft_printf("LIST A\n");
			ft_printlist(data->stack_a);
			ft_printf("\n");
			ft_printf("LIST B\n");
			ft_printlist(data->stack_b);
			ft_printf("\n");
			
			ft_sort_3(data);
			
			ft_printf("LIST A\n");
			ft_printlist(data->stack_a);
			ft_printf("\n");
			ft_printf("LIST B\n");
			ft_printlist(data->stack_b);
			ft_printf("\n");

		}
		else
		{
			ft_pushswap_free(1);
			
		}
		ft_pushswap_free(0);
	}
	return (0);
}