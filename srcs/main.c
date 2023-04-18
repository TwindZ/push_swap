/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/18 17:56:05 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sort_3(t_data *data, char set)
{
	t_stack *temp;

	if(set == 'a')
		temp = data->stack_a;
	else
		temp = data->stack_b;
	
	if(temp->index > temp->next->index 
			&& temp->next->index > temp->next->next->index)
		{
			ft_rot_kind(data, set);
			ft_swap_kind(data, set);
		}
	else if(temp->index > temp->next->index 
			&& temp->index > temp->next->next->index)
		ft_rot_kind(data, set);
	else if(temp->index > temp->next->index)
		ft_swap_kind(data, set);
	else if (temp->index < temp->next->index 
			&& temp->index > temp->next->next->index)
		ft_rrot_kind(data, set);
	else if (temp->index < temp->next->index 
			&& temp->index < temp->next->next->index)
	{
		ft_swap_kind(data, set);
		ft_rot_kind(data, set);
	}
}

int	ft_find_biggest(t_data *data, char set)
{
	int biggest;
	t_stack *temp;

	biggest = INT_MIN;
	if(set == 'a')
		temp = data->stack_a;
	else
		temp = data->stack_b;
	while(temp != NULL)
	{
		if(biggest < temp->index)
			biggest = temp->index;
		temp = temp->next;
	}
	return (biggest);
}

int ft_find_smallest(t_data *data, char set)
{
	int smallest;
	t_stack *temp;

	smallest = INT_MAX;
	if(set == 'a')
		temp = data->stack_a;
	else
		temp = data->stack_b;
	while(temp != NULL)
	{
		if(smallest > temp->index)
			smallest = temp->index;
		temp = temp->next;
	}
	return (smallest);
}

void	ft_sort_5(t_data *data)
{
	int small;
	int big;
	
	big = ft_find_biggest(data, 'a');
	small = ft_find_smallest(data, 'a');
	while(ft_stacksize(data->stack_a) > 3)
	{
		if(data->stack_a->index == small || data->stack_a->index == big)
			ft_push_b(data);
		ft_rot_kind(data, 'a');
	}
	if(ft_sorted(data->stack_a) == FALSE && ft_stacksize(data->stack_a) == 3)
		ft_sort_3(data, 'a');
	if(data->stack_b->index < data->stack_b->next->index)
		ft_swap_kind(data, 'b');
	ft_push_a(data);
	ft_rot_kind(data, 'a');
	ft_push_a(data);
}

void	ft_simple_sort(t_data *data)
{
	while(data->stack_a != NULL)
	{
		if(data->stack_a->index == ft_find_smallest(data, 'a'))
			ft_push_b(data);
		else
			ft_rot_kind(data, 'a');
	}
	while(data->stack_b != NULL)
	{
		ft_push_a(data);
	}
}

void	ft_bubble(t_data *data)
{
	while(ft_sorted(data->stack_a) == FALSE)
	{
		if(data->stack_a->index == ft_find_biggest(data, 'a'))
			ft_rot_kind(data, 'a');
		else if(data->stack_a->index > data->stack_a->next->index)
			ft_swap_kind(data, 'a');
		else 
			ft_rot_kind(data, 'a');
	}
}

void	ft_radix(t_data *data, int base)
{
	int div;
	int mod;
	int i;
	
	div = 1;
	mod = 0;
	i = ft_stacksize(data->stack_a);
	// ft_printf("int = %d", i);
	while(ft_sorted(data->stack_a) == FALSE)
	{
		while(data->stack_a != NULL)
		{
			i = ft_stacksize(data->stack_a);
			while(i)
			{
				if((data->stack_a->index / div) % base == mod)
					ft_push_b(data);
				else if(data->stack_a != NULL)
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

void	ft_lower_cost(t_data *data)
{
	int i;
	int bestcost;

	
	i = 2;
	bestcost = INT_MAX;
	while(i != ft_stacksize(data->stack_a) / 2)
	{
		data->cost = 0;
		ft_radix(data, i);
		if(bestcost > data->cost)
		{
			bestcost = data->cost;
			data->base = i;
		}
		data->cost = bestcost;
		data->base = data->base;
		i++;
		ft_rot_kind(data, 'a');
	}
	data->write_flag = 0;
}

int main(int argc, char **argv)
{
	t_data *data;
	
	if(argc > 1)
	{
		data = ft_init(argc, argv);
		if(/*ft_no_double(data) == TRUE && */data->stack_a != NULL 
				&& ft_sorted(data->stack_a) == FALSE)
		{
			ft_index(data);
			
			// ft_printf("LIST A\n");
			// ft_printlist(data->stack_a);
			// ft_printf("\n");
			// ft_printf("LIST B\n");
			// ft_printlist(data->stack_b);
			// ft_printf("\n");
			
			if(ft_stacksize(data->stack_a) == 3)
				ft_sort_3(data, 'a');
			else if (ft_stacksize(data->stack_a) <= 5 && ft_stacksize(data->stack_a) >= 4)
				ft_bubble(data);
			else if (ft_stacksize(data->stack_a) > 5 && ft_stacksize(data->stack_a) <= 10 )
				ft_simple_sort(data); /*50 736*/
			else 
				ft_radix(data, 4); /*50 670*/
				
				
				
				
				
				// ft_lower_cost(data);
				// ft_printf("%d\n", data->cost);
				// ft_printf("%d\n", data->base);
				// ft_radix(data, 5);
				// ft_printf("%d\n", data->cost);
				// ft_printf("%d\n", data->base);
			
			// ft_printf("LIST A\n");
			// ft_printlist(data->stack_a);
			// ft_printf("\n");
			// ft_printf("LIST B\n");
			// ft_printlist(data->stack_b);
			// ft_printf("\n");

			// ft_printf("%d\n", ft_find_biggest(data, 'a'));
			// ft_printf("%d\n", ft_find_smallest(data, 'a'));

		}
		else
		{
			ft_pushswap_free(1);
		}
		ft_pushswap_free(0);
	}
	return (0);
}