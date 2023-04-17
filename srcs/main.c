/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 10:27:10 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/17 17:40:04 by emlamoth         ###   ########.fr       */
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
	while(data->stack_b != NULL)
	{
		if(data->stack_b->content == ft_find_smallest(data, 'b'))
			ft_push_a(data);
		else
			ft_rot_kind(data, 'b');
	}
}

void	ft_radix(t_data *data)
{
	int div;
	int mod;
	int i;
	
	div = 1;
	mod = 0;
	i = ft_stacksize(data->stack_a);
	// ft_printf("int = %d", i);
		while(data->stack_a != NULL)
		{
			while(i)
			{
				if((data->stack_a->content / div) % 10 == mod)
					ft_push_b(data);
				else if(data->stack_a != NULL)
					ft_rot_kind(data, 'a');
				i--;
			}
			i = ft_stacksize(data->stack_a);
			// ft_printf("int = %d", i);

			if(mod < 9)
				mod++;
			else
				mod = 0;
		}
		div *= 10;
		mod = 9;
		while(data->stack_b != NULL)
		{
			i = ft_stacksize(data->stack_b);
			while(i)
			{
				if((data->stack_b->content / div) % 10 == mod)
					ft_push_a(data);
				else if(data->stack_b != NULL)
					ft_rot_kind(data, 'b');
				i--;
			}
			if(mod > 0)
				mod--;
			else
				mod = 9;
		}
		if(data->stack_b != NULL)
			ft_simple_sort(data);
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
			
			// if(ft_stacksize(data->stack_a) == 3)
			// 	ft_sort_3(data, 'a');
			// else if (ft_stacksize(data->stack_a) == 5)
			// 	ft_sort_5(data);
			// else
				// ft_bubble_sort(data);
				// ft_simple_sort(data); /*50 736*/
				ft_radix(data); /*50 670*/
			
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