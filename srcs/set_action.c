/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emlamoth <emlamoth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 15:20:43 by emlamoth          #+#    #+#             */
/*   Updated: 2023/04/25 10:36:12 by emlamoth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*This function counts the number of movements made during the simulation and
writes the movements when the final radix sort is executed.*/
void	ft_write_or_count(t_data *data, char *movename)
{
	if (data->write_flag == 1)
		ft_printf("%s\n", movename);
	else
		data->cost++;
}

/*This function dispatches which action needs to be done based on the 
character set.*/
void	ft_rot(t_data *data, char set)
{
	if (set == 'a')
	{
		data->stack_a = ft_rotstack(data->stack_a);
		ft_write_or_count(data, "ra");
	}
	else if (set == 'b')
	{
		data->stack_b = ft_rotstack(data->stack_b);
		ft_write_or_count(data, "rb");
	}
	else if (set == 'r')
	{
		data->stack_a = ft_rotstack(data->stack_a);
		data->stack_b = ft_rotstack(data->stack_b);
		ft_write_or_count(data, "rr");
	}
}

/*This function dispatches which action needs to be done based on the 
character set.*/
void	ft_rrot(t_data *data, char set)
{
	if (set == 'a')
	{
		data->stack_a = ft_rrotstack(data->stack_a);
		ft_write_or_count(data, "rra");
	}
	else if (set == 'b')
	{
		data->stack_b = ft_rrotstack(data->stack_b);
		ft_write_or_count(data, "rrb");
	}
	else if (set == 'r')
	{
		data->stack_a = ft_rrotstack(data->stack_a);
		data->stack_b = ft_rrotstack(data->stack_b);
		ft_write_or_count(data, "rrr");
	}
}

/*This function dispatches which action needs to be done based on the 
character set.*/
void	ft_swap(t_data *data, char set)
{
	if (set == 'a')
	{
		data->stack_a = ft_stackswap(data->stack_a);
		ft_write_or_count(data, "sa");
	}
	else if (set == 'b')
	{
		data->stack_b = ft_stackswap(data->stack_b);
		ft_write_or_count(data, "sb");
	}
	else if (set == 's')
	{
		data->stack_a = ft_stackswap(data->stack_a);
		data->stack_b = ft_stackswap(data->stack_b);
		ft_write_or_count(data, "ss");
	}
}
