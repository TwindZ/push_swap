/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/12 18:44:03 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_printlist(t_stack *list)
{
	while(list != NULL)
	{
		// ft_printf("\nlist :		%p \n", list);
		// ft_printf("\nlist->index : %d \n", list->index);
		// ft_printf("\nlist->content : %d \n\n", list->content);
		// ft_printf("list->next :	%p \n		|\n", list->next);
		ft_printf("%d\n", list->content);
		list = list->next;
		usleep(500000);
	}
}

void	ft_sort_3(t_data *data)
{
		if((data->stack_a->index == 2) 
				&& (data->stack_a->next->index == 3))
		{
		ft_swap_kind(data, 'a');
		ft_rot_kind(data, 'a');
		}
		else if((data->stack_a->index == 1) 
				&& (data->stack_a->next->index == 2))
		{
		ft_rot_kind(data, 'a');
		ft_swap_kind(data, 'a');
		}
		else if((data->stack_a->index == 1) 
				&& (data->stack_a->next->index == 3))
		ft_rrot_kind(data, 'a');
		else if((data->stack_a->index == 3) 
				&& (data->stack_a->next->index == 1))
		ft_swap_kind(data, 'a');
		else if((data->stack_a->index == 1) 
				&& (data->stack_a->next->index == 1))
		ft_rot_kind(data, 'a');

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